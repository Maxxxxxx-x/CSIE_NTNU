#include <stdio.h>
#include <stdlib.h>

void CheckState(int state, int req, char* err){
    if (state == req) return;
    printf("%s\n", err);
    exit(1);
}

int LookUp[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void ValidateDate(int Date[3], char* DateType){
    if (Date[1] < 1 || Date[1] > 31 || Date[0] < 1 || Date[0] > 12) goto Invalid_Date;
    int IsLeap = 0;
    if (Date[2] % 4 == 0) IsLeap = 1;
    if (Date[0] != 2 && LookUp[Date[0]] && Date[1] <= LookUp[Date[1]]) return;
    if ((IsLeap == 1 && Date[0] == 2 && Date[1] <= 29) || (IsLeap == 0 && Date[0] == 2 && Date[1] <= 28)) return;
    Invalid_Date:
    printf("Invalid %s date.\n", DateType);
    exit(1);
}

void PrintDate(int Day, int Month, int Year){
    int d_r = "";
    int m_r = "";
    if (Day < 10) d_r = "0";
    if (Month < 10) m_r = "0";
    printf("%s%d-%s%d-%d", d_r, Day, m_r, Month, Year);
}


void ListDatesBetween(int StartDate[3], int EndDate[3]){
    //Date mm/dd/yyyy
    int s_d, s_m, s_y = StartDate[1], StartDate[0], StartDate[2];
    int e_d, e_m, e_y = EndDate[1], EndDate[0], EndDate[2]
    if (s_d == s_m){
        PrintDate(s_d, s_m, s_y);
    }
    while (1){
        if (s_d == e_d && s_m == e_m && s_y == e_y) break
    }
}

int main(){
    int StartDate[3];
    int EndDate[3];
    int state;
    printf("Start Date: ");
    state = scanf("%d-%d-%d", &StartDate[0], &StartDate[1], &StartDate[2]);
    CheckState(state, 3, "Invalid Input.");
    ValidateDate(StartDate, "Start");
    printf("End Date: ");
    state = scanf("%d-%d-%d", &EndDate[0], &EndDate[1], &EndDate[2]);
    CheckState(state, 3, "Invalid Input.");
    ValidateDate(EndDate, "End");
    if (EndDate[2] < StartDate[2]) goto Exit;
    if (EndDate[2] == StartDate[2] && EndDate[1] < StartDate[1]) goto Exit;
    if (EndDate[2] == StartDate[2] && EndDate[1] == StartDate[1] && EndDate[0] < StartDate[0]) goto Exit;

    ListDatesBetween(StartDate, EndDate);
    main();
    return 0;
    Exit:
    printf("Swap Start Date and End Date\n.");
    return 1;
}