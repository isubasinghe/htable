#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"


int main(int argc, char *argv[]) {
    int size = 100;
    if(argc != 2) {
        return -1;
    }
    size = atoi(argv[1]);
    if(size < 0) {
        return -1;
    }
    hash_t *table = new_hash_table(100);
    
    char word[1024];

    while(scanf("%s", word) != EOF) {
        hash_table_put(table, word, 1);
    }

    for(int i=0; i < table->nwritten; i++) {
        int slot = table->written_indexes[i];
        for(int j=0; j < table->slots[slot].written; j++) {
            table->slots[slot].keys[j];
        }
    }
    free_hash_table(table);
    return 0;
}