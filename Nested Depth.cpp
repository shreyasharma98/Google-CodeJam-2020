#include<iostream>
#include<string>
using namespace std;


int main() {
  int t;
  cin>>t;
  for(int testCase = 0;testCase<t;testCase++)
  {
      string s;
      cin>>s;
      string output = "";
      int n = s.length();
     // bool *visited = new bool[n];
    for(int j = 0;j<s[0]-48;j++)
     {
         output+='(';
     }
     output+=s[0];
      for(int i = 1;i<n;i++)
      {
             if(s[i] == s[i-1])
             {
                 output+=s[i];
             }
             else if(s[i] > s[i-1])
             {
                 int temp = s[i]-s[i-1];
                 for(int j = 0;j<temp;j++)
                 {
                     output+='(';
                 }
                 output+=s[i];
             }
             else
             {
                 int temp = s[i-1]-s[i];
                 for(int j = 0;j<temp;j++)
                 {
                     output+=')';
                 }
                 output+=s[i];
             }
      }
      for(int j = 0;j<s[n-1]-48;j++)
     {
         output+=')';
     }
      cout<<"Case #"<<testCase+1<<": "<<output<<endl;
  }
  return 0;
  }

