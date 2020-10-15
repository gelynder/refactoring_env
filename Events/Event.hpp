#pragma once

#include "Event.hpp"

class Event : public IEvent
{
public:
    Event(std::uint32_t id) : id_(id) {};
    std::uint32_t getEventId() const override
    {
        return id_;
    }

private:
    std::uint32_t id_;
};
