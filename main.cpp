#include "crud.hpp"
using namespace std;

int main()
{
    int opcao;
    Menu m1;

    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Agendar Paciente\n";
        cout << "2. Editar Paciente\n";
        cout << "3. Excluir Paciente\n";
        cout << "4. Listar Pacientes\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            m1.agendarPaciente();
            break;
        case 2:
            m1.editarPaciente();
            break;
        case 3:
            m1.excluirPaciente();
            break;
        case 4:
            m1.listarPaciente();
            break;
        case 5:
            cout << "Saindo...\n";
            break;
        default:
            cout << "Opção inválida!\n";
        }
    } while (opcao != 5);

    return 0;
}