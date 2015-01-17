#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int MAXN = 500;
int F[MAXN][MAXN];

int minDistance(string word1, string word2) 
{
    
    int len1 = word1.size();
    int len2 = word2.size();
    
    for (int i = 0; i <= max(len1, len2); i++)
        F[i][0] = F[0][i] = i;
        
    for (int i = 1; i <= len1; i++) 
    {
        for (int j = 1; j <= len2; j++) 
        {
            if (word1[i-1] == word2[j-1])
                F[i][j] = F[i-1][j-1];
            else
                F[i][j] = min(F[i-1][j-1], min(F[i-1][j], F[i][j-1])) + 1;
        }
    }
    return F[len1][len2];
}

int main()
{
	vector<string> pattern;
	vector<int> freq;

	string str; while(std::getline (std::cin,str))
	{
		int i=0;for(;i<pattern.size();i++)
		{
			if(minDistance(pattern.at(i), str) <= 5)
				break;
		}
		if(i==pattern.size())
		{
			pattern.push_back(str);
			freq.push_back(1);
		}
		else freq[i]++;
	}
	int mx=freq[0];
	for(int i=1;i<freq.size();i++)
		mx=max(mx,freq[i]);
	cout<<mx<<endl;

	return 0;
}