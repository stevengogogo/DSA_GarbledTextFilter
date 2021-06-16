#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "GarbleFilter.h"
#include "utils.h"

int main()
{
    char text[2000] = "DSARANDOMTEXTISSOHARD\0";
    char garble[2000] = "RTTX\0";
    int head = -1;
    int tail = -1;
    occurText oc = init_occurText();
    get_region_occurrence(garble, &oc, 0, strlen(garble)-1);

    next_garble_region(text, &tail, &head, strlen(text), &oc);

    return 0;
}