#include<stdio.h>

void affichage(int n){
    int i,j;
    for(i=1;i<=5;i++){
        for(j=1;j<=5;j++){
            printf("%4c", t[i][j]);
        }
        printf("\n");
    }
}
int main(){
    char a='.', b=',', c='  ', J1='b', J2='a', J,g;
    int i,j,ij=0,ji=0,x,y,z,w,o;
    char t[10][10];

    for(i=1;i<=5;i++)
    {
        if(i==1 || i==2){
            for(j=1;j<=5;j++){
                t[i][j]=a;
                printf("%4c", t[i][j]);
            }
            printf("\n");
        }

        if(i==3){
            for(j=1;j<=5;j++){
                if(j==1 || j==4){
                    t[i][j]=a;
                    printf("%4c", t[i][j]);
                }

                if(j==3){
                    t[i][j]=c;
                    printf("%4c", t[i][j]);
                }

                if(j==2 || j==5){
                    t[i][j]=b;
                    printf("%4c", t[i][j]);
                }
            }
            printf("\n");
        }

        if(i==4 || i==5){
            for(j=1;j<=5;j++){
                t[i][j]=b;
                printf("%4c", t[i][j]);
            }
            printf("\n");
        }
    }

    printf("\n");

    while(1<2){
        J=J1;
        J1=J2;
        if(J1=='a'){
            printf("Joueur 1 \n");
                while(2>1){
                    printf("Coordonne pion(x,y) \nEntrer x : ");
                    scanf("%d",&x);
                    printf("Entrer y : ");
                    scanf("%d", &y);

                    printf("Coordonne lieu(z,w) \nEntrer z : ");
                    scanf("%d", &z);
                    printf("Entrer w : ");
                    scanf("%d", &w);
                    printf("\n");

                    if(t[x][y]==a && t[z][w]==c){
                        if(t[x+1][y]==t[z][w] || t[x-1][y]==t[z][w] || t[x][y+1]==t[z][w] || t[x][y-1]==t[z][w] || t[x+1][y+1]==t[z][w] || t[x-1][y-1]==t[z][w] || t[x-1][y+1]==t[z][w] || t[x+1][y-1]==t[z][w]){
                            break;
                        }
                    }
                    else{printf("Deplacement impossible, Recommencer\n");}
                }

            g=t[x][y];
            t[x][y]=c;
            t[z][w]=g;

            if(x!=z && y==w){
                if(x>z){
                    if(t[z-1][w]==b && t[x+1][w]==b){
                        printf("Pour choisir le pions � �liminer, tapez 1 pour le haut ou 2 pour le bas\nEnter(1 ou 2) : ");
                        scanf("%d", &o);
                        if(o==1){
                            for(i=z-1;i>=1;i--){
                                j=w;
                                if(t[i][j]==a){break;}
                                else{t[i][j]=c;}}
                        }
                        if(o==2){
                            for(i=x+1;i<=5;i++){
                                j=w;
                                if(t[i][j]==a){break;}
                                else{t[i][j]=c;}}
                        }
                    }
                    if(t[z-1][w]==b){
                        for(i=z-1;i>=1;i--){
                            j=w;
                            if(t[i][j]==a){break;}
                            else{t[i][j]=c;}
                        }
                    }
                    if(t[x+1][w]==b){
                        for(i=x+1;i<=5;i++){
                            j=w;
                            if(t[i][j]==a){break;}
                            else{t[i][j]=c;}
                        }
                    }
                    for(i=1;i<=5;i++){
                        for(j=1;j<=5;j++){
                            printf("%4c", t[i][j]);
                        }
                        printf("\n");
                    }
                }

                if(x<z){
                    if(t[z+1][w]==b && t[x-1][w]==b){
                        printf("Pour choisir le pions � �liminer, tapez 1 pour le haut ou 2 pour le bas\nEnter(1 ou 2) : ");
                        scanf("%d", &o);
                        if(o==1){
                            for(i=x-1;i>=1;i--){
                                if(t[i][j]==a){break;}
                                else{t[i][j]=c;}
                            }
                        }
                        if(o==2){
                            for(i=z+1;i<=5;i++){
                                j=w;
                                if(t[i][j]==a){break;}
                                else{t[i][j]=c;}
                            }
                        }
                    }
                    if(t[z+1][w]==b && t[x-1][w]!=b){
                        for(i=z+1;i<=5;i++){
                            j=w;
                            t[i][j]=c;
                        }
                    }
                    if(t[z+1][w]!=b && t[x-1][w]!=b){
                        for(i=x-1;i>=1;i--){
                            j=w;
                            if(t[i][j]==a){break;}
                            else{t[i][j]=c;}
                        }
                    }
                    for(i=1;i<=5;i++){
                        for(j=1;j<=5;j++){
                            printf("%4c", t[i][j]);
                        }
                        printf("\n");
                    }
                }
            }

            if(x==z && y!=w){
                if(y<w){
                    if(t[z][w+1]==b && t[z][x-1]==b){
                        printf("Pour choisir le pions � �liminer, tapez 1 pour le droite ou 2 pour le gauche\nEnter(1 ou 2) : ");
                        scanf("%d", &o);
                        if(o==2){ //gauche
                            for(j=x-1;j>=1;j--){
                                i=z;
                                if(t[i][j]==a){break;}
                                else{t[i][j]=c;}
                            }
                        }
                        if(o==1){
                            for(j=w+1;j<=5;j++){
                                i=z;
                                if(t[i][j]==a){break;}
                                else{t[i][j]=c;}
                            }
                        }
                    }
                    else{
                        if(t[z][x-1]==b){ //gauche
                            for(j=x-1;j>=1;j--){
                                i=z;
                                if(t[i][j]==a){break;}
                                else{t[i][j]=c;}
                            }
                        }
                        if(t[z][w+1]==b){ //droite
                            for(j=w+1;j<=5;j++){
                                i=z;
                                if(t[i][j]==a){break;}
                                else{t[i][j]=c;}
                            }
                        }
                    }

                    for(i=1;i<=5;i++){
                        for(j=1;j<=5;j++){
                            printf("%4c", t[i][j]);
                        }
                        printf("\n");
                    }
                }

                if(y>w){
                    if(t[z][w-1]==b && t[z][y+1]==b){
                        printf("Pour choisir le pions � �liminer, tapez 1 pour le droite ou 2 pour le gauche\nEnter(1 ou 2) : ");
                        scanf("%d", &o);
                        if(o==2){ //gauche
                            for(j=w-1;j>=1;j--){
                                i=z;
                                if(t[i][j]==a){break;}
                                else{t[i][j]=c;}
                            }
                        }
                        if(o==1){ //droite
                            for(j=y+1;j<=5;j++){
                                i=z;
                                if(t[i][j]==a){break;}
                                else{t[i][j]=c;}
                            }
                        }
                    }
                    else{
                        if(t[z][y+1]==b && t[z][w-1]!=b){
                            for(j=y+1;j<=5;j++){
                                i=z;
                                if(t[i][j]==a){break;}
                                else{t[i][j]=c;}
                            }
                        }
                        if(t[z][w-1]==b && t[z][y+1]!=b){
                            for(j=w-1;j>=1;j--){
                                i=z;
                                if(t[i][j]==a){break;}
                                else{t[i][j]=c;}
                            }
                        }
                    }

                    for(i=1;i<=5;i++){
                        for(j=1;j<=5;j++){
                            printf("%4c", t[i][j]);
                        }
                        printf("\n");
                    }
                }
            }
            if(x!=z && y!=w){
                if(x>z && y<w){
                    if(t[z-1][w+1]==b && t[x+1][y-1]==b){
                        printf("Pour choisir le pion � �limin�, tapez 1 pour le haut sinon 2 : ");
                        scanf("%d", &o);
                        if(o==1){ //haut
                            for(i=z-1;i>=1;i--){
                                for(j=w+1;j<=5;j++){
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }

                        if(o==2){
                            for(i=x+1;i<=5;i++){
                                for(j=y-1;j>=1;j--){
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                    }
                    else{
                        if(t[z-1][w+1]==b && t[x+1][y-1]!=b){
                            for(i=z-1;i>=1;i--){
                                for(j=w+1;j<=5;j++){
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        if(t[z-1][w+1]!=b && t[x+1][y-1]==b){
                            for(i=x+1;i<=5;i++){
                                for(j=y-1;j>=1;j--){
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                    }
                    for(i=1;i<=5;i++){
                        for(j=1;j<=5;j++){
                            printf("%4c", t[i][j]);
                        }
                        printf("\n");
                    }
                }

                if(x<z && y>w){
                    if(t[z+1][w-1]==b && t[x-1][y+1]==b){
                        printf("Pour choisir le pion � �limin�, tapez 1 pour le haut sinon 2 : ");
                        scanf("%d", &o);
                        if(o==1){ //haut
                            for(i=z+1;i<=5;i++){
                                for(j=w-1;j>=1;j--){
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }

                        if(o==2){
                            for(i=x-1;i>=1;i--){
                                for(j=y+1;j<=5;j++){
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                    }
                    else{
                        if(t[z+1][w-1]==b && t[x-1][y+1]!=b){
                            for(i=z+1;i<=5;i++){
                                for(j=w-1;j>=1;j--){
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        if(t[z+1][w-1]!=b && t[x-1][y+1]==b){
                            for(i=x-1;i>=1;i--){
                                for(j=y+1;j<=5;j++){
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                    }
                    for(i=1;i<=5;i++){
                        for(j=1;j<=5;j++){
                            printf("%4c", t[i][j]);
                        }
                        printf("\n");
                    }
                }
            }
        }

        if(J1=='b'){
            printf("Joueur 2 \n");
        }
        J2=J;
    }
}
