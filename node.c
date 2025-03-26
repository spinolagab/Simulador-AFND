#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

// Getters
char* getName(Node *state){
  return state->name;
}

char getLetter(Dictionary *dict){
  return dict->letter;
}

char *getReference(Dictionary *dict){
  return dict->reference;
}

// Setters
void setName(Node *state, char *name){
  strcpy(state->name, name);
}

void setConnections(Node *state, Dictionary **connections, int size){

  for (int i = 0; i < size; i++){
    state->connections[i] = connections[i];
  }

}


