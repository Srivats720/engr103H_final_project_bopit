#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>

const int switchPin = 7;
const int leftButtonPin = 4;
const int rightButtonPin = 5;
const int ledPin = 13;

//The 5 recent scores will be stored. The most recent value will be taken from the array and shown as highscore
int player_1_highscore[5] ={};
int player_2_highscore[5]={};

int playscore_1 = 0;
int playscore_2 = 0;

float speed = 10; //speed of the game. incremented as score increases

bool gameStart = false;
bool player1 = true;
bool player2 = false;

volatile bool button1Flag = false;
volatile bool button2Flag = false;
volatile bool switchState = HIGH; // HIGH means switch off due to INPUT_PULLUP

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(leftButtonPin, INPUT_PULLDOWN);
  pinMode(rightButtonPin, INPUT_PULLDOWN);

  CircuitPlayground.begin();
  Serial.begin(9600);
  CircuitPlayground.setAccelRange(LIS3DH_RANGE_8_G);

}

void loop() {
  playerChange();

}

//main function that has the functionality of the whole game
void main(){

}

//function containing the bopIt functionality 
void bopIt(){
  
  for(int i = 0; i < 10; i++){
    CircuitPlayground.setPixelColor(i, 255, 141, 161);
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
    switchFlag = false;
    player1 = true;
    player2 = false;
    Serial.println("Player 1");
    delay(2000);
  } else {
    switchFlag = true;
    player1 = false;
    player2 = true;
    Serial.println("Player 2");
    delay(2000);
  }
  delay(50);  // Small debounce delay
}

// //function containing game restart functionality
void restart(){
  gameStart = false;
  playerScore = 0;
}


