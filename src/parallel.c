#include "mpi.h"
#include "../include/print.h"
#include "../include/parallel_distribution.h"

extern int GRID_HEIGHT;
extern int GRID_WIDTH;
extern int DEBUG;

void parallel_init(int* n_chunks, int* world_rank) {
    MPI_Init(NULL, NULL);

    MPI_Comm_size(MPI_COMM_WORLD, n_chunks);
    MPI_Comm_rank(MPI_COMM_WORLD, world_rank);
}

void parallel_finalize() {
    MPI_Finalize();
}

