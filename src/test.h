#ifndef TEST_H
#define TEST_H

#include <stdlib.h>

struct Test {
    char* sentence;
    char* user_response;
    size_t sentence_length;
    int errors;
};

#endif // TEST_H
