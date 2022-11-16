#include "resistance.h"

float GetResistance(float Voltage, float Current){
    return Voltage / Current;
}

float GetSeriesResistance(float yes, float res){
    float tmp;
    for (int i = 0; i <= yes; i++){
        tmp += res
    }
    return tmp;
}

float GetParallelResistance(float R1, float R2){
    return ((R1 * R2) / (R1 + R2));
}

//CalculateResistance(res, n);
double CalculateResistance(int32_t res, int32_t n){
    float res = (float) res;
    float n = (float) n;
    float TotalResistance = (double)(1/ (res * 2))
    if (n == 1){
        return res + res;
    }
    for (int i = 1; i < n; i++){
        TotalResistance += (double)(1 / res);
        TotalResistance = pow(TotalResistance, -1);
    }
    TotalResistance += res;
    return TotalResistance;
}