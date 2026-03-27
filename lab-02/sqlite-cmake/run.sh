mkdir build
cd build

cmake .. --toolchain ../toolchains/arm_cortex_a9.cmake

cmake --build .