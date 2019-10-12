#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAMINHO_ARQUIVO "C:/NetBeansProjects/workspace/Projetos em C/Alunos.txt"
typedef struct{
	char* nome;
	int matricula;
	int idade;
	float nota;
}Aluno;

void salvar_Aluno(Aluno a){
    FILE *arquivo  = fopen(CAMINHO_ARQUIVO, "w+");
    if (arquivo != NULL) {
        fprintf(arquivo, "----Aluno----\n");     
		fprintf(arquivo, "Nome: %s\n",a.nome);     
		fprintf(arquivo, "Matricula : %d\n",a.matricula);     
    	fprintf(arquivo, "Idade : %d\n",a.idade);    
		fprintf(arquivo,"Nota : %f\n",a.nota);   
	}
    else {
        printf("Falha ao abrir o arquivo");
    }    
    fclose(arquivo);
}

void ver_Alunos(){
FILE *arq;
char info[50];
 
 arq = fopen(CAMINHO_ARQUIVO, "r+");
 if(arq == NULL)
   printf("Erro, nao foi possivel abrir o arquivo\n");
 else
  while( (fgets(info, sizeof(info), arq))!=NULL )
   printf("%s", info);
   printf("\n\n");
 
 fclose(arq);
}

	
Aluno setAluno(char* nome,int idade, int matricula, float nota){  
    Aluno A;
	A.nome = nome;  
	A.idade = idade;  
    A.matricula = matricula;
    A.nota = nota;
	return A;
}

int main(){
	int q =0;
	int i = 0;
	int ss;
	
	Aluno Dados;
	
	
	while(q != 3){
		printf("Sistema de Cadastro de Alunos\n\n1)Cadastrar Aluno \n2)Lista de Alunos \n3)Sair\nOpcao :");
		scanf("%d", &q);
		if(q == 1){
			float nota;
			char nome[30];
			int matricula;
			int idade;
			int i = 0;
			
			printf("Digite seu nome :");
			scanf("%s",nome);
			printf("Digite sua matricula :");
			scanf("%d",&matricula);
			printf("Digite a sua idade :");
			scanf("%d",&idade);							
			
			printf("Digite a sua nota :");
			scanf("%f",&nota);							
			float nota2[1] = {nota};

			float *p = nota2;
			
			Dados = setAluno(nome,matricula,idade,p[0]);
			salvar_Aluno(Dados);
			break;
		}		
		
		if(q == 2){
			ver_Alunos();
		}
	}
}


