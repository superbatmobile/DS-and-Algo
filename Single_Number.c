

int singleNumber(int* nums, int numsSize){
    int i, res;
    res = *nums;
    for ( i = 1; i < numsSize; i++){
        res ^= nums[i];
    }
    return res;
}