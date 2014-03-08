
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	int location;int grade;int preNum;
	int prefer[51];int nowTurn;int selUnivN;int oldId;
}STU;

typedef struct{
	int location;int need;int now;int stu[200];
}UNIV;

STU students[151];
UNIV university[52];int fullMinge;

int cmp(const void*p1,const void*p2)
{
	STU*s1=(STU*)p1;STU*s2=(STU*)p2;
	return s1->grade<s2->grade?1:-1;
}

int main()
{
	int cases;scanf("%d",&cases);
	int studentNum;int univNum;
	while(cases--)
	{
		fullMinge=0;
		scanf("%d%d",&studentNum,&univNum);
		for(int i=0;i<studentNum;i++)
		{
			scanf("%d%d%d",&students[i].location,&students[i].grade,&students[i].preNum);
			for(int j=0;j<students[i].preNum;j++)
			{
				scanf("%d",&students[i].prefer[j]);
				students[i].prefer[j]=students[i].prefer[j]-1;
			}
			students[i].nowTurn=0;
			students[i].oldId=i;
			students[i].selUnivN=-1;
		}
		for(int i=0;i<univNum;i++)
		{
			scanf("%d%d",&university[i].location,&university[i].need);
			university[i].now=0;
			fullMinge+=university[i].need;
			for(int j=0;j<200;j++)
				university[i].stu[j]=-1;
		}
		qsort(students,studentNum,sizeof(STU),cmp);
		int sucStu=0;
		int suc[160];memset(suc,0,sizeof(int)*160);
		while(sucStu<studentNum&&sucStu<fullMinge)
		{
			int i;
			for(i=0;i<studentNum;i++)
			{
				if(suc[i]==0)
					break;
			}
			if(i==studentNum)
				break;
			for(i=0;i<studentNum;i++)
			{
				if(suc[i]==0)
				{
					if(students[i].nowTurn==students[i].preNum)
					{
						suc[i]=-1;continue;
					}
					int preUnivN=students[i].prefer[students[i].nowTurn];
					if(university[preUnivN].now<university[preUnivN].need)
					{
						suc[i]=1;students[i].nowTurn++;students[i].selUnivN=preUnivN;
						university[preUnivN].stu[university[preUnivN].now++]=i;
						sucStu++;
					}
					else if(university[preUnivN].location==students[i].location)
					{
						int j;
						students[i].nowTurn++;
						for(j=0;j<university[preUnivN].need;j++)
						{
							int stuN=university[preUnivN].stu[j];
							if(university[preUnivN].location==students[stuN].location)
							{
								if(students[i].grade>students[stuN].grade)
								{
									university[preUnivN].stu[j]=i;
									students[i].selUnivN=preUnivN;
									suc[i]=1;suc[stuN]=0;
									break;
								}
							}
							else
							{
								if(students[stuN].grade*7<students[i].grade*10)
								{
									university[preUnivN].stu[j]=i;
									students[i].selUnivN=preUnivN;
									suc[i]=1;suc[stuN]=0;
									break;
								}
							}
						}
					}
					else
					{
						int j;
						students[i].nowTurn++;
						for(j=0;j<university[preUnivN].need;j++)
						{
							int stuN=university[preUnivN].stu[j];
							if(students[stuN].location==university[preUnivN].location)
							{
								if(students[stuN].grade*10>students[i].grade*7)
									continue;
								else
								{
									university[preUnivN].stu[j]=i;
									students[i].selUnivN=preUnivN;
									suc[i]=1;suc[stuN]=0;
									break;
								}
							}
							else
							{
								if(students[stuN].grade<students[i].grade)
								{
									university[preUnivN].stu[j]=i;
									students[i].selUnivN=preUnivN;
									suc[i]=1;suc[stuN]=0;
									break;
								}
							}
						}
					}
				}
			}
		}

		int sel[160];int suc2[160];int grade[160];
		for(int i=0;i<studentNum;i++)
		{
			sel[students[i].oldId]=students[i].selUnivN;
			grade[students[i].oldId]=students[i].grade;
			suc2[students[i].oldId]=suc[i];
		}
		for(int i=0;i<studentNum;i++)
		{
			if(suc2[i]==1)
				printf("%d\n",sel[i]+1);
			else
				printf("not accepted\n");
		}
		putchar('\n');
	}

}
