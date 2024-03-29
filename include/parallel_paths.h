//
// Created by Jacopo Clocchiatti on 03/09/23.
//

#ifndef PARALLEL_A_STAR_NEW_PARALLEL_PATHS_H
#define PARALLEL_A_STAR_NEW_PARALLEL_PATHS_H

#include "comm.h"

void print_paths(MsgChunkEnd* paths, int my_rank);
MsgChunkEnd* parallel_compute_paths(MsgChunkStart* msg_start, Node* nodes, int size, int rank);

#endif //PARALLEL_A_STAR_NEW_PARALLEL_PATHS_H
