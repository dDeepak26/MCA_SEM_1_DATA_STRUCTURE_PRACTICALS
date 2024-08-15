#include<iostream.h>
#include<conio.h>

int vertArr[20][20]; 
int count = 0;
void displayMatrix(int v) {
 int i, j;
 for(i = 0; i < v; i++) {
 for(j = 0; j < v; j++) {
 cout << vertArr[i][j] << " ";
 }
 cout << endl;
 }
}
void add_edge(int u, int v) 
{ 
 vertArr[u][v] = 1;
 vertArr[v][u] = 1;
}
 int main() {
clrscr();
 int v = 5; 
 add_edge(0, 1);
 add_edge(0, 2);
 add_edge(0, 4);
 add_edge(1, 3);
 add_edge(3, 2);
 add_edge(2, 4);
 displayMatrix(v);
getch();
 return 0;
}
