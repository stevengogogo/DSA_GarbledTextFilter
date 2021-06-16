#ifndef GARBLEFILTER_H
#define GARBLEFILTER_H
#define N_ASCII_ELEMENT 128

#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef struct {
    int occur[N_ASCII_ELEMENT];
    int obs[N_ASCII_ELEMENT];
    int nexceed;
    int noccur;
} occurText;

occurText init_occurText();
void add_obs(char, occurText*);
void del_obs(char, occurText*);
bool satisfied_obs(occurText);

//Preprocessing: Garble Text
int str2ascii(char);

/** Get occurrence in the region [str, end].
 * @note For garble text pattern
*/
void get_region_occurrence(char*, occurText*, int str, int end);

//Locate Garble Text
/** Move to next garble text region
 * @return 0 no gable text retion left; 1: found garble text
*/
bool next_garble_region(char* text, int* tail, int* head, int textlen, occurText*);

static int interface(){

}


#endif