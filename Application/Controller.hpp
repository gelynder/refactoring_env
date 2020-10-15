#pragma once

#include "ICommunicationPoint.hpp"

#include "IEventHandler.hpp"
#include "IEvent.hpp"

#include <memory>

class ICommunicationPoint;

namespace Application
{

class Controller : public IEventHandler
{
public:
    Controller(ICommunicationPoint& communicationPoint);

    void handle(std::unique_ptr<IEvent> ev) override;

private:
    ICommunicationPoint& communicationPoint_;
};

}  // namespace Application
