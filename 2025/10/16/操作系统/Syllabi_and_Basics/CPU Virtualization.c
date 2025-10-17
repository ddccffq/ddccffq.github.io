#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include "common.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }
    char *str = argv[1];
    while (1) {
        Spin(1);
        printf("%s\n", str);
    }
    return 0;
}

// execute ./"CPU Virtualization" "A" & ./"CPU Virtualization" "B" & ./"CPU Virtualization" "C"
// outcome:
// [1] 22870
// [2] 22871
// C
// A
// B
// A
// C
// B
// B
// C
// A
// C
// A
// B
// C
// B
// A
// A
// C
// B
// A
// C
// B
// ^C