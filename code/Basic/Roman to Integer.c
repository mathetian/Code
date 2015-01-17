class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      	map<char,int>ciM;
      	ciM.insert(make_pair('I',1));
      	ciM.insert(make_pair('V',5));
      	ciM.insert(make_pair('X',10));
      	ciM.insert(make_pair('L',50));
      	ciM.insert(make_pair('C',100));
      	ciM.insert(make_pair('D',500));
      	ciM.insert(make_pair('M',1000));

      	int len=s.size();int result=0;
      	int i=0;
      	while(i<len)
      	{
      		char c=s[i];
      		if(i==len-1)
      		{
      			result+=ciM[c];
      			i++;
      			continue;
      		}
      		if(c=='I'||c=='X'||c=='C')
      		{
      			char d=s[i+1];
      			if(c=='I')
      			{
      				switch(d)
      				{
	  					case 'V':
	  						result+=4;
	  						i=i+2;
	  					break;
	  					case 'X':
	  						result+=9;
	  						i=i+2;
	  					break;
	  					default:
	  						result+=1;
	  						i=i+1;
	  					break;
      				}
      			}
      			else if(c=='X')
      			{
      				switch(d)
      				{
      					case 'L':
      						result+=40;
      						i=i+2;
      					break;
      					case 'C':
      						result+=90;
      						i=i+2;
      					break;
      					default:
      						result+=ciM[c];
      						i=i+1;
      					break;
      				}
      			}
      			else
      			{
      				switch(d)
      				{
      					case 'D':
      						result+=400;
      						i=i+2;
      					break;
      					case 'M':
      						result+=900;
      						i=i+2;
      					break;
      					default:
      						result+=ciM[c];
      						i=i+1;
      					break;
      				}
      			}
      			continue;
      		}
      		result+=ciM[c];
      		i++;
      	}
      	return result;
    }
};