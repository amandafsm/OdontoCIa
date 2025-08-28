#include "Paciente.hpp"
#include "crud.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#pragma once

using namespace std;

void Menu::salvarPrograma()
{
    ofstream arquivo("backup.txt", ios::out);

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }
    // Escrever apenas os elementos realmente usados

    for (int i = 0; i < acharPosicao(); i++)
    {
        arquivo << paciente[i].getNome() << ";"
                << paciente[i].getcpf() << ";"
                << paciente[i].getIdade() << ";" << paciente[i].getTelefone() << ";" << paciente[i].getPeso() << ";"
                << paciente[i].getPagamento() << ";" << consulta[i].getData()
                << ";" << consulta[i].getHorario() << ";" << consulta[i].getConsulta() << endl;
    }

    arquivo.close();
}