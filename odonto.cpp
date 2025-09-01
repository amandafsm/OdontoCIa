#include "crud.hpp"
#include "editar.hpp"
#include "excluir.hpp"
#include "agendar.hpp"
#include "listar.hpp"
#include "carregar.hpp"
#include "salvar.hpp"
#include "relatorio.hpp"

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
    cout << " [5] ➝ Listar Médicos\n";
    cout << " [6] ➝ Gerar Relatório\n";
    cout << " [7] ➝ Sair\n";
    cout << "-----------------------------------------\n";
    cout << " Escolha uma opção: ";
}

int main()
{
    int opcao;
    Menu m1;
    m1.carregarPrograma();

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
            cout << "📋 Lista de Médicos\n";
            m1.listarMedico();
            break;     
        case 6:
            cout << "📋 Gerar Relatório\n";
            m1.relatorioPaciente();
            break;
        case 7:
            cout << "🚪 Saindo do sistema...\n";
            m1.salvarPrograma();
            break;
        default:
            cout << "❌ Opção inválida! Tente novamente.\n";
        }

        if (opcao != 7)
        {
            cout << "\nPressione ENTER para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opcao != 7);

    return 0;
}
