#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
  int num;
  struct node *preptr;
  struct node *nextptr;
} *stnode, *ennode;

void DlListcreation (int n);
void DlLinsertNodeAtMiddle (int num, int pos);
void displayDlList ();

void main ()
{
clrscr();
  int n, num1, a, insPlc;
  stnode = NULL;
  ennode = NULL;

  cout << "Input the number of nodes: ";
  cin >> n;
  DlListcreation (n);
  displayDlList ();

  cout << "Input the position (2 to " << n - 1 << ") to insert a new node: ";
  cin >> insPlc;

  if (insPlc <= 1 || insPlc >= n)
    {
      cout << "Invalid position\n";
    }
  else
    {
      cout << "Input data for the position " << insPlc << ": ";
      cin >> num1;
      DlLinsertNodeAtMiddle (num1, insPlc);
      displayDlList ();
    }
  getch();
}

void DlListcreation (int n)
{
  int i, num;
  struct node *fnNode;

  if (n >= 1)
    {
      stnode = (struct node *) malloc (sizeof (struct node));

      if (stnode != NULL)
	{
	  cout << "Input data for node 1: ";
	  cin >> num;

	  stnode->num = num;
	  stnode->preptr = NULL;
	  stnode->nextptr = NULL;
	  ennode = stnode;

	  for (i = 2; i <= n; i++)
	    {
	      fnNode = (struct node *) malloc (sizeof (struct node));

	      if (fnNode != NULL)
		{
		  cout << "Input data for node " << i << ": ";
		  cin >> num;
		  fnNode->num = num;
		  fnNode->preptr = ennode;
		  fnNode->nextptr = NULL;
		  ennode->nextptr = fnNode;
		  ennode = fnNode;
		}
	      else
		{
		  cout << "Memory cannot be allocated.";
		  break;
		}
	    }
	}
      else
	{
	  cout << "Memory cannot be allocated.";
	}
    }
}

void DlLinsertNodeAtMiddle (int num, int pos)
{
  int i;
  struct node *newnode, *tmp;
  if (ennode == NULL)
    {
      cout << "No data found in the list!\n";
    }
  else
    {
      tmp = stnode;
      i = 1;
      while (i < pos)
	{
	  tmp = tmp->nextptr;
	  i++;
	}
      if (tmp != NULL)
	{
	  newnode = (struct node *) malloc (sizeof (struct node));
	  newnode->num = num;
	  newnode->nextptr = tmp->nextptr;
	  newnode->preptr = tmp;
	  if (tmp->nextptr != NULL)
	    {
	      tmp->nextptr->preptr = newnode;
	    }
	  tmp->nextptr = newnode;
	}
      else
	{
	  cout << "The position you entered is invalid.\n";
	}
    }
}

void displayDlList ()
{
  struct node *tmp;
  tmp = stnode;
  int n = 1;
  while (tmp != NULL)
    {
      cout << " node " << n << ": " << tmp->num << "\n";
      n++;
      tmp = tmp->nextptr;	// current pointer moves to the next node
    }
}