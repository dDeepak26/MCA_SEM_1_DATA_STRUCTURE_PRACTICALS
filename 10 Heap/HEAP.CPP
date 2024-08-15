#include<iostream.h>
#include <stdio.h>
#include <conio.h> // For getch()
#include <stdlib.h>
#define MAX_SIZE 100
int heap[MAX_SIZE];
int n = 0; // Represents the number of nodes intheheap
void insert(int num);
void deleteMax();
void display();
int main() {
int choice, num;
while (1) {
clrscr();
cout<<"--------------------------------------\n";
cout<<" Heap \n";
cout<<"--------------------------------------\n";
cout<<"1. Insert an element\n";
cout<<"2. Delete the maximum element\n";
cout<<"3. Display all elements \n";
cout<<"4. Quit\n";
cout<<"Enter your choice: ";
scanf("%d"
, &choice);
switch (choice) {
case 1:
printf("Enter the element to be inserted: ");scanf("%d"
, &num);
insert(num);
break;
case 2:
deleteMax();
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("Invalid choice\n");
}
getch(); // Wait for user input
}
}
void insert(int num) {
int parent;
n++; // Increase the number of nodes
int location = n - 1;
while (location > 0) {
parent = (location - 1) / 2;
if (num <= heap[parent]) {
heap[location] = num;
return;
}
heap[location] = heap[parent];
location = parent;
}
heap[0] = num; // Assign the number to the root
}
void deleteMax() {
if (n == 0) {
printf("Heap is empty \n");
return;
}
int max_value = heap[0];
heap[0] = heap[n - 1];
n--;
int i = 0;
int left, right, temp;
while (1)
{
left = 2 * i + 1;
right = 2 * i + 2;
if (right < n) {
if (heap[i] >= heap[left] && heap[i] >=heap[right])
return;
if (heap[right] <= heap[left]) {
temp = heap[i];
heap[i] = heap[left];
heap[left] = temp;
i = left;
}
else
{
temp = heap[i];
heap[i] = heap[right];
heap[right] = temp;
i = right;
}
} else if (left == n - 1 && heap[i] < heap[left]){temp = heap[i];
heap[i] = heap[left];
heap[left] = temp;
return;
}
else
return;
}
}
void display()
{
if (n == 0)
{
printf("Heap is empty\n");
return;
}
printf("Heap elements: ");
for (int i = 0; i < n; i++)
printf("%d ", heap[i]);
printf("\n");
}