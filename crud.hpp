#include "Paciente.hpp"
#pragma once

using namespace std;

class Menu
{
protected:
    Paciente paciente[100];
    Consulta consulta[100];
    int totalpac;

public:
    void agendarPaciente();
    void editarPaciente();
    void excluirPaciente ();
    void listarPaciente ();
};

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

            // salvarEmArquivo(); // Implemente esta função conforme necessário
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
void Menu::agendarPaciente()
{
    string nomeP, telefone, data, horario;
    float peso;
    int idadeP, idadeM, tipoInt, consulta;
    bool conv, part;

    // preciso de algo que me permita usar essa função e escrever na posição certa do array de consultas.
    //  Nome do paciente
    cout << "Nome do paciente: ";
    getline(cin >> ws, nomeP);
    if (nomeP.empty())
    {
        nomeP = validarNome(nomeP);
    }

    // Idade do paciente
    cout << "Idade do paciente: ";
    cin >> idadeP;
    while (cin.fail() || idadeP <= 0 || idadeP > 80)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Idade inválida. Digite novamente: ";
        cin >> idadeP;
    }
    cin.ignore();

    // Peso do paciente
    cout << "Peso do paciente: ";
    cin >> peso;
    while (cin.fail() || peso <= 0 || peso > 200)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Peso inválido. Digite novamente: ";
        cin >> peso;
    }
    cin.ignore();

    // Telefone
    cout << "Telefone: ";
    getline(cin, telefone);
    while (telefone.empty() || telefone.length() < 11)
    {
        cout << "Telefone inválido. Digite novamente: ";
        getline(cin >> ws, telefone);
    }
    cout << "Convênio ou Particular " << endl;
    cout << "(1-Particular, 0-Convenio): ";
    cin >> tipoInt;
    if (tipoInt == 0)
    {
        conv = false;
        part = true;
    }
    else if (tipoInt == 1)
    {
        conv = true;
        part = false;
    }
    int dia, mes, ano;
    bool dataValida = false;
    while (!dataValida)
    {
        cout << "Data " << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Ano: ";
        cin >> ano;
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
        getline(cin, horario);
    }
    cout << "Tipo de consulta (0=RESTAURACAO, 1=CLAREAMENTO, 2=ORTODONTIA, 3=LIMPEZA, 4=EXAMES_ROTINA): ";
    cin >> consulta;
    cin.ignore();
}
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
            // "Remove" o paciente sobrescrevendo com um objeto padrão
            paciente[i] = Paciente(); // Supondo que Paciente tem um construtor padrão
            cout << "Paciente excluído com sucesso!\n";
            break;
        }
    }
    if (!encontrado)
    {
        cout << "Paciente não encontrado.\n";
    }
}
void Menu::listarPaciente()
{
    cout << "Lista de pacientes:\n";
    for (int i = 0; i < 100; i++)
    {
        // Supondo que getNome() retorna uma string não vazia para pacientes cadastrados
        if (!paciente[i].getNome().empty())
        {
            cout << "Nome: " << paciente[i].getNome() << endl;
            cout << "CPF: " << paciente[i].getcpf() << endl;
            cout << "Idade: " << paciente[i].getIdade() << endl;
            cout << "Telefone: " << paciente[i].getTelefone() << endl;
            cout << "------------------------" << endl;
        }
    }
}