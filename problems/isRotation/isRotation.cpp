#include <iostream>

using namespace std;

int rotateCheck(char *str1, char * str2)
{
  int str1_len=0;
  int str2_len=0;
  while(*str1!='\0')
    {
      str1_len++;
      str1++;
    }
  cout<<"string length is "<<str1_len<<endl;
  if(str1_len==0)
    {
      cout<< "Empty string"<<endl;
      exit(1);
    }
  
  char *str1Double= (char *)malloc(str1_len*sizeof(char));
  str1=str1-str1_len;
  
  while(*str1!='\0')
    {
      *str1Double=*str1;
      str1++;
      str1Double++;
    }
  str1=str1-str1_len;
  while(*str1!='\0')
    {
      *str1Double=*str1;
      str1++;
      str1Double++;
    }
  str1Double=str1Double-2*str1_len;
  //int i;
  // for(i=0; i<2*str1_len;i++)
  // {
  // *str1Double=*str1;
  // str1++;
  // if(*str1=='\0')
  // str1=str1-str1_len;
  // }
  
  while(*str2!='\0')
    {
      str2_len++;
      str2++;
    }
  str2=str2-str2_len;
  
  if(str1_len!=str2_len)
    return 0;
  
  int count=0;
  
  while(*str1Double!='\0')
    {
      cout << "strDouble char "<<*str1Double<<endl;
      cout << "str2 char "<<*str2<<endl;
      getchar();
      
      if(*str1Double==*str2)
	{
	  count++;
	  str2++;
	}
      else
	{
	  str2=str2-count;
	  count=0;
	}
      
      cout <<endl<< "count is "<<count<<endl; 
      if(count==str2_len)
	return 1;
      
      
      str1Double++;
    }
  
  return 0;
}



int main() {
  char *str1 ="festival";
  char *str2 ="valfesti";
  
  int result;
  result=rotateCheck(str1, str2);
  
  if (result==1)
    cout<<"String2 is a rotation";
  
  else
    cout<<"String2 is not a rotation";
  
  return 0;
  
}
