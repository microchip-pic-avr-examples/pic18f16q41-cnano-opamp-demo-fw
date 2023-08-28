/* 
 * File:   application.h
 * Author: C16783
 *
 * Created on August 26, 2020, 9:24 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#ifdef	__cplusplus
extern "C" {
#endif


    int init_flag = 0;
    uint8_t sw0_flag = 0;

    enum opa_mode {
        EXTERNAL = 1,
        UNITY_GAIN = 2,
        NON_INVERTING = 3,
        INVERTING = 4
    } opa_config;

    void IntroSplashMessage(void);
    void GetOpampConfig(void);
    void BlinkLED(int8_t cnt);
    void CLC1_InterruptHandler(void);
    void OPA_External(void);
    void OPA_UnityGain(void);
    void OPA_NonInverting(void);
    void OPA_Inverting(void);

#ifdef	__cplusplus
}
#endif

#endif	/* APPLICATION_H */

