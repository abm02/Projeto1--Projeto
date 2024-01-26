/*********PROJETO 11 PIANO TILES 2.0 
ANA MORGADO  2020216657 
DIANA MACEDO 2020217658
*********/

// incluem bibliotecas TFT e SPI
#include <TFT.h>  
#include <SPI.h>
#include <SD.h>
#include<Wire.h>                //para comunicar entre os 2 arduinos

// definição de pino para Arduino UNO
#define cs1   10
#define cs2   7
#define cs3   4
#define dc1   9
#define dc2   6
#define dc3   3
#define rst1  8
#define rst2  5
#define rst3  2

int numenviado = 0; 

void Receber(int x){
  numenviado = Wire.read();
}

// crie uma instância da biblioteca
TFT screen1 = TFT(cs1, dc1, rst1);
TFT screen2 = TFT(cs2, dc2, rst2);
TFT screen3 = TFT(cs3, dc3, rst3);

// screen1
void tft_draw1(TFT& t, int constante){
  //limpe a tela com um fundo preto
  screen1.background(0, 0, 0);
  //defina o tamanho do texto
  screen1.setTextSize(2);
  //gerar uma cor bonita de texto
  screen1.stroke(250, 16, 200);
  
//1º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen1.text("   xx      ",15,constante+30);
  //print 2o retangulo no cimo da tela
  screen1.text("         xx",18,constante+20);
  //print 3o retangulo no cimo da tela  
  screen1.text("xx         ",15,constante+10);
  //print 4o retangulo no cimo da tela  
  screen1.text("      xx   ",15, constante);
  
//2º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen1.text("   xx      ",15,constante+30-40);
  //print 2o retangulo no cimo da tela
  screen1.text("         xx",18,constante+20-40);
  //print 3o retangulo no cimo da tela  
  screen1.text("xx         ",15,constante+10-40);
  //print 4o retangulo no cimo da tela  
  screen1.text("      xx   ",15, constante-40);

//3º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen1.text("   xx      ",15,constante+30-80);
  //print 2o retangulo no cimo da tela
  screen1.text("         xx",18,constante+20-80);
  //print 3o retangulo no cimo da tela  
  screen1.text("xx         ",15,constante+10-80);
  //print 4o retangulo no cimo da tela  
  screen1.text("      xx   ",15, constante-80);
//4º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen1.text("   xx      ",15,constante+30-120);
  //print 2o retangulo no cimo da tela
  screen1.text("         xx",18,constante+20-120);
  //print 3o retangulo no cimo da tela  
  screen1.text("xx         ",15,constante+10-120);
  //print 4o retangulo no cimo da tela  
  screen1.text("      xx   ",15, constante-120);

//5º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen1.text("   xx      ",15,constante+30-160);
  //print 2o retangulo no cimo da tela
  screen1.text("         xx",18,constante+20-160);
  //print 3o retangulo no cimo da tela  
  screen1.text("xx         ",15,constante+10-160);
  //print 4o retangulo no cimo da tela  
  screen1.text("      xx   ",15, constante-160);

//6º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen1.text("   xx      ",15,constante+30-200);
  //print 2o retangulo no cimo da tela
  screen1.text("         xx",18,constante+20-200);
  //print 3o retangulo no cimo da tela  
  screen1.text("xx         ",15,constante+10-200);
  //print 4o retangulo no cimo da tela  
  screen1.text("      xx   ",15, constante-200);

//7º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen1.text("   xx      ",15,constante+30-240);
  //print 2o retangulo no cimo da tela
  screen1.text("         xx",18,constante+20-240);
  //print 3o retangulo no cimo da tela  
  screen1.text("xx         ",15,constante+10-240);
  //print 4o retangulo no cimo da tela  
  screen1.text("      xx   ",15, constante-240);
}

// screen2
void tft_draw2(TFT& t, int constante){    
  //limpe a tela com um fundo preto
  screen2.background(0, 0, 0);
  //defina o tamanho do texto
  screen2.setTextSize(2);
  //gerar uma cor bonita de texto
  screen2.stroke(250, 16, 200);
//1º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen2.text("   xx      ",15,constante+30);
  //print 2o retangulo no cimo da tela
  screen2.text("         xx",18,constante+20);
  //print 3o retangulo no cimo da tela  
  screen2.text("xx         ",15,constante+10);
  //print 4o retangulo no cimo da tela  
  screen2.text("      xx   ",15, constante);
  
//2º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen2.text("   xx      ",15,constante+30-40);
  //print 2o retangulo no cimo da tela
  screen2.text("         xx",18,constante+20-40);
  //print 3o retangulo no cimo da tela  
  screen2.text("xx         ",15,constante+10-40);
  //print 4o retangulo no cimo da tela  
  screen2.text("      xx   ",15, constante-40);

//3º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen2.text("   xx      ",15,constante+30-80);
  //print 2o retangulo no cimo da tela
  screen2.text("         xx",18,constante+20-80);
  //print 3o retangulo no cimo da tela  
  screen2.text("xx         ",15,constante+10-80);
  //print 4o retangulo no cimo da tela  
  screen2.text("      xx   ",15, constante-80);
//4º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen2.text("   xx      ",15,constante+30-120);
  //print 2o retangulo no cimo da tela
  screen2.text("         xx",18,constante+20-120);
  //print 3o retangulo no cimo da tela  
  screen2.text("xx         ",15,constante+10-120);
  //print 4o retangulo no cimo da tela  
  screen2.text("      xx   ",15, constante-120);

//5º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen2.text("   xx      ",15,constante+30-160);
  //print 2o retangulo no cimo da tela
  screen2.text("         xx",18,constante+20-160);
  //print 3o retangulo no cimo da tela  
  screen2.text("xx         ",15,constante+10-160);
  //print 4o retangulo no cimo da tela  
  screen2.text("      xx   ",15, constante-160);

//6º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen2.text("   xx      ",15,constante+30-200);
  //print 2o retangulo no cimo da tela
  screen2.text("         xx",18,constante+20-200);
  //print 3o retangulo no cimo da tela  
  screen2.text("xx         ",15,constante+10-200);
  //print 4o retangulo no cimo da tela  
  screen2.text("      xx   ",15, constante-200);

//7º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen2.text("   xx      ",15,constante+30-240);
  //print 2o retangulo no cimo da tela
  screen2.text("         xx",18,constante+20-240);
  //print 3o retangulo no cimo da tela  
  screen2.text("xx         ",15,constante+10-240);
  //print 4o retangulo no cimo da tela  
  screen2.text("      xx   ",15, constante-240);
}

//screen3
void tft_draw3(TFT& t , int constante){
  //limpe a tela com um fundo preto
  screen3.background(0, 0, 0);
  //defina o tamanho do texto
  screen3.setTextSize(2);
  //gerar uma cor bonita de texto
  screen3.stroke(250, 16, 200);
  
//1º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen3.text("   xx      ",15,constante+30);
  //print 2o retangulo no cimo da tela
  screen3.text("         xx",18,constante+20);
  //print 3o retangulo no cimo da tela  
  screen3.text("xx         ",15,constante+10);
  //print 4o retangulo no cimo da tela  
  screen3.text("      xx   ",15, constante);
  
//2º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen3.text("   xx      ",15,constante+30-40);
  //print 2o retangulo no cimo da tela
  screen3.text("         xx",18,constante+20-40);
  //print 3o retangulo no cimo da tela  
  screen3.text("xx         ",15,constante+10-40);
  //print 4o retangulo no cimo da tela  
  screen3.text("      xx   ",15, constante-40);

//3º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen3.text("   xx      ",15,constante+30-80);
  //print 2o retangulo no cimo da tela
  screen3.text("         xx",18,constante+20-80);
  //print 3o retangulo no cimo da tela  
  screen3.text("xx         ",15,constante+10-80);
  //print 4o retangulo no cimo da tela  
  screen3.text("      xx   ",15, constante-80);
//4º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen3.text("   xx      ",15,constante+30-120);
  //print 2o retangulo no cimo da tela
  screen3.text("         xx",18,constante+20-120);
  //print 3o retangulo no cimo da tela  
  screen3.text("xx         ",15,constante+10-120);
  //print 4o retangulo no cimo da tela  
  screen3.text("      xx   ",15, constante-120);

//5º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen3.text("   xx      ",15,constante+30-160);
  //print 2o retangulo no cimo da tela
  screen3.text("         xx",18,constante+20-160);
  //print 3o retangulo no cimo da tela  
  screen3.text("xx         ",15,constante+10-160);
  //print 4o retangulo no cimo da tela  
  screen3.text("      xx   ",15, constante-160);

//6º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen3.text("   xx      ",15,constante+30-200);
  //print 2o retangulo no cimo da tela
  screen3.text("         xx",18,constante+20-200);
  //print 3o retangulo no cimo da tela  
  screen3.text("xx         ",15,constante+10-200);
  //print 4o retangulo no cimo da tela  
  screen3.text("      xx   ",15, constante-200);

//7º GRUPO DE 4 QUADRADOS 
  //print 1o retangulo no cimo da tela
  screen3.text("   xx      ",15,constante+30-240);
  //print 2o retangulo no cimo da tela
  screen3.text("         xx",18,constante+20-240);
  //print 3o retangulo no cimo da tela  
  screen3.text("xx         ",15,constante+10-240);
  //print 4o retangulo no cimo da tela  
  screen3.text("      xx   ",15, constante-240);
}

void setup() {
    screen1.begin();
    screen2.begin();
    screen3.begin();  

Serial.begin(9600);

    Wire.begin(1);
    Wire.onReceive(Receber);    //Quando o outro arduino enviar um novo valor, este recebe (iniciando a função Receber)
}

void loop() {
  int coordenada;
  numenviado = 0; 

  //Colocar os 3 ecrãs a preto
  screen1.background(0, 0, 0);
  screen2.background(0, 0, 0);
  screen3.background(0, 0, 0);
  
  if(numenviado==1){
    for (coordenada = 0; coordenada< 2000; coordenada=coordenada+5){
      tft_draw1(screen1, coordenada+300);
      tft_draw2(screen2, coordenada+300-128);
      tft_draw3(screen3, coordenada+300-256);
      if (numenviado==0){
        coordenada = 3000;    //para acabar o ciclo
      }
    }
  }  
}
