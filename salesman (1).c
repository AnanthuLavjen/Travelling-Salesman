#include<stdio.h>
#include<stdlib.h>
struct node
{
    int city ;
    int cost;
    struct node *link;
}*gptr[20],*ptr;
int visit[20],tcost=0,n;
void createGraph()
{
    int i,j,v,k,item,money;
    struct node *temp;
    printf("Enter the no of vertices : ");
    scanf("%d",&n);
    for ( i = 1 ; i <= n; i++)
    {
        gptr[i]=NULL;
    }
    for ( i = 1 ; i <= n; i++)
    {
        printf("Enter the starting city  : ");
        scanf("%d",&v);
        printf("Enter the no of cities connected to city %d : ",v);
        scanf("%d",&k);
        for ( j = 1 ; j <= k; j++)
        {
            struct node *p = (struct node *)malloc(sizeof(struct node));
            printf("Enter the city connected no %d : ",j);
            scanf("%d",&item);
            printf("Enter the cost of travel : ");
            scanf("%d",&money);
            if (gptr[v]==NULL)
            {
                p->city  = item;
                p->cost = money;
                p->link = NULL;
                gptr[v]=p;
            }
            else
            {
                temp = gptr[v];
                p->city  = item;
                p->cost = money;
                p->link = NULL;
                while (temp->link != NULL)
                    temp = temp->link;
                temp->link=p;
            }
        }
    }
}
int next_v(int v)
{
    int min = 1000000,democost=0;
    struct node *temp=NULL;
    for (ptr=gptr[v] ; ptr!=NULL ; ptr = ptr->link)
    {
        if ((!visit[ptr->city ]) && (ptr->cost != 0 ) && (ptr->cost < min))
        {
            democost = ptr->cost;
            min = ptr->cost;
            temp = ptr;
        }
    }
    if (temp!=NULL)
    {
        tcost += democost;
        return temp->city ;
    }
    else
        return v+100;    
}
void TSP(int v)
{
    int next,count;
    visit[v] = 1;
    printf("%d->",v);
    next = next_v(v);
    if(next == v+100)
    {
        int i = 1;
        tcost += gptr[next-100]->cost ;
        printf("1\n"); 
        return;
    }
    TSP(next);
}
int main()
{
    int w;
    createGraph();
    printf("The shortest path is :\n");
    TSP(1);
    printf("The total cost is : %d",tcost);
    return 0;
}