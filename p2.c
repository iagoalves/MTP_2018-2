/* P2.c */
/* Iago Alves de Oliveira */
/* 11811ECP006 */
#include <stdio.h>
/* Inicio funções de outras bibliotecas recriadas for fun */
void int_char(int dec,char bin[]){
   int cont=0;
   int i;
   int x=dec;
    while ( x ) {
    x=x/10;
    cont=cont+1;
    }
    x=dec;
    for(i=cont -1 ;x>1;i--){
        bin[i]=((x%10)+48);
        x=x/10;
        bin[i+1]='\0';
    }
}

int cont_string(char string[]){
    int cont=0;
    int i;
    for(i=0;string[i]!='\0';i++){
        cont++;
    }
    return cont;
}

int string_int(char string[],int cont, int idec[]){
    int i;
    for(i=0;i<cont;i++){
        idec[i]=string[i]-48;
    }
}


int atoi(int idec[],int cont){
int i;
int x=1;
int v[256];
for(i=cont;i>0;i--){
    v[i-1]=idec[i-1]*x;
    x=x*10;
}
int vet_num=0;
for(i=cont;i>0;i--){
vet_num=vet_num+v[i-1];
}
return vet_num;
}

int char_int(char idec[],int cont){
int i;
int x=1;
int v[256];
for(i=cont;i>0;i--){
    v[i-1]=(idec[i-1]-48)*x;
    x=x*10;
}
int vet_num=0;
for(i=cont;i>0;i--){
vet_num=vet_num+v[i-1];
}
return vet_num;
}

void int_string(int idec[], int cont, char *string[]){ /* Roubei nessa função, nao consegui transformar int para string de verdade */
    int i;
    char aux[10];
    for(i=0;i<cont;i++){
        snprintf(aux, 2, "%c", idec[i]+48);
        string[i]=aux[0];
        string[i+1]='\0';
    }
    for (i=0;i<cont;i++){
    }
}

void invert_char(char string[],int cont){
int i;
int stringx[256];
for(i=0;i<cont;i++){
    stringx[cont-1-i]=string[i];
}
i=0;
for(i=0;i<cont;i++){
    string[i]=stringx[i];
}
}
void invert_string(char *string[],int cont){
int i;
int stringx[256];
for(i=0;i<cont;i++){
    stringx[cont-1-i]=string[i];
}
i=0;
for(i=0;i<cont;i++){
    string[i]=stringx[i];
}
printf(" \n");
}

int pow(int x,int y){
int aux=x;
if(y==0){
    x=1;
}
else if (y==1){
    x=x;
}
else{
    while(y>1){
            x=x*2;
        y=y-1;
    }
}
return x;
}

/* Fim funções de outras bibliotecas recriadas for fun */

char dec_bin(char dec[],char bin[]){
    int cont=cont_string(dec);
    int idec=char_int(dec,cont);
    int restototal=idec;
    int rot=0;
    do{
        bin[rot]=(restototal%2)+48;
        restototal=restototal/2;
        rot=rot+1;
}while(restototal>=1);
int i;
    invert_char(bin,rot);
}



int bin_dec(char bin[]){
    int i;
    int cont=cont_string(bin);
    int dec=0;
    invert_char(bin,cont);
    for(i=cont-1;i>=0;i--){
        int potencia=pow(2,i);
        dec=dec+((bin[i]-48)*potencia);
    }
    return dec;
}

int hex_dec(char bin[]){
    int i;
    int cont=cont_string(bin);
    int dec=0;
    invert_char(bin,cont);
    for(i=cont-1;i>=0;i--){
    if((bin[i]-48)<=9){
        int potencia=pow(16,i);
        dec=dec+((bin[i]-48)*potencia);
        }
    else if(bin[i]>=68 &&bin[i]<=90){
        int potencia=pow(16,i);
        dec=dec+((bin[i]-55)*potencia);
    }
    else{
        int potencia=pow(16,i);
        dec=dec+((bin[i]-87)*potencia);
    }
    }
    return dec;
}

int oct_dec(char bin[]){
    int i;
    int cont=cont_string(bin);
    int dec=0;
    invert_char(bin,cont);
    for(i=cont-1;i>=0;i--){
        int potencia=pow(8,i);
        dec=dec+((bin[i]-48)*potencia);
    }
    return dec;
}

char dec_hex(int dec[],char bin[]){
    int restototal=dec;
    int rot=0;
    if (restototal<10){
        bin[rot]=restototal+48;
        printf("hex = %c \n",bin[rot]);
        rot=rot+1;
    }
    else{
    do{
        if (restototal<10){
            bin[rot]=(restototal%16)+48;
            restototal=restototal/16;
            rot=rot+1;
            printf("hex = %c \n",bin[rot]);
        }
        else if(restototal<17){
            bin[rot]=(restototal%16)+55;
            restototal=restototal/16;
            rot=rot+1;
            printf("hex = %c \n",bin[rot]);
        }
        else{
            bin[rot]=(restototal%16)+87;
            restototal=restototal/16;
            rot=rot+1;
            printf("hex = %c \n",bin[rot]);
        }
    }while(restototal>=16);
    }
    int i;
        invert_char(bin,rot);
}


int main(){
while(1){
int a;
int cont;
printf("Digite um numero de 1 a 7:\n 1: bin to dec \n 2: bin to hex \n 3: hex to dec\n 4: hex to bin \n 5: dec to bin \n 6: dec to hex \n 7: oct to hex \n");
scanf("%i",&a); getchar();
if(a==1){
    printf("Conversão binario para decimal digite o número binario: \n");
    int dec;
    char bin[256];
    scanf("%s",&bin); getchar();
    dec=bin_dec(bin);
    printf("dec e : %i \n",dec);
}

if(a==2){
    printf("Conversão binario para hexadecimal \n");
    char bin[256];
    char idec[256];
    scanf("%s",&bin); getchar();
    int dec;
    dec=bin_dec(bin);
    printf("%x \n",dec);
}

if(a==3){
    printf("Conversão hexadecimal para decimal \n");
    char hex[256];
    int dec;
    scanf("%s",&hex); getchar();
    dec=hex_dec(hex);
    printf("dec e %i :",dec);
}

if(a==4){
    printf("Conversão hexadecimal para binario \n");
    char hex[256];
    char bin[256];
    int dec;
    scanf("%s",&hex); getchar();
    dec=hex_dec(hex);
    dec_hex(bin,hex);

}

if (a==5){
    printf("Conversão decimal para binario  \n");
    char dec[256];
    char bin[256];
    scanf("%s",&dec); getchar();
    dec_bin(dec,bin);
    int i;
    printf("bin e %s :", bin);
}

if(a==6){
    printf("Conversão decimal para hexadecimal \n");
    int dec;
    scanf("%i",&dec); getchar();
    dec=bin_dec(bin);
    printf("%x \n",dec);
}

if(a==7){
    printf("Conversão octal para decimal \n");
    char hex[256];
    int dec;
    scanf("%s",&hex); getchar();
    dec=oct_dec(hex);
    printf("dec e %i :",dec);
}
}
//bin_hex
//decimal=bin_dec(bin);
//dec_hex(decimal);
}
