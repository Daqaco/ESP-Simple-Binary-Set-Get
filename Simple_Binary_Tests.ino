uint8_t Check_Bit_Int(uint8_t var, uint8_t pos){
     if((var & (1<<pos)))
          return 1;
     else
          return 0;
}

void Set_Bit_Int(uint8_t *var, uint8_t setbit, bool setval){
     uint8_t temp_var = *var;
     if(setval)     // Set to True
          temp_var |= 1<<setbit;
     else
          temp_var &= ~(1<<setbit);     
     *var = temp_var;
}

void setup() {

     Serial.begin(115200);
     while(!Serial);
     Serial.println("Serial Started");

}

void loop() {

     uint8_t testvar1;

     for(int outerloop = 0; outerloop < 8; outerloop++){

          Set_Bit_Int(&testvar1, outerloop, true);
          
          Serial.print("Testing Binary Value: ");
          Serial.println(testvar1, BIN);
          Serial.println();
     
          //Check_Bit works from right to left
          for(int loop = 0; loop < 8; loop++){
               Serial.printf("Testing bit %d equals: ", loop);
               Serial.println(Check_Bit_Int(testvar1, loop));
          }
          Serial.print("\n\n");
          delay(5000);
     }
}
