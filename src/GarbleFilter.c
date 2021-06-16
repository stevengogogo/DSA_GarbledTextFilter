#include "GarbleFilter.h"


occurText init_occurText(){
    occurText oc;

    for(int i=0;i<N_ASCII_ELEMENT;i++){
        oc.occur[i]=0;
        oc.obs[i] = 0;
    }
    oc.nexceed = 0;
    oc.noccur = 0;
    return oc;
}

void add_obs(char c, occurText* oc){
    int asc = str2ascii(c);
    ++oc->obs[asc];
    if(oc->obs[asc] >= oc->occur[asc] && oc->occur[asc] !=0){
        ++oc->nexceed;
    }
}

void del_obs(char c, occurText* oc){
    int asc = str2ascii(c);
    --oc->obs[asc];
    assert(oc->obs[asc]>=0);
    if(oc->obs[asc] < oc->occur[asc] && oc->occur[asc] !=0){
        --oc->nexceed;
    }
}

bool satisfied_obs(occurText oc){
    if(oc.nexceed>=oc.noccur){
        return true;
    }
    else{
        return false;
    }
}

int str2ascii(char chr){
    return chr;
}

void get_region_occurrence(char* text,occurText* oc, int str, int end){
    int i = str;
    int asc;
    for(int i=str;i<=end;i++){
        asc = str2ascii(text[i]);
        if(oc->occur[asc]==0){++oc->noccur;}
        ++(oc->occur[asc]);
    }
}

bool next_garble_region(char* text, int* tail, int* head, int textlen, occurText* oc){
    //Move one step forward
    if(*tail==textlen-1)
        return 0;
    else{
        del_obs(text[*tail], oc);
        ++(*tail);
    }

    //move head
    while(*head < textlen && oc->nexceed){
        
    }
}