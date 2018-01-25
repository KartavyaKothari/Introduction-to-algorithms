#include<stdio.h>
//Merge sort:
//Worst case complexity: O(n^2)
//Best case complexity: O(n^2)
//Would be preffered for heavily unsorted elements
//Would be preffered for small smaple set

void selectionsort(int arr[],int n){
    int min,index;

    for(int i = 0 ; i < n ; i++){
        min = arr[i];
        index = i;
        for(int j = i + 1 ; j < n ; j++){
            if(arr[j]<min){
                min = arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {710,841,491,833,740,491,502,251,864,377,719,682,245,425,851,961,69,990,290,265};

    for(int i = 0 ; i < 20 ; i++)
        printf("%d ", arr[i]);

    selectionsort(arr,20);

    putchar('\n');

    for(int i = 0 ; i < 20 ; i++)
        printf("%d ", arr[i]);

    return 0;
}
