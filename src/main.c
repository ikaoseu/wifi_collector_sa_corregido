#include <stdio.h>
#include <stdlib.h>

#include "../incl/main.h"
#include "../incl/quit.h"
#include "../incl/collect.h"
#include "../incl/display_all.h"
#include "../incl/display.h"



int cell_num;


int main()
{
    system("clear");

    char response;

    do
    {
        print_menu();
        scanf("%d", &menu_int);

        switch (menu_int)
        {
        case 1:
            response = getchar();
            quit(response);
            break;
        case 2: 
            cell_collect();
            break;
        case 10:
            print_cell();
            break;
        case 11:
            break;    
        default:
            printf("At this moment this functionality is not available.\n\n");
            break ;
        }
    } while (1);
    return 0;

}

void print_menu()
{
    printf("[2022] SUCEM S.L Wifi Collector\n\n");
    printf("[ 1] wificollector_quit\n");
    printf("[ 2] wificollector_collect\n");
    printf("[ 3] wificollector_show_data_one_network\n");
    printf("[ 4] wificollector_select_best\n");
    printf("[ 5] wificollector_select_worst\n");
    printf("[ 6] wificollector_delete_net\n");
    printf("[ 7] wificollector_sort\n");
    printf("[ 8] wificollector_export\n");
    printf("[ 9] wificollector_import\n");
    printf("[10] wificollector_display\n");
    printf("[11] wificollector_display_all\n");
    printf("Option: ");
}


//this function is for choosing the cell we want to collect, 
// it only works if a number within 1-21 is entered, if not
// it will ask you to enter a valid number (1-21)

int choose_cell()
{

    printf("What cell do you want to focus? (1 - 21):");
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
