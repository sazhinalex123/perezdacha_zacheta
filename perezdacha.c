#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
int main(){
    double**arr;
int a,b,i,j;
int p,l;
int q=0;
int tmp;
int u;
FILE*input_file;
FILE*output_file;
output_file=fopen("data.res","w");
input_file=fopen("data.dat","r");
if(!input_file){
    printf("Oshibka\n");
    return -2;
}

fscanf(input_file,"%d",&a);
fscanf(input_file,"%d",&b);
l=a+1;
p=b+1;
if((a<=0)||(b<=0)){
        printf("Oshibka s razmerom\n");
        exit(4);
    }
    arr=(double**)malloc(a*sizeof(double*));
    if(arr==NULL){
        printf("Oshibka s pamyatiu\n");
        exit(1);
    }
    for(i=0;i<a;i++){
        arr[i]=(double*)malloc(b*sizeof(double));
        if(arr[i]==NULL){
            printf("Oshibka s pamyatiu1\n");
            for(int m=0;m<i;i++){
                free (arr[m]);
            }
            exit(2);
        }
    }
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){
            fscanf(input_file, "%lf",&(arr[i][j]));
        }
    }
    for(i=0;i<a;i++){
        for(j=0;j<b-1;j++){
            for(u=0;u<b-1;u++){
            if(arr[i][u]>arr[i][u+1]){
                tmp=arr[i][u];
                arr[i][u]=arr[i][u+1];
                arr[i][u+1]=tmp;
            }
        }
    }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            fprintf(output_file,"%lf ",arr[i][j]);
            if(j==b-1){
                fprintf(output_file,"\n");
            }
         }
    }
    free(arr);
    for(int i=0;i<a;i++){
        free(arr[i]);
    }
    fclose(output_file);
    fclose(input_file);
    return 0;
}
