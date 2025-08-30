#include "Paciente.hpp"
#include "crud.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#pragma once

using namespace std;

void Menu::agendarPaciente()
{
    string nomeP, telefone, data, horario, cpf;
    float peso;
    int idadeP, idadeM, tipoInt, tipoConsulta;
    int pos = 0;
    pos = acharPosicao();
    //  Nome do paciente
    cout << "NOME: ";
    getline(cin >> ws, nomeP);
    paciente[pos].setNome(nomeP);

    cout << "CPF: ";
    getline(cin >> ws, cpf);
    paciente[pos].setcpf(cpf);

    // Idade do paciente
    cout << "IDADE: ";
    cin >> idadeP;
    while (cin.fail() || idadeP <= 0 || idadeP > 80)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Idade inválida. Digite novamente: ";
        cin >> idadeP;
    }
    cin.ignore();
    paciente[pos].setIdade(idadeP);

    cout << "PESO: ";
    cin >> peso;
    paciente[pos].setPeso(peso);
    cin.ignore();

    // Telefone
    cout << "TELEFONE: ";
    getline(cin, telefone);
    while (telefone.empty() || telefone.length() < 11)
    {
        cout << "Telefone inválido. Digite novamente: ";
        getline(cin >> ws, telefone);
    }
    paciente[pos].setTelefone(telefone);

    cout << "Convênio ou Particular" << endl;
    cout << "(1-Particular, 0-Convenio): ";
    cin >> tipoInt;
    paciente[pos].setPagamento(tipoInt);

    int dia, mes, ano;
    bool dataValida = false;
    while (!dataValida)
    {
        cout << "Insira a data da Consulta: " << endl;
        cout << "Dia: ";
        cin >> dia;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida para o dia. Tente novamente." << endl;
            continue;
        }
        cout << "Mes: ";
        cin >> mes;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida para o mês. Tente novamente." << endl;
            continue;
        }
        cout << "Ano: ";
        cin >> ano;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida para o ano. Tente novamente." << endl;
            continue;
        }
        cin.ignore();

        // Verifica validade do mês
        if (mes < 1 || mes > 12)
        {
            cout << "Mês inválido. Tente novamente." << endl;
            continue;
        }

        // Verifica validade do dia
        int diasNoMes;
        switch (mes)
        {
        case 2:
            // Verifica ano bissexto
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
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
        }

        if (dia < 1 || dia > diasNoMes)
        {
            cout << "Dia inválido para o mês informado. Tente novamente." << endl;
            continue;
        }

        dataValida = true;
    }

    // Formata a data como DD/MM/AAAA
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%02d/%02d/%04d", dia, mes, ano);
    data = buffer;

    cout << "Horário (formato HH:MM): ";
    getline(cin, horario);

    // Validação simples do formato "HH:MM"
    while (horario.length() != 5 || horario[2] != ':' ||
           !isdigit(horario[0]) || !isdigit(horario[1]) ||
           !isdigit(horario[3]) || !isdigit(horario[4]))
    {
        cout << "Horário inválido. Digite novamente (formato HH:MM): ";
        getline(cin >> ws, horario);
    }
    cout << "Tipo de consulta (0=RESTAURACAO, 1=CLAREAMENTO, 2=ORTODONTIA, 3=LIMPEZA, 4=EXAMES_ROTINA): " << endl;
    cin >> tipoConsulta;
    while (cin.fail() || tipoConsulta < 0 || tipoConsulta > 4)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Tipo de consulta inválido. Digite novamente (0-4): ";
        cin >> tipoConsulta;
    }
    cin.ignore();
    consulta[pos].setData(data);
    consulta[pos].setHorario(horario);
    consulta[pos].setTipodeConsulta(static_cast<TipodeConsulta>(tipoConsulta));
    cout << "Paciente cadastrado com sucesso!\n";
}