/* 한글 코드 실습

   임의의 유니코드 값에 대한 한글 코드값(10진수 또는 16진수)과
   <초성, 중성, 종성>값을 출력

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_one_syllable(){ 
	srand(time(NULL));
	return rand() % 11172 + 0xAC00;
}

int main() {
	int code,cho,jung,jong; 
	code = get_one_syllable();
	cho = ((code - 0xAC00) / 28) / 21; 
	jung = ((code - 0xAC00) / 28) % 21; 
	jong = (code - 0xAC00) % 28;
	printf("(%d,%d,%d)",cho,jung,jong); 
}