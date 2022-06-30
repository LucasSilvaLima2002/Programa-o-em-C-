struct cidadao{
    char CPF[10],RG[10],CNH[10];
    int servico,status;
};
struct no{
    struct cidadao dado;
    struct no* prox;
};
typedef struct no* TipoFila;
typedef struct cidadao TipoCidadao;
void init(TipoFila *ini, TipoFila *fim){
    *ini  = NULL;
    *fim = NULL;
}
int isEmpty(TipoFila ini,TipoFila fim) {
    if ((ini == NULL) && (fim == NULL))
        return(1);
    else        return(0);
}
void enqueue( TipoFila *ini, TipoFila fim, struct cidadao v)
{
TipoFila novo;
novo=(TipoFila ) malloc (sizeof(struct no));
if (novo==NULL)
     cout << "Fila Cheia \n";
else  {
     novo->dado=v;
     novo->prox=NULL;
     if (isEmpty(ini, *fim)){
         ini = novo;
         }
     else{
         (fim)->prox= novo;
         }
        *fim=novo;
    }
}
int dequeue (TipoFila *ini, TipoFila *fim, struct cidadao *v){
    TipoFila aux = ini;
    if (isEmpty(ini, *fim))
              return 0;
    else{
        *v = aux->dado;
        ini = aux->prox;
        if (ini == NULL)
            *fim = NULL;
        free(aux);
        return 1;
    }
}
