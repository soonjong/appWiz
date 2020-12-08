/** --------------------------------------------------------------------------------------------
    @file           AppSD.h
    @brief          Space Detection Application eader for application wizard project
    @version        0.01
    @warning        
    @instruction    It is not allowed to change this file arbitrarily without permission.
                    If you have a good way to change to a better direction, please contact me.
    @author         Jin, Soonjong (soonjong.jin@gmail.com)
    @date           revision history
                    2020. 12/06: files is created by JIn
-------------------------------------------------------------------------------------------- **/
#ifndef APP_SD_H
#define APP_SD_H

#ifndef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** --------------------------------------------------------------------------------------------
    including header files
-------------------------------------------------------------------------------------------- **/
#include "../TypeDef.h"
#include "../DualBuffer.h"
/** --------------------------------------------------------------------------------------------
    global constants
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global enumerations
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global macros
--------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global type definitions
-------------------------------------------------------------------------------------------- **/
class AppSD
{
private:
    /* I/F */
    DualBuffer<INT16S>  out_preproc_dbuf;
    DualBuffer<FP32>    out_mainproc_dbuf;
    

public:
    /* functions */
    /* constructor */
    /* copy constructor */
    explicit AppSD(const AppSD& rhs) = delete;
    /* move constructor */
    explicit AppSD(AppSD&& rhs) = delete;
    /* copy assignment operator */
    AppSD& operator =(const AppSD& rhs) = delete;
    /* move assignment operator */
    AppSD& operator =(AppSD&& rhs) = delete;
    /* destructor */
    virtual ~AppSD() {}
    /* setter */
    /* getter */
    /* shower */
};

/** --------------------------------------------------------------------------------------------
    global variables
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global function prototypes
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global function lists
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    END OF FILE
-------------------------------------------------------------------------------------------- **/
#ifndef __cplusplus
}
#endif /* __cplusplus */

#endif /* APP_SD_H */
