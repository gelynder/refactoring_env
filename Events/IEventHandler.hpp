#pragma once

#include <memory>

class IEvent;

class IEventHandler
{
public:
    virtual ~IEventHandler() = default;
    virtual void handle(std::unique_ptr<IEvent>) = 0;
};
