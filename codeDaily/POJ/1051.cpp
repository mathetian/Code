#include<stdio.h>
#include<string.h>

char *morseCode[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
char *morseCode2[]={"..--","---.",".-.-","----"};

char input[111];char morseDe[500];int num2[111];int len;

void print()
{
	printf("%s\n",morseDe);
	for(int i=0;i<len;i++)
		printf("%d ",num2[i]);
	printf("\n");
}

int main()
{
	int num;
	scanf("%d",&num);
	for(int m=1;m<=num;m++)
	{
		scanf("%s",input);
		memset(morseDe,'\0',500);
		int index=0;
		len=strlen(input);
		for(int i=0;i<len;i++)
		{
			if(input[i]>='A'&&input[i]<='Z')
			{
				strcat(morseDe,morseCode[input[i]-'A']);
				num2[i]=strlen(morseCode[input[i]-'A']);
			}
			else
			{
				if(input[i]=='_')
					strcat(morseDe,morseCode2[0]);
				else if(input[i]=='.')
					strcat(morseDe,morseCode2[1]);
				else if(input[i]==',')
					strcat(morseDe,morseCode2[2]);
				else if(input[i]=='?')
					strcat(morseDe,morseCode2[3]);
				num2[i]=4;
			}
		}
		for(int i=0;i<len/2;i++)
		{
			int tmp=num2[i];num2[i]=num2[len-1-i];num2[len-1-i]=tmp;
		}
		int index2=0;
	//	print();
		printf("%d: ",m);
		for(int i=0;i<len;i++)
		{
			
			char tmp[111];
			strncpy(tmp,morseDe+index2,num2[i]);
			index2+=num2[i];
			tmp[num2[i]]='\0';
			int j;
			for(j=0;j<26;j++)
			{
				if(strcmp(tmp,morseCode[j])==0)
					break;
			}
			if(j<26)
				printf("%c",'A'+j);
			else
			{
				if(strcmp(tmp,morseCode2[0])==0)
					printf("_");
				else if(strcmp(tmp,morseCode2[1])==0)
					printf(".");
				else if(strcmp(tmp,morseCode2[2])==0)
					printf(",");
				else if(strcmp(tmp,morseCode2[3])==0)
					printf("?");
			}
		}
		printf("\n");
	}
	return 0;
}