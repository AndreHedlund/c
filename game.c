#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int nivel;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular; //obj calcular!

void jogar();
void mostrarInfo(Calcular calc);
int pontos = 0; //variavel global

int main(){
    srand(time(NULL));//so pode ser chamado uma vez!
    jogar();
    return 0;
}

void jogar(){
    Calcular calc;
    int nivel;
    printf("\n__________MY GAME___________\n");
    printf("Choice level [1] [2] [3]: ");
    scanf("%d", &nivel);
    calc.nivel = nivel;

    //gera int randomico entre 0 e 3
    calc.operacao = rand() % 3; 

    if(calc.nivel == 1){
        calc.valor1 = rand() % 11;
        calc.valor2 = rand() % 11;
    }else if(calc.nivel == 2){
        calc.valor1 = rand() % 101;
        calc.valor2 = rand() % 101;
    }else if(calc.nivel == 3){
        calc.valor1 = rand() % 1001;
        calc.valor2 = rand() % 1001;
    }else{
        calc.valor1 = rand() % 100001; 
        calc.valor2 = rand() % 100001;
    }
    int resposta;
    printf("Resultado: ");
    if(calc.operacao == 0){
        printf("%d + %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if(somar(resposta, calc)){
            pontos += 1;
            printf("vc tem %d ponto(s).\n", pontos);
        }
    }else if(calc.operacao == 1){
        printf("%d - %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if(subtrair(resposta, calc)){
            pontos += 1;
            printf("vc tem %d ponto(s).\n", pontos);
        }
    }else if(calc.operacao == 2){
        printf("%d x %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if(multiplicar(resposta, calc)){
            pontos += 1;
            printf("vc tem %d ponto(s).\n", pontos);
        }
    }else{
        printf("operacao %d nao reconhecida!", calc.operacao);
    }
    //continuar no jogo?
    printf("Continuar jogando?\n[1]sim\n[0]nao\n");
    int continuar;
    scanf("%d", &continuar);

    if(continuar){
        jogar();
    }else{
        printf("Total pontos: %d\n",pontos);
        printf("Encerrando MY GAME...!\n");
        exit(0);
    }
}

void mostrarInfo(Calcular calc){
    char op[25];

    if(calc.operacao == 0){
        sprintf(op,"Somar");
    }else if(calc.operacao == 1){
        sprintf(op,"Subtrair");
    }else if(calc.operacao == 2){
        sprintf(op,"Multiplicar");
    }else{
        sprintf(op, "Operacao desconhecida!");
    }
    printf("Valor 1: %d\nValor 2: %d\nNivel: %d\nOperacao: %s",
        calc.valor1, calc.valor2, calc.nivel, op);
}
int somar(int resposta, Calcular calc){
    int resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;
    int certo = 0;

    if(resposta == calc.resultado){
        printf("Resposta certa!\n");
        certo = 1;
    }else{
        printf("Resposta errada!\n");
    }
    printf("%d + %d: %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}
int subtrair(int resposta, Calcular calc){
    int resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;
    int certo = 0;

    if(resposta == calc.resultado){
        printf("Resposta certa!\n");
        certo = 1;
    }else{
        printf("Resposta errada!\n");
    }
    printf("%d - %d: %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int multiplicar(int resposta, Calcular calc){
    int resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;
    int certo = 0;

    if(resposta == calc.resultado){
        printf("Resposta certa!\n");
        certo = 1;
    }else{
        printf("Resposta errada!\n");
    }
    printf("%d x %d: %d\n", calc.valor1, calc.valor2, calc.resultado);
    return certo;
}



