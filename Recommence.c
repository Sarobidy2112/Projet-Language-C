#include<stdio.h>
int main(){
    int r=-1;

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

    if(r>=1){}
    else{break;}
}
