#include "crud.hpp"
#include <iostream>
#include <limits>
using namespace std;

// Função para limpar a tela 
void limparTela()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void exibirMenu()
{
    cout << "\n=========================================\n";
    cout << "        🏥 OdontoCIa 🏥       \n";
    cout << "=========================================\n";
    cout << " [1] ➝ Agendar Paciente\n";
    cout << " [2] ➝ Editar Paciente\n";
    cout << " [3] ➝ Excluir Paciente\n";
    cout << " [4] ➝ Listar Pacientes\n";
    cout << " [5] ➝ Gerar Relatório de Pacientes\n";
    cout << " [6] ➝ Sair\n";
    cout << "-----------------------------------------\n";
    cout << " Escolha uma opção: ";
}

int main()
{
    int opcao;
    Menu m1;
    m1.carregarPacientes();

    do
    {
        limparTela();
        exibirMenu();
        cin >> opcao;

        // tratamento de erro para entrada inválida 
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcao = -1;
        }

        limparTela();
        switch (opcao)
        {
        case 1:
            cout << "📅 Agendar Paciente\n";
            m1.agendarPaciente();
            break;
        case 2:
            cout << "✏️ Editar Paciente\n";
            m1.editarPaciente();
            break;
        case 3:
            cout << "🗑️ Excluir Paciente\n";
            m1.excluirPaciente();
            break;
        case 4:
            cout << "📋 Lista de Pacientes\n";
            m1.listarPaciente();
            break;
        case 5:
            cout << "🚪 Saindo do sistema...\n";
            break;
        default:
            cout << "❌ Opção inválida! Tente novamente.\n";
        }

        if (opcao != 5)
        {
            cout << "\nPressione ENTER para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opcao != 5);

    return 0;
}
