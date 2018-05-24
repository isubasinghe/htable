#ifndef HTABLE_H
#define HTABLE_H

#define SEED 73802
#ifndef INITAL_SIZE
#define INITAL_SIZE 2
#endif // INITIAL_SIZE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "hash.h"

typedef struct {
    char **keys;
    int *vals;
    int cap;
    int written;
} slot_t;

typedef struct {
    slot_t *slots;
    int nslots;
    int seed;
} htable_t;



htable_t *new_hash_table(int);

void insert_to_slot(slot_t *, char *, int );

bool slot_has(slot_t *, char *);

int slot_get(slot_t *, char *);

int hash_table_gets(htable_t *, char *, int *);

void hash_table_put(htable_t *, char *, int);

bool hash_table_has(htable_t *, char *);

void free_slot(slot_t *);

void free_slots(htable_t *);

void free_hash_table(htable_t *);

#endif // HTABLE_H