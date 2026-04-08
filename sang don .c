#include <bai_2.h>

#include <def_877a.h>
#use delay(clock=4000000)
#FUSES NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,
signed int i,j;
int kq,xoay;
void main()
{
//set port a,d,c,e=output 
trisa=0x00;
trisd=0x00;
trise=0x00;
trisc=0x00;
//set RA1 (cot 1)
porta=0b00000010;
porte=0b00000000;
portc=0b00000000;
   while(TRUE)
   {
   kq=0b00000000;
     
      for (i=8;i>=1;i--){
      xoay=0b00000001;
      //or xoay voi kq 
      portd=xoay|kq;
      delay_ms(200);
      for (j=1;j<i;j++){
      xoay=xoay<<1;
      portd=kq|xoay;
      delay_ms(200);
      }
      kq=portd;
      }


   }
   }
