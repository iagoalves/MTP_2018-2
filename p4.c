/* P4.c */
/* Iago Alves de Oliveira */
/* 11811ECP006 */
#include<stdio.h>
int A(int,int);

 int main(){
     int m;
     int n;
     printf("Digite o valor de m: ");
     scanf("%d",&m);
     setbuf(stdin,NULL);
     printf("Digite o valor de n: ");
     scanf("%d",&n);
     int resultado = ack(m,n);
     printf("O resultado é: %i",resultado);
     return 0;
 }

int ack(int m, int n)
{
    if (m == 0){
        return n+1;
    }
    else if((m > 0) && (n == 0)){
        return ack(m-1, 1);
    }
    else if((m > 0) && (n > 0)){
        return ack(m-1, ack(m, n-1));
    }
}
