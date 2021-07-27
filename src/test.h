#ifndef TEST_H
#define TEST_H

#include <stdlib.h>
#define AVERAGE_WORD_LEN 4.7

struct Test {
    char* sentence;
    size_t sentence_length;
    char* user_response;
    double elapsed_time;
    // Amount of characters that are not wrong
    int correct_chars;
    int errors;
};

struct Test* test_init(const size_t word_count);

double calculate_wpm(struct Test* test);
double calculate_accuracy(struct Test* test);
void calculate_errors(struct Test* test);

void print_test_info(struct Test* test);
void start_test(struct Test* test);

#endif // TEST_H
