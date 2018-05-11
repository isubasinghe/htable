#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"


int main(int argc, char *argv[]) {
    hash_t *table = new_hash_table(100);
    
    char word[1024];

    while(scanf("%s", word) != EOF) {
        hash_table_put(table, word, 1);
    }
    printf("\n\n\n\n\n");

    printf_table(table);
    free_hash_table(table);
    return 0;
}