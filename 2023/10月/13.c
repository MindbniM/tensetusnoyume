bool repeatedSubstringPattern(char * s){
    int len=strlen(s);
    if(len<=1)
    return false;
    char str1[len+1];
    strcpy(str1,"");
    int cout;
    for(int i=1;i<=len/2;i++)
    {
        cout=len/i;
        if(len%i==0)
        {
            for(int j=0;j<cout;j++)
            {
                strncat(str1,s,i);
            }
            if(strcmp(str1,s)==0)
                return true;
        }
        strcpy(str1,"");
    }
    return false;
}