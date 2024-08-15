#include<iostream.h>
#include<conio.h>
void main()
{
int arr[10],num,first,last,middle,i;
cout<<"Enter the 10 array elements:";
for(i=0;i<10;i++)
cin>>arr[i];
cout<<"\n Enter Element to be search:";
cin>>num;
first=0;
last=9;
middle=(first+last)/2;
while(first<=last)
{
if(arr[middle]<num)
first=middle+1;
else if(arr[middle]==num)
{
cout<<"\n The Number,"<<num<<"Found at position "<<middle+1;
break;
}
else
last=middle-1;
middle=(first+last)/2;
}
if(first>last)
cout<<"\n the Number,"<<num<<"is not found in givven array:";
cout<<endl;
getch();
}