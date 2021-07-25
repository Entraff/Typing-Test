#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#define WORDS_PATH "../words.txt"
// The maximum length of any given string in words.txt
#define MAX_STR_LEN  20

size_t total_word_count();

// Creates a random string of (word_count) words
char* random_string(const size_t word_count);

#endif // FILE_H
