/*

	index2018.exe 명령어를 623 번 하기 위해 배치파일을 만드는 C 코드

*/
#include <stdio.h>
#include <stdlib.h>

int main(){

     FILE *f = NULL;
     f = fopen("run.txt","w");

     FILE *stream = NULL;
     stream = fopen("fnames.txt","r");

     int num;
     char str[255];
     int i= 1;
     while(i<=623){
     	fscanf(stream,"%s",&str);
	    fprintf(f,"index2018.exe C:/Users/jiyeon/Desktop/ir2/ITnews/%s output%d.txt \n",str,i);
		i++; 
	}
}