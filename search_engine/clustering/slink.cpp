/*

구했던 유사도행렬을 이용해 SLINK를 구현하기 위해 유사도행렬을 텍스트 파일 (simil_matrix.txt)에 쓴 후 아래의 코드를 실행
SLINK 구현방법은 UNION_FIND 트리를 사용

*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;
double sim[624][624] = {0, };
int parent[624];

void init(){
  for(int i=0;i<6;i++){
    parent[i] = i;
  }
}

int find(int x){
  if(parent[x]==x) return x;
  return find(parent[x]);
}

void merge(int x,int y){
  x = find(x);
  y = find(y);
  if(x == y) return;
  parent[y] = x;
}

int main(){

  double simil;
  ifstream in("simil_matrix.txt");

  for(int i = 1;i < 624;i++){
    for(int j = 1;j < 624;j++){
      in >> simil;
      sim[i][j] = simil;
    }
  }
   //초기화
  init();
  
  for(int k=0;k<194376;k++)
  {
    double max = -1;
    int max_i,max_j;

    //max값 찾고 최대값을 배열에서 지우기(0으로 만들기)
    for(int i = 1;i < 624;i++){
      for(int j = i+1;j < 624;j++){
        if(sim[i][j]>=max){
           max = sim[i][j];
           max_i = i;
           max_j = j;
        }
      }
    }

    sim[max_i][max_j] = 0;

    //최대값 클러스터링
    merge(max_i,max_j);

  }

  for(int i = 1;i < 624;i++){
  	cout << parent[i] << " ";
  }
  

}




