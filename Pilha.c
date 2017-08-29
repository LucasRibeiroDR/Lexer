
#include "Pilha.h"

void adicionarPilha2(Pilha *p , int valor)
{

    p->vetor[p->tamanho] = valor;
    p->tamanho++;

}

int removerPilha(Pilha *p)
{
    if(p->tamanho == 0) return -1; ///caso a pilha esteja vazia e foi utilizado a funcao removerpilha.
    int valor = p->vetor[p->tamanho - 1];
    p->vetor[p->tamanho] = 0;
    p->tamanho--;
    return valor;
}

int topoPilha(Pilha *p)
{
    return p->vetor[p->tamanho - 1];
}
