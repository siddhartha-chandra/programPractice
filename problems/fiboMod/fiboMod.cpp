#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;

vector<short> vecAdd(vector<short> result, vector<short> A)
{
  vector<short> res;
  res.resize(result.size());
    
  int diff=result.size()-A.size();
  A.resize(A.size()+diff);

  int i;
  for(i=A.size()-diff; i<A.size();i++)
    A[i]=0;

  int carry=0;
  for(i=0;i<A.size();i++)
    {
      res[i]=A[i]+result[i]+carry;
      if(res[i]>9)
        {
	  res[i]=res[i]-10;
	  carry=1;
	  if(i== (A.size()-1))
	    res.push_back(1);
        }
      else
	carry=0;
    }
    
  return res; 
}


vector<short> vecSquare(vector<short> B)
{
  int i,j=1,carry,n=0;
    
  vector<short> ans;
  ans.resize(B.size());
  for(i=0;i<ans.size();i++)
    ans[i]=B[i];
    
  //cout<< "Need to square: ";
  for(i=B.size()-1;i>=0;i--)
    {   
      //cout<<B[i];
      n=n+ B[i]*(pow(10,i));
    }
   
  //cout<<endl<<"value of n is: "; 
  //cout<<n<<endl;
    
  while(j<n)
    {
      carry=0;
      for(i=0;i<ans.size();i++)
        {
	  //cout<<"inside squaring fnc: "<<ans[i]<<" + "<<B[i]<<" + "<<carry<<" = ";
	  ans[i]= ans[i]+B[i];
	  //cout<<ans[i]<<endl;
            
	  if(ans[i]>9)
            {
	      ans[i]=ans[i]-10;
	      //carry++;
	      if(i==ans.size()-1)
                {
		  //cout<<"creating more space in array"<<endl;
		  ans.push_back(1);
		  B.push_back(0);
		  //carry=0;
                }
	      else
                {
		  ans[i+1]=ans[i+1]+1;
		  //carry=0;
                }
                    
                 
            }
	  //else
	  //carry=0;
        }
       
      //cout<<"intermediate square result: "<<ans[i-1]<<endl;
       
      j++;
    }
   
  //cout<< "square of: "<<endl;
  //for(i=0;i<ans.size();i++)
  //    cout<<ans[i]<<" ";
  //cout<<endl<<endl;
    
  //for(i=0;i<ans.size();i++)
  //    cout<<ans[i]<<" ";
  //cout<<endl;
    
  return ans;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int N;
    
  vector<short> A,B,result;
  int Atemp,Btemp;
  cin>>Atemp;
  cin>>Btemp;
  cin>>N;
  int temp=Atemp;
    
  while((Atemp/10)!=0)
    {
      result.push_back(Atemp%10);
      Atemp/=10;
    }
    
  //cout<<to_string(temp%10)<<"jess"<<endl;
  A.push_back(Atemp%10);
    
  while((Btemp/10)!=0)
    {
      B.push_back(Btemp%10);
      Btemp/=10;
    }
    
  //cout<<to_string(temp%10)<<"jess"<<endl;
  B.push_back(Btemp%10);

    
  while((temp/10)!=0)
    {
      result.push_back(temp%10);
      temp/=10;
    }
    
  //cout<<to_string(temp%10)<<"jess"<<endl;
  result.push_back(temp%10);

    
  int i,j;
  //for(i=0; i<result.size(); i++)
  //    cout<<result[i]<<endl;
  
  for(i=0; i<N-2; i++)
    {   
        
      //cout<<"___"<<pow(B,2)<<endl;
      //cout<<"need to find Power of: ";
      //for(j=0;j<B.size();j++)
      //    cout<<B[j];
      //cout<<endl;
        
        
      result = vecSquare(B);
      result = vecAdd(result,A);
        
        
      //for(j=0;j<result.size();j++)
      //    cout<<result[j];
        
      //cout<<" = ";
        
      //for(j=0;j<B.size();j++)
      //    cout<<B[j];       
      //cout<<"^2 + ";
        
      //for(j=0;j<A.size();j++)
      //    cout<<A[j];
      //cout<<endl;
        
        
      A.resize(B.size());
      for(j=0;j<A.size();j++)
	A[j]=B[j];

      B.resize(result.size());
      for(j=0;j<B.size();j++)
	B[j]=result[j];
        
        
        
      //cout<<result[0]<<endl;
    }
        
  //cout<<endl<<"Final Result: "<<endl;
  for(i=result.size()-1;i>=0;i--)
    {
      cout<<result[i];    
    }
    
    
  //cout<<fixed<<setprecision(0)<<result<<endl;
  //cout << setprecision(0) << result<<endl;
    
  return 0;
}
