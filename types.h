#ifndef PRO2_2024_P1_TYPES_H
#define PRO2_2024_P1_TYPES_H

#define NAME_LENGTH_LIMIT 10

typedef char tUserId[NAME_LENGTH_LIMIT];
typedef char tConsoleId[NAME_LENGTH_LIMIT];
typedef enum {nintendo, sega} tConsoleBrand;
typedef float tConsolePrice;
typedef int tBidCounter;
typedef int tPosL;

typedef struct tItemL {
    tPosL pos;//Añado place para poder comparar las diferentes casillas del array como enteros
    tUserId seller;
    tConsoleId consoleId;
    tConsoleBrand consoleBrand;
    tConsolePrice consolePrice;
    tBidCounter bidCounter;
} tItemL;


#endif

