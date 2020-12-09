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
const INT32U sz_elmt_map[] = { 0U, 1U, 1U, 2U, 2U, 4U, 4U, 6U, 6U, 2U, 4U, 8U, 0U};
/** --------------------------------------------------------------------------------------------
    global enumerations
-------------------------------------------------------------------------------------------- **/
enum class SEQ_FMT : INT32U {       UNKNOWN     =  0U,
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

enum class SEQ_TYPE : INT32U {      UNK =  0U,
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
                                    F64 = 11U,
                                    MAX = 12U };
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
    SEQ_FMT     seq_fmt;
    SEQ_TYPE    seq_type;

    INT32U      sz_tput;

    STRING      name_path;
    STRING      name_file;

    INT32U      idx_curr_buf;
    INT32U      idx_next_buf;

    INT32U      sz_wid;
    INT32U      sz_hei;
    INT32U      sz_elmt;

    INT8U*      p_buf[2];

    INT32U      is_captured;

    FILE*       fp;

public:
    /* functions */
    void switchIdxBuf();
    /* constructor */
    explicit ImgSeq() noexcept;// : status(FILE_STATUS::NOT_OPENED), seq_fmt(SEQ_FMT::UNKNOWN), seq_type(SEQ_TYPE::UNK), sz_wid(0U), sz_hei(0U), sz_tput(0U), name_path(""), name_file(""), idx_curr_buf(0U), idx_next_buf(1U)
    /* copy constructor */
    explicit ImgSeq(const ImgSeq& rhs) = delete;
    /* move constructor */
    explicit ImgSeq(ImgSeq&& rhs) = delete;
    /* copy assignment operator */
    ImgSeq& operator =(const ImgSeq& rhs) = delete;
    /* move assignment operator */
    ImgSeq& operator =(ImgSeq&& rhs) = delete;
    /* destructor */
    virtual ~ImgSeq();
    /* setter */
    void setStatus() = delete;
    void setStatus(const FILE_STATUS& rhs) noexcept;
    void setStatus(const bool& rhs) = delete;
    void setSeqFmt() = delete;
    void setSeqFmt(const STRING& rhs) noexcept;
    void setSeqFmt(const INT32S rhs) noexcept;
    void setSeqType() = delete;
    void setSeqType(const STRING& rhs) noexcept;
    void seqSeqType(const INT32S rhs) noexcept;
    void setWid(const INT32S inp) noexcept;
    void setHei(const INT32S inp) noexcept;
    void setTput(const INT32S inp) noexcept;
    void setNamePath() = delete;
    void setNamePath(const STRING& rhs) noexcept ;
    void setNameFile() = delete;
    void setNameFile(const STRING& rhs) noexcept;
    /* getter */
    FILE_STATUS getStatus() const noexcept { return status; }
    SEQ_FMT     getSeqFmt() const noexcept { return seq_fmt; }
    INT32U      getWid()  const noexcept { return sz_wid; }
    INT32U      getHei()  const noexcept { return sz_hei; }
    INT32U      getTput() const noexcept { return sz_tput; }
    STRING      getNamePath() const noexcept { return name_path; }
    STRING      getNameFile() const noexcept { return name_file; }
    INT32U      getIdxCurrBuf() const noexcept { return idx_curr_buf; }
    INT32U      getIdxNextBuf() const noexcept { return idx_next_buf; }
    /* shower */
    friend OSTREAM& operator << (OSTREAM& os, const ImgSeq& rhs) noexcept;
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
