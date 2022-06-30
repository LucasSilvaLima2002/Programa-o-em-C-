#include <iostream>
#include <locale>
#include<cstring>
#define MAX 2000
#define NC 50

using namespace std;
struct cliente_banco {  //declaração o molde da struct
	   char nome[NC];
	   char endereco[NC];
	   char CPF[NC];
	   int conta;
	   int ano_abertura;
	   float saldo;
       };
       typedef struct cliente_banco Tipo_Cliente;
int main(){
setlocale(LC_ALL,"");
Tipo_Cliente clientes[MAX];
int nc,i,x,neg;
char resp;
char CPF_procurado[15];

    cout<<"Numero de clientes:";
    cin>>nc;
    for(i=0;i<nc;i++){
    cout << "Informe CPF do cliente: \n ";
    cin.ignore();
    cin.getline(clientes[i].CPF,NC) ;
    cout << "Nome do cliente: \n";
    cin.getline(clientes[i].nome,NC) ;
    cout << "digite o endereço: \n";
    cin.getline(clientes[i].endereco,NC) ;
    cout << "digite o numero da conta: \n";
    cin >> clientes[i].conta;
    cout << "Ano de abertura da conta: \n";
    cin >> clientes[i].ano_abertura;
    cout << "Digite saldo atual da conta: \n";
    cin >> clientes[i].saldo;
}
//do{
        //cout << "Informe CPF do cliente: ";
        //cin.getline(clientes[nc].CPF,NC) ;
        //cout << "Nome do cliente: \n";
        //cin.getline(clientes[nc].nome,NC) ;
        //cout << "digite o endereço: ";
        //cin.getline(clientes[nc].endereco,NC) ;
        //cout << "digite o numero da conta: ";
        //cin >> clientes[nc].conta;
        //cout << "Ano de abertura da conta: ";
        //cin >> clientes[nc].ano_abertura;
        //cout << "Digite saldo atual da conta: ";
        //cin >> clientes[nc].saldo;
        //nc++;
        //cout <<"deseja cadastrar mais 1 cliente? (s/n): ";
        //cin >> resp;
        //cin.ignore();
    //n} while ((resp == 's' || resp == 'S') && nc < MAX);

    for (i=0; i<nc; i++){
    cout << "\n\n******************************************" << endl;
    cout << "**\t Numero do cliente " <<i+1 << endl;
    cout << "**\t Nome: " << clientes[i].nome  << endl;
    cout << "**\t CPF: " << clientes[i].CPF  << endl;
    cout << "**\t Endereço: " << clientes[i].endereco  << endl;
    cout << "**\t Conta: " << clientes[i].conta  << endl;
    cout << "**\t Ano de Abertura: " << clientes[i].ano_abertura  << endl;
    cout << "**\t Saldo: " << clientes[i].saldo << endl;
    cout << "******************************************\n\n\n" ;
}
 for (i=0; i<nc; i++){
 x=0;
 if(clientes[i].ano_abertura <= 2011);{
 x++;}}
 cout<<"O numero de contas com mais de 10 anos:"<<x+1<<endl;

 for (i=0; i<nc; i++){
 neg=0;
if(clientes[i].saldo < 0){
    neg++;
  cout << "contas negativas: " << clientes[i].conta << endl;}}



cout << "\n\nDigite CPF do cliente a ser procurado: ";
cin.ignore();
cin.getline(CPF_procurado, NC);

i=0;
while ( strcmp(CPF_procurado, clientes[i].CPF) != 0  && i<nc)
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
}
