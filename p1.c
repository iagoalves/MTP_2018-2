/* P1.c */
/* Iago Alves de Oliveira */
/* 11811ECP006 */
#include<stdio.h>
int main(){
char bits[256];
scanf("%s",bits);
int i;
int estado=0;
for (i=0;bits[i]=="\0";i++){
    if(estado == 0 && bits[i]=='1'){
        estado=1;
    }
    else if(estado == 1 && bits[i]=='0'){
        estado=2;
    }
    else if(estado == 1 && bits[i]!='0'){
        estado=0;
    }
    else if(estado==2 && bits[i]== '0'){
        estado=1;
    }
}
if(estado == 0){
    printf("O número binario : %s",bits);
    printf(" é divisivel por 3");
}
else{
       printf("O número binario : %s",bits);
    printf(" não é divisivel por 3");
}
}
