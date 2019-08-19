set(CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(appsdir-base STATIC utils.cpp AbstractFileSystemWatcher.h FileSystemWatcher.cpp AppsDir.cpp)
target_link_libraries(appsdir-base PUBLIC Qt5::Core)
target_include_directories(appsdir-base PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})