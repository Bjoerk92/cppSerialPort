/**
 * @file Serial_unix.cpp
 * @author Anders (anders.bjoerk.unf@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-18
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifdef __linux__
#include "Serial.hpp"



Serial::Serial(const Serial_cfg& config)
{
    if (this->_connected)
    {
        throw "Serial Error: Already connected";
    }

    

}

#endif