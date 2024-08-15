#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int i,j,temp,n;
int a[100];
cout<<"enter the elements:"<<endl;
cin>>n;
cout<<"Enter the array values: \n";
for(i=0;i<n;i++)
{
cin>>a[i];
}
for(i=0;i<n;i++)
{
temp=a[i];
j=i-1;
while(j>=0 && a[j]>temp)
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=temp;
}
 cout<<"Sorted list is:";
 for(i=0;i<n;i++)
 {
 cout<<a[i];
 cout<<endl;

 }
	getch();

}
