#include<stdio.h>
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int arr[m][n];
    int sum[m]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
            sum[i]+=arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        
            printf("%d",sum[i]);
        
    }
}
