#include<iostream>  
using namespace std;  
int findSmallest (int[],int);  
int main ()  
{  
    int myarray[22] = {65,110,116,111,110,105,111,32,82,116,111,115,107,105,32,73,78,75,73,57,56,48};  
    int pos,temp,pass=0;  
    cout<<"\n Input list of elements to be Sorted\n";  
    for(int i=0;i<22;i++)  
    {  
        cout<<myarray[i]<<"\t";  
    } 
    for(int i=0;i<22;i++)  
    {  
        pos = findSmallest (myarray,i);  
        temp = myarray[i];  
        myarray[i]=myarray[pos];  
        myarray[pos] = temp; 
        pass++;
    }  
    cout<<"\n Sorted list of elements is\n";  
    for(int i=0;i<22;i++)  
    {  
        cout<<myarray[i]<<"\t";  
    } 
    cout<<"\nNumber of passes required to sort the array: "<<pass;
    return 0;  
}  
int findSmallest(int myarray[],int i)  
{  
    int ele_small,position,j;  
    ele_small = myarray[i];  
    position = i;  
    for(j=i+1;j<22;j++)  
    {  
        if(myarray[j]<ele_small)  
        {  
            ele_small = myarray[j];  
            position=j;  
        }  
    }  
    return position;  
}