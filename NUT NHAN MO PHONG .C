#include <maTRix_button.h>

//#include <16f877a.h>
#include <def_877a.h>

#FUSES NOWDT, HS, NOPUT, NOPROTECT, NODEBUG, NOBROWNOUT, NOLVP, NOCPD, NOWRT
#use delay(clock=4000000)

#define SW0  RB0
#define SW1  RB2
#define SW2  RB4
#define SW3  RB5

#define COL1  RA1
#define COL2  RA2
#define COL3  RA3
#define COL4  RA5

#define LCD_RS_PIN PIN_A2
#define LCD_RW_PIN PIN_A3
//cho nay can xem lai :sach la pin a5 
#define LCD_ENABLE_PIN PIN_A0
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5
#define LCD_DATA6       PIN_D6
#define LCD_DATA7       PIN_D7

#include <lcd.c>


char GetKey(void);
char READ_SWITCHES(void);
void main()
{

    TRISD = 0x00;
    PORTD = 0X00;
    TRISC = 0x00;

    lcd_init();
    lcd_putc("\fTestKey ");
    lcd_gotoxy(1,2);
    lcd_putc("KeyPad Control...");
    delay_ms(1000);

    lcd_gotoxy(0,1);
    lcd_putc("\fENTER KEY");
    lcd_gotoxy(1,2);
    lcd_putc("        ");

    char Key = 'n';
      RB0=0; RB2=0; RB4=0; RB5=0;
    RA1=0; RA2=0; RA3=0; RA5=0; // Reset keypad
//DN B0,B2,B4,B5 =INPUT 
  trisb=0xff;
  trisa=0x00;
    //TRISB0=1; TRISB2=1; TRISB4=1; TRISB5=1;
    //A1,A2,A3,A5=OUTPUT 
    //TRISA1=0; TRISA2=0; TRISA3=0; TRISA5=0;


    // BAT DIEN TRO KEO 
   OPTION_REG &= 0x7F;

    while(TRUE)
    {
        
        Key = GetKey();
        lcd_gotoxy(1,2);
        lcd_putc(Key);
    }
}


char GetKey(void)
{
    char key = 'n';

    while(key=='n')
    {
        key = READ_SWITCHES();  // Quét ma tr?n
    }

    return key; // Tr? v? giá tr? sau khi quét
}

char READ_SWITCHES(void)
{
    // Hàng 1
    COL1=1; COL2=0; COL3=0; COL4=0;

    if(SW0==0){ delay_ms(50); if(SW0==0) return '0'; }
    if(SW1==0){ delay_ms(50); if(SW1==0) return '1'; }
    if(SW2==0){ delay_ms(50); if(SW2==0) return '2'; }
    if(SW3==0){ delay_ms(50); if(SW3==0) return '3'; }

    // Hàng 2
    COL1=0; COL2=1; COL3=0; COL4=0;

    if(SW0==0){ delay_ms(50); if(SW0==0) return '4'; }
    if(SW1==0){ delay_ms(50); if(SW1==0) return '5'; }
    if(SW2==0){ delay_ms(50); if(SW2==0) return '6'; }
    if(SW3==0){ delay_ms(50); if(SW3==0) return '7'; }

    // Hàng 3
    COL1=0; COL2=0; COL3=1; COL4=0;

   if(SW0==0){ delay_ms(50); if(SW0==0) return '8'; }
   if(SW1==0){ delay_ms(50); if(SW1==0) return '9'; }
    if(SW2==0){ delay_ms(50); if(SW2==0) return 'A'; }
   if(SW3==0){ delay_ms(50); if(SW3==0) return 'B'; }

   //Hàng 4
     COL1=0; COL2=0; COL3=0; COL4=1;

   if(SW0==0){ delay_ms(50); if(SW0==0) return 'C'; }
   if(SW1==0){ delay_ms(50); if(SW1==0) return 'D'; }
    if(SW2==0){ delay_ms(50); if(SW2==0) return 'E'; }
   if(SW3==0){ delay_ms(50); if(SW3==0) return 'F'; }

    return 'n'; // Không có nút nào ðý?c nh?n
}
