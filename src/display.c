#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../incl/display.h"
#include "../incl/main.h"



// this function prints the information in the cell
 void print_cell(){
      char y_n;
      printer();   

      printf("Do you want to print the information of another cell? [y/N]:");
        scanf("%s", &y_n);
        
        switch (y_n)
        {
            case 'y':
            case 'Y':
                print_cell();

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
    



    void printer(){

        char input_of_String[MAX_STRING_SIZE];
        int count_v = 0;
        
        char cell_name[20] = {"Cell "};
        int value;

        int picker = choose_cell();
   
       //int to string
        sprintf(input_of_String, "%i", picker); 
        strcat(cell_name, input_of_String);

        for(int i = 0; i < LINE_SIZE; i++)
        {        
        value = checker(i, cell_name);
        if(value == strlen(cell_name))
        {
            printf("\n%s %s %s %s %s %s %s %s %s\n", conn_array[i].cell_num,
                    conn_array[i].mac, conn_array[i].essid, conn_array[i].mode, 
                    conn_array[i].channel, conn_array[i].en_key,conn_array[i].quality, 
                    conn_array[i].freq, conn_array[i].signal_l);
        }else{
            count_v++;
            if(count_v == 80)
            {
                printf("\nScan the cell first, you can do this by pressing number 2 in th main menu\n");
            break;
            }
        }
    }
    }

    int checker(int iterator, char cell_name[]){
        int counter3 = 0;
        //we check the whole name of the pos array so we can state if it matches
        for(int j=0; j<strlen(conn_array[iterator].cell_num); j++){
            if(conn_array[iterator].cell_num[j] == cell_name[j]){
                counter3++;
            }
        }
        return counter3;
        
    }

    
