#include <iostream>
using namespace std;
#include <cstring>
#include <locale>
#define MAX 3
#define NC 40

int main(){
    setlocale(LC_ALL,"");
    int id[MAX] , pesq_id[MAX], i, opcao, aux=0,presente,x=0, val_carg[MAX], pesq;
    char cnpj[MAX][NC], porto_dest[MAX][NC], pesq_cnpj[MAX][NC];

    do{
        cout << "\nDigite o n�mero de uma op��o a seguir para prosseguir"
        << "\n0.Encerrar programa\n"
        << "1.Cadastro dos conteiners\n"
        << "2.Consultar as informa��es dos conteiners atrav�s do ID ou do CNPJ\n"
        << "3.Gerar lista dos conteiners\n"
        << "4.Retirar conteiner\n"
        << "5.Gerar vetor com os IDs dos conteiners j� embarcados\n";
        cin >> opcao;
         cout << "Sua escolha foi a op��o de n�mero " << opcao;
    switch (opcao){
      case 0:
          cout << "Seu programa ser� encerrado";
          break;
case 1:

        cout << "\nDigite seu c�digo de ID :";
        cin >> id[i];
        cout << "\nDigite o CNPJ da sua empresa: ";
        cin.ignore();
        cin.getline(cnpj[i], NC);
        cout << "\nDigite o porto de destino da carga: ";
        cin.getline(porto_dest[i], NC);
        cout << "\nDigite o valor estimado da carga: ";
        cin >> val_carg[i];
        cout << "\nSeu ID �: " << id[i];
        cout << "\nO CNPJ da sua empresa �: " << cnpj[i];
        cout << "\nO porto destino da carga �: " << porto_dest[i];
        cout << "\nO valor esstimado da carga � de:" << val_carg[i];
        cout <<"\n"<< i;
        i++;

          break;
      default:
        cout <<"\nOp��o inv�lida!";
        break;
        case 2:
          cout << "\nDigite 1 para ID e 2 para CNPJ: ";
          cin >> pesq;
          switch (pesq) {
            case 1:
                cout << "\nDigite seu ID: ";
                cin >> pesq_id[MAX];
                if(pesq_id[MAX]==id[i])

                    { for (i=0;i<x;i++){
                        if(pesq_id[MAX]==id[i])
                         if (presente == 1) {
                    cout << "O porto de destino da carga �: " << porto_dest;
                    cout << "\nO valor esstimado da carga � de:" << val_carg[i];
                        }
                    }
                    }

        }



          }
        }
        while (opcao!=0);
        }
