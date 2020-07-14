#include<iostream>
#include<stdio.h>
#define MAXLENGTH 10
using namespace std;

int w[100],p[100],x[100],f[100][100];

void backpack(int m,int n)
{
    int y=0,i=0;
    for(y=0;y<=m;y++)//初始化
        f[n][y]=0;
    for(y=w[n];y<=m;y++)
        f[n][y]=p[n];
    for(i=n-1;i>0;i--)//核心算法，动态规划
    {
        for(y=0;y<=m;y++)
            f[i][y]=f[i+1][y];
        for(y=w[i];y<=m;y++)
            if(f[i+1][y]<=f[i+1][y-w[i]]+p[i])
                f[i][y]=f[i+1][y-w[i]]+p[i];
    }
}
void solution(int m,int n)
{
    int i=0;
    for(i=1;i<n;i++)
    {
        if(f[i][m]==f[i+1][m])//如果没发生变化，则是没装
            x[i]=0;
        else//否则装上
        {
            x[i]=1;
            m=m-w[i];
        }
    }
}


int main()
{
    int tw,tp,m,n,s,i;
    cout<<"请输入背包最大容量m"<<endl;
    cin>>m;
    cout<<"请输入物品组数n"<<endl;
    cin>>n;
    cout<<"请输入各组物品的w和p"<<endl;
    s=0;
    for(i=1;i<=n;i++)
    {
        cin>>tw>>tp;
        s=s+tw;
        w[i]=tw;
        p[i]=tp;
    }
    if(s<=m)
    {
        cout<<"全装下了"<<endl;
        return 0;
    }
    backpack(m,n);
    solution(m,n);
    for(i=1;i<=n;i++)
        cout<<"x["<<i<<"]="<<x[i]<<endl;
    cout<<"最大价值为"<<f[1][m]<<endl;
    return 0;
}
