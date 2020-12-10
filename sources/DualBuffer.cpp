/** ---------------------------------------------------------------------------------------------
    @file           DualBuffer.cpp
    @brief          dual buffer source for application wizard project
    @version        0.01
    @warning        
    @instruction    It is not allowed to change this file arbitrarily without permission.
                    If you have a good way to change to a better direction, please contact me.
    @author         Jin, Soonjong (soonjong.jin@gmail.com)
    @date           revision history
                    2020. 12/10: files is created by JIn
-------------------------------------------------------------------------------------------- **/

/** --------------------------------------------------------------------------------------------
    including header files
-------------------------------------------------------------------------------------------- **/
#include "DualBuffer.h"
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
template <typename TYPE>
void DualBuffer<TYPE>::switchIdxBuf()
{
    idx_curr_buf = (idx_curr_buf + 1U) & 0x01;
    idx_next_buf = (idx_next_buf + 1U) & 0x01;
}
/* constructor */
template <typename TYPE>
DualBuffer<TYPE>::DualBuffer() noexcept : sz_wid(0U), sz_hei(0U), idx_curr_buf(0U), idx_next_buf(1U)
{
    if((0U == sz_wid) || (0U == sz_hei))
    {
        p_buf[idx_curr_buf] = nullptr;
        p_buf[idx_curr_buf] = nullptr;
    }
    else{
        p_buf[idx_curr_buf] = new TYPE [(sz_wid * sz_hei)];
        p_buf[idx_next_buf] = new TYPE [(sz_wid * sz_hei)];
    }
}
/* copy constructor */
/* move constructor */
/* copy assignment operator */
/* move assignment operator */
/* destructor */
template <typename TYPE>
DualBuffer<TYPE>::~DualBuffer()
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
template <typename TYPE>
void DualBuffer<TYPE>::resetIdxBuf() noexcept
{
    idx_curr_buf = 0U;
    idx_next_buf = 0U;
}
/* getter */
/* shower */
template <typename TYPE>
OSTREAM& operator << (OSTREAM& os, const DualBuffer<TYPE>& rhs) noexcept
{
    os << rhs.getWid() << " x " << rhs.getHei();
    return os;
}

/** --------------------------------------------------------------------------------------------
    END OF FILE
-------------------------------------------------------------------------------------------- **/
