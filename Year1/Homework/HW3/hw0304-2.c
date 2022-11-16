#include <stdlib.h>
#include <stdio.h>

#include "hanoi.h"

void throw(char Error[], int code){
    printf("%s\n", Error);
    exit(code);
}

void CompareState(int state, int required){
    if (state == required) return;
    throw("Invalid input", 1);
}

int GetDiskNum(){
    int tmp;
    printf("Please enter the disk number (2-20): ");
    int state = scanf("%d", &tmp);
    CompareState(state, 1);
    if (tmp < 2 || tmp > 20){
        printf("Invalid input! Disk number out of range!!\n");
        GetDiskNum();
    }
    return tmp;
}
int main(){
    int DiskNum = GetDiskNum();
    SolveHanoi(DiskNum, 1, 2, 3);
    return 0;
}

/*
Iterative Version
*/
