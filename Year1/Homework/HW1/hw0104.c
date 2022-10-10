#include <stdio.h>
#include <stdlib.h>

int lvl, atk_1, type, status, mov_pwr, mov_type, mov_cat;
float atk, tgt_def;
int tgt_def_1, tgt_type;
int env_wx, env_ter;

char SpaceFormat[4] = "    ";

void HandleStatusMismatch(int Status){
    if (Status != 1) {
        printf("Invalid input.\n");
        exit(1);
    }
}


void HandleInvalidStat(char* ErrMsg){
    printf("%s\n", ErrMsg);
    exit(1);
}


void ValidateStat(int Stat, int StatType){
    switch(StatType){
        case 0:
        if (Stat < 0 || Stat > 100) HandleInvalidStat("Invalid level.");
        break;

        case 1:
        if (Stat <= 0) HandleInvalidStat("Atk must be a non-zero integer.");
        break;

        case 2:
        if (Stat < 0 || Stat > 7) HandleInvalidStat("Invalid Pokemon type.");
        break;

        case 3:
        if (Stat < 0 || Stat > 2) HandleInvalidStat("Invalid status.");
        break;

        case 4:
        if (Stat <= 0) HandleInvalidStat("move power must be a non-zero integer.");
        break;

        case 5:
        if (Stat < 0 || Stat > 7) HandleInvalidStat("Invalid move type");
        break;

        case 6:
        if (Stat < 0 || Stat > 1) HandleInvalidStat("Invalid move category");
        break;

        case 7:
        if (Stat <= 0) HandleInvalidStat("def must be a non-zero integer.");
        break;

        case 8:
        if (Stat < 0 || Stat > 7) HandleInvalidStat("Invalid type.");
        break;

        case 9:
        if (Stat < 0 || Stat > 5) HandleInvalidStat("Invalid weather.");
        break;

        case 10:
        if (Stat < 0 || Stat > 3) HandleInvalidStat("Invalid Terrain.");
        break;

        default:
        HandleInvalidStat("Unexpected Error: StatType not given.");
        break;
    }
}

int GetInput(char* Question, int Type){
    int tmp;
    printf("%s%s: ", SpaceFormat, Question);
    int status = scanf("%d", &tmp);
    HandleStatusMismatch(status);
    ValidateStat(tmp, Type);
    return tmp;
}

float GetWeatherBuff(){
    if (env_wx == 1){
        if (mov_type == 0) return 0.5;
        if (mov_type == 1) return 2;
    }
    if (env_wx == 2){
        if (mov_type == 0) return 2;
        if (mov_type == 1) return 0.5;
    }
    return 1;
}

float GetTypeBuff(){
    switch(type){
        case 0:
        switch(tgt_type){
            case 0:
            case 2:
            case 7:
            return 0.5;
            break;

            case 3:
            case 6:
            return 1;
            break;

            case 1:
            case 4:
            case 5:
            return 2;
            break;
        }
        break;

        case 1:
        switch(tgt_type){
            case 0:
            case 1:
            case 4:
            case 7:
            return 0.5;
            break;

            case 3:
            case 5:
            case 6:
            return 1;
            break;

            case 2:
            return 2;
            break;
        }

        case 2:
        switch(tgt_type){
            case 1:
            case 2:
            case 3:
            case 7:
            return 0.5;
            break;

            case 6:
            return 1;
            break;

            case 0:
            case 4:
            case 5:
            return 2;
            break;
        }

        case 3:
        switch(tgt_type){
            case 4:
            case 6:
            return 0.5;
            break;

            case 0:
            case 1:
            case 3:
            case 5:
            case 7:
            return 1;
            break;

            case 2:
            return 2;
            break;
        }

        case 4:
        switch(tgt_type){
            case 5:
            return 0.5;
            break;

            case 0:
            case 2:
            case 4:
            case 6:
            case 7:
            return 1;
            break;

            case 1:
            case 3:
            return 2;
            break;
        }

        case 5:
        switch(tgt_type){
            case 3:
            return 0;
            break;

            case 0:
            case 2:
            case 5:
            case 7:
            return 1;
            break;

            case 1:
            case 4:
            case 6:
            return 2;
            break;
        }

        case 6:
        switch(tgt_type){
            case 5:
            return 0;
            break;

            case 2:
            case 6:
            case 7:
            return 0.5;
            break;
            
            case 1:
            case 4:
            return 1;
            break;

            case 0:
            case 3:
            return 2;
            break;
        }

        case 7:
        switch(tgt_type){
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            return 1;
            break;
            
            case 7:
            return 2;
            break;
        }
    }
}

float GetStab(){
    if (type == mov_type) return 2;
    return 1;
}

float GetStatus(){
    if (status == 0 && mov_cat == 0) return 1;
    if (status = 1 && mov_cat == 0) return 0.5;
    if (status == 2 && mov_cat == 1) return 0.5;
    return 1;
}

float GetTerrain(){
    if (mov_type == 3 ) return 1;
    if (env_ter == 1 && mov_type == 2) return 2;
    if (env_ter == 2 && mov_type == 6) return 2;
    if (env_ter == 3 && mov_type == 7) return 0.5;
    return 1;
}

float GetFactor(){
    float WeatherBuff = GetWeatherBuff();
    float Stab = GetStab();
    float TypeBuff = GetTypeBuff(); //this
    float StatusBuff = GetStatus();
    float TerrrainBuff = GetTerrain();
    printf("FACTOR: %lf * %lf * %lf * %lf * %lf\n", WeatherBuff, Stab, TypeBuff, StatusBuff, TerrrainBuff);
    return WeatherBuff * Stab * TypeBuff * StatusBuff * TerrrainBuff;
}

int CalculateDmg(){
    float Factor = GetFactor();
    printf("DEBUG_FACTOR: %lf\n", Factor);
    printf("DEBUG_DMG: (((%d * 2 + 10) / 250) * (%lf / %lf) * %d) + 2 * %lf\n", lvl, atk, tgt_def, mov_pwr, Factor);
    int Dmg = ((int)(((float)(lvl * 2 + 10) / (float) 250) * (atk / tgt_def) * mov_pwr) + 2) * Factor;
    return Dmg;
}

void GetAtkData(){
    printf("Attacker\n");
    lvl = GetInput("level", 0);
    atk_1 = GetInput("atk", 1);
    type = GetInput("type", 2);
    status = GetInput("status", 3);
    mov_pwr = GetInput("move power", 4);
    mov_type = GetInput("move type", 5);
    mov_cat = GetInput("move category", 6);
    atk = atk_1;
    if (env_wx == 3 && type == 2){
        atk *= 0.5;
        return;
    }
    if (env_wx == 4 && type == 3){
        atk *= 2;
        return;
    }
}

void GetTgtData(){
    printf("Target\n");
    tgt_def_1 = GetInput("def", 7);
    tgt_type = GetInput("type", 8);
    tgt_def = tgt_def_1;
    if (env_wx == 2 && tgt_type == 5){
        tgt_def *= 0.5;
        return;
    }
    if (env_wx == 5 && tgt_type == 4){
        tgt_def *= 2;
        return;
    }
}

void GetEnvData(){
    printf("Environment\n");
    env_wx = GetInput("weather", 9);
    env_ter = GetInput("terrain", 10);
}

int main(){
    GetAtkData();
    GetTgtData();
    GetEnvData();
    int Dmg = CalculateDmg();
    printf("Damage --> %d\n", Dmg);
    return 0;
}