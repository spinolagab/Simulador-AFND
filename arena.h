#ifndef ARENA_H
#define ARENA_H

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "node.h"

typedef struct{
    size_t capacity;
    size_t size;
    Node *data;
}Arena;

Arena arenaCreate (size_t capacity);
void *arenaAlloc (Arena *arena, size_t size);
void arenaFree (Arena *arena);
#endif