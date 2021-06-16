#ifndef GARBLEFILTER_H
#define GARBLEFILTER_H
#define N_ASCII_ELEMENT 128


typedef struct {
    int occur[N_ASCII_ELEMENT];
    int obs[N_ASCII_ELEMENT];
    int nexceed;
} occurText;

occurText init_occurText();

//Preprocessing: Garble Text
int str2ascii(char);
void get_occurrence(char*, occurText*);


static int interface(){

}


#endif