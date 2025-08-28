#include "Paciente.hpp"
#include "crud.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#pragma once

using namespace std;

void Menu::excluirPaciente()
{
    string cpfBusca;
    cout << "Digite o CPF do paciente a ser excluído: ";
    cin >> cpfBusca;
    bool encontrado = false;

    for (int i = 0; i < 100; i++)
    {
        if (paciente[i].getcpf() == cpfBusca)
        {
            encontrado = true;
            paciente[i] = Paciente();
            consulta[i] = Consulta();
            cout << "Paciente excluído com sucesso!\n";
            break;
        }
    }
    if (!encontrado)
    {
        cout << "Paciente não encontrado.\n";
    }
}