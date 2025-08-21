#include "Paciente.hpp"
#include <fstream>
#include <sstream>
#pragma once

using namespace std;

class Menu
{
protected:
    Paciente paciente[100];
    Consulta consulta[100];
    int totalpac;

public:
    void carregarPacientes();
    void agendarPaciente();
    void editarPaciente();
    void excluirPaciente();
    void listarPaciente();
    int acharPosicao();
};
void Menu::carregarPacientes()
{

    ifstream arquivo("backup.txt");
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo!" << endl;
    }

    string linha;
    while (getline(arquivo, linha))
    { // lê linha por linha
        stringstream ss(linha);
        int pos = acharPosicao();
        string cpf, nome, idadeStr, conv, telefone;

        getline(ss, nome, ';');
        getline(ss, cpf, ';');
        getline(ss, idadeStr, ';');
        getline(ss, telefone, ';');
        getline(ss, conv, ';');

        int idade = stoi(idadeStr); // converter string para int.
        int pag = stoi(conv);

        paciente[pos].setNome(nome);
        paciente[pos].setcpf(cpf);
        paciente[pos].setIdade(idade);
        paciente[pos].setTelefone(telefone);
        // Falta colocar as variáveis e as funções de salvar em consulta.
    }
}
int Menu::acharPosicao()
{
    for (int i = 0; i < 100; i++)
    {
        if (paciente[i].getNome() == "")
        {
            return i;
        }
    }
    // Se não houver posição disponível, retorna sempre a última posição
    return 99;
}

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
    string nomeP, telefone, data, horario, cpf;
    float peso;
    int idadeP, idadeM, tipoInt, consulta;
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

    // Peso do paciente
    //    cout << "PESO: ";
    //    cin >> peso;
    //    while (cin.fail() || peso <= 0 || peso > 200)
    //    {
    //        cin.clear();
    //        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //        cout << "Peso inválido. Digite novamente: ";
    //        cin >> peso;
    //    }
    //    cin.ignore();

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
        getline(cin >> ws, horario);
    }
    cout << "Tipo de consulta (0=RESTAURACAO, 1=CLAREAMENTO, 2=ORTODONTIA, 3=LIMPEZA, 4=EXAMES_ROTINA): " << endl;
    cin >> consulta;
    cin.ignore();

    // implementa as funções de setar as variaveis de consulta, pode fazer igual eu fiz, a função achar posição vai indicar o primeiro indicie de paciente vazio.
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
    bool encontrado = false;
    int cond = 0;
    cout << "Listar todos[0]" << endl
         << "Listar apenas um paciente[1]" << endl;
    cin >> cond;
    if (cond == 0)
    {
        cout << "Lista de pacientes:\n";
        for (int i = 0; i < 100; i++)
        {
            // Supondo que getNome() retorna uma string não vazia para pacientes cadastrados
            if (!paciente[i].getNome().empty())
            {
                encontrado = true;
                cout << "Nome: " << paciente[i].getNome() << endl;
                cout << "CPF: " << paciente[i].getcpf() << endl;
                cout << "Idade: " << paciente[i].getIdade() << endl;
                cout << "Telefone: " << paciente[i].getTelefone() << endl;
                cout << "------------------------" << endl;
            }
        }
    }
    else if (cond == 1)
    {
        cout << "Digite o CPF do Paciente: " << endl;
        string cpfbusca = "";
        getline(cin >> ws, cpfbusca);
        for (int i = 0; i < 100; i++)
        {
            if (paciente[i].getcpf() == cpfbusca)
            {
                cout << "Nome: " << paciente[i].getNome() << endl;
                cout << "CPF: " << paciente[i].getcpf() << endl;
                cout << "Idade: " << paciente[i].getIdade() << endl;
                cout << "Telefone: " << paciente[i].getTelefone() << endl;
                cout << "------------------------" << endl;
            }
            else
            {
                continue;
            }
        }
    }
}
