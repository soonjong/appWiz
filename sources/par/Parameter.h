/** --------------------------------------------------------------------------------------------
    @file           Parameter.h
    @brief          parameter header for application wizard project
    @version        0.01
    @warning        
    @instruction    It is not allowed to change this file arbitrarily without permission.
                    If you have a good way to change to a better direction, please contact me.
    @author         Jin, Soonjong (soonjong.jin@gmail.com)
    @date           revision history
                    2020. 11/11: files is created by JIn
-------------------------------------------------------------------------------------------- **/
#ifndef PARAMETER_H
#define PARAMETER_H

#ifndef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** --------------------------------------------------------------------------------------------
    including header files
-------------------------------------------------------------------------------------------- **/
#include "../TypeDef.h"
#include "RunMode.h"
#include "ImgSeq.h"
#include "../RetCode.h"
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
class Parameter
{
private:
	RunMode 	app_sd;
	RunMode		app_od;


	ImgSeq		capture_img_seq;
	ImgSeq		display_img_seq;


public:
    /* setter */
    /* getter */
    const RunMode* getRunModeAppSd() const noexcept { return &app_sd; }
    const RunMode* getRunModeAppOd() const noexcept { return &app_od; }
    const ImgSeq*  getImgSeqCapture() const noexcept { return &capture_img_seq; }
    const ImgSeq*  getImgSeqDisplay() const noexcept { return &display_img_seq; }
    /* shower */
    /* constructor */
    /* copy constructor */
    /* move constructor */
    /* copy assignment operator */
    /* move assignment operator */
    /* destructor */
    /* functions */
    RET_CODE parser(const STRING& inp_arg);
    void     show_usage_message (const STRING& inp_arg) const;
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

#endif /* PARAMETER_H */
