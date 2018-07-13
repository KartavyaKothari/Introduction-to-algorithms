#include<stdio.h>
//Counting sort:
//Complexity: O(n)
//Would be preffered if values are from a fixed finite set of nos
//Would be preffered for small sample set

void countingsort(int arr[],int n){
    int counts[40] = {0};
    int sortedArray[n];

    for(int i = 0;  i < n; i++){
        counts[arr[i]]++;
    }

    for(int i = 0; i < 39 ; i++){
        counts[i+1] = counts[i+1]+counts[i];
    }

    for(int i = 0; i < n ; i++){
        sortedArray[counts[arr[i]]-1] = arr[i];
        counts[arr[i]]--;
    }

    for(int i = 0; i < n ; i++){
        arr[i]= sortedArray[i];
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {5,28,16,4,33,20,28,6,16,12,8,21,10,1,15,24,31,35,6,15,11,12,36,18,37,0,15,23,33,13,32,16,26,6,2,19,36,2,22,28,17,2,3,24,26,3,21,27,24,33,35,13,35,21,13,17,35,8,30,14,21,0,38,9,9,34,36,10,2,25,34,14,37,21,24,29,22,24,38,29,7,5,4,7,33,26,21,8,0,16,3,2,19,24,28,4,26,0,38,32};
    int n = 100;

    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);

    countingsort(arr,n);

    putchar('\n');

    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);

    return 0;
}