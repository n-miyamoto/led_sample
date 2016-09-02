#ifdef __XC32
#include <plib.h>
#endif
#ifdef __XC16
#include <xc.h>
#endif

#include "config.h"
#include "delay.h"

#ifdef __XC16

//8MHz
//_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & ICS_PGx1 & FWDTEN_OFF )
//_CONFIG2( IESO_OFF & FNOSC_FRC & FCKSM_CSDCMD & OSCIOFNC_OFF &
//IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_NONE )

//32MHz PIC24FJ64GA
    //_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & ICS_PGx1 & FWDTEN_OFF )
    //_CONFIG2( IESO_ON & FNOSC_FRCPLL & FCKSM_CSDCMD & OSCIOFNC_ON &
    //IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_NONE  & PLL96MHZ_ON & PLLDIV_DIV2 )
    //_CONFIG4(RTCOSC_SOSC)
    
    #ifdef __PIC24FJ64GB002__
    _CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & ICS_PGx1 & FWDTEN_OFF )
    _CONFIG2( IESO_ON & FNOSC_FRCPLL & FCKSM_CSDCMD & OSCIOFNC_ON &
    IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_NONE  & PLL96MHZ_ON & PLLDIV_DIV2 )
    _CONFIG4(RTCOSC_SOSC)
    #endif

//16MHz PIC24FJ64GB
//_CONFIG1( JTAGEN_OFF & GCP_OFF & GWRP_OFF & ICS_PGx1 & FWDTEN_OFF )
//_CONFIG2( IESO_ON & FNOSC_FRCPLL & FCKSM_CSDCMD & OSCIOFNC_OFF &
//IOL1WAY_OFF & I2C1SEL_PRI & POSCMOD_NONE  & PLL96MHZ_ON & PLLDIV_DIV2 )
#endif

#ifdef __XC32
// CPU40MHz
#pragma config FNOSC    = FRCPLL        // Oscillator Selection
#pragma config POSCMOD  = OFF           // Primary Oscillator
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider
#pragma config FPLLMUL  = MUL_20        // PLL Multiplier
#pragma config FPBDIV   = DIV_1         // Peripheral Clock divisor
#pragma config FPLLODIV = DIV_2
#pragma config ICESEL   = ICS_PGx3      // ICE/ICD Comm Channel Select
#pragma config FWDTEN   = OFF           // Watchdog Timer
#endif
//

void config_init(void)
{
#ifdef __XC32
    SYSTEMConfigPerformance(FCY);
    mJTAGPortEnable(DEBUG_JTAGPORT_OFF);
#endif
#ifdef __XC16
	CLKDIV = 0;
/*
        TRISBbits.TRISB13 = 0;
        REFOCONbits.ROEN = 1; //enable pin out
        REFOCONbits.ROSSLP = 0;
        REFOCONbits.ROSEL=0;
        REFOCONbits.RODIV = 0;
 * */
#endif
}



