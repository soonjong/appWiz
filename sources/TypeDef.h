/** --------------------------------------------------------------------------------------------
    @file           TypeDef.h
    @brief          type definition for application wizard project
    @version        0.01
    @warning        
    @instruction    It is not allowed to change this file arbitrarily without permission.
                    If you have a good way to change to a better direction, please contact me.
    @author         Jin, Soonjong (soonjong.jin@gmail.com)
    @date           revision history
                    2020. 11/11: files is created by JIn
-------------------------------------------------------------------------------------------- **/
#ifndef TYPE_DEF_H
#define TYPE_DEF_H

#ifndef __cplusplus
extern "C" {
#endif /* __cplusplus */
/** --------------------------------------------------------------------------------------------
    including header files
-------------------------------------------------------------------------------------------- **/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
/** --------------------------------------------------------------------------------------------
    global constants
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global enumerations
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global macros
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global type definitions
-------------------------------------------------------------------------------------------- **/
using INT8U  = unsigned char;
using INT8S  = signed char;
using INT16U = unsigned short;
using INT16S = signed short;
using INT32U = unsigned int;
using INT32S = signed int;
using INT64U = unsigned long long;
using INT64S = signed long long;
using FP32   = float;
using FP64   = double;

using BOOL   = bool;

using STRING     = std::string;
using STR_STREAM = std::stringstream;

using OSTREAM    = std::ostream;
using ISTREAM    = std::istream;

using INFILE     = std::ifstream;
using OUTFILE    = std::ofstream;
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

#endif /* TYPE_DEF_H */
