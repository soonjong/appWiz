/** --------------------------------------------------------------------------------------------
    @file           FileStatus.h
    @brief          file status header for application wizard project
    @version        0.01
    @warning        
    @instruction    It is not allowed to change this file arbitrarily without permission.
                    If you have a good way to change to a better direction, please contact me.
    @author         Jin, Soonjong (soonjong.jin@gmail.com)
    @date           revision history
                    2020. 11/11: files is created by JIn
-------------------------------------------------------------------------------------------- **/
#ifndef FILE_STATUS_H
#define FILE_STATUS_H

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
enum class FILE_STATUS : INT32U {	NOT_OPENED = 0U,
                                    IS_OPENED = 1U };
/** --------------------------------------------------------------------------------------------
    global macros
--------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global type definitions
-------------------------------------------------------------------------------------------- **/
class FileStatus
{
private:
    FILE_STATUS	status;
public:
    /* setter */
    void setStatus() = delete;
    void setStatus(const FILE_STATUS& rhs) noexcept { status = rhs; }
    void setStatus(const bool& rhs) = delete;
    /* getter */
    FILE_STATUS getStatus() const noexcept { return status; }
    /* shower */
    friend OSTREAM& operator << (OSTREAM& os, const FileStatus& rhs) noexcept{
        os << (FILE_STATUS::NOT_OPENED == rhs.status) ? "NOT_OPENED" : "IS_OPENED";
        return os;
    }
    /* constructor */
    explicit FileStatus() noexcept : status(FILE_STATUS::NOT_OPENED) {}
    /* copy constructor */
    explicit FileStatus(const FileStatus& rhs) = delete;
    /* move constructor */
    explicit FileStatus(FileStatus&& rhs) = delete;
    /* copy assignment operator */
    FileStatus& operator =(const FileStatus& rhs) = delete;
    /* move assignment operator */
    FileStatus& operator =(FileStatus&& rhs) = delete;
    /* destructor */
    virtual ~FileStatus() {}
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

#endif /* FILE_STATUS_H */
