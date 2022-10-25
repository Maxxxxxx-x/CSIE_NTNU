#include <stdio.h>
#include <stdlib.h>

void throw(char Error[], int Code){
    printf("%s", Error);
    exit(Code);
}

void Compare(int Num, int Req){
    if (Num == Req) return;
    throw("Invalid input", 1);
}


int main(){
    int Date[1];
    int Price;
    int Term;
    int Rate;
    int Tax;
    int Insurance;
    int Add_Pay;
    printf("Loan Date: ");
    int state = scanf("%d.%d", &Date[0], &Date[1]);
    Compare(state, 2);
    printf("Loan Price: ");
    int state = scanf("%d", &Price);
    Compare(state, 2);
    printf("Loan Term (yrs): ");
    int state = scanf("%d", )

}