#include <bai_2.h>


#include <def_877a.h>

#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use delay(clock=4000000)

#define SW0  RB0
#define SW1  RB2
#define SW2  RB4
#define SW3  RB5

#define COL5  RE0
#define COL6  RE1
#define COL7  RE2
#define COL8  RC0

#define LCD_RS_PIN PIN_A2
#define LCD_RW_PIN PIN_A3
#define LCD_ENABLE_PIN PIN_A5
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5
#define LCD_DATA6       PIN_D6
#define LCD_DATA7       PIN_D7

#include <lcd.c>

void chan_1();
int GetKey(void);
int READ_SWITCHES(void);
void hien_thi(int Key);
void chop_tat();
const unsigned int LED[17]= {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77, 0x7C, 0b00111001, 0b01011110, 0x79, 0x47,0xff};
void main()
{


    TRISD = 0x00;
    trisb=0xff;
  trisa=0x00;
    TRISC = 0x00;
    trise=0x00;
    PORTD = 0X00;

    //lcd_init();
    //lcd_putc("\fTestKey ");
    //lcd_gotoxy(1,2);
    //lcd_putc("KeyPad Control...");
    //delay_ms(1000);

   // lcd_gotoxy(0,1);
    //lcd_putc("\fENTER KEY");
    //lcd_gotoxy(1,2);
    //lcd_putc("        ");




 
    
     COL5=0;COL6=0;COL7=0;COL8=0;
    // BAT DIEN TRO KEO 
   OPTION_REG &= 0x7F;
      int pass_true[3]={1,2,3};
      int pass[3];       
      int key;
      int nhap=0;int time=0;
    while(TRUE)
    {
    
while(nhap < 3){

     key=2210;
    while(key == 2210){
        key = READ_SWITCHES();
              
    }
   hien_thi(key);
    pass[nhap] = key;
    nhap++;
//kt xem coi nha phim chua :key=2210 thi thoat 
    while(READ_SWITCHES() != 2210);
}
       
       


//kt xem co nhap dung pass khong 
     for (int kt =0;kt<3;kt++)
     {
     if (pass[kt]==pass_true[kt]) time++;
     }
     if (time==3){
     //nhay 5 l
     for (int sl=0;sl<5;sl++){
      chop_tat();
     }
     }
      time=0;
 //hien thi neu nhap dung      
      hien_thi(key);
 //xoa het sau 3 lan nhap      
      if (nhap==3) {
        nhap=0;
        pass[0]=0;
        pass[1]=0;
        pass[2]=0;
            
            }
        }

              
        }
        
    






    


int READ_SWITCHES(void)
{
    // Hàng 1
    COL5=1; COL6=0; COL7=0; COL8=0;

    if(SW0==0){ delay_ms(50); if(SW0==0) return 0; }
    if(SW1==0){ delay_ms(50); if(SW1==0) return 1; }
    if(SW2==0){ delay_ms(50); if(SW2==0) return 2; }
    if(SW3==0){ delay_ms(50); if(SW3==0) return 3; }

    // Hàng 2
    COL5=0; COL6=1; COL7=0; COL8=0;

    if(SW0==0){ delay_ms(50); if(SW0==0) return 4; }
    if(SW1==0){ delay_ms(50); if(SW1==0) return 5; }
    if(SW2==0){ delay_ms(50); if(SW2==0) return 6; }
    if(SW3==0){ delay_ms(50); if(SW3==0) return 7; }

    // Hàng 3
    COL5=0; COL6=0; COL7=1; COL8=0;

   if(SW0==0){ delay_ms(50); if(SW0==0) return 8; }
   if(SW1==0){ delay_ms(50); if(SW1==0) return 9; }
    if(SW2==0){ delay_ms(50); if(SW2==0) return 10; }
   if(SW3==0){ delay_ms(50); if(SW3==0) return 11; }

   //Hàng 4
     COL5=0; COL6=0; COL7=0; COL8=1;

  if(SW0==0){ delay_ms(50); if(SW0==0) return 12; }
   if(SW1==0){ delay_ms(50); if(SW1==0) return 13; }
   if(SW2==0){ delay_ms(50); if(SW2==0) return 14; }
  if(SW3==0){ delay_ms(50); if(SW3==0) return 15; }

    return 2210 ; 
}
void chan_1(){

                       portA=  0b00000010;
                      portC=  0x00;
                   portE=  0x00;
}

void hien_thi(int Key){

            
                
                     chan_1();
                     Portd= LED[Key];
                     delay_ms(100);
     
}
void chop_tat(){
chan_1();
                     Portd= 0xff;
                     delay_ms(100);
                     Portd= 0x00;
                     delay_ms(100);                     
                     
}
