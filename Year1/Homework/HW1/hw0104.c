#include <stdio.h>
#include <stdlib.h>

void HandleError(int status, char* ErrMsg){
    if (status == 0){
        printf("%s\n", ErrMsg);
        exit(1);
    }
}

int ask(char thing2ask[]){
    int tmp;
    printf("    %s: ", thing2ask);
    int status = scanf("%d", &tmp);
    HandleError(status, "Invalid input (char required, got int)");
    return 0;
}

int main(){
    printf("Attacker\n");
    int lvl = ask("level");
    int atk = ask("atk");
    int type = ask("type");
    int status = ask("status");
    int move_power = ask("move power");
    int move_type = ask("move type");
    int move_cat = ask("move category");
    printf("Target\n");
    int tgt_def = ask("def");
    int tgt_type = ask("type");
    printf("Environment\n");
    int weather = ask("weather");
    int terrain = ask("terrain");


    return 0;
}