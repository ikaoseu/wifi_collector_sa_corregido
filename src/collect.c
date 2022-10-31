#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/collect.h"
#include "../incl/main.h"

//printf("%s", buffer);

//extern char file_name[];
int counter = 0;
int counter2 = 0;
// it collects the cell

void cell_collect()
{
    char y_n;
    int pick = choose_cell();
    char final_cell[MAX_STRING_SIZE];

    //int to string
    sprintf(final_cell, "%i", pick);  
    char file_name[20] = {"../files/info_cell_"};
    

    //Concatenating strings together to form the filename
    //file_name declared in .h
    strcat(file_name, final_cell);
    strcat(file_name, ".txt");
    

    read_cell(file_name);

    printf("Do you want to add another access point? [y/N]: ");
    scanf("%s", &y_n);

    switch (y_n)
    {
    case 'y':
    case 'Y':
        //free(file_name[20]);  tengo q revisar esta forma que es mas clean.
        //strcat(file_name, "../files/info_cell_");
        cell_collect();
    case 'n':
    case 'N':
        system("clear");
        break;
    
    default:
        printf("\n ERROR, input is not valid, try it again!\n");
        system("clear");
        break;
    }
}

// this function reads the information in the file
// and returns the data in a struct

void read_cell(char file_name[MAX_STRING_SIZE])
{

    //int index = 0;
    char buffer[LINE_SIZE];
    FILE * cell_file = fopen(file_name, "r");

    if(!cell_file){
        printf("No se ha podido leer el archivo");
    }else{

        while(fgets(buffer, LINE_SIZE, cell_file)){
            stacker(buffer);
            if(counter == 8){
                counter = 0;
                counter2++;
                printf("--------------------------------------------");
            }else{
                counter++;
            }
        }
        /* this shit good, but it could be better.
        while(getchar() != EOF){
            for(int i=0; i<9; i++){
                if(fgets(buffer, LINE_SIZE, cell_file)){
                
                    stacker(buffer);
                    counter++;
                }
            }
            counter = 0;
            counter2++;
            printf("--------------------------------------------");
            
        }
        */
    }
    fclose(cell_file);
}

void stacker (char buffer[]){

       switch(counter) {

            case 0  :
                strcpy(conn_array[counter2].cell_num, buffer);
                printf("%s", conn_array[counter2].cell_num);
            break; /* optional */
	
            case 1  :
                strcpy(conn_array[counter2].mac, buffer);
                printf("%s", conn_array[counter2].mac);
            break; /* optional */

            case 2  :
                strcpy(conn_array[counter2].essid, buffer);
                printf("%s", conn_array[counter2].essid);
            break; /* optional */

            case 3  :
                strcpy(conn_array[counter2].mode, buffer);
                printf("%s", conn_array[counter2].mode);
            break; /* optional */

            case 4  :
                strcpy(conn_array[counter2].channel, buffer);
                printf("%s", conn_array[counter2].channel);
            break; /* optional */

            case 5  :
                strcpy(conn_array[counter2].en_key, buffer);
                printf("%s", conn_array[counter2].en_key);
            break; /* optional */

            case 6  :
                strcpy(conn_array[counter2].quality, buffer);
                printf("%s", conn_array[counter2].quality);
            break; /* optional */

            case 7  :
                strcpy(conn_array[counter2].freq, buffer);
                printf("%s", conn_array[counter2].freq);
            break; /* optional */

            case 8  :
                strcpy(conn_array[counter2].signal_l, buffer);
                printf("%s", conn_array[counter2].signal_l);
            break; /* optional */

       }
}