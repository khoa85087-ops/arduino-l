#include <ngay_2.h>

#include <def_877a.h>
#use delay(clock=4000000)
#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP,
const unsigned int LED[10]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void chan_1();
void chan_2();
void hien_thi(int i,int l);
void main()
{
 
//dn output 
 trisd=0x00; 
 trise=0x00;
 trisc=0x00;
 trisa=0x00;
 //gan gia tri 
portd=0x00;
 while(true)
 { 

    for (int l=0;l<=9;l++){
      for (int i=0;i<=9;i++){
          hien_thi(i,l);
            }
         }

  
       }
     
   
       
 }

void chan_1(){

                       portA=  0b00000010;
                      portC=  0x00;
                   portE=  0x00;
}
void chan_2(){

                       portA=  0b00000100;
                      portC=  0x00;
                   portE=  0x00;
}

void hien_thi(int i,int l){
int time ;//1s=50*20*10^-3
           
          for (time =0;time<50;time++){      
                     chan_1();
                     Portd= LED[i];
                     delay_ms(10);
                     
                     chan_2();
                     portd=LED[l];
                     delay_ms(10);
                     
              
          }     
               
          
}
