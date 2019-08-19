# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(AppImageLauncherTestBase STATIC FakeLauncher.cpp FakeInspector.cpp FakeInstaller.cpp FakeFileSystemWatcher.cpp)
target_link_libraries(AppImageLauncherTestBase PUBLIC appsdir-base Qt5::Core Qt5::Test Qt5::Widgets)
target_include_directories(AppImageLauncherTestBase PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})