#include <iostream>
#include<locale>
#include <stdlib.h>
using namespace std;

struct livro{
    char titulo[50], autor[30];
    float preco;
};

typedef struct livro TipoLivro;

int main() {
    setlocale(LC_ALL,"");
    TipoLivro *pont;

    pont = (TipoLivro*) malloc(sizeof(TipoLivro));

    if (pont == NULL)
        cout << "N�o foi poss�vel alocar espa�o requisitado \n";
    else{
        cout <<"sizeof TipoLivro: " << sizeof(TipoLivro) <<endl;
        cout << "digite t�tulo: ";
        cin.getline(pont->titulo, 50);
        cout << "digite autor: ";
        cin.getline(pont->autor, 30);
        cout << "Pre�o R$";
        cin >> pont->preco;


        cout <<"Apresenta��o do livro armazenado na regi�o alocada dinamicamente\n ";
        cout <<"T�tulo do livro: " << pont->titulo << "\n Autor: "<< pont->autor << "\n  R$"<< pont->preco << endl;

        free(pont);
        }
    return 0;
}



