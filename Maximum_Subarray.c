int maxSubArray(int* nums, int numsSize){
    int res = *nums;
    int cur = *nums;
    for(int i = 1; i< numsSize;i++){
        int temp = *(nums+i) + cur;
        if (temp > *(nums+i)){
            cur = temp;
        }else{
            cur = *(nums+i);
        }
        if (cur > res){
            res = cur;
        }
    }
    return res;
}