//Struct

#include <iostream>
#include <locale>
#include <cstring>
#define NC 50
#define MAX 2000


using namespace std;
 struct cliente_banco {
 char nome[NC], endereco[NC], CPF[NC];
 int conta, ano_abertura,n[NC];
 float saldo;
       };
typedef struct cliente_banco Tipo_Cliente;

int main(){
    setlocale(LC_ALL,"");
   Tipo_Cliente clientes[MAX];
 	int i, nc;
 	int cont10,n_neg;
 	char CPF_procurado[16];
 	char resp;
 	nc=0;
do{

   cout<<"Informe CPF do cliente:";
   cin.getline(clientes[nc].CPF,NC);
   cout<<"Nome do cliente:\n";
   cin.getline(clientes[nc].nome,NC);
   cout<<"Informe o endereço:";
   cin.getline(clientes[nc].endereco,NC) ;
   cout<<"Digite o numero da conta:";
   cin>> clientes[nc].conta;
   cout<<"Digite o ano de abertura:";
   cin>> clientes[nc].ano_abertura;
   cout<<"Digite o saldo atual:";
   cin>> clientes[nc].saldo;
   nc++;
   cout<<"Deseja cadastrar mais um cliente?(s/n):";
   cin>>resp;
   cin.ignore();
}
    while ((resp == 's' || resp == 'S') && nc < MAX);

   for(i=0;i<nc;i++){
   cout<<"/n/n******************************************"<<endl;
   cout<<"Informações do cliente"<<endl;
   cout<<"\t Nome:"<<clientes[i].nome<<endl;
   cout<<"\t endereço:"<<clientes[i].endereco<<endl;
   cout<<"\t CPF:"<<clientes[i].CPF<<endl;
   cout<<"\t conta:"<<clientes[i].conta<<endl;
   cout<<"\t Ano de abertura:"<<clientes[i].ano_abertura<<endl;
   cout<<"\t Saldo:"<<clientes[i].saldo<<endl;}

   cont10=0;
   for(i=0;i<nc;i++){
        if(clientes[i].ano_abertura <= 2011)
        cont10++;
   }
   cout<<"numero de clientes com conta maior que dez anos:" << cont10 << endl;

   n_neg=0;
   for(i=0;i<nc;i++){
        if(clientes[i].saldo<0){
        n_neg++;
  cout<<"Numero de contas com saldo negativo"<<n_neg++<<endl;
  cout << "conta: " << clientes[i].conta << endl;}

   }
   cout<<"Digite o cpf do cliente a ser procurado:";
   cin.getline (CPF_procurado,NC);

   i=0;
   while(strcmp(CPF_procurado, clientes[i].CPF) !=0 && i<nc);
    i++;
   if (i<nc){
    cout << "\n\n******************************************" << endl;
    cout << "**\t Informações do Cliente " << endl;
    cout << "**\t Nome: " << clientes[i].nome  << endl;
    cout << "**\t CPF: " << clientes[i].CPF  << endl;
    cout << "**\t Endereço: " << clientes[i].endereco  << endl;
    cout << "**\t Conta: " << clientes[i].conta  << endl;
    cout << "**\t Ano de Abertura: " << clientes[i].ano_abertura  << endl;
    cout << "**\t Saldo: " << clientes[i].saldo << endl;
    cout << "******************************************\n\n\n" ;
    }
else
    cout << "Cliente não encontrado\n";

    return 0;















    return 0;
}
