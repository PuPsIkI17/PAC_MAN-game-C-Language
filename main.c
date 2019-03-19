// Pîslari Vadim
#include <stdio.h>

//functia care afiseaza joaca
void afisare(int N, int M, int x, int y, int pers, int x1, int y1,
        int x2, int y2 ,int x3, int y3){
    int i, j;//variabile contor
    for(i = 0; i != N; i++){
        for(j = 0; j != M; j++){
            if(i==0 || i == N-1) printf("*");
            else if(j == 0 || j == M-1) printf("*");
            else if(i == x && j == y) printf("%c",pers);
            else if(i == x1 && j == y1 && x1 != 0 ) printf("x");
            else if(i == x2 && j == y2 && x2 != 0 ) printf("x");
            else if(i == x3 && j == y3 && x3 != 0 ) printf("x");
            else printf(" ");
        }
        printf("\n");
    }
}


int main(){

//x,y--coordonatele; N,M,P--variabile cerute in enuntul problemei;

int N, M,  x, y, P;

// misc--miscarile(a,s,d,w); pers--personajul;
char misc, pers = 'v';

//x1,y1-coordonatele primului obstacol, c1-tipul lui
int x1 = 0, y1 = 0;
char c1;

//x2,y2-coordonatele al 2 obstacol, c2-tipul lui
int x2 = 0 , y2 = 0;
char c2;

//x3,y3-coordonatele al treilea obstacol, c3-tipul lui
int x3 = 0, y3 = 0;
char c3;

/*variabile ce verifica daca este a doua
 miscare pentru obstacole mobile */
int pas1 = 0 ,pas2 = 0 ,pas3 = 0;

scanf("%d %d %d %d %d",&N ,&M ,&y ,&x ,&P);

if(P>=1){
    scanf("%d %d %c",&x1,&y1,&c1);
}

if(P>=2){
    scanf("%d %d %c",&x2,&y2,&c2);
}
if(P==3){
    scanf("%d %d %c",&x3,&y3,&c3 );
}

N += 2;
M += 2;

//prima reprezentare a jocucului
afisare(N, M, x, y, pers, x1, y1, x2, y2, x3, y3);

while(scanf(" %c",&misc)){
    if(misc == 'q') break;
     //miscarea in dependenta de valorile primite
     if(misc == 'w'){//sus
        if (x != 1){
            x--;
            pers='^';
        }
    }
     else if(misc == 'a'){//stanga
        if(y != 1){
            y--;
            pers = '<';
        }
     }
     else if (misc == 's'){//jos
        if(x != N-2){
            x++;
            pers = 'v';
        }
     }
     else if (misc == 'd'){//dreapta
        if(y != M-2){
            y++;
            pers = '>';
        }
    }

    //miscarea obstacolelor mobile
    if(c1 == 'm') pas1++;
    if(pas1 == 2){
        if(x != x1){
           if(x > x1) x1++;
           else x1--;
        }
        if(y != y1){
           if( y> y1) y1++;
           else y1--;
        }
        pas1= 0;
    }

    if(c2 == 'm') pas2++;
    if( pas2== 2){
        if(x != x2){
           if(x > x2) x2++;
           else x2--;
        }
        if(y != y2){
           if(y > y2) y2++;
           else y2--;
        }
        pas2 = 0;
    }

    if(c3 == 'm') pas3++;
    if(pas3 == 2){
        if(x != x3){
           if(x > x3) x3++;
           else x3--;
        }
        if(y != y3){
           if(y > y3) y3++;
           else y3--;
        }
        pas3 = 0;
    }
    //se verifica daca personajul nu a dat peste obstacol
    if( (x == x1 && y == y1) || (x == x2 && y == y2) || (x == x3 && y == y3)){
        printf("GAME OVER\n");
        break;
    }

    afisare(N ,M ,x ,y ,pers ,x1 ,y1 ,x2 ,y2 ,x3 ,y3);

    //se verifica daca sa finisat jocul
    if(x == N-2 && y == M-2){
        printf("GAME COMPLETED\n");
        break;
    }

}

return 0;
}





