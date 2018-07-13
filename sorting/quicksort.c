#include<stdio.h>
//Quick sort:
//Worst case complexity: O(n^2)
//Average case complexity: O(nlog(n))
//Constant factors hidden in quick sort quite low
//Sorts in place3sw2 
//Would be preffered for mostly-sorted elements
//Would be preffered for small sample set
//Stable sort? - We can choose to make it stable or unstable by changing comparison
//              condition to >= instead of >

void swap(int *a, int *b);

int partition(int arr[], int a, int b){
    int i = a-1,j;
    int x = arr[b];

    for(j = a; j<b ; j++){
        if(arr[j]<=x){
            i++;
            swap(arr+i,arr+j);
        }
    }
    swap(arr+b,arr+i+1);

    return i+1;
}

void quickSort(int arr[], int a, int b){
    int p;

    if(a<b){
        p = partition(arr,a,b);
        quickSort(arr,a,p-1);
        quickSort(arr,p+1,b);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {779,287,510,330,225,777,486,630,384,413};

    for(int i = 0 ; i < 10 ; i++)
        printf("%d ",arr[i] );

    quickSort(arr,0,9);

    putchar('\n');

    for(int i = 0 ; i < 10 ; i++)
        printf("%d ",arr[i] );

    return 1;
}

void swap(int *a, int *b){
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}