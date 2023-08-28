 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
� [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "application.h"

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Set ClC1 interrupt callback function allows to switch opa_config while switch0 pressed.
    CLC1_CLCI_SetInterruptHandler(CLC1_InterruptHandler);

    IntroSplashMessage();
    GetOpampConfig();

    while(1)
    {
        //printf("init_flag=%d, sw0_flag=%d\n", init_flag, sw0_flag);
        switch (opa_config) {
            case EXTERNAL:
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

            case UNITY_GAIN:
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

            case NON_INVERTING:
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

            case INVERTING:
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