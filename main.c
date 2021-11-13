#include <msp430.h>

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;
    P1DIR |= BIT6;
    P1OUT = 0x00;
    P1SEL |= BIT6;
    TACCR0 = 62500-1;
    TACCTL1 = OUTMOD_7;
    TACCR1 = 6250-1;
    TACTL = TASSEL_2 + MC_1 + ID_3;

    while(1){
        P1OUT ^= BIT6;
    }
}
