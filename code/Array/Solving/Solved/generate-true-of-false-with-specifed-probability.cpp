/**
	Question, https://sites.google.com/site/spaceofjameschen/home/math/generate-true-of-false-with-specifed-probability

	Very simple solution/
**/

bool generate(int n,int k)
{
	return (rand()%n)>=k?false:true;
}