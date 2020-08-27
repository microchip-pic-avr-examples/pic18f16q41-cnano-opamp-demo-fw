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

    int opa_config = 0;
    int init_flag = 0;
    
    void IntroSplashMessage(void);
    void GetOpampConfig(void);
    void BlinkLED(int8_t cnt);
    void OPA_External(void);
    void OPA_UnityGain(void);
    void OPA_NonInverting(void);
    void OPA_Inverting(void);

#ifdef	__cplusplus
}
#endif

#endif	/* APPLICATION_H */

