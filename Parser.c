#include "Parser.h"

typedef struct
{
    int lookahead;
    struct Pilha* pilha;
}Parser;

int InicializarParser(Parser *p , int inicio )
{
    adicionarPilha2(&p->pilha , 36);
    adicionarPilha2(&p->pilha , inicio);
    ///p->lookahead = yylex();
}

int verificacaoParser(Parser *p)
{
    int topo = topoPilha(p->pilha);
    int aux  = p->lookahead;
    if(topo >= 400 && topo < 406 )
    {
        switch(topo)
        {
        case PROGR:
            if(aux>= 260 && aux<=265)
            {
                removerPilha(p->pilha);
                adicionarPilha2(p->pilha , REC);;
                adicionarPilha2(p->pilha , EOL);
                adicionarPilha2(p->pilha , CMD);
            }
            else
                return -1;
            break;
        case REC:
            if(aux >= 260 && aux<=265 )
            {
                removerPilha(p->pilha);
                adicionarPilha2(p->pilha , PROGR);
            }
            else if(aux == END || aux == 36 )
            {
                removerPilha(p->pilha);
            }
            else
                return -1;
            break;
        case CMD:
            switch(aux)
            {
            case IF:
                removerPilha(p->pilha);
                adicionarPilha2(p->pilha , CMD);
                adicionarPilha2(p->pilha , THEN);
                adicionarPilha2(p->pilha , EXPR);
                adicionarPilha2(p->pilha , IF);
                break;
            case WHILE:
                removerPilha(p->pilha);
                adicionarPilha2(p->pilha,CMD);
                adicionarPilha2(p->pilha,EXPR);
                adicionarPilha2(p->pilha , WHILE);
                break;
            case BEGIN:
                removerPilha(p->pilha);
                adicionarPilha2(p->pilha,END);
                adicionarPilha2(p->pilha,PROGR);
                adicionarPilha2(p->pilha,BEGIN);
                break;
            case WRITE || READ || VAR:
                removerPilha(p->pilha);
                adicionarPilha2(p->pilha,SCMD);
                break;
            default:
                return -1;
            }
        case SCMD:
            switch(aux)
            {
            case WRITE:
                removerPilha(p->pilha);
                adicionarPilha2(p->pilha,VAR);
                adicionarPilha2(p->pilha,WRITE);
                break;
            case READ:
                removerPilha(p->pilha);
                adicionarPilha2(p->pilha,VAR);
                adicionarPilha2(p->pilha,READ);
                break;
            case VAR:
                removerPilha(p->pilha);
                adicionarPilha2(p->pilha,EXPR);
                adicionarPilha2(p->pilha,EQ);
                adicionarPilha2(p->pilha,VAR);
                break;
            default:
                return -1;
            }
        case EXPR:
            if(aux == NUM )
            {
                removerPilha(p->pilha);
                adicionarPilha2(p->pilha,REC2);
                adicionarPilha2(p->pilha,NUM);
                break;
            }
            else
                return -1;
        case REC2:
            switch(aux)
            {
            case PLUS:
                removerPilha(p->pilha);
                adicionarPilha2(p->pilha,EXPR);
                adicionarPilha2(p->pilha,PLUS);
                break;
            case MINUS:
                removerPilha(p->pilha);
                adicionarPilha2(p->pilha,EXPR);
                adicionarPilha2(p->pilha,MINUS);
                break;
            default:
                return -1;
            }
        }
        ///CONTINUA AKI

    }
}

int executarParser(Parser *p , int inicio )
{
    InicializarParser(&p , inicio);

}

