#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <sys/time.h>
#include <stdlib.h>

#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <sched.h>
#include <utmpx.h>
#include <stdlib.h>
#include <strings.h>

#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <omp.h>

#ifdef _OPENMP
void bind_threads_to_cores()
{
#pragma omp parallel default(none)
    {
#pragma omp critical
	{
	    cpu_set_t mask[1024];
	    int num_threads = omp_get_num_threads();
	    int thread_id = omp_get_thread_num();
	    size_t cpu_alloc_size = CPU_ALLOC_SIZE(num_threads);
	    CPU_ZERO_S(cpu_alloc_size, mask);
	    CPU_SET_S(thread_id, num_threads, mask);
	    sched_setaffinity(0, cpu_alloc_size, mask);
	}
    }
}
#endif

