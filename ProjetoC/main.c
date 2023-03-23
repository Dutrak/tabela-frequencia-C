#include <stdio.h>

float doAcum(float a, float b, int index){

    if (index == 0){
        return a;
    }else{
        return a + b;
    }
    
}

float doCalc(float (*ptr)(float a, float b), float a, float b){
    float result = ptr(a, b);
    return result;
}

float relative(float a, float b){
    return a / b;
}


int main(){
    int num;
    printf("\nDigite o numero de variaveis: ");
    scanf("%d",&num);
    printf("\n");
    char name[num][256];
    int abs[num], sum = 0, absacum[num];
    float rel[num], relacum[num];
    for (int i = 0; i < num; i++){
        printf("Digite o nome da %d° variavel: ", (i+1));
        scanf("%s",name[i]);
        printf("Digite a frequência absoluta referente a variavel \"%s\": ", name[i]);
        scanf("%d",&abs[i]);
        printf("\n\n");
        sum += abs[i];
    }

    for (int i = 0; i < num; i++){
        rel[i] = doCalc(relative,abs[i], sum);
        absacum[i] = doAcum(abs[i], absacum[i - 1], i);
        relacum[i] = doAcum(rel[i], relacum[i - 1], i);
    }

    printf("TABELA DE DISTRIBUIÇÃO DE FREQUENCIAS:\n\n");
    
    for (int i = 0; i < num; i++){
        printf("(x): %s     (F): %d     (fr): %.4f    (fr%%): %.2f    (Fac): %d    (FrAc): %.4f     (FrAc%%): %.2f \n",
        name[i], abs[i], rel[i], rel[i]*100, absacum[i], relacum[i],relacum[i]*100);
    }
    printf("\n\n\n");
}