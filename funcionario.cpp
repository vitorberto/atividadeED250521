#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// criando struct de funcionario
struct Funcionario
{
	int prontuario;
	string nome;
	double salario;
	struct Funcionario *prox;
	struct Funcionario *ante;
};

Funcionario *init()
{
	return NULL;
}

Funcionario *inserir(Funcionario *funcionario, int prontuario, string nome, double salario)
{
	Funcionario *novo = new Funcionario();
	novo->prontuario = prontuario;
	novo->nome = nome;
	novo->salario = salario;
	novo->prox = funcionario;

	// Guardando o ponteiro do novo funcionario na estrutura do funcionario antigo
	if (funcionario != NULL && funcionario->ante != NULL)
		funcionario->ante = novo;

	return novo;
}

Funcionario *pesquisar(Funcionario *funcionario, int prontuario)
{
	Funcionario *aux;
	aux = funcionario;
	while (aux != NULL && aux->prontuario != prontuario)
	{
		aux = aux->prox;
	}
	return aux;
}

Funcionario *remover(Funcionario *funcionario, int prontuario)
{
	Funcionario *aux;
	aux = pesquisar(funcionario, prontuario);
	if (aux == NULL)
	{
		cout << "ERRO! O prontuário digitado não foi encontrado" << endl;
		return funcionario;
	}

	if (aux->ante != NULL)
		aux->ante->prox = aux->prox;
	if (aux->prox != NULL)
		aux->prox->ante = aux->ante;
	funcionario = aux->prox;

	free(aux);

	return funcionario;
}

void listar(Funcionario *funcionario)
{
	Funcionario *aux;
	aux = funcionario;

	cout << "Listando Funcionarios: " << endl;

	while (aux != NULL)
	{
		cout << "Prontuario: " << aux->prontuario << "\t | Nome: " << aux->nome << " \t | Salário: " << aux->salario << endl;
		aux = aux->prox;
	}
	cout << "--------------------" << endl;
}

int main(int argc, char **argv)
{
	int escolha;
	Funcionario *funcionarios = init();

	listar(funcionarios);

	do
	{
		cout << "Escolha a ação que deseja executar:" << endl;
		cout << "0. SAIR" << endl;
		cout << "1. Inserir" << endl;
		cout << "2. Excluir" << endl;
		cout << "3. Pesquisar" << endl;
		cout << "4. Listar" << endl;

		cin >> escolha;

		if (escolha == 1)
		{
			string nome;
			int prontuario;
			double salario;

			bool prontuarioIgual;

			cout << "--------------------" << endl
					 << "Inserir um funcionário:" << endl;
			cout << "Digite o nome do funcionário: ";
			cin >> nome;

			do
			{
				prontuarioIgual = false;
				cout << "Digite o prontuário do funcionário: ";
				cin >> prontuario;

				Funcionario *encontrado = pesquisar(funcionarios, prontuario);
				if (encontrado != NULL)
				{
					cout << "ERRO! O prontuário do funcionário deve ser único e o digitado já está cadastrado no sistema" << endl;
					prontuarioIgual = true;
				}
			} while (prontuarioIgual);

			cout << "Digite o salário do funcionário: ";
			cin >> salario;

			funcionarios = inserir(funcionarios, prontuario, nome, salario);
		}
		else if (escolha == 2)
		{
			int prontuario;

			cout << "--------------------" << endl
					 << "Digite o prontuário do funcionário que deseja excluir: ";
			cin >> prontuario;
			funcionarios = remover(funcionarios, prontuario);
		}
		else if (escolha == 3)
		{
			int prontuario;
			Funcionario *aux;

			cout << "--------------------" << endl
					 << "Digite o prontuário do funcionário que deseja pesquisar: ";
			cin >> prontuario;

			aux = pesquisar(funcionarios, prontuario);

			if (aux != NULL)
			{
				cout << "Resultado da pesquisa: " << endl;
				cout << "Prontuario: " << aux->prontuario << "\t | Nome: " << aux->nome << " \t | Salário: " << aux->salario << endl;
			}
			else
			{
				cout << "ERRO! O prontuário digitado não foi encontrado" << endl;
			}
		}
		else
		{
			listar(funcionarios);
		}

	} while (escolha != 0);
}