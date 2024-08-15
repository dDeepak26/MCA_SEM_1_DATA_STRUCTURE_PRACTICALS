#include <iostream.h> 

#include <conio.h> 

class selection 

{ 

int a[10]; 

int i, n, min_index, j; 

public: 

void get(); 

void sort(); 

}; 

void selection::get() 

{ 

cout << "\n\n Selection Sort : \n\n"; 

cout << "\n Enter the size of Array : "; 

cin >> n; 

cout << "\n Enter elements : \n"; 

for (i = 0; i < n; i++) 

{ 

cin >> a[i]; 

} 

} 

 

// selection sorting 

void selection::sort() 

{ 

 

for (i = 0; i <= n - 2; i++) 

{ 

min_index = i; 

for (j = i + 1; j <= n - 1; j++) 

{ 

if (a[min_index] > a[j]) 

min_index = j; 

} 

 

// exchange smallest number with i th position number 

if (min_index != i) 

{ 

int temp; 

temp = a[i]; 

a[i] = a[min_index]; 

a[min_index] = temp; 

} 

} 

cout << "\n Array elements after selection sort : \n"; 

for (i = 0; i < n; i++) 

cout << a[i] << "\t"; 

} 

void main() 

{ 

clrscr(); 

selection s; 

s.get(); 

s.sort(); 

getch(); 

} 