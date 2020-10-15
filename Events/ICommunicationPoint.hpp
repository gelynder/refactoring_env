#pragma once

#include <cstdint>

class ICommunicationPoint
{
public:
    virtual ~ICommunicationPoint() = default;
    virtual void send(std::uint32_t) = 0;
};
