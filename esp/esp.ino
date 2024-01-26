//http://arduino.esp8266.com/stable/package_esp8266com_index.json
//CÓDIGO 03 - WEB SERVER E ENVIA PARA O ARDUINO A MÚSICA SELECIONADA

#include <ESP8266WiFi.h>
#include<SoftwareSerial.h>        //biblioteca para enviar para o Arduino
  SoftwareSerial esparduino(3,1);

//Credênciais do Wi-Fi
const char* ssid = "Ana Beatriz Morgado";
const char* password = "beatriz2002";

WiFiServer server(80);

//Variáveis globais
String header;      // Variável para armazenar o HTTP request
int numerodamusica = 0;     //numerodamusica = 0 == recomeçar
  
//Variáveis auxiliares que indicam o estado dos botões
  String output5State = "inicio";
  String output4State = "inicio";
  String output14State = "inicio";

//DECLARAÇÃO DAS VARIÁVEIS RELATIVAS AO TEMPO
// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  esparduino.begin(9600);
  Serial.begin(115200);

  // Conectar ao Wi-Fi
  Serial.print("A tentar conectar a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();

}

void loop() { 
//VERIFICA SE ALGUÉM ESTÁ CONECTADO À PÁGINA WEB OU SE ALGUÉM SE DESCONECTOU
  WiFiClient client = server.available();   // Vê se alguém se ligou ao servidor

  if (client) {                             // If a new client connects,
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
//--------------------------------------------------------------  
//VERIFICA SE ALGUM BOTÃO FOI PRESSIONADO
            if (header.indexOf("GET /5/on") >= 0) {
              numerodamusica = 1;
              output5State = "selecionada";
            } else if (header.indexOf("GET /5/off") >= 0) {
              numerodamusica = 1;
              output5State = "inicio";
            } else if (header.indexOf("GET /4/on") >= 0) {
              numerodamusica = 2;
              output4State = "selecionada";
            } else if (header.indexOf("GET /4/off") >= 0) {
              numerodamusica = 2;
              output4State = "inicio";
            } else if (header.indexOf("GET /14/on") >= 0) {
              numerodamusica = 3;
              output14State = "selecionada";
            } else if (header.indexOf("GET /14/off") >= 0) {
              numerodamusica = 3;
              output14State = "inicio";
            }
  
//CRIAR A PÁGINA WEB HTML
            client.println("<!DOCTYPE html><html>");      //Indica que estamos a enviar HTML
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");     //Faz com q a página web consiga "responder"
            client.println("<link rel=\"icon\" href=\"data:,\">");
    //Botões
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #F93C3C; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #F93C3C;}</style></head>");

    //Título e subtítulo
            client.println("<body><h1>PIANO TILES 2.0</h1>");
            client.println("<p>Selecione a musica natalicia com que pretende jogar:</p>");

    //Estado Atual do botão 5
            // If the output5State is one strate, it displays the other
            if (output5State == "inicio") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">Jingle Bell Rock</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">Jingle Bell Rock</button></a></p>");
            }

    //Estado Atual do botão 4
            // If the output4State is one strate, it displays the other
            if (output4State == "inicio") {
              client.println("<p><a href=\"/4/on\"><button class=\"button\">We Wish You a Merry Christmas</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">We Wish You a Merry Christmas</button></a></p>");
            }

    //Estado Atual do botão 14
            // If the output14State is one strate, it displays the other
            if (output14State == "inicio") {
              client.println("<p><a href=\"/14/on\"><button class=\"button\">Santa Claus is Coming to Town</button></a></p>");
            } else {
              client.println("<p><a href=\"/14/off\"><button class=\"button button2\">Santa Claus is Coming to Town</button></a></p>");
            }
            client.println("</body></html>");

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
  }
//Reiniciar a variável header
    header = "";
//terminar a conexão
    client.stop();

//ENVIAR O NÚMERO DA MÚSICA PARA O ARDUINO
    esparduino.begin(9600); 
    if (numerodamusica== 1 || numerodamusica== 2 || numerodamusica== 3){
      esparduino.print(numerodamusica, DEC);
    }
    numerodamusica = 0;
  }
}
