//Author: Joseph Kehoe
//Edited by:
//Name: Marcel Zama
//College ID: C00260146
//Date: 14/11/2023
//License: GPL-3.0 (See LICENSE text for the full LICENSE)


// OpenMP program to print Hello World
// using C language

// OpenMP header
#include <omp.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	// Beginning of parallel region
	#pragma omp parallel
	{

		printf("Hello World... from thread = %d\n",
			omp_get_thread_num());
	}
	// Ending of parallel region
}


// 
// helloThreads.cpp ends here
