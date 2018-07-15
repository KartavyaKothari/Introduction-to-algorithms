#include<stdio.h>

//Incomplete!!!!!!!!


#define NEG_INFINITY -1000

typedef struct {
    int low;
    int high;
    int sum;
} RANGE;

RANGE findMaxSubArray(int arr[],int low,int high){
    int maxSum = arr[low];
    int n = high - low + 1;
    int maxLow;
    int maxHigh;
    int currMax = arr[low];

    for(int i = 1 ; i < n ; i ++){
        if(currMax + arr[i] > currMax){
            currMax = currMax + arr[i];
        }
        if(currMax > maxSum){
            maxSum = currMax;
        }
    }

    RANGE maxSumSubArray;
    maxSumSubArray.sum = maxSum;
    maxSumSubArray.low = maxLow;
    maxSumSubArray.high = maxHigh;

    return maxSumSubArray;
}

int main(int argc, char const *argv[]) {
    int arr[] = {8,-16,5,-9,-1,-14,-10,-17,0,-7,19,15,10,-5,-10,-5,11,-4,-5,-5};
    int n = sizeof(arr)/sizeof(int);

    RANGE maxSubArray = findMaxSubArray(arr,0,n-1);

    printf("Max sum = %d\nFrom array index %d to index %d\n", maxSubArray.sum,maxSubArray.low,maxSubArray.high);

    return 0;
}
