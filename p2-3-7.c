#include<stdio.h>

int isSumExist(int s[], int n, int ele){
    for(int i = 0 ; i < 20 ; i++){
        int p=i+1,q=19,m;

        while(p<q){
            m = (p+q)/2;

            if(ele==(s[m]+s[i])){
                return 1;
            }else if(ele>(s[m]+s[i])){
                p = m+1;
            }else q = m-1;
        }
    }
    return 0;
}

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
    if(q-p>1){
        int m = (p+q)/2;
        mergesort(arr,p,m);
        mergesort(arr,m+1,q);
        merge(arr,p,m,q);
    }
}

int main(int argc, char const *argv[]) {
    int s[] = {545,993,512,178,437,502,34,101,666,500,249,573,679,758,661,699,615,204,533,628};
    int ele = 679;

    mergesort(s,0,19);

    int isFound = isSumExist(s,20,ele);

    if(isFound==1){
        printf("Sum found!\n");
    }else printf("Sum not found :(\n");

    return 0;
}
