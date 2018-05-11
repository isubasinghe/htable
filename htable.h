#ifndef HTABLE_H
#define HTABLE_H

#define SEED 73802
#define INITAL_SIZE 128

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
} hash_t;

void printf_table(hash_t *);

hash_t *new_hash_table(int);

// TODO: implement a move to front
void move_to_front(slot_t *);

void insert_to_slot(slot_t *, char *, int );

bool slot_has(slot_t *, char *);

int slot_get(slot_t *, char *);

void hash_table_put(hash_t *, char *, int);

bool hash_table_has(hash_t *, char *);

void free_slot(slot_t *);

void free_slots(hash_t *);

void free_hash_table(hash_t *);

#endif // HTABLE_H