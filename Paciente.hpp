#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

#pragma once

using namespace std;

class Pessoa
{
protected:
    string nome;
    int idade;
    string cpf;
    float peso;

public:
    Pessoa(string n = "", int i = 0) : nome(n), idade(i) {}
    virtual void setcpf(string c) = 0;
    virtual void setNome(string n) = 0;
    virtual void setIdade(int i) = 0;
    virtual void setPeso(float p) = 0;
    string getcpf() { return cpf; }
    string getNome() { return nome; }
    int getIdade() { return idade; }
    float getPeso() { return peso; }
};

class Paciente : public Pessoa
{
protected:
    string telefone;
    bool convenio;
    bool particular;

public:
    Paciente(string n = "", int i = 0, string t = "", bool c = false, bool p = false)
        : Pessoa(n, i), telefone(t), convenio(c), particular(p) {}

    void setPeso(float p);
    void setcpf(string c);
    void setNome(string n);
    void setIdade(int i);
    void setTelefone(string t);
    void setPagamento(int i);

    string getTelefone() const { return telefone; }
    int getPagamento();
    string getPagamentoStr();
    bool getParticular() const { return particular; }
};
void Paciente::setPeso(float p)
{
    while (cin.fail() || p <= 0 || p > 200)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Peso inválido. Exemplo: '0 até 200'" << "Digite novamente: ";
        cin >> p;
    }
    peso = p;
}
void Paciente::setcpf(string c)
{
    while (c.length() != 11)
    {
        cout << "CPF inválido. Exemplo: '12345678911'\nDigite novamente: ";
        getline(cin >> ws, c);
    }

    cpf = c;
}

void Paciente::setNome(string n)
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
void Paciente::setIdade(int i)
{
    if (i > 100)
    {
        cout << "Idade inválida. Digite novamente:";
        cin >> i;
    }
    idade = i;
}
string Paciente::getPagamentoStr()
{
    if (convenio == true)
    {
        return "Convênio";
    }
    else
    {
        return "Particular";
    }
}
int Paciente::getPagamento()
{
    if (convenio == true)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void Paciente::setTelefone(string t)
{
    while (t.length() != 11)
    {
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

class Medico: public Pessoa{
    protected:
    string crm;
    string espec;
    string telefone;
    public:
    Medico(string n, int i, string c, string t, string crm, string e); 
    void setPeso(float p) { peso = p;}
    void setcpf(string c);
    void setNome(string n);
    void setIdade(int i);
    void setTelefone(string t);
    void setCrm(string c){ crm = c; }
    void setEspec(string e){ espec = e; }
    string getTelefone() const { return telefone; }
    string getCrm(){ return crm; }
    string getEspec(){ return espec; }
};
Medico::Medico(string n, int i, string c, string t, string crm, string e){
    setNome(n);
    setIdade(i);
    setcpf(c);
    setTelefone(t);
    setCrm(crm);
    setEspec(e);
}
void Medico::setcpf(string c)
{
    while (c.length() != 11)
    {
        cout << "CPF inválido. Exemplo: '12345678911'\nDigite novamente: ";
        getline(cin >> ws, c);
    }

    cpf = c;
}
void Medico::setTelefone(string t)
{
    while (t.length() != 11)
    {
        cout << "Telefone inválido. Exemplo: '83912345678'\nDigite novamente: ";
        getline(cin >> ws, t);
    }

    telefone = t;
}
void Medico::setNome(string n)
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
void Medico::setIdade(int i)
{
    if (i > 100)
    {
        cout << "Idade inválida. Digite novamente:";
        cin >> i;
    }
    idade = i;
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

class Consulta
{
protected:
    Paciente paciente;
    string medico[5] = {"Mariana Lopes", "Ricardo Nogueira", "Camila Ferreira", "André Carvalho", "Beatriz Mendes"};
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
    int getConsulta() { return static_cast<int>(tipo); }
    string getParecer() const { return parecer; }
    string getDataProcedimento() const { return dataProcedimento; }
    string getmedico(int i);
    string corrigirHora(string h);

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

string Consulta::corrigirHora(string h)
{
    string hora = h.substr(0, 2) + ":" +
                  h.substr(2, 2);
    return hora;
}
string Consulta::getmedico(int i) { return medico[i]; }