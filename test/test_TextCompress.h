#ifndef TEST_TEXTCOMPRESS_H
#define TEST_TEXTCOMPRESS_H
#include "acutest.h"
#include "TextCompress.h"
#include "utils.h"
#include <string.h>

void text_hash(void){
    que pinT;
    que pinH;

    char text[2000]="okayokayokay";
    TextCompressMark(text, strlen(text), &pinT, &pinH);


    kill_que(&pinT);
    kill_que(&pinH);
}


#endif