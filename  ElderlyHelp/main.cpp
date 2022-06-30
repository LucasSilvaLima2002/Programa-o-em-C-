/*********************************************
Lucas Silva Lima/RM:85306
Guilherme Cabrini Oliveira/RM:84189
Neil Della Vega/RM:84916
Thiago Yoneyama Hiroaki Masuda/RM85927
**********************************************/
#include <iostream>
#include<locale>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>

using namespace std;

#define N_Clientes 100  //número de clientes máximo da clínica
#define N_MED 48        //número de medidas registradas por dia
#define NC 20           //número de caracteres das strings usadas no programa
#define NC_LINHA 80
#define NC_SN 4         //número de caracteres das strings de resposta sim e nao

 struct med{
      char hora[NC];
      int sistole;
      int diastole;
      int frequencia;
      int glicemia;
};
typedef struct med TipoMedida;
struct clien{
    char id[NC];
    int idade;
    char sexo[NC];
    char hipertensao[NC_SN];
    char diabetes[NC_SN];

};
typedef struct clien TipoCliente;




int busca_binaria(TipoCliente vet[], int num, char chave[]){
int i_baixo = 0,i_alto = num-1, i_medio;
int achou = 0;
int	pos = -1;
int cont = 0;

while( achou != 1 && i_baixo <=  i_alto)	{
	i_medio = (i_baixo + i_alto)/2;

	cont++;
	if (strcmp(chave,vet[i_medio].id)==0)  {
		pos = i_medio;
		achou =1;
		}
	else {
		if (strcmp(chave,vet[i_medio].id)<=0)
			i_alto = i_medio-1;
		else
			i_baixo = i_medio+1;
        }
	}

	return(pos);
}


int busca_sequencial_exaustiva(TipoMedida vet[],int chave,int encontrados[]){
int i, ne=0;
for(i=0; i<48; i++){
      if(vet[i].glicemia == chave){
        encontrados[ne] = i;
        ne++;
    }
}
return ne;
}

int insertionsort(TipoMedida vetor[],int n)
{
int eleito, j,i;
int comp=0;
for(i = 1; i <n; i++) {
	eleito = vetor[i].frequencia;
	j = i-1;
    comp++;
	while (j >= 0 && vetor[j].frequencia < eleito) {
        comp++;
		vetor[j+1].frequencia = vetor[j].frequencia;
		j = j-1;
		}
	vetor[j+1].frequencia =  eleito;
	}
return comp;
}

int main(){

setlocale(LC_ALL, "");
FILE *arq;
int i,np,nm,n,resp,ne,indice[N_MED];
int maior=0;  //variável que armazena o maior valor de glicemia
int cont;   //variável que armazena quantas medidas de pressão com valores acima de 14:10
char id[NC];
char aux[NC_LINHA];
TipoMedida medidas[N_MED],encontrados[N_MED];
TipoCliente clientes[N_Clientes];

arq = fopen("ListaClientes.txt", "rt");
if (arq == NULL)  {
     printf("Problemas na abertura do arquivo\n");
     return -1;
    }
else{
      np = 0;
      fgets(aux, NC_LINHA,arq);
      cout <<aux<<endl;
      while (fscanf(arq, "%s%i%s%s%s", clientes[np].id, &clientes[np].idade,clientes[np].sexo,clientes[np].hipertensao,clientes[np].diabetes) != EOF){
          cout << clientes[np].id<< "\t\t "<< clientes[np].idade << " \t"<<clientes[np].sexo<< "\t" <<clientes[np].hipertensao << "\t\t" <<clientes[np].diabetes<<endl;
          np++;
          }
   fclose(arq);
   do{
        cout << "\n************  Lista de Clientes com Registros Atualizados *********************\n";
        cout << "\t 1393\n\t 1492\n ";
        cout <<"Qual ID de cliente que quer analisar: ";
        cin.getline(id, 80);
        cout << "cliente a consultar: " << id<< endl;
        n = busca_binaria(clientes,np,id);
        if(np == -1){
        cout << "Registro não encontrado \n";}
        else{

        cout <<"ID: "<< clientes[n].id<< " idade: "<< clientes[n].idade << " sexo: "<<clientes[n].sexo<< " hipertensão: " <<clientes[n].hipertensao<< " diabetes: "<<clientes[n].diabetes <<endl;}
        system("pause");

        strcat(id,"_01_06");
        strcat(id,".txt");
        arq = fopen(id, "rt");
        if (arq == NULL)  {
            printf("Problemas na abertura do arquivo\n");
            return -1;
            }
          nm= 0;
          fgets(aux, NC_LINHA,arq);
          while (nm<N_MED) {
              fscanf(arq, "%s%i%i%i%i", medidas[nm].hora, &medidas[nm].sistole,&medidas[nm].diastole,&medidas[nm].frequencia,&medidas[nm].glicemia);
              if(maior<medidas[nm].glicemia){
               maior=medidas[nm].glicemia;}
              nm++;
          }
          fclose(arq);

          do{
            system("cls");
            cout << "1) Encontrar maior medida de glicemia registrada e apresentar todas as ocorrências.\n" ;
            cout << "2) Apresentar quantas medidas foram registradas de pressão sistólica a partir de 14 mmHg e diastólica a partir de 10 mmHg .\n";
            cout << "3) Apresentar os 20 registros com os maiores valores de pulsação.\n";
            cout << "4) Encerrar análise do cliente.\n";
            cout << "\t Digite a opção desejada: " ;
            cin >> resp;
            cin.ignore();
             switch(resp){
              case 1: system("cls");{



               for (i=0;i<N_MED; i++){
               if(medidas[i].glicemia > maior){
               maior=medidas[i].glicemia;
               indice[i]=i;
                     }
                 }


                int nx = busca_sequencial_exaustiva(medidas, maior, indice);
                for(i=0;i<nx;i++){
                cout <<"\nMaiores niveis de glicose:"<<endl;
                cout << "Horário: "<<medidas[indice[i]].hora<<endl;
                cout <<"Sistole: "<<medidas[indice[i]].sistole<<endl;
                cout <<"Diastole: "<<medidas[indice[i]].diastole<<endl;
                cout <<"Frequencia: "<<medidas[indice[i]].frequencia<<endl;
                cout <<"Glicemia: "<<medidas[indice[i]].glicemia<<"\t"<<endl;}

              }

                      system("pause");
                      break;
              case 2: system("cls");
              for(i=0;i<48;i++){
              if(medidas[i].diastole>=10){
                    cont++;}}
              cout<<"Numero de vezes que a diastole foi maior ou igual a 10: "<<cont<<endl;
              for(i=0;i<48;i++){
              if(medidas[i].sistole>=14){
                    cont++;}}
            cout<<"Numero de vezes que a sisstole foi maior ou igual a 14: "<<cont<<endl;


                      system("pause");
                      break;
              case 3: system("cls");
                      insertionsort(medidas,N_MED);
                      for(i=0;i<20;i++){
                        cout<<medidas[i].frequencia<< endl;
                      }
                      system("pause");
                      break;

                      system("pause");
                      break;
              case 4: cout << "Encerrando a avaliação. \nGerar atualização do prontuário!\n\n";
                      break;
              default: cout << "opção inválida\n";
              }
            } while (resp!=4);
        cout << "Deseja analisar mais um cliente? (1-sim /Qualquer outro valor - não): ";
        cin >> resp;
        cin.ignore();
      }while(resp == 1);
    }
    return 0;

}

