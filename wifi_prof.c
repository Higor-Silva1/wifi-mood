#include <WiFi.h>
#include <WiFiClientSecure.h>

WiFiClientSecure client;//Cliente seguro (para ter acesso ao HTTPS)
String textFix = "GET path";
const char* ssid = "SSID"; // SSID
const char* password = "123"; // senha
const char* server = "docs.google.com"; // Our server URL:https://mood-a.herokuapp.com/

void setup()
{
Serial.begin(9600);//Inicia a comunicacao serial
Serial.println("Inicio");
WiFi.mode(WIFI_STA);//Habilita o modo estaao
delay(100);

Serial.print("Conectando a SSID: ");
Serial.println(ssid);
WiFi.begin(ssid, password);
//tentativa de conectar na rede
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
// esperar 1 segundos
delay(1000);
}
Serial.println("");
Serial.print("Connectado a ");
Serial.println(ssid);
Serial.println("IP address: ");
Serial.println(WiFi.localIP());
client.setInsecure();
}
