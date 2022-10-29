#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void throw(char error[], int code){
    printf("%s\n", error);
    exit(code);
}

void CompareState(int Num, int Req){
    if (Num == Req) return;
    throw("Invalid input!", 1);
}

int IsNap(double NapProb){
    if (NapProb == 0) return 0;
    int tmp = rand() % 10;
    double tmp1 = ((double) tmp ) / 10;
    if (tmp > NapProb) return 1;
    return 0;
}


void StartRace(double Race_Dist, double TorSpd, double HareSpd, double NapProb){
    int RaceEnded = 0;
    int Turns = 0;
    double T_Dist, H_Dist;
    while (1){
        if (RaceEnded == 1){
            if (T_Dist > H_Dist) printf("Turn %d) Tortoise: %lf (Winner), Hare: %lf\n", Turns, T_Dist, H_Dist);
            if (H_Dist > T_Dist) printf("Turn %d) Tortoise: %lf , Hare: %lf (Winner)\n", Turns, T_Dist, H_Dist);
            if (T_Dist == H_Dist) printf("Turn %d) Tortoise: %lf , Hare: %lf (Draw)\n", Turns, T_Dist, H_Dist);
            break;
        }
        printf("Turn %d) ", Turns);
        T_Dist += TorSpd;
        int Nap = IsNap(NapProb);
        if (Nap){
            H_Dist += 0;
            printf("Tortoise: %lf, Hare: %lf (NAP)\n", T_Dist, H_Dist);
        }else{
            H_Dist += HareSpd;
            printf("Tortoise: %lf, Hare: %lf\n", T_Dist, H_Dist);
        }
        if (T_Dist > Race_Dist || H_Dist > Race_Dist) RaceEnded = 1;
    }
    return;
}


int main(){
    srand(time(NULL));
    double Race_Dist = 12.3;
    double TorSpd = 0.3;
    double HareSpd, NapProb;
    int state;
    printf("The Hare Speed (m/turn): ");
    state = scanf("%lf", &HareSpd);
    CompareState(state, 1);
    printf("The Nap Probability (0-1): ");
    state = scanf("%lf", &NapProb);
    CompareState(state, 1);
    if (NapProf > 1) throw("Probability of nap is greater than 1!", 1);
    StartRace(Race_Dist, TorSpd, HareSpd, NapProb);
    return 0;
}