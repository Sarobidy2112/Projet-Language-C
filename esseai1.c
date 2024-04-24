#include<stdio.h>
int main(){
    char a='.', b=',', c='  ', J1='b', J2='a', J,g;
    int i,j,ij=0,ji=0,x,y,z,w,o;
    char t[7][7];

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
                        g=t[x][y];
                        t[x][y]=c;
                        t[z][w]=g;

                        if(x!=z && y==w){
                            if(x>z){
                                    if(t[z-1][w]==b && t[x+1][w]==b){
                                        printf("Pour choisir le pions à éliminer, tapez 1 pour le haut ou 2 pour le bas\nEnter(1 ou 2) : ");
                                        scanf("%d", &o);
                                        if(o==1){
                                            for(i=z-1;i>=1;i--){
                                                j=w;
                                                if(t[i][j]==a){break;}
                                                else{t[i][j]==c;}}
                                        }
                                        if(o==2){
                                            for(i=x+1;i<=5;i++){
                                                j=w;
                                                if(t[i][j]==a){break;}
                                                else{t[i][j]==c;}}
                                            }
                                    }
                                    else{
                                        if(t[z-1][w]==b){
                                            for(i=z-1;i>=1;i--){
                                                j=w;
                                                if(t[i][j]==a){break;}
                                                else{t[i][j]==c;}
                                            }
                                        }
                                        if(t[x+1][w]==b){
                                            for(i=x+1;i<=5;i++){
                                                j=w;
                                                if(t[i][j]==a){break;}
                                                else{t[i][j]==c;}
                                            }
                                        }
                                    }
                            }
                            if(x<z){
                                if(t[z+1][w]==b && t[x-1][w]==b){
                                    printf("Pour choisir le pions à éliminer, tapez 1 pour le haut ou 2 pour le bas\nEnter(1 ou 2) : ");
                                    scanf("%d", &o);
                                    if(o==1){
                                        for(i=x-1;i>=1;i--){
                                            j=w;
                                            if(t[i][j]==a){break;}
                                            else{t[i][j]==c;}
                                        }
                                    }
                                    if(o==2){
                                        for(i=z+1;i<=5;i++){
                                            j=w;
                                            if(t[i][j]==a){break;}
                                            else{t[i][j]==c;}
                                        }
                                    }
                                }
                                else{
                                    if(t[z+1][w]==b){
                                        for(i=z+1;i<=5;i++){
                                            j=w;
                                            if(t[i][j]==a){break;}
                                            else{t[i][j]==c;}}
                                        }
                                    if(t[x-1][w]==b){
                                        for(i=x-1;i>=1;i--){
                                            j=w;
                                            if(t[i][j]==a){break;}
                                            else{t[i][j]==c;}
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                    else{printf("Deplacement impossible, Recommencer\n");}
                }
            if(J1=='b'){
                printf("Joueur 2 \n");
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

                    if(t[x][y]==b && t[z][w]==c){
                        if(x!=z && y==w){
                            if(x>z){
                                printf("Vertical vers le haut");}
                            }
                        break;
                    }
                    else{printf("Deplacement impossible, Recommencer\n");}
                }
            }
        J2=J;


        for(i=1,j=1;i<=5,j<=5;i++,j++){
            if(t[i][j]==c){
                ij=ij+1;
                ji=ji+1;}
            if(t[i][j]==a){
                ij=ij+1;}
            if(t[i][j]==b){
                ji=ji+1;}
        }
        if(ij==25){
            printf("Le Joueur A a gagné");
            break;}
        if(ji==25){
            printf("Le Joueur B a gagné");
            break;}
        }
    }
}
