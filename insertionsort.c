#include<conio.h>
#include<stdio.h>

int main(){
    int arr[10] = {779,287,510,330,225,777,486,630,384,413};
    int j;

    for(int i = 0 ; i < 10 ; i++)
        printf("%d ",arr[i] );

    for(int i = 1 ; i < 10 ; i++){
        int key = arr[i];
        for(j = i-1 ; j >= 0 ; j--){
            if(arr[j]>key){
                arr[j+1]=arr[j];
            }else break;
        }
        arr[j+1]=key;
    }

    putchar('\n');

    for(int i = 0 ; i < 10 ; i++)
        printf("%d ",arr[i] );

    return 1;
}
