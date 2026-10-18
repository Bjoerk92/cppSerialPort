/**
 * @file Serial_win.cpp
 * @author Anders (anders.bjoerk.unf@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-18
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifdef _WIN32

#include "Serial.hpp"
#include <stdexcept>


Serial::Serial(const Serial_cfg& config)
{
    DCB dcbSerialParams = {0};

    if (this->_connected)
    {
        throw std::runtime_error("Serial Error: Already in use");
    }
    
    this->io_handler_ = CreateFileA(config.port.c_str(),
                                    GENERIC_READ | GENERIC_WRITE,
                                    0,
                                    nullptr,
                                    OPEN_EXISTING,
                                    FILE_ATTRIBUTE_NORMAL,
                                    nullptr);
    
    if (this->io_handler_ == INVALID_HANDLE_VALUE)
    {
        throw std::runtime_error("Serial Error: Not able to open port");
    }

    dcbSerialParams.BaudRate = config.baudrate;
    dcbSerialParams.ByteSize = config.bytesize;

    if (config.stopbits == Serial::StopBits::ONE_STOP_BIT)
    {
        dcbSerialParams.StopBits = ONESTOPBIT;
    }
    else // two stop bits.
    {
        dcbSerialParams.StopBits = TWOSTOPBITS;
    }

    if (config.parity == Serial::Parity::NO_PARITY)
    {
        dcbSerialParams.Parity = NOPARITY;
    }
    else if (config.parity == Serial::Parity::EVEN_PARITY)
    {
        dcbSerialParams.Parity = EVENPARITY;
    }
    else // odd parity
    {
        dcbSerialParams.Parity = ODDPARITY;
    }

    dcbSerialParams.fDtrControl = DTR_CONTROL_ENABLE;

    if (SetCommState(io_handler_, &dcbSerialParams) == FALSE)
    {
        std::cout << "Warning: could not set serial port params\n";
    }
    else
    {
        // setup successful, so we purge RX and TX to make it ready for use.
        this->_connected = true;
        PurgeComm(io_handler_, PURGE_RXCLEAR | PURGE_TXCLEAR);
    }
}

Serial::~Serial()
{
    if (this->_connected)
    {
        this->_connected = false;
        CloseHandle(io_handler_);
    }
}

#endif