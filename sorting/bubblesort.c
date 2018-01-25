#include<stdio.h>

void bubblesort(int arr[], int n) {
    for(int i = 0 ; i < n ; i ++){
        int isSorted = 1;
        for(int j = 0 ; j < n-1 ; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted==1)break;
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {710,841,491,833,740,491,502,251,864,377,719,682,245,425,851,961,69,990,290,265};
    int n = 20;

    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);

    bubblesort(arr,n);

    putchar('\n');

    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);

    return 0;
}
