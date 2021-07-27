#include <stdio.h>
#include <string.h>
#include <time.h>
#include "file.h"
#include "test.h"

struct Test* test_init(const size_t word_count) {
    struct Test* test = malloc(sizeof(struct Test));

    test->sentence = random_string(word_count);
    test->sentence_length = strlen(test->sentence);
    test->user_response = malloc(sizeof(char) * (test->sentence_length));
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

void print_test_info(struct Test* test) {
    printf("\nAccuracy: %f%%\n", calculate_accuracy(test));
    printf("WPM: %f\n", calculate_wpm(test));
    printf("Elapsed time: %f\n", test->elapsed_time);
    printf("Test length: %lu chars\n", test->sentence_length);
    printf("Correct characters: %d\n", test->correct_chars);
    printf("Errors: %d\n", test->errors);
}

void start_test(struct Test* test) {
    time_t elapsed_time = time(NULL);

    puts(test->sentence); 
    fgets(test->user_response, test->sentence_length + 1, stdin);

    elapsed_time = time(NULL) - elapsed_time;

    test->elapsed_time = elapsed_time;
    calculate_errors(test);

    print_test_info(test);
}
