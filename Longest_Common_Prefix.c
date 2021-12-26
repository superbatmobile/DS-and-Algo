

char * longestCommonPrefix(char ** strs, int strsSize){
    char* res = strs[0];
    int i,j, len;
    len = strlen(res);
    for ( i = 0; i < len; i++){
        for (j = 1; j < strsSize; j++){
            if (res[i] != strs[j][i]){
                res[i] = '\0';
                return res;
            }
        }
    }
    return res;
}