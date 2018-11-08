/* 한글 코드 실습

 KS 완성형(KS X 1001) 한글 코드
 힌글 2350자를 출력

*/

#include <stdio.h>
int main() {
    int hcode;
	int i, j;
	for (i=0xB0; i <= 0xC8; i++) { 
		for (j=0xA1; j <= 0xFE; j++) {
			hcode = (i << 8) | j;
			printf("%c%c :0x%x(%d)\n",i,j,hcode,hcode);
		} 
	}
	return 0; 
}