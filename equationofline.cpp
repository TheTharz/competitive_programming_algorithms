#include <iostream>
using namespace std;
int main(){
  int x1,y1,x2,y2;
  cout << "X1,Y1";
  cin >> x1 >> y1;
  cout << "X2,Y2";
  cin >> x2 >> y2;

  int a = y2-y1;
  int b = x1-x2;
  int c = x2*y1-x1*y2;


  

  cout << "Equation of line is " << a << "x + " << b << "y + " << c << " = 0" << endl;
}