#include "Paciente.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#pragma once

using namespace std;

class Menu 
{
private:
Medico medicos[5] = {
    Medico(string("Mariana Lopes"), 45, string("58291436720"), string("83987654321"), string("123456"), string("RESTAURACAO")),
    Medico(string("Ricardo Nogueira"), 39, string("71382549031"), string("83999887766"), string("234567"), string("CLAREAMENTO")),
    Medico(string("Camila Ferreira"), 50, string("29473861542"), string("83988776655"), string("345678"), string("ORTODONTIA")),
    Medico(string("André Carvalho"), 33, string("83941752653"), string("83977665544"), string("456789"), string("LIMPEZA")),
    Medico(string("Beatriz Mendes"), 42, string("60518394764"), string("83966554433"), string("567890"), string("EXAMES_ROTINA"))
};

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
    void listarMedico();
    void relatorioPaciente();
    int acharPosicao();
    void salvarPrograma();
};
