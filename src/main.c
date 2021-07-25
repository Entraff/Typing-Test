#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"
#include "test.h"
#include "util.h"

int main() {
    srand(time(NULL));
    puts(random_string(100));
    return EXIT_SUCCESS;
}
