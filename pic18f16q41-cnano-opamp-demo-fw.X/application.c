/*
 * File:   application.c
 * Author: C16783
 *
 * Created on August 26, 2020, 9:24 AM
 */

#include <xc.h>
#include "application.h"
#include "mcc_generated_files/mcc.h"

void IntroSplashMessage(void) {
    printf("PIC18F16Q41 Curiosity Nano OPA Demo \r\n");
    printf("Select OPA mode of operation using pins RA4 and RA5.\r\n");
    printf("Press SW0 after selecting mode of operation to reconfigure OPA module. \r\n");
    printf("Please refer to included readme.md for more information. \r\n");
    printf("-------------------------------------------------------------------\r\n");
}

void GetOpampConfig(void) {
    opa_config = ((PORTAbits.RA5 << 1)+(PORTAbits.RA4)) + 1;
}

void BlinkLED(int8_t cnt) {
    for (int i = cnt; i > 0; i--) {
        LATCbits.LATC1 = 0;
        __delay_ms(250);
        LATCbits.LATC1 = 1;
        __delay_ms(250);
    }
}

void OPA_External(void) {
    printf("OPA Configuration: Direct Connection to External Pins \r\n");
    printf("OPA1OUT = RC2 | OPA1IN+ = RC3 | OPA1IN- = RA2 \r\n\r\n");
    OPA1CON0bits.EN = 0; // Disable OPA Module;
    OPA1CON1 = 0x02; //RESON Disabled; NSS OPA1IN2-; 
    OPA1CON2 = 0x22; //NCH OPA1IN-; PCH OPA1IN+; 
    OPA1CON3 = 0x01; //FMS No Connection; PSS OPA1IN1+; 
    OPA1CON0 = 0xC0; //EN Enabled; User Defined Feedback; 
}

void OPA_UnityGain(void) {
    printf("OPA Configuration: Unity Gain Buffer \r\n");
    printf("OPA1OUT = RC2 | OPA1IN+ = RC3 \r\n\r\n");
    OPA1CON0bits.EN = 0; // Disable OPA Module;
    OPA1CON1 = 0x00; //RESON Disabled; NSS OPA1IN0-; 
    OPA1CON2 = 0x02; //NCH No Connection; PCH OPA1IN+; 
    OPA1CON3 = 0x01; //FMS No Connection; PSS OPA1IN1+; 
    OPA1CON0 = 0xC8; //EN Enabled; Unity Gain Connection Enabled; 
}

void OPA_NonInverting(void) {
    printf("OPA Configuration: Non-Inverting Programmable Gain Amplifier \r\n");
    printf("OPA1OUT = RC2 | OPA1IN+ = RC3 \r\n\r\n");
    OPA1CON0bits.EN = 0; // Disable OPA Module;
    OPA1CON1 = 0x5F; //GSEL R1 = 4R and R2 = 12R, R2/R1 = 3; RESON Enabled; NSS Vss; 
    OPA1CON2 = 0x12; //NCH GSEL; PCH OPA1IN+; 
    OPA1CON3 = 0x81; //FMS OPA1OUT; PSS OPA1IN1+; 
    OPA1CON0 = 0xC0; //EN Enabled; CPON Enabled; UG OPAIN- pin; SOC User Defined Feedback; 
}

void OPA_Inverting(void) {
    printf("OPA Configuration: Inverting Programmable Gain Amplifier \r\n");
    printf("OPA1OUT = RC2 | OPA1IN- = RA2 \r\n\r\n");
    OPA1CON0bits.EN = 0; // Disable OPA Module;
    OPA1CON1 = 0x5A; //GSEL R1 = 4R and R2 = 12R, R2/R1 = 3; RESON Enabled; NSS OPA1IN2-; 
    OPA1CON2 = 0x13; //NCH GSEL; PCH Vdd/2; 
    OPA1CON3 = 0x80; //FMS OPA1OUT; PSS OPA1IN0+; 
    OPA1CON0 = 0xC0; //EN Enabled; CPON Enabled; UG OPAIN- pin; SOC User Defined Feedback; 
}