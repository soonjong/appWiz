/** --------------------------------------------------------------------------------------------
    @file           ImgSeq.h
    @brief          image sequence header for application wizard project
    @version        0.01
    @warning        
    @instruction    It is not allowed to change this file arbitrarily without permission.
                    If you have a good way to change to a better direction, please contact me.
    @author         Jin, Soonjong (soonjong.jin@gmail.com)
    @date           revision history
                    2020. 11/11: files is created by JIn
-------------------------------------------------------------------------------------------- **/
#ifndef IMG_SEQ_H
#define IMG_SEQ_H

#ifndef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** --------------------------------------------------------------------------------------------
    including header files
-------------------------------------------------------------------------------------------- **/
#include "../TypeDef.h"
#include "FileStatus.h"
/** --------------------------------------------------------------------------------------------
    global constants
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global enumerations
-------------------------------------------------------------------------------------------- **/
enum class SEQ_FMT : INT32U {		UNKNOWN     =  0U,
									UYVY422I    =  1U,
									YUYV422I    =  2U,
									YUV420SP    =  3U,
									YUV444I	    =  4U,
									YUV444P     =  5U,
									BGR444I     =  6U,
									BGR444P     =  7U,
									RGB444I     =  8U,
									RGB444P     =  9U,
									RCCC_BAYER  = 10U,
									RCCB_BAYER  = 11U,
									RGGB_BAYER  = 12U, 
                                    MAX_SEQ_FMT = 13U };

enum class SEQ_TYPE : INT32U {		UNK =  0U,
									U08 =  1U,
									S08 =  2U,
									U16 =  3U,
									S16 =  4U,
									U32 =  5U,
									S32 =  6U,
									U64 =  7U,
									S64 =  8U,
									F16 =  9U,
									F32 = 10U,
									F64 = 11U };
/** --------------------------------------------------------------------------------------------
    global macros
--------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    global type definitions
-------------------------------------------------------------------------------------------- **/
class ImgSeq : public FileStatus
{
private:
    FILE_STATUS	status;
    STRING		name_file;
    SEQ_FMT     seq_fmt;

    FILE*       fp;

public:
    /* setter */
    void setStatus() = delete;
    void setStatus(const FILE_STATUS& rhs) noexcept { status = rhs; }
    void setStatus(const bool& rhs) = delete;
    void setNameFile() = delete;
    void setNameFile(const STRING& rhs) noexcept { name_file = rhs; }
    void setSeqFmt(const INT32S rhs) noexcept { if((static_cast<int>(SEQ_FMT::UNKNOWN) < rhs) && (static_cast<int>(SEQ_FMT::MAX_SEQ_FMT) < rhs))   seq_fmt = static_cast<SEQ_FMT>(rhs); }
    /* getter */
    FILE_STATUS getStatus() const noexcept { return status; }
    STRING      getNameFile() const noexcept { return name_file; }
    /* shower */
    friend OSTREAM& operator << (OSTREAM& os, const ImgSeq& rhs) noexcept{
        os << rhs.name_file << " - " << (FILE_STATUS::NOT_OPENED == rhs.status) ? "NOT_OPENED" : "IS_OPENED";
        return os;
    }
    /* constructor */
    explicit ImgSeq() noexcept : status(FILE_STATUS::NOT_OPENED), name_file(""), fp(nullptr) {}
    /* copy constructor */
    explicit ImgSeq(const ImgSeq& rhs) = delete;
    /* move constructor */
    explicit ImgSeq(ImgSeq&& rhs) = delete;
    /* copy assignment operator */
    ImgSeq& operator =(const ImgSeq& rhs) = delete;
    /* move assignment operator */
    ImgSeq& operator =(ImgSeq&& rhs) = delete;
    /* destructor */
    virtual ~ImgSeq() {}
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

#endif /* IMG_SEQ_H */
