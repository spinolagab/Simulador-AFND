#include "filereading.c"
#include "arena.c"

/*
 * ==Entrada==
 * 1. Alfabeto (%s) -> String, separar em caracteres. 
 * 2. Número de estados (%d)
 * 3. Quantidade de estados finais (%d)
 * 4. Estados finais, no modelo qf1 qf2 qf3 ... qfn -> Strtok e fgets para coleta dinâmica
 * 5. Número de transições do AFND (%d)
 * 6-n.Transições no formato: <estado atual> <símbolo do alfabeto> <estado de chegada>
 * 7. Número de Entradas (%d)
 * 8-m. Entrada das palavras 
 * 
 * ==Exemplo de Entrada==
 * 1. ab
 * 2. 3
 * 3. 1
 * 4. 2
 * 5. 4
 * 6-1 = 0 a 0
 * 6-2 = 0 a 1
 * 6-3 = 0 b 0
 * 6-4 = 1 b 2
 * 7. 5
 * 8-1 aab
 * 8-2 aababab
 * 8-3 ababb
 * 8-4 bbaa
 * 8-5 b
 * 
 * ==Saída Esperada==
 * aab OK
 * aababab OK
 * ababb not OK
 * bbaa not OK
 * b not OK
 *
 */
int main(int argc, char* argv[]){
   if (argc < 2){
      printf("Argumentos insuficientes! Uso: ./<executavel> <arquivo de entrada>\n");
      return 1;
   }
   Automaton automato;
   if ( readFile(argv[1], &automato) != 0){
      return 1;  
   }

   Arena arena = arenaCreate(automato.numStates);
   Node *n1 = arenaAlloc (&arena,1);
   Node *n2 = arenaAlloc (&arena,1);
   Node *n3 = arenaAlloc (&arena,1);

   printf ("Alfabeto: %s\n", automato.alphabet);
   printf ("Número de estados: %d\n", automato.numStates);
   printf ("Estados finais: ");
   for (size_t i = 0; i < automato.numFinalStates; i++)
      printf ("%d ", automato.finalStates[i]);

   printf ("\nNúmero de transições: %d\n", automato.numTransitions);
   for (size_t i = 0; i < automato.numTransitions; i++)
      printf ("Transição: %d %c %d\n", 
               automato.transitions[i][0],
               (char)automato.transitions[i][1],
               automato.transitions[i][2]
      );
   
   for (size_t i = 0; i < automato.numWords; i++){
      printf ("%s\n", automato.words[i]);
   }

   arenaFree(&arena);

}