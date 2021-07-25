#include <string.h>
#include "file.h"
#include "test.h"

struct Test* test_init(const size_t word_count) {
    struct Test* test = malloc(sizeof(struct Test));

    test->sentence = random_string(word_count);
    test->user_response = NULL;
    test->sentence_length = strlen(test->sentence);
    test->errors = 0;
    test->elapsed_time = 0;

    return test;
}

double calculate_wpm(struct Test* test) {
    int correct_chars = test->sentence_length - test->errors;
    double average_words = (double)correct_chars / AVERAGE_WORD_LEN;
    // Words per second
    double WPS = average_words / test->elapsed_time;
    return WPS * 60;
}
