# Install script for directory: /home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/bin/SignalDef" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/bin/SignalDef")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/bin/SignalDef"
         RPATH "/gpfs/home/t2k/tvngoc/Programs/ROOT/6-22-02/lib:/home/t2k/tvngoc/Programs/ROOT/6-22-02/lib:/home/t2k/tvngoc/Programs/BOOST/boost_1_73_0/lib:/home/t2k/tvngoc/Programs/WAGASCI/lib/wagasci/b2")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/bin/SignalDef")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/bin" TYPE EXECUTABLE FILES "/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/build/src/SignalDef")
  if(EXISTS "$ENV{DESTDIR}/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/bin/SignalDef" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/bin/SignalDef")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/bin/SignalDef"
         OLD_RPATH "/gpfs/home/t2k/tvngoc/Programs/ROOT/6-22-02/lib:/home/t2k/tvngoc/Programs/ROOT/6-22-02/lib:/home/t2k/tvngoc/Programs/BOOST/boost_1_73_0/lib:/home/t2k/tvngoc/Programs/WAGASCI/lib/wagasci/b2:"
         NEW_RPATH "/gpfs/home/t2k/tvngoc/Programs/ROOT/6-22-02/lib:/home/t2k/tvngoc/Programs/ROOT/6-22-02/lib:/home/t2k/tvngoc/Programs/BOOST/boost_1_73_0/lib:/home/t2k/tvngoc/Programs/WAGASCI/lib/wagasci/b2")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/bin/SignalDef")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/t2k/tvngoc/gpfs/tvngoc/wagascimc/mctruth_based_study/build/src/cc0pi/cmake_install.cmake")

endif()

