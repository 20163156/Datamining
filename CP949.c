/* 한글 코드 실습

  CP949의 8822자 출력

*/

#include <stdio.h>
int main() {
    int hcode,i,j;
	for (i=0x81; i <= 0xA0; i++) { 
		for (j=0x41; j <= 0x5A; j++) {
            hcode = (i << 8) | j;
			printf("%c%c :0x%x(%d)\n",i,j,hcode,hcode); 
		}
	}
	for (i=0x81; i <= 0xA0; i++) {
		for (j=0x61; j <= 0x7A; j++) {
			hcode = (i << 8) | j;
			printf("%c%c :0x%x(%d)\n",i,j,hcode,hcode);
		} 
	}

	for (i=0x81; i <= 0xA0; i++) { 
		for (j=0x81; j <= 0xFE; j++) {
        	hcode = (i << 8) | j;
			printf("%c%c :0x%x(%d)\n",i,j,hcode,hcode); 
		}
	}	

	for (i=0xA1; i <= 0xC5; i++) { 
		for (j=0x41; j <= 0x5A; j++) {
        	hcode = (i << 8) | j;
			printf("%c%c :0x%x(%d)\n",i,j,hcode,hcode); 
		}
	}

	for (i=0xA1; i <= 0xC5; i++) { 
		for (j=0x61; j <= 0x7A; j++) {
        	hcode = (i << 8) | j;
			printf("%c%c :0x%x(%d)\n",i,j,hcode,hcode); 
		}
	}

	for (i=0xA1; i <= 0xC5; i++) { 
		for (j=0x81; j <= 0xA0; j++) {
        	hcode = (i << 8) | j;
			printf("%c%c :0x%x(%d)\n",i,j,hcode,hcode); 
		}
	}
	for (i=0xC6; i <= 0xC6; i++) { 
		for (j=0x41; j <= 0x52; j++) {
        	hcode = (i << 8) | j;
			printf("%c%c :0x%x(%d)\n",i,j,hcode,hcode); 
		}
	}
	return 0; 
}