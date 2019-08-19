add_subdirectory(base)
add_subdirectory(appimageservices-interfaces)

set(CMAKE_AUTORCC ON)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    PRIVATE appsdir-base
    PRIVATE AppImageServicesInterfaces
)

install(
    TARGETS ${CMAKE_PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)