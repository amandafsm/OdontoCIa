#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#pragma once

using namespace std;

// enum de médico 
// verificar se já tem todos atributos necessários
// gerar relatorio (geral, consultas, medicos)
// fazer diagrama (ultimo)
// verificar se existe polimorfismo 
// metodo para subscrever 


// Classe Pessoa
class Pessoa
{

private:
    string nome;
    int idade;
    string cpf;
    float peso;

public:
    Pessoa(string n = "", int i = 0) : nome(n), idade(i) {}
    void setcpf(string c);
    void setNome(string n);
    void setIdade(int i);
    void setPeso(float p);
    string getcpf() { return cpf; }
    string getNome() { return nome; }
    int getIdade() { return idade; }
    float getPeso(){ return peso;}
};
void Pessoa::setPeso(float p){
    while (cin.fail() || p <= 0 || p > 200)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Peso inválido. Digite novamente: ";
            cin >> p;
        }
        peso = p;
    }
void Pessoa::setcpf(string c)
{
    while (c.length() != 11) {
        cout << "CPF inválido. Exemplo: '12345678911'\nDigite novamente: ";
        getline(cin >> ws, c);
    }

    cpf = c;
}

void Pessoa::setNome(string n)
{
    string temp = "";
    if (n.empty())
    {
        while (n.empty())
        {
            cout << "Nome não pode ser vazio. Digite novamente: ";
            getline(cin >> ws, temp);
            nome = temp;
        }
    }
    else
    {
        nome = n;
    }
}
void Pessoa::setIdade(int i)
{
    if (i > 100)
    {
        cout << "Idade inválida. Digite novamente:";
        cin >> i;
    }
    idade = i;
}

// Classe Paciente
class Paciente : public Pessoa
{
private:
    string telefone;
    bool convenio;
    bool particular;

public:
    Paciente(string n = "", int i = 0, string t = "", bool c = false, bool p = false)
        : Pessoa(n, i), telefone(t), convenio(c), particular(p) {}

    void setTelefone(string t);
    void setPagamento(int i);

    string getTelefone() const { return telefone; }
    bool getConvenio() const { return convenio; }
    bool getParticular() const { return particular; }
};
void Paciente::setTelefone(string t) {
    while (t.length() != 11) {
        cout << "Telefone inválido. Exemplo: '83912345678'\nDigite novamente: ";
        getline(cin >> ws, t);
    }

    telefone = t;
}
void Paciente::setPagamento(int i)
{
    if (i == 0)
    {
        convenio = true;
        particular = false;
    }
    else if (i == 1)
    {
        convenio = false;
        particular = true;
    }
}

// Enumeração para tipos de consulta
enum class TipodeConsulta
{
    RESTAURACAO,
    CLAREAMENTO,
    ORTODONTIA,
    LIMPEZA,
    EXAMES_ROTINA
};

// Classe Consulta
class Consulta
{
private:
    Paciente paciente;
    string medico[5];
    string data;
    string horario;
    TipodeConsulta tipo;
    string parecer;
    string dataProcedimento;

public:
    Consulta(Paciente p = Paciente(), string d = "", string h = "",
             TipodeConsulta t = TipodeConsulta::RESTAURACAO, string pr = "", string dP = "")
        : paciente(p), data(d), horario(h), tipo(t), parecer(pr), dataProcedimento(dP) {}

    void setPaciente(const Paciente &p) { paciente = p; }
    void setData(const string &d) { data = d; }
    void setHorario(const string &h) { horario = h; }
    void setTipodeConsulta(TipodeConsulta t) { tipo = t; }
    void setTipodeConsulta(const string &t) { tipo = stringToTipodeConsulta(t); }
    void setParecer(const string &pr) { parecer = pr; }
    void setDataProcedimento(const string &dP) { dataProcedimento = dP; }

    Paciente getPaciente() const { return paciente; }
    string getData() const { return data; }
    string getHorario() const { return horario; }
    TipodeConsulta getTipodeConsulta() const { return tipo; }
    string getParecer() const { return parecer; }
    string getDataProcedimento() const { return dataProcedimento; }

    static TipodeConsulta stringToTipodeConsulta(const string &t)
    {
        if (t == "RESTAURACAO")
            return TipodeConsulta::RESTAURACAO;
        if (t == "CLAREAMENTO")
            return TipodeConsulta::CLAREAMENTO;
        if (t == "ORTODONTIA")
            return TipodeConsulta::ORTODONTIA;
        if (t == "LIMPEZA")
            return TipodeConsulta::LIMPEZA;
        if (t == "EXAMES_ROTINA")
            return TipodeConsulta::EXAMES_ROTINA;
        return TipodeConsulta::RESTAURACAO;
    }
};