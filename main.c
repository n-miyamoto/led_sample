#include <stdio.h>
#include "delay.h"
#include "config.h"
#include "stdlib.h"
#include "xc.h"

int main(void)
{
    config_init();
    
    TRISAbits.TRISA3=0; //output
    TRISAbits.TRISA3 = 0;   //P10: set to Output for high side switch
    LATAbits.LATA3 = 0;     //turn off high side switch
    while(1){
        LATAbits.LATA3 = rand()%2;
        delay_us(100);
    }
}
