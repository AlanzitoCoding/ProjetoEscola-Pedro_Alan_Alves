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
    int id;
    int matricula;
    char sexo;
    char cpf[12];
    char nome[100];
    Date dataNascimento;
} Pessoa;

typedef struct{
    int id;
    int semestre;
    int codigo;
    int professorID_FK;
    int alunosID_FK[TAM];
    char nome[100];
} Disciplina;

void cadastrarPessoa(Pessoa listaPessoa[], int qntPessoa, char tipo[], int id){
    listaPessoa[qntPessoa].id = id;
    
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
        printf("ID: %d\nMatrícula: %d\nNome: %sCPF: %s\n", listaPessoa[i].id, listaPessoa[i].matricula, listaPessoa[i].nome, listaPessoa[i].cpf);
        printf("Data de Nascimento: %d/%d/%d\nSexo: %c\n\n", listaPessoa[i].dataNascimento.dia, listaPessoa[i].dataNascimento.mes, listaPessoa[i].dataNascimento.ano, listaPessoa[i].sexo);
    }
}

void editarPessoa(Pessoa listaPessoa[], int qntPessoa, char tipo[]){
    int id, pos, achou = 0;
    
    listarPessoas(listaPessoa, qntPessoa);

    printf("Digite o id do(a) %s que deseja editar: ", tipo);
    scanf("%d", &id);
    
    for(int i = 0; i < qntPessoa; i++){
        if(listaPessoa[i].id == id){
            achou = 1;
            pos = i;
            break;
        }
    }

    if(achou == 1){
        getchar();

        printf("Digite o novo nome do(a) %s: ", tipo);
        fgets(listaPessoa[pos].nome, 100, stdin);
    
        printf("Digite o novo CPF do(a) %s: ", tipo);
        fgets(listaPessoa[pos].cpf, 12, stdin);
    
        getchar();
    
        printf("Digite o novo sexo do(a) %s: ", tipo);
        scanf("%c", &listaPessoa[pos].sexo);
    
        printf("Digite a nova matrícula do(a) %s: ", tipo);
        scanf("%d", &listaPessoa[pos].matricula);
    
        printf("Digite o novo dia de nascimento do(a) %s: ", tipo);
        scanf("%d", &listaPessoa[pos].dataNascimento.dia);
    
        printf("Digite o novo dia de nascimento do(a) %s: ", tipo);
        scanf("%d", &listaPessoa[pos].dataNascimento.mes);
    
        printf("Digite o novo ano de nascimento do(a) %s: ", tipo);
        scanf("%d", &listaPessoa[pos].dataNascimento.ano);    
    }
    else{
        printf("Pessoa não encontrada!");
    }


}
void excluirPessoa(Pessoa listaPessoa[], int qntPessoa, char tipo[]){
    int id, pos, achou = 0;
    
    listarPessoas(listaPessoa, qntPessoa);

    printf("Digite o id do(a) %s que deseja excluir: ", tipo);
    scanf("%d", &id);
    
    for(int i = 0; i < qntPessoa; i++){
        if(listaPessoa[i].id == id){
            achou = 1;
            pos = i;
            break;
        }
    }

    if(achou == 1){
        getchar();

        for(int i = pos; i < qntPessoa - 1; i++){
            listaPessoa[i].id = listaPessoa[i+1].id;
            strcpy(listaPessoa[i].nome, listaPessoa[i+1].nome);
            strcpy(listaPessoa[i].cpf, listaPessoa[i+1].cpf);
            listaPessoa[i].sexo = listaPessoa[i+1].sexo;
            listaPessoa[i].matricula = listaPessoa[i+1].matricula;
            listaPessoa[i].dataNascimento.dia = listaPessoa[i+1].dataNascimento.dia;
            listaPessoa[i].dataNascimento.mes = listaPessoa[i+1].dataNascimento.mes;
            listaPessoa[i].dataNascimento.ano = listaPessoa[i+1].dataNascimento.ano;
        }
    }
    else{
        printf("Pessoa não encontrada!");
    }

}

void main(){
    int opt, optAlunos, qntAlunos = 0, qntProfs = 0, alunoId = 1, profId = 1;
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
                    scanf("%d", &optAlunos);              
                    switch(optAlunos){
                        case 1:{
                            getchar();
    
                            if(qntAlunos == TAM){
                                printf("Lista cheia!");
                                break;
                            }
    
                            cadastrarPessoa(alunos, qntAlunos, "aluno(a)", alunoId);                        
                            qntAlunos++;
                            alunoId++;
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
                        case 3:{
                            getchar();
    
                            if(qntAlunos == 0){
                                printf("Lista vazia!");
                                break;
                            }
    
                            editarPessoa(alunos, qntAlunos, "aluno(a)");
                            break;
                        }
                        case 4:{
                            getchar();
    
                            if(qntAlunos == 0){
                                printf("Lista vazia!");
                                break;
                            }
    
                            excluirPessoa(alunos, qntAlunos, "aluno(a)");
                            qntAlunos--;
                            break;
                        }
                    }
                }while(optAlunos != 0);
                
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