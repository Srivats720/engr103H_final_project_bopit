#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>

const int switchPin = 7;
const int leftButtonPin = 4;
const int rightButtonPin = 5;
const int ledPin = 13;

//The 5 recent scores will be stored. The most recent value will be taken from the array and shown as highscore
int player_1_highscore[5] = {};
int player_2_highscore[5] = {};

int playerscore = 0;

float speed = 5000; //will be mapped to the player score. Start from 5 seconds

bool gamestart = false;
bool player1 = true;
bool player2 = false;

volatile bool button1Flag = false;
volatile bool button2Flag = false;
volatile bool accelFlag = false;
volatile bool switchState = HIGH; // HIGH means switch off due to INPUT_PULLUP

void setup() {
  
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(leftButtonPin, INPUT_PULLDOWN);
  pinMode(rightButtonPin, INPUT_PULLDOWN);

  CircuitPlayground.begin();
  Serial.begin(9600);
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);

  attachInterrupt(digitalPinToInterrupt(button1Flag), button1ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(button2Flag), button2ISR, RISING);

}

void loop() {
  main();
}

int main(){

  Serial.println("Current Player: ");
  if(player1){
    Serial.println("Player 1");
  }
  else if(player2){
    Serial.println("Player 2");
  }
  Serial.println("Use the switch to decide who will be playing");

  playerChange();

  Serial.println("Press both buttons to start game:");
}

//function containing the bopIt functionality 
void bopIt(){
  
  for(int i = 0; i < 10; i++){
    CircuitPlayground.setPixelColor(i, 255, 141, 161);
    delay(speed);
    CircuitPlayground.clearPixels();
  }
  
}

//function containing the twistIt functionality
void twistIt(){

}

//function containing pullIt functionality
void pullIt(){

}

//controls player switch
void playerChange(){
  bool state = digitalRead(switchPin);

  if (state == HIGH) {
    player1 = true;
    player2 = false;
    Serial.println("Player 1");
    delay(2000);
  } else {
    player1 = false;
    player2 = true;
    Serial.println("Player 2");
    delay(2000);
  }
  delay(50);  // Small debounce delay
}

void gameStart(){
  if(button1Flag && button2Flag){
    gamestart = true;
    button1Flag = false;
    button2Flag = false;
  }
  
}

// //function containing game restart functionality
void restart(){
  gamestart = false;
  playerscore = 0;
}

void button1ISR(){
  if(button1Flag){
    button1Flag = false;
  }
  else{
    button1Flag = true;
  }
}

void button2ISR(){
  if(button2Flag){
    button2Flag = false;
  }
  else{
    button2Flag = true;
  }
}

