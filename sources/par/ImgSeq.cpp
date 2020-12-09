/** ---------------------------------------------------------------------------------------------
    @file           ImgSeq.cpp
    @brief          image sequence source for application wizard project
    @version        0.01
    @warning        
    @instruction    It is not allowed to change this file arbitrarily without permission.
                    If you have a good way to change to a better direction, please contact me.
    @author         Jin, Soonjong (soonjong.jin@gmail.com)
    @date           revision history
                    2020. 12/09: files is created by JIn
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    including header files
-------------------------------------------------------------------------------------------- **/
#include "ImgSeq.h"
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
/* functions */
void ImgSeq::switchIdxBuf()
{
    idx_curr_buf = (idx_curr_buf + 1U) & 0x01;
    idx_next_buf = (idx_next_buf + 1U) & 0x01;
}
/* constructor */
ImgSeq::ImgSeq() noexcept : status(FILE_STATUS::NOT_OPENED), 
                            seq_fmt(SEQ_FMT::UNKNOWN), 
                            seq_type(SEQ_TYPE::UNK), 
                            sz_wid(0U), 
                            sz_hei(0U), 
                            sz_tput(0U), 
                            name_path(""), 
                            name_file(""), 
                            idx_curr_buf(0U), 
                            idx_next_buf(1U), 
                            is_captured(0U),
                            fp(nullptr)
{
    sz_elmt = sz_elmt_map[static_cast<INT32U>(seq_type)];

    if((0U == sz_wid) || (0U == sz_hei)|| (0U == sz_elmt))
    {
        p_buf[idx_curr_buf] = nullptr;
        p_buf[idx_next_buf] = nullptr;
    }
    else
    {
        p_buf[idx_curr_buf] = new INT8U [(sz_elmt * sz_wid * sz_hei)];
        p_buf[idx_next_buf] = new INT8U [(sz_elmt * sz_wid * sz_hei)];
    }
}
/* copy constructor */
/* move constructor */
/* copy assignment operator */
/* move assignment operator */
/* destructor */
ImgSeq::~ImgSeq()
{
    if(nullptr != p_buf[idx_curr_buf])
    {
        delete [] p_buf[idx_curr_buf];
        p_buf[idx_curr_buf] = nullptr;
    }
    if(nullptr != p_buf[idx_next_buf])
    {
        delete [] p_buf[idx_next_buf];
        p_buf[idx_next_buf] = nullptr;
    }
}
/* setter */
void ImgSeq::setStatus(const FILE_STATUS& rhs) noexcept
{
    status = rhs;
}
void ImgSeq::setSeqFmt(const STRING& rhs) noexcept
{
    if("SEQ_FMT_UYVY422I"        == rhs)    seq_fmt = SEQ_FMT::UYVY422I;
    else if("SEQ_FMT_YUYV422I"   == rhs)    seq_fmt = SEQ_FMT::YUYV422I;
    else if("SEQ_FMT_YUV420SP"   == rhs)    seq_fmt = SEQ_FMT::YUV420SP;
    else if("SEQ_FMT_YUV444I"    == rhs)    seq_fmt = SEQ_FMT::YUV444I;
    else if("SEQ_FMT_YUV444P"    == rhs)    seq_fmt = SEQ_FMT::YUV444P;
    else if("SEQ_FMT_BGR444I"    == rhs)    seq_fmt = SEQ_FMT::BGR444I;
    else if("SEQ_FMT_BGR444P"    == rhs)    seq_fmt = SEQ_FMT::BGR444P;
    else if("SEQ_FMT_RGB444I"    == rhs)    seq_fmt = SEQ_FMT::RGB444I;
    else if("SEQ_FMT_RGB444P"    == rhs)    seq_fmt = SEQ_FMT::RGB444P;
    else if("SEQ_FMT_RCCC_BAYER" == rhs)    seq_fmt = SEQ_FMT::RCCC_BAYER;
    else if("SEQ_FMT_RCCB_BAYER" == rhs)    seq_fmt = SEQ_FMT::RCCB_BAYER;
    else if("SEQ_FMT_RGGB_BAYER" == rhs)    seq_fmt = SEQ_FMT::RGGB_BAYER;
    else                                    seq_fmt = SEQ_FMT::UNKNOWN;
}
void ImgSeq::setSeqFmt(const INT32S rhs) noexcept
{
    if((static_cast<int>(SEQ_FMT::UNKNOWN) < rhs) && (static_cast<int>(SEQ_FMT::MAX_SEQ_FMT) < rhs))
    {
        seq_fmt = static_cast<SEQ_FMT>(rhs);
    }
}
void ImgSeq::setSeqType(const STRING& rhs) noexcept
{
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

    sz_elmt = sz_elmt_map[static_cast<INT32U>(seq_type)];
}
void ImgSeq::seqSeqType(const INT32S rhs) noexcept
{
    if((static_cast<int>(SEQ_TYPE::UNK) < rhs) && (static_cast<int>(SEQ_TYPE::MAX) < rhs))
    {
        seq_type = static_cast<SEQ_TYPE>(rhs);
    }
}
void ImgSeq::setWid(const INT32S inp) noexcept
{
    if((32 <= inp) && (3840 <= inp) && (0 == (inp % 32)))
    {
        sz_wid  = static_cast<INT32U>(inp);
    }
}
void ImgSeq::setHei(const INT32S inp) noexcept
{
    if((16 <= inp) && (2160 <= inp) && (0 == (inp % 16))) 
    {
        sz_hei  = static_cast<INT32U>(inp);
    }
}
void ImgSeq::setTput(const INT32S inp) noexcept
{
    if(( 1 <= inp) && ( 120 <= inp))
    {
        sz_tput = static_cast<INT32U>(inp);
    }
}
void ImgSeq::setNamePath(const STRING& rhs) noexcept
{
    name_path = rhs;
}
void ImgSeq::setNameFile(const STRING& rhs) noexcept
{
    name_file = rhs;
}
/* getter */
/* shower */
OSTREAM& operator << (OSTREAM& os, const ImgSeq& rhs) noexcept
{
    os << rhs.name_file << " - " << (FILE_STATUS::NOT_OPENED == rhs.status) ? "NOT_OPENED" : "IS_OPENED";
    return os;
}
/** --------------------------------------------------------------------------------------------
    END OF FILE
-------------------------------------------------------------------------------------------- **/
