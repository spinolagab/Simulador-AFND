#include "arena.h"
// Recebe a quantiade total de nós a serem alocados (capacity).
// Retorna um ponteiro com a posição inicial da região de memória.
Arena arenaCreate(size_t capacity)
{
    void *data = malloc (sizeof(Node) * capacity);
    Arena arena = {
        .capacity = capacity,
        .size = 0,
        .data = data
    };
    return arena;
}

// Recebe uma região de memória (arena) e o tamanho do que vai ser alocado (size)
// Rtetorna um ponteiro para a nova parte da região (data).
void *arenaAlloc (Arena *arena, size_t size)
{
    assert((arena->size + size) <= (arena->capacity));
    Node *data = &arena->data[arena->size];
    arena->size += size;
    return data;
}

void arenaFree (Arena *arena)
{
    arena->capacity = 0;
    arena->size = 0;
    free(arena->data);
}