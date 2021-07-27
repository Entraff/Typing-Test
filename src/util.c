#include <stdlib.h>
#include "util.h"

int rand_range(const int min, const int max) {
    return rand() % (max - min) + min;
}

double calculate_elapsed(struct timeval* start, struct timeval* end) {
    long seconds = end->tv_sec - start->tv_sec;
    long microseconds = end->tv_usec - start->tv_usec;
    double time_elapsed = seconds + (microseconds * MICRO_LENGTH);
    return time_elapsed;
}
