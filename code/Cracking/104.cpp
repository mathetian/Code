#define POS -1
#define NEG 1
 
int getFlag(int a)
{
    return a>0?POS:NEG;
}
 
int getNegative(int a)
{
    if(a==0)
        return a;
    int flag=getFlag(a);
    int b=0;
    while(a!=0)
    {
        a+=flag;
        b+=flag;
    }
    return b;
}
 
int minus(int a,int b)
{
    return a+getNegative(b);
}
 
int multiplyABS(int a,int b)
{
    if(a<b) return multiplyABS(b,a);
    int r=0;
    for(;b>0;b--)
        r+=a;
    return r;
}
 
int multiply(int a,int b)
{
    int r=multiplyABS(abs(a),abs(b));
    if(getFlag(a)==getFlag(b))
        return r;
    return getNegative(r);
}
 
int divideABS(int a,int b)
{
    if(a<b)  return 0;
    int r=0;
    for(;a>=b;a=minus(a,b))
        r+=1;
    return r;
}
 
int divide(int a,int b)
{
    if(b==0)
        throw "error";
    int r=divideABS(abs(a),abs(b));
    if(getFlag(a)==getFlag(b))
        return r;
    return getNegative(r);
}