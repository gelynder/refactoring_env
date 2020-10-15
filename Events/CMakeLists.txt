add_custom_target(DynamicEvents_HEADERS SOURCES
    IEvent.hpp
    IEventHandler.hpp
    ICommunicationPoint.hpp
    Event.hpp
)

add_library(Events INTERFACE)
add_dependencies(Events ${LIBRARY_NAME}_HEADERS)
target_include_directories(Events INTERFACE .)
