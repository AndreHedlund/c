/*Faça um algoritmo em linguagem C que realiza a busca de um aluno da UNINTER no AVA. 
A busca deve ser realizada utilizando uma estrutura de dados bastante eficiente para esta tarefa de 
busca. Dentre as estruturas que podem ser empregados estão: árvore binária ou hash.
1. Deve-se armazenar o nome do aluno, seu e-mail e seu RU. Para o armazenamento  utilize uma estrutura 
heterogênea de dados.
2.Não é necessário fazer a leitura dos dados dos alunos manualmente. Você já  pode deixar pré-cadastrado
os dados no seu código. Cadastre pelo menos  uns 10 contatos de alunos na sua estruturade dados.
Um dos contatos deverá ser o seu próprio nome e o seu RU da UNINTER;
3.Em um menu na tela, peça para o usuário digitar um RU. O programa deverá realizar a busca por este RU
na estrutura de dados e, caso localize o RU, deverá mostrar o nome correspondente do aluno e o e-mail
deste contato. Caso não localize, uma mensagem de erro deve ser apresentada.
4.Para testar o programa, teste a busca com o seu RU e coloque a captura de tela */
#include <stdio.h>
#include <stdlib.h>
#define M 10

typedef struct dadosAluno {
    int ru;
    char nome[55];
    char email[55];
}dadosAluno; 

//tabela hash do tipo dadosAluno
dadosAluno tabelaHash[M]; 

//recebendo os dados do aluno para cadastro
dadosAluno lerdadosAluno(){
    dadosAluno Aluno;
    printf("Ru do aluno: ");
    scanf("%d", &Aluno.ru);
    scanf("%*c");
    printf("Nome do Aluno: ");
    fgets(Aluno.nome, 55-1, stdin);
    printf("Email do Aluno: ");
    fgets(Aluno.email, 55-1, stdin);
    return Aluno;
}
//procurando um aluno na tabela
dadosAluno* procurar(int numeroRU){
    int indice = criarCodigoHash(numeroRU);
    while (tabelaHash[indice].ru != -1){
        if (tabelaHash[indice].ru == numeroRU){
            return &tabelaHash[indice];
        }
        else{
            indice = criarCodigoHash(indice + 1);
        }
    }
    return NULL;
}
int main(){
    int opcao, numeroRU;
    dadosAluno* Aluno;

    inicializarTabela(); // inicializando a tabela com um índice para cada aluno.

//menu principal
    do{
        printf("\n>>SISTEMA DE CADASTRO DE ALUNOS<<\n");
        printf("1 - Inserir aluno\n");
        printf("2 - Buscar por ru\n");
        printf("3 - Listar alunos\n");
        printf("4 - Encerrar programa\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
        case 1:
            printf("\nCADASTRAR ALUNO\n");
            inserir(); 
            break;
        case 2:
            printf("BUSCAR POR RU\n");
            printf("Ru do aluno: ");
            scanf("%d", &numeroRU);
            Aluno = procurar(numeroRU);//função para buscar o ru
            if (Aluno){
                printf("\nDADOS DO ALUNO BUSCADO\n");
                printf("Ru...................: %d\n", Aluno->ru);
                printf("Nome.................: %s", Aluno->nome);
                printf("Email................: %s", Aluno->email);
                printf("\n");
            }
            else{
                printf("\nRu nao encontrado!\n");
            }
            break;
        case 3:
            listarTabela(); //listar os dados cadastrados.
            break;
        case 4:
            printf("Programa encerrado...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }

    } 
    while (opcao != 4);
    return 0;
}

//indexacao da tabela e inicializacao
void inicializarTabela(){
    int i;
    for (i = 0; i < M; i++){
        tabelaHash[i].ru = -1;
    }
}
//inserindo os dados dos alunos na tabela
void inserir(){
    dadosAluno alu = lerdadosAluno();
    int indice = criarCodigoHash(alu.ru);
    while (tabelaHash[indice].ru != -1){
        indice = criarCodigoHash(indice + 1);
    }
    tabelaHash[indice] = alu;
}

//listando os alunos que foram inseridos na tabela
void listarTabela(){
    printf("\n\nLISTA DE ALUNOS CADASTRADOS\n");
    int i;
    for (i = 0; i < M; i++){
        if (tabelaHash[i].ru != -1){
            printf("Ru..................: %d\n", tabelaHash[i].ru);
            printf("Nome................: %s", tabelaHash[i].nome);
            printf("Email...............: %s\n", tabelaHash[i].email);
        }
    }
    printf("\n");
}

//gerando hash para os elementos da tabela
int criarCodigoHash(int numeroRU){
    return numeroRU % M;
}