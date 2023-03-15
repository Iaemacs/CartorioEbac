#include <stdio.h> // biblioteca de comunicação com o usuario 
#include <stdlib.h> // biblioteca de alocação de espaço em memória 
#include <locale.h> // biblioteca de alocação texto por região
#include <string.h> // biblioteca responsavel por cuidar das strings

int registrar() //Função de registro de usuários no sistema
{
	//inicio de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de variaveis/string
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);//coleta de informação 
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strings
	

	

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);

	
	FILE *file; //cria o arquivo no banco de dados
	file = fopen(arquivo,"w"); //cria o arquivo na pasta onde salvou o sistema
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);

	


	file = fopen(arquivo, "a");// a se refere a atualizar o arquivo em que vai ser aberto
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);

	

	printf("Digite o sobrenome a ser cadastrado: ");

	scanf("%s", sobrenome);

	

	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	

	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);

	

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);

	

	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);

	

	system("pause");
	
	

}



int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Cpf não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}



int deletar()
{
	char cpf[40];
	
	printf ("Digite o cpf do usuário a ser deletado: ");
	scanf ("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file != NULL)
	{
		fclose(file);
		remove(cpf);
		printf("\n");
		printf(" Usuário deletado com sucesso!. \n\n");
		system("pause");
		
	}
	
	else
	{
		printf("\n");
		printf(" O usuário não se encontra no sistema!. \n\n");
		system("pause");
	}
	

}



int main ()
{
	int opcao=0; // Definindo variáveis 
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
		printf("###Cartório da EBAC###\n\n"); // Inicio do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); // Fim do menu
	
		scanf("%d" , &opcao);  //armazenar na variável, escolha do usuario
	
		system("cls");  //limpar a tela
		
		
		switch(opcao)
		{
			case 1: 	
			registrar();
			break;
			
			case 2:  
			consultar();
			break;
			
			case 3: 
			deletar();
			break;
			
			case 4:
			Printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
			
			default: 
			printf("Essa opção não está disponivel\n");
			system("pause");
			break;
			
		}
			
	}
}

