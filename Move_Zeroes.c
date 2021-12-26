

void moveZeroes(int* nums, int numsSize){
    int i, j, temp;
    i =  0;
    while ( i  < numsSize ){
        if(nums[i] == 0)
            break;
        i++;
    }
    if ( i == numsSize-1)
        return;
    j = i + 1;
    while ( j < numsSize){
        if(nums[j] != 0)
            break;
        j++;
    }
    while ( i < j && j < numsSize){
        nums[i++] = nums[j];
        nums[j++] = 0;
        while ( i  < numsSize ){
        if(nums[i] == 0)
            break;
        i++;
    }
        while ( j < numsSize){
        if(nums[j] != 0)
            break;
        j++;
    }
    }
}