#include <msp430.h>

void main(void)
{
    WDTCTL =WDTPW + WDTHOLD;

    P1DIR |= BIT6;
    TA0CTL = TASSEL_2 + MC_1 + ID_3 + TACLR;

    TA0CCR0 = 31250;
    TA0CCR1 = 6250;

    TA0CCTL0 |= CCIE;
    TA0CCTL1 |= CCIE;

    TA0CCTL0 &=~CCIFG;
    TA0CCTL1 &=~CCIFG;

    _enable_interrupts();
}
#pragma vector = TIMER0_A0_VECTOR
__interrupt void TA0_ISR (void)
{
    P1OUT |= BIT6;
    TA0CCTL0 &=~CCIFG;
}

#pragma vector = TIMER0_A1_VECTOR
__interrupt void TA1_ISR (void)
    {
    P1OUT &=~BIT6;
    TA0CCTL1 &=~CCIFG;
    }
