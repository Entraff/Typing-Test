#include <string.h>
#include "file.h"
#include "test.h"

struct Test* test_init(const size_t word_count) {
    struct Test* test = malloc(sizeof(struct Test));

    test->sentence = random_string(word_count);
    test->user_response = "";
    test->sentence_length = strlen(test->sentence);
    test->errors = 0;

    return test;
}
