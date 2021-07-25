#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "file.h"

int main() {
    srand(time(NULL));
    puts(random_string(10));
}
