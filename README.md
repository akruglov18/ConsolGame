# Consol_Game


# How to install on VS2019
## Pre-build
      Instal Windows SDK Version 10.0.19041.0
      Install tools v141 for VS
## Build
      mkdir build
      cd build
      cmake -G "Visual Studio 16 2019" -Tv141 -DCMAKE_SYSTEM_VERSION=10.0.19041.0 -DBUILD_SHARED_LIBS=TRUE ..
      cmake --build .
