#include <stdio.h>
#include <stdlib.h>

int lvl, atk_1, type, status, mov_pwr, mov_type, mov_cat;
float atk, tgt_def;
int tgt_def_1, tgt_type;
int env_wx, env_ter;

int main(){
    int tmp;
    printf("Attacker\n");
    printf("    level: ");
    tmp = scanf("%d", &lvl);
    if (tmp != 1){
        printf("Invalid input.\n");
        return 1;
    }
    if (lvl < 0 || lvl > 100){
        printf("Invalid level.\n");
        return 1;
    }
    printf("    atk: ");
    tmp = scanf("%d", &atk_1);
    if (tmp != 1){
        printf("Invalid input.\n");
        return 1;
    }
    if (atk_1 <= 0){
        printf("atk must be a non-zero integer.\n");
        return 1;
    }
    printf("    type: ");
    tmp = scanf("%d", &type);
    if (tmp!= 1){
        printf("Invalid input\n");
        return 1;
    }
    if (type < 0 || type > 7){
        printf("Invalid pokemon type.\n");
        return 1;
    }
    printf("    status: ");
    tmp = scanf("%d", &status);
    if (tmp!= 1){
        printf("Invalid input.\n");
        return 1;
    }
    if (status < 0 || status > 2){
        printf("Invalid status.\n");
        return 1;
    }
    printf("    move power: ");
    tmp = scanf("%d", &mov_pwr);
    if (tmp!= 1){
        printf("Invalid input.\n");
        return 1;
    }
    if (mov_pwr < 0){
        printf("Invalid move power.\n");
        return 1;
    }
    printf("    move type: ");
    tmp = scanf("%d", &mov_type);
    if (tmp!= 1){
        printf("Invalid input.\n");
        return 1;
    }
    if (mov_type < 0 || mov_type > 5){
        printf("Invalid move type.\n");
        return 1;
    }
    printf("    move category: ");
    tmp = scanf("%d", &mov_cat);
    if (tmp!= 1){
        printf("Invalid input.\n");
        return 1;
    }
    if (mov_cat < 0 || mov_cat > 5){
        printf("Invalid move category.\n");
        return 1;
    }
    atk = atk_1;
    if (env_wx == 3 && type == 2){
        atk *= 0.5;
    }
    if (env_wx == 4 && type == 3){
        atk *= 2;
    }

    //Get Target data
    printf("Target\n");
    printf("    def: ");
    tmp = scanf("%d", &tgt_def_1);
    if (tmp != 1){
        printf("Invalid input.\n");
        return 1;
    }
    if (tgt_def_1 <= 0){
        printf("def must be a non-zero integer.\n");
        return 1;
    }
    printf("    type: ");
    tmp = scanf("%d", &tgt_type);
    if (tmp!= 1){
        printf("Invalid input.\n");
        return 1;
    }
    if (tgt_type < 0 || tgt_type > 7){
        printf("Invalif type.\n");
        return 1;
    }
    tgt_def = tgt_def_1;
    if (env_wx == 2 && tgt_type == 5){
        tgt_def *= 0.5;
    }
    if (env_wx == 5 && tgt_type == 4){
        tgt_def *= 2;

    }

    //get env data
    printf("Environment\n");
    printf("    weather: ");
    tmp = scanf("%d", &env_wx);
    if (tmp != 1){
        printf("invalid input\n");
        return 1;
    }
    if (env_wx < 0|| env_wx > 5){
        printf("Invalid weather.\n");
        return 1;
    }
    printf("    terrain:");
    tmp = scanf("%d", &env_ter);
    if (tmp != 1){
        printf("Invalid terrain.\n");
        return 1;
    }
    if (env_ter < 0 || env_ter > 3){
        printf("Invalid terrain.\n");
        return 1;
    }
    
    //WeatherBuff
    float WeatherBuff = 1;
    if (env_wx ==1){
        if (mov_type == 0){
            WeatherBuff = 0.5;
        }
        if (mov_type == 1){
            WeatherBuff = 1;
        }
    }
    if (env_wx == 2 ){
        if (mov_type == 0){
            WeatherBuff = 2;
        }
        if (mov_type == 1){
            WeatherBuff = 0.5;
        }
    }

    //Stab
    float Stab = 1;
    if (type == mov_type){
        Stab = 2;
    }

    //TypeBuff
    float TypeBuff;
    switch(type){
        case 0:
        switch(tgt_type){
            case 0:
            case 2:
            case 7:
            TypeBuff = 0.5;
            break;

            case 3:
            case 6:
            TypeBuff = 1;
            break;

            case 1:
            case 4:
            case 5:
            TypeBuff = 2;
            break;
        }
        break;

        case 1:
        switch(tgt_type){
            case 0:
            case 1:
            case 4:
            case 7:
            TypeBuff = 0.5;
            break;

            case 3:
            case 5:
            case 6:
            TypeBuff = 1;
            break;

            case 2:
            TypeBuff = 2;
            break;
        }

        case 2:
        switch(tgt_type){
            case 1:
            case 2:
            case 3:
            case 7:
            TypeBuff = 0.5;
            break;

            case 6:
            TypeBuff = 1;
            break;

            case 0:
            case 4:
            case 5:
            TypeBuff = 2;
            break;
        }

        case 3:
        switch(tgt_type){
            case 4:
            case 6:
            TypeBuff = 0.5;
            break;

            case 0:
            case 1:
            case 3:
            case 5:
            case 7:
            TypeBuff = 1;
            break;

            case 2:
            TypeBuff = 2;
            break;
        }

        case 4:
        switch(tgt_type){
            case 5:
            TypeBuff = 0.5;
            break;

            case 0:
            case 2:
            case 4:
            case 6:
            case 7:
            TypeBuff = 1;
            break;

            case 1:
            case 3:
            TypeBuff = 2;
            break;
        }

        case 5:
        switch(tgt_type){
            case 3:
            TypeBuff = 0;
            break;

            case 0:
            case 2:
            case 5:
            case 7:
            TypeBuff = 1;
            break;

            case 1:
            case 4:
            case 6:
            TypeBuff = 2;
            break;
        }

        case 6:
        switch(tgt_type){
            case 5:
            TypeBuff = 0;
            break;

            case 2:
            case 6:
            case 7:
            TypeBuff = 0.5;
            break;
            
            case 1:
            case 4:
            TypeBuff = 1;
            break;

            case 0:
            case 3:
            TypeBuff = 2;
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
            TypeBuff = 1;
            break;
            
            case 7:
            TypeBuff = 2;
            break;
        }
    }

    //Status
    /*
    if (status == 0 && mov_cat == 0) return 1;
    if (status = 1 && mov_cat == 0) return 0.5;
    if (status == 2 && mov_cat == 1) return 0.5;
    return 1;
}
    */
    float StatusBuff = 1;
    if (status == 0 && mov_cat == 0){
        StatusBuff = 1;
    }
    if ((status == 1 && mov_cat == 0) || (status == 2 && mov_cat == 1)){
        StatusBuff = 0.5;
    }

    //Terrain
    float TerrainBuff = 1;
    if (mov_type == 3){
        TerrainBuff = 1;
    }
    if ((env_ter == 1 && mov_type == 2) || (env_ter == 2 && mov_type == 6)){
        TerrainBuff = 2;
    }
    if (env_ter == 3 && mov_type == 7){
        TerrainBuff = 0.5;
    }
    float Factor = WeatherBuff * Stab * TypeBuff * StatusBuff * TerrainBuff;
    int Dmg = ((int)(((float)(lvl * 2 + 10) / (float) 250) * (atk / tgt_def) * mov_pwr) + 2) * Factor;
    printf("Damage --> %d\n", Dmg);
    return 0;
}