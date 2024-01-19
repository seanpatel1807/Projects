#include<stdio.h>
int matrixChainMulti(int n,int m[10][10],int p[5])
{
    int i,j,k,a,b,min,temp;
    int o=n;
    a=0;
    while(a!=n)
    {
        for(i=0,j=a;i<o;i++,j++)
        {
            if(i==j)
            {
                m[i][i]=0;
            }
            else if(i!=j)
            {
                min=65534;
                for(k=i;k<=j-1;k++)
                {
                    m[i][j]=m[i][k]+m[k+1][j]+(p[i]*p[k+1]*p[j+1]);
                   
                    if(min>m[i][j])
                    {
                    
                        min=m[i][j]; 
            
                    }
                    m[i][j]=min;
                }
            }
            
        }
        o--;
        a++;
    }
    return m[0][n-1];
}
void main()
{   
    int n,x;
    printf("Enter number of matrix :");
    scanf("%d",&n);
    int m[n][n];
    int p[n];
    int i=0,j;
    for(i=0;i<=n;i++)
    {   x=0;
    	printf("Enter p[%d]     :-",i);
    	scanf("%d",&x);
    	p[i]=x;
	}
    printf("Minimum numnber of operation for multiplication of following matrix:\n");
    for(i=0,j=1;i<n;i++,j++)
	{ 
		printf(" %d * %d ||",p[i],p[j]);
	   }   
   printf("\n Number of multiplication operations: %d \n",matrixChainMulti(n,m,p));
    
}
