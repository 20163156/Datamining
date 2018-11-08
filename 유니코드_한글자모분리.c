/* 한글 코드 실습

   임의의 유니코드 음절을 자모를 분리하여 출력
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
	FILE *fp;

	code = get_one_syllable();

	cho = ((code - 0xAC00) / 28) / 21; 
	jung = ((code - 0xAC00) / 28) % 21; 
	jong = (code - 0xAC00) % 28;

	cho += 0x1100; 
	jung += 0x1161; 
	jong += 0x11A8-1;
	fp = fopen("output.txt","w"); 

	//BOM
	putc(0xFE, fp);
	putc(0xFF, fp);

	putc((cho >> 8) & 0xff, fp);
	putc(cho & 0xff, fp); 

	putc((jung >> 8) & 0xff, fp);
	putc(jung & 0xff, fp); 

	putc((jong >> 8) & 0xff, fp);
    putc(jong & 0xff, fp);

    fclose(fp);
	
	return 0; 
}	