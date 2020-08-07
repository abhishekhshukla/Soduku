#include <bits/stdc++.h>
#define int long long int
#define mod 1000000007
#define w(t) int t; cin>>t; while(t--)
#define f(i,n) for( int i=0;i<n;i++)
#define pb push_back()
#define pob pop_back()
using namespace std;

bool rakhPaye(int *a,int n,int c,int mine)
    {
		int k=1;
		int su=0;
		for(int i=0;i<n;i++)
		   {
			    if(su+a[i]>mine)
				  {
					  k++;
					  su=a[i];
				  
				 if(k>c)
				   return false;}
				else su+=a[i];
		   }
		 return true;

	}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	w(t)
	  {

		  int n,k;
		  cin>>n;
		  int sum=0;
		  int a[n];
          f(i,n)
		    {   int x;
				cin>>x;a[i]=x;
				sum+=x;
			}
			cin>>k;
           //  sort(a,a+n);
			int s,e=sum;
			//int mid;
			s=*max_element(a,a+n);
			int ans=INT_MAX;
			while(s<=e)
			 {
				int mid=(s+e)/2;
				 
				bool rekpaye=rakhPaye(a,n,k,mid);
				if(rekpaye==true)
				   {  
					  ans=min(mid,ans);
                      e=mid-1;
				   }
				   else s=mid+1;
			 }

			 if(ans==INT_MAX)
			    ans=-1;
			 cout<<ans<<"\n";
	  }    

}

