# Game

## Build
      git submodule update --init --recursive
      mkdir build
      cd build
      cmake -DBUILD_SHARED_LIBS=TRUE -DBUILD_GMOCK=OFF ..
      cmake --build .
