#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"


int main(int argc, char *argv[]) {
    hash_t *table = new_hash_table(1000);

    free_hash_table(table);
    return 0;
}