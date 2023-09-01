<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# PIC18F16Q41 Curiosity Nano OPAMP Demonstration Firmware

The PIC18F16Q41 Curiosity Nano Evaluation Kit is preprogramed to demonstrate the Operational Amplifier (OPA or OPAMP) module and provide a number of different OPAMP configurations. The OPA configuration depends on the state of two input pins: RA4 and RA5. Each of these pins is internally pulled high using the Weak Pull-up functionality built into the pad. If left unconnected, the corresponding pin will be high and read logic '```1```'. Connect the pin directly to ground for logic '```0```'. When updating the OPA configuration, the onboard LED0 will blink a number of times equal to the selected setting. To check the current setting or reconfigure the OPA, press SW0 on the Curiosity Nano board.

<img src="images/modes_of_operation.jpg" alt="MCHP" width="500"/></a>

## Related Documentation

- [PIC18F16Q41 Curiosity Nano User Guide](https://ww1.microchip.com/downloads/en/DeviceDoc/PIC18F16Q41-Curiosity-Nano-Hardware-User-Guide-DS50003048A.pdf)
- [PIC18F16Q41 Device Page](https://www.microchip.com/wwwproducts/en/PIC18F16Q41)

## Software Used:

- [MPLAB® X IDE 6.05](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide) or newer
- [MPLAB® XC8 2.41](hhttps://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilersttp://www.microchip.com/mplab/compilers) or a newer compiler
- [MPLAB® Code Configurator (MCC) 5.5.7](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator) or newer
- [Microchip PIC18F-Q Series Device Support (1.20.405)](https://packs.download.microchip.com/) or newer

## Hardware Used

- [PIC18F16Q41 Curiosity Nano](https://www.microchip.com/en-us/development-tool/ev26q64a)

## Setup

A brand new PIC18F16Q41 Curiosity Nano comes with the code in this repository preprogrammed onto the device. This demo code can be reprogrammed to the PIC18F16Q41 by copying the hex file onto the CURIOSITY virtual drive that shows up once the Nano board is plugged into a PC. The entire project can also be accessed using MPLAB X IDE 6.05 or a newer version.

## Operation

The OPA configuration is determined based on the logic levels of the RA4 and RA5 pins. To select the OPA configuration, set RA4 and RA5 pins according to the table below. After setting the pins to match the desired OPA configuration, press SW0 to update the OPA module configuration and resume operation. The PIC18F16Q41 operates in Sleep mode with the OPA enabled when not being reconfigured.

| RA5 | RA4 | Configuration                                 |  
| --- | --- | ----------------------------------------------|
|  ```0```  |  ```0```  | 1 - Connected directly to external pins       |
|  ```0```  |  ```1```  | 2 - Unity Gain Buffer/Voltage Follower        |
|  ```1```  |  ```0```  | 3 - Noninverting Programmable Gain Amplifier |
|  ```1```  |  ```1```  | 4 - Inverting Programmable Gain Amplifier     |

**Note:** Weak Pull-ups are enabled on RA4 and RA5 pins in this code example, so unless each pin is directly connected to ground, they will read as logic '```1```' when setting up the OPA module configuration.

### Configuration 1: Connected Directly to External Pins

In this configuration, both of the OPA inputs and the output are connected directly to the corresponding Input/Output (I/O) pins. This allows the OPA to be used on its own with external discrete components to provide a feedback network and achieve a specific functionality.

| OPAMP | OPA1IN+       | OPA1IN-       | OUTPUT        |
| ----- | -------       | --------------| ------------- |
| OPA1  | RC3 (OPA1IN1+)| RA2 (OPA1IN2-)| RC2 (OPA1OUT) |

<img src="images/OPA_External.png" alt="MCHP" width="500"/></a>

### Configuration 2: Unity Gain Buffer

In this configuration, the OPA is configured as a unity gain buffer (voltage follower). When configured in this mode, only the positive input of the OPA (OPA1IN+) and the output (OPA1OUT) are connected to the external I/O pins, while the negative input of the OPA (OPA1IN-) is internally connected to the output of the OPA to form a unity gain buffer, as shown in the figure below.

| OPA   | Positive Input  | Output (OUT)  |
| :----:|:--------------: | :-----------: |
| OPA1  |  RC3 (OPA1IN1+) | RC2 (OPA1OUT) |

<img src="images/OPA_UnityGainBuffer.png" alt="MCHP" width="500"/></a>

### Configuration 3: Noninverting Programable Gain Amplifier (PGA)

In this configuration, the OPA is configured as a noninverting PGA and uses the internal resistor ladder built into the OPA module. The positive input (OPA1IN+) and the output (OPA1OUT) of the OPA are connected to the corresponding I/O pins. The OPA is preconfigured with a gain of '4' using the internal resistor ladder. This gain can be changed by writing a different value to the GSEL bits of OPA1CON1 in the function named ```void OPA_NonInverting(void)``` located in ```application.c```.

| OPA    | Gain | Positive Input   | Output (OUT)  |
| :----: | :--: | :--------------: | :-----------: |
| OPA1   |  4   | RC3 (OPA1IN1+)   | RC2 (OPA1OUT) |

<img src="images/OPA_NonInvertingPGA.png" alt="MCHP" width="500"/></a>

<img src="images/OPA_NonInverting_Gain.PNG" alt="MCHP" width="250"/></a>

### Configuration 4: Inverting PGA

In this configuration, the OPA is configured as an inverting PGA and used the internal resistor ladder built into the OPA module. The OPA is preconfigured with a gain of '3' using the internal resistor ladder. This gain can be changed by writing a different value to the GSEL bits of OPA1CON1 in the function named ```void OPA_Inverting(void)``` located in ```application.c```.

| OPA    | Gain | Positive Input   | Output (OUT)  |
| :----: | :--: | :--------------: | :-----------: |
| OPA1   |  3   | RA2 (OPA1IN2-)   | RC2 (OPA1OUT) |

<img src="images/OPA_InvertingPGA.png" alt="MCHP" width="500"/></a>

<img src="images/OPA_InvertingGain.PNG" alt="MCHP" width="350"/></a>
