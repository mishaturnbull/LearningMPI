/*
 * helloworld.c
 * Misha Turnbull
 * 201912082318
 */

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
	// Create MPI environment
	MPI_Init(NULL, NULL);

	int world_size;  // world size
	int world_rank;  // process rank  (what number this one is?)

	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	// name of the processor  (hostname?)
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	int name_len;
	MPI_Get_processor_name(processor_name, &name_len);

	// Hello world!
	printf("Hello World!  I am processor %s, rank %s of %s processors\n",
		processor_name, world_rank, world_size);

	// Finalize the MPI environment
	// Is this kinda like freeing it?  The guide i'm using says to do it
	// but seems like something that would be done automatically
	MPI_Finalize();
}
