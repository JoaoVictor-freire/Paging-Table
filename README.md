# Paging-Table
Trabalho 2 de Sistemas Operacionais - FIFO | OTM | LRU
Professor: Fernando Menezes Matos
Alunos: João Victor Freir e Matheus de Mendonça

Este projeto simula três algoritmos de substituição de páginas (FIFO, Ótimo e LRU) para comparar sua eficiência na gestão de falhas de página em sistemas operacionais.

## Algoritmos Implementados
- FIFO (First-In-First-Out): Substitui a página mais antiga na memória.
- Ótimo (OTM): Substitui a página que não será usada por mais tempo no futuro.
- LRU (Least Recently Used): Substitui a página usada há mais tempo.

## Execução
Compilação:
Windows: g++ -o escalonador .\escalonador.cpp

Mac/Linux: g++ -std=c++11 escalonador.cpp -o escalonador

## Saída
A saída do código mostra o número de falhas de página para cada algoritmo (FIFO, Ótimo e LRU), indicando quantas vezes uma nova página precisou ser carregada na memória:

- FIFO: Substitui a página mais antiga. Neste caso, teve 9 falhas de página, o que reflete um desempenho mediano.
- Ótimo: Substitui a página que será usada mais tarde, resultando em 8 falhas, sendo o mais eficiente, já que "prevê" as referências futuras.
- LRU: Substitui a página que foi usada há mais tempo. Também teve 8 falhas, mostrando um desempenho igual ao Ótimo nesta execução.
  
Menos falhas indicam maior eficiência do algoritmo em gerenciar a memória.
