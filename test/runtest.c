#include <stdio.h>

#include "acutest.h"

#include "test_utils.h"
#include "test_GarbleFilter.h"

// Run TESTs 
TEST_LIST = {
    {"Utility", test_utils},
    {"Ascii convertion", test_ascii},
    {"Get occurrence", text_occurrence},
    {"Find garble text", find_garble_text},
    {"Find smallest leftest garble region",find_leftsmall_garble_text},
    {"Find smallest leftest garble region 2",find_leftsmall_garble_text2},
    {"Slice text", test_slice_text},
    {"Garble text filter", text_garblefilter},
    {NULL, NULL} // Terminate the test
};