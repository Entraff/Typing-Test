#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include "test.h"
#include "util.h"

void ncurses_init() {
    initscr();
    cbreak();
    noecho();
    clear();
}

void print_count_choices(const int* choices, const size_t length) {
    puts("Choose how many words you want to use via the index on the left of the prompts");
    for (size_t i = 0; i < length; ++i)
        printf("[%lu] %d words\n", i + 1, choices[i]);
}

void scan_choice_index(size_t* dest, const size_t MAX_INDEX) {
    do {
        scanf("%lu", dest); 
    } while ((*dest <= 0) && (*dest > MAX_INDEX));

    // Consumes newline
    getchar();
    // decrements the index as 1 is added to the available indicies to the user
    // to improve readability but would be an invalid index if the maximum was chosen
    --*dest;
}

int main() {
    srand(time(NULL));

    const int WORD_COUNT_CHOICES[] = { 15, 30, 60, 100 };
    const size_t CHOICES_LENGTH = ARRAY_SIZE(WORD_COUNT_CHOICES);
    size_t choice_index, word_count;

    print_count_choices(WORD_COUNT_CHOICES, CHOICES_LENGTH);
    // Validates the choice index from the user
    scan_choice_index(&choice_index, CHOICES_LENGTH);
    word_count = WORD_COUNT_CHOICES[choice_index];

    struct Test* test = test_init(word_count);
    start_test(test);

    return EXIT_SUCCESS;
}
