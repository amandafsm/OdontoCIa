#include "Paciente.hpp"
#include "crud.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#pragma once

using namespace std;

void Menu::listarPaciente()
{
    bool encontrado = false;
    int cond = 0;
    cout << "Listar todos[0]" << endl
         << "Listar apenas um paciente[1]" << endl;
    cin >> cond;
    if (cond == 0)
    {
        cout << "Lista de pacientes:\n";
        for (int i = 0; i < 100; i++)
        {

            if (!paciente[i].getNome().empty())
            {
                encontrado = true;
                cout << "Nome: " << paciente[i].getNome() << endl;
                cout << "CPF: " << paciente[i].getcpf() << endl;
                cout << "Idade: " << paciente[i].getIdade() << " anos" << endl;
                string telefone = "(" + paciente[i].getTelefone().substr(0, 2) + ") " +
                                  paciente[i].getTelefone().substr(2, 5) + "-" +
                                  paciente[i].getTelefone().substr(7, 4);
                cout << "Telefone: " << telefone << endl;
                cout << "Peso: " << paciente[i].getPeso() << " Kg" << endl;
                cout << "Pagamento: " << paciente[i].getPagamentoStr() << endl;
                int tipoConsulta = static_cast<int>(consulta[i].getTipodeConsulta());
                string tipoConsultaStr;
                switch (tipoConsulta)
                {
                case 0:
                    tipoConsultaStr = "RESTAURACAO";
                    break;
                case 1:
                    tipoConsultaStr = "CLAREAMENTO";
                    break;
                case 2:
                    tipoConsultaStr = "ORTODONTIA";
                    break;
                case 3:
                    tipoConsultaStr = "LIMPEZA";
                    break;
                case 4:
                    tipoConsultaStr = "EXAMES_ROTINA";
                    break;
                default:
                    tipoConsultaStr = "DESCONHECIDO";
                    break;
                }
                cout << "Tipo de Consulta: " << tipoConsultaStr << endl;
                cout << "Odontologista: " << consulta[i].getmedico(tipoConsulta) << endl;
                cout << "------------------------" << endl;
            }
        }
    }
    else if (cond == 1)
    {
        cout << "Digite o CPF do Paciente: " << endl;
        string cpfbusca = "";
        getline(cin >> ws, cpfbusca);
        for (int i = 0; i < 100; i++)
        {
            if (paciente[i].getcpf() == cpfbusca)
            {
                cout << "------------------------" << endl;
                cout << "Nome: " << paciente[i].getNome() << endl;
                cout << "CPF: " << paciente[i].getcpf() << endl;
                cout << "Idade: " << paciente[i].getIdade() << " anos" << endl;
                string telefone = "(" + paciente[i].getTelefone().substr(0, 2) + ") " +
                                  paciente[i].getTelefone().substr(2, 5) + "-" +
                                  paciente[i].getTelefone().substr(7, 4);
                cout << "Telefone: " << telefone << endl;
                cout << "Peso: " << paciente[i].getPeso() << " Kg" << endl;
                cout << "Pagamento: " << paciente[i].getPagamentoStr() << endl;
                int tipoConsulta = static_cast<int>(consulta[i].getTipodeConsulta());
                string tipoConsultaStr;
                switch (tipoConsulta)
                {
                case 0:
                    tipoConsultaStr = "RESTAURACAO";
                    break;
                case 1:
                    tipoConsultaStr = "CLAREAMENTO";
                    break;
                case 2:
                    tipoConsultaStr = "ORTODONTIA";
                    break;
                case 3:
                    tipoConsultaStr = "LIMPEZA";
                    break;
                case 4:
                    tipoConsultaStr = "EXAMES_ROTINA";
                    break;
                default:
                    tipoConsultaStr = "DESCONHECIDO";
                    break;
                }
                cout << "Tipo de Consulta: " << tipoConsultaStr << endl;
                cout << "Odontologista: " << consulta[i].getmedico(tipoConsulta) << endl;
                cout << "------------------------" << endl;
            }
            else
            {
                continue;
            }
        }
    }
}