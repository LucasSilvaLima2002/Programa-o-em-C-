#include <iostream>
#include <locale.h>
#include <stdio.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"");
    int resp,resp2;
    float x,y,dinheiro=100;
    cout<<"A quantidade de dinheiro é de: "<<dinheiro<<endl;
      do{
    cout<<"Digite 1 para somar e 2 para subtrair"<<endl;
    cin>>resp;
    switch(resp){
    case 1:
        cout<<"Digite a quantidade a ser somada"<<endl;
        cin>>x;
        dinheiro = dinheiro + x;
        break;
    case 2:
        cout<<"Digite a quantidade a ser subtraida"<<endl;
        cin>>y;
        dinheiro = dinheiro - y;
    break;
    }
    cout<<"A quantidade de dinheiro é de: "<<dinheiro<<endl;
    cout<<"Digite 1 para continuar e 2 para encerrar"<<endl;
    cin>>resp2;
    }while(resp2==1);



    return 0;
}
