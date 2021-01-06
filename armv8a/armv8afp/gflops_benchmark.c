// Hisi 3519A gFLOPS
#include <time.h>
#include <stdio.h>

#define LOOP (1e9)
#define OP_FLOATS (80)

// void test(int nn){
//     asm volatile(
        
//         "0:                             \n"

//         "subs       %0, #1              \n"
//         "bne        0b                  \n"
//         "vmla.f32 q0, q0, q0            \n"
//         "vmla.f32 q1, q1, q1            \n"
//         "vmla.f32 q2, q2, q2            \n"
//         "vmla.f32 q3, q3, q3            \n"
//         "vmla.f32 q4, q4, q4            \n"
//         "vmla.f32 q5, q5, q5            \n"
//         "vmla.f32 q6, q6, q6            \n"
//         "vmla.f32 q7, q7, q7            \n"
//         "vmla.f32 q8, q8, q8            \n"
//         "vmla.f32 q9, q9, q9            \n"
        
//         : "=r"(nn)
//         : "0"(nn)
//         : "cc", "memory", "q0", "q1", "q2", "q3", "q4", "q5", "q6", "q7", "q8", "q9"
//     );
// }

void TEST(int);

static double get_time(struct timespec *start,
                       struct timespec *end) {
    return end->tv_sec - start->tv_sec + (end->tv_nsec - start->tv_nsec) * 1e-9;
}



int main() {
    struct timespec start, end;
    double time_used = 0.0;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);

    TEST(LOOP);

    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    time_used = get_time(&start, &end);
    printf("perf: %.6lf \r\n", LOOP * OP_FLOATS * 1.0 * 1e-9 / time_used);
}
