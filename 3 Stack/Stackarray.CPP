#include<iostream.h>
#include<conio.h>
int top=-1;
int a[100],n;
void push(int x)
{
 if(top>= n-1)
 {
  cout<<"the stack is full"<<endl;
  }
   else{
    top++;
    a[top]=x;
    }
    }
    void pop()
    {
    if(top<=-1)
    {
     cout<<"the stack is empty"<<endl;
     }
     else{
      cout<<"pop the element"<<a[top]<<endl;
      top--;
      }
      }

      void show()
      {
       if(top>=0)
       {
	cout<<"stack elements are: "<<endl;
       for(int i=top;i>=0;i--)
       {
	cout<<a[i]<<endl;
	cout<<endl;
	}
	}
	else{
	 cout<<"stack is empty"<<endl;
	 }
	 }
	 void main()
	 {
	  int choice,x;
	  clrscr();
	  cout<<"enter the size of elements:"<<endl;
	  cin>>n;
	  do{
	   cout<<"1. push"<<endl;
	   cout<<"2. pop"<<endl;
	   cout<<"3. show"<<endl;
	   cout<<"4. exit"<<endl;
	   cin>>choice;
	   switch(choice){
	    case 1:
	    {
	     cout<<"enter value to push:"<<endl;
	     cin>>x;
	     push(x);
	     break;
	     }

	     case 2:
	     {
	     pop();
	     break;
	     }
	     case 3:
	     {
	     show();
	     break;
	     }
	     case 4:
	     {
	     cout<<"exit"<<endl;
	     break;

	     }
	     default:
	     {
	      cout<<"the choice is invalid"<<endl;
	      }
	       }
	       }while(choice!=4);
	       getch();
	       }









