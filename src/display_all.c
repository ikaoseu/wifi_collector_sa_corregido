#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/display_all.h"
#include "../incl/main.h"

int count_v;

//this function prints the connection array with all its information

// prints the info of all cells

void print_all()
{
    for (int i = 0; i < count_v; i++)
    {
        printf("\n%s %s %s %s %s %s %s %s %s\n",
                conn_array[i].cell_num, conn_array[i].mac,
                conn_array[i].essid, conn_array[i].mode,
                conn_array[i].channel, conn_array[i].en_key,
                conn_array[i].quality, conn_array[i].freq,
                conn_array[i].signal_l);

    }
}

