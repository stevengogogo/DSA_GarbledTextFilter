/**
 * @file test_GarbleFilter.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TEST_GARBLEFILTER_H
#define TEST_GARBLEFILTER_H
#include <string.h>
#include "acutest.h"
#include "GarbleFilter.h"


void test_ascii(void){
    char t = 'a';
    TEST_CHECK(str2ascii(t) == 97);
    TEST_CHECK(str2ascii('z') == 122);
    TEST_CHECK(str2ascii('A') == 65);
    TEST_CHECK(str2ascii('Z') == 90);
    TEST_MSG("Got %d", str2ascii(t));
}

void text_occurrence(void){
    char t[2000] = "I have a good day\0";
    occurText oc = init_occurText();

    int len = strlen(t);
    TEST_CHECK(len==17);
    TEST_CHECK(t[len-1] == 'y');
    TEST_CHECK(t[0] == 'I');

    //Get occurrence
    get_region_occurrence(t, &oc, 0, len-1);
    TEST_CHECK(oc.occur[str2ascii('h')] == 1);
    TEST_CHECK(oc.occur[str2ascii('o')] == 2);
    TEST_CHECK(oc.occur[str2ascii('a')] == 3);
    TEST_CHECK(oc.occur[str2ascii('y')] == 1);
    TEST_CHECK(oc.nexceed == 0);
    TEST_CHECK(oc.noccur == 10);

    //Add obs
    add_obs('h', &oc);
    TEST_CHECK(oc.obs[str2ascii('h')] == 1);
    TEST_CHECK(oc.nexceed == 1);
    del_obs('h', &oc);
    TEST_CHECK(oc.obs[str2ascii('h')] == 0);
    TEST_CHECK(oc.nexceed == 0);

    TEST_CHECK(oc.obs[str2ascii('z')] == 0);
    TEST_CHECK(oc.nexceed == 0);
}

void find_garble_text(void){
    char text[2000] = "DSARANDOMTEXTISSOHARD\0";
    char garble[2000] = "RTTX\0";
    int head = 0;
    int tail = 0;
    occurText oc = init_occurText();
    get_region_occurrence(garble, &oc, 0, strlen(garble)-1);


    bool sat = next_garble_region(text, &tail, &head, strlen(text), &oc);

    //TEST
    //PIN
    TEST_CHECK(head == 12);
    TEST_CHECK(tail==3);
    //Observation
    TEST_CHECK(oc.obs[str2ascii('R')]==1);
    TEST_CHECK(oc.obs[str2ascii('T')]==2);
    TEST_CHECK(oc.obs[str2ascii('X')]==1);
    //Valid
    TEST_CHECK(oc.nexceed == oc.noccur);
    TEST_CHECK(sat == true);
    //Occurrence
    TEST_CHECK(oc.occur[str2ascii('R')] == 1);   
    TEST_CHECK(oc.occur[str2ascii('T')] == 2);   
    TEST_CHECK(oc.occur[str2ascii('X')] == 1);   
    TEST_CHECK(oc.occur[str2ascii('z')] == 0);
    TEST_CHECK(oc.noccur == 3);

}




#endif