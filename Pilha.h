#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct
{
    int vetor[150];
    int tamanho;

}Pilha;


void adicionarPilha2(Pilha* , int );
int removerPilha(Pilha*);
int topoPilha(Pilha*);

#endif // PILHA_H_INCLUDED
