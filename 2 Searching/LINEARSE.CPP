#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
 int arr[100],n,i,index,num;
 cout<<"enter the array:"<<endl;
 cin>>n;
 cout<<"enter the numbers in array:"<<endl;

 for(i=0;i<n;i++)

  cin>>arr[i];
	cout<<"enter the element to search in array:"<<endl;
  cin>>num;

  for(i=0;i<n;i++)
  {
     if(arr[i]==num)
     {
      index=i;
      break;
      }
     }

     cout<<"the element found at index number:"<<index<<endl;
     getch();

     }












