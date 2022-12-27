#include <stdlib.h>
#include <stdio.h>

#include "canvas.h"

#define BLACK "\033[0;30m"
#define YELLOW "\033[0;33m"
#define WHITE "\033[0;37m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RED "\033[0;31m"
/*
• *color option 0: white.
• *color option 1: red.
• *color option 2: yellow.
• *color option 3: green.
• *color option 4: blue.
*/

int CheckState(int State, int Required){; return (State == Required) ? 0 : 1;}

void ShowCanvas(){
    printf("  ");
    for (int i = 0; i < col_size; i++){
        printf("%d ", i % 10);
    }
    printf("\n");
    for (int i = 0; i < row_size; i++){
        printf("%d", i % 10);
        for (int j = 0; j < col_size; j++){
            printf(WHITE);
            if (canvas[i][j] == 1) printf(BLACK);
            printf("██");
            printf(WHITE);
        }
        printf("\n");
    }
}


void GenerateNewCanvas(int x, int y, int color){
    switch(color){
        case 0:
            printf(WHITE);
            break;
        case 1:
            printf(RED);
            break;       
        case 2:
            printf(YELLOW);
            break;
        case 3:
            printf(GREEN);
            break;
        case 4:
            printf(BLUE);
            break;
    }
    int PlacesToColor[row_size][col_size] = {0};
    for (int i = 0; i < row_size; i++){ //y uses row
        for (int j = 0; j < col_size; j++){ //x uses col
            if (canvas[i][j] == 1) PlacesToColor[i][j] == 1;
            
        }
    }
    printf(WHITE);
}

void Prompt(){
    int x = 0;
    int y = 0;
    int color;
    printf("Please enter the point (x,y): ");
    int state;
    state = scanf("(%d,%d)", &x, &y);
    if (CheckState(state, 2) || x < 0 || y < 0 || x >= row_size || y >= col_size || canvas[y][x] == 1){
        printf("Invalid point. Please try again!!\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        Prompt();
    }
    printf("Please enter the color[0-4]: ");
    state = scanf("%d", &color);
    if (CheckState(state, 1) || color < 0 || color > 4){
        printf("Invalid *color. Please try again!!\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        Prompt();
    }
    GenerateNewCanvas(x, y, color);
    Prompt();
}

int main(){
    ShowCanvas();
    Prompt();
    return 0;
}