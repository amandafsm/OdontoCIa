#include "Paciente.hpp"
#include "crud.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#pragma once

using namespace std;

void Menu::relatorioPaciente()
{
    ofstream arquivo("relatorio_pacientes.txt");
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo para escrita!" << endl;
        return;
    }

    // Cabeçalho do relatório
    arquivo << "=========================================\n";
    arquivo << "         RELATÓRIO DE PACIENTES         \n";
    arquivo << "=========================================\n\n";

    // Lista de pacientes
    int count = 0;
    for (int i = 0; i < 100; i++)
    {
        if (!paciente[i].getNome().empty())
        {
            count++;
            arquivo << "PACIENTE #" << count << "\n";
            arquivo << "Nome: " << paciente[i].getNome() << "\n";
            string cpf = paciente[i].getcpf().substr(0, 3) + "." +
                         paciente[i].getcpf().substr(3, 3) + "." +
                         paciente[i].getcpf().substr(6, 3) + "-" +
                         paciente[i].getcpf().substr(9, 2);
            arquivo << "CPF: " << cpf << "\n";
            arquivo << "Idade: " << paciente[i].getIdade() << "\n";
            string telefone = "(" + paciente[i].getTelefone().substr(0, 2) + ") " +
                              paciente[i].getTelefone().substr(2, 5) + "-" +
                              paciente[i].getTelefone().substr(7, 4);
            arquivo << "Telefone: " << telefone << "\n";
            arquivo << "Peso: " << fixed << setprecision(2) << paciente[i].getPeso() << " Kg \n";
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
            arquivo << "Procedimento: " << tipoConsultaStr << endl
                    << "Cirurgião-dentista: " << consulta[i].getmedico(tipoConsulta) << endl;
            arquivo << "-----------------------------------------\n";
        }
    }

    // Rodapé do relatório
    arquivo << "\nTotal de pacientes: " << count << "\n";
    arquivo << "=========================================\n";

    arquivo.close();
    cout << "Relatório gerado com sucesso em 'relatorio_pacientes.txt'!\n";
    cout << "Total de pacientes registrados: " << count << endl;
}