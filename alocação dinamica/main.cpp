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
   cout<<"Não foi possivel alocar o espaço requisitado"<<endl;
   }
   else{
    cout<<"sizeof char:" <<sizeof(char)<<endl;
    cout<<"Digite caracter"<<endl;
    cin>>*pontChar;
    cout<<"Apresentação do dado armazenado na região = " << *pontChar;
    free(pontChar);
   }


    return 0;
}
