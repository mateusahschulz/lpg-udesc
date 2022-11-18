#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//declaração das funções usadas no programa
void menuPrincipal();
void menuAluno();
void menuNotas();
void menuRelatorio();
void cadastrarAluno();
void consultarAluno();
void excluirAluno();
void alterarAluno();
void relatorioAluno();
void incluirNota();
void alterarNota();
void excluirNota();
void consultarNota();
void relatorioNotas();
void relatorioMedia();


//definição das structs e declaração
typedef struct Aluno{
	int idAluno;
	char nomeAluno[50];
	int deleted;
	int qtdNotasAluno;
}Aluno;

typedef struct Nota{
	int idAluno;
	int idNota;
	float valorNota;
	int idConsulta;
}Nota;

int qtdAlunos = 0;
int qtdNotas = 0;
Aluno alunos[10];
Nota notas[30];

//funções: 
int main(){
	printf("BEM VINDOS AO SISTEMA UDESC\n");
	menuPrincipal();
	
	return 0;
}

void menuPrincipal(){
	int opcao;
	
	do{
		printf("\nMENU PRINCIPAL\n");
		printf("1 - Aluno\n2 - Notas\n3 - Relatorio\n4 - Sair\nEscolha uma opcao: ");
		scanf("%d", &opcao);
		getchar();
		switch(opcao){
			case 1:
				menuAluno();
				break;
			case 2:
				menuNotas();
				break;
			case 3:
				menuRelatorio();
				break;
			case 4:
				printf("\nObrigado por usar!\n");
				break;
			default: 
				printf("Por favor, coloque um entrada valida\n");
		}	
	}while(opcao != 4);
}

void menuAluno(){
	int opcao;
	do{
		printf("\nMENU - ALUNO:\n");
		printf("1 - Cadastrar\n2 - Consultar por Id\n3 - Excluir\n4 - Alterar por Id\n5 - Relatorio\n6 - Voltar\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		getchar();
		switch(opcao){
			case 1:
				cadastrarAluno();
				break;
			case 2:
				consultarAluno();
				break;
			case 3:
				excluirAluno();
				break;
			case 4:
				alterarAluno();
				break;
			case 5:
				relatorioAluno();
				break;	
			case 6:
				break;	
			default: 
				printf("Por favor, coloque um entrada valida\n");
		}	
	}while(opcao != 6);
}

void menuNotas(){
	int opcao;
	printf("\nMENU - NOTAS:\n");
	do{
		printf("\n1 - Incluir nota do aluno\n2 - Alterar nota do aluno\n3 - Excluir nota do aluno\n");
		printf("4 - Consultar notas do aluno\n5 - Voltar\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		getchar();
		switch(opcao){
			case 1:
				incluirNota();
				break;
			case 2:
				alterarNota();
				break;
			case 3:
				excluirNota();
				break;
			case 4:
				consultarNota();
;				break;
			case 5:
				break;		
			default: 
				printf("Por favor, coloque um entrada valida\n");
		}	
	}while(opcao != 5);
}

void menuRelatorio(){
	int opcao;
	do{
		printf("\nMENU - RELATORIOS:\n");
		printf("1 - Relatorio de notas\n2 - Relatorio de medias\n3 - Voltar\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				relatorioNotas();
				break;
			case 2:
				relatorioMedia();
				break;
			case 3:
				break;		
			default: 
				printf("Por favor, coloque um entrada valida\n");
		}	
	}while(opcao != 3);
}

void cadastrarAluno(){
	alunos[qtdAlunos].idAluno = qtdAlunos + 1;
	alunos[qtdAlunos].deleted = 0;
	printf("\nCodigo do aluno: %d\n", alunos[qtdAlunos].idAluno);
	printf("Digite o nome do aluno: ");
	fgets(alunos[qtdAlunos].nomeAluno, 50, stdin);
	alunos[qtdAlunos].nomeAluno[strlen(alunos[qtdAlunos].nomeAluno) - 1] = '\0';
	while(strlen(alunos[qtdAlunos].nomeAluno) <= 3){
		printf("Digite um nome valido: ");
		fgets(alunos[qtdAlunos].nomeAluno, 50, stdin);
		alunos[qtdAlunos].nomeAluno[strlen(alunos[qtdAlunos].nomeAluno) - 1] = '\0';
	}
	qtdAlunos++;
	
}

void consultarAluno(){ 
	int i, id;
	printf("\nCodigo do aluno: ");
	scanf("%d", &id);
	for(i = 0; i < qtdAlunos; i++){
		if((alunos[i].idAluno == id) && (alunos[i].deleted == 0)){
			printf("Aluno: %s\n", alunos[i].nomeAluno);
		}else if((alunos[i].deleted == 1) && (alunos[i].idAluno == id)){
			printf("\nAluno nao existe na base!\n");
		}	
	}
	if(id <= 0 || id > qtdAlunos){
		printf("\nNao existe o Id na base de alunos!\n");
	}
}

void excluirAluno(){
	int id, i;
	char confirma;
	printf("\nDigite o Id do aluno: ");
	scanf("%d", &id);
	getchar();
	for(i = 0; i < qtdAlunos; i++){
		if((alunos[i].deleted == 0) && (alunos[i].idAluno == id)){
			printf("\nCodigo do aluno: %d\n", alunos[i].idAluno);
			printf("Aluno: %s\n", alunos[i].nomeAluno);
			printf("Confirmar exclusao? [S]im ou [N]ao\n");
			confirma = getchar();
			confirma = toupper(confirma);
			if (confirma == 'S'){
				alunos[i].deleted = 1;
				printf("\nAluno deletado!\n");
			}else if(confirma == 'N'){
				printf("\nOperacao cancelada\n");
			}
		}else if((alunos[i].deleted == 1) && (alunos[i].idAluno == id)){
			printf("\nAluno nao existe na base!\n");
		}
	}
	if(id <= 0 || id > qtdAlunos){
		printf("\nNao existe o Id na base de alunos!\n");
	}
}

void alterarAluno(){
	int i, id;
	char novoNome[50];
	char confirma;
	printf("\nDigite o Id do Aluno: ");
	scanf("%d", &id);
	getchar();
	for(i = 0; i < qtdAlunos; i++){
		if((alunos[i].deleted == 0) && (alunos[i].idAluno == id)){
			printf("\nCodigo do aluno: %d\n", alunos[i].idAluno);
			printf("Aluno: %s\n", alunos[i].nomeAluno);
			printf("Novo nome: ");
			fgets(novoNome, 50, stdin);
			while(strlen(novoNome) <= 3){
				printf("Digite um nome valido: ");
				fgets(novoNome, 50, stdin);
			}	
			printf("Confirmar alteracao? [S]im ou [N]ao\n");
			confirma = getchar();
			confirma = toupper(confirma);
			if(confirma == 'S'){
				strcpy(alunos[i].nomeAluno, novoNome);
				alunos[i].nomeAluno[strlen(alunos[i].nomeAluno) - 1] = '\0';
				printf("\nNome mudado com sucesso!\n");
			}else if(confirma == 'N'){
				printf("\nOperacao cancelada!\n");
			}
		}else if((alunos[i].deleted == 1) && (alunos[i].idAluno == id)){
			printf("\nAluno nao existe na base!\n");
		}
	}
	if(id <= 0 || id > qtdAlunos){
		printf("\nAluno nao existe na base!\n");
	}
}

void relatorioAluno(){
	
	//Utilizado para mostrar a data e hora que a tabela foi acessada.
	struct tm *dataHoraAtual;
	time_t tempo;
	time(&tempo);
	dataHoraAtual = localtime(&tempo);
	
	
	int i, j;
	char x = 'x';
	printf("\n+-------------------------------------------------------------------------+\n");
	printf("|\t\t\tRelatorio de alunos\t\t\t\t  |\n");
	printf("+------+------------------------------------------------------------------+\n");
	printf("|  ID  |  Nome\t\t\t\t\t\t    |\tExcluido  |\n");
	printf("+------+----------------------------------------------------+-------------+\n");
	for(i = 0; i < qtdAlunos; i++){
		printf("|   %d  |", alunos[i].idAluno);
		printf("  %-50s", alunos[i].nomeAluno);
		if(alunos[i].deleted == 1){
			printf("|   %-10c", x);	
		}else{
			printf("|             ");
		}
		printf("|\n");
		printf("+------+----------------------------------------------------+-------------+\n");
	}
	printf("\n______________________________________________Gerado em %d/%d/%d as %d:%d\n", dataHoraAtual -> tm_mday, dataHoraAtual -> tm_mon + 1, dataHoraAtual -> tm_year + 1900, dataHoraAtual -> tm_hour, dataHoraAtual -> tm_min);
}
	
void incluirNota(){
	int id, i, cont;
	printf("Digite o Id do aluno: ");
	scanf("%d", &id);
	getchar();
	for(i = 0; i < qtdAlunos; i++){
		if((alunos[i].deleted == 0) && (alunos[i].idAluno == id) && (alunos[i].qtdNotasAluno < 3)){
			printf("\nCodigo do aluno: %d\n", alunos[i].idAluno);
			printf("Nome do aluno: %s\n", alunos[i].nomeAluno);
			cont = 1;
			for(alunos[i].qtdNotasAluno = 0; alunos[i].qtdNotasAluno < 3; alunos[i].qtdNotasAluno++){			
				printf("Digite a nota %d do aluno: ", alunos[i].qtdNotasAluno + 1);
				notas[qtdNotas].idAluno = alunos[i].idAluno;
				scanf("%f", &notas[qtdNotas].valorNota);
				notas[qtdNotas].idNota = qtdNotas + 1;
				notas[qtdNotas].idConsulta = cont;
				while(notas[qtdNotas].valorNota < 0 || notas[qtdNotas].valorNota > 10){
					printf("Digite um valor entre 0 e 10: ");
					scanf("%f", &notas[qtdNotas].valorNota);
				}
				qtdNotas++;	
				cont++;
			}
		}else if((alunos[i].deleted == 1) && (alunos[i].idAluno == id)){
			printf("\nAluno nao existe na base!\n");
		}
		else if((alunos[i].deleted == 0) && (alunos[i].idAluno == id) && (alunos[i].qtdNotasAluno >= 3)){
			printf("\nAluno com todas as notas cadastradas!\n");
		}
	}
	if (id > qtdAlunos || id <= 0){
		printf("\nAlunos nao existe na base!\n");
	}
}

void alterarNota(){
	int i, id, j, opcao;
	printf("Digite o Id do aluno: ");
	scanf("%d", &id);
	getchar();
	for(i = 0; i < qtdAlunos; i++){
		if((alunos[i].deleted == 0) && (alunos[i].idAluno == id) && alunos[i].qtdNotasAluno != 0){
			printf("\nCodigo do aluno: %d\n", alunos[i].idAluno);
			printf("Nome do aluno: %s\n", alunos[i].nomeAluno);
			for(j = 0; j < qtdNotas; j++){
				if((notas[j].idAluno == id)){
					printf("Nota[%d]: %.2f\n", notas[j].idConsulta, notas[j].valorNota);
				}
			}
			printf("Qual nota deseja alterar? ");
			scanf("%d", &opcao);
			while(opcao < 1 || opcao > 3){
				printf("Nota nao existe! Digitar novamente :");
				scanf("%d", &opcao);
			}
			for(j = 0; j < qtdNotas; j++){
				if((notas[j].idAluno == id) && (notas[j].idConsulta == opcao)){
					printf("Digite a nova nota: ");
					scanf("%f", &notas[j].valorNota);
				}
			}
		}else if((alunos[i].deleted == 1) && (alunos[i].idAluno == id)){
			printf("\nAluno nao existe na base!\n");
		}else if((alunos[i].deleted == 0) && (alunos[i].idAluno == id) && (alunos[i].qtdNotasAluno == 0)){
			printf("\nAluno nao possui notas cadastradas!\n");
		} 
	}
	if(id > qtdAlunos || id <= 0){
		printf("\nAluno nao existe na base!\n");
	}    
}

void excluirNota(){
	int i, id, j, opcao;
	printf("Digite o Id do aluno: ");
	scanf("%d", &id);
	getchar();
	for(i = 0; i < qtdAlunos; i++){
		if((alunos[i].deleted == 0) && (alunos[i].idAluno == id) && alunos[i].qtdNotasAluno != 0){
			printf("\nCodigo do aluno: %d\n", alunos[i].idAluno);
			printf("Nome do aluno: %s\n", alunos[i].nomeAluno);
			for(j = 0; j < qtdNotas; j++){
				if((notas[j].idAluno == id)){
					printf("Nota[%d]: %.2f\n", notas[j].idConsulta, notas[j].valorNota);
				}
			}
			printf("Qual nota deseja excluir? ");
			scanf("%d", &opcao);
			while(opcao < 1 || opcao > 3){
				printf("Nota nao existe! Digitar novamente: ");
				scanf("%d", &opcao);
			}
			for(j = 0; j < qtdNotas; j++){
				if((notas[j].idAluno == id) && (notas[j].idConsulta == opcao)){
					notas[j].valorNota = 0;
				}
			}
		}else if((alunos[i].deleted == 1) && (alunos[i].idAluno == id)){
			printf("\nAluno nao existe na base!\n");
		}else if((alunos[i].deleted == 0) && (alunos[i].idAluno == id) && (alunos[i].qtdNotasAluno == 0)){
			printf("\nAluno nao possui notas cadastradas!\n");
		} 
	}
	if(id > qtdAlunos || id <= 0){
		printf("\nAluno nao existe na base!\n");
	}    	
}

void consultarNota(){
	int i, id, j;
	printf("Digite o Id do aluno: ");
	scanf("%d", &id);
	getchar();
	for(i = 0; i < qtdAlunos; i++){
		if((alunos[i].deleted == 0) && (alunos[i].idAluno == id) && alunos[i].qtdNotasAluno != 0){
			printf("\nCodigo do aluno: %d\n", alunos[i].idAluno);
			printf("Nome do aluno: %s\n", alunos[i].nomeAluno);
			for(j = 0; j < qtdNotas; j++){
				if((notas[j].idAluno == id)){
					printf("Nota[%d]: %.2f\n", notas[j].idConsulta, notas[j].valorNota);
				}
			}
		}else if((alunos[i].deleted == 1) && (alunos[i].idAluno == id)){
			printf("\nAluno nao existe na base!\n");
		}else if((alunos[i].deleted == 0) && (alunos[i].idAluno == id) && (alunos[i].qtdNotasAluno == 0)){
			printf("\nAluno nao ha notas cadastradas!\n");
		} 
	}
	if(id > qtdAlunos || id <= 0){
		printf("\nAluno nao existe na base!\n");
	}
}


void relatorioNotas(){   

	//Utilizado para mostrar a data e hora que a tabela foi acessada.
	struct tm *dataHoraAtual;
	time_t tempo;
	time(&tempo);
	dataHoraAtual = localtime(&tempo);
	
	
	int i, j;
	printf("\n+-----------------------------------------------------------------------------------+\n");
	printf("|\t\t\t\tRelatorio de notas\t\t\t\t    |\n");
	printf("+------+----------------------------------------------------+-------+-------+-------+\n");
	printf("|  ID  |  Nome\t\t\t\t\t\t    |Nota 01|Nota 02|Nota 03|\n");
	printf("+------+----------------------------------------------------+-------+-------+-------+\n");
	for(i = 0; i < qtdAlunos; i++){
		if(alunos[i].deleted == 0){
			printf("|   %d  |", alunos[i].idAluno);
			printf("  %-50s", alunos[i].nomeAluno);
			for(j = 0; j < qtdNotas; j++){
				if((notas[j].idAluno == alunos[i].idAluno) && (alunos[i].qtdNotasAluno != 0)){
					printf("| %5.2f ",  notas[j].valorNota);
				}else if(alunos[i].qtdNotasAluno == 0){
					printf("|       |       |       ");
					break;
				}
			}
			printf("|\n");
			printf("+------+----------------------------------------------------+-------+-------+-------+\n");
		}
	}
	printf("\n________________________________________________________Gerado em %d/%d/%d as %d:%d\n", dataHoraAtual -> tm_mday, dataHoraAtual -> tm_mon + 1, dataHoraAtual -> tm_year + 1900, dataHoraAtual -> tm_hour, dataHoraAtual -> tm_min);
}

void relatorioMedia(){
	
	//Utilizado para mostrar a data e hora que a tabela foi acessada.
	struct tm *dataHoraAtual;
	time_t tempo;
	time(&tempo);
	dataHoraAtual = localtime(&tempo);
	
	
	int i, j;
	float soma;
	printf("\n+-------------------------------------------------------------------------+\n");
	printf("|\t\t\tRelatorio de medias\t\t\t\t  |\n");
	printf("+------+------------------------------------------------------------------+\n");
	printf("|  ID  |  Nome\t\t\t\t\t\t    |\tMedia     |\n");
	printf("+------+----------------------------------------------------+-------------+\n");
	for(i = 0; i < qtdAlunos; i++){
		if(alunos[i].deleted == 0){
			printf("|   %d  |", alunos[i].idAluno);
			printf("  %-50s", alunos[i].nomeAluno);
			printf("|");
			soma = 0;
			for(j = 0; j < qtdNotas; j++){
				if((notas[j].idAluno == alunos[i].idAluno)){
					soma += notas[j].valorNota;
				}
			}
			printf("\t%-10.2f|\n", soma/3);
			printf("+------+----------------------------------------------------+-------------+\n");
		}
	}
	printf("\n______________________________________________Gerado em %d/%d/%d as %d:%d\n", dataHoraAtual -> tm_mday, dataHoraAtual -> tm_mon + 1, dataHoraAtual -> tm_year + 1900, dataHoraAtual -> tm_hour, dataHoraAtual -> tm_min);
}

