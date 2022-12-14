#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct Aluno{
	int idAluno;
	char nomeAluno[50];
	int deleted;
}Aluno;

void menuPrincipal(Aluno *alunos);
void carregarAlunos(Aluno *alunos);
void consultarAluno(Aluno *alunos);
void excluirAluno(Aluno *alunos);
void relatorioAluno(Aluno *alunos);

//funções: 
int main(){
	Aluno alunos[24];
	carregarAlunos(alunos);
	printf("BEM VINDOS AO SISTEMA UDESC\n");
	menuPrincipal(alunos);
	
	return 0;
}

void menuPrincipal(Aluno *alunos){
	int opcao;
	
	do{
		printf("\nMENU PRINCIPAL\n");
		printf("1 - Consultar aluno\n2 - Relatorio alunos\n3 - Excluir aluno por Id\n4 - Sair\nEscolha uma opcao: ");
		scanf("%d", &opcao);
		getchar();
		switch(opcao){
			case 1:
				consultarAluno(alunos);
				break;
			case 2:
				relatorioAluno(alunos);
				break;
			case 3:
				excluirAluno(alunos);
				break;
			case 4:
				printf("\nObrigado por usar!");
				break;
			default: 
				printf("Por favor, coloque um entrada valida\n");
		}
	}while(opcao != 4);
}



void carregarAlunos(Aluno *alunos){
	FILE *arq;
	arq = fopen("alunos.csv", "r");
	char nome[50];
	int id, contador = 0;
	fscanf(arq, "%[^\n]", nome);
	while(fscanf(arq, "%d;%[^\n]", &id, nome) != EOF){
		alunos[contador].idAluno = id;
		strcpy(alunos[contador].nomeAluno, nome);
		alunos[contador].deleted = 0;
		contador++;
	}
	fclose(arq);
}

void consultarAluno(Aluno *alunos){ 
	int i, id, achou = 0;
	printf("\nCodigo do aluno: ");
	scanf("%d", &id);
	for(i = 0; i < 24; i++){
		if((alunos[i].idAluno == id) && (alunos[i].deleted == 0)){
			printf("Aluno: %s\n", alunos[i].nomeAluno);
			achou = 1;
		}else if((alunos[i].deleted == 1) && (alunos[i].idAluno == id)){
			printf("\nAluno nao existe na base!\n");
			achou = 1;
		}
	}
	if(!achou){
		printf("\nNao existe o Id na base de alunos!\n");
	}
}

void excluirAluno(Aluno *alunos){
	int id, i, achou = 0;
	char confirma;
	printf("\nDigite o Id do aluno: ");
	scanf("%d", &id);
	getchar();
	for(i = 0; i < 24; i++){
		if((alunos[i].deleted == 0) && (alunos[i].idAluno == id)){
			printf("\nCodigo do aluno: %d\n", alunos[i].idAluno);
			printf("Aluno: %s\n", alunos[i].nomeAluno);
			achou = 1;
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
	if(!achou){
		printf("\nNao existe o Id na base de alunos!\n");
	}
}



void relatorioAluno(Aluno *alunos){
	
	//Utilizado para mostrar a data e hora que a tabela foi acessada.
	struct tm *dataHoraAtual;
	time_t tempo;
	time(&tempo);
	dataHoraAtual = localtime(&tempo);
	
	
	int i, j;
	char x = 'x';
	printf("\n+-----------------------------------------------------------+\n");
	printf("|\t\tRelatorio de alunos\t\t\t    |\n");
	printf("+-------------+----------------------------------------------\n");
	printf("|     ID      |  Nome\t\t\t\t\t    |\n");
	printf("+-------------+---------------------------------------------+\n");
	for(i = 0; i < 24; i++){
		if(alunos[i].deleted == 0){
			printf("| %-12d|", alunos[i].idAluno);
			printf("  %-43s", alunos[i].nomeAluno);
			printf("|\n");
			printf("+-------------+---------------------------------------------+\n");
		}
	}
	printf("\n______________________________________________Gerado em %d/%d/%d as %d:%d\n", dataHoraAtual -> tm_mday, dataHoraAtual -> tm_mon + 1, dataHoraAtual -> tm_year + 1900, dataHoraAtual -> tm_hour, dataHoraAtual -> tm_min);
}
	



