#include<stdio.h>

int binSearch(int arr[], int low, int high, int ele){
    while(low<=high){
        int m = (low+high)/2;
        if(ele==arr[m]){
            return m;
        }else if(ele<arr[m]){
            high = m-1;
        }else low = m+1;
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    int arr[] = {69,245,251,265,290,377,425,491,491,502,682,710,719,740,833,841,851,864,961,990};
    int index;
    int ele = 290;

    index = binSearch(arr,0,19,ele);

    if(index!=-1){
        printf("Element found at index %d\n", index);
    }else printf("Element not found\n");

    return 0;
}
