#include "htable.h"

hash_t *new_hash_table(int size) {
    hash_t *table = malloc(sizeof(hash_t));
    table->nslots = size;
    table->slots = malloc(size*sizeof(slot_t));
    table->seed = SEED;
    for(int i=0; i < table->nslots; i++) {
        table->slots[i].keys = NULL;
        table->slots[i].vals = NULL;
    }
    return table;
}

bool slot_has(slot_t *slot, char *s) {
    bool in = 0;
    
    return in;
}

bool hash_table_has(hash_t *table, char *s) {
    bool in = 0;
    in = slot_has(&table->slots[xorhash(s, table->seed, table->nslots)], s);
    return in;
}


void insert_to_slot(slot_t *slot, char *s, int val) {
    if(slot->keys == NULL) {
        slot->cap = INITAL_SIZE;
        slot->keys = malloc(INITAL_SIZE*sizeof(char *));
        slot->vals = malloc(INITAL_SIZE*sizeof(int));
    }else {
        if(slot->cap <= slot->written) {
            slot->cap *= 2;
            slot->keys = realloc(slot->keys, slot->cap*sizeof(char *));
            slot->vals = realloc(slot->vals, slot->cap*sizeof(int));
        }

        slot->keys[slot->written] = strdup(s);
        slot->vals[slot->written] = val;
        slot->written++;
    }
}

void hash_table_put(hash_t *table, char *key, int val) {
    int seed = 75823;
    int slotn = xorhash(key, seed, table->nslots);
    insert_to_slot(&table->slots[slotn], key, val);
}

void free_slots(hash_t *table) {
    for(int i=0; i < table->nslots; i++) {
        if(table->slots[i].keys) {
            for(int j=0; j < table->slots[i].written; j++) {
                free(table->slots[i].keys[j]);
            } 
            free(table->slots[i].vals);
        }
    }
}


void free_hash_table(hash_t *table) {
    free_slots(table);
    free(table);
}