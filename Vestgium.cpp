#include<iostream>
#include<unordered_map>
#include<iterator>
using namespace std;
void func(int** arr,int n,int t)
{
    unordered_map<int,int> colMap;
    int diagSum = 0;
    int rowSum = 0;
    int colSum = 0;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(i == j)
                diagSum+= arr[i][j];
        }
    }
    for(int i = 0;i<n;i++)
    {
         unordered_map<int,int> rowMap;
         for(int j = 0;j<n;j++)
         {
             rowMap[arr[i][j]]++;
         }

         unordered_map<int,int>::iterator it = rowMap.begin();
         while(it!=rowMap.end())
         {
             if(it->second > 1)
             {
                 rowSum++;
                 break;
             }
             it++;
         }
    }
    for(int i = 0;i<n;i++)
    {
         unordered_map<int,int> colMap;
         for(int j = 0;j<n;j++)
         {
             colMap[arr[j][i]]++;
         }

         unordered_map<int,int>::iterator it = colMap.begin();
         while(it!=colMap.end())
         {
             if(it->second > 1)
             {
                 colSum++;
                 break;
             }
             it++;
         }
    }

    cout<<"Case #"<<t+1<<": "<<diagSum<<" "<<rowSum<<" "<<colSum<<endl;

}
int main()
{
    int t;
    cin>>t;

    for(int x=0;x<t;x++)
    {
        int n;
        cin>>n;
        int **arr = new int*[n];
        for(int i = 0;i<n;i++)
            arr[i] = new int[n];

        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }
        func(arr,n,x);
        for (int i=0; i<n; i++)
            delete[] arr[i];

        delete[] arr;
    }
    return 0;

}
