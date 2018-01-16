#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
typedef double db;
const int maxn=1e4+5;
const db eps=1e-6;
int n,top,s[maxn];
db ans;
struct node
{
	db x,y;
	bool operator < (const node &a) const
	{
		if(fabs(x-a.x)<=eps) return y-a.y<-eps;
		return x-a.x<-eps;
	}
}p[maxn];
node minu(node a,node b)
{
	node c;
	c.x=a.x-b.x,c.y=a.y-b.y;
	return c;
}
db mul(node a,node b)
{
	return a.x*b.y-a.y*b.x;
}
db calc(node a,node b,node c)
{
	return mul(minu(b,a),minu(c,a));
}
db getdis(node a,node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++)
	{
		while(top>1&&calc(p[s[top-1]],p[s[top]],p[i])<=0) top--;
		s[++top]=i;
	}
	int temp=top;
	for(int i=n-1;i;i--)
	{
		while(top>temp&&calc(p[s[top-1]],p[s[top]],p[i])<=0) top--;
		s[++top]=i;
	}
	for(int i=2;i<=top;i++) ans+=getdis(p[s[i]],p[s[i-1]]);
	ans+=getdis(p[s[1]],p[s[top]]);
	printf("%.2lf",ans);
	return 0;
}
