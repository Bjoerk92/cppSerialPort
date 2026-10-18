/**
 * @file Serial.hpp
 * @author Anders (anders.bjoerk.unf@gmail.com)
 * @brief Header file for the serial library
 * @version 0.1
 * @date 2026-10-18
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <chrono>
#include <thread>
#include <time.h>
#include <fstream>


#ifdef _WIN32 // windows platform
#include <Windows.h>
#else // UNIX platform (Linux, Ubuntu, IOS)
#include <termios.h>
#endif


class Serial {

    private:
        HANDLE io_handler_;
        bool _connected = false;
        
    public:

        enum class Bytesize : BYTE {
            BYTESIZE_5 = 5,
            BYTESIZE_6 = 6,
            BYTESIZE_7 = 7,
            BYTESIZE_8 = 8,
            BYTESIZE_9 = 9,
        };

        enum class StopBits : BYTE {
            ONE_STOP_BIT,
            TWO_STOP_BIT,
        };

        enum class Parity : BYTE {
            NO_PARITY,
            EVEN_PARITY,
            ODD_PARITY,
        };

        struct Serial_cfg {
            std::string port;
            DWORD       baudrate;
            BYTE        bytesize;
            StopBits    stopbits;
            Parity      parity;
        };


        explicit Serial(const Serial_cfg& config);
        ~Serial();
};