#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"
#include "test.h"
#include "util.h"
#include <unistd.h>
#include <sys/time.h>

int main() {
    srand(time(NULL));
    struct Test* test = test_init(25);
    start_test(test);
    return EXIT_SUCCESS;
}
