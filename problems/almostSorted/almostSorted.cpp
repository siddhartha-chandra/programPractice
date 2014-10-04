#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
  int i,N,elem;
    
  cin>>N;
    
  vector<int> vec;
  vec.resize(N);
  for(i=0;i<N;i++)
    {
      cin>>elem;
      vec[i]=elem;
      //cout<<vec[i]<<endl;
    }
    
  int small=0;
  int large=N-1;
  bool smallSet=false;
  bool largeSet=false;
    
  for(i=1; i<N;i++)
    {
      if(small>large)
	break;
        
      if(vec[i]<vec[i-1] && smallSet==false)
        {
	  small=i-1;
	  smallSet=true;
        }
          
      //cout <<"::"<<vec[N-i-1]<<" "<<vec[N-i]<<endl;
      if(vec[N-i-1]>vec[N-i] && largeSet==false)
        {

	  large=N-i;
	  //cout << "setting large= "<<large<<endl;
	  largeSet=true;
        }
            
    }
    
  //cout<<"small: "<<small<<endl;
  //cout<<"large: "<<large<<endl;
    
  if(!smallSet && !largeSet)
    {
      cout<<"yes"<<endl;
      return 0;
    }
    
  if(N==2)
    {
      cout<<"yes"<<endl<<"swap "<<1<<" "<<2<<endl;
      return 0;    
    }
    
  //swapping large and small index
  vec[small]=vec[small]^vec[large];
  vec[large]=vec[small]^vec[large];
  vec[small]=vec[small]^vec[large];
    
  bool rev=false;
  bool swap=true;
    
  for(i=small; i<large; i++)
    {    
      if(vec[i+1]<vec[i])
        {           
	  if(swap==false)
            {
	      rev=false;
	      break;
            }
            
	  rev=true;
	  swap=false;
	  break;
        }   
           
    }
    
  int l;

    
  if(rev==true)
    {
      //cout<<"rev is true"<<endl;
      int tempSmall=small+1;
      int tempLarge=large-1;
        
      while(tempSmall<tempLarge)
        {   
	  vec[tempSmall]=vec[tempSmall]^vec[tempLarge];
	  vec[tempLarge]=vec[tempSmall]^vec[tempLarge];         
	  vec[tempSmall]=vec[tempSmall]^vec[tempLarge];   
            
	  tempSmall++;
	  tempLarge--;
        }
            
            
    }
    
  //cout<<"swap= "<<swap<<endl;
  //cout<<"rev= "<<rev<<endl;
    
  for(i=0;i<N-1;i++)
    {
      //cout<<"--" <<vec[i]<<endl;
      if(vec[i+1]<vec[i])    
        {
	  //cout<<"shud not happen for sortable"<<endl;
	  swap=false;
	  rev=false;
	  break;
        }
    }
        
  if(swap==true)
    cout<<"yes"<<endl<<"swap "<<small+1<<" "<<large+1<<endl;
  else if (rev==true)
    cout<<"yes"<<endl<<"reverse "<<small+1<<" "<<large+1<<endl;
    
  if(rev==false && swap==false)
    cout<<"no"<<endl; 

  return 0;
}
