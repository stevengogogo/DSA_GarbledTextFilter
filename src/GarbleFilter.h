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

/** Move to the next garble text region [tail, head]
 * @param tail start tail (should set `-1` for starting)
 * @param head start head (should set `-1` for starting)
 * @param textlen length of the text (including '\0')
 * @return 0 no gable text retion left; 1: found garble text
*/
bool next_garble_region(char* text, int* tail, int* head, int textlen, occurText*);

bool leftist_smallest_garble_region(char* text, int textlen, char* garble, int garblelen, int* tail, int* head);

static int interface(){

}


#endif