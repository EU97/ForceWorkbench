#include"LoadCell.h"
#include "HX711.h"
#include <Arduino.h>



HX711 LOADCELL1; 
HX711 LOADCELL2; 
float force1  = 0; 
float force2  = 0;


void LoadCell1_ini(void)
    {
        Serial.println("Initializing LoadCell 1");
        LOADCELL1.begin(LOADCELL1_DOUT_PIN, LOADCELL1_SCK_PIN);
        delay(100);	
        LOADCELL1.set_scale(2280.f); // 2280.f for 1Kg loadcell                    
        LOADCELL1.tare();				    
        Serial.println("After setting up the scale:");
        Serial.print("read: \t\t");
        Serial.println(LOADCELL1.read());         
        Serial.print("read average: \t\t");
        Serial.println(LOADCELL1.read_average(20));      
        Serial.print("get value: \t\t");
        Serial.println(LOADCELL1.get_value(5));	
        Serial.print("get units: \t\t");
        Serial.println(LOADCELL1.get_units(5), 1); 
    }

float LoadCell1_data(void)
    {
        LOADCELL1.power_up(); 
        force1 = LOADCELL1.get_units(10);
        LOADCELL1.power_down();	
        return force1;		        
    }
