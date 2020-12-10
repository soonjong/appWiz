/** --------------------------------------------------------------------------------------------
    @file           DualBuffer.h
    @brief          dual buffer header for application wizard project
    @version        0.01
    @warning        
    @instruction    It is not allowed to change this file arbitrarily without permission.
                    If you have a good way to change to a better direction, please contact me.
    @author         Jin, Soonjong (soonjong.jin@gmail.com)
    @date           revision history
                    2020. 12/06: files is created by JIn
-------------------------------------------------------------------------------------------- **/
#ifndef DUAL_BUFFER_H
#define DUAL_BUFFER_H

#ifndef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** --------------------------------------------------------------------------------------------
    including header files
-------------------------------------------------------------------------------------------- **/
#include "./TypeDef.h"
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
template <typename TYPE>
class DualBuffer
{
private:
	INT32U		sz_wid;
	INT32U		sz_hei;

    INT32U      idx_curr_buf;
    INT32U      idx_next_buf;

    TYPE*       p_buf[2];

public:
    /* functions */
    void switchIdxBuf();
    /* constructor */
    explicit DualBuffer() noexcept;
    /* copy constructor */
    explicit DualBuffer(const DualBuffer& rhs) = delete;
    /* move constructor */
    explicit DualBuffer(DualBuffer&& rhs) = delete;
    /* copy assignment operator */
    DualBuffer& operator =(const DualBuffer& rhs) = delete;
    /* move assignment operator */
    DualBuffer& operator =(DualBuffer&& rhs) = delete;
    /* destructor */
    virtual ~DualBuffer();
    /* setter */
	void setWid(const INT32S inp) = delete;//noexcept { if((32 <= inp) && (3840 <= inp) && (0 == (inp % 32)))  sz_wid  = static_cast<INT32U>(inp); }
    void setHei(const INT32S inp) = delete;// noexcept { if((16 <= inp) && (2160 <= inp) && (0 == (inp % 16)))  sz_hei  = static_cast<INT32U>(inp); }
    void resetIdxBuf() noexcept;
    /* getter */
    INT32U      getWid()  const noexcept { return sz_wid; }
    INT32U      getHei()  const noexcept { return sz_hei; }
    TYPE*       getCurrBuf() const noexcept { return p_buf[idx_curr_buf]; }
    TYPE*       getNextBuf() const noexcept { return p_buf[idx_next_buf]; }
    /* shower */
    friend OSTREAM& operator << (OSTREAM& os, const DualBuffer& rhs) noexcept;
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

#endif /* DUAL_BUFFER_H */
