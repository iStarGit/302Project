#include <stdio.h>

int out = 0;
//Motors
const int MLP1 = 3; // 1 to 3
const int MLP2 = 5; // 2 to 5
const int MRP3 = 9; // 3 to 9
const int MRP4 = 10; // 4 to 10

//Photoresistors 
const int PhotoWhiteL = A0; // Col J 
const int PhotoBlack = A1; //Col D
const int PhotoWhiteR = A2; // Col A

// IR Sensors
const int IRFront = 11; //Col 
const int IRLeft = 12;
const int IRRight = 13;

//Left - White: 280 - 285, Black: 260 - 265 
//Middle - White: 370 - 375, Black: 300-305
//Right - White: 345-353, Black: 305- 315

// Left Photosensor Range 
int lWhiteLow = 280;
int lWhiteHigh = 285;

int lBlackLow = 260;
int lBlackHigh = 265;

// Middle Photosensor Range 
int mWhiteLow = 370;
int mWhiteHigh = 375;

int mBlackLow = 300;
int mBlackHigh = 305;

// Right Photosensor Range 
int rWhiteLow = 345;
int rWhiteHigh = 353;

int rBlackLow = 305;
int rBlackHigh = 315; 

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  //MOTORS
  pinMode(MLP1, OUTPUT);
  pinMode(MLP2, OUTPUT);
  pinMode(MRP3, OUTPUT);
  pinMode(MRP4, OUTPUT);


  //IR Sensors
  pinMode(IRLeft, INPUT);
  pinMode(IRFront, INPUT);
  pinMode(IRRight, INPUT);
}

void loop() {
  int rWhite = analogRead(A0);
  int black = analogRead(A1);
  int lWhite = analogRead(A2);

  int leftIR = digitalRead(IRLeft);
  int rightIR = digitalRead(IRRight);
  int frontIR = digitalRead(IRFront);

  //PhotoResistors


  char buffer[400]; 
  Serial.println("\nPhotoresistors");
  out = sprintf(buffer, "leftWhite: %d, middleBlack: %d, rightWhite: %d", lWhite, black, rWhite);
  for(int k = 0; k <= out; k++)
  {
    Serial.print(buffer[k]);
  }

  Serial.println("\nIRSensor");
  out = sprintf(buffer, "Left: %d, Front: %d, Right: %d", leftIR, frontIR, rightIR);
  for(int l = 0; l <= out; l++)
  {
    Serial.print(buffer[l]);
  }

/*
  digitalWrite(MLP1, HIGH);
  digitalWrite(MLP2, LOW);
  digitalWrite(MRP3, HIGH);
  digitalWrite(MRP4, LOW);
 */
  /*
  Serial.println("leftWhite: ");
  Serial.println(lWhite);
  

  Serial.println("middleBlack: ");
  Serial.println(black);
  

  Serial.println("rightWhite: ");
  Serial.println(rWhite);
*/

  //Checking to see if it on the black tape, if it is, then drive straight) 
  /*
  if( ((lWhite > lWhiteLow) && (lWhite < lWhiteHigh)) && ((rWhite > rWhiteLow) && (rWhite < rWhiteHigh)) && ((black > mBlackLow) && (black < mBlackHigh)))
  {
    analogWrite(MLP1, 150);
    digitalWrite(MLP2, LOW);
    //analogWrite(MLP2, motorValue);
    analogWrite(MRP3, 150);
    //analogWrite(MRP4, motorValue);
    digitalWrite(MRP4, LOW);  
    delay(30);  
  }
  
*/
  if(frontIR == 1)
  {
    digitalWrite(MLP1, LOW);
    digitalWrite(MLP2, LOW);
    digitalWrite(MRP3, LOW);
    digitalWrite(MRP4, LOW);
    delay(500);
  }

  
    analogWrite(MLP1, 75);
    digitalWrite(MLP2, LOW);
   //analogWrite(MLP2, motorValue);
    analogWrite(MRP3, 75);
    //analogWrite(MRP4, motorValue);
    digitalWrite(MRP4, LOW);  
    delay(500);  
    
/*
  else if((lWhite > black) && (rWhite > black) && ((black < lWhite) && (black < rWhite)))
  {
    analogWrite(MLP1, 175);
    digitalWrite(MLP2, LOW);
    //analogWrite(MLP2, motorValue);
    analogWrite(MRP3, 175);
    //analogWrite(MRP4, motorValue);
    digitalWrite(MRP4, LOW);  
    delay(500);  
  }
  */
/*
  else if( ((lWhite < black) && (lWhite < rWhite)))
  {
    analogWrite(MLP2, 175);
    digitalWrite(MLP1, LOW);
    //analogWrite(MLP2, motorValue);
    analogWrite(MRP3, 175);
    //analogWrite(MRP4, motorValue);
    digitalWrite(MRP4, LOW);  
    delay(500);  
  }

 
  else if( ((rWhite < black) && (rWhite < lWhite)))
  {
    analogWrite(MLP1, 175);
    digitalWrite(MLP2, LOW);
    //analogWrite(MLP2, motorValue);
    analogWrite(MRP4, 175);
    //analogWrite(MRP4, motorValue);
    digitalWrite(MRP3, LOW);  
    delay(500);  
  }
*/
 

  delay(500);

/*
   digitalWrite(MLP1, HIGH);
   digitalWrite(MLP2, LOW);
    
    
   digitalWrite(MRP3, HIGH);
   digitalWrite(MRP4, LOW); 
*/
   /*
    analogWrite(MLP1, 150);
    digitalWrite(MLP2, LOW);
    //analogWrite(MLP2, motorValue);
    analogWrite(MRP3, 150);
    //analogWrite(MRP4, motorValue);
    digitalWrite(MRP4, LOW);  
    delay(30);  
    */
  /*
  for(int motorValue = 255; motorValue > 0; motorValue -=15)
  {
    analogWrite(MLP1, 150);
    digitalWrite(MLP2, LOW);
    //analogWrite(MLP2, motorValue);
    analogWrite(MRP3, 150);
    //analogWrite(MRP4, motorValue);
    digitalWrite(MRP4, LOW);  
    delay(30);  
  }
*/

 

  

}
