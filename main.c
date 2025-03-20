/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif




char *enumtochar(tConsoleBrand b) {
    if (b==nintendo) {
        return "nintendo";
    }
    else {return "sega";}
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4) {
    tList list;
    tItemL item;
    createEmptyList(&list);

    switch (command) {

        case 'N':
            printf("********************\n%s %c: console %s seller %s brand %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            strcpy(item.consoleId, param1);
            strcpy(item.seller, param2);
            if (strcmp("nintendo", param3) == 0) {
                item.consoleBrand=nintendo;
            }
            else {
                item.consoleBrand=sega;
            }
            item.consolePrice=atoi(param4);
            item.bidCounter=0;
            insertItem(item,LNULL,&list);
            if (insertItem(item,LNULL,&list)==true) {
                printf("New: console %s seller %s brand %s price %s\n",param1, param2, param3, param4);
            }
            else {
                printf("+ Error: New not possible\n");
            }
            break;

        case 'D':
            printf("********************\n%s %c: console %s \n", commandNumber, command, param1);
            tItemL item1=getItem(findItem(param1,list),list);
            deleteAtPosition(findItem(param1,list),&list);
            if (findItem(param1,list)==LNULL) {
                printf("Delete: console %s seller %s brand %s price %f bids %d\n",item1.consoleId,item1.seller,enumtochar(item1.consoleBrand), item1.consolePrice,item1.bidCounter);
            }
            else {
                printf("+ Error: Delete not possible\n");
            }
            break;

        case 'B':
            printf("********************\n%s %c: console %s bidder %s brand %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            break;

        case 'S':
            printf("********************\n%s %c\n", commandNumber, command);
            tPosL p=first(list);
            do {
                printf("Console %s seller %s brand %s price %f bids %d\n",getItem(p,list).consoleId,getItem(p,list).seller,enumtochar(getItem(p,list).consoleBrand),getItem(p,list).consolePrice,getItem(p,list).bidCounter);
                p=next(p,list);
            }while (next(p,list)!=LNULL);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);
            processCommand(commandNumber, command[0], param1, param2, param3, param4);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}






