#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>

int throw(char error[], int ShouldExit){
    printf("%s\n", error);
    if (ShouldExit){
        exit(0);
    }
}

char *Options[6] = {"", "Add the course grade", "Remove the course grade", "GPA report", "Target GPA", "Exit"};

int T_Points, T_Credits;

void Add(){
    void GetPts(){
        char c;
        int tmp_pts;
        printf("Points (0 - 100): ");
        if (scanf("%d", &tmp_pts) == 0){
            throw("Invalid input!", 0);
            scanf("%c", c);
            GetPts();
        }
        if (tmp_pts < 0){
            printf("Cannot be negative!\n")
            GetPts();
        }
        T_Points += tmp_pts;
        return;
    }
    void GetCrds(){
        char c;
        int tmp_crds;
        printf("Credits (0 - 4): ");
        if (scanf("%d", &tmp_pts) == 0){
            throw("Invalid input!", 0);
            scanf("%c", c);
            GetCrds();
        }
        if (tmp_crds < 0){
            printf("Cannot be negative!\n");
            GetCrds();
        }
        T_Credits += tmp_crds;
        return;
    }
    GetPts();
    GetCrds();
    return;
}

void Remove(){
    if (T_Points == 0 || T_Credits == 0){
        printf("Add a course first!\n");
    }
    void GetPts(){
        char c;
        int tmp_pts;
        printf("Points (0 - 100): ");
        if (scanf("%d", &tmp_pts) == 0){
            throw("Invalid input!", 0);
            scanf("%c", c);
            GetPts();
        }
        if (tmp_pts < 0){
            printf("Cannot be negative!\n");
            GetPts();
        }
        if (T_Points - tmp_pts < 0){
            printf("Points will be negative!\n");
            return;
        }
        T_Points -= tmp_pts;
        return;
    }
    void GetCrds(){
        char c;
        int tmp_crds;
        printf("Credits (0 - 4): ");
        if (scanf("%d", &tmp_pts) == 0){
            throw("Invalid input!", 0);
            scanf("%c", c);
            GetCrds();
        }
        if (tmp_crds < 0){
            printf("Cannot be negative!\n");
            GetCrds();
        }
        if (T_Credits - tmp_crds < 0){
            printf("Credits will be negative!\n");
            return;
        }
        T_Credits -= tmp_crds;
        return;
    }
    GetPts();
    GetCrds();
    return;
}

double GetGPA(){
    double tmp_GPA;
    
    return tmp_GPA;
}

void Report(){
    printf("Total Credits: %d\n", T_Credits);
    printf("GPA: %lf\n", GetGPA());
}

void HandleChoice(int choice){
    switch(choise){
        case 1:
        Add();
        break;

        case 2:
        Remove();
        break;

        case 3:
        Report();
        break;

        case 4:
        Target();
        break;

        case 5:
        throw("Terminating...", 1);
        break;
    }
}

void MainMenu(){
    for (int i = 1; i < 6; i++){
        printf("%d) %s.\n", i, Options[i]);
    }
    return;
}

int GetChoice(){
    char c:
32_t Choice;
    printf("Your Choice (1-5): ");
    int state = scanf("%d", &Choice);
    if (state != 1){
        throw("That was not an integer >:\nMight cause error", 0);
        scanf("%c", c);
        GetChoice();
    }
    if (Choice > INT32_MAX){
        throw("Invalid input!", 0);
        GetChoice();
    }
    if (Choice < 1 || Choice > 5){
        throw("Invalid choice!", 0);
        GetChoice();
    }
    return Choice;
}

void Start(){
    int Choice;
    MainMenu();
    Choice = GetChoice();
    printf("Choice = %d", Choice);
    HandleChoice(Choice);
    return;
}

int main(){
    Start();
    return 0;
}