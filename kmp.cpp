#include <iostream>
#include <string.h>
using namespace std;

void computeLPSArray(char* pat, int M, int* lps);


void KPMSearch(char* pat,char* txt){
  int M = strlen(pat);
  int N = strlen(txt);

  //declare a lps array with size M
  int lps[M];

  computeLPSArray(pat,M,lps);

  int i = 0;
  int j = 0;
  while((N-i)>=(M-j)){
    if(pat[j]==txt[i]){
      i++;
      j++;
    }

    if(j==M){
      cout << "Found pattern at index " << i-j << endl;
      j = lps[j-1];
    }else if(i<N && pat[j]!=txt[i]){
      if(j != 0)
        j = lps[j-1];
      else
        i = i+1;
    }
  }
}

void computeLPSArray(char* pat,int M,int* lps){
  int len = 0;

  lps[0] = 0;

  int i=1;

  while(i<M){
    if(pat[i]==pat[len]){
      len++;
      lps[i] = len;
      i++;
    }else{
      if(len!=0){
        len = lps[len-1];
      }else{
        lps[i] = 0;
        i++;
      }
    }
  }
}


int main(){
  char txt[] = "ABABDABACDABABCABAB";
  char pat[] = "ABABCABAB";
  KPMSearch(pat,txt);
  return 0;
}
