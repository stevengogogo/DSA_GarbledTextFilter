#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "GarbleFilter.h"
#include "utils.h"
#include "TextCompress.h"

int main()
{
    que pinT;
    que pinH;

    char text[2000]="okayokayokay";
    TextCompressMark(text, strlen(text), &pinT, &pinH);


    kill_que(&pinT);
    kill_que(&pinH);

    return 0;
}