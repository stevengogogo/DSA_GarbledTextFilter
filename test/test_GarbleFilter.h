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
}




#endif