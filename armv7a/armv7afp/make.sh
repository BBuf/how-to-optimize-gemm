arm-himix200-linux-as -o test.o test.S -mfloat-abi=softfp -mfpu=neon -march=armv7-a
arm-himix200-linux-gcc -c gflops_benchmark.c
arm-himix200-linux-gcc -o gflops_benchmark gflops_benchmark.o test.o