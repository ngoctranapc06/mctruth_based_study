add_executable(SignalDef
        main.cpp
        )	

target_link_libraries(SignalDef ${WAGASCI_RECON_LIBRARIES})

target_include_directories(SignalDef PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS SignalDef DESTINATION "${CMAKE_INSTALL_BINDIR}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(cc0pi)
