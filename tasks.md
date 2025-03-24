# Tarefas
## Estrutura do código
### Estruturas de dados:
Implementar as seguintes estruturas:
    - Estrutura do estado, com identificador do estado e lista de transições.
    - Estrutura da transição, com estado de origem, símbolo do alfabeto e estado de destino.
    - Estrutura do autômato, com alfabeto, estados, estados finais e transições.
### Leitura do Arquivo
Função de leitura de arquivo deverá:
    - Ler o alfabeto.
    - Ler o número de estados.
    - Ler quais são os estados finais.
    - Ler o número de transições.
    - Ler quais são as transições.
    - Ler o número de palavras que serão avaliadas.
    - Ler as palavras a serem avaliadas
### Simulação do AFND
A função que simulará o AFND deve:
    - Começar do estado inicial.
    - Para cada símbolo da palavra, verificar todas as transições possíveis a partir dos estados atuais.
    - Manter uma lista de estados ativos (estados que podem ser alcançados) e atualizar conforme as transições.
    - No final da palavra, verificar se algum estado ativo é um estado final.

