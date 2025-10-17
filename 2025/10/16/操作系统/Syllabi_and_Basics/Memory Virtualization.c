#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"

int main () {
    int *p = malloc(sizeof(int));
    assert(p != NULL);
    printf("(%d) address pointed to by p: %p\n", getpid(), p);
    *p = 0;
    while (1) {
        Spin(1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);
    }
    return 0;
    
}

// execute ./"Memory Virtualization" & ./"Memory Virtualization"
// outcome:
// [1] 26490
// (26491) address pointed to by p: 0x134e062a0
// (26490) address pointed to by p: 0x124e062a0
// (26490) p: 1
// (26491) p: 1
// (26491) p: 2
// (26490) p: 2
// (26490) p: 3
// (26491) p: 3
// (26491) p: 4
// (26490) p: 4
// (26491) p: 5
// (26490) p: 5
// (26491) p: 6
// (26490) p: 6
// (26491) p: 7
// (26490) p: 7
// (26491) p: 8
// (26490) p: 8
// (26491) p: 9
// (26490) p: 9