#include<stdio.h>
#include<conio.h>

struct job{
    int id;
    int t1;
    int t2;
};

void sort1(int j,struct job a1[]){
    for(int i=0;i<j;i++){
        for(int k=i+1;k<j;k++){
            if(a1[i].t1>a1[k].t1){
                struct job temp = a1[i];
                a1[i] = a1[k];
                a1[k] = temp;
            }
        }
    }
}

void sort2(int k,struct job a2[]){
    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(a2[i].t2>a2[j].t2){
                struct job temp = a2[i];
                a2[i] = a2[j];
                a2[j] = temp;
            }
        }
    }
}

int main(){
    int n;
    printf("Enter the number of jobs:");
    scanf("%d",&n);

    int i, j, k;
    struct job arr[n];
    printf("Enter t1 and t2 of each job:");
    for(i=0;i<n;i++){
        arr[i].id=i+1;
        scanf("%d %d",&arr[i].t1,&arr[i].t2);
    }

    struct job a1[n];
    j=0;

    for(i=0;i<n;i++){
        if(arr[i].t1<=arr[i].t2){
            a1[j]=arr[i];
            j++;
        }
    }

    sort1(j,a1);
    
    struct job a2[n];
    k=0;

    for(i=0;i<n;i++){
        if(arr[i].t1>arr[i].t2){
            a2[k]=arr[i];
            k++;
        }
    }

    sort2(k,a2);

    struct job a3[n];
    for(i=0;i<j;i++){
        a3[i]=a1[i];
    }
    
    int l=0;
    
    for(i=j;i<j+k;i++){
        a3[i]=a2[l];
        l++;
    }

    printf("The sequence is:");
    for(i=0;i<n;i++){
        printf("%d ",a3[i].id);
    }
    return 0;
}