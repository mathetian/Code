#include<stdio.h>
#include<string.h>

#define OVERFLOW 1
#define NFLOW 0

char memory[300];///char A[5],B[5];
char A,B;

int makeAddr(char a,char b)
{
	int ans=0;
	if(b>='0'&&b<='9')
		ans=b-'0';
	else if(b>='A'&&b<='F')
		ans=b-'A'+10;
	if(a>='0'&&a<='9')
		ans+=(a-'0')*16;
	else if(a>='A'&&a<='F')
		ans+=(a-'A'+10)*16;
	return ans;
}

void writeIntoA(int st)
{
	int addr=makeAddr(memory[st],memory[st+1]);
	A=memory[addr];
}


void writeIntoMemory(int st)
{
	int addr=makeAddr(memory[st],memory[st+1]);
	memory[addr]=A;
}

void swap()
{
	char tmp2=A;A=B;B=tmp2;
}

void IntToChar(int t1,char&out)
{
	if(t1>=0&&t1<=9)
		out='0'+t1;
	else
		out='A'+t1-10;
}

int CharToInt(char tmp3)
{
	if(tmp3>='0'&&tmp3<='9')
		return tmp3-'0';
	else
		return 10+tmp3-'A';
}

void AddAB()
{
	int a,b;
	a=CharToInt(A);b=CharToInt(B);
	a+=b;b=a/16;a=a%16;
	IntToChar(a,A);IntToChar(b,B);
}

int INCA(char&t)
{
	if(t<='8')
		t+=1;
	else if(t=='9')
		t='A';
	else if(t>='A'&&t<'F')
		t+=1;
	else
	{
		t='0';return OVERFLOW;
	}
	return NFLOW;
}

int DECA(char&t)
{
	if(t>='1'&&t<='9')
		t-=1;
	else if(t=='A')
		t='9';
	else if(t>'A')
		t-=1;
	else if(t=='0')
	{
		t='F';
		return OVERFLOW;
	}
	return NFLOW;
}

void JP(int st,int&nowPos)
{
	//if(A=='0')
	//	nowPos+=3;
	//else
	//	nowPos=makeAddr(memory[st],memory[st+1]);
	if(A!='0')
		nowPos+=3;
	else
		nowPos=makeAddr(memory[st],memory[st+1]);
}

void BR(int st,int&nowPos)
{
	nowPos=makeAddr(memory[st],memory[st+1]);
}

int main()
{
	while(scanf("%s",memory)!=EOF)
	{
		if(memory[0]=='8')
			break;
		int stPos=0;
		while(memory[stPos]!='8')
		{
			//printf("%d\n",stPos);
			switch(memory[stPos])
			{
			case '0':
				writeIntoA(stPos+1);stPos+=3;
				//puts(memory);
				break;
			case '1':
				writeIntoMemory(stPos+1);stPos+=3;
				//puts(memory);
				break;
			case '2':
				swap();stPos+=1;
				//puts(memory);
				break;
			case '3':
				AddAB();stPos+=1;
			//	puts(memory);
				break;
			case '4':
				INCA(A);stPos+=1;
			//	puts(memory);
				break;
			case '5':
				DECA(A);stPos+=1;
				//puts(memory);
				break;
			case '6':
				JP(stPos+1,stPos);
				//stPos+=1;
			//	puts(memory);
				break;
			case '7':
				BR(stPos+1,stPos);
				//puts(memory);
				break;
			}
		}
		puts(memory);
	}
	return 0;
}