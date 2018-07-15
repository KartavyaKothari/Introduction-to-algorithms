#include<stdio.h>
//Radix sort:
//Complexity: O(n)
//Would be preffered if values have same number of digits
int digitRange;
int digits;

void countingsort(int arr[], int n, int div);
int  power(int a, int b);
void displayArray(int arr[],int n);
int getDigitAtOrder(int num, int order);

void radixsort(int arr[], int n){
    for(int i = 0 ; i < digits ; i++){
        countingsort(arr,n,i);
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {119,873,255};
    digits = 3;
    digitRange = 10;
    int n = sizeof(arr)/sizeof(int);

    displayArray(arr,n);

    radixsort(arr,n);

    putchar('\n');

    displayArray(arr,n);

    return 0;
}

void displayArray(int arr[],int n){
    printf("\nArray =>>");
    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

void countingsort(int arr[],int n,int order){
    int counts[digitRange];
    int sortedArray[n];

    for(int i = 0 ; i < digitRange ; i++){
        counts[i] = 0;
    }

    for(int i = 0;  i < n; i++){
        counts[getDigitAtOrder(arr[i],order)]++;
    }

    for(int i = 0; i < digitRange-1 ; i++){
        counts[i+1] = counts[i+1]+counts[i];
    }

    for(int i = 0; i < n ; i++){
        sortedArray[counts[getDigitAtOrder(arr[i],order)]-1] = arr[i];
        counts[getDigitAtOrder(arr[i],order)]--;
    }

    for(int i = 0; i < n ; i++){
        arr[i]= sortedArray[i];
    }
}

int getDigitAtOrder(int num, int order){
    return (num/power(digitRange,order))%digitRange;
}

int power(int a, int b){
    if(a==0) return 0;
    if(b==0) return 1;

    return a*power(a,b-1);
}