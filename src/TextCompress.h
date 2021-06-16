#ifndef TEXT_COMPRESS
#define TEXT_COMPRESS
#define D_ 23
#define Q_ 1000081
#define INIT_PIN_SIZE 10000
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>

void TextCompressMark(char* text, int textlen, que* pinT, que* pinH);
void update_hash(char , int* cur_hash, int* cur_len, int* H, bool rev);
void clear_hash(int* cur_hash, int* cur_len, int* H);

void PrintCompressedText(char* text, int textlen, que* pinT, que* pinH);

#endif