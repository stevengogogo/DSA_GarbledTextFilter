#include "GarbleFilter.h"


occurText init_occurText(){
    occurText oc;

    for(int i=0;i<N_ASCII_ELEMENT;i++){
        oc.occur[i]=0;
        oc.obs[i] = 0;
    }
    oc.nexceed = 0;
    return oc;
}

int str2ascii(char chr){
    return chr;
}

void get_region_occurrence(char* text,occurText* oc, int str, int end){
    int i = str;
    int asc;
    for(int i=str;i<=end;i++){
        asc = str2ascii(text[i]);
        ++(oc->occur[asc]);
    }
}
