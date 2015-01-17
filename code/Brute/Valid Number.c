#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        //integer,float,exp, oct,hex
        char*tmp=new char[strlen(s)];
        strcpy(tmp,s);
		    tmp=trimwhitespace(tmp);
        int len=strlen(tmp);
        if(len==0) return false;
        if(len==1)
        {
        	if(tmp[0]>='0'&&tmp[0]<='9')
        		return true;
        	else
        		return false;
        }
        enum{
        	INT,FLOAT,EXP,UND,FLAG,DOT
        };
        int flag=UND;
        int flag2=true;
        bool val=0;
       	for(int i=0;i<len&&flag2;i++)
       	{
       		switch(flag)
       		{
       			case UND:
       			{
       				if(tmp[0]>='0'&&tmp[0]<='9')
       					flag=INT;
       				else if(tmp[0]=='.')
       				{
                val=1;
                flag=DOT;
              }
       				else if(tmp[0]=='+'||tmp[0]=='-')
       					flag=FLAG;
       				else
       					return false;
       			}
       			break;
       			case INT:
       			{
       				if(tmp[i]>='0'&&tmp[i]<='9')
       					flag=INT;
       				else if(tmp[i]=='.')
       					flag=DOT;
       				else if(tmp[i]=='e'||tmp[i]=='E')
       					flag=EXP;
       				else
       					return false;
       			}
       			break;
       			case FLOAT:
       			{
       				if(tmp[i]>='0'&&tmp[i]<='9')
       					flag=FLOAT;
       				else if(tmp[i]=='e'||tmp[i]=='E')
       					flag=EXP;
       				else
       					return false;
       			}
       			break;
       			case EXP:
       			{
       				if(tmp[i]>='0'&&tmp[i]<='9')
       					flag=EXP;
       				else if(tmp[i]=='+'||tmp[i]=='-')
       				{
       					if(i+1<len&&(tmp[i-1]=='e'||tmp[i-1]=='E'))
       					{
       						flag=EXP;
       					}
       					else
       						return false;
       				}
       				else
       					return false;
       			}
       			break;
       			case FLAG:
       			{
       				if(tmp[i]>='0'&&tmp[i]<='9')
       					flag=INT;
       				else if(tmp[i]=='.')
       					flag=DOT;
       				else
       					return false;
       			}
       			break;
       			case DOT:
       			{
       				if(tmp[i]>='0'&&tmp[i]<='9')
       					flag=FLOAT;
       				else if(tmp[i]=='e'||tmp[i]=='E')
              {
                if(val==0)
                    flag=EXP;
                else
                  return false;
              }
       				else
       					return false;
       			}	
       			break;
       			default:
       				return false;
       			break;
       		}
       	}
       	if(flag==EXP)
       	{
       		if(tmp[len-1]=='e'||tmp[len-1]=='E')
       			return false;
       	}
       	else if(flag==FLAG)
       		return false;
       	else if(flag==DOT)
       	{
       		if(tmp[len-2]=='+'||tmp[len-2]=='-')
       			return false;
       	}
       	return true;
    }
private:
	char *trimwhitespace(char *str)
	{
	  char *end;

	  // Trim leading space
	  while(isspace(*str)) str++;

	  if(*str == 0)  // All spaces?
	    return str;

	  // Trim trailing space
	  end = str + strlen(str) - 1;
	  while(end > str && isspace(*end)) end--;

	  // Write new null terminator
	  *(end+1) = 0;

	  return str;
	}
};

int main()
{
	Solution solution;
	std::cout<<solution.isNumber("-.")<<std::endl;

	return 0;
}