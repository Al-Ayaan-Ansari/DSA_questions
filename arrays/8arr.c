#include<stdio.h>

void ganja()
{
    printf("siraj ganja");
}
int printarr(int arr[],int asize){
    for(int i=0;i<asize;i++){
        printf("%d",arr[i]);
    }
    return 0;
}



int main(){
    int n=98456234;
    int i;
    int arr[8];
    for(i=0;i<8;i++){
        int a= n%10;
        arr[7-i]=a;
        n=n/10;
    }
    int revarr[8];
    for(int j=0;j<8;j++){
        revarr[7-j]=arr[j];
    }
    printarr(arr,8);
    printf("\n");
    printarr(revarr,8);
    return 0;
    ganja();

    

    
}

