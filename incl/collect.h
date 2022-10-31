#ifndef COLLECT_H
#define COLLECT_H

void cell_collect();
int get_input_num();
void read_cell(char file_name[]);
void stacker (char buffer[]);
void put_connection_to_struct(int cell_num, char mac[], char essid[],
                              char mode[], int channel, char en_key[],
                              char quality, char freq[], char signal_l[]);

#endif 
