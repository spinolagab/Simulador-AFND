#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filereading.h"

// Recebe o nome do arquivo e um autômato para armazenar o conteúdo lido.
// Retorna 1 caso em falha e 0 no sucess.
int readFile (const char* fileName, Automaton* automaton)
{
    FILE* file = fopen(fileName, "r"); 
    if (!file){
        perror ("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Ler alfabeto
    fgets (automaton->alphabet, sizeof(automaton->alphabet), file);
    automaton->alphabet[ strcspn(automaton->alphabet, "\n") ] = 0;

    // Ler número de estados
    fscanf (file, "%d", &automaton->numStates);

    // Ler número de estados finais
    fscanf (file, "%d", &automaton->numFinalStates);

    // Ler os estados finais
    for (size_t i = 0 ; i < automaton->numFinalStates; ++i)
        fscanf (file, "%d", &automaton->finalStates[i]);
    

    // Ler o número de transições
    fscanf (file, "%d", &automaton->numTransitions);

    // Ler as transições
    for (size_t i = 0; i < automaton->numTransitions; ++i){
    fscanf(file, "%d %c %d", 
        &automaton->transitions[i][0], 
        &automaton->transitionSymbols[i],
        &automaton->transitions[i][1]);
    }

    // Ler o número de palavras
    fscanf (file, "%d", &automaton->numWords);
   
    // Ler palavras
    for (size_t i = 0; i < automaton->numWords; ++i)
        fscanf(file, "%s", &automaton->words[i][0]);
    

    fclose(file);
    return 0;
}
