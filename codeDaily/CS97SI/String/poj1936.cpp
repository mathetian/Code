#include<stdio.h>
#include<string.h>
#define MAX 100005
 
char s1[MAX],s2[MAX];
int main()
{
 while(scanf("%s%s",s1,s2)!=EOF)
 {
     int len1 = strlen(s1);
     int len2 = strlen(s2);
     int i=0;
    int j=0;
     while(1){
         if(i==len1){
             printf("Yes\n");
             break;
        }
         else if(j==len2){
             printf("No\n");
            break;
         }
         if(s1[i]==s2[j])
             i++,j++;
         else
             j++;
     }
 }
    return 0;
 }