#include <gtest/gtest.h>

#include "Mocks/CommunicationPointMock.hpp"

#include "Controller.hpp"
#include "Event.hpp"

using namespace ::testing;

namespace Application
{

struct ControllerTest : Test
{
    ControllerTest()
    {
    }

    CommunicationPointMock communicationPointMock;
};

TEST_F(ControllerTest, DummyTest)
{
    EXPECT_EQ(0,0);
}

TEST_F(ControllerTest, ShouldSend100IfEventIdIs10)
{
    std::uint32_t EVENT_ID = 10;
    std::uint32_t EXPECTED_VALUE = 100;
    EXPECT_CALL(communicationPointMock, send(EXPECTED_VALUE));

    Controller sut(communicationPointMock);
    sut.handle(std::make_unique<Event>(EVENT_ID));
}

TEST_F(ControllerTest, ShouldSend200IfEventIdIs20)
{
    std::uint32_t EVENT_ID = 20;
    std::uint32_t EXPECTED_VALUE = 200;
    EXPECT_CALL(communicationPointMock, send(EXPECTED_VALUE));

    Controller sut(communicationPointMock);
    sut.handle(std::make_unique<Event>(EVENT_ID));
}


TEST_F(ControllerTest, ShouldSend0IfEventIdIs5)
{
    std::uint32_t EVENT_ID = 5;
    std::uint32_t EXPECTED_VALUE = 0;
    EXPECT_CALL(communicationPointMock, send(EXPECTED_VALUE));

    Controller sut(communicationPointMock);
    sut.handle(std::make_unique<Event>(EVENT_ID));
}


}  // namespace Application
