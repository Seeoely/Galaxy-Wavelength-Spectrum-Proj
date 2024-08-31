#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
FILE *A=fopen("Mags.txt","r");
FILE *B=fopen("Magnitudes.txt","w");
FILE *C=fopen("u_g_r.txt","w");
FILE *D=fopen("r_i_z.txt","w");

float x;
int i;
int j=0;
int k=0;
char Age[10][200]={"0.001Gyr:","0.06Gyr:","0.8Gyr:","2.0Gyr:","3.0Gyr:","4.5Gyr:","6.5Gyr:","9.5Gyr:","10.0Gyr:","12.5Gyr:"};
float Mag[50];
while(fscanf(A,"%e",&x)!=EOF){
	Mag[j]=x;
	j++;
}

for(i=0;i<50;i=i+5){
	fprintf(B,"%s\n[u]=%e\n[g]=%e\n[r]=%e\n[i]=%e\n[z]=%e\n[u-g]=%e\n[g-r]=%e\n[r-i]=%e\n[i-z]=%e\n\n",Age[k],Mag[i],Mag[i+1],Mag[i+2],Mag[i+3],Mag[i+4],Mag[i]-Mag[i+1],Mag[i+1]-Mag[i+2],Mag[i+2]-Mag[i+3],Mag[i+3]-Mag[i+4]);
fprintf(C,"%e %e\n",Mag[i]-Mag[i+1],Mag[i+1]-Mag[i+2]);
fprintf(D,"%e %e\n",Mag[i+2]-Mag[i+3],Mag[i+3]-Mag[i+4]);
k++;
}
fclose(A);
fclose(B);
fclose(C);
fclose(D);
}
