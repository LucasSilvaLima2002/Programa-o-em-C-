#include <iostream>
#define MAX 100
using namespace std;

int main()
{
    char teste[MAX];

    cout<<"Escolha uma palavra"<<endl;
    cin>> teste[MAX];
    cout<<"Palavra: "<< teste[MAX]<<endl;
    teste[MAX]=  teste[MAX] + 7;
    cout<<"Palavra: "<< teste[MAX]<<endl;

    return 0;
}
