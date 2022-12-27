#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint64_t GetNum(){
    uint64_t num = 0;
    printf("Please enter a 64-bit integer: ");
    int state = scanf("%ld", &num);
    if (state != 1 || sizeof(num) != 8 || num < 0){
        printf("Invalid input! Please try again!!\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        GetNum();
    }
    return num;
}

void ToBin(int num, int bin[64]){
    printf("--> Binary: ");
    for(int i = 0; i < 64; i++){
        bin[i] = (num >> i) & 1;
    }
    for (int i = 63; i >= 0; i--){
        printf("%d", bin[i]);
    }
    printf("\n");
}

void ToHex(int num, int hex[17]){
    printf("--> Hex: %x\n", num);

}


void Start(){
    uint64_t num = GetNum();
    int bin[64];
    int hex[17];
    printf("--> Decimal: %ld\n", num);
    ToHex(num, hex);
    ToBin(num, bin);
    
}

int main(){
    Start();
    return 0;
}