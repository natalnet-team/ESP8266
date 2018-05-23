#include <ESP8266WiFi.h>  //biblioteca das placas Esp
 
const char* ssid = "TEAM-OBR";  //nome da rede
const char* password = "Ei, qual a senha do roteador?!?!"; // senha da rede
 
int ledPin = 2; // GPIO13 que representa o pino D7 no NodeMCU
WiFiServer server(80);  //cria a conexão com o servidor na porta 80
int value = LOW;
 
void setup() {
  Serial.begin(115200); //inicia o envio de dados pelo cabo USB
  delay(1000);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
 
  // Connectando a uma WiFi e imprime o nome da rede, mas isso é enviado pelo cabo USB (Serial)
  Serial.println();
  Serial.println();
  Serial.print("Connectando com ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password); //inicia a conexão com a rede wifi

 //enquanto não conecta ele vai imprimir . a cada meio segundo
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connectedo!");  // a conexão com wifi começou e foi impressa a mensagem
 
  // Inicia a comunicação com o server
  server.begin();
  Serial.println("Server iniciou em: ");  //via usb foi enviada a mensagem que o servidor está conectado
 
  // Imprimir o IP onde está a página web
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
 
void loop() {
  // Checa se um cliente conectou
  WiFiClient client = server.available();
  if (!client) {  //se o valor em client for falso o servidor não está disponivel então chama a função loop novamente
    return;
  }
 
  // Espera o clinte pedir algo
  Serial.println("mensagem do cliente: ");
  while(!client.available()){  //enquanto o cliente não pede, espere um milisegundo e depois tenta de novo
    delay(1);
  }
 
  // Lê a primeira linha da requisição
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  // Muda situação do LED, caso o parâmetro seja detectado 
  if (request.indexOf("ONOFF") != -1) {
    digitalWrite(ledPin, !digitalRead(ledPin));
    if(value == LOW){
      value = HIGH;
      Serial.println("ON");
    }
    else{
      value = LOW;
      Serial.println("OFF");
    }
  }
 
  
 
// Set ledPin according to the request

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
 
