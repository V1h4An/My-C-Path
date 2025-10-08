#include <stdio.h>
#include <stdlib.h>
int main(){
    int a=0;
    int b=1;
    int f=0;
    for(int i=1;i<=15;i++){
        f=a+b;
        printf("%d element of series = %d\n",i,f);
        a=b;
        b=f;
    }
}