int max (int a, int b)
{
    return a > b ? a : b;
}

int rob(int* nums, int numsSize){
    if (numsSize == 1)
        return *nums;

    int i;
    int ref[numsSize];
    ref[0] = *nums;
    ref[1] = max(*(nums+1), *nums);
    if (numsSize == 2)
        return ref[1];
    for ( i = 2; i < numsSize; i++){
        ref[i] = max(ref[i-1], nums[i] + ref[i-2]);
    }
    return ref[numsSize-1];
}