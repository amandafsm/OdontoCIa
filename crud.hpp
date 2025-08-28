#include "Paciente.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#pragma once

using namespace std;

class Menu
{
protected:
    Paciente paciente[100];
    Consulta consulta[100];
    int totalpac;

public:
    Menu() : totalpac(0)
    {
        for (int i = 0; i < 100; i++)
        {
            paciente[i] = Paciente();
            consulta[i] = Consulta();
        }
    }
    void carregarPrograma();
    void agendarPaciente();
    void editarPaciente();
    void excluirPaciente();
    void listarPaciente();
    void relatorioPaciente();
    int acharPosicao();
    void salvarPrograma();
};
