#include <stdio.h>
#include <stdlib.h>
void resolve_labirinto(char[10][10],int,int);
void voltar(char, int, int);

int main(){
char vet[10][10]={
{'e', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
{'x', 'o', 'x', 'x', 'x', 'x', 'x', 'x', 'o', 'x'},
{'x', 'o', 'x', 'x', 'x', 'x', 'x', 'x', 'o', 'x'},
{'x', 'o', 'o', 'o', 'x', 'x', 'x', 'x', 'o', 'x'},
{'x', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'x'},
{'x', 'o', 'o', 'o', 'x', 'x', 'x', 'x', 'x', 'x'},
{'x', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'x'},
{'x', 'o', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'o'},
{'x', 'o', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
{'x', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'}};
resolve_labirinto(vet,0,0);
printf("fim");
}

void resolve_labirinto(char vet[10][10],int x, int y){
    // declaração dos movimentos
    int down;
    int up;
    int left;
    int right;
    int upleft;
    int upright;
    int downleft;
    int downright;
    // comentarios = legenda
    // w = caminho errado
    down=vet[y+1][x]; // v
    up=vet[y-1][x]; // ^
    left=vet[y][x-1]; // l
    right=vet[y][x+1]; // >
    upleft=vet[y-1][x-1]; // `
    upright=vet[y-1][x+1]; // ´
    downleft=vet[y+1][x-1]; // "\"
    downright=vet[y+1][x+1]; // "/"
        if(right=='o' && x+1<10){
            vet[y][x]='>';
            x=x+1;
        }
        else if(down=='o' && (y+1<10)){
        vet[y][x]='v';
        y=y+1;
        }
        else if(up=='o' && ((y-1)>(-1))){
            vet[y][x]='^';
            y=y-1;
        }

        else if(left=='o' && x-1>0){
            vet[y][x]='<';
            x=x-1;
        }
        else if(upright=='o' && x+1<10 && y-1>-1){
            vet[y][x]='´';
            x=x+1;
            y=y-1;
        }
        else if(upleft=='o' && x-1>0 && y-1 >-1){
            vet[y][x]='`';
            x=x+1;
            y=y-1;
        }
        else if(downright=='o'&& y+1<10 && x+1 <10){
            vet[y][x]='\\';
            y=y+1;
            x=x+1;
        }
        else if(downleft=='o' && y+1 <10 && x-1>-1){
            vet[y][x]='/';
            y=y+1;
            x=x-1;
        }
        else if(down!='x' && down!='w' && (y+1<10)){
        vet[y][x]='w';
        y=y+1;
        }
        else if(up!='x' && up!='w'  && ((y-1)>(-1))){
            vet[y][x]='w';
            y=y-1;
        }
        else if(right!='x' && right!='w' && x+1<10){
            vet[y][x]='w';
            x=x+1;
        }
        else if(left!='x' && left!='w' && x-1>0){
            vet[y][x]='w';
            x=x-1;
        }
        else if(upright!='x' &&upright!='w'  && x+1<10 && y-1>-1){
            vet[y][x]='w';
            x=x+1;
            y=y-1;
        }
        else if(upleft!='x' &&upleft!='w' && x-1>0 && y-1 >-1){
            vet[y][x]='w';
            x=x-1;
            y=y-1;
        }
        else if(downright!='x' && downright!='w' && y+1<10 && x+1 <10){
            vet[y][x]='w';
            y=y+1;
            x=x+1;
        }
        else if(downleft!='x' &&downleft!='w' && y+1 <10 && x-1>-1){
            vet[y][x]='w';
            y=y+1;
            x=x-1;
        }
    int i=0;
    int j=0;
    printf("%i",y);
    printf(" ");
    printf("%i",x);
    printf("\n");
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            printf("%c",vet[i][j]);
            if(j==9){
                printf("\n");
            }
        }
    }
    printf("\n\n");
    if(x==9&&y==9){
        vet[x][y]='D';
        for(i=0;i<10;i++){
            for(j=0;j<10;j++){
                printf("%c",vet[i][j]);
                if(j==9){
                    printf("\n");
                }
            }
        }
    }
    else{
        resolve_labirinto(vet,x,y);
    }
}
