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
    {NULL, NULL} // Terminate the test
};