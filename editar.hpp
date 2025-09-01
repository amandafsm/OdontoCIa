#include "Paciente.hpp"
#include "crud.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#pragma once

using namespace std;

void Menu::editarPaciente()
{
    string cpfBusca;
    cout << "Digite o cpf do paciente: ";
    cin >> cpfBusca;
    bool encontrado = false;

    for (int i = 0; i < 100; i++)
    {
        if (paciente[i].getcpf() == cpfBusca)
        {
            encontrado = true;
            cout << "Paciente encontrado: " << paciente[i].getNome() << "." << endl;

            string novoNome, novoProcedimento, novoTelefone, novaData, novoHorario;
            int novaIdade, opcao;
            bool novoConvenio, novoParticular;

            do
            {
                cout << "\nO que deseja editar?\n";
                cout << "[1]Nome\n";
                cout << "[2]Procedimento\n";
                cout << "[3]Telefone\n";
                cout << "[4]Data do procedimento\n";
                cout << "[5]Novo convênio\n";
                cout << "[6]Novo horário\n";
                cout << "[7]Nova idade\n";
                cout << "[8]Voltar ao menu anterior\n";
                cin >> opcao;
                cin.ignore();

                switch (opcao)
                {
                case 1:
                {
                    cout << "Novo nome:" << endl;
                    getline(cin, novoNome);
                    paciente[i].setNome(novoNome);
                    break;
                }
                case 2:
                {
                    int escolhaNovoProcedimento = 0;

                    cout << "Novo procedimento\n";
                    cout << "[1]Restauração" << endl;
                    cout << "[2]Clareamento" << endl;
                    cout << "[3]Ortodontia" << endl;
                    cout << "[4]Limpeza" << endl;
                    cout << "[5]Exames de rotina" << endl;
                    cin >> escolhaNovoProcedimento;

                    consulta[i].setTipodeConsulta(static_cast<TipodeConsulta>(escolhaNovoProcedimento));
                    break;
                }
                case 3:
                {
                    cout << "Novo telefone:" << endl;
                    getline(cin, novoTelefone);
                    while (novoTelefone.empty() || novoTelefone.length() < 11)
                    {
                        cout << "Telefone inválido. Digite novamente: ";
                        getline(cin >> ws, novoTelefone);
                    }
                    paciente[i].setTelefone(novoTelefone);
                    break;
                }
                case 4:
                {
                    int novoDia, novoMes, novoAno;

                    while (true)
                    {
                        cout << "Insira a nova data da Consulta: " << endl;
                        cout << "Dia: ";
                        if (!(cin >> novoDia))
                        {
                            cout << "Entrada inválida! Digite apenas números.\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }

                        cout << "Mês: ";
                        if (!(cin >> novoMes))
                        {
                            cout << "Entrada inválida! Digite apenas números.\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }

                        cout << "Ano: ";
                        if (!(cin >> novoAno))
                        {
                            cout << "Entrada inválida! Digite apenas números.\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }

                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

                   
                        if (novoMes < 1 || novoMes > 12)
                        {
                            cout << "Mês inválido. Tente novamente." << endl;
                            continue;
                        }

                        int diasNoMes;
                        switch (novoMes)
                        {
                        case 2:
                            
                            if ((novoAno % 4 == 0 && novoAno % 100 != 0) || (novoAno % 400 == 0))
                                diasNoMes = 29;
                            else
                                diasNoMes = 28;
                            break;
                        case 4:
                        case 6:
                        case 9:
                        case 11:
                            diasNoMes = 30;
                            break;
                        default:
                            diasNoMes = 31;
                            break;
                        }

                        if (novoDia < 1 || novoDia > diasNoMes)
                        {
                            cout << "Dia inválido para o mês informado. Tente novamente." << endl;
                            continue;
                        }

                        break;
                    }

                    char novoBuffer[11];
                    snprintf(novoBuffer, sizeof(novoBuffer), "%02d%02d%04d", novoDia, novoMes, novoAno);

                    novaData = novoBuffer;
                    consulta[i].setData(novoBuffer);
                    break;
                }
                case 5:
                {
                    cout << "Convênio ou Particular: " << endl;
                    cout << "(1-Convenio, 0-Particular): ";
                    cin >> novoParticular;
                    paciente[i].setPagamento(novoParticular);
                    break;
                }
                case 6:
                {
                    cout << "Digite o novo Horário: " << endl;
                    getline(cin, novoHorario);

                    while (novoHorario.length() != 5 || novoHorario[2] != ':' ||
                           !isdigit(novoHorario[0]) || !isdigit(novoHorario[1]) ||
                           !isdigit(novoHorario[3]) || !isdigit(novoHorario[4]))
                    {
                        cout << "Horário inválido. Digite novamente (formato HH:MM): ";
                        getline(cin >> ws, novoHorario);
                    }
                    novoHorario = novoHorario.substr(0,2) + novoHorario.substr(3,2);
                    consulta[i].setHorario(novoHorario);
                    break;
                }
                case 7:
                {
                    cout << "Nova idade: " << endl;
                    cin >> novaIdade;
                    while (cin.fail() || novaIdade <= 0 || novaIdade > 80)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Idade inválida. Digite novamente: ";
                        cin >> novaIdade;
                    }
                    cin.ignore();
                    paciente[i].setIdade(novaIdade);
                    break;
                }
                case 8:
                {
                    cout << "Voltando ao menu anterior...\n"
                         << endl;
                    break;
                }
                default:
                    cout << "[ERRO] Opção inválida! Escolha novamente\n"
                         << endl;
                }
            } while (opcao != 8);
        }
    }
    if (!encontrado)
    {
        cout << "Paciente não encontrado.\n";
    }
}

string validarNome(string nome)
{
    while (nome.empty())
    {
        cout << "Nome não pode ser vazio. Digite novamente: ";
        getline(cin >> ws, nome);
    }
    return nome;
}