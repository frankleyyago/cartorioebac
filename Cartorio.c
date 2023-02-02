#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memoria
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings

int registro()//função responsável por cadastrar usuários no sistema
{
	//inicio de criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informações do usuário
	scanf("%s",cpf);//armazenando strings
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo,"w");//cria o arquivo
	fprintf(file,cpf);//salva o valor da variavel (cpf)
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abrindo arquivo para adicionar informação
	fprintf(file,",");//informação adicionada (virgula)
	fclose(file);//fechando arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informação do usuário
	scanf("%s",nome);//armazenando informação acima coletada
	
	file = fopen(arquivo,"a");//abrindo arquivo para adicionar informação
	fprintf(file,nome);//adicionando informação (nome)
	fclose(file);//fechando arquivo
	
	file = fopen(arquivo,"a");//abrindo arquivo para adicionar informação
	fprintf(file,",");//adicionando informação (virgula)
	fclose(file);//fechando arquivo
	
	printf("Digite o nome o sobrenome a ser cadastrado: ");//coletando inf do usuário
	scanf("%s",sobrenome);//armazenando a informação acima coletada
	
	file = fopen(arquivo,"a");//abrindo arquivo para adicionar informação
	fprintf(file,sobrenome);//salva o valor da variavel (sobrenome)
	fclose(file);//fechando arquivo
	
	file = fopen(arquivo,"a");//abrindo arquivo para adicionar informação
	fprintf(file,",");//adicionando informação (virgula)
	fclose(file);//fechando arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando inf do usuário
	scanf("%s",cargo);//armazenando a informação acima coletada
	
	file = fopen(arquivo,"a");//abrindo arquivo para adicionar informação adicional
	fprintf(file,cargo);//salva o valor da variavel (cargo)
	fclose(file);//fechando arquivo
	
	system("pause");//pausando o sistema
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Adicionando idioma
	char cpf[40];
	char conteudo[200];
	
	printf("Qual CPF você deseja consultar?: ");
	scanf("%s",cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("Foi mal, usuário não identificado, tente novamente!\n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL);
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("O usuário não cadastrado!\n");
		system("pause");
	}
	
	else(file!=NULL);
	{
		printf("O usuário foi deletado com sucesso!\n");
		system("pause");
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo idioma
	int opcao=0; //definindo variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrado\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao=strcmp(senhadigitada,"admin");
	
	if(comparacao==0)
	{	
		system("cls");
		for(laco=1;laco=1;)
		{
		
			system("cls");//limpar tela
			
			setlocale(LC_ALL, "Portuguese"); //definindo idioma
		
			printf ("### Cartório da EBAC ###\n\n"); //inicio do menu
			printf ("Escolha a opção desejada do menu: \n\n");
			printf ("\t1 - Registrar nomes\n");
			printf ("\t2 - Consultar nomes\n");
			printf ("\t3 - Deletar nomes\n\n"); //final do menu
			printf ("\t4 - Sair do sistema\n\n");
			printf ("Escolha uma opção: ");
		
			scanf ("%d", &opcao); //armazenando escolha do usuário
		
			system("cls"); //limpando a tela
		
			switch(opcao)
			{
				case 1:
				registro();//chamada de funções
				break;
				
				case 2:
				consultar();//chamada de funções
				break;
				
				case 3:
				deletar();//chamada de funções
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
							
				default:
				printf("Opção indisponível no momento!\n");
				system("pause");
				break;
			}//fim da seleção
		}
	}
	
	else
		printf("Senha incorreta");
}
