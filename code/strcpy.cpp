#include <stdio.h>
#include <string.h>
#include <errno.h>

/**
	1. may not overlap(depend of implementation)
	2. util null byte(the initialization of memory will be null)
	3. must be large enough(if not, anything can happen)
**/
char *strcpy_(char *dest, const char *src)
{
	char *orig=dest; 
    while((*dest++ = *src++) != '\0');
    return orig;
}

char *strncpy_(char *dest, const char *src, size_t n)
{
   size_t i;

   for (i = 0; i < n && src[i] != '\0'; i++)
       dest[i] = src[i];
   for ( ; i < n; i++)
       dest[i] = '\0';

   return dest;
}

size_t strlen_(const char *src)
{
	size_t i = 0;
	while((*src++)!='\0') i++;
	return i;
}

char *strcat_(char *dest, const char *src)
{
	char *orig=dest;
	while((*dest)!='\0') dest++;
	while((*dest++=*src++)!='\0');
	*dest='\0';

	return orig;
}

char *strncat_(char *dest, const char *src, size_t n)
{
	char *orig=dest; size_t i=0;
	while((*dest++)!='\0');
	while(i<n&&(*dest++=*src++)!='\0') i++;

	if(i==n) *dest='\0';

	return orig;
}

/**
	 The memory areas must not overlap.
**/

void *memcpy_(void *dest, const void *src, size_t n)
{
	void *orig=dest; size_t i=0;
	char *cdest=(char*)dest;
	const char *csrc=(const char*)src;

	while(i++<n) *cdest++=*csrc++;
	return orig;
}

bool overlap_(void *a, void *b, size_t n)
{
    char *x = (char*)a, *y =  (char*)b;
    return (a<=b && x+n>y) || (b<=a && x+n>y);
}

#include <string>
#include <iostream>
using namespace std;

bool replace_1(string& str, const string& from, const string& to) 
{
    size_t start_pos = str.find(from);
    if(start_pos == string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

string replace_2(string& str, const string& from, const string& to) 
{
	string rs; size_t i = 0;
	while(i<str.size())
	{
		size_t j=0,k=i;
		while(i<str.size()&&j<from.size()&&str.at(i)==from.at(j)) { i++;j++; }
		if(j==from.size()) rs+=to;
		else
		{
			rs.push_back(str.at(k));
			i=k+1;
		}
	}

    return rs;
}

//Todo list
char *replace_3(char *src, const char *from, const char *to)
{
}

class BigInteger
{
int len, arr[100], flag;
public:
	BigInteger(int val) { }
	BigInteger(string val) { }

	BigInteger& operator+(const BigInteger&integer)
	{
		if(flag==integer.flag)
		{
			int mnlen=min(len, integer.len);

			int remain=0;
			for(int i=0;i<mnlen;i++)
			{
				arr[i]+=integer.arr[i]+remain;
				remain=arr[i]/10;arr[i]%=10;
			}
		}
		else
		{

		}
	}

	BigInteger& operator-(const BigInteger&integer)
	{
	}

	BigInteger& operator+=(const BigInteger&integer)
	{
		*this=*this+integer;
		return *this;
	}

	BigInteger& operator-=(const BigInteger&integer)
	{
		*this=*this-integer;
		return *this;
	}

	BigInteger& operator*(const BigInteger&integer)
	{
		BigInteger tmp1=*this, tmp2=tmp1;
		for(int i=0;i<integer.len;i++)
		{
			tmp2=tmp1; tmp2.multiply_(integer.arr[i]);
			shiftl(1); *this+=tmp2;
		}
	}

	BigInteger& operator/(const BigInteger&integer)
	{

	}

	BigInteger sqrt()
	{

	}

	ostream& operator<<(ostream&os)
	{
		for(int i=len-1;i>=0;i--)
			os<<arr[i];
		return os;
	}

private:
	void multiply_(int val)
	{
		int remain=0;
		for(int i=0;i<len;i++)
		{
			arr[i] = arr[i]*val+remain;
			remain=arr[i]/10;arr[i]%=10;
		}
		while(remain!=0)
		{
			arr[len++]=remain%10;
			remain/=10;
		}
	}

	void shiftl(int step)
	{
		for(int i=len-1;i>=0;i--)
			arr[i+1]=arr[i];
		len++;
	}
};

void DoTest1()
{
	char dest[3];
	char src[] = {'h', 'e', 'l', 'l', 'o', 'w', 'w','h', 'e', 'l', 'l', 'o', 'w', 'w','h', 'e', 'l', 'l', 'o', 'w', 'w','h', 'e', 'l', 'l', 'o', 'w', 'w','h', 'e', 'l', 'l', 'o', 'w', 'w','h', 'e', 'l', 'l', 'o', 'w', 'w','h', 'e', 'l', 'l', 'o', 'w', 'w'};
	strcpy_(dest, src);
	if(errno != 0) printf("error: %s\n", strerror(errno));
	printf("%s\n", dest);
}

/**overlap**/
void DoTest2()
{	
	char dest[] = "hello world";
	const char *src = dest-1;
	printf("src: %s\n", src);
	strcpy(dest, src);
	if(errno != 0) printf("error: %s\n", strerror(errno));
	printf("%s\n", dest);
}

void DoTest3()
{
	char dest[3];
	printf("%d\n", (int)strlen(dest));
}

void DoTest4()
{
	char dest[] = "hello world";
	const char *src = dest-5;
	printf("src: %s\n", src);
	memcpy(dest, src, 3);
	printf("%s\n",dest);
}

void DoTest5()
{
	string src="helloworld helloworld";
	string from="wo", to = "abc";
	cout<<replace_2(src,from,to)<<endl;
}

int sqrt(int val)
{
	int r=10000,l=1;
	while(l<r)
}

int main()
{
	DoTest5();
	return 0;
}
