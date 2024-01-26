#include<CapacitiveSensor.h>    //para o sensor capacitivo
#include<SoftwareSerial.h>      //para comunicar entre o arduino e o módulo de wifi
#include<Wire.h>                //para comunicar entre os 2 arduinos

//Variáveis Globais 
  int buzzer = 11;
  
  int tecla_pressionada;
  unsigned int frequencia;
  unsigned int duracao;

  int tempo1=0;
  int tempo2=0;
  
  int numero_notas = 0;
  int teclas[] = {2, 4, 1, 3, 2, 4, 1, 3, 2, 4, 1, 3, 2, 4, 1, 3, 2, 4, 1, 3, 2, 4, 1, 3, 2, 4, 1, 3};
  int notas[30];
  int beats[30];
  int tempo = 1800;

 //MÚSICAS DE NATAL
  int numero_notas_jingle = 28;
  int notas_jingle[] = {659, 659, 659, 659, 659, 659, 659, 784, 523, 587, 659, 698, 698, 698, 698, 698, 659, 659, 659, 659, 659, 587, 587, 659, 587, 784, 587, 784};
    //E5=659   G5=784     C5=523     D5=587     F5=698    
  int beats_jingle[] = {8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 2, 8, 8, 8, 8, 8, 8, 8, 16, 16, 8, 8, 8, 8, 4, 4};


  int numero_notas_wish = 28;
  int notas_wish[] = {349, 392, 349, 330, 294, 294, 294, 392, 392, 440, 392, 349, 330, 330, 330, 440, 440, 494, 440, 392, 349, 294, 247, 247, 294, 392, 330, 349};
    //B3=247     F4=349     G4=392     E4=330     D4=294     A4=440     B4=494
  int beats_wish[] = {4, 4, 8, 8, 8, 8, 4, 4, 4, 4, 8, 8, 8, 8, 4, 4, 4, 4, 8, 8, 8, 8, 4, 4, 8, 8, 4, 4, 4, 2};

  int numero_notas_santa = 28;
  int notas_santa[] = {392, 330, 349, 392, 392, 392, 440, 494, 523, 523, 523, 330, 349, 392, 392, 392, 440, 392, 349, 349, 330, 392, 262, 330, 294, 349, 247, 262};
    //G4=392     E4=330     F4=349     A4=440     B4=494     C5=523     C4=262     D4=294     B3=247     
  int beats_santa[] = {8, 8, 8, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 4, 4, 4, 8, 8, 4, 2, 4, 4, 4, 4, 4, 2, 4, 1};
 //-------------------
 

  //Definir o PIN de envio e receção
    CapacitiveSensor   cs_2_3 = CapacitiveSensor(2,3);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin
    CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin
    CapacitiveSensor   cs_2_5 = CapacitiveSensor(2,5);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin
    CapacitiveSensor   cs_2_6 = CapacitiveSensor(2,6);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin
    
  //Para o envio do esp para o arduino 
    SoftwareSerial esparduino(8,9);   //Rx, Tx pin
    
void setup() {
  // turn off autocalibrate on channel 1
    cs_2_3.set_CS_AutocaL_Millis(0xFFFFFFFF);

  Serial.begin(9600);
  esparduino.begin(9600);
  Wire.begin();
}

void loop() {
//ENVIAR "0" PARA O OUTRO ARDUINO (para ele não correr o programa)
  Wire.beginTransmission(1);    //"liga-se" ao arduino #1
  Wire.write(0);
  Wire.endTransmission();
            
//REECEBER A MÚSICA ESCOLHIDA NA WEB 
  char valor_esp = esparduino.read();
  Serial.println(valor_esp);

  if ((valor_esp == '1') || (valor_esp == '2') || (valor_esp == '3')){
    //iniciar o display
      //ENVIAR "1" PARA O OUTRO ARDUINO (para ele iniciar as notas)
        Wire.beginTransmission(1);    //"liga-se" ao arduino #1
        Wire.write(1);
        Wire.endTransmission();
        delay(6000);                  //delay de 6 segundos para que as notas atinjam o fundo do ecrã
        tempo1 = millis();
  }
  if (valor_esp == '1'){
    // valor_esp = 1 JINGLE BELLS
      numero_notas = numero_notas_jingle;
 
      for (int i=0; i<numero_notas; i++){
        notas[i]=notas_jingle[i];
        beats[i]=beats_jingle[i];
      }
  }
  if (valor_esp == '2'){
    // valor_esp = 2 WE WISH YOU A MERRY CHRISTMAS
      numero_notas = numero_notas_santa;
 
      for (int i=0; i<numero_notas; i++){
        notas[i]=notas_wish[i];
        beats[i]=beats_wish[i];
      }
  }
  if (valor_esp == '3'){
    // valor_esp = 3 SANTA CLAUS IS COMING TO TOWN 
      numero_notas = numero_notas_santa;
 
      for (int i=0; i<numero_notas; i++){
        notas[i]=notas_santa[i];
        beats[i]=beats_santa[i];
      }
  }

//TOCAR A MÚSICA ESCOLHIDA  
     
    for (int i=0; i<numero_notas; i++){ 
      //Definir a sensibilidade dos sensores
        long total1 =  cs_2_3.capacitiveSensor(30);
        long total2 =  cs_2_4.capacitiveSensor(30);
        long total3 =  cs_2_5.capacitiveSensor(30);
        long total4 =  cs_2_6.capacitiveSensor(30);

      //Verificar qual foi a tecla pressionada 
        if (total1 > 150){
          tecla_pressionada = 1;
        }
        if (total2 > 150){
          tecla_pressionada = 2;
        }
        if (total3 > 150){
          tecla_pressionada = 3;
        }
        if (total4 > 150){
          tecla_pressionada = 4;
        }
      //Se nenhuma tecla for pressionada, espera até que seja pressionada
        if (total1<=150  &  total2<=150  &  total3<=150 & total4<=150){
          tecla_pressionada = 0;
        }

      //Verificar se já passou mais do que 0.5 segundos 
      //Verificar se a tecla que foi pressionada foi a correta
      //se sim, toca a nota
      //se não, toca 3 vezes um som de erro e volta para o inicio do programa
      tempo2 = millis();
      tempo2 = tempo2 - tempo1;
        if (tempo2 >= 2000){
           //ENVIAR "0" PARA O OUTRO ARDUINO (para ele para de correr o programa)
              Wire.beginTransmission(1);    //"liga-se" ao arduino #1
              Wire.write(0);
              Wire.endTransmission();
            tone(buzzer,262,300);
            delay(500);
            tone(buzzer,262,300);
            delay(500);
            tone(buzzer,262,300);
            delay(500);
            i=100;     //recomeça o jogo
        }
        if (tecla_pressionada == 0){
          noTone(buzzer);
          i=i-1;      //para que não avance na posição dos vetores
        }
        else if (tecla_pressionada == teclas[i]){
          frequencia = notas[i];
          duracao = beats[i]*tempo;
          tone(buzzer,frequencia, duracao);
          delay(250);
          tempo1 = millis();
        }
        else{
          //ENVIAR "0" PARA O OUTRO ARDUINO (para ele para de correr o programa)
            Wire.beginTransmission(1);    //"liga-se" ao arduino #1
            Wire.write(0);
            Wire.endTransmission();
          tone(buzzer,262,300);
          delay(500);
          tone(buzzer,262,300);
          delay(500);
          tone(buzzer,262,300);
          delay(500);
          i=100;     //recomeça o jogo
        }
    }
delay(10);      //delay arbitrário 
noTone(buzzer);

valor_esp = '0';     
numero_notas = 0;        //para que a música não reproduza 2 vezes seguidas
}
