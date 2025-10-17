#define ledred 7
#define ledblue 5
#define ledgreen 6
#define pushButton 4
#define maximum 3

int btnclicado = 0;
int btnliberado = 0;
int ciclo = 0;
void trocarLed(){
  if(ciclo == maximum){
    ciclo = 0;
  }
                       
  if(ciclo == 0){

	digitalWrite(ledred, HIGH);
    digitalWrite(ledgreen, LOW);
    digitalWrite(ledblue, LOW);
  }
                       
  if(ciclo == 1){

	digitalWrite(ledred, LOW);
  	digitalWrite(ledgreen, HIGH);
    digitalWrite(ledblue, LOW);
  }
  if(ciclo == 2){
 
	digitalWrite(ledred, LOW);
    digitalWrite(ledgreen, LOW);
    digitalWrite(ledblue, HIGH);
  }
  ciclo ++;
}

void keyUp(){
  if((btnclicado == 1) and (btnliberado == 1)){
    btnclicado = 0;
    btnliberado = 0;
    trocarLed();
  }
  
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
  if(digitalRead(pushButton) == HIGH){
    btnclicado = 1;
    btnliberado = 0;
  }else{
    btnliberado = 1;
  }
  
  keyUp();
  
}
