#include <stdio.h>

typedef enum {
    Start,
    S1,
    S2,
    S3,
    S4,
    S5,
    S6,
    Final
} FSMState;

typedef struct {
    FSMState state;
    void (*handler)();
} FSM;

void Start_Handler(){puts("Start");}
void S1_Handler(){puts("S1");}
void S2_Handler(){puts("S2");}
void S3_Handler(){puts("S3");}
void S4_Handler(){puts("S4");}
void S5_Handler(){puts("S5");}
void S6_Handler(){puts("S6");}
void Final_Handler(){puts("Final");}


int main(){
    FSM fsm;
    int input;
    fsm.state = Start;
    fsm.handler = Start_Handler;
    do{
        fsm.handler();
        printf("Please enter an integer: ");
        scanf("%d", &input);
        switch (fsm.state) {
            case Start:
                if (input == 10 || input == 35){
                    fsm.state = S1;
                    fsm.handler = S1_Handler;
                    break;
                }
                if (input == 11){
                    fsm.state = S3;
                    fsm.handler = S3_Handler;
                    break;
                }
                if (input == 20 || input == 78){
                    fsm.state = S5;
                    fsm.handler = S5_Handler;
                    break;
                }
            
            case S1:
                if (input == 19){
                    fsm.state = S2;
                    fsm.handler = S2_Handler;
                    break;
                }
                if (input == 12 || input == 36){
                    fsm.state = S6;
                    fsm.handler = S6_Handler;
                    break;
                }
                fsm.state = S1;
                fsm.handler = S1_Handler;
                break;
            
            case S2:
                if (input == 43){
                    fsm.state = S2;
                    fsm.handler = S2_Handler;
                    break;
                }
                if (input == 99){
                    fsm.state = Final;
                    fsm.handler = Final_Handler;
                    break;
                }
                fsm.state = Start;
                fsm.handler = Start_Handler;
                break;
            
            case S3:
                fsm.state = S4;
                fsm.handler = S4_Handler;
                break;
            
            case S4:
                fsm.state = S6;
                fsm.handler = S6_Handler;
                break;

            case S5:
                if (input == 1){
                    fsm.state = S4;
                    fsm.handler = S4_Handler;
                    break;
                }
                if (input == 2){
                    fsm.state = S6;
                    fsm.handler = S6_Handler;
                    break;
                }
                fsm.state = Start;
                fsm.handler = Start_Handler;
                break;
            
            case S6:
                if (input == 108){
                    fsm.state = Final;
                    fsm.handler = Final_Handler;
                    break;
                }
                fsm.state = S5;
                fsm.handler = S5_Handler;
                break;
            
            case Final:
                fsm.state = Final;
                fsm.handler = Final_Handler;
                break;
        }
    } while (1);
    return 0;
}
