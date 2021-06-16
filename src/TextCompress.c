#include "TextCompress.h"


void TextCompressMark(char* text, int textlen, que* pinT, que* pinH){
    assert(text[textlen]=='\0');
    int head = textlen-1; //text[textlen] == '\0'
    int tail = 0;
    int hashh, hasht;
    int lenh, lent;
    int Hh, Ht;

    *pinT = init_que(INIT_PIN_SIZE);
    *pinH = init_que(INIT_PIN_SIZE);

    clear_hash(&hashh, &lenh, &Hh);
    clear_hash(&hasht, &lent, &Ht);

    while(head>tail){
        update_hash(text[head], &hashh, &lenh, &Hh, false);
        update_hash(text[tail], &hasht, &lent, &Ht, true);

        if (hashh == hasht){
            enque(pinT, tail);//'|' on the right
            enque(pinH, head);//'|' on the left
            clear_hash(&hashh, &lenh, &Hh);
            clear_hash(&hasht, &lent, &Ht);
        }
        --head;
        ++tail;
    }

}

void update_hash(char c, int* cur_hash, int* cur_len, int* H, bool rev){
    int asc = str2ascii(c);
    ++(*cur_len);
    int new_hash = ((*H)*asc) % Q_;
    if (rev)
        *cur_hash = *cur_hash + new_hash;
    else{
        *cur_hash = (*cur_hash * D_) % Q_;
        *cur_hash = (*cur_hash + asc) % Q_;
    }
    *H = ((*H)*D_) % Q_;//new hash num
}

void clear_hash(int* cur_hash, int* cur_len, int* H){
    *cur_hash = 0;
    *cur_len = 0;
    *H = 1;
}

void PrintCompressedText(char* text, int textlen, que* pinT, que* pinH){
    int last = peek_que(pinT);
    for(int i=0;i<textlen;i++){
        
        if(i == peek_que(pinH) && last+1 != peek_que(pinH)){
            printf("|");
            deque(pinH);
        }

        printf("%c", text[i]);

        if(i==peek_que(pinT)){
            last = peek_que(pinT);
            printf("|");
            deque(pinT);
        }


    }
}