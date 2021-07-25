#ifndef TEST_H
#define TEST_H

#include <stdlib.h>
#define AVERAGE_WORD_LEN 4.7

struct Test {
    char* sentence;
    char* user_response;
    size_t sentence_length;
    double elapsed_time;
    int errors;
};

struct Test* test_init(const size_t word_count);
double calculate_wpm(struct Test* test);

#endif // TEST_H
