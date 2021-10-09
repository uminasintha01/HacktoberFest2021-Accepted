#include <iostream>
using namespace std;
int main()
{
  int i,f=1,n;
  cout<<"Enter number of which u want to calculate factorial";
  cin>>n;

    for(i=1;i<=n;i++)
    {
      f=f*i;
    }

   cout<<"factorial of " <<n<< "is:" <<f<<endl;

  return 0;
}
