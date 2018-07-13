#include<stdio.h>
//Merge sort:
//Worst case complexity: O(nlog(n))
//Best case complexity: O(nlog(n))
//Would be preffered for heavily unsorted elements
//Would be preffered for large sample set
//Does not do the sorting InPlace

void merge(int arr[], int p, int m, int q) {
    int l[m-p+1];
    int r[q-m];

    for(int i = 0 ; i <= m-p ; i++){
        l[i] = arr[p+i];
    }

    for(int i = 0 ; i < q-m ; i++){
        r[i] = arr[m+1+i];
    }

    int ri = 0;
    int li = 0;
    int i = 0;

    while(ri<q-m&&li<m-p+1){
        if(l[li]<r[ri]){
            arr[p+i++] = l[li++];
        }else arr[p+i++] = r[ri++];
    }

    while(ri<q-m){
        arr[p+i++] = r[ri++];
    }

    while(li<m-p+1){
        arr[p+i++] = l[li++];
    }
}

void mergesort(int arr[], int p, int q) {
    //The terminating condition is p>=q
    //There is chance for optimization here
    //We can decide a threshold n0 before which Insertion sort gives a better performance than merge sort
    //Then below that threshold we can sort the arrray in one go using insertion sort
    if(p<q){
        int m = (p+q)/2;
        mergesort(arr,p,m);
        mergesort(arr,m+1,q);
        merge(arr,p,m,q);
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {710,841,491,833,740,491,502,251,864,377,719,682,245,425,851,961,69,990,290,265};
    int n = 20;

    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);

    mergesort(arr,0,n-1);

    putchar('\n');

    for(int i = 0 ; i < n ; i++)
        printf("%d ", arr[i]);

    return 0;
}
