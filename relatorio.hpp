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
            arquivo << "Idade: " << paciente[i].getIdade() << " anos\n";
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
            string data = consulta[i].getData().substr(0,2) + "/" + consulta[i].getData().substr(2,2) + "/" + consulta[i].getData().substr(4,4);
            string horario = consulta[i].getHorario().substr(0, 2) + ":" + consulta[i].getHorario().substr(2,2);
            arquivo << "Procedimento: " << tipoConsultaStr << endl
                    << "Cirurgião-dentista: " << consulta[i].getmedico(tipoConsulta) << endl
                     << "Data da Consulta: " << data << endl
                     << "Horario: " << horario << endl;
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