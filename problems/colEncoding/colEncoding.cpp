#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int ssdecode(const string str)
{
  int i,c;
  int sum=0;
  int len = str.size();
  cout<< len<<endl;
  for(i=0; i<len; i++)
    {
      c=str[i];
      sum = sum + pow(26,len-1-i)* (c- 'A'+1);
      //cout<<endl<<sum<<endl;
      
    }
  return sum;
}

int main() {
 // your code goes here
  string s;
  cout<< "Input the column string "<<endl;
  cin>>s;
  int res= ssdecode(s);
  
  cout<<"result is "<<res<<endl;
   return 0;
 }  
