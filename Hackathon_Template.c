#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

#define TOTAL_POINTS 1000000000 // 1 Billion points for better accuracy
#define SEED_BASE 12345 // Base seed value

long get_memory_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss; // Memory usage in kilobytes
}

int main(int argc, char **argv) {
    int rank, size, i, count = 0, total_count;
    double x, y, pi, start_time, total_time;
    long memory_usage;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    // Set seed based on process rank and base seed value
    srand(SEED_BASE + rank);

    // {Write code here} Fill in Code to Ensure all processes start timing at the same moment and make sure you are waiting for all

    //responsible for determining whether a randomly generated point (x, y) falls within the unit circle. If it does, the count variable is incremented.
    for (i = 0; i < TOTAL_POINTS / size; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        if (x * x + y * y <= 1) count++;
    }

    // {Write code here} Get the output from other processes

    total_time = (MPI_Wtime() - start_time) * 1e9;  // Convert seconds to nanoseconds

    if (rank == 0) {
        pi = 4.0 * total_count / TOTAL_POINTS;
        double error = fabs(pi - M_PI);
        double error_percentage = (error / M_PI) * 100;
        memory_usage = get_memory_usage(); // Get memory usage in kilobytes
        printf("Estimated π = %.15f (with 15 decimal places)\n", pi);
        printf("Error percentage = %.15f%%\n", error_percentage);
        printf("Total time = %.0f nanoseconds\n", total_time);
        printf("Memory usage = %ld kilobytes\n", memory_usage);
    }

    MPI_Finalize();
    return 0;
}