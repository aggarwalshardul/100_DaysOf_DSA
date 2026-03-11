/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct{
    int num;
    int freq;
}Pair;

int cmp(const void *a,const void *b){
    Pair *p1=(Pair*)a;
    Pair *p2=(Pair*)b;
    return p2->freq - p1->freq;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    Pair arr[numsSize];
    int size=0;

    for(int i=0;i<numsSize;i++){
        int found=0;

        for(int j=0;j<size;j++){
            if(arr[j].num==nums[i]){
                arr[j].freq++;
                found=1;
                break;
            }
        }

        if(!found){
            arr[size].num=nums[i];
            arr[size].freq=1;
            size++;
        }
    }

    qsort(arr,size,sizeof(Pair),cmp);

    int *result=(int*)malloc(sizeof(int)*k);

    for(int i=0;i<k;i++){
        result[i]=arr[i].num;
    }

    *returnSize=k;
    return result;
}