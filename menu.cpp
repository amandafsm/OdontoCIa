#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#pragma once

using namespace std;

struct Paciente
{
    string nome;
    string procedimento;
    string idade;
    string telefone;
    string data;
    string horario;
    string medico;
    string convenio;
    string particular;
};

vector<Paciente> paciente;

// Função para salvar os pacientes no arquivo
void salvarEmArquivo()
{
    ofstream arquivo("pacientes.txt");
    for (const auto &p : paciente)
    {
        arquivo << p.nome << endl
                << p.procedimento << endl
                << p.idade << endl
                << p.telefone << endl
                << p.data << endl
                << p.horario << endl
                << p.medico << endl
                << p.convenio << endl
                << p.particular << endl;
    }
    arquivo.close();
}

// Função para carregar os pacientes do arquivo
void carregarDoArquivo()
{
    ifstream arquivo("pacientes.txt");
    string nome, procedimento;
    while (getline(arquivo, nome) && getline(arquivo, procedimento))
    {
        paciente.push_back({nome, procedimento});
    }
    arquivo.close();
}

void listarPaciente()
{
    if (paciente.empty())
    {
        cout << "Nenhum paciente cadastrado.\n";
        return;
    }
    for (size_t i = 0; i < paciente.size(); ++i)
    {
        cout << "[" << i << "] " << paciente[i].nome << ": " << paciente[i].procedimento << endl;
    }
}

//void agendarPaciente()
//{
//    Paciente novo;
//    cout << "NOME: ";
//    getline(cin, novo.nome);
//    cout << "PROCEDIMENTO: ";
//    getline(cin, novo.procedimento);
//    cout << "IDADE: ";
//    getline(cin, novo.idade);
//    cout << "TELEFONE: ";
//    getline(cin, novo.telefone);
//    cout << "DATA: ";
//    getline(cin, novo.data);
//    cout << "HORÁRIO: ";
//    getline(cin, novo.horario);
//    cout << "MÉDICO: ";
//    getline(cin, novo.medico);
//    cout << "CONVÊNIO: ";
//    getline(cin, novo.convenio);
//    cout << "PARTICULAR: ";
//    getline(cin, novo.particular);
//    paciente.push_back(novo);
//    salvarEmArquivo();
//    cout << "Paciente cadastrado!\n";
//}

void editarPaciente()
{
    listarPaciente();
    cout << "Digite o índice do paciente para editar: ";
    size_t indice;
    cin >> indice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (indice < paciente.size())
    {
        cout << "Novo paciente: ";
        getline(cin, paciente[indice].nome);
        cout << "Novo procedimento: ";
        getline(cin, paciente[indice].procedimento);
        cout << "Nova idade: ";
        getline(cin, paciente[indice].idade);
        cout << "Novo telefone: ";
        getline(cin, paciente[indice].telefone);
        cout << "Nova data: ";
        getline(cin, paciente[indice].data);
        cout << "Novo horário: ";
        getline(cin, paciente[indice].horario);
        cout << "Novo médico: ";
        getline(cin, paciente[indice].medico);
        cout << "convênio: Sim/Não";
        cin >> paciente[indice].convenio;
        cout << "Particular: Sim/Não";
        getline(cin, paciente[indice].particular);
        salvarEmArquivo();
        cout << "Paciente editado com sucesso!\n";
    }
    else
    {
        cout << "Índice inválido.\n";
    }
}

void excluirPaciente()
{
    listarPaciente();
    cout << "Digite o índice do paciente para excluir: ";
    size_t indice;
    cin >> indice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (indice < paciente.size())
    {
        paciente.erase(paciente.begin() + indice);
        salvarEmArquivo();
        cout << "Paciente excluído com sucesso!\n";
    }
    else
    {
        cout << "Índice inválido.\n";
    }
}