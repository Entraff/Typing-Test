#include <stdio.h>
#include <string.h>
#include <time.h>
#include "file.h"
#include "test.h"

struct Test* test_init(const size_t word_count) {
    struct Test* test = malloc(sizeof(struct Test));

    test->sentence = random_string(word_count);
    test->sentence_length = strlen(test->sentence);
    test->user_response = malloc(sizeof(char) * (test->sentence_length + 1));
    test->correct_chars = test->sentence_length;
    test->errors = 0;
    test->elapsed_time = 0.0;

    return test;
}

double calculate_wpm(struct Test* test) {
    double average_words = (double)test->correct_chars / AVERAGE_WORD_LEN;
    // Words per second
    double WPS = average_words / test->elapsed_time;
    return WPS * 60;
}

double calculate_accuracy(struct Test* test) {
    double error_percentage = (double)test->errors / (double)test->sentence_length * 100;
    return 100.0 - error_percentage;
}

void calculate_errors(struct Test* test) {
    for (size_t i = 0; i < test->sentence_length; ++i) {
        if (test->sentence[i] != test->user_response[i]) {
            ++test->errors;
            --test->correct_chars;
        }
    }
}

void start_test(struct Test* test) {
    clock_t timer = clock();

    puts(test->sentence); 
    fgets(test->user_response, test->sentence_length, stdin);

    timer = clock() - timer;  
    double elapsed_time = (double)timer - CLOCKS_PER_SEC;

    test->elapsed_time = elapsed_time;
    calculate_errors(test);
}
