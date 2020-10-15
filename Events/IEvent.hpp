#pragma once

#include <cstdint>

class IEvent
{
public:
    virtual ~IEvent() = default;
    virtual std::uint32_t getEventId() const = 0;
};
