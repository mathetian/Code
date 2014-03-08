#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

#define N 100
int kind[N];
typedef struct
{
	int d[4];
	int typeNum;
	int SNum;
	int MxV;
}D;

vector<D>vD;

D tmp2;
/*
	customer: 需求的数量
	kNums:    可选择的kind的数量
	tp:       记录选择
	n2:       数目数
	kindNum:  记录选择的种类数
	oldKind： 记录上一个选择的类型
*/
void process(int customer,int kNums,D&tp,int n2,int kindNum,int oldKind)
{
	if(customer==0)
	{
		tp.SNum=n2;
		tp.typeNum=kindNum;
		int mx2=tp.d[0];
		for(int i=1;i<tp.SNum;i++)
		{
			if(mx2<tp.d[i])
			{
				mx2=tp.d[i];
			}
		}
		tp.MxV=mx2;
		vD.push_back(tp);
	}
	else if(kNums==0||n2>=4)
		return;
	else
	{
		if(kind[kNums-1]<=customer)
		{
			tp.d[n2]=kind[kNums-1];
			if(oldKind==kNums-1)
				process(customer-kind[kNums-1],kNums,tp,n2+1,kindNum,oldKind);
			else
				process(customer-kind[kNums-1],kNums,tp,n2+1,kindNum+1,kNums-1);
		}
		process(customer,kNums-1,tp,n2,kindNum,oldKind);
	}
}

int main()
{
	int kNums;
	int customer;
	while(scanf("%d",kind)!=EOF)
	{
		kNums=1;int tmp;
		while(scanf("%d",&tmp)&&tmp!=0)
		{
			kind[kNums++]=tmp;
		}
		sort(kind,kind+kNums);
		while(scanf("%d",&customer)&&customer!=0)
		{
			vD.clear();
			tmp2.SNum=0;
			process(customer,kNums,tmp2,0,0,-1);
			int s2=vD.size();
			if(s2==0)
			{
				printf("%d ---- none\n",customer);
				continue;
			}
			int mxType=vD.at(0).typeNum;int heshide=0;
			
			for(int i=0;i<s2;i++)
			{
				if(vD.at(i).typeNum>mxType)
				{
					mxType=vD.at(i).typeNum;
					heshide=i;
				}
			}
			int minNum=vD.at(heshide).SNum;
			for(int i=0;i<s2;i++)
			{
				if(vD.at(i).typeNum==mxType)
				{
					if(vD.at(i).SNum<minNum)
					{
						minNum=vD.at(i).SNum;
						heshide=i;
					}
				}
			}
			int mxV=vD.at(heshide).MxV;int n4=1;
			for(int i=0;i<s2;i++)
			{
				if(vD.at(i).typeNum==mxType&&vD.at(i).SNum==minNum)
				{
					if(vD.at(i).MxV>mxV)
					{
						mxV=vD.at(i).MxV;
						heshide=i;
					}
				}
			}
			int flag2=0;
			for(int i=0;i<s2;i++)
			{
				if(vD.at(i).typeNum==mxType&&vD.at(i).SNum==minNum&&vD.at(i).MxV==mxV&&i!=heshide)
				{
					flag2=1;
					break;
				}
			}
			if(flag2==0)
			{
				printf("%d (%d):",customer,vD.at(heshide).typeNum);
				sort(vD.at(heshide).d,vD.at(heshide).d+vD.at(heshide).SNum);
				for(int i=0;i<vD.at(heshide).SNum;i++)
				{
					printf(" %d",vD.at(heshide).d[i]);
				}
				putchar('\n');
			}
			else
			{
				printf("%d (%d):",customer,vD.at(heshide).typeNum);
				printf(" tie\n");
			}

		}
	}
	
	return 0;
}