#include "TextCompress.h"


void TextCompressMark(char* text, int textlen, que* pinT, que* pinH){
    int head = textlen;
    int tail = 0;
    int hashh, hasht;
    int lenh, lent;
    int Hh, Ht;

    *pinT = init_que(INIT_PIN_SIZE);
    *pinH = init_que(INIT_PIN_SIZE);

    clear_hash(&hashh, &lenh, &Hh);
    clear_hash(&hasht, &lent, &Ht);

    while(head>tail){
        update_hash(text[head], &hashh, &lenh, &Hh);
        update_hash(text[tail], &hasht, &lent, &Ht);

        if (hashh == hasht){
            enque(pinT, tail);//'|' on the right
            enque(pinH, head);//'|' on the left
            clear_hash(&hashh, &lenh, &Hh);
            clear_hash(&hasht, &lent, &Ht);
        }
        ++head;
        --tail;
    }

}

void update_hash(char c, int* cur_hash, int* cur_len, int* H){
    int asc = str2ascii(c);
    ++(*cur_len);
    *H = ((*H)*D_) % Q_;//new hash num
    int new_hash = ((*H)*asc) % Q_;
    *cur_hash = *cur_hash + new_hash;
}

void clear_hash(int* cur_hash, int* cur_len, int* H){
    *cur_hash = 0;
    *cur_len = 0;
    *H = 1;
}