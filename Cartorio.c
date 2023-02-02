#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em memoria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das strings

int registro()//fun��o respons�vel por cadastrar usu�rios no sistema
{
	//inicio de cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��es do usu�rio
	scanf("%s",cpf);//armazenando strings
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo,"w");//cria o arquivo
	fprintf(file,cpf);//salva o valor da variavel (cpf)
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abrindo arquivo para adicionar informa��o
	fprintf(file,",");//informa��o adicionada (virgula)
	fclose(file);//fechando arquivo
	
	printf("Digite o nome a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s",nome);//armazenando informa��o acima coletada
	
	file = fopen(arquivo,"a");//abrindo arquivo para adicionar informa��o
	fprintf(file,nome);//adicionando informa��o (nome)
	fclose(file);//fechando arquivo
	
	file = fopen(arquivo,"a");//abrindo arquivo para adicionar informa��o
	fprintf(file,",");//adicionando informa��o (virgula)
	fclose(file);//fechando arquivo
	
	printf("Digite o nome o sobrenome a ser cadastrado: ");//coletando inf do usu�rio
	scanf("%s",sobrenome);//armazenando a informa��o acima coletada
	
	file = fopen(arquivo,"a");//abrindo arquivo para adicionar informa��o
	fprintf(file,sobrenome);//salva o valor da variavel (sobrenome)
	fclose(file);//fechando arquivo
	
	file = fopen(arquivo,"a");//abrindo arquivo para adicionar informa��o
	fprintf(file,",");//adicionando informa��o (virgula)
	fclose(file);//fechando arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//coletando inf do usu�rio
	scanf("%s",cargo);//armazenando a informa��o acima coletada
	
	file = fopen(arquivo,"a");//abrindo arquivo para adicionar informa��o adicional
	fprintf(file,cargo);//salva o valor da variavel (cargo)
	fclose(file);//fechando arquivo
	
	system("pause");//pausando o sistema
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Adicionando idioma
	char cpf[40];
	char conteudo[200];
	
	printf("Qual CPF voc� deseja consultar?: ");
	scanf("%s",cpf);
	
	FILE*file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("Foi mal, usu�rio n�o identificado, tente novamente!\n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
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
		printf("O usu�rio n�o cadastrado!\n");
		system("pause");
	}
	
	else(file!=NULL);
	{
		printf("O usu�rio foi deletado com sucesso!\n");
		system("pause");
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo idioma
	int opcao=0; //definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
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
		
			printf ("### Cart�rio da EBAC ###\n\n"); //inicio do menu
			printf ("Escolha a op��o desejada do menu: \n\n");
			printf ("\t1 - Registrar nomes\n");
			printf ("\t2 - Consultar nomes\n");
			printf ("\t3 - Deletar nomes\n\n"); //final do menu
			printf ("\t4 - Sair do sistema\n\n");
			printf ("Escolha uma op��o: ");
		
			scanf ("%d", &opcao); //armazenando escolha do usu�rio
		
			system("cls"); //limpando a tela
		
			switch(opcao)
			{
				case 1:
				registro();//chamada de fun��es
				break;
				
				case 2:
				consultar();//chamada de fun��es
				break;
				
				case 3:
				deletar();//chamada de fun��es
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
							
				default:
				printf("Op��o indispon�vel no momento!\n");
				system("pause");
				break;
			}//fim da sele��o
		}
	}
	
	else
		printf("Senha incorreta");
}
