/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.4
        Device            :  PIC18F16Q41
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"
#include "application.h"

/*
                         Main application
 */

void main(void) {
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    IntroSplashMessage();
    GetOpampConfig();

    while (1) {

        switch (opa_config) {
            case 1:
                if (init_flag == 0) {
                    BlinkLED(opa_config);
                    OPA_External();
                    init_flag = 1;
                } else if (sw0_flag == 1) {
                    sw0_flag = 0;
                    init_flag = 0;
                    GetOpampConfig(); // Update state of RA5 / RA4 to determine OPA configuration;
                }
                SLEEP();
                break;

            case 2:
                if (init_flag == 0) {
                    BlinkLED(opa_config);
                    OPA_UnityGain();
                    init_flag = 1;
                } else if (sw0_flag == 1) {
                    sw0_flag = 0;
                    init_flag = 0;
                    GetOpampConfig(); // Update state of RA5 / RA4 to determine OPA configuration;
                }
                SLEEP();
                break;

            case 3:
                if (init_flag == 0) {
                    BlinkLED(opa_config);
                    OPA_NonInverting();
                    init_flag = 1;
                } else if (sw0_flag == 1) {
                    sw0_flag = 0;
                    init_flag = 0;
                    GetOpampConfig(); // Update state of RA5 / RA4 to determine OPA configuration;
                }
                SLEEP();
                break;

            case 4:
                if (init_flag == 0) {
                    BlinkLED(opa_config);
                    OPA_Inverting();
                    init_flag = 1;
                } else if (sw0_flag == 1) {
                    sw0_flag = 0;
                    init_flag = 0;
                    GetOpampConfig(); // Update state of RA5 / RA4 to determine OPA configuration;
                }
                SLEEP();
                break;

            default:
                printf("OPA Configuration Input Error! \r\n");
                break;
        }
    }
}


/**
 End of File
 */