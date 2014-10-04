#include <cmath>
#include <math.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() 
{
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
  vector<int> arr;
  int N;
  int i,j, k,elem,highest=0;
    
  cin>>elem;
  N=elem;
    
  //cout << "Count is "<<N<<endl;
  for(i=0;i<N;i++)
    {
      cin>>elem;
      arr.push_back(elem);
      //cout<< "pushing elem "<<elem<<endl;
    }

  unordered_map<int,int> numMap;
  vector<int> xorList;
        
  //for(j=0;j<N;j++)
  for(j=N-1;j>=0;j--)
    {
      elem= arr[j];
      //cout<< "list from "<<elem<<endl;
      //cout << elem <<endl;
        
      if(!numMap[elem])
	numMap[elem]=1;        
      else
        {
	  if(numMap[elem]>highest)
	    highest=numMap[elem];
	  numMap[elem]++;
        }
        
      //if(j==N-1) 
      //  break;
        
      if(!xorList.empty())
        {
	  for(k=0; k<xorList.size(); k++)
	    {
	      //cout <<xorList[k]<<" ^ "<<arr[j]<<" = ";
	      xorList[k]=xorList[k]^arr[j]; 
	      //cout << xorList[k] <<endl;                
	      if(!numMap[xorList[k]])
		numMap[xorList[k]]=1;        
	      else
                {
		  numMap[xorList[k]]++;
		  if(numMap[xorList[k]]>highest)
                    highest=numMap[xorList[k]];
                }
	    }
        }
        
      /*
        for(i=1+j; i<N;i++)
        {
            
            elem=elem^arr[i];
            cout << elem <<endl;
            
            if(!numMap[elem])
                numMap[elem]=1;        
            else
            {
                numMap[elem]++;
                if(numMap[elem]>highest)
                    highest=numMap[elem];
            }
        }
      */
        
      xorList.push_back(elem);
      //cout <<"list ends"<<endl<<endl;
    }
    
  //cout << "highest count is"<< highest<<endl;
  unordered_map<int,int>::const_iterator it;    
  int key = 10000000;
  int ans= key;
  for (it = numMap.begin(); it != numMap.end(); ++it)
    {
      if (it->second == highest)
        {
	  key = it->first;
	  //cout <<"key value: "<<key<<endl;
	  if(key<ans)
            {
	      //cout<<"found something smaller"<<endl;
	      ans=key;
            }

        }
    }
    
  cout<<ans<<" "<<highest<<endl;
    
  return 0;
}
