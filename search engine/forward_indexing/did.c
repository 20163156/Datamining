/*

  빈도를 계산한 텍스트파일에 DID 를 부여하기 위한 코드
  앞에서 생성된 623 개의 텍스트 파일명 끝에 숫자가 부여되어 있는데 그걸 따와서 DID 값으로 한다. (ex->count1.txt 의 DID 는 1, count234.txt 의 DID 는 234) 2 차원배열을 freq,term 으로 2 개를 생성한 후 freq[DID][index]에는 빈도를 저장하고 term[DID][index]에는 색인어들을 저장한다.
  (ex->freq[20][50] 은 20 번문서의 51 번째 색인어에 대한 빈도)
  (ex->term[20][50] 은 20 번문서의 51 번째 색인어)


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int tp string
void *itoa2(int number, char *str, int radix)
{
   int digits = 0;
   int divider = 1;
   int index = 0;
   while( (number / divider) > 0){  
       digits++;
       divider *= radix;
   }
   divider /= radix;
   for(; digits > 0; digits--){
       *(str + index) = (number / divider) + '0';
       number -= ((number / divider) * divider);
       index++;
       divider /= radix;
   }
   *(str + index) = '\0'; 
}


int main(){

  int i;
  int freq[700][500];             //빈도를 저장하는 배열 
  char term[700][500];            //색인어를 저장하는 배열
  
  for(i = 1;i <= 623;++i){        //문서가 623개라고 가정 
      char s2[255];
      itoa(i,s2,10); 

      char s1[]="count";
      char s3[]=".txt";

      strcat(s1,s2);
      strcat(s1,s3);

      FILE *f = NULL;
      f = fopen(s1,"r+w");     //s1은 count1.txt~count623.txt이 되고
                               //이걸 623번(문서의 갯수) open한다.
      int index;
      index =0;                //각각의 문서당 색인어들의 갯수를 담는 변수


      while(index<500){
        int FREQ;
        char TERM;;
        fscanf(f,"%d%s",&FREQ,&TERM); //count1~623.txt 파일에서 빈도,색인어 읽기 
       
        freq[i][index] = FREQ; //빈도 저장
        term[i][index] = TERM; //색인어 저장 
        
        index++;
      }



      fseek(f,0,SEEK_SET); //커서를 파일의 맨앞으로 이동
      fprintf(f,"DID:%d\n",i); // count1~623.txt파일의 앞에 DID값 출력 
      fclose(f);

    } 
}