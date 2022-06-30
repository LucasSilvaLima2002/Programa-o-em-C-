#define NUM_CAD 8 //N_CONV
#include <iostream>
#define NUM_CHA 300 //N_CHAR
#include<locale>

using namespace std;
int main()
 {
    setlocale(LC_ALL,"");
    char url[NUM_CAD][NUM_CAD];
    int i, o,position,vence, VOTO, m, vencedor;
    int cpf[NUM_CAD], posminerva[NUM_CAD];
    float AVAL1[NUM_CAD],AVAL2[NUM_CAD], AVAL3[NUM_CAD], media[NUM_CAD], minerva[NUM_CAD], maiorNota;
    bool ESCOLHA;

     do {
            cout <<" Quantas pessoas vao participar do concurso? \n Máximo "<<NUM_CAD<<endl;
            cin>>o;
    }
    while (o>NUM_CAD);

    for (i=0; i<o; i++){
            media[i]=0;
            cout<<"informe o link do projeto do candidato "<<i+1<<endl;
            cin.ignore();
            cin.getline(url[i],NUM_CHA);
            cout<<" CPF do proprietário do projeto "<<i+1<<endl;
            cout<<"*Insira sem pontuações ou '-' ***\n";
            cin>>cpf[i];
            cout<<"Nota do avaliador número 1   \n";
            cin>>AVAL1[i];
            cout<<"Nota do avaliador número 2   \n";
            cin>>AVAL2[i];
            cout<<"Nota do avaliador número 3   \n";
            cin>>AVAL3[i];
            media[i]= (AVAL1[i]+AVAL2[i]+AVAL3[i])/3;
    }

    cout<<"*APRESENTANDO A MÉDIA DOS CANDIDATOS*\n";
    for(i=0;i<o;i++){

        cout<<"\t candidato "<<i+1<<": "<<media[i]<<endl;
    }
    for (i=0;i<o;i++){
            if(media[i]>maiorNota){
                    maiorNota = media[i];
                    position=i;

            }}
            m=0;
        for (i=0;i<o;i++){
            if(maiorNota=media[i]){
                    m++;
                    minerva[i]=media[i];
                    posminerva[i]=i;

            } }

    if(m==1){

        cout<<"\t O vencedor é: "<<endl;
        cout<<"Projeto Nº"<<position+1<<endl;
        cout<<"CPF: "<<cpf[position]<<endl;
        cout<<"Link: "<<url[position]<<endl;
}else{

  for (i=0;i<o;i++){
        cout<<"média " << minerva[i]+1<<endl;
        cout<<"número do candidato " << posminerva[i]+1<<endl;
        }
        cout<<"escolha o número do candidato vencedor "<<endl;
        cin>>vencedor;}
    return 0;
}
