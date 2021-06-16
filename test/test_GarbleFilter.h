#ifndef TEST_GARBLEFILTER_H
#define TEST_GARBLEFILTER_H

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




#endif