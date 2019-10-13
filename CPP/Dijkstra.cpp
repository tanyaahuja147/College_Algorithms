#include<iostream>

using namespace std;

int shortest(int, int);

int cost[10][10],dist[10],i,j,k,n,m,s[20],v,totcost,path[20];

int p;

int main()
{
    int c;

    cout<<"\nEnter the no of vertices :";
    cin>>n;
    n++;

    cout<<"\nEnter no of edges : ";
    cin>>m;

    cout<<"\n Enter (Source,destination,path cost)\nEdge cost : ";
    for(k=1 ; k<m ; k++)
    {
        cin>>i>>j>>c;
        cost[i][j]=c;
    }

    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=n ; j++)
        {
            if(cost[i][j]==0)
            {
                cost[i][j]==31999;
            }
        }
    }
    cout<<"\n Enter initial vertex : ";
    cin>>v;
    cout<<"\n Source :"<<v<<endl;
    shortest(v,v);
    return 0;
}

int shortest(int v, int n)
{
    int mi;

    for(i=0 ; i<=n ; i++)
    {
        s[i]=0;
        dist[i]=cost[v][i];
    }

    path[++p]=v;
    s[v]=1;
    dist[v]=0;

    for(i=2 ; i<=n-1 ; i++)
    {
        k = -1;
        mi=31999;

        for(j=1 ; j<=n ; j++)
        {
            if(dist[j]<mi && s[j]!=1)
            {
                mi = dist[j];
                k=j;
            }
        }
        if(cost[v][k]<=dist[k])
        {
            p=1;
        }
        path[++p]=k;
        for(j=1;j<=p;j++)
        {
            cout<<path[j];
        }
        s[k]=1;
        for(j=1 ; j<=n ; j++)
        {
            if(cost[k][j]!=31999 && dist[j] >= dist[k] + cost[k][j] && s[j]!=1)
            {
                dist[j]=dist[k]+cost[k][j];
            }
        }
    }
}


