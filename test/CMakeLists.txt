if (ENABLE_TESTING)
    find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED Test)

    add_subdirectory(test-base)

    # Tell CMake to run moc when necessary:
    set(CMAKE_AUTOMOC ON)

    # As moc files are generated in the binary dir, tell CMake
    # to always look for includes there:
    set(CMAKE_INCLUDE_CURRENT_DIR ON)

    add_executable(AppsDirTests AppsDirTests.cpp)
    target_link_libraries(AppsDirTests appsdir-base AppImageLauncherTestBase Qt5::Test)

    # Allways must be at the end
    enable_testing()
endif ()