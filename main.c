#include "filereading.c"

int isFinalState(Automaton* automaton, int state)
{
  for (int i = 0; i < automaton->numFinalStates; i++) 
    if (automaton->finalStates[i] == state) 
      return 1;
  
  return 0;
}

int simulateAFND (Automaton *automaton, int currentState, char *word, int index)
{
  if (index == strlen(word)) 
    return isFinalState(automaton, currentState);

  char currentSymbol = word[index];
  int accepted = 0;

  for (int i = 0; i < automaton->numTransitions; i++) {
    int automatonId = automaton->transitions[i][0];
    char automatonSymbol = automaton->transitionSymbols[i];

    if (automatonId == currentState && automatonSymbol == currentSymbol){

      int nextState = automaton->transitions[i][1];

      if (simulateAFND (automaton, nextState, word, index +1))
        accepted = 1;
      
    }
  }

  return accepted;
}

void testWords (Automaton* automaton) 
{
  for (int i = 0; i < automaton->numWords; i++) {
    int result = simulateAFND(automaton, 0, automaton->words[i], 0);
    printf("%d: %s %s\n", i+1, automaton->words[i], result ? "OK" : "not OK");
  }
}

int main(int argc, char* argv[])
{
  if (argc < 2){
     printf("Argumentos insuficientes! Uso: ./<executavel> <arquivo de entrada>\n");
     return 1;
  }

  Automaton automato;
  if (readFile(argv[1], &automato) != 0)
     return 1;  
   
  testWords (&automato);
  return EXIT_SUCCESS;
}
