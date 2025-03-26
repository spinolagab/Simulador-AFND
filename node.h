#ifndef __Node_H__
#define __Node_H__

typedef struct Dictionary{
  char letter;
  char reference[3];
} Dictionary;


typedef struct Node{
  // Os Nodes podem ir até "q19"
  char name[3];
  Dictionary *connections[10];
}Node;

// Getters
char* getName(Node *state);

char getLetter(Dictionary *dict);

char *getReference(Dictionary *dict);


// Setters
void setName(Node *state, char *name);

void setConnections (Node *state, Dictionary **connections, int size);



#endif
