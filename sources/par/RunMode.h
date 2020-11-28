/** --------------------------------------------------------------------------------------------
    @file           RunMode.h
    @brief          running mode header for application wizard project
    @version        0.01
    @warning        
    @instruction    It is not allowed to change this file arbitrarily without permission.
                    If you have a good way to change to a better direction, please contact me.
    @author         Jin, Soonjong (soonjong.jin@gmail.com)
    @date           revision history
                    2020. 11/11: files is created by JIn
-------------------------------------------------------------------------------------------- **/
#ifndef RUN_MODE_H
#define RUN_MODE_H

#ifndef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** --------------------------------------------------------------------------------------------
    including header files
-------------------------------------------------------------------------------------------- **/
#include "../TypeDef.h"
/** --------------------------------------------------------------------------------------------
    global constants
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global enumerations
-------------------------------------------------------------------------------------------- **/
enum class RUN_MODE : INT32U {   SKIP = 0U, RUN = 1U };
/** --------------------------------------------------------------------------------------------
    global macros
--------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global type definitions
-------------------------------------------------------------------------------------------- **/
class RunMode
{
private:
    RUN_MODE mode;

public:
    /* setter */
    void setRunMode() = delete;
    void setRunMode(const bool& rhs) = delete;
    void setRunMode(const RUN_MODE& rhs) noexcept { mode = rhs; }
    void setRunMode(const STRING& rhs) noexcept { mode = ("RUN" == rhs) ? RUN_MODE::RUN : RUN_MODE::SKIP; }
    /* getter */
    RUN_MODE getRunMode() const noexcept { return mode; }
    /* shower */
    friend OSTREAM& operator << (OSTREAM& os, const RunMode& rhs) noexcept{
        os << (RUN_MODE::SKIP == rhs.mode) ? "SKIP" : "RUN";
        return os;
    }
    /* constructor */
    explicit RunMode() noexcept : mode(RUN_MODE::SKIP) {}
    explicit RunMode(const RUN_MODE& rhs) noexcept : mode(rhs) {}
    explicit RunMode(const BOOL& rhs) = delete;
    /* copy constructor */
    explicit RunMode(const RunMode& rhs) noexcept : mode(rhs.mode) {}
    /* move constructor */
    explicit RunMode(RunMode&& rhs) noexcept : mode(std::move(rhs.mode)) {}
    /* copy assignment operator */
    RunMode& operator =(const RunMode& rhs) noexcept {	mode = rhs.mode;
    													return *this; }
    /* move assignment operator */
    RunMode& operator =(RunMode&& rhs) noexcept { 	mode = std::move(rhs.mode);
    												return *this; }
    /* destructor */
    virtual ~RunMode() {}
    /* functions */
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

#endif /* RUN_MODE_H */
