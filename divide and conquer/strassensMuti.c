#include <stdlib.h>
#include <stdio.h>

int main(){
    int n,i,j;
    int a[100][100],b[100][100],c[100][100];
    printf("Enter the order of the matrix: ");
    scanf("%d",&n);
    printf("Enter the elements of the first matrix: \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix: \n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&b[i][j]);
        }
    }
    int p=(a[1][1]+a[2][2])*(b[1][1]+b[2][2]);
    int q=(a[1][2]+a[2][2])*b[1][1];
    int r=a[1][1]*(b[1][2]-b[2][2]);
    int s=a[2][2]*(b[2][1]-b[1][1]);
    int t=(a[1][1]-a[1][2])*b[2][2];
    int u=(a[2][1]-a[1][1])*(b[1][1]+b[1][2]);
    int v=(a[1][2]-a[2][2])*(b[2][1]+b[2][2]);

    c[0][0]=p+s-t+v;
    c[0][1]=r+t;
    c[1][0]=q+s;
    c[1][1]=p+r-q+u;

    printf("The resultant matrix is: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}