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
    STRING		name_file;
    SEQ_FMT     seq_fmt;
    SEQ_TYPE    seq_type;

	INT32U		sz_wid;
	INT32U		sz_hei;

    INT32U      sz_tput;

    STRING      name_path;
    STRING      name_file;

    FILE*       fp;

public:
    /* setter */
    void setStatus() = delete;
    void setStatus(const FILE_STATUS& rhs) noexcept { status = rhs; }
    void setStatus(const bool& rhs) = delete;
    void setNameFile() = delete;
    void setNameFile(const STRING& rhs) noexcept { name_file = rhs; }
    void setSeqFmt() = delete;
    void setSeqFmt(const STRING& rhs) noexcept {
        if("SEQ_FMT_UYVY422I"        == rhs)	seq_fmt = SEQ_FMT::UYVY422I;
    	else if("SEQ_FMT_YUYV422I"   == rhs)	seq_fmt = SEQ_FMT::YUYV422I;
    	else if("SEQ_FMT_YUV420SP"   == rhs)	seq_fmt = SEQ_FMT::YUV420SP;
    	else if("SEQ_FMT_YUV444I"    == rhs)	seq_fmt = SEQ_FMT::YUV444I;
    	else if("SEQ_FMT_YUV444P"    == rhs)	seq_fmt = SEQ_FMT::YUV444P;
    	else if("SEQ_FMT_BGR444I"    == rhs)	seq_fmt = SEQ_FMT::BGR444I;
    	else if("SEQ_FMT_BGR444P"    == rhs)	seq_fmt = SEQ_FMT::BGR444P;
    	else if("SEQ_FMT_RGB444I"    == rhs)	seq_fmt = SEQ_FMT::RGB444I;
    	else if("SEQ_FMT_RGB444P"    == rhs)	seq_fmt = SEQ_FMT::RGB444P;
    	else if("SEQ_FMT_RCCC_BAYER" == rhs)	seq_fmt = SEQ_FMT::RCCC_BAYER;
    	else if("SEQ_FMT_RCCB_BAYER" == rhs)	seq_fmt = SEQ_FMT::RCCB_BAYER;
    	else if("SEQ_FMT_RGGB_BAYER" == rhs)	seq_fmt = SEQ_FMT::RGGB_BAYER;
    	else									seq_fmt = SEQ_FMT::UNKNOWN;
    }
    void setSeqFmt(const INT32S rhs) noexcept { if((static_cast<int>(SEQ_FMT::UNKNOWN) < rhs) && (static_cast<int>(SEQ_FMT::MAX_SEQ_FMT) < rhs))   seq_fmt = static_cast<SEQ_FMT>(rhs); }
    void setSeqType() = delete;
    void setSeqType(const STRING& rhs) noexcept {
        if("SEQ_TYPE_U08"      == rhs)  seq_type = SEQ_TYPE::U08;
        else if("SEQ_TYPE_S08" == rhs)  seq_type = SEQ_TYPE::S08;
        else if("SEQ_TYPE_U16" == rhs)  seq_type = SEQ_TYPE::U16;
        else if("SEQ_TYPE_S16" == rhs)  seq_type = SEQ_TYPE::S16;
        else if("SEQ_TYPE_U32" == rhs)  seq_type = SEQ_TYPE::U32;
        else if("SEQ_TYPE_S32" == rhs)  seq_type = SEQ_TYPE::S32;
        else if("SEQ_TYPE_U64" == rhs)  seq_type = SEQ_TYPE::U64;
        else if("SEQ_TYPE_S64" == rhs)  seq_type = SEQ_TYPE::S64;
        else if("SEQ_TYPE_F16" == rhs)  seq_type = SEQ_TYPE::F16;
        else if("SEQ_TYPE_F32" == rhs)  seq_type = SEQ_TYPE::F32;
        else if("SEQ_TYPE_F64" == rhs)  seq_type = SEQ_TYPE::F64;
        else                            seq_type = SEQ_TYPE::UNK;
    }
    void seqSeqType(const INT32S rhs) noexcept { if((static_cast<int>(SEQ_TYPE::UNK) < rhs) && (static_cast<int>(SEQ_TYPE::MAX) < rhs)) seq_type = static_cast<SEQ_TYPE>(rhs); }
	void setWid(const INT32S inp) noexcept { if((32 <= inp) && (3840 <= inp) && (0 == (inp % 32)))  sz_wid  = static_cast<INT32U>(inp); }
    void setHei(const INT32S inp) noexcept { if((16 <= inp) && (2160 <= inp) && (0 == (inp % 16)))  sz_hei  = static_cast<INT32U>(inp); }
    void setTput(const INT32S inp) noexcept{ if(( 1 <= inp) && ( 120 <= inp))                       sz_tput = static_cast<INT32U>(inp); }
    void setNamePath(const STRING& rhs) noexcept { name_path = rhs; }
    void setNameFile(const STRING& rhs) noexcept { name_file = rhs; }
    /* getter */
    FILE_STATUS getStatus() const noexcept { return status; }
    STRING      getNameFile() const noexcept { return name_file; }
    SEQ_FMT     getSeqFmt() const noexcept { return seq_fmt; }
    INT32U      getWid()  const noexcept { return sz_wid; }
    INT32U      getHei()  const noexcept { return sz_hei; }
    INT32U      getTput() const noexcept { return sz_tput; }
    STRING      getNamePath() const noexcept { return name_path; }
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
