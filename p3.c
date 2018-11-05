/* P3.c */
/* Iago Alves de Oliveira */
/* 11811ECP006 */
#include <stdio.h>
int main(){
    char a[256];
    scanf("%s",a);
    int b[256];
    int i;
    int x=0;
    for (i=0;a[i]!='\0';i++){
        if (a[i]>47&&a[i]<58){
           b[x]=a[i]-48;
           printf("%i",b[x]);
           x=x+1;
        }
    }
}
