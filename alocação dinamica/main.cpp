#include <iostream>
#include <locale>

using namespace std;

int main()
{
   setlocale(LC_ALL,"");
   char  *pontChar;
   cout<<"teste"<<endl;
   cin>>*pontChar;

   pontChar = (char*) malloc(sizeof(char));

   if(pontChar ==NULL){
   cout<<"N�o foi possivel alocar o espa�o requisitado"<<endl;
   }
   else{
    cout<<"sizeof char:" <<sizeof(char)<<endl;
    cout<<"Digite caracter"<<endl;
    cin>>*pontChar;
    cout<<"Apresenta��o do dado armazenado na regi�o = " << *pontChar;
    free(pontChar);
   }


    return 0;
}
