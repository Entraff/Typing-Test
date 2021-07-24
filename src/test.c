#include <string.h>
#include "test.h"

struct Test* test_init() {
    struct Test* test = malloc(sizeof(struct Test));

    test->sentence = "";
    test->user_response = "";
    test->sentence_length = strlen(test->sentence);
    test->errors = 0;

    return test;
}
