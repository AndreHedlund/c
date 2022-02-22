/*Faça um algoritmo em linguagem C que emule as características de um player de músicas sendo executado
em modo texto, via prompt de comando.
1. Deve-se criar uma playlist das músicas utilizando uma lista encadeada.
A lista encadeada poderá ser simples ou dupla, circular ou não circular, Fica a critério do aluno 
decidir.
2. Deve-se armazenar o nome de cada música, do artista/banda e a duração da faixa. Para o 
armazenamento utilize uma estrutura heterogênea de dados.
3. Para inserção dos dados, você pode criar uma leitura dos dados através de um menu na tela ou 
já deixá-los armazenados em um arquivo texto no seu computador e só carregar este arquivo ao 
executar o programa, ou ambas soluções, decida também como você irá implementar a inserção
(no início, no fim ou no meio da lista encadeada) Deve existir um menu na tela. 
 Este menu deve permitir a inserção de novas músicas (caso optado pela inserção manual de dados), 
 deve ter a opção de listar todas as músicas da playlist (listagem de uma lista encadeada) na 
 tela e encerrar o programa.
*/
#include <stdio.h>
#include <stdlib.h>

struct Playlist{
    char musica[30], artista[30];
    float duracao;
    struct Playlist *prox; //ponteiro para apontar para o proximo elemento
};
typedef struct Playlist lista;

//funcao que verifica se a lista esta vazia
int vazia(lista *le){
	if(le->prox == NULL){
		return 1;
	}else{
		return 0;
	}
}
//funcao para inicializar a lista
void iniciar(lista *le){
	le->prox = NULL;
}

void encerrar(lista *le){
	if(!vazia(le)){
		lista *proxNo, *atual;
		atual = le->prox;
		while(atual != NULL){
			proxNo = atual->prox;
			free(atual);
			atual = proxNo;
		}
	}
}
//funcao para exibir os dados da lista
void exibir(lista *le){
	if(vazia(le)){
		printf("Playlist vazia!\n");
		return;
	}
	//variavel tmp para receber o proximo elemento
	lista *tmp;
	tmp = le->prox;
	printf("\n______MUSICAS NA PLAYLIST______\n");
	while(tmp != NULL){
        printf("Musica............: %s", tmp->musica);
        printf("Artista...........: %s", tmp->artista);
        printf("Duracao Musica....: %.2f\n\n", tmp->duracao);
		tmp = tmp->prox;
	}
	printf("\n");
}
//funcao para receber e inserir os dados no final da lista
void insereFim(lista *le){
    int c;
	lista *novo = (lista*)malloc(sizeof(lista));//funcao malloc para fazer a alocacao dinamica
	if(!novo){
		printf("Sem memória disponível!\n");
		exit(1);
	}
	scanf("%*c");//while ((c = getchar()) !=  '\n' && c  != EOF) {}// limpa buffer de teclado

    printf("Nome da musica: ");
	fflush(stdin);
    fgets(novo->musica, 29, stdin);

    printf("Nome do artista: ");
	fflush(stdin);
    fgets(novo->artista, 29, stdin);
    
    printf("Tamanho da musica: ");
    scanf("%f", &novo->duracao);
	novo->prox = NULL;
	if(vazia(le)){
		le->prox = novo;
	}else{
		lista *tmp = le->prox;

		while(tmp->prox != NULL){
			tmp = tmp->prox;
		}
		tmp->prox = novo;
	}
}
//funcao para receber a lista e uma opcao no menu
void opcao(lista *le, int op){
	switch(op){
		case 0:
			encerrar(le);
			printf("Player encerrado!\n");
			break;
		case 1:
			exibir(le);
			break;
		case 2:
			insereFim(le);
			break;
		case 3:
			iniciar(le);
			printf("Playlist apagada!\n");
			break;
		default:
			printf("Comando inválido!\n");
	}
}
//funcao para o usuario escolher o que deseja fazer na playlist
int menu(){
	int opt;

	printf("\n___PLAYER DE MUSICA___\n");
	printf("0 - Sair \n");
	printf("1 - Exibir playlist \n");
	printf("2 - Adicionar musica \n");
	printf("3 - Limpar playlist \n");
	printf("Opcao: ");
	scanf("%d", &opt);
	return opt;
}

int main(){
	lista *le = (lista*)malloc(sizeof(lista));
	//condicao que verifica se foi possivel fazer a alocacao de memoria
	if(!le){
		printf("Sem memória disponível");
		exit(1);
	}
	iniciar(le);
	int opt;

	do{
		opt=menu();
		opcao(le, opt);
	}while(opt);
	free(le); //liberar memoria 
	return 0;
}