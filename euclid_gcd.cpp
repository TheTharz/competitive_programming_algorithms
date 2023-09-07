#include <iostream>
using namespace std;

int euclid_gcd(int a, int b){
  if(b==0)
    return a;
  else
    return euclid_gcd(b,a%b);
}

int main(){
  cout << euclid_gcd(60,29);// finds the gcd of 60 and 29
}
//p.s when entering the values to the function, the first value should be greater than the second value