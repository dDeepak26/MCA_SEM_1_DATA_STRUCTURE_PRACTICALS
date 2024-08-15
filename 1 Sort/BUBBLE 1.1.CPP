#include<iostream.h>
#include<conio.h>
int main()
{
clrscr();
int i,j,temp,pass=0;
int a[10];
cout<<"inert into the array:\n";
for(i=0;i<10;i++)
{
cin>>a[i];
}
cout<<"Arry is:"<<a[i];
for(i=0;i<10;i++)
{
	for(j=i+1;j<10;j++)
	{
	  temp=a[i];
	  a[i]=a[j];
	  a[j]=temp;
	}
	pass++;
}
cout<<"sorted list is: \n ";
for(i=0;i<10;i++)
{
cout<<a[i]<<"\n";
}
 cout<<"Number of pass are:"<<pass;
 getch();
 return 0;
}
