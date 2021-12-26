

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct __node {
    int value;
    int index;
    struct __node* next;
}node;

void insert(node** hashTable, int value, int index, int n)
{
    int hash = abs(value) % n;
    node* temp = hashTable[hash];
    node* newn = (node*)malloc(sizeof(node));
    newn->value = value;
    newn->index = index;
    newn->next = temp->next;
    temp->next = newn;    
}

int search(node** hashTable, int target, int n)
{
    int index = abs(target) % n;
    node* temp = hashTable[index]->next;
    while(temp) {
        if (temp->value == target){
            return temp->index;
        }
        temp = temp->next;
    }
    return -1;
}

void freeHashTable(node** hashTable, int n)
{
    int i = 0;
    node *temp = NULL;
    node *delete = NULL;
    for (int i=0; i<n; i++) {
        temp = hashTable[i];
        while (temp) {
            delete = temp;
            temp = temp->next;
            free(delete);
        }
    }
    free(hashTable);
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i=0, j=0, index = 0;
    int *result = NULL;
    node **hashTable = (node **)malloc(numsSize*sizeof(node*));
    for(int i=0; i<numsSize; i++){
        hashTable[i] = (node*)calloc(1, sizeof(node));
    }
    for(i = 0; i < numsSize; i++) {
        index = search(hashTable, target - nums[i], numsSize);
        if(-1 == index)
            insert(hashTable, nums[i], i, numsSize);
        else {
            result = (int*)malloc(sizeof(int) * 2);
            result[0] = index;
            result[1] = i;
            freeHashTable(hashTable, numsSize);
            return result;
        }    
    }
    freeHashTable(hashTable, numsSize);
    return result;

}