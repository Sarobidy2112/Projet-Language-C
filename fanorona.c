#include<stdio.h>
int main(){
    char a='.', b=',', c='  ';
    int i,j;
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
    //Permutation des Joueurs
    char J1='b',J2='a',J;

    int x,y,z,w;
    //Coordonnée pions joueur1

    int q,s,d,f;
    //Coordonnée pion Joueur2

    char g,h;
    int k, n=2;

    for(k=1;k<=n;k++)
    {
        J=J1;
        J1=J2;
        if(J1=='a'){
            printf("Joueur 1 \n");
            printf("Entrer les coordonnés x,y du pion à deplacer\nEntrer x = ");
            scanf("%d", &x);
            printf("Entrer y = ");
            scanf("%d", &y);

            printf("Entrer les coordonnés z,w du lieu de déplacement\nEntrer z = ");
            scanf("%d", &z);
            printf("Entrer w = ");
            scanf("%d", &w);

            //Deplacement vertical
                if(x!=z && y==w){
                    if(x<z){
                        printf("Deplacement verticale vers le bas \n");
                        g=t[x][y];
                        t[x][y]=c;
                        t[z][w]=g;

                     //Suppression bass
                        for(i=z+1;i<=5;i++)
                        {
                            j=w;
                            if(t[i][j]==b){
                                t[i][j]=c;
                            }
                        }

                    //Suppression haut
                        for(i=x-1;i>=1;i--)
                        {
                            j=w;
                            if(t[i][j]==b){
                                t[i][j]=c;
                            }
                        }

                        for(i=1;i<=5;i++)
                        {
                            for(j=1;j<=5;j++)
                            {
                                printf("%4c", t[i][j]);
                            }
                            printf("\n");
                        }
                    }
                    if(x>z){
                        printf("Deplacement verticale vers le haut \n");
                        g=t[x][y];
                        t[x][y]=c;
                        t[z][w]=g;

                     //Suppression haut
                        for(i=w-1;i>=0;i--)
                        {
                            j=w;
                            t[i][j]=c;
                            if(t[i][j]==a){
                                t[i][j]=c;
                            }
                        }

                    //Suppression bas
                        for(i=x+1;i<=5;i++)
                        {
                            j=w;
                            t[i][j]=c;
                            if(t[i][j]==a){
                                t[i][j]=c;
                            }
                        }

                        for(i=1;i<=5;i++)
                        {
                            for(j=1;j<=5;j++)
                            {
                                printf("%4c", t[i][j]);
                            }
                            printf("\n");
                        }
                    }
                }

            //Deplacement horizontal
                if(x==z && y!=w){
                    if(y<w){
                        printf("Deplacement horizontal vers le droite \n");
                        g=t[x][y];
                        t[x][y]=c;
                        t[z][w]=g;

                     //Suppression
                        for(j=w-1;j>=1;j--)
                        {
                            i=z;
                            t[i][j]=c;
                        }

                        for(i=1;i<=5;i++)
                        {
                            for(j=1;j<=5;j++)
                            {
                                printf("%4c", t[i][j]);
                            }
                            printf("\n");
                        }
                    }
                    else{
                        printf("Deplacement horizontal vers le gauche \n");
                        g=t[x][y];
                        t[x][y]=c;
                        t[z][w]=g;

                     //Suppression
                        for(j=w+1;j<=5;j++)
                        {
                            i=z;
                            t[i][j]=c;
                        }

                        for(i=1;i<=5;i++)
                        {
                            for(j=1;j<=5;j++)
                            {
                                printf("%4c", t[i][j]);
                            }
                            printf("\n");
                        }
                    }
                }

            //Deplacement oblique droite
                if(x!=z && y!=w){
                    if(x<z && y>w){
                        printf("Deplacement oblique droite vers le bas \n");
                        g=t[x][y];
                        t[x][y]=c;
                        t[z][w]=g;

                     //Suppression

                        for(i=z-1;i>=1;i--)
                        {
                            for(j=w+1;j<=5;j++)
                            {
                                t[i][j]=c;
                            }
                        }

                        for(i=1;i<=5;i++)
                        {
                            for(j=1;j<=5;j++)
                            {
                                printf("%4c", t[i][j]);
                            }
                            printf("\n");
                        }
                    }
                    if(x>z && y<w){
                        printf("Deplacement oblique droite vers le haut");
                    }
                }

            //Deplacement oblique gauche
                if(x!=z && y!=w){
                    if(x<z && y<w){
                        printf("Deplacement oblique gauche vers le bas");
                    }
                    if(x>z && y>w){
                        printf("Deplacement oblique gauche vers le haut");
                    }
                }
            printf("\n");
        }
    }
}
