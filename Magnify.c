#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
FILE *A=fopen("fnu_m62_0.001Gyr","r");
FILE *B=fopen("fnu_m62_12.5Gyr","r");
FILE *C=fopen("youngest.txt","w");
FILE *D=fopen("oldest.txt","w");

int i,j;
float x,y,w,z;
float young1[1221];
float young2[1221];
float old1[1221];
float old2[1221];

while(fscanf(A,"%f %f",&x,&y)!=EOF){
        young1[i]=x;
        young2[i]=y*(5*(pow(10,12)));
        fprintf(C,"%e %e\n",young1[i],young2[i]);
        i++;
}

while(fscanf(B,"%f %f",&w,&z)!=EOF){
        old1[j]=w;
        old2[j]=z*(7.9*(pow(10,14)));
        fprintf(D,"%e %e\n",old1[j],old2[j]);
        j++;
}

fclose(A);
fclose(B);
fclose(C);
fclose(D);
}

