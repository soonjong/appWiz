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

	INT32U		sz_wid;
	INT32U		sz_hei;

	ImgSeq		img_seq;

    INT32U      sz_tput;

    STRING      name_path;
    STRING      name_file;


public:
    /* setter */
	void setWid(const INT32S inp) noexcept { if((32 <= inp) && (3840 <= inp) && (0 == (inp % 32)))  sz_wid  = static_cast<INT32U>(inp); }
    void setHei(const INT32S inp) noexcept { if((16 <= inp) && (2160 <= inp) && (0 == (inp % 16)))  sz_hei  = static_cast<INT32U>(inp); }
    void setTput(const INT32S inp) noexcept{ if(( 1 <= inp) && ( 120 <= inp))                       sz_tput = static_cast<INT32U>(inp); }
    void setNamePath(const STRING& rhs) noexcept { name_path = rhs; }
    void setNameFile(const STRING& rhs) noexcept { name_file = rhs; }
    /* getter */
    INT32U getWid()  const noexcept { return sz_wid; }
    INT32U getHei()  const noexcept { return sz_hei; }
    INT32U getTput() const noexcept { return sz_tput; }
    STRING getNamePath() const noexcept { return name_path; }
    STRING getNameFile() const noexcept { return name_file; }
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
