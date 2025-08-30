#include "Paciente.hpp"
#include "crud.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>
#pragma once

using namespace std;

void Menu::carregarPrograma()
{
    ifstream arquivo("./backup.txt");
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    string linha;
    while (getline(arquivo, linha))
    {
        // --- Pega a posição livre ---
        int pos = acharPosicao();
        stringstream ss(linha);
        string cpf, nome, pesoS, idadeSt, conv, telefone;
        string data, horario, tipoconsulta;
        int idade = 0;
        float peso = 0.0;
        int convenio = 0;
        int cons = 0;

        getline(ss, nome, ';');
        getline(ss, cpf, ';');
        getline(ss, idadeSt, ';');
        getline(ss, telefone, ';');
        getline(ss, pesoS, ';');
        getline(ss, conv, ';');
        getline(ss, data, ';');
        getline(ss, horario, ';');
        getline(ss, tipoconsulta);

        try
        {
            idade = stoi(idadeSt);
            peso = stof(pesoS);
            convenio = stoi(conv);
            cons = stoi(tipoconsulta);
        }
        catch (...)
        {
            cout << "Erro na conversão da linha: " << linha << endl;
            continue; // pula linha inválida
        }

        // --- Atualiza paciente no vetor ---
        paciente[pos].setNome(nome);
        paciente[pos].setcpf(cpf);
        paciente[pos].setIdade(idade);
        paciente[pos].setTelefone(telefone);
        paciente[pos].setPeso(peso);
        paciente[pos].setPagamento(convenio);
        consulta[pos].setHorario(horario);
        consulta[pos].setData(data);
        consulta[pos].setTipodeConsulta(static_cast<TipodeConsulta>(cons));
    }

    arquivo.close();
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