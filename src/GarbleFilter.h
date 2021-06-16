#ifndef GARBLEFILTER_H
#define GARBLEFILTER_H
#define N_ASCII_ELEMENT 128

#include <string.h>

typedef struct {
    int occur[N_ASCII_ELEMENT];
    int obs[N_ASCII_ELEMENT];
    int nexceed;
} occurText;

occurText init_occurText();

//Preprocessing: Garble Text
int str2ascii(char);
void get_region_occurrence(char*, occurText*, int str, int end);


static int interface(){

}


#endif