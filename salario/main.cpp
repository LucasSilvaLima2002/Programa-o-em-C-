#include <iostream>
#include<locale>

using namespace std;

int main()
{
setlocale(LC_ALL,"");
float SLR;
int x;

 cout << "Qual o sal�rio atual do funcion�rio? ";
cin >> SLR;

 cout <<"Quanto anos � funcion�rio da empresa? ";
cin >> x;

 if (x<0)
cout <<" Tempo deve ser maior do zero \n";
else {
if (x <= 2)
SLR = SLR  * 1,03;
else if (x <= 5)
SLR = SLR * 1.05;
else if (x <= 10)
SLR = SLR * 1.07;
else
SLR = SLR * 1.09;
cout << "O valor final do sal�rio � R$ " << SLR << endl;
}
return 0;
}
