#ifndef FILEREADING_H
#define FILEREADING_H

#define MAX_ALPHABET_SIZE (10)
#define MAX_STATES (20)
#define MAX_WORD (100)
#define MAX_TRANSITIONS (MAX_ALPHABET_SIZE * MAX_STATES)

typedef struct {
    char alphabet[MAX_ALPHABET_SIZE];
    int numStates;
    int numFinalStates;
    int finalStates[MAX_STATES];
    int numTransitions;
    int transitions[MAX_TRANSITIONS][2];
    char transitionSymbols[MAX_TRANSITIONS];
    int numWords;
    char words[MAX_ALPHABET_SIZE][MAX_WORD];
} Automaton;

int readFile(const char* fileName, Automaton* automaton);

#endif // !__FILE_READING_H__
