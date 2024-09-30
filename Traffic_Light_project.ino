
#define green_1   4
#define yellow_1  5               
#define red_1     6
#define green_2   7
#define yellow_2  8
#define red_2     9
#define green_3   10
#define yellow_3  11
#define red_3     12
#define green_4   13
#define yellow_4  A1
#define red_4     A2
#define ledpin    A3
volatile int Change_mode_button = LOW;
volatile int transfer_button = LOW;


//int num_Traffic = 4 ; 

void setup() {
  pinMode(ledpin,   OUTPUT);
  pinMode(green_1,  OUTPUT);
  pinMode(green_2,  OUTPUT);
  pinMode(green_3,  OUTPUT); 
  pinMode(green_4,  OUTPUT);
  pinMode(yellow_1, OUTPUT);
  pinMode(yellow_2, OUTPUT); 
  pinMode(yellow_3, OUTPUT);
  pinMode(yellow_4, OUTPUT);
  pinMode(red_1,    OUTPUT);
  pinMode(red_2,    OUTPUT);
  pinMode(red_3,    OUTPUT);
  pinMode(red_4,    OUTPUT); 
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), ISR_Button_2, RISING);
  attachInterrupt(digitalPinToInterrupt(3), ISR_Button_3, RISING); 
  digitalWrite(red_1, HIGH); 
  digitalWrite(red_2, HIGH); 
  digitalWrite(red_3, HIGH); 
  digitalWrite(red_4, HIGH);
}
void ISR_Button_2() {
if(Change_mode_button == HIGH ){
    Change_mode_button = LOW;
  } 
  else {
    Change_mode_button = HIGH;
  }
  digitalWrite(ledpin,Change_mode_button );
}
void ISR_Button_3() {
  transfer_button = HIGH;
}
void flashing (int G){
  for(int i = 0 ; i<3 ; i++){
    digitalWrite(G, HIGH);
    delay(500);
    digitalWrite(G, LOW);
    delay(500);
  }
}
void Traffic_Light(int R, int Y, int G){
    transfer_button = LOW;  
    digitalWrite(R, LOW);
    digitalWrite(G, HIGH);
    delay(2000);
     if (Change_mode_button == 1) {
    while (transfer_button != 1);
  } else {
    delay(1000);
  }
   flashing(G);
     digitalWrite(Y, HIGH);
     delay(1000);
     digitalWrite(Y, LOW);
     digitalWrite(R, HIGH);
     delay(1000);
}
void loop() {
 
Traffic_Light(red_1, yellow_1, green_1);
Traffic_Light(red_2, yellow_2, green_2);
Traffic_Light(red_3, yellow_3, green_3);
Traffic_Light(red_4, yellow_4,green_4);





/*if(num_Traffic > 2){
  Traffic_Light(red_3, yellow_3, green_3);
}
if (num_Traffic > 3){
  Traffic_Light(red_4, yellow_4,green_4);
}
*/
}