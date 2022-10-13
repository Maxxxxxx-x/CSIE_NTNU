#include <stdio.h>
#include <stdint.h>

int main(){
    uint16_t n;
    printf("Please enter  n (16-bits unsigned): ");
    int state = scanf("%d", &n);
    if (state != 1){
        printf("Invalid input.");
        return 1;
    }

    for (int i = 1; i <= n; i++){
        printf("n = %d\n", i);
        //Leibniz's Formula
        int tmp1_L = 1;
        int sum_L = 0;
        for (int j = 0; j < n; j++){
            if (j % 2 == 0){
                sum_L += 4 / tmp1_L;
            }else{
                sum_L -= 4/tmp1_L;
            }
            tmp1_L += 2;
            printf("Gregory – Leibniz series: %d (%lf)\n", sum_L, tmp1_L);
            break;
        }
        //Nilakantha's Formula
        int tmp1_N = 1;
        int sum_N = 0;
        for (int j = 0; j < n; j++){

        }
    }

    return 0;
}