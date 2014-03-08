#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class BigInteger{
public:
	BigInteger(string str){this->str=str;}
	BigInteger add(BigInteger&big);
	BigInteger mul(BigInteger&big);
	void 	   print(){cout<<str<<endl;}
	string 	   out(){ return str; }
private:
	string str;
	string _lmove(string str,int step);
	string _addstr(string str1,string str2);
	string _times(string str,int time);
};

string BigInteger::_addstr(string str1,string str2)
{
	int i=str1.size()-1,j=str2.size()-1;string rs;
	int remain=0;while(i>=0&&j>=0)
	{
		remain=remain+str1.at(i)+str2.at(j)-2*'0';
		rs.push_back(remain%10+'0');
		remain/=10;i--;j--;
	}
	while(i>=0)
	{
		remain=remain+str1.at(i)-'0';
		rs.push_back(remain%10+'0');
		remain/=10;i--;
	}
	while(j>=0)
	{
		remain=remain+str2.at(j)-'0';
		rs.push_back(remain%10+'0');
		remain/=10;j--;
	}
	if(remain!=0) rs.push_back(remain+'0');
	reverse(rs.begin(),rs.end());
	return rs;
}

string BigInteger::_times(string str,int time)
{
	string rs; while(time--) rs=_addstr(rs,str);
	return rs; 
}

string BigInteger::_lmove(string str,int step)
{
	string rs=str;if(step==0) return rs;
	while(step--) rs.push_back('0');
	return rs;
}

BigInteger BigInteger::mul(BigInteger&big)
{
	int i=big.str.size()-1,step=0;string rs;
	while(i>=0)
	{
		rs=_addstr(rs,_lmove(_times(str,big.str.at(i)-'0'),step));
		i--;step++;
	}
	return BigInteger(rs);
}

BigInteger BigInteger::add(BigInteger&big)
{
	return BigInteger(_addstr(str,big.str));
}

int main()
{
	string val;int n,m;
	while(cin>>val)
	{
		cin>>n;m=n;string val2;int pos;
		if((pos=val.find('.'))==string::npos) 
		val2=val; else val2=val.substr(0,pos)+val.substr(pos+1);
		BigInteger big(val2);BigInteger init(val2);
		while(--n) big=big.mul(init);pos=5-pos;
		val=big.out();reverse(val.begin(),val.end());
		if(m*pos<=val.size())
		{
			val2=val;val=val.substr(0,m*pos);val.push_back('.');
			val=val+val2.substr(m*pos);reverse(val.begin(),val.end());
		}
		else
		{
			int remain=m*pos-val.size();
			string str(remain,'0');
			val=val+str+".";
			reverse(val.begin(),val.end());
		}
		int j=val.size()-1;//cout<<"end:"<<val<<endl;
		while(j>=0)
		{
			if(val.at(j)=='.'||val.at(j)!='0') break;
			j--;
		}
		val=val.substr(0,j+1);if(val.at(val.size()-1)=='.') 
		val=val.substr(0,val.size()-1);cout<<val<<endl;
	}
	return 0;
}