#include <stdio.h>
#include <stdlib.h>

int DebugMode = 1;

int main(){
    int Card1, Card2, Card3, Card4, Card5;
    int Type1, Type2, Type3, Type4, Type5;
    printf("Please enter 5 cards: ");
    int state = scanf("%d %d %d %d %d", &Card1, &Card2, &Card3, &Card4, &Card5);
    if (state != 5){
        printf("Invalid input.\n");
        return 1;
    };
    if (Card1 < 1 || Card1 > 52 || Card2 < 1 || Card2 > 52 || Card3 < 1 || Card3 > 52 || Card4 < 1 || Card4 > 52 || Card5 < 1 || Card5 > 52){
        printf("Invalid card.");
        return 1;
    }
    if (Card1 == Card2 || Card1 == Card3 || Card1 == Card4 || Card1 == Card5 || Card2 == Card3 || Card2 == Card4 || Card2 == Card5 || Card3 == Card4 || Card3 == Card5 || Card4 == Card5){
        printf("Duplicated cards detected. Cheater!\n");
        return 1;
    }
    Type1 = Card1 % 13;
    if (Type1 == 0){
        Type1 = 13;
    }
    Type2 = Card2 % 13;
    if (Type2 == 0){
        Type2 = 13;
    }
    Type3 = Card3 % 13;
    if (Type3 == 0){
        Type3 = 13;
    }
    Type4 = Card4 % 13;
    if (Type4 == 0){
        Type4 = 13;
    }
    Type5 = Card5 % 13;
    if (Type5 == 0){
        Type5 = 13;
    }
    //sort 
    int tmp1 = 0;
    int tmp2 = 0;
    int tmp3 = 0;
    int tmp4 = 0;
    int tmp5 = 0;
    int tmp;
    

     if (Type1 > Type2){
        tmp1 = Type1;
        tmp2 = Type2;
    }else{
        tmp1 = Type2;
        tmp2 = Type1;
    }
    //sort C D
    if (Type3 > Type4){
        tmp3 = Type3;
        tmp4 = Type4;
    }else{
        tmp3 = Type4;
        tmp4 = Type3;
    }
    
    if (DebugMode == 1){
        printf("DEBUG 1: %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4);
    }

    if (tmp3 >= tmp1 || tmp3 > tmp2){
        if (tmp3 >= tmp1 || tmp3 > tmp2){
            if (tmp3 > tmp1){
                tmp = tmp3;
                tmp3 = tmp2;
                tmp2 = tmp1;
                tmp1 = tmp;
                if (tmp4 > tmp3){
                    tmp = tmp4;
                    tmp4 = tmp3;
                    tmp3 = tmp;
                }
            }
            if (tmp3 == tmp1){
                tmp = tmp3;
                tmp3 = tmp2;
                tmp2 = tmp;
                if (tmp4 > tmp3){
                    tmp = tmp4;
                    tmp4 = tmp3;
                    tmp3 = tmp;
                }
            }
            if (tmp3 > tmp2){
                tmp = tmp3;
                tmp3 = tmp2;
                tmp2 = tmp;
            }
        }
        if (tmp4 > tmp3){
            tmp = tmp4;
            tmp4 = tmp3;
            tmp3 = tmp;
        }
    }

    if (DebugMode == 1){
        printf("DEBUG 2: %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4);
    }

    int pass = 0;
    if (Type5 >= tmp1 && pass == 0){
        if (Type5 > tmp1 && pass == 0){
            tmp5 = tmp4;
            tmp4 = tmp3;
            tmp3 = tmp2;
            tmp2 = tmp1;
            tmp1 = Type5;
            pass = 1;
        }
        if (Type5 == tmp1 && pass == 0){
            tmp5 = tmp4;
            tmp4 = tmp3;
            tmp3 = tmp3;
            tmp2 = Type5;
            pass = 1;
        }
    }
    if (Type5 >= tmp2 && pass == 0){
        if (Type5 > tmp2 && pass == 0){
            tmp5 = tmp4;
            tmp4 = tmp3;
            tmp3 = tmp2;
            tmp2 = Type5;
            pass = 1;
        }
        if (Type5 == tmp2 && pass == 0){
            tmp5 = tmp4;
            tmp4 = tmp3;
            tmp3 = Type5;
            pass = 1;
        }
    }
    if (Type5 >= tmp3 && pass == 0){
        if (Type5 > tmp3 && pass == 0){
            tmp5 = tmp4;
            tmp4 = tmp3;
            tmp3 = Type5;
            pass = 1;
        }
        if (Type5 == tmp3 && pass == 0){
            tmp5 = tmp4;
            tmp4 = Type5;
            pass = 1;
        }
    }

    if (Type5 >= tmp4 && pass == 0){
        if (Type5 > tmp4 && pass == 0){
            tmp5 = tmp4;
            tmp4 = Type5;
            pass = 1;
        }
    }

    if (Type5 <= tmp4 && pass == 0){
        tmp5 = Type5;
        pass = 1;
    }

    if (DebugMode == 1){
        printf("DEBUG 3: %d | %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4, tmp5);
    }
    int Sorted_Type1 = tmp1;
    int Sorted_Type2 = tmp2;
    int Sorted_Type3 = tmp3;
    int Sorted_Type4 = tmp4;
    int Sorted_Type5 = tmp5;
    
    //GetType
    //Card1
    if (Card1 >= 1 && Card1 <= 13){
        Type1 = 1;
    }
    if (Card1 >= 14 && Card1 <= 26){
        Type1 = 2;
    }
    if (Card1 >= 27 && Card1 <= 39){
        Type1 = 3;
    }
    if (Card1 >= 40 && Card1 <= 52){
        Type1 = 4;
    }
    //Card2
    if (Card2 >= 1 && Card2 <= 13){
        Type2 = 1;
    }
    if (Card2 >= 14 && Card2 <= 26){
        Type2 = 2;
    }
    if (Card2 >= 27 && Card2 <= 39){
        Type2 = 3;
    }
    if (Card2 >= 40 && Card2 <= 52){
        Type2 = 4;
    }
    //Card3
    if (Card3 >= 1 && Card3 <= 13){
        Type3 = 1;
    }
    if (Card3 >= 14 && Card3 <= 26){
        Type3 = 2;
    }
    if (Card3 >= 27 && Card3 <= 39){
        Type3 = 3;
    }
    if (Card3 >= 40 && Card3 <= 52){
        Type3 = 4;
    }
    //Card4
    if (Card4 >= 1 && Card4 <= 13){
        Type4 = 1;
    }
    if (Card4 >= 14 && Card4 <= 26){
        Type4 = 2;
    }
    if (Card4 >= 27 && Card4 <= 39){
        Type4 = 3;
    }
    if (Card4 >= 40 && Card4 <= 52){
        Type4 = 4;
    }
    //Card5
    if (Card5 >= 1 && Card5 <= 13){
        Type5 = 1;
    }
    if (Card5 >= 14 && Card5 <= 26){
        Type5 = 2;
    }
    if (Card5 >= 27 && Card5 <= 39){
        Type5 = 3;
    }
    if (Card5 >= 40 && Card5 <= 52){
        Type5 = 4;
    }
    if (DebugMode == 1){
        printf("DEBUG: types %d | %d | %d | %d | %d\n", Type1, Type2, Type3, Type4, Type5);
    }

    //Pattern check
    int Flush = 0;
    int Straight = 0;
    if (Type1 == Type2 == Type3 == Type4 == Type5){
        Flush = 1;
    }
    printf("Sorted = %d | %d | %d | %d | %d\n", Sorted_Type1, Sorted_Type2, Sorted_Type3, Sorted_Type4, Sorted_Type5);
    if (Sorted_Type1 == Sorted_Type2 + 1 && Sorted_Type1 == Sorted_Type3 + 2 && Sorted_Type1 == Sorted_Type4 + 3 && Sorted_Type1 == Sorted_Type5 + 4){
        Straight = 1;
    }
    if (Straight == 1 && Flush == 1){
        printf("Straight Flush\n");
        return 0;
    }
    if (Straight == 1){
        printf("Straight\n");
        return 0;
    }
    if (Flush == 1){
        printf("Flush\n");
        return 0;
    }
    
    if (Sorted_Type1 == Sorted_Type2 && Sorted_Type3 == Sorted_Type4 && Sorted_Type4 == Sorted_Type5 || Sorted_Type4 == Sorted_Type5 && Sorted_Type1 == Sorted_Type2 && Sorted_Type2 == Sorted_Type3 ){
        printf("Full house\n");
        return 0;
    }

    if (Sorted_Type1 == Sorted_Type2 && Sorted_Type2 == Sorted_Type3 || Sorted_Type3 == Sorted_Type4 && Sorted_Type4 == Sorted_Type5){
        printf("Three of a kind\n");
        return 0;
    }

    if (Sorted_Type1 == Sorted_Type2 && Sorted_Type2 == Sorted_Type3 && Sorted_Type3 == Sorted_Type4 || Sorted_Type2 == Sorted_Type3 && Sorted_Type3 == Sorted_Type4 && Sorted_Type4 == Sorted_Type5){
        printf("Four of a Kind\n");
        return 0;
    }
    
    if ((Sorted_Type1 == Sorted_Type2 && Sorted_Type3 == Sorted_Type4 || Sorted_Type4 == Sorted_Type5) || (Sorted_Type2 == Sorted_Type3 && Sorted_Type4 == Sorted_Type5)){
        printf("Two pairs\n");
        return 0;
    }

    if (Sorted_Type1 == Sorted_Type2 || Sorted_Type2 == Sorted_Type3 || Sorted_Type3 == Sorted_Type4 || Sorted_Type4 == Sorted_Type5){
        printf("Pair\n");
        return 0;
    }

    //Unrecognized
    printf("High Card\n");
    return 0;
}