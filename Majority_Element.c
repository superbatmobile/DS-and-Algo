

int majorityElement(int* nums, int numsSize){
    int count = 1;
    int res = *nums;
    int i ;
    for ( i = 1; i < numsSize; i++){
        if( nums[i] == res){
            count ++;
        }else if (count > 1){
            count --;
        }else{
            res = nums[i];
        }
    }
    return res;
}