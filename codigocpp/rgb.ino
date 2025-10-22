#define ledred 7
#define ledblue 5
#define ledgreen 6
#define pushButton 4
#define maximum 3

unsigned char btnclicado = 0;
unsigned char ciclo = 0;

void trocarLed(){
  if (ciclo == maximum){
    ciclo = 0;
  }

  digitalWrite(ledred, LOW);
  digitalWrite(ledgreen, LOW);
  digitalWrite(ledblue, LOW);

  if (ciclo == 0){
	  digitalWrite(ledred, HIGH);
  }else if(ciclo == 1){
  	digitalWrite(ledgreen, HIGH);
  }else if(ciclo == 2){
    digitalWrite(ledblue, HIGH);
  }

  ciclo++;
}

void keyUp(){
  trocarLed();
  btnclicado = 0;
  
}

void setup()
{
  pinMode(ledred, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(ledblue, OUTPUT);
  pinMode(pushButton, INPUT);
}

void loop()
{

  if (digitalRead(pushButton) == HIGH){
    btnclicado = 1;
  }else if ( btnclicado ){
    keyUp(); 
  }
  
}
