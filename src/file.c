#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "util.h"

size_t total_word_count() {
    FILE* word_file = fopen(WORDS_PATH, "r");
    char current_char = fgetc(word_file);
    size_t word_count = 0;

    while (current_char != EOF) {
        // Each new word is separated by a linefeed
        if (current_char == '\n')
            ++word_count;
        current_char = fgetc(word_file);
    }

    fclose(word_file);
    return word_count;
}

char* random_string(const size_t word_count) {
    // The maximum possible size for the resulting out_str
    const size_t OUT_STR_SIZE = sizeof(char) * MAX_STR_LEN * word_count;
    const size_t TOTAL_WORD_COUNT = total_word_count();
    const char* DELIMETER = " ";

    // Thanks John Carmack!
    char* words[] = {
        #include WORDS_PATH
    };

    char* out_str = calloc(OUT_STR_SIZE, 1);

    size_t random_index, i;    
    for (i = 0; i < word_count; ++i) {
        // Picks a random word from words.txt and appends
        // it to out_str
        random_index = rand_range(0, TOTAL_WORD_COUNT);
        strcat(out_str, words[random_index]);

        // Adds a space if not on the last iteration
        if (i < word_count - 1)
            strcat(out_str, DELIMETER);
    }
    return out_str;
}
