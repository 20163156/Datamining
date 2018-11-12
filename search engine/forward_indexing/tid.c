/*

각 색인어들을 1~n 까지 TID 를 출력하고 TID-DF 테이블 생성하기 위한 코드
TID-DF 테이블을 위해 배열을 하나만들고 index 로는 TID 값을 주고 value 는 df 값을 준다.


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *f;
	f = fopen("df.txt","r"); //문서빈도가 계산된 텍스트파일 열기 

	FILE *stream;
    stream = fopen("tid_term.txt","w");

	int i; //TID 변수
	i=1;
	int table[40000]; //TID-DF 배열 생성
	
	while(1){
	    int df;
		char term[255];
		
		fscanf(f,"%d %s",&df,&term); //df.txt에서 DF,색인어 입력받기

		if(!feof(f)){
			fprintf(stream,"TID:%d TERM:%s\n",i,term);
			//tid를 부여하고 tid와 색인어 출력 }
		}
		else{break;}

		i++;
		table[i] = df;		//tid,df table을 배열로 생성
	}
}