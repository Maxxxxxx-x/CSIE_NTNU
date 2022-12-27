#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "division.h"
uint8_t xsize = 0, ysize = 0;
uint8_t *X, *Y;
uint8_t *Q, *R;
uint8_t qsize = 0, rsize = 0;
int main() {
    printf("how many digits of x?");
    scanf("%hhu", &xsize);
    X = calloc(xsize, sizeof(uint8_t));
    Q = calloc(xsize, sizeof(uint8_t));
    R = calloc(xsize, sizeof(uint8_t));
    printf("input the X\n");
    getchar();
    for (int i = 0; i < xsize; ++i) {
        char input;
        scanf("%c", &input);
        X[i] = input - '0';
    }
    // for (int i = 0; i < xsize; ++i) printf("%hhu ", X[i]);

    printf("how many digits of y?");
    scanf("%hhu", &ysize);
    Y = calloc(ysize, sizeof(uint8_t));
    printf("input the Y\n");
    getchar();
    for (int i = 0; i < ysize; ++i) {
        char input;
        scanf("%c", &input);
        Y[i] = input - '0';
    }
    for (int i = 0; i < xsize; ++i) printf("%hhu", X[i]);
    printf("/");
    for (int i = 0; i < ysize; ++i) printf("%hhu", Y[i]);
    printf("=\n");
    division(&Q, &qsize, &R, &rsize, X, xsize, Y, ysize);
    for (int i = 0; i < qsize; ++i) printf("%hhu", Q[i]);
    printf("...");
    for (int i = 0; i < rsize; ++i) printf("%hhu", R[i]);
    printf("\n");
    free(X);
    free(Y);
    free(Q);
    free(R);
    return 0;
}
