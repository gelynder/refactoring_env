#pragma once

#include <gmock/gmock.h>

#include "ICommunicationPoint.hpp"

namespace Application
{

class CommunicationPointMock : public ICommunicationPoint
{
public:
    MOCK_METHOD1(send, void(std::uint32_t));
};

} // namespace Application
