#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
int m = 0;
int n = 0;
int k = 0;
int lecturarb_num(){
	FILE *archivo;
	char magico[8];
	int a=8;

	archivo=fopen("bacterias.bin","rb");

	char *fgets(char *m,int a,FILE *archivo);

	if(magico == "7201D2ED"){
		printf("ES EL NUMERO MAGICO");
		return 1;
	}
	else{
		printf("NO ES EL NUMERO MAGICO");
		return 0;
	}
}
int lecturarb_m (){
    FILE *archivo;
    int m;
	int j=4;
    archivo=fopen("bacterias.bin","rb");
	int *fgets(int *m, int j, FILE *archivo);

    return m;
}
int lecturarb_n (){
    FILE *archivo;
    char n;
    int l=4;
    archivo=fopen("bacterias.bin","rb");
    char *fgets(char *n,int l,FILE *archivo);

    return n;
}
int lecturarb_k (){
    FILE *archivo;
    char k;
    int x=4;
    archivo=fopen("bacterias.bin","rb");
    char*fgets(char *k,int x,FILE  *archivo);
    return k;
}
int lecturarb_muertas(int k){
	FILE *archivo;
	int x =4;
    int muerta [2][k];
    archivo=fopen("bacterias.bin","rb");
    for (int t=0; t<k;t++){
	for (int y=0; y<2;y++){

    int *fgets(int muerta,int  x,FILE * archivo);

        }
	}
	return muerta [2][k];
}

int guardar(int wena){
	FILE *archivo;
	archivo=fopen("bacterias.bin","a+b");
	char hex[8];
	int j =8;
	while(j!=0){

    sprintf(&hex[0], "%08x", wena);

	}
	for(int i=0;i<8;i++){
		fputs(hex,archivo);
	}
	fclose(archivo);
}


void Imprimir(int valores[][25], int m, int n )
{
 int i=0;
 int j =0;
for(j=0;j<n;j++){
 for (i=0; i<m; ++i){
      printf("%d\t",valores[i][j]);
 printf("\n");
        }
    }
}
void Duplicar(int NFIL, int NCOL,int ori[][25], int dest[ ][25]){
    for(int i=0;i<NFIL;i++){
        for(int j=0;j<NCOL;j++){
            dest[i][j]=ori[i][j];
    	}
	}
}

void Refrescar(int NFIL,int NCOL ,int Matriz[][25]){
    int copiamatriz[NFIL][25];
    int NUMcelulasvivas=0,i,j;
    Duplicar(NFIL ,NCOL ,Matriz, copiamatriz);
    for(i=0;i<NFIL;i++){
        for(j=0;j<NCOL;j++){
            if(i>0 && j>0 && Matriz[i-1][j-1]==1){
                NUMcelulasvivas++;
            }
            if(i>0 && Matriz[i-1][j]==1){
                NUMcelulasvivas++;
            }
            if(i>0 && j<NCOL && Matriz[i-1][j+1]==1){
                NUMcelulasvivas++;
            }
            if(j>0 && Matriz[i][j-1]==1){
                NUMcelulasvivas++;
            }
            if(j<NCOL && Matriz[i][j+1]==1){
                NUMcelulasvivas++;
            }
            if(i<NFIL && j>0 && Matriz[i+1][j-1]==1){
                NUMcelulasvivas++;
            }
            if(i<NFIL && Matriz[i+1][j]==1){
                NUMcelulasvivas++;
            }
            if(i<NFIL && j<NCOL && Matriz[i+1][j+1]==1){
                NUMcelulasvivas++;
            }
            if(Matriz[i][j]==1){
                if(NUMcelulasvivas==2 || NUMcelulasvivas==3){
                    copiamatriz[i][j]=1;
                }
                else{
                    copiamatriz[i][j]=0;
                }
            }
            else{
                if(NUMcelulasvivas==3){
                    copiamatriz[i][j]=1;
                }
            }
            //Ponemos a 0 el contador
            NUMcelulasvivas=0;
        }
    }
    Duplicar(NFIL,NCOL,copiamatriz, Matriz);
}
void Resucitar(int NFIL, int NCOL,int Matriz[][25])
	{
    int i,j,a,b;
    do{
        printf("Introduce fila <1-%d>: ", NFIL);
        i=getche()-48;
        fflush(stdin);
    }while(i<1 || i>NFIL);
    do{
        printf("\nIntroduce columna <1-%d>: ", NCOL);
        j=getche()-48;
        fflush(stdin);
    }while(j<1 || j>NCOL);


    Matriz[i-1][j-1]=1;
    system("cls");
    Imprimir(Matriz,NFIL,NCOL);
    printf("\nCompruebe la seleccion, desea mantenerla? [s/n]");
    b=getch();
    fflush(stdin);
    if(b=='n') Matriz[i-1][j-1]=a;
}
void Patron(int NFIL,int NCOL, int Matriz[][25]){
    Matriz[NFIL-(NFIL/2+1)][NCOL-(NCOL/2+1)]=1; //1 Posicion (1,1) del patron
    Matriz[NFIL-(NFIL/2+1)][NCOL-(NCOL/2)]=1;   //2 Posicion (1,2) del patron
    Matriz[NFIL-(NFIL/2+1)][NCOL-(NCOL/2-1)]=0; //3 Posicion (1,3) del patron
    Matriz[NFIL-NFIL/2][NCOL-(NCOL/2+1)]=1;     //4 Posicion (2,1) del patron
    Matriz[NFIL-(NFIL/2)][NCOL-(NCOL/2)]=0;     //5 Posicion (2,2) del patron
    Matriz[NFIL-(NFIL/2)][NCOL-(NCOL/2-1)]=1;   //6 Posicion (2,3) del patron
    Matriz[NFIL-(NFIL/2-1)][NCOL-(NCOL/2+1)]=0; //7 Posicion (3,1) del patron
    Matriz[NFIL-(NFIL/2-1)][NCOL-(NCOL/2)]=1;   //8 Posicion (3,2) del patron
    Matriz[NFIL-(NFIL/2-1)][NCOL-(NCOL/2-1)]=0; //9 Posicion (3,3) del patron



}
int Juego(int NFIL, int NCOL,int muerte[][25]){
    int Matriz [NFIL][25];
    int poblacion=0;
    int i = NFIL;
    int j = NCOL;
    char confirmar;
    char repetir;


        system("cls");
        do{
            printf("\n\tNivel de poblacion:\n");
            printf("\n\t1-leer\n");
            printf("\t2-evolucion\n");
            printf("\t3-return\n");


            poblacion=getch();
            fflush(stdin);

            system ("cls");
        }
        while(!(poblacion=='1' || poblacion=='2' || poblacion=='3' ));
        for(i=0;i<NFIL;i++){
            for(j=0;j<NCOL;j++){
                Matriz [i][j]=0;
            }
        }
        if(poblacion == '1')
            poblacion=(((NFIL*NCOL)/100));

        else if(poblacion=='2'){
            Resucitar(NFIL,NCOL,Matriz);

        };
        else{
               return 0 ;
}



		for (int p = 0; p<k; i++) {
			for (int k = 0; k<2; j++)

				Matriz[muerte[j][i]][muerte[j + 1][i]] = 1;
			if (Matriz[muerte[j][i]][muerte[j + 1][i]] == 0) {
				Matriz[muerte[j][i]][muerte[j + 1][i]] = 1;
			}
		}

        char letra;
        do{
        do{
            do
            {
                system("cls");
                Imprimir(Matriz ,NFIL,NCOL);
                printf("\nPulse una tecla: \n[s] para salir \n[c] para revivir celula \n[f] para introducir forma");
                letra=getch();
                fflush(stdin);
                if(letra=='s'){
                    system("cls");
                    Imprimir(Matriz,NFIL,NCOL);
                    printf("\nFin del juego");
                }
                else if(letra=='f'){
                    Patron(NFIL,NCOL,Matriz);
                }
                else if(letra=='c'){
                    system("cls");
                    Imprimir(Matriz,NFIL,NCOL);
                    Resucitar(NFIL,NCOL,Matriz);
                }
                else{
                    Refrescar(NFIL,NCOL,Matriz);
                }
            }while(letra!='s');
            system("cls");
            printf("\n\n\n\n%20cSeguro que quieres salir? [s/n]", ' ');
            char confirmar=getch();
            fflush(stdin);

        }while(confirmar=='n');
        system("cls");
        printf("\n\n\n\n%20cVolver a empezar? [s/n]", ' ');
        repetir=getch();
        fflush(stdin);

    }while(  repetir=='s');


}
int main(){
	int empezamos = lecturarb_num();
	int m = lecturarb_m();
	int n = lecturarb_n();
	int k = lecturarb_k();
	k=25;
	int muerte[2][k];
	muerte[2][k]= lecturarb_muertas(k);
    Juego(m,n,muerte);
    return 0;
}
