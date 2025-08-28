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
            int novaIdade;
            bool novoConvenio, novoParticular;

            cin.ignore();
            cout << "Novo nome: " << endl;
            getline(cin, novoNome);
            paciente[i].setNome(novoNome);
            cout << "Novo procedimento: " << endl;
            getline(cin, novoProcedimento);
            cout << "Nova idade: " << endl;
            cin >> novaIdade;
            paciente[i].setIdade(novaIdade);
            cout << "Novo telefone: " << endl;
            getline(cin, novoTelefone);
            paciente[i].setTelefone(novoTelefone);
            cout << "Convênio ou Particular: " << endl;
            cout << "(1-Convenio, 0-Particular): ";
            cin >> novoParticular;
            paciente[i].setPagamento(novoParticular);

            salvarPrograma();
            cout << "Paciente editado com sucesso!\n";
            break;
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
