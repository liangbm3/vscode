#include <iostream>
using namespace std;

int main()
{
    int list1[]={1,3,5,7,9};
    int list2[]={2,4,6,8,10};
    int list3[15];
    int size1=5;
    int size2=5;
    int i=0,j=0,k=0;
    while (true)
    {
        if(list1[i]>list2[j])
        {
            list3[k]=list2[j];
            k=k+1;
            j=j+1;
        }
        else
        {
            list3[k]=list1[i];
            k=k+1;
            i=i+1;
        }
        
        if(i+j==size1+size2-1)
        {
            if(list1[size1-1]>list2[size2-1])
            {
                list3[size1+size2-1]=list1[size1-1];
            }
            else
            {
                list3[size1+size2-1]=list2[size2-1];
            }
            break;
        }
        
    }
    for(int k=0;k<10;k++)
    {
        cout<<list3[k]<<" ";
    }
}