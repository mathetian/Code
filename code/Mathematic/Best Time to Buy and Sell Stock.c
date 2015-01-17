class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return mx(prices,0,prices.size());
    }
private:
	int mxc(vector<int>&prices,int start,int hnum,int num)
	{
		int mid=start+hnum;

		int l=0xfffffff;
		int i=mid-1;
		while(i>=start)
		{
			if(l>prices[i])
				l=prices[i];
			i--;
		}
		int r=-0xfffffff;
		i=mid; int end = start + num ;
		while(i<end)
		{
			if(r<prices[i])
				r=prices[i];
			i++;
		}
		return r-l;
	}

	int mx(vector<int>&prices,int start,int num)
	{
		if(num<=1)
			return 0;
		else if(num==2)
		{
			if(prices[start+1]>prices[start])
				return prices[start+1]-prices[start];
			return 0;
		}
		else if(num==3)
		{
			int a=prices[start];
			int b=prices[start+1];
			int c=prices[start+2];

			int r1=b-a;int r2=c-a;
			int r3=c-b;
			int rv=max(r1,max(r2,r3));
			if(rv<0) return 0;
			return rv;
		}
		else
		{
			int hnum=num/2;
			int a=mx(prices,start,hnum);
			int b=mx(prices,start+hnum,num-hnum);
			int c=mxc(prices,start,hnum,num);
			return max(a,max(b,c));
		}
	}
};