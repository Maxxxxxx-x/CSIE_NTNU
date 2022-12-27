#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void csie_interpreter(uint8_t code[], size_t size, size_t mem_limit){
    uint8_t *Memory = malloc(mem_limit);
    if (Memory == NULL){
        fprintf(stderr, "Error: failed to allocate memory\n");
        return;
    }
    uint8_t *DPointer = Memory;
    const uint8_t *CmdPointer = code;

    while (CmdPointer - code < size){
        uint8_t Cmd = *CmdPointer;

        switch(Cmd){
            case 0: //Increase data pointer
                if (DPointer - Memory >= mem_limit - 1){
                    fprintf(stderr, "Error: Data pointer out of bounds!\n");
                    return;
                }
                DPointer++;
                break;
            case 1: //Decrease data pointer
                if (DPointer - Memory <= 0){
                    fprintf(stderr, "Error: Data pointer out of bounds!\n");
                    return;
                }
                DPointer--;
                break;
            case 2: //Increase data pointer by 1
                (*DPointer)++;
                break;
            case 3: //Decrease data pointer by 1
                (*DPointer)--;
                break;
            case 4: //Output current uint8_t number at Data pointer
                printf("%d\n", *DPointer);
                break;
            case 5: //Read uint8)t from stdin
                if (scanf("%hhu", DPointer) != 1){
                    fprintf(stderr, "Error: Failed to read input!\n");
                }
                break;
            case 6: //Move command pointer to matching cmd 7 if data pointer is 0
                if (*DPointer == 0){
                    int Depth = 1;
                    while (Depth > 0 && CmdPointer - code < size){
                        CmdPointer++;
                        if (*CmdPointer == 6) Depth++;
                        if (*CmdPointer == 7) Depth--;
                    }
                }
                break;
            case 7: //Move to matching cmd 6 if data pointer is non zero
                if (*DPointer!= 0){
                    int Depth = 1;
                    while (Depth > 0 && CmdPointer - code > 0){
                        CmdPointer--;
                        if (*CmdPointer == 6) Depth--;
                        if (*CmdPointer == 7) Depth++;
                    }
                    CmdPointer--;
                }
                break;
        }
        CmdPointer++;
    } 
    free(Memory);
}