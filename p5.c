#include<stdio.h>
typedef
    unsigned long long int
    Bytes8;
typedef
    struct LCG {Bytes8 a,c,m,rand_max,atual;}
    LCG;
 void semente (LCG * r, Bytes8 seed){
     r -> a = 0x5DEECE66DULL;
     r -> c = 11ULL;
     r ->m =(1ULL <<48);
     r -> atual = seed;
 }
 Bytes8 lcg_rand(LCG * r){
    r -> atual = (r-> a *r -> atual +r->c) %r->m;
    return r->atual;
}
double lcg_rand_01(LCG * r){
    return ((double) lcg_rand(r))/(r->rand_max);
}
void gera_numeros(float *vetor, int tam, float min, float max, LCG *r){
    int i;
    for(i=0;i<tam;i++)
        vetor[i] = (max-min)*lcg_rand_01(r)+min;
}
float somatorio(float v[], int cont,float soma){
    if(cont==50){
        return soma;
    }
    else{
        printf("%i",cont);
        soma = soma + v[cont]+v[cont+1];
        cont = cont+1;
        printf(" foram somados %f",v[cont-1]);
        printf("%f" ,v[cont]);
        printf(" resultado : %f",soma);
        printf("\n");
        somatorio(v,cont,soma);
    }
}

float produtorio(float v[], int cont,float produto){
    if(cont==50){
        return produto;
    }
    else{
        printf("%i",cont);
        produto = produto* v[cont]*v[cont+1];
        cont = cont+1;
        printf(" foram somados %f",v[cont-1]);
        printf("%f" ,v[cont]);
        printf(" resultado : %f",produto);
        printf("\n");
        produtorio(v,cont,produto);
    }
}
 int main(){
    LCG random;
    semente (&random,123456);
    float vetor[50];
    int N=51;
    gera_numeros(vetor,N,0.5,1.5,&random);
    int i;
    for(i=0;i<50;i++){
        printf ("%f",vetor[i]);
        printf ("\n");
    }
    int op;
    printf("Tecle 1 para somatorio Tecle 2 para produtorio ou tecle 3 para sair");
    scanf("%d", &op);
    while(op!=3){
        if(op==1){
               float soma=somatorio(vetor,0,0);
               printf ("%f",soma);
        }
        if(op==2){
                float  produto=produtorio(vetor,0,1);
                printf ("%f",produto);
        }
        printf("Tecle 1 para somatorio Tecle 2 para produtorio ou tecle 3 para sair");
        scanf("%d", &op);
    }


 }
