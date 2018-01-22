#include<stdio.h>

int main(int argc, char const *argv[]) {
    int arr[] = {710,841,491,833,740,491,502,251,864,377,719,682,245,425,851,961,69,990,290,265};
    int min,index;

    for(int i = 0 ; i < 20 ; i++)
        printf("%d ", arr[i]);

    for(int i = 0 ; i < 20 ; i++){
        min = arr[i];
        index = i;
        for(int j = i + 1 ; j < 20 ; j++){
            if(arr[j]<min){
                min = arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }

    putchar('\n');

    for(int i = 0 ; i < 20 ; i++)
        printf("%d ", arr[i]);

    return 0;
}
