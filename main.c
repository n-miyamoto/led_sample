#include <stdio.h>
#include "delay.h"
#include "config.h"
#include "stdlib.h"
#include "xc.h"

int main(void)
{
    config_init();
    
    TRISAbits.TRISA3 = 0;   //init digital port.
    while(1){
        LATAbits.LATA3 = rand()%2;
        delay_us(100);
    }
}
