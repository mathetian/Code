#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef struct{
	int x,y;
}ELEM;

int xf[]={0,0,1,-1};
int yf[]={1,-1,0,0};

/*int minimalSteps(vector<string> const &board) {
	queue<ELEM> a[2];	
    int r=board.size(),c=board.at(0).size();
    vector<string> va;vector<string> vb;
    int flag=0;
    for(int i=0;i<r;i++)
    {
    	va.push_back(board.at(i));
    	vb.push_back(board.at(i));
    	for(int j=0;j<c;j++)
    	{
    		if(board[i][j]=='o')
    		{
    			ELEM elem;elem.step=0;
    			elem.x=i;elem.y=j;
    				
    			if(flag==0)
    			{
    				a[0].push(elem);
    				flag=1;
    			}
    			else a[1].push(elem);
    		}
    	}
    }
    int c1[2];
    for(int j=0;j<2;j++)
    {
        c1[j]=-1;
        while(!a[j].empty())
        {
            ELEM elem=a[j].front();a[j].pop();
            int x=elem.x,y=elem.y;
            if(x==0||y==0||x==r-1||y==c-1)
            {
                c1[j]=elem.step;
                break;
            }
            for(int i=0;i<4;i++)
            {
                int nx=x+xf[i],ny=y+yf[i];
                if(nx>=0&&ny>=0&&nx<r&&ny<c)
                {
                    if(va[nx][ny]=='.')
                    {
                        va[nx][ny]='x';ELEM elem2;
                        elem2.x=nx,elem2.y=ny;
                        elem2.step=elem.step+1;
                        a[j].push(elem2);
                    }
                }
            }
        }
    }
    if(c1[0]==-1&&c1[1]==-1) return -1;
    if(c1[0]>10&&c1[1]>10) return -1;
    if(c1[0]==-1) return c1[1]+1;
    if(c1[1]==-1) return c1[0]+1;
    return min(c1[0],c1[1])+1;
}
*/

int r,c;
vector<string> b;
int fell(int x,int y)
{
    if(x<0||y<0||x>r-1||y>c-1) return true;
    return false;
}

int fell(ELEM elem)
{
    int x=elem.x,y=elem.y;
    return fell(x,y);
}

int mstep;
void dfs(ELEM*elems,int step)
{
    if(step>10) return;
    if(fell(elems[0])&&fell(elems[1])) return;
    else if(fell(elems[0])||fell(elems[1])) 
        mstep=min(mstep,step);
    else
    {
        for(int i=0;i<4;i++)
        {
            int nx1=elems[0].x+xf[i];
            int ny1=elems[0].y+yf[i];
            int nx2=elems[1].x+xf[i];
            int ny2=elems[1].y+yf[i];
            if(fell(nx1,ny1)&&fell(nx2,ny2)) continue;

            if(!fell(nx1,ny1)&&!fell(nx2,ny2))
            {
                if(b[nx1][ny1]!='#'&&b[nx2][ny2]!='#')
                {
                    ELEM elems2[2];
                    elems2[0].x=nx1;elems2[0].y=ny1;
                    elems2[1].x=nx2;elems2[1].y=ny2;
                    dfs(elems2,step+1);
                }
                else if(b[nx1][ny1]!='#')
                {
                    ELEM elems2[2];
                    elems2[0].x=nx1;elems2[0].y=ny1;
                    elems2[1]=elems[1];
                    dfs(elems2,step+1);
                }   
                else if(b[nx2][ny2]!='#')
                {
                    ELEM elems2[2];
                    elems2[0]=elems[0];
                    elems2[1].x=nx2;elems2[1].y=ny2;
                    dfs(elems2,step+1);
                }
            }
            else if(fell(nx1,ny1)){mstep=min(mstep,step+1);return;}
            else if(fell(nx2,ny2)){mstep=min(mstep,step+1);return;}
        }
    }
}

int minimalSteps(vector<string> const &board) {
    int cnt=0;ELEM elems[2];b=board;
    r=board.size(),c=board.at(0).size();
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(board[i][j]=='o')
            {
                elems[cnt].x=i;
                elems[cnt].y=j;
                cnt++;
            }
        }
    }
    mstep=11;
    dfs(elems,0);
    if(mstep==11) return -1;
    return mstep;
}

/*int main()
{
    vector<string> board;
    board.push_back("oo");
    cout<<minimalSteps<<endl;
    return 0;
}
*/
