//incomplete
#include <iostream>
#include <set>
#include <iterator>

using namespace std;

struct subset
{
    int n, cost;
    int a[50];
};

void subsetCover(struct subset s[],int n,int u[],int m)
{    
    set<int> u1;
    for(int i=0;i<m;i++)
        u1.insert(u[i]);
    set<int> s1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<s[i].n;j++)
        {
            s1.insert(s[i].a[j]);
        }
    }
}

int main()
{
    int n, m;
    printf("Enter the number of items: ");
    scanf("%d", &m);
    int u[m];
    printf("Enter the value of items: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &u[i]);
    }
    printf("Enter the number of subsets: ");
    scanf("%d", &n);
    struct subset s[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the cost of subset %d: ", i + 1);
        scanf("%d", &s[i].cost);
        printf("Enter the number of items in subset %d: ", i + 1);
        scanf("%d", &s[i].n);
        for (int j = 0; j < s[i].n; j++)
        {
            printf("Enter the item %d: ", j + 1);
            scanf("%d", &s[i].a[j]);
        }
    }
    subsetCover(s, n, u, m);

    return 0;
}