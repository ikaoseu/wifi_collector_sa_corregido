#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/collect.h"
#include "../incl/main.h"

//printf("%s", buffer);

extern char file_name[];
int counter = 0;

int cell_num;
//this function is for choosing the cell we want to collect, 
// it only works if a number within 1-21 is entered, if not
// it will ask you to enter a valid number (1-21)

int choose_cell()
{

    printf("What cell do you want to collect? (1 - 21):");
    scanf("%d", &cell_num);
    if(cell_num >= 1 && cell_num <= 21)
    {
        return cell_num;
    } 
    else 
    {
        while(cell_num <= 0 || cell_num >= 22)
        {
            printf("Please enter a valid number for the cell. (1-21)");
            scanf("%d", &cell_num);
        }
        return cell_num;
    }
    return 0; //error
}

// it collects the cell

void cell_collect(char file_name[])
{
    char y_n;
    int pick = choose_cell();
    char final_cell[MAX_STRING_SIZE];

    //string to char
    sprintf(final_cell, "%i", pick );  

    

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
        cell_collect(file_name);
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
        for(int i=0; i<9; i++){
            if(fgets(buffer, LINE_SIZE, cell_file)){
                
                stacker(buffer);
                counter++;
            }
        }

    }

/*
  //  int cell_num;
    char mac[LINE_SIZE];
    char essid[LINE_SIZE];
    char mode[LINE_SIZE];
    int channel;
    char en_key[LINE_SIZE];
    int quality;
    char freq[LINE_SIZE];
    char signal_l[LINE_SIZE];

    if(cell_file == NULL)
    {
        printf("Error opening file: %s\n", file_name); //error message w filename
    } 
    else 
    {
        while(fscanf(cell_file, "%i %s %s %s %i %s %i %s %s", &cell_num, mac, essid, mode, &channel, en_key, &quality, freq, signal_l) != EOF)
        {
            //insert the data in the struct
            put_connection_to_struct(cell_num, mac, essid, mode, channel, 
            en_key, quality, freq, signal_l);
        }
        
        fclose(cell_file);
    }
    */
}

void stacker (char buffer[]){

       switch(counter) {

            case 0  :
                strcpy(conn_array[0].cell_num, buffer);
            break; /* optional */
	
            case 1  :
                strcpy(conn_array[0].mac, buffer);
            break; /* optional */

            case 2  :
                strcpy(conn_array[0].essid, buffer);
            break; /* optional */

            case 3  :
                strcpy(conn_array[0].mode, buffer);
            break; /* optional */

            case 4  :
                strcpy(conn_array[0].channel, buffer);
            break; /* optional */

            case 5  :
                strcpy(conn_array[0].en_key, buffer);
            break; /* optional */

            case 6  :
                strcpy(conn_array[0].quality, buffer);
            break; /* optional */

            case 7  :
                strcpy(conn_array[0].freq, buffer);
            break; /* optional */

            case 8  :
                strcpy(conn_array[0].signal_l, buffer);
            break; /* optional */

       }
}








// This function puts the data obtained from file info_cell_NN into the struct
/*
void put_connection_to_struct(int cell_num, char mac[MAX_STRING_SIZE], char essid[MAX_STRING_SIZE],
                        char mode[MAX_STRING_SIZE], int channel, char en_key[MAX_STRING_SIZE],
                        char quality, char freq[MAX_STRING_SIZE], char signal_l[MAX_STRING_SIZE])
{
    int index = 1;

    if(index < ARRAY_SIZE)
    {
        conn_array[index].cell_num = cell_num;
        strcpy(conn_array[index].mac, mac);
        strcpy(conn_array[index].essid, essid);
        strcpy(conn_array[index].mode, mode);
        conn_array[index].channel = channel;
        strcpy(conn_array[index].en_key, en_key);
        conn_array[index].quality = quality;
        strcpy(conn_array[index].freq, freq);
        strcpy(conn_array[index].signal_l, signal_l);

        printf("Network read from %s (added to position %i of the array)\n", file_name, index);
        printf("\n%i %s %s %s %i %s %i %s %s\n", conn_array[index].cell_num, conn_array[index].mac, conn_array[index].essid, 
                conn_array[index].mode, conn_array[index].channel, conn_array[index].en_key,
                conn_array[index].quality, conn_array[index].freq, conn_array[index].signal_l);

        index++;
    } 
    else 
    {
        printf("Error: the array is full and it can not store further conn_array, to reset the storage please restart the program");
    }
}
*/
