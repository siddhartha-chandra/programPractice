#include <iostream>

using namespace std;

bool isPowerOfTwo(int *num)
{
  int a=*num;
  if (((a&(a-1))==0)&&a>0)
    return true;
  else
    return false;
}

int main(int argc, char* argv[])
{
  int a;
  cout<< "Enter a number to check for power of two"<<endl;
  cin>>a;
  bool ans= isPowerOfTwo(&a);
  
  if(ans)
    cout<<"Yay! It is a power of two"<<endl;
  else
    cout<<"Not a power of two"<<endl;

  return 0;
}
