#include<stdio.h>
//Radix sort:
//Complexity: O(n)
//Would be preffered if values have same number of digits

void countingsort(int arr[], int n, int div);
int  power(int a, int b);
void displayArray(int arr[],int n);

void radixsort(int arr[], int n){
    int digits = 3;

    for(int i = 0 ; i < digits ; i++){
        countingsort(arr,100,power(10,digits-i-1));
    }
}

int main(int argc, char const *argv[]) {
    int arr[] = {119,873,255,608,369,560,444,640,660,431,985,928,547,434,254,434,748,459,132,300,841,577,324,342,260,477,750,476,611,523,804,383,463,765,264,317,286,542,705,910,562,618,651,927,932,983,688,878,609,455,847,284,119,889,103,206,839,825,395,100,577,128,812,465,218,511,162,175,102,762,524,502,856,660,723,118,994,517,465,614,351,612,103,826,184,131,443,477,466,687,142,691,441,680,477,833,790,477,205,979};
    int n = 100;

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

void countingsort(int arr[],int n,int div){
    int counts[10] = {0};
    int sortedArray[n];

    for(int i = 0;  i < n; i++){
        printf("**%d**\n",(arr[i]/div)%10);
        counts[(arr[i]/div)%10]++;
    }

    // displayArray(counts,10);

    for(int i = 0; i < 9 ; i++){
        counts[i+1] = counts[i+1]+counts[i];
    }

    for(int i = 0; i < n ; i++){
        sortedArray[counts[(arr[i]/div)%10-1]] = arr[i];
        counts[(arr[i]/div)%10]--;
    }

    for(int i = 0; i < n ; i++){
        arr[i]= sortedArray[i];
    }

    //displayArray(arr,n);
}

int power(int a, int b){
    if(a==0) return 0;
    if(b==0) return 1;

    return a*power(a,b-1);
}