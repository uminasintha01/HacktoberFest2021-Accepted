#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,i,c=0,j;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++){
    cin>>a[i];
  }
  for(j=0;j<n-1;j++){
    if(a[j+1]<a[j]){
      c+=(a[j]-a[j+1]);
      a[j+1]=a[j];
    }
  }
  cout<<c<<endl;
  return 0;
}
