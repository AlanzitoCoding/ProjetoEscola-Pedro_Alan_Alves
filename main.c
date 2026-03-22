// Louvado seja o Senhor

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 3

typedef struct{
    int dia;
    int mes;
    int ano;
} Date;

typedef struct{
    int matricula;
    char sexo;
    char cpf[11];
    char nome[100];
    Date dataNascimento;
} Pessoa;

void cadastrarPessoa(Pessoa listaPessoa[], int qntPessoa, char tipo[]){
    printf("Digite o nome do(a) %s: ", tipo);
}

void main(){
    int opt, qntAlunos = 0, qntProfs = 0;
    Pessoa alunos[TAM], profs[TAM];

    do{
        printf("\n\n========== MENU ==========\n\n");
        printf("1 - Gerenciamento de Alunos\n2 - Gerenciamento de Professores\n3 - Relatórios\n0 - Sair\nOpção: ");
        scanf("%d", &opt);

        switch(opt){
            case 1:{
                printf("\n\n========== MENU ALUNOS ==========\n\n");
                printf("1 - Cadastro de Aluno\n2 - Listagem dos Alunos\n3 - Edição de dados do Aluno\n4 - Exclusão de Aluno\n0 - Sair\nOpção: ");                
                switch(opt){
                    case 1:{

                    }
                }
                break;
            }
            case 2:{
                printf("\n\n========== MENU PROFESSORES ==========\n\n");
                printf("1 - Cadastro de Professor\n2 - Listagem dos Professores\n3 - Edição de dados do Professor\n4 - Exclusão de Professor\n0 - Sair\nOpção: ");                
                break;
            }
        }
    }while(opt != 0);
}