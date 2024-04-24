#include<stdio.h>

const int max_ligne = 5;
const int max_colonne = 9;

void affichage(char t[max_ligne][max_colonne]){
    int i,j;
    for(i=1;i<=max_ligne;i++){
        for(j=1;j<=max_colonne;j++){
            printf("%4c", t[i][j]);
        }
        printf("\n");
    }
}

int main(){
    char a='*', b='�', c='  ',g; // PIONS

    char J1='b', J2='a', J; // POUR LA PERMUTATION DES JOOUEURS
    int i,j; // INDICE TABLEAU
    int x,y,z,w; // COORDONNE DES PIONS ET PLACES
    int o; // CHOIX D'ELIMINATTION
    int ij,ji; // POUR L'ARRET DU JEUX
    int r; // POUR LA REPETITION
    char t[max_ligne][max_colonne];


        // Placement PIONS :
    for(i=1;i<=max_ligne;i++)
    {
        if(i==1 || i==2){
            for(j=1;j<=max_colonne;j++){
                t[i][j]=a;
            }
        }

        if(i==3){
            for(j=1;j<=max_colonne;j++){
                if(j==1 || j==3 ||  j==6 || j==8){
                    t[i][j]=a;
                }

                if(j==5){
                    t[i][j]=c;
                }

                if(j==2 || j==4 || j==7 || j==9){
                    t[i][j]=b;
                }
            }
        }

        if(i==4 || i==5){
            for(j=1;j<=max_colonne;j++){
                t[i][j]=b;
            }
        }
    }

    affichage(t);

    printf("\n");

    while(1<2){
        ij=0;
        ji=0;

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

                while(1>0){
                    r=-1;
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
                                    for(i=x+1;i<=max_ligne;i++){
                                        j=w;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}}
                                }
                            }
                            else{
                                if(t[z-1][w]==b){
                                    for(i=z-1;i>=1;i--){
                                        j=w;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(t[x+1][w]==b){
                                    for(i=x+1;i<=max_ligne;i++){
                                        j=w;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            affichage(t);
                        }

                        if(x<z){
                            if(t[z+1][w]==b && t[x-1][w]==b){
                                printf("Pour choisir le pions � �liminer, tapez 1 pour le haut ou 2 pour le bas\nEnter(1 ou 2) : ");
                                scanf("%d", &o);
                                if(o==1){
                                    for(i=x-1;i>=1;i--){
                                        j=w;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(o==2){
                                    for(i=z+1;i<=max_ligne;i++){
                                        j=w;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            else{
                                if(t[z+1][w]==b && t[x-1][w]!=b){
                                    for(i=z+1;i<=max_ligne;i++){
                                        j=w;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(t[z+1][w]!=b && t[x-1][w]!=b){
                                    for(i=x-1;i>=1;i--){
                                        j=w;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            affichage(t);
                        }
                    }

                    if(x==z && y!=w){
                        if(y<w){
                            if(t[z][w+1]==b && t[z][y-1]==b){
                                printf("Pour choisir le pions � �liminer, tapez 1 pour le droite ou 2 pour le gauche\nEnter(1 ou 2) : ");
                                scanf("%d", &o);
                                if(o==2){ //gauche
                                    for(j=y-1;j>=1;j--){
                                        i=z;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(o==1){
                                    for(j=w+1;j<=max_colonne;j++){
                                        i=z;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            else{
                                if(t[z][y-1]==b && t[z][w+1]!=b){ //gauche
                                    for(j=y-1;j>=1;j--){
                                        i=z;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(t[z][w+1]==b && t[z][y-1]!=b){ //droite
                                    for(j=w+1;j<=max_colonne;j++){
                                        i=z;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            affichage(t);
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
                                    for(j=y+1;j<=max_colonne;j++){
                                        i=z;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            else{
                                if(t[z][y+1]==b && t[z][w-1]!=b){
                                    for(j=y+1;j<=max_colonne;j++){
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
                            affichage(t);
                        }
                    }

                    if(x!=z && y!=w){
                        if(x>z && y<w){
                            if(t[z-1][w+1]==b && t[x+1][y-1]==b){
                                printf("Pour choisir le pion � �limin�, tapez 1 pour le haut sinon 2 : ");
                                scanf("%d", &o);
                                if(o==1){ //haut
                                    for(i=z-1;i>=1;i--){
                                        j=w+1;
                                        w=w+1;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }

                                if(o==2){
                                    for(i=x+1;i<=max_ligne;i++){
                                        j=y-1;
                                        y=y-1;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            else{
                                if(t[z-1][w+1]==b && t[x+1][y-1]!=b){
                                    for(i=z-1;i>=1;i--){
                                        j=w+1;
                                        w=w+1;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(t[z-1][w+1]!=b && t[x+1][y-1]==b){
                                    for(i=x+1;i<=max_ligne;i++){
                                        j=y-1;
                                        y=y-1;
                                        if(t[i][j]==a){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            affichage(t);
                        }

                    if(x<z && y>w){
                        if(t[z+1][w-1]==b && t[x-1][y+1]==b){
                            printf("Pour choisir le pion � �limin�, tapez 1 pour le haut sinon 2 : ");
                            scanf("%d", &o);
                            if(o==1){ //haut
                                for(i=z+1;i<=max_ligne;i++){
                                    j=w-1;
                                    w=w-1;
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                            if(o==2){
                                for(i=x-1;i>=1;i--){
                                    j=y+1;
                                    y=y+1;
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        else{
                            if(t[z+1][w-1]==b && t[x-1][y+1]!=b){
                                for(i=z+1;i<=max_ligne;i++){
                                    j=w-1;
                                    w=w-1;
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                            if(t[z+1][w-1]!=b && t[x-1][y+1]==b){
                                for(i=x-1;i>=1;i--){
                                    j=y+1;
                                    y=y+1;
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        affichage(t);
                    }
                    if(x>z && y>w){
                        if(t[z-1][w-1]==b && t[x+1][y+1]==b){
                            printf("Pour choisir le pion � �limin�, tapez 1 pour le haut sinon 2 : ");
                            scanf("%d", &o);
                            if(o==1){ //haut
                                for(i=z-1;i>=1;i--){
                                    j=w-1;
                                    w=w-1;
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                            if(o==2){
                                for(i=x+1;i<=max_ligne;i++){
                                    j=y+1;
                                    y=y+1;
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        else{
                            if(t[z-1][w-1]==b && t[x+1][y+1]!=b){
                                for(i=z-1;i>=1;i--){
                                    j=w-1;
                                    w=w-1;
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                            if(t[z-1][w-1]!=b && t[x+1][y+1]==b){
                                for(i=x+1;i<=max_ligne;i++){
                                    j=y+1;
                                    y=y+1;
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        affichage(t);
                    }

                    if(x<z && y<w){
                        if(t[z+1][w+1]==b && t[x-1][y-1]==b){
                            printf("Pour choisir le pion � �limin�, tapez 1 pour le haut sinon 2 : ");
                            scanf("%d", &o);
                            if(o==1){ //haut
                                for(i=x-1;i>=1;i--){
                                    j=y-1;
                                    y=y-1;
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                            if(o==2){
                                for(i=z+1;i<=max_ligne;i++){
                                    j=w+1;
                                    w=w+1;
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        else{
                            if(t[z+1][w+1]==b && t[x-1][y-1]!=b){
                                for(i=z+1;i<=max_ligne;i++){
                                    j=w+1;
                                    w=w+1;
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                            if(t[z+1][w+1]!=b && t[x-1][y-1]==b){
                                for(i=x-1;i>=1;i--){
                                    j=y-1;
                                    y=y-1;
                                    if(t[i][j]==a){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        affichage(t);
                    }
                }

            // RECOMMENCEMENT

                //Vertical
            if(t[z+1][w]==c && t[z-1][w]==b){r=r+1;}
            if(t[z+1][w]==c && t[z+2][w]==b){r=r+1;}
            if(t[z-1][w]==c && t[z+1][w]==b){r=r+1;}
            if(t[z-1][w]==c && t[z-2][w]==b){r=r+1;}

                //Horizontal
            if(t[z][w-1]==c && t[z][w+1]==b){r=r+1;}
            if(t[z][w-1]==c && t[z][w-2]==b){r=r+1;}
            if(t[z][w+1]==c && t[z][w-1]==b){r=r+1;}
            if(t[z][w+1]==c && t[z][w+2]==b){r=r+1;}

                //Oblique (\)
            if(t[z-1][w-1]==c && t[z+1][w+1]==b){r=r+1;}
            if(t[z-1][w-1]==c && t[z-2][w-2]==b){r=r+1;}
            if(t[z+1][w+1]==c && t[z-1][w-1]==b){r=r+1;}
            if(t[z+1][w+1]==c && t[z+2][w+2]==b){r=r+1;}

                //Oblique (/)
            if(t[z-1][w+1]==c && t[z+1][w-1]==b){r=r+1;}
            if(t[z-1][w+1]==c && t[z-2][w+2]==b){r=r+1;}
            if(t[z+1][w-1]==c && t[z-1][w+1]==b){r=r+1;}
            if(t[z+1][w-1]==c && t[z+2][w-2]==b){r=r+1;}

            printf("r = %d \n", r);

            if(r>=1){
                while(2>1){

                    x=z;
                    y=w;

                    printf("Coordonne lieu(z,w) \nEntrer z : ");
                    scanf("%d", &z);
                    printf("Entrer w : ");
                    scanf("%d", &w);
                    printf("\n");

                    if(t[x][y]==a && t[z][w]==c){
                        if(t[x+1][y]==t[z][w] || t[x-1][y]==t[z][w] || t[x][y+1]==t[z][w] || t[x][y-1]==t[z][w] || t[x+1][y+1]==t[z][w] || t[x-1][y-1]==t[z][w] || t[x-1][y+1]==t[z][w] || t[x+1][y-1]==t[z][w] && x!=z && y!=w){
                            break;
                        }
                    }
                    else{printf("Deplacement impossible, Recommencer\n");}
                }
            }
            else{break;}
        }
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
                        if(t[x+1][y]==t[z][w] || t[x-1][y]==t[z][w] || t[x][y+1]==t[z][w] || t[x][y-1]==t[z][w] || t[x+1][y+1]==t[z][w] || t[x-1][y-1]==t[z][w] || t[x-1][y+1]==t[z][w] || t[x+1][y-1]==t[z][w]){
                            break;
                        }
                    }
                    else{printf("Deplacement impossible, Recommencer\n");}
                }
            while(1>0){
                    g=t[x][y];
                    t[x][y]=c;
                    t[z][w]=g;

                    if(x!=z && y==w){
                        if(x>z){
                            if(t[z-1][w]==a && t[x+1][w]==a){
                                printf("Pour choisir le pions � �liminer, tapez 1 pour le haut ou 2 pour le bas\nEnter(1 ou 2) : ");
                                scanf("%d", &o);
                                if(o==1){
                                    for(i=z-1;i>=1;i--){
                                        j=w;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}}
                                }
                                if(o==2){
                                    for(i=x+1;i<=max_ligne;i++){
                                        j=w;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}}
                                }
                            }
                            else{
                                if(t[z-1][w]==a){
                                    for(i=z-1;i>=1;i--){
                                        j=w;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(t[x+1][w]==a){
                                    for(i=x+1;i<=max_ligne;i++){
                                        j=w;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            affichage(t);
                        }

                        if(x<z){
                            if(t[z+1][w]==a && t[x-1][w]==a){
                                printf("Pour choisir le pions � �liminer, tapez 1 pour le haut ou 2 pour le bas\nEnter(1 ou 2) : ");
                                scanf("%d", &o);
                                if(o==1){
                                    for(i=x-1;i>=1;i--){
                                        j=w;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(o==2){
                                    for(i=z+1;i<=max_ligne;i++){
                                        j=w;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            else{
                                if(t[z+1][w]==a && t[x-1][w]!=a){
                                    for(i=z+1;i<=max_ligne;i++){
                                        j=w;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(t[z+1][w]!=a && t[x-1][w]!=a){
                                    for(i=x-1;i>=1;i--){
                                        j=w;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            affichage(t);
                        }
                    }

                    if(x==z && y!=w){
                        if(y<w){
                            if(t[z][w+1]==a && t[z][y-1]==a){
                                printf("Pour choisir le pions � �liminer, tapez 1 pour le droite ou 2 pour le gauche\nEnter(1 ou 2) : ");
                                scanf("%d", &o);
                                if(o==2){ //gauche
                                    for(j=y-1;j>=1;j--){
                                        i=z;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(o==1){
                                    for(j=w+1;j<=max_colonne;j++){
                                        i=z;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            else{
                                if(t[z][y-1]==a && t[z][w+1]!=a){ //gauche
                                    for(j=y-1;j>=1;j--){
                                        i=z;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(t[z][w+1]==a && t[z][y-1]!=a){ //droite
                                    for(j=w+1;j<=max_colonne;j++){
                                        i=z;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            affichage(t);
                        }

                        if(y>w){
                            if(t[z][w-1]==a && t[z][y+1]==a){
                                printf("Pour choisir le pions � �liminer, tapez 1 pour le droite ou 2 pour le gauche\nEnter(1 ou 2) : ");
                                scanf("%d", &o);
                                if(o==2){ //gauche
                                    for(j=w-1;j>=1;j--){
                                        i=z;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(o==1){ //droite
                                    for(j=y+1;j<=max_colonne;j++){
                                        i=z;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            else{
                                if(t[z][y+1]==a && t[z][w-1]!=a){
                                    for(j=y+1;j<=max_colonne;j++){
                                        i=z;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }

                                if(t[z][w-1]==a && t[z][y+1]!=a){
                                    for(j=w-1;j>=1;j--){
                                        i=z;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            affichage(t);
                        }
                    }
                    if(x!=z && y!=w){
                        if(x>z && y<w){
                            if(t[z-1][w+1]==a && t[x+1][y-1]==a){
                                printf("Pour choisir le pion � �limin�, tapez 1 pour le haut sinon 2 : ");
                                scanf("%d", &o);
                                if(o==1){ //haut
                                    for(i=z-1;i>=1;i--){
                                        j=w+1;
                                        w=w+1;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }

                                if(o==2){
                                    for(i=x+1;i<=max_ligne;i++){
                                        j=y-1;
                                        y=y-1;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            else{
                                if(t[z-1][w+1]==a && t[x+1][y-1]!=a){
                                    for(i=z-1;i>=1;i--){
                                        j=w+1;
                                        w=w+1;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                                if(t[z-1][w+1]!=a && t[x+1][y-1]==a){
                                    for(i=x+1;i<=max_ligne;i++){
                                        j=y-1;
                                        y=y-1;
                                        if(t[i][j]==b){break;}
                                        else{t[i][j]=c;}
                                    }
                                }
                            }
                            affichage(t);
                        }

                    if(x<z && y>w){
                        if(t[z+1][w-1]==a && t[x-1][y+1]==a){
                            printf("Pour choisir le pion � �limin�, tapez 1 pour le haut sinon 2 : ");
                            scanf("%d", &o);
                            if(o==1){ //haut
                                for(i=z+1;i<=max_ligne;i++){
                                    j=w-1;
                                    w=w-1;
                                    if(t[i][j]==b){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                            if(o==2){
                                for(i=x-1;i>=1;i--){
                                    j=y+1;
                                    y=y+1;
                                    if(t[i][j]==b){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        else{
                            if(t[z+1][w-1]==a && t[x-1][y+1]!=a){
                                for(i=z+1;i<=max_ligne;i++){
                                    j=w-1;
                                    w=w-1;
                                    if(t[i][j]==b){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                            if(t[z+1][w-1]!=a && t[x-1][y+1]==a){
                                for(i=x-1;i>=1;i--){
                                    j=y+1;
                                    y=y+1;
                                    if(t[i][j]==b){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        affichage(t);
                    }
                    if(x>z && y>w){
                        if(t[z-1][w-1]==a && t[x+1][y+1]==a){
                            printf("Pour choisir le pion � �limin�, tapez 1 pour le haut sinon 2 : ");
                            scanf("%d", &o);
                            if(o==1){ //haut
                                for(i=z-1;i>=1;i--){
                                    j=w-1;
                                    w=w-1;
                                    if(t[i][j]==b){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                            if(o==2){
                                for(i=x+1;i<=max_ligne;i++){
                                    j=y+1;
                                    y=y+1;
                                    if(t[i][j]==b){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        else{
                            if(t[z-1][w-1]==a && t[x+1][y+1]!=a){
                                for(i=z-1;i>=1;i--){
                                    j=w-1;
                                    w=w-1;
                                    if(t[i][j]==b){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                            if(t[z-1][w-1]!=a && t[x+1][y+1]==a){
                                for(i=x+1;i<=max_ligne;i++){
                                    j=y+1;
                                    y=y+1;
                                    if(t[i][j]==b){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        affichage(t);
                    }

                    if(x<z && y<w){
                        if(t[z+1][w+1]==a && t[x-1][y-1]==a){
                            printf("Pour choisir le pion � �limin�, tapez 1 pour le haut sinon 2 : ");
                            scanf("%d", &o);
                            if(o==1){ //haut
                                for(i=x-1;i>=1;i--){
                                    j=y-1;
                                    y=y-1;
                                    if(t[i][j]==b){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                            if(o==2){
                                for(i=z+1;i<=max_ligne;i++){
                                    j=w+1;
                                    w=w+1;
                                    if(t[i][j]==b){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        else{
                            if(t[z+1][w+1]==a && t[x-1][y-1]!=a){
                                for(i=z+1;i<=max_ligne;i++){
                                    j=w+1;
                                    w=w+1;
                                    if(t[i][j]==b){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                            if(t[z+1][w+1]!=a && t[x-1][y-1]==a){
                                for(i=x-1;i>=1;i--){
                                    j=y-1;
                                    y=y-1;
                                    if(t[i][j]==b){break;}
                                    else{t[i][j]=c;}
                                }
                            }
                        }
                        affichage(t);
                    }
                }

                    // RECOMMENCEMENT
                r=0;
                    //Vertical
                if(t[z+1][w]==c && t[z-1][w]==a){r=r+1;}
                if(t[z+1][w]==c && t[z+2][w]==a){r=r+1;}
                if(t[z-1][w]==c && t[z+1][w]==a){r=r+1;}
                if(t[z-1][w]==c && t[z-2][w]==a){r=r+1;}

                    //Horizontal
                if(t[z][w-1]==c && t[z][w+1]==a){r=r+1;}
                if(t[z][w-1]==c && t[z][w-2]==a){r=r+1;}
                if(t[z][w+1]==c && t[z][w-1]==a){r=r+1;}
                if(t[z][w+1]==c && t[z][w+2]==a){r=r+1;}

                    //Oblique (\)
                if(t[z-1][w-1]==c && t[z+1][w+1]==a){r=r+1;}
                if(t[z-1][w-1]==c && t[z-2][w-2]==a){r=r+1;}
                if(t[z+1][w+1]==c && t[z-1][w-1]==a){r=r+1;}
                if(t[z+1][w+1]==c && t[z+2][w+2]==a){r=r+1;}

                    //Oblique (/)
                if(t[z-1][w+1]==c && t[z+1][w-1]==a){r=r+1;}
                if(t[z-1][w+1]==c && t[z-2][w+2]==a){r=r+1;}
                if(t[z+1][w-1]==c && t[z-1][w+1]==a){r=r+1;}
                if(t[z+1][w-1]==c && t[z+2][w-2]==a){r=r+1;}

                printf("r = %d \n", r);

                if(r>=1){
                    while(2>1){
                        r=0;
                        x=z;
                        y=w;

                        printf("Coordonne lieu(z,w) \nEntrer z : ");
                        scanf("%d", &z);
                        printf("Entrer w : ");
                        scanf("%d", &w);
                        printf("\n");

                        if(t[x][y]==b && t[z][w]==c){
                            if(t[x+1][y]==t[z][w] || t[x-1][y]==t[z][w] || t[x][y+1]==t[z][w] || t[x][y-1]==t[z][w] || t[x+1][y+1]==t[z][w] || t[x-1][y-1]==t[z][w] || t[x-1][y+1]==t[z][w] || t[x+1][y-1]==t[z][w] && x!=z && y!=w){
                                break;
                            }
                        }
                        else{printf("Deplacement impossible, Recommencer\n");}
                    }
                }
                else{break;}
            }
    }
            // ARRET GAGNANT:
                for(i=1;i<=max_ligne;i++){
                    for(j=1;j<=max_colonne;j++){
                        if(t[i][j]==c){
                            ij=ij+1;
                            ji=ji+1;
                        }
                        if(t[i][j]==a){
                            ij=ij+1;
                        }
                        if(t[i][j]==b){
                            ji=ji+1;
                        }
                    }
                }

                if(ij==45){
                    printf("Joueur A a gagn�");
                    break;
                }

                if(ji==45){
                    printf("Joueur B a gagn�");
                    break;
                }
        J2=J;
    }
}
