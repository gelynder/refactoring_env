#include "Controller.hpp"

namespace Application
{

Controller::Controller(ICommunicationPoint& communicationPoint)
    : communicationPoint_(communicationPoint)
{

}

void Controller::handle(std::unique_ptr<IEvent> ev)
{
    if (ev->getEventId() == 10)
    {
        communicationPoint_.send(100);
    }
    else if (ev->getEventId() == 20)
    {
        communicationPoint_.send(200);
    }
    else
    {
        communicationPoint_.send(0);
    }

}

}  // namespace Application
