/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  oh SAY CAN YOU SEE
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */

// Pin 2-8 is connected  to the 7 segments of the display.
int bbbtn = 1;
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
//including the wire.h library into the code
#include <Wire.h>

int a = 0;

int pinG = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;
int btn = 13;

// the setup routine  runs once when you press reset:
void setup() {
  // initialize  the digital pins as outputs.
  Serial.begin(9600);
  /*Wire.begin(0x55);
  Wire.onReceive(receiveEvent);*/
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
}
/*void receiveEvent(int bytes) {
  while(Wire.available()){
    a = Wire.read();    // read one character from the I2C
  }
}*/
/*
1 is up, 2 is down, 3 is left, 4 is right
*/

int geometric(int x, int y, int z, int f) {
  return x * y * z * f;
}

int arithmetic(int x, int y, int z, int f) {
  return x + y + z + f;
}

int direction(int x, int y) {
  if (y < 100) {
    return 1;
  } else if (y > 600) {
    return 2;
  } else if (x < 100) {
    return 3;
  } else if (x > 600) {
    return 4;
  }
  return 0;
}

//void turn all off

void print_state(int i) {
  if (i % 2 == 0) {
    pinMode(D1, HIGH);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    pinMode(D4, LOW);
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  } else if (i % 2 == 1) {
    pinMode(D4, HIGH);
    pinMode(D1, LOW);
    pinMode(D2, LOW);
    pinMode(D3, LOW);
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
  }
}

int dig = 1;

int fstd = 0;
int secd = 0;
int thd = 0;
int fth = 0;

void print_num(int i, int num) {
  for (int i = 9; i <= 12; i++) {
    digitalWrite(i, HIGH);
  }
  digitalWrite(i + 8, LOW);
  if (num == 0) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, LOW);
  } else if (num == 1) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  } else if (num == 2) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, LOW);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
  } else if (num == 3) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, HIGH);
  } else if (num == 4) {
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  } else if (num == 5) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  } else if (num == 6) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  } else if (num == 7) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, LOW);
    digitalWrite(pinG, LOW);
  } else if (num == 8) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, HIGH);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  } else if (num == 9) {
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, HIGH);
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, HIGH);
    digitalWrite(pinE, LOW);
    digitalWrite(pinF, HIGH);
    digitalWrite(pinG, HIGH);
  }
}

int state = 0;
int prevstate = 0;
int prev_state = 0;
int info=0;
// the loop routine runs over  and over again forever:
void loop() {
  while(true){
    int x = analogRead(A1);
    int y = analogRead(A2);
    if(Serial.available()>0){
      info = Serial.read();
      Serial.println(info, DEC);
    }
    //Wire.onReceive(receiveEvent);
    prevstate = direction(x, y);
    if (direction(x, y) == 3) {
      state++;
      print_state(state);
    } else if (direction(x, y) == 4) {
      state--;
      if (state <= 0) {
        state = 0;
      }
      //Serial.println("Pressed");
      print_state(state);
    }
    //Serial.println(a);
    if (info == 49) {
      while(info!=48){
        dig = 0;
        if(Serial.available()){
          info = Serial.read();
        }
      }
      //Serial.println("reached");
      x = analogRead(A1);
      y = analogRead(A2);
      break;
    }
  }
  info = 0;
  bool end = false;
  while(true){
    if(Serial.available()){
      info = Serial.read();
    }
    Serial.print("info is ");
    int x =analogRead(A1);
    int y =analogRead(A2);
    while (direction(x, y) == 0) {
      x = analogRead(A1);
      y = analogRead(A2);
      prev_state = 0;
      print_num(D1, fstd);
      print_num(D2, secd);
      print_num(D3, thd);
      print_num(D4, fth);
      if(Serial.available()){
        info = Serial.read();
      }
      if(info == 49){
        end = true;
        break;

      }
    }
    while (true) {
      if(Serial.available()){
        info = Serial.read();
      }

      if (direction(x, y) == 0 && prev_state != 0) {
        prev_state = 0;
      }
      x = analogRead(A1);
      y = analogRead(A2);
      print_num(1, fstd);
      print_num(2, secd);
      print_num(3, thd);
      print_num(4, fth);
      if (direction(x, y) == 3 && prev_state != 3) {
        prev_state = 3;
        dig++;
        if (dig > 4) {
          dig = 1;
        }
        print_num(1, fstd);
        print_num(2, secd);
        print_num(3, thd);
        print_num(4, fth);
      }
      if (direction(x, y) == 4 && prev_state != 4) {
        dig--;
        prev_state = 4;
        if (dig < 1) {
          dig = 4;
        }
        print_num(1, fstd);
        print_num(2, secd);
        print_num(3, thd);
        print_num(4, fth);
      }
      if (direction(x, y) == 1 && prev_state != 1) {
        prev_state = 1;
        if (dig == 1) {
          fstd++;
          if (fstd > 9) {
            fstd = 0;
          } else if (fstd < 0) {
            fstd = 9;
          }
          print_num(1, fstd);
          print_num(2, secd);
          print_num(3, thd);
          print_num(4, fth);
          Serial.println("number is");
          Serial.print(fstd);
          Serial.print(secd);
          Serial.print(thd);
          Serial.println(fth);
        } 
        else if (dig == 2) {
          secd++;
          prev_state = 2;
          if (secd > 9) {
            secd = 0;
          } else if (secd < 0) {
            secd = 9;
          }
          print_num(1, fstd);
          print_num(2, secd);
          print_num(3, thd);
          print_num(4, fth);
          Serial.println("number is");
          Serial.print(fstd);
          Serial.print(secd);
          Serial.print(thd);
          Serial.println(fth);
        } 
        else if (dig == 3) {
          thd++;
          if (thd > 9) {
            thd = 0;
          } else if (thd < 0) {
            thd = 9;
          }
          print_num(1, fstd);
          print_num(2, secd);
          print_num(3, thd);
          print_num(4, fth);
          Serial.println("number is");
          Serial.print(fstd);
          Serial.print(secd);
          Serial.print(thd);
          Serial.println(fth);
        } 
        else if (dig == 4) {
          fth++;
          if (fth > 9) {
            fth = 0;
          } else if (fth < 0) {
            fth = 9;
          }
          Serial.println("number is");
          Serial.print(fstd);
          Serial.print(secd);
          Serial.print(thd);
          Serial.println(fth);
        }
        if(info == 49){
          end = true;
          break;
        }
        Serial.println("number is");
        Serial.print(fstd);
        Serial.print(secd);
        Serial.print(thd);
        Serial.println(fth);
      }
        /*while (true) {
          x = analogRead(A1);
          y = analogRead(A2);
          print_num(1, fstd);
          print_num(2, secd);
          print_num(3, thd);
          print_num(4, fth);
          Serial.println("number is");
          Serial.print(fstd);
          Serial.print(secd);
          Serial.print(thd);
          Serial.println(fth);
        }*/
      if(info==49){
        end = true;
        break;
      }
      if(end == true){
        break;
      }
    }


    while(true){
      if(state%2==0){
        int alpha = fstd*secd*thd*fth;
        Serial.print("geo mean is:");
        Serial.println(alpha);
        int first = alpha%10;
        int second = ((alpha%100)-first)/10;
        int third = ((alpha%1000)-first-(10*second))/100;
        int fourth = ((alpha%10000)-first - (10*second) - (100*third))/1000;
        print_num(1,first);
        print_num(2,second);
        print_num(3,third);
        print_num(4,fourth);
        delay(100000);
      }
      else{
        int alpha = fstd+secd+thd+fth;
        Serial.print("arithmetic mean is:");
        Serial.println(alpha);
        int first = alpha%10;
        int second = ((alpha%100)-first)/10;
        int third = ((alpha%1000)-first-(10*second))/100;
        int fourth = ((alpha%10000)-first - (10*second) - (100*third))/1000;
        print_num(1,first);
        print_num(2,second);
        print_num(3,third);
        print_num(4,fourth);
        delay(10000);
      }
    }
  }
}

  /*digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW); 
  //0
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);*/
  /*digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3,  LOW);
  digitalWrite(D4, LOW); */
  //1
  /*digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD,  HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);   
  delay(1);               // wait for a second
  
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3,  HIGH);
  digitalWrite(D4, LOW); 
  //2
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD,  HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);     
  delay(1);               // wait for a second

  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, HIGH); 
  //3
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);     
  delay(1);               // wait for a second
  */
  /*  
  //4
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC,  LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second
  
  //5
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD,  LOW);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second
  
  //6
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE,  LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second
  
  //7
  digitalWrite(pinA,  LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD,  HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);     
  delay(1000);               // wait for a second
  
  //8
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE,  LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second

  //9
  digitalWrite(pinA,  LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD,  HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);     
  delay(1000);               // wait for a second
  */
