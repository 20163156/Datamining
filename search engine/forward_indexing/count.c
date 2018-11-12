/*

	wordcount.exe 명령어를 623 번 하기 위해 배치파일을 만드는 C 코드

*/


#include <stdio.h>
#include <stdlib.h>

int main(){
     
     FILE *f = NULL;
     f = fopen("run2.txt","w");
     
     int i= 1;
     while(i<=623){
		fprintf(f,"wordcount.exe -new C:/Users/jiyeon/Desktop/ir2/output%d.txt count%d.txt \n",i,i);
		i++; 
	 }
}
