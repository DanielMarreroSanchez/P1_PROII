/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Daniel Marrero Sánchez LOGIN 1: **********
 * AUTHOR 2: Iago Bescansa Alcoba LOGIN 2: **********
 * GROUP: 1.2
 * DATE: 21 / 03 / 25
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

void init(char *param1, char *param2,char *param3 ,char *param4, tList *list){
    tItemL item;

    strcpy(item.consoleId, param1);
    strcpy(item.seller, param2);
    if (strcmp("nintendo", param3) == 0) {
        item.consoleBrand=nintendo;
    }
    else {
        item.consoleBrand=sega;
    }
    item.consolePrice=atof(param4);
    item.bidCounter=0;
    if(findItem(param1,*list)==LNULL) {
        if (insertItem(item,LNULL,list)==true) {
            printf("* New: console %s seller %s brand %s price %s\n",param1, param2, param3, param4);
        }
    }
    else {
        printf("+ Error: New not possible\n");
    }

}

void borrar(char *param1, tList *list){
    if (findItem(param1,*list)!=LNULL) {

        tItemL item1=getItem(findItem(param1,*list),*list);
        printf("* Delete: console %s seller %s brand %s price %.2f bids %d\n",item1.consoleId,item1.seller,enumtochar(item1.consoleBrand), item1.consolePrice,item1.bidCounter);
        deleteAtPosition(findItem(param1,*list),list);
    }
    else {
        printf("+ Error: Delete not possible\n");
    }
}



void pujar(char *param1, char *param2, char *param3, tList *list){
    tItemL i=getItem(findItem(param1,*list),*list);
    tPosL p = findItem(param1,*list);
    if (strcmp(param2, i.seller) != 0 && i.consolePrice<atof(param3) && findItem(param1,*list)!=LNULL) {

        i.consolePrice = atof(param3);
        i.bidCounter++;
        updateItem(i, p,list);
        printf("* Bid: console %s seller %s brand %s price %.2f bids %d\n", i.consoleId, i.seller, enumtochar(i.consoleBrand), i.consolePrice, i.bidCounter);
    }
    else
        printf("+ Error: Bid not possible\n");
}

void estadisticas(tList *list){
    int n=0,s=0;
    float sumn=0,sums=0;


    for(tPosL p=first(*list);p!=LNULL;p=next(p,*list)) {
        printf("Console %s seller %s brand %s price %.2f bids %d\n",getItem(p,*list).consoleId,getItem(p,*list).seller,
                                                                            enumtochar(getItem(p,*list).consoleBrand),getItem(p,*list).consolePrice,
                                                                            getItem(p,*list).bidCounter);

        if(getItem(p,*list).consoleBrand==nintendo) {
            n++;
            sumn+=getItem(p,*list).consolePrice;
        }
        else {
            s++;
            sums+=getItem(p,*list).consolePrice;
        }
    }

    float mediaN = 0;
    float mediaS = 0;
    if (n >= 1)
        mediaN = sumn / (float)n;
    if (s >= 1)
        mediaS = sums / (float)s;


    printf("Brand     Consoles    Price  Average\n"
                   "Nintendo  %8d %8.2f %8.2f\n"
                   "Sega      %8d %8.2f %8.2f\n", n, sumn, mediaN, s, sums, mediaS);

}


void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *list) {
    switch (command) {

        case 'N':
            printf("********************\n"
                          "%s %c: console %s seller %s brand %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            init(param1, param2, param3,param4, list);
            break;

        case 'D':
            printf("********************\n"
                          "%s %c: console %s \n", commandNumber, command, param1);
            borrar(param1, list);
            break;

        case 'B':
            printf("********************\n"
                   "%s %c: console %s bidder %s price %s \n", commandNumber, command, param1, param2, param3);
            pujar(param1, param2,param3, list);
            break;

        case 'S':
            printf("********************\n"
                          "%s %c\n", commandNumber, command);
            estadisticas(list);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    tList list;
    createEmptyList(&list);
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
            processCommand(commandNumber, command[0], param1, param2, param3, param4,&list);
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
