

const byte segment_pins[8] = {9, 8, 7, 6, 5, 4, 3, 2};
const byte power_pins[4] = {10, 11, 12, 13};
const byte digit[10][8] = {
  {0, 0, 0, 0, 0, 0, 1, 1},
  {1, 0, 0, 1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0, 1, 0, 1},
  {0, 0, 0, 0, 1, 1, 0, 1},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {0, 1, 0, 0, 1, 0, 0, 1},
  {1, 1, 0, 0, 0, 0, 0, 1},
  {0, 0, 0, 1, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 0, 0, 1},
  {0, 0, 0, 1, 1, 0, 0, 1},
};
const byte scan[4][4] = {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
};

byte btn;
byte d[4];
unsigned long start_time, count;

void setup()
{
  pinMode(1,INPUT_PULLUP);
  
  for (byte i = 0; i < 8; i++) {
    pinMode(segment_pins[i], OUTPUT); 
  }
  for (byte i = 0; i < 4; i++) {
    pinMode(power_pins[i], OUTPUT);
  }
  start_time = millis() / 500;
}

void loop()
{
  count = millis() / 500 - start_time;
  set_decimal(count);
  for(byte k = 0; k < 4; k++){

    for(byte j = 0; j < 4; j++) {
      digitalWrite(power_pins[j],LOW);
    }    

    for(byte j = 0; j < 8; j++){
      digitalWrite(segment_pins[j], digit[d[k]][j]);
    }

    for(byte j = 0; j < 4; j++) {
      digitalWrite(power_pins[j], scan[k][j]);
    }
    if(k==2){
        digitalWrite(segment_pins[7], LOW);
    }   
    delay(4);
  }
}

void set_decimal(int count){ 
  btn=digitalRead(1);
  if(btn==LOW){
  d[0] = count%10; 
  d[1] = (count/10)%6; 
  d[2] = (count/100)%10; 
  d[3] = (count/1000)%6; 
  }
  else{
  d[0] = 9-count%10; 
  d[1] = 5-(count/10)%6; 
  d[2] = 9-(count/100)%10; 
  d[3] = 5-(count/1000)%6;  
  }
}  
    
    
    
    


