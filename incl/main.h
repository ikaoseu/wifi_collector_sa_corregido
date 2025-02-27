#ifndef MAIN_H  
#define MAIN_H

#define MAX_STRING_SIZE 80
#define ARRAY_SIZE 200
#define LINE_SIZE 80

int menu_int;

typedef struct connections
{
    char cell_num[MAX_STRING_SIZE];
    char mac[MAX_STRING_SIZE];
    char essid[MAX_STRING_SIZE];
    char mode[MAX_STRING_SIZE];
    char channel[MAX_STRING_SIZE];
    char en_key[MAX_STRING_SIZE];
    char quality[MAX_STRING_SIZE];
    char freq[MAX_STRING_SIZE];
    char signal_l[MAX_STRING_SIZE];
} connection_t;

struct connections conn_array[ARRAY_SIZE];

// pretendemos hacer un array de structs

// collect data celda 21, hacemos un leerporlineas, nos devuelve una salida (txt), esta salida la guardamos en connections es un array, 

// en vez de almacenar ints definimos con el struct una variable que se va a llamar conexiones (qu conexiones a su vez van a ser arrays)

//hay que crear una funcion que saque lo leido de un file y lo meta en un struct

void print_menu();
int choose_cell();
#endif
