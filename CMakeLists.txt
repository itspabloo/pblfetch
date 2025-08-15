cmake_minimum_required(VERSION 3.10)
project(pblfetch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(pblfetch
    main.cpp
    art_drawer.hpp
    sysinfo.hpp
    consts.hpp
)

install(TARGETS pblfetch
    RUNTIME DESTINATION bin
)

install(FILES art.txt
    DESTINATION ${CMAKE_INSTALL_PREFIX}/.config/pblfetch
)
