#include <stdio.h>
#include <stdlib.h>

int Type1, Type2, Type3, Type4, Type5; //Unsorted
int Sorted_Type1, Sorted_Type2, Sorted_Type3, Sorted_Type4, Sorted_Type5; //Sorted, Largest -> Smallest

void HandleStateMismatch(int State, int Req){
    if (State == Req) return;
    printf("Invalid input.");
    exit(1);
}

int GetCardIndex(int Card){
    int CardNo = Card % 13;
    if (CardNo == 0) return 13;
    return CardNo;
}

/*
CARD TYPES REFERENCE
Spade = 1
Heart = 2
Diamond = 3
Club = 4
*/

int GetCardType (int CardNum){
    if (CardNum >= 1 && CardNum<= 13) return 1;
    if (CardNum >= 14 && CardNum <= 26) return 2;
    if (CardNum >= 27 && CardNum <= 39) return 3;
    return 4;
}

void Sort(int A, int B, int C, int D, int E){ //if it works, it works, dont question it anymore, dont touch it anymore, leave it here
    int tmp1 = 0;
    int tmp2 = 0;
    int tmp3 = 0;
    int tmp4 = 0;
    int tmp5 = 0;
    int tmp;
    if (A > B){
        tmp1 = A;
        tmp2 = B;
    }else{
        tmp1 = B;
        tmp2 = A;
    }
    printf("DEBUG 1: %d | %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4, tmp5);
    if (C > D){
        tmp3 = C;
        tmp4 = D;
    }else{
        tmp3 = D;
        tmp4 = C;
    }
    printf("DEBUG 2: %d | %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4, tmp5);
    if (tmp1 == tmp3){
        tmp = tmp2;
        tmp2 = tmp3;
        tmp3 = tmp;
    }
    printf("DEBUG 3: %d | %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4, tmp5);
    if (tmp2 < tmp3){
        tmp = tmp2;
        tmp2 = tmp3;
        tmp3 = tmp;
    }
    printf("DEBUG 4: %d | %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4, tmp5);
    if (tmp3 < tmp4){
        tmp = tmp3;
        tmp3 = tmp4;
        tmp4 = tmp;
    }
    printf("DEBUG 5: %d | %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4, tmp5);
    if (tmp4 < tmp5){
        tmp = tmp4;
        tmp4 = tmp5;
        tmp5 = tmp;
    }
    printf("DEBUG 6: %d | %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4, tmp5);
    if (E <= tmp4) tmp5 = E;
    printf("DEBUG 7: %d | %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4, tmp5);
    if (E >= tmp4){
         if (E >= tmp1){
            tmp5 = tmp4;
            tmp4 = tmp3;
            tmp3 = tmp2;
            tmp2 = tmp1;
            tmp1 = E;
            Sorted_Type1 = tmp1;
            Sorted_Type2 = tmp2;
            Sorted_Type3 = tmp3;
            Sorted_Type4 = tmp4;
            Sorted_Type5 = tmp5;
    printf("DEBUG 8: %d | %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4, tmp5);
            return;
        }
        if (E >= tmp2){
            tmp5 = tmp4;
            tmp4 = tmp3;
            tmp3 = tmp2;
            tmp2 = E;
            Sorted_Type1 = tmp1;
            Sorted_Type2 = tmp2;
            Sorted_Type3 = tmp3;
            Sorted_Type4 = tmp4;
            Sorted_Type5 = tmp5;
    printf("DEBUG 9: %d | %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4, tmp5);
            return;
        }
        if (E >= tmp3){
            tmp5 = tmp4;
            tmp4 = tmp3;
            tmp3 = E;
            Sorted_Type1 = tmp1;
            Sorted_Type2 = tmp2;
            Sorted_Type3 = tmp3;
            Sorted_Type4 = tmp4;
            Sorted_Type5 = tmp5;
    printf("DEBUG 10: %d | %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4, tmp5);
            return;
        }
        
        tmp5 = tmp4;
        tmp4 = E;

            Sorted_Type1 = tmp1;
            Sorted_Type2 = tmp2;
            Sorted_Type3 = tmp3;
            Sorted_Type4 = tmp4;
            Sorted_Type5 = tmp5;
    printf("DEBUG 11: %d | %d | %d | %d | %d\n", tmp1, tmp2, tmp3, tmp4, tmp5);
        return;
    }
}

void CheckValidCards(int Card1, int Card2, int Card3, int Card4, int Card5){
    if (Card1 < 1 || Card1 > 52 || Card2 < 1 || Card2 > 52 || Card3 < 1 || Card3 > 52 || Card4 < 1 || Card4 > 52 || Card5 < 1 || Card5 > 52){
        printf("Invalid card.");
        exit(1);
    }
    if (Card1 == Card2 || Card1 == Card3 || Card1 == Card4 || Card1 == Card5 || Card2 == Card3 || Card2 == Card4 || Card2 == Card5 || Card3 == Card4 || Card3 == Card5 || Card4 == Card5){
        printf("Duplicated cards detected. Cheater!\n");
        exit(1);
    }
    Type1 = GetCardIndex(Card1);
    Type2 = GetCardIndex(Card2);
    Type3 = GetCardIndex(Card3);
    Type4 = GetCardIndex(Card4);
    Type5 = GetCardIndex(Card5);
    Sort(Type1, Type2, Type3, Type4, Type5);
    Type1 = GetCardType(Card1);
    Type2 = GetCardType(Card2);
    Type3 = GetCardType(Card3);
    Type4 = GetCardType(Card4);
    Type5 = GetCardType(Card5);
    return;
}


/*
A = 1
K = 2
Q = 3
J = 4
10 = 5
9 = 6
8 = 7
7 = 8
6 = 9
5 = 10
4 = 11
3 = 12
2 = 13
*/

int IsStraightFlush(int Card1, int Card2, int Card3, int Card4, int Card5){
    if (Type1 != Type2 && Type1 != Type3 && Type1 != Type4 && Type1 != Type5) return 0;
    printf("Same card types!");
    if (Sorted_Type5 - 4 == Sorted_Type1 && Sorted_Type4 - 3 == Sorted_Type1 && Sorted_Type3 - 2 == Sorted_Type1 && Sorted_Type2 - 1 == Sorted_Type1) return 1;
    return 0;
}

int IsFourOfAKind(int Card1, int Card2, int Card3, int Card4, int Card5){
}

int IsFullHouse(int Card1, int Card2, int Card3, int Card4, int Card5){
}

int IsFlush(int Card1, int Card2, int Card3, int Card4, int Card5){
}

int IsStraight(int Card1, int Card2, int Card3, int Card4, int Card5){
}

int IsThreeOfAKind(int Card1, int Card2, int Card3, int Card4, int Card5){
}

int IsTwoPairs(int Card1, int Card2, int Card3, int Card4, int Card5){
}

int IsOnePair(int Card1, int Card2, int Card3, int Card4, int Card5){
}

int IsHighCard(int Card1, int Card2, int Card3, int Card4, int Card5){
}

int main(){
    int Card1, Card2, Card3, Card4, Card5;
    printf("Please enter 5 cards: ");
    int state = scanf("%d %d %d %d %d", &Card1, &Card2, &Card3, &Card4, &Card5);
    HandleStateMismatch(state, 5);
    CheckValidCards(Card1, Card2, Card3, Card4, Card5);
    printf("Sorted Cards: %d | %d | %d | %d | %d\n", Sorted_Type1, Sorted_Type2, Sorted_Type3, Sorted_Type4, Sorted_Type5);
    printf("Card   Types: %d | %d | %d | %d | %d\n", Type1, Type2, Type3, Type4, Type5);
    if (IsStraightFlush(Card1, Card2, Card3, Card4, Card5) == 1){
        printf("Straight Flush");
        return 0;
    } 
    if (IsFourOfAKind(Card1, Card2, Card3, Card4, Card5) == 1){
        printf("Four of a Kind");
        return 0;
    }  
    if (IsFullHouse(Card1, Card2, Card3, Card4, Card5) == 1){
        printf("Full House");
        return 0;
    }  
    if (IsFlush(Card1, Card2, Card3, Card4, Card5) == 1){
        printf("Flush");
        return 0;
    } 
    if (IsStraight(Card1, Card2, Card3, Card4, Card5) == 1){
        printf("Straight");
        return 0;
    }  
    if (IsThreeOfAKind(Card1, Card2, Card3, Card4, Card5) == 1){
        printf("Three of a Kind");
        return 0;
    } 
    if (IsTwoPairs(Card1, Card2, Card3, Card4, Card5) == 1){
        printf("Two Pairs");
        return 0;
    }  
    if (IsOnePair(Card1, Card2, Card3, Card4, Card5) == 1){
        printf("One Pair");
        return 0;
    } 
    if (IsHighCard(Card1, Card2, Card3, Card4, Card5) == 1){
        printf("High Card");
        return 0;
    }
    printf("Unrecognized hand");
    return 0;
}