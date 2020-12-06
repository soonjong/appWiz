/** ---------------------------------------------------------------------------------------------
    @file           appWiz.cpp
    @brief          main for application wizard project
    @version        0.01
    @warning        
    @instruction    It is not allowed to change this file arbitrarily without permission.
                    If you have a good way to change to a better direction, please contact me.
    @author         Jin, Soonjong (soonjong.jin@gmail.com)
    @date           revision history
                    2020. 11/11: files is created by JIn
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    including header files
-------------------------------------------------------------------------------------------- **/
#include "TypeDef.h"
#include "RetCode.h"
#include "par/Parameter.h"
#include <thread>
#include <mutex>
/** --------------------------------------------------------------------------------------------
    including library files
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    file scope constants
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    file scope enumeration
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    file scope macros
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    file scope type definitions
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    file scope variables
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    file scope function prototypes
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    file scope function lists
-------------------------------------------------------------------------------------------- **/
int main(int argc, char* argv[])
{
	RET_CODE ret_status = RET_CODE::NO_ERROR;
	Parameter par;
	const STRING inp_arg_str((1 == argc) ? "parameters/default.par" : argv[1]);

	ret_status = par.parser(inp_arg_str);

	if(RET_CODE::NO_ERROR == ret_status)
	{
        std::mutex lock_capture;
        std::mutex lock_display;
        std::thread capture(std::ref(par), std::ref(lock_capture));
        std::thread display(std::ref(par), std::ref(lock_display));

	}

	if(RET_CODE::NO_ERROR == ret_status)
	{

	}


	return ((RET_CODE::NO_ERROR == ret_status) ? 0 : 1);
}

void app_od_preproc(Parameter& inp_par, std::mutex& mtx)
{
    const INT32U inp_buf = inp_par.getImgSeqCapture().getIdxCurrBuf();
 
    mtx.lock();
    mtx.unlock();
}

void app_od_mainproc(Parameter& inp_par, std::mutex&&mtx)
{
    const INT32U capture
}
void capture(Parameter& inp_par, std::mutex& mtx)
{
    ImgSeq& img_seq_capture = inp_par.getImgSeqCapture();

    const INT32U next_buf = img_seq_capture.getIdxNextBuf();

    //capture with idx next buf!! 

    mtx.lock();
    img_seq_capture.switchIdxBuf();
    mtx.unlock();
}

void display(Parameter& inp_par, std::mutex& mtx)
{
    ImgSeq& img_seq_display = inp_par.getImgSeqDisplay();


    mtx.lock();
    img_seq_display.switchIdxBuf();
    mtx.unlock();
}
/** --------------------------------------------------------------------------------------------
    END OF FILE
-------------------------------------------------------------------------------------------- **/
