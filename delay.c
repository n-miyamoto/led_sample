#ifdef __XC32
#include <plib.h>           /* Include to use PIC32 peripheral libraries      */
#endif
#ifdef __XC16
#include <xc.h>
#endif


#include <stdio.h>         /* For uint32_t definition                        */
#include "delay.h"

#ifndef __XC16
void delay_us (unsigned int n)
{
#if defined(__XC32) && defined(I_USE_TRIS)
    const unsigned int function_overhead = 6;

    while (n > 1000)  // To avoid timer overflow
    {
        delay_ms (1000);
        n -= 1000;
    }

    if (n > function_overhead)
    {
        TMR1 = 0;  // Reset timer to 0

        PR1
            =   (n - function_overhead)
              * (FCY / 1000)
              / 1000;

        IFS0bits.T1IF = 0;       // Clear overflow flag

        T1CONbits.ON  = 1;       // Turn timer on

        while (! IFS0bits.T1IF)  // Wait until overflow flag is set
            ;
    }
#endif
#if defined(__XC32) && defined(I_USE_TIMER)
	while(delay--)
	{
		int_status = INTDisableInterrupts();
		OpenCoreTimer(FCY / 2000000);
		INTRestoreInterrupts(int_status);
		mCTClearIntFlag();
		while( !mCTGetIntFlag() )
			;
	}
	mCTClearIntFlag();
#endif
}
#endif

#ifndef __XC16
void delay_ms (unsigned int n)
{
#if defined(__XC32) && defined(I_USE_TRIS)
    while (n --)
        delay_us (1000);
#endif
#if defined(__XC32) && defined(I_USE_TIMER)
	unsigned int int_status;
	while(delay--)
	{
		int_status = INTDisableInterrupts();
		OpenCoreTimer(FCY / 2000);
		INTRestoreInterrupts(int_status);
		mCTClearIntFlag();
		while( !mCTGetIntFlag() )
			;
	}
	mCTClearIntFlag();
#endif
}
#endif

