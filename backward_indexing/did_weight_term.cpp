/*

df.txt에는 TERM들과 각각의 TERM들에 대한 DF들이 담겨있다. 이때 텍스트파일에 써진 TERM들의 순서는 TID가 된다.
즉 , 첫번째 TERM인 %( 의 TID는 1이고 DF는 2이다.
out1.txt~out623.txt 에는 1번문서부터 623번문서에 해당하는 가중치(weight)와 TERM들이 저장된다.
Ex)out1.txt --à DID가 1번인 문서의 TERM들과 weight가 저장되어있다.


*/


#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <sstream>

using namespace std;
int arr[33000] = {0,};
string arr2[33000] = {"0",};

int main(){


   ifstream in("df.txt");
   int i = 1; 
   int j = 1;

   while(!in.eof()){
     string term;
     int df;
      in >> df >> term;
      arr[i++] = df;
      arr2[j++] = term;

   }

  for(int i = 1;i <= 623;i++){
    string name = "count";
    string name2 = "/Users/jiyeon/Downloads/out/out";

    string name_tmp;
    stringstream s;
    s << i;
    name_tmp = s.str();

    name.append(name_tmp);
    name.append(".txt");

    name2.append(name_tmp);
    name2.append(".txt");

    ifstream in2(name);
    ofstream of(name2);

        while(!in2.eof()){ 
          string tem;
          int tf;

          in2 >> tf >> tem;

          double weight;  
          for(int k = 1;k<33000;k++){
            if(arr2[k] == tem){
              weight = tf * (log2(623/double(arr[k])));
              break;
            }
          }

          of << weight << "   " << tem << endl;
       
        

        }

  }

}
