#ifndef UTIL_H
#define UTIL_H
#include <sys/time.h>
// How much of one microsecond is part of one second
#define MICRO_LENGTH 0.00000001
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int rand_range(const int min, const int max);
double calculate_elapsed(struct timeval* start, struct timeval* end);

#endif // UTIL_H
