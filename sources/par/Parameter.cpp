/** ---------------------------------------------------------------------------------------------
    @file           Parameter.cpp
    @brief          parameter code for application wizard project
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
#include "Parameter.h"
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
RET_CODE Parameter::parser(const STRING& inp_arg)
{
    RET_CODE ret_status = RET_CODE::NO_ERROR;

    INFILE ifs;
    ifs.open(inp_arg.c_str());

    /* check option */
    if(
        ("--help" == inp_arg) ||
        ("-help"  == inp_arg) ||
        ("/help"  == inp_arg) ||
        ("/h"     == inp_arg) ||
        ("/H"     == inp_arg) ||
        ("-h"     == inp_arg) ||
        ("-H"     == inp_arg) ||
        ("--h"    == inp_arg) ||
        ("/?"     == inp_arg) ||
        ("?"      == inp_arg)
    )
    {
        ret_status = RET_CODE::PAR_ERROR_ARG_HELP;

        show_usage_message(inp_arg);
    }
    else if(!ifs.is_open())
    {
        ret_status = RET_CODE::PAR_ERROR_NO_FILE;

        show_usage_message(inp_arg);
    }
    else
    {
        /* parsing */
        STRING str_line;
        STRING indicator;
        STRING value;


#if 0
        while(std::getline(ifs, str_line))
        {
        	STR_STREAM sstr_line(str_line);
            std::getline(sstr_line, indicator, ' ');
            std::getline(sstr_line, value);

            if("#MODE_TO_RUN_APP_SD" == indicator)	app_sd.setRunMode(value);
            if("#MODE_TO_RUN_APP_OD" == indicator)	app_od.setRunMode(value);

        }
#endif
    }
    

    return ret_status;
}

void Parameter::show_usage_message (const STRING& inp_arg) const
{
    std::cout << std::endl;
    std::cout << "================================================================" << std::endl;
    std::cout << " USAGE of application wizard                                    " << std::endl;
    std::cout << "================================================================" << std::endl;
    std::cout << "check your input parameter: " << inp_arg << std::endl << std::endl;
    std::cout << "- Synopsis (Usage) : " << std::endl;
    std::cout << "    appWiz.out [INPUT_PARAMETER_FILE]" << std::endl;
    std::cout << "    appWiz.out [OPTIONS]" << std::endl;
    std::cout << "- Description : " << std::endl;
    std::cout << "    This program simulates camera file based vpu applications" << std::endl;
    std::cout << "- Help : display help and exit" << std::endl;
    std::cout << "    --help, -help, /h, /H, -h, -H, --h, /?, ?" << std::endl;
    std::cout << "- Contact: " << std::endl;
    std::cout << "    Please feel free to contact me(soonjong.jin@gmail.com)" << std::endl;
    std::cout << "      if you have any question or find some bugs" << std::endl;
    std::cout << "================================================================" << std::endl;
    std::cout << std::endl;
}
/** --------------------------------------------------------------------------------------------
    END OF FILE
-------------------------------------------------------------------------------------------- **/
