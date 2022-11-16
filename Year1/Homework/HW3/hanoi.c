#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>


#include "hanoi.h"

void Solve(int DiskNum, int Initial, int Target, int auxillary){
    if (DiskNum == 1){
        printf("move disk 1 to rod %d\n", Target);
        return;
    }
    printf("1\n");
    SolveHanoi(DiskNum - 1, Initial, auxillary, Target);
    printf("2\n");
    printf("move disk %d to rod %d\n", DiskNum, Target);
    printf("3\n");
    SolveHanoi(DiskNum - 1, auxillary, Target, Initial);
    printf("4\n");
}

void SolveHanoi(int DiskNum, int Initial, int Target, int auxillary){
    Solve(DiskNum, Initial, Target, auxillary);
}
/*
Recursive Version of Tower of Hanoi
*/