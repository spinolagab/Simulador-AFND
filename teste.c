#include <stdio.h>
#include <stdlib.h>
#include "node.c"
#include <string.h>

int main(int argc, char const *argv[])
{
  Node *state = (Node *)malloc(sizeof(Node));
  Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
  
  printf("Estado e dicionario criados\n");

  dict->letter = 'a';
  strcpy(dict->reference, "tst");  

  printf("Dados do dicionario\nletter: %c\nreference: %s\n", dict->letter, dict->reference);

  printf("Nomeando o node\n");
  strcpy(state->name, "q10");

  printf("Atribuindo dicionario ao node %s\n", getName(state));
  Dictionary *dictList[1];
  dictList[0] = dict;
  setConnections(state, dictList, 1);

  printf("Atribuicoes efetuadas\nreference: %s\nletter: %c\n", state->connections[0]->reference, state->connections[0]->letter);

  return 0;
}
