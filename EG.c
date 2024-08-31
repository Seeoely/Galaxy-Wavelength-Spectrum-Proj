#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float proj(char Gal[100], char Band[20], int max, char file[100]){
        FILE *A=fopen(Gal,"r");
        FILE *B=fopen(Band,"r");
        FILE *C=fopen(file,"a");

        int x;
        float y;
        float u;
        float v;
        float sum1=0;
        float sum2=0;
        float integration;
        float mAB;
        int i=0;
        int j=0;
        int k=0;
        int n=0;
        int m=0;
        float Pass1[200];
	float Spec1[1221];
        float Pass2[200];
        float Spec2[1221];
        float Spec3[200];
        float Spec4[200];
        float Inter[200];
        float Mult[200];

        while(fscanf(B,"%d   %f",&x,&y)!=EOF){
                Pass1[i]=x;
                Pass2[i]=y;
		i++;
        }

        while(fscanf(A,"%e %e",&u,&v)!=EOF){
                Spec1[j]=u;
                Spec2[j]=v;
                if(u>=Pass1[0] && u<=max){
                        Spec3[k]=u;
                        Spec4[k]=v;
                        k++;
                }
                j++;
        }

        for(n=0;n<=45;n++){
                while(Spec3[m]>=Pass1[n] && Spec3[m]<=Pass1[n+1]){
                        Inter[m]=(Pass2[n]+((Pass2[n+1]-Pass2[n])/(Pass1[n+1]-Pass1[n]))*(Spec3[m]-Pass1[n]));//(Spec3[k],Inter[k]) interpolated Pass coord
                        Mult[m]=(Inter[m]*Spec4[m]);
                        sum1=sum1+Mult[m];
                        sum2=sum2+Inter[m];
			m++;
                }
        }
 
	integration=sum1/sum2;
        mAB=-2.5*log10(integration);
        fprintf(C,"%e\n",mAB);
	
	fclose(A);
        fclose(B);
        fclose(C);
	
	return(mAB);
}


int main(){
char file1[100]={"Mags.txt"};

char Gal1[100]={"/Users/colevogt/Downloads/Astro/Model_Spectra-1/fnu_m62_0.001Gyr"};
char Gal2[100]={"/Users/colevogt/Downloads/Astro/Model_Spectra-1/fnu_m62_0.06Gyr"};
char Gal3[100]={"/Users/colevogt/Downloads/Astro/Model_Spectra-1/fnu_m62_0.8Gyr"};
char Gal4[100]={"/Users/colevogt/Downloads/Astro/Model_Spectra-1/fnu_m62_2.0Gyr"};
char Gal5[100]={"/Users/colevogt/Downloads/Astro/Model_Spectra-1/fnu_m62_3.0Gyr"};
char Gal6[100]={"/Users/colevogt/Downloads/Astro/Model_Spectra-1/fnu_m62_4.5Gyr"};
char Gal7[100]={"/Users/colevogt/Downloads/Astro/Model_Spectra-1/fnu_m62_6.5Gyr"};
char Gal8[100]={"/Users/colevogt/Downloads/Astro/Model_Spectra-1/fnu_m62_9.5Gyr"};
char Gal9[100]={"/Users/colevogt/Downloads/Astro/Model_Spectra-1/fnu_m62_10.0Gyr"};
char Gal10[100]={"/Users/colevogt/Downloads/Astro/Model_Spectra-1/fnu_m62_12.5Gyr"};

char uBand[100]={"/Users/colevogt/Downloads/Astro/sdss_response/sys.u"};
char gBand[100]={"/Users/colevogt/Downloads/Astro/sdss_response/sys.g"};
char rBand[100]={"/Users/colevogt/Downloads/Astro/sdss_response/sys.r"};
char iBand[100]={"/Users/colevogt/Downloads/Astro/sdss_response/sys.i"};
char zBand[100]={"/Users/colevogt/Downloads/Astro/sdss_response/sys.z"};

proj(Gal1,uBand,4130,file1);
proj(Gal1,gBand,5830,file1);
proj(Gal1,rBand,7230,file1);
proj(Gal1,iBand,8630,file1);
proj(Gal1,zBand,11230,file1);

proj(Gal2,uBand,4130,file1);
proj(Gal2,gBand,5830,file1);
proj(Gal2,rBand,7230,file1);
proj(Gal2,iBand,8630,file1);
proj(Gal2,zBand,11230,file1);

proj(Gal3,uBand,4130,file1);
proj(Gal3,gBand,5830,file1);
proj(Gal3,rBand,7230,file1);
proj(Gal3,iBand,8630,file1);
proj(Gal3,zBand,11230,file1);

proj(Gal4,uBand,4130,file1);
proj(Gal4,gBand,5830,file1);
proj(Gal4,rBand,7230,file1);
proj(Gal4,iBand,8630,file1);
proj(Gal4,zBand,11230,file1);

proj(Gal5,uBand,4130,file1);
proj(Gal5,gBand,5830,file1);
proj(Gal5,rBand,7230,file1);
proj(Gal5,iBand,8630,file1);
proj(Gal5,zBand,11230,file1);

proj(Gal6,uBand,4130,file1);
proj(Gal6,gBand,5830,file1);
proj(Gal6,rBand,7230,file1);
proj(Gal6,iBand,8630,file1);
proj(Gal6,zBand,11230,file1);

proj(Gal7,uBand,4130,file1);
proj(Gal7,gBand,5830,file1);
proj(Gal7,rBand,7230,file1);
proj(Gal7,iBand,8630,file1);
proj(Gal7,zBand,11230,file1);

proj(Gal8,uBand,4130,file1);
proj(Gal8,gBand,5830,file1);
proj(Gal8,rBand,7230,file1);
proj(Gal8,iBand,8630,file1);
proj(Gal8,zBand,11230,file1);

proj(Gal9,uBand,4130,file1);
proj(Gal9,gBand,5830,file1);
proj(Gal9,rBand,7230,file1);
proj(Gal9,iBand,8630,file1);
proj(Gal9,zBand,11230,file1);

proj(Gal10,uBand,4130,file1);
proj(Gal10,gBand,5830,file1);
proj(Gal10,rBand,7230,file1);
proj(Gal10,iBand,8630,file1);
proj(Gal10,zBand,11230,file1);
}
