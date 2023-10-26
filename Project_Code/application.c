/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"
 
uint_8 hours = 23 ,minutes = 56 , seconds =53;
uint_8 counter = 0;
int main() {
    
Std_ReturnType ret = E_NOT_OK;
application_initialize();
while(1){
    for(counter = 0; counter< 50 ; counter++){
  ret = gpio_port_write_logic(PORTD_INDEX, 0x3E);   
  ret = gpio_port_write_logic(PORTC_INDEX, (uint_8)(hours/10));
      _delay(5000);  
  ret = gpio_port_write_logic(PORTD_INDEX, 0x3D); 
  ret = gpio_port_write_logic(PORTC_INDEX, (uint_8)(hours%10));
       _delay(5000);  
  ret = gpio_port_write_logic(PORTD_INDEX, 0x3B); 
  ret = gpio_port_write_logic(PORTC_INDEX, (uint_8)(minutes/10));
       _delay(5000);  
  ret = gpio_port_write_logic(PORTD_INDEX, 0x37); 
  ret = gpio_port_write_logic(PORTC_INDEX, (uint_8)(minutes%10));
       _delay(5000);  
  ret = gpio_port_write_logic(PORTD_INDEX, 0x2F); 
  ret = gpio_port_write_logic(PORTC_INDEX, (uint_8)(seconds/10));
        _delay(5000);  
  ret = gpio_port_write_logic(PORTD_INDEX, 0x1F); 
  ret = gpio_port_write_logic(PORTC_INDEX, (uint_8)(seconds%10));
         _delay(5000);        
    } 
    seconds++;
    if(seconds == 60){
    minutes++;
    seconds =0;
    }
 if(minutes == 60){
    hours++;
    minutes =0;
    }
  if(hours == 24){
    hours=0;
    }  

}
  return (EXIT_SUCCESS);
}
void application_initialize(void){
    Std_ReturnType ret = E_NOT_OK;
ret = gpio_port_direction_intialize(PORTC_INDEX, 0xF0);
ret = gpio_port_direction_intialize(PORTD_INDEX, 0xC0);
}