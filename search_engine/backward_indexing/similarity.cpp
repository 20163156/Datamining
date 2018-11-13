/*
유사도 계산모델은 cosine similarity로 하고 식은 다음과 같다.
upper triangular matrix 를 구현하기 위한 2차원 배열의 변수명은 sim으로 한다.
tid_term.txt에는 <TID,TERM>쌍이 들어있다.
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <cmath>

using namespace std;
double freq[38000][624] = {0, };
double sim[624][624] = {0,};

int main(){


   ifstream in("tid_term.txt");
   string table[38000];

   while(!in.eof()){
     string term;
     int tid;
      in >> term >> tid;
      table[tid] = term;

   }


   for(int i = 1;i <= 623;++i){
     string name = "/Users/jiyeon/Downloads/out/out"; 
     
     string tmp;
     stringstream s;
     s << i;
     tmp = s.str();

     name.append(tmp);
     name.append(".txt");

     ifstream in2(name);
     int j = 0;

     while(j<400){

        string tmp_term;
        double weight;
        int tmp;

        in2 >> weight >> tmp_term;

        for(int k = 1;k < 38000;k++){
          if(tmp_term == table[k]){
            tmp = k;
            break;
          }
        }

        freq[tmp][i] = weight;
        j++;

     }


   }
   

   for(int i = 1;i <=623;i++){
    for(int j = i+1; i < j;j++){
      double vec = 0;
      double i_sum = 0;
      double j_sum = 0;
      for(int k = 1;k < 33000;k++){
        vec += freq[k][i] * freq[k][j];
        i_sum += freq[k][i] * freq[k][i];
        j_sum += freq[k][j] * freq[k][j];


      }
      sim[i][j] = vec / sqrt(i_sum * j_sum);
      if(j>623){break;}
    }
   }

   ofstream of("simil_matrix.txt");
   for(int i = 1;i<=623;i++){
   	for(int j = 1;i<=623;j++){
   		of<<sim[i][j] <<" ";
   	}
   }



}
