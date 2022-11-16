#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>

#include "hanoi_iterative.h"

int OnAux;
int OnTarget;

int CheckValid(int DiskNum, int Rod){
    printf("Target Disk: %d\nTarget Rod: %d\n, Auxillary Rod: %d\n", DiskNum, OnTarget, OnAux);
    if (Rod == 2){
        if (OnTarget && OnTarget > DiskNum) return 0;
        return 1;
    }
    if (Rod == 3){
        if (OnAux && OnAux > DiskNum) return 0;
        return 1;
    }
}

void Move(int DiskNum, int RodNum){
    printf("move disk %d to rod %d\n", DiskNum, RodNum);
    if (RodNum == 2){
        OnTarget = DiskNum;
        return;
    }
    OnAux = DiskNum;
    return;
}

void SolveHanoi(int DiskNum, int Init, int Target, int Aux){
    int Tgt_Cpy = Target;
    int Aux_Cpy = Aux;
    int MovesRequired = pow(2, DiskNum) - 1;
    printf("moves required: %d\n", MovesRequired);
    for (int i = 1; i <= MovesRequired; i++){
        if (i % 3 == 1){
            if (CheckValid(DiskNum, Target) == 0){
                Move(DiskNum, Target);
                DiskNum -= 1;
                continue;
            }
            Move(DiskNum, Aux);
            DiskNum -= 1;
            continue;
        }
        if (i % 3 == 2){
            if (CheckValid(DiskNum, Aux) == 0){
                Move(DiskNum, Aux);
                DiskNum -= 1;
                continue;
            }
            Move(DiskNum, Target);
            DiskNum -= 1;
            continue;
        }
        if (i % 3 == 0){
            if (CheckValid(DiskNum, Target) == 0){
                Move(DiskNum, Target);
                DiskNum -= 1;
                continue;
            }
            Move(DiskNum, Aux);
            DiskNum -= 1;
            continue;
        }
        
    }
    return;
}

/*
Iterative Version
*/