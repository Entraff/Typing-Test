#ifndef TEST_H
#define TEST_H

#include <stdlib.h>

struct Test {
    char* sentence;
    char* user_response;
    size_t sentence_length;
    int errors;
};

struct Test* test_init(const size_t word_count);

#endif // TEST_H
