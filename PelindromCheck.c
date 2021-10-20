#include <stdio.h>
#include <string.h>
int main()
{
    char name[200];
    int flag = 0;
    int i;
    printf("\nEnter string:");
    scanf("%s",&name);
    for(i=1;i<=strlen(name);i++){
        if(name[i-1]!=name[strlen(name)-i]){
            flag = 1;
            break;
        }
    }
    if(flag==0){
        printf("\nGiven string is pelindrom");
    }
    else{
        printf("\nGiven string is not pelindrom");
    }
    return 0;
}
