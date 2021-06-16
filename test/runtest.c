#include <stdio.h>

#include "acutest.h"

#include "test_utils.h"
#include "test_GarbleFilter.h"

// Run TESTs 
TEST_LIST = {
    {"Utility", test_utils},
    {"Ascii convertion", test_ascii},
    {NULL, NULL} // Terminate the test
};