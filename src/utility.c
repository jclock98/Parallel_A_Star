#include <stdarg.h>
#include <printf.h>

#include <unistd.h>
#include <mpi.h>
#include <stdbool.h>

extern bool DEBUG;

int printf_debug(const char *format, ...) {
    if (DEBUG < 1) return 1;

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    // Check if string is only "\n", in case print without prefix
    if (format[0] == '\n' && format[1] == '\0') {
        printf("\n");
        return 1;
    } else {
        printf("[DEBUG][PROCESS %d] ", world_rank);
    }

    va_list args;
    va_start(args, format);
    int result = vprintf(format, args);
    va_end(args);

    return result;
}

void debug(int rank_to_debug) {
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    if (world_rank != rank_to_debug) return;
    volatile int i = 0;
    while (0 == i)
        sleep(5);
}
