#include <iostream>
#include <cstring>
#include <ctime>
#include <stdlib.h>

using namespace std;
#define MAX 10

int main()
{
    int opcao, id[MAX][6], presenca[MAX][2],val_carg[MAX][20],a, b, i, y, z = 0;
    bool sair = false, id_teste = false, carg = false;
    char porto[MAX][32], port_dest[1][32], cnpj[MAX][20], c[1][20];
    for (i = 0; i < MAX; i++)
    {
        presenca[i][2] = 1; // Monta a lista da situa��o da carga. (1 p/ armazenada, 0 p/ em transporte)
    }
    while (sair == false)
    {
        cin.clear();
        cout << "\nInforme um numero de acordo com o menu abaixo:\n" // Menu principal
             << "0)Encerrar programa.\n"
             << "1)Cadastrar entrada de Conteiner no armazem.\n"
             << "2)Consultar informacoes de conteiner.\n"
             << "3)Gera uma lista de container selecionados pelo porto destino.\n"
             << "4)Retira os containers para serem embarcados em um navio.\n"
             << "5)Gera relatorio de todos conteiners que ja foram embarcados.\n"
             << endl;
        cout << "Opcao desejada: ";
        cin >> opcao;
        switch (opcao) // Apropriara a op�ao do usuario de acordo com o menu anterior
        {
        case 0: // Fecha o programa
            cout << "\n**Encerrando programa..**" << endl;
            sair = true;
            break;
        case 1: // Cadastra um novo container: ID � gerado automaticamente, CNPJ e Destino s�o escolhidos pelo usuario
            system("cls");
            while (id_teste == false)
            {
                //cout << "\nInforme o ID do container (max. 6 digitos): ";
                //cin >> y;
                y = (rand() % 999999) + 1; // Gerar um ID aleatorio de 6 digitos
                for (i = 0; i < MAX; i++)
                {
                    if (y != id[i][6]) // Garante que o ID seja unico
                    {
                        id_teste = true;
                    }
                    else
                    {
                        cout << "ID ja cadastrado. Informe um outro valor." << endl;
                        id_teste = false;
                        break;
                    }
                }
            }
            cout << "ID Gerado: " << y << endl;
            cout << "CNPJ do proprietario da carga (xx.xxx.xxx/xxx-xx): ";
            cin.sync(); // limpa o buffer
            cin.getline(cnpj[z], 20);
            cout << "Porto de destino da carga: ";
            cin.sync();
            cin.getline(porto[z], 32);
            cout << "Valor da carga (max. 19 digitos): ";
            cin >> val_carg[z][20];
            cout << "Carga cadastrada com sucesso!" << endl;
            z = z + 1; // Para todo novo container que for registrada no sistema
            id_teste = false;
            break;
        case 2: // Busca informa��es dos containers, seja pelo ID ou CNPJ.
            system("cls");
            cout << "\n de qual maneira voce quer consultar as informacoes: "
                 << "\n1) ID"
                 << "\n2) CNPJ"
                 << "\nOpcao: ";
            cin >> a;
            if (a == 1) // ID
            {
                cout << "Informe o ID: ";
                cin >> b;
                system("cls");
                cout << "\nCargas registradas:" << endl;
                carg = false;
                for (i = 0; i < MAX; i++)
                {
                    if (b == id[i][6]) // Compara os dados informados com aqueles armazenados
                    {
                        carg = true;
                        cout << "*******************************************************"
                             << "\nID: " << id[i][6]
                             << "\nCNPJ: " << cnpj[i]
                             << "\nPorto de destino: " << porto[i]
                             << "\nValor da carga: R$" << val_carg[i][20] << ",00";
                        if (presenca[i][2] == 1)
                        {
                            cout << "\nSituacao: Carga no armazem." << endl;
                        }
                        else
                        {
                            cout << "\nSituacao: Carga ja foi embarcada." << endl;
                        }
                    }
                }
                if (carg == false) // Caso n�o localize nenhum container pelo ID informado
                {
                    cout << "**Nenhuma carga encontrada para o ID '" << b << "' informado.**" << endl;
                }
            }
            else if (a == 2) // CNPJ
            {
                cout << "Informe o CNPJ: ";
                cin.sync();
                cin.getline(c[0], 20);
                system("cls");
                cout << "\nCargas registradas:" << endl;
                carg = false;
                for (i = 0; i < MAX; i++)
                {
                    if (strcmp(c[0], cnpj[i]) == 0)
                    {
                        carg = true;
                        cout << "*******************************************************"
                             << "\nID: " << id[i][6]
                             << "\nCNPJ: " << cnpj[i]
                             << "\nPorto de destino: " << porto[i]
                             << "\nValor da carga: R$" << val_carg[i][20] << ",00";
                        if (presenca[i][2] == 1)
                        {
                            cout << "\nSituacao: Carga no armazem." << endl;
                        }
                        else
                        {
                            cout << "\nSituacao: Carga ja foi embarcada." << endl;
                        }
                    }
                }
                if (carg == false) // Caso n�o localize nenhum container pelo CNPJ informado
                {
                    cout << "**Nenhuma carga encontrada para o CNPJ '" << c[0] << "' informado.**\n";
                }
            }
            else // Se o usuario digitar qualquer coisa diferente de 1 ou 2 ele volta ao menu anterior.
            {
                cout << "Opcao invalida." << endl;
                break;
            }
            break;
        case 3: // Busca informa��es dos containers de acordo com o destino
            system("cls");
            cout << "\nInforme o porto de destino: ";
            cin.sync();
            cin.getline(port_dest[0], 32);
            system("cls");
            cout << "\nCargas registradas com destino para '" << port_dest[0] << "' :" << endl;
            carg = false;
            for (i = 0; i < MAX; i++)
            {
                if (strcmp(port_dest[0], porto[i]) == 0)
                {
                    carg = true;
                    cout << "*******************************************************"
                         << "\nID: " << id[i][6]
                         << "\nCNPJ: " << cnpj[i]
                         << "\nValor da carga: R$" << val_carg[i][20] << ",00";
                    if (presenca[i][2] == 1)
                    {
                        cout << "\nSituacao: Carga no armazem." << endl;
                    }
                    else
                    {
                        cout << "\nSituacao: Carga ja foi embarcada." << endl;
                    }
                }
            }
            if (carg == false) // Caso n�o localize nenhuma carga pelo destino informado
            {
                cout << "**Nenhuma carga encontrada para o destino '" << port_dest[0] << "' informado.**\n";
            }
            break;
        case 4: // Retira os containers do armazem de acordo com o destino
            system("cls");
            cout << "\nInforme o destino dos containers a serem embarcados: ";
            cin.sync();
            cin.getline(port_dest[0], 32);
            system("cls");
            carg = false;
            cout << "\nCargas registradas com destino para '" << port_dest[0] << "' embarcadas:" << endl;
            for (i = 0; i < MAX; i++)
            {
                if (strcmp(port_dest[0], porto[i]) == 0)
                {
                    carg = true;
                    cout << "*******************************************************"
                         << "\nID: " << id[i][6]
                         << "\nCNPJ: " << cnpj[i]
                         << "\nValor da carga: R$" << val_carg[i][20] << ",00";
                    if (presenca[i][2] == 1) // Inverte o valor da armazenagem da carga de 1(armazenada) para 0(em transporte).
                    {
                        presenca[i][2] = 0;
                        cout << "\nSituacao: Carga retirada para embarcacao." << endl;
                    }
                }
            }
            if (carg == false) // Caso n�o localize nenhum container pelo destino informado
            {
                cout << "**Nenhuma carga encontrada para o destino '" << port_dest[0] << "' informado.**\n";
            }
            break;
        case 5: // Lista todos os containers que ja foram embarcados desde que sistema foi inicializado
            system("cls");
            cout << "\nLista de todos os containers ja embarcados: " << endl;
            carg == false;
            for (i = 0; i < MAX; i++)
            {
                if (presenca[i][2] == 0)
                {
                    carg == true;
                    cout << "*******************************************************"
                         << "\nID: " << id[i][6]
                         << "\nCNPJ: " << cnpj[i]
                         << "\nPorto de destino: " << porto[i]
                         << "\nValor da carga: R$" << val_carg[i][20] << ",00" << endl;
                }
            }
            if (carg == false) // Caso n�o haja nenhuma carga em transporte
            {
                cout << "**Nenhuma carga embarcada.**\n";
            }
            break;
        default: // Se o valor do menu informado seja diferente do intervalo de  0 <= x <= 6
            cout << "\n\t**Opcao invalida!**" << endl;
            break;
        }
    }
    return 0;
}
