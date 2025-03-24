#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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
int main(int argc, char* argv){
   char buffer[1024];
   scanf("%s", &buffer);
   // TODO: Trocar o \n por \0
   uint32_t alphabetSize = strlen(buffer);
   char *alphabet = malloc( (*alphabet) * alphabetSize)	;


}