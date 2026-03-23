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
    char cpf[12];
    char nome[100];
    Date dataNascimento;
} Pessoa;

void cadastrarPessoa(Pessoa listaPessoa[], int qntPessoa, char tipo[]){
    printf("Digite o nome do(a) %s: ", tipo);
    fgets(listaPessoa[qntPessoa].nome, 100, stdin);

    printf("Digite o CPF do(a) %s: ", tipo);
    fgets(listaPessoa[qntPessoa].cpf, 12, stdin);

    getchar();

    printf("Digite o sexo do(a) %s: ", tipo);
    scanf("%c", &listaPessoa[qntPessoa].sexo);

    printf("Digite a matrícula do(a) %s: ", tipo);
    scanf("%d", &listaPessoa[qntPessoa].matricula);

    printf("Digite o dia de nascimento do(a) %s: ", tipo);
    scanf("%d", &listaPessoa[qntPessoa].dataNascimento.dia);

    printf("Digite o dia de nascimento do(a) %s: ", tipo);
    scanf("%d", &listaPessoa[qntPessoa].dataNascimento.mes);

    printf("Digite o ano de nascimento do(a) %s: ", tipo);
    scanf("%d", &listaPessoa[qntPessoa].dataNascimento.ano);    
}

void listarPessoas(Pessoa listaPessoa[], int qntPessoa){
    for(int i = 0; i < qntPessoa; i++){
        printf("Matrícula: %d\nNome: %sCPF: %s", listaPessoa[i].matricula, listaPessoa[i].nome, listaPessoa[i].cpf);
        printf("Data de Nascimento: %d/%d/%d\nSexo: %c\n\n", listaPessoa[i].dataNascimento.dia, listaPessoa[i].dataNascimento.mes, listaPessoa[i].dataNascimento.ano, listaPessoa[i].sexo);
    }
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
                getchar();

                do{
                    printf("\n\n========== MENU ALUNOS ==========\n\n");
                    printf("1 - Cadastro de Aluno\n2 - Listagem dos Alunos\n3 - Edição de dados do Aluno\n4 - Exclusão de Aluno\n0 - Sair\nOpção: ");  
                    scanf("%d", &opt);              
                    switch(opt){
                        case 1:{
                            getchar();
    
                            if(qntAlunos == TAM){
                                printf("Lista cheia!");
                                break;
                            }
    
                            cadastrarPessoa(alunos, qntAlunos, "aluno(a)");                        
                            qntAlunos++;
                            break;
                        }
                        case 2:{
                            getchar();
    
                            if(qntAlunos == 0){
                                printf("Lista vazia!");
                                break;
                            }
    
                            listarPessoas(alunos, qntAlunos);
                            break;
                        }
                    }
                }while(opt != 0);
                
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