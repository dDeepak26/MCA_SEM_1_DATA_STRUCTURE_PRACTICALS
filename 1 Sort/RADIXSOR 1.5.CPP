#include <iostream.h> 

#include <conio.h> 

class radixsort 

{ 

    int arr[20], n, i; 

 

public: 

    void getdata(); 

    void display(); 

    void sort(); 

}; 

 

void radixsort ::getdata() 

{ 

    cout << "\n\n Radix Sort : \n\n"; 

    cout << "\n Enter the size of the array : "; 

    cin >> n; 

    cout << "\n \n Enter the elements of the Array : \n \n"; 

    for (i = 0; i < n; i++) 

        cin >> arr[i]; 

    cout << "\n Unsorted Array is : \n \n "; 

    for (i = 0; i < n; i++) 

        cout << arr[i] << " "; 

} 

void radixsort ::sort() 

{ 

    int bucket[10][20], buck_count[10], b[10]; 

    int i, j, k, r, no_of_passes = 0, divisor = 1, largest, pass_no; 

 

    largest = arr[0]; 

 

    for (i = 1; i < n; i++) // Find the largest Number 

    { 

        if (arr[i] > largest) 

            largest = arr[i]; 

    } 

 

    while (largest > 0) // Find number of digits in largest number 

    { 

        no_of_passes++; 

        largest /= 10; 

    } 

 

    for (pass_no = 0; pass_no < no_of_passes; pass_no++) 

    { 

 

        for (k = 0; k < 10; k++) 

            buck_count[k] = 0; // Initialize bucket count 

        for (i = 0; i < n; i++) 

        { 

            r = (arr[i] / divisor) % 10; 

            bucket[r][buck_count[r]++] = arr[i]; 

        } 

        i = 0; // collect elements from bucket 

        for (k = 0; k < 10; k++) 

        { 

            for (j = 0; j < buck_count[k]; j++) 

                arr[i++] = bucket[k][j]; 

        } 

 

        divisor *= 10; 

    } 

} 

void radixsort ::display() 

{ 

    cout << "\n \n Sorted list is : \n \n "; 

    for (i = 0; i < n; i++) 

        cout << arr[i] << " "; 

} 

void main() 

{ 

    clrscr(); 

    radixsort r; 

    r.getdata(); 

    r.sort(); 

    r.display(); 

    getch(); 

} 