// Digite "thinger.io" no Library Manager.
// Instale a biblioteca thinger.io (by Alvaro Luis Bustamante)
#include <ThingerESP32.h>


// Digite "dht sensor library" no Library Manager.
// Instale a biblioteca DHT sensor (library by Adafruit)
#include <DHT.h>

#define pinoDHT 17
#define tipoDHT DHT11 // (azul) ou DHT22 (branco)

DHT dht(pinoDHT, tipoDHT);

// Insira as credenciais do dispositivo configurado na plataforma:
#define USERNAME "nina-rebello"           // Seu nome de usuário na plataforma thinger.io
#define DEVICE_ID "ESP32"          // Device ID criado na plataforma
#define DEVICE_CREDENTIAL "ninarf"  // Credencial do device criada na plataforma

// Insira as credenciais da sua rede WiFi 4G:
// Utilize um roteador de um celular próximo.
// No Android, certifique-se de deixar a frequência em 2.4GHz
// No iPhone, certifique-se de habilitar a opção "Maximizar Compatibilidade"
#define SSID "Iphone de Nina" 
#define SSID_PASSWORD "nina12345"

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

// Crie aqui suas variáveis:
float temp, umid;              // Para sensor DHT11
int numero;                    // Número randômico
String ID = "ESP32"; // Identificador

void setup() {  
  Serial.begin(115200);  
  thing.add_wifi(SSID, SSID_PASSWORD);
  delay(500);

  // Adicione os nomes dos Devices Resources à esquerda
  // e as variáveis do seu código à direita
  thing["temperature"] >> outputValue(temp);  
  thing["humidity"] >> outputValue(umid); 
  thing["random_number"] >> outputValue(numero); 
  thing["device_id"] >> outputValue(ID);  
}

void loop() {

  // Chamada da função para gerar o número randômico.
  geraNumero();

  // Chamada da função para leitura de temperatura e umidade do sensor.
  leituraSensor();

  // Essa função é responsável pela comunicação com a plataforma:
  thing.handle();
  // A requisição ocorrerá a cada 5 segundos.
  delay(5000);
}

void geraNumero(){
  // Crie aqui sua função para gerar o número randômico
  numero = random(0, 100); // Gera um número aleatório entre 0 e 99

}

void leituraSensor(){
  // Crie aqui sua função para ler os valores de temperatura e umidade do sensor DHT
  umid = dht.readHumidity(); // Lê a umidade
  temp = dht.readTemperature(); // Lê a temperatura em Celsius

}



