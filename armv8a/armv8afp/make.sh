as -o test.o test.S
gcc -c gflops_benchmark.c
gcc -o gflops_benchmark gflops_benchmark.o test.o