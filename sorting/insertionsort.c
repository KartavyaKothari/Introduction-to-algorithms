#include<stdio.h>
//Insertion sort:
//Worst case complexity: O(n^2)
//Best case complexity: O(n)
//Would be preffered for mostly-sorted elements
//Would be preffered for small sample set

void insertionSort(int arr[],int n){
    for(int i = 1 ; i < n ; i++){
        int key = arr[i];
        int j;

        //Linear search part in insertion sort
        for(j = i-1 ; j >= 0 ; j--){
            if(arr[j]>key){
                arr[j+1]=arr[j];
            }else break;
        }

        //Binary search in insertion sort
        //This cant be implemented, as a linear fashion not only is required to
        //search but also to shift all elements one by one towards the right to
        //make space for the key element to be inserted

        // int q = i-1;
        // int p = 0;
        // int m = i -1;
        //
        // while(p<q){
        //     m = (p+q)/2;
        //
        //     if(key<arr[m]){
        //         q = m-1;
        //     }else p = m+1;
        // }
        //
        // while(j>=0){
        //     if(arr[j]>key){
        //         arr[j+1]=arr[j];
        //     }else break;
        //
        //     j--;
        // }

        arr[j+1]=key;
    }
}

int main(){
    int arr[] = {779,287,510,330,225,777,486,630,384,413};

    for(int i = 0 ; i < 10 ; i++)
        printf("%d ",arr[i] );

    insertionSort(arr,10);

    putchar('\n');

    for(int i = 0 ; i < 10 ; i++)
        printf("%d ",arr[i] );

    return 1;
}
