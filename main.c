#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    float valor_prod, retorno, valor_final;
    int pont, bonif, milheiro;
}Simulacao;

Simulacao simulacoes[100];
int total = 0;

void linha(){
    for(int i = 0; i < 50; i++)
        printf("-");
    return;
}

int verifica_file(){
    FILE *f = fopen("simulacoes.txt", "r");
    if(f){
        fclose(f);
        return 1;
    }
    fclose(f);
    return 0;
}

void carrega_file(){
    FILE *f = fopen("simulacoes.txt", "r");
    if(f == NULL){
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }
    fscanf(f, "%i\n", &total);

    for(int i = 0; i < total; i++){
        fscanf(f, "%f\n", &simulacoes[i].valor_prod);
        fscanf(f, "%i\n", &simulacoes[i].pont);
        fscanf(f, "%i\n", &simulacoes[i].bonif);
        fscanf(f, "%i\n", &simulacoes[i].milheiro);
        fscanf(f, "%f\n", &simulacoes[i].retorno);
        fscanf(f, "%f\n", &simulacoes[i].valor_final);
    }
    printf("\nSimulações salvas carregadas com sucesso!\n");
    return;
}

Simulacao simular(Simulacao s){
    s.retorno = s.valor_prod * s.pont;
    s.retorno = s.retorno + (s.bonif/100.0) * s.retorno;
    s.retorno = (s.retorno / 1000.0) * s.milheiro;
    s.valor_final = s.valor_prod - s.retorno;
    return s;
}

void salvar_file(){
    FILE *f = fopen("simulacoes.txt", "w");
    if(f == NULL){
        printf("\nErro ao abrir o arquivo!\n");
        return;
    }
    fprintf(f, "%i\n", total);

    for(int i = 0; i < total; i++){
        fprintf(f, "%f\n", simulacoes[i].valor_prod);
        fprintf(f, "%i\n", simulacoes[i].pont);
        fprintf(f, "%i\n", simulacoes[i].bonif);
        fprintf(f, "%i\n", simulacoes[i].milheiro);
        fprintf(f, "%f\n", simulacoes[i].retorno);
        fprintf(f, "%f\n", simulacoes[i].valor_final);
    }
    printf("\nArquivo salvo com sucesso!\n");
    system("pause");
    return;
}

void digita_simulacao(Simulacao s){
    printf("\n");
    linha();
    printf("\nValor do produto R$: %.2f", s.valor_prod);
    printf("\nPontuação por real: %i", s.pont);
    printf("\nBonificação 0 a 100%%: %i", s.bonif);
    printf("\nValor do milheiro R$: %i", s.milheiro);
    printf("\nRetorno R$: %.2f", s.retorno);
    printf("\nValor final R$: %.2f\n", s.valor_final);
    linha();
    printf("\n");
    return;
}

void listar_simulacoes(){
    system("cls");
    printf("Simulações:");
    for(int i = 0; i < total; i++){
        digita_simulacao(simulacoes[i]);
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    if(verifica_file()){
        carrega_file();
    }
    int opc;
    Simulacao s;
    char res;
    do{
        system("cls");

        linha();
        printf("\nSimulador\n");
        linha();
        printf("\n1. Fazer simulação\n2. Visualizar simulações salvas\n3. Sair\n-> ");
        scanf("%i", &opc);
        linha();

        switch(opc){
            case 1:
                system("cls");
                printf("Simular Produto\n");
                linha();
                printf("\nValor do produto R$: ");
                scanf("%f", &s.valor_prod);
                printf("Pontuação por real: ");
                scanf("%i", &s.pont);
                do{
                   printf("Bonificação (maior que 0%%): ");
                   scanf("%i", &s.bonif);
                }while(s.bonif < 0);
                do{
                    printf("Valor do milheiro(R$ 17 à R$ 29): ");
                    scanf("%i", &s.milheiro);
                }while(s.milheiro < 17 || s.milheiro > 29);
                linha();
                s = simular(s);
                printf("\nRetorno R$: %.2f", s.retorno);
                printf("\nValor final R$: %.2f\n", s.valor_final);
                linha();

                printf("\n");
                system("pause");
                system("cls");

                do{
                    printf("Gostaria de salvar essa simulação(s/n)? ");
                    setbuf(stdin, NULL);
                    res = getchar();
                }while(res != 's' && res != 'n');

                if(res == 's'){
                    if(total >= 100){
                        printf("\nNão há espaço!\n");
                        system("pause");
                        break;
                    }
                    simulacoes[total] = s;
                    total++;
                    salvar_file();
                }
                break;
            case 2:
                if(total){
                    listar_simulacoes();
                }
                else printf("\nNão há simulações salvas!\n");
                system("pause");
                break;
            case 3:
                printf("\nSaindo!\n");
                system("pause");
                break;
            default:
                printf("\nOpção inválida!\n");
                system("pause");
        }
    }while(opc != 3);
    return 0;
}
