#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>

#define RX_PIN 0  //RX
#define TX_PIN 2  //TX

SoftwareSerial mySerial(RX_PIN, TX_PIN);

const char* ssid = "xxxxxxxxxxxxx";
const char* password = "xxxxxxxxxxxxx";
const char* mqtt_server = "xxxxxxxxxxx";
const int mqtt_port = 1883;
const char* mqtt_user = "ESP01-UPX3";
const char* mqtt_topic = "upx3";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  delay(1000);
  Serial.begin(115200);
  mySerial.begin(9600);

  setup_wifi();
  
  client.setServer(mqtt_server, mqtt_port);

  reconnect();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (mySerial.available()) {
    String message = mySerial.readStringUntil('\n'); 
    Serial.println("Mensagem recebida: " + message);
    
    if (client.publish(mqtt_topic, message.c_str())) {
      Serial.println("Mensagem enviada via MQTT com sucesso");
    } else {
      Serial.println("Falha ao enviar a mensagem via MQTT");
    }
  }
}


void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando-se a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    if (client.connect("ESP01-UPX3")) {
      Serial.println("Conectado");
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}