#include<stdio.h>

#define NEG_INFINITY -100

typedef struct {
    int low;
    int high;
    int sum;
} RANGE;

int findSum(int arr[], int low, int high){
    int n = high - low + 1;
    int sum = 0;

    if(n == 0){
        return arr[low];
    }

    for(int i = 0 ; i < n ; i ++){
        sum = sum + arr[low+i];
    }

    return sum;
}

RANGE findMaxCrossingSubArray(int arr[], int low, int mid, int high){
    int maxLeftSumIndex = mid;
    int maxRightSumIndex = mid+1;
    int maxSum = NEG_INFINITY;

    for(int i = mid ; i >= low ; i--){
        int currSum = findSum(arr,i,mid);

        if(currSum>maxSum){
            maxSum = currSum;
            maxLeftSumIndex = i;
        }
    }

    maxSum = NEG_INFINITY;

    for(int i = mid+1 ; i <= high ; i++){
        int currSum = findSum(arr,i,mid);

        if(currSum>maxSum){
            maxSum = currSum;
            maxRightSumIndex = i;
        }
    }

    RANGE maxCrossingArray;
    maxCrossingArray.sum = findSum(arr,maxLeftSumIndex,mid) + findSum(arr,mid+1,maxRightSumIndex);
    maxCrossingArray.low = maxLeftSumIndex;
    maxCrossingArray.high = maxRightSumIndex;

    return maxCrossingArray;
}

RANGE findMaxSubArray(int arr[],int low,int high){
    if(high>low){
        int mid = (high+low)/2;
        RANGE leftSide;
        RANGE rightSide;
        RANGE fullSide;

        leftSide = findMaxSubArray(arr,low,mid);
        fullSide = findMaxCrossingSubArray(arr,low,mid,high);
        rightSide = findMaxSubArray(arr,mid+1,high);

        if(leftSide.sum>fullSide.sum){
            if(leftSide.sum>rightSide.sum){
                return leftSide;
            }else return rightSide;
        }else if(rightSide.sum>fullSide.sum){
            return rightSide;
        }else return fullSide;
    }

    RANGE unity;
    unity.sum = arr[low];
    unity.low = low;
    unity.high = high;

    return unity;
}

int main(int argc, char const *argv[]) {
    int arr[] = {8,-16,5,-9,-1,-14,-10,-17,0,-7,19,15,10,-5,-10,-5,11,-4,-5,-5};
    int n = sizeof(arr)/sizeof(int);

    RANGE maxSubArray = findMaxSubArray(arr,0,n-1);

    printf("Max sum = %d\nFrom array index %d to index %d\n", maxSubArray.sum,maxSubArray.low,maxSubArray.high);

    return 0;
}
