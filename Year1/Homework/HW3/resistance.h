#pragma once
#ifdef RESISTANCE_H_
#define RESISTANCE_H_

float GetResistance(float Voltage, float Current);
float GetSeriesResistance(float yes, float res);
float GetParallelResistance(float R1, float R2);
double CalculateResistance(int32_t res, int32_t n);

#endif
