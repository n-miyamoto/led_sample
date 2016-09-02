#include <stdio.h>
#include <stdlib.h>
#include "delay.h"
#include "config.h"
#include "xc.h"

int main(void)
{
    config_init();
    
    TRISAbits.TRISA3 = 0;   //init digital port connected to LED
    while(1){
        LATAbits.LATA3 = rand()%2;  //turn on or off LED
        delay_us(100);
    }
}
