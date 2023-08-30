#include <iostream>
#include <string>
using namespace std;

void rabin_carp(string text,string pattern){
  int m = pattern.length();//length of pattern
  int n = text.length();//length of text
  int q = 128;//mod
  int x = 11;//typical prime multiplier
  int x_m = 1;//x^(m-1) used for next hash computation
  int hash_pattern = 0;
  int hash_text = 0;
  
  for (int i = 0; i <m-1; i++)
    x_m = (x_m*x)%q;

  //hash value of string and pattern
  for(int i = 0; i <m; i++){
    hash_pattern = (hash_pattern*x+pattern[i])%q;
    hash_text = (hash_text*x+text[i])%q;
  }

  //find the match
  for(int i=0;i<=n-m;i++){
    if(hash_pattern==hash_text){
      int j;
      for(j=0;j<m;j++){
        if(text[i+j]!=pattern[j])
          break;
      }
      if(j==m)
        cout<<"Pattern found at index "<<i<<endl;
    }
    if(i<n-m){
      hash_text = (x*(hash_text-text[i]*x_m)+text[i+m])%q;
      if(hash_text<0)
        hash_text = hash_text+q;
    }
  }
}


int main(){
  string test = "ABCDEFGHIJKL";
  string pattern = "EFG";
  rabin_carp(test,pattern);
}