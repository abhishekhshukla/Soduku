#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007
using namespace std;
// a[][] is matrix which contains solution of sodyko
// please enter '0' for Null Spaces of Soduku 
bool check(int a[][10],int n,int i,int j,int num)
     {   
       int x;
	   for(x=0;x<n;x++)
	     {
			 if(a[i][x]==num)
			   {
				   return false;
			   }
			   if(a[x][j]==num)
			      {
					  return false;
				  }
		 }

		 int r=sqrt(n);
		int  xx=(i/r)*r;
		
		 int yy=(j/r)*r;
		 int y;
		 for(x=xx;x<xx+r;x++)
            {
				for(y=yy;y<yy+r;y++)
				  if(a[x][y]==num)
				    return false;
			}  
			return true;       

	 }

bool calc(int a[][10],int n,int i,int j)
   {
	    
	  if(i==n)
	    {
			for(int x=0;x<n;x++)
			  {
				  for(int y=0;y<n;y++)
				    cout<<a[x][y]<<" ";
					cout<<"\n";
			  }

			return true;
		}
		if(j==n)
		 return calc(a,n,i+1,0);
		  
		if(a[i][j]!=0)
		  return calc(a,n,i,j+1);
		
		for(int num=1;num<=n;num++)
		   {
			   if(check(a,n,i,j,num))
			     {   
					   a[i][j]=num;
					   if(calc(a,n,i,j))
					      {
							  return true;
						  }
                       
				 }
		   }
		   a[i][j]=0;
		   return false;
   }

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int a[10][10];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
		   {
			   cin>>a[i][j];
		   }
	calc(a,n,0,0);

}
