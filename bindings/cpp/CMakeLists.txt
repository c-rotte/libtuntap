# libtuntap C++ binding CMakeLists.txt
# ====================================

# tuntap++ declaration
# --------------------
add_library(tuntap++ tuntap++.cc tuntap++.hh)

target_include_directories(tuntap++ PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tuntap++ PRIVATE ../../tuntap.c)

if(UNIX)
    target_include_directories(tuntap++ PUBLIC
            /usr/include/
            /usr/local/include/
            )
    target_compile_definitions(tuntap++ PUBLIC -DUnix)
    target_sources(tuntap++ PRIVATE ../../tuntap-unix.c)
endif(UNIX)

if(Windows)
    target_compile_definitions(tuntap++ PUBLIC -DWindows)
    target_sources(tuntap++ PRIVATE ../../tuntap-windows.c)
endif(Windows)

if(UNIX)
    if(Linux)
        target_compile_definitions(tuntap++ PUBLIC -D_GNU_SOURCE)
        target_sources(tuntap++ PRIVATE ../../tuntap-unix-linux.c)
    elseif (OpenBSD)
        target_sources(tuntap++ PRIVATE ../../tuntap-unix-openbsd.c)
        target_sources(tuntap++ PRIVATE ../../tuntap-unix-bsd.c)
    elseif (NetBSD)
        target_sources(tuntap++ PRIVATE ../../tuntap-unix-netbsd.c)
        target_sources(tuntap++ PRIVATE ../../tuntap-unix-bsd.c)
    elseif (FreeBSD)
        target_sources(tuntap++ PRIVATE ../../tuntap-unix-freebsd.c)
        target_sources(tuntap++ PRIVATE ../../tuntap-unix-bsd.c)
    elseif (Darwin)
        target_sources(tuntap++ PRIVATE ../../tuntap-unix-darwin.c)
        target_sources(tuntap++ PRIVATE ../../tuntap-unix-bsd.c)
    elseif (DragonFly)
        target_sources(tuntap++ PRIVATE ../../tuntap-unix-freebsd.c)
        target_sources(tuntap++ PRIVATE ../../tuntap-unix-bsd.c)
    else()
        message(FATAL_ERROR "Your operating system is not supported yet")
    endif()
endif(UNIX)

if(Windows)
    target_link_libraries(tuntap++ Ws2_32.lib)
endif(Windows)

set_target_properties(tuntap++ PROPERTIES
                      POSITION_INDEPENDENT_CODE TRUE
                      VERSION 2.1
                      CXX_STANDARD 11)

# install rules for shared and static
# -----------------------------------
install(TARGETS tuntap++
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include)

install(FILES tuntap++.hh
        DESTINATION include)
