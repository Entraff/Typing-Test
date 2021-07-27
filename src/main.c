#include <time.h>
#include <stdlib.h>
#include "test.h"

int main() {
    srand(time(NULL));
    struct Test* test = test_init(25);
    start_test(test);
    return EXIT_SUCCESS;
}
