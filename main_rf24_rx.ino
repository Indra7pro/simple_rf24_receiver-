#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

#define CE_PIN   PB13
#define CSN_PIN  PB14

const byte thisSlaveAddr[5] = {'I','N','D','R','A'};

RF24 radio(CE_PIN, CSN_PIN);

struct dt {
  int j1;
  int j2;
  int j3;
  int j4;
  bool b1;
  bool b2;
};

dt data_received;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Servo pins
#define SERVO1_PIN PB9
#define SERVO2_PIN PB8
#define SERVO3_PIN PB7
#define SERVO4_PIN PB6

// Digital output pins
#define OUT1 PB4
#define OUT2 PB3

void setup() {
  Serial.begin(115200);
  Serial.println("RX starting...");

  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);

  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  servo3.attach(SERVO3_PIN);
  servo4.attach(SERVO4_PIN);

  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_HIGH);
  radio.openReadingPipe(1, thisSlaveAddr);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&data_received, sizeof(data_received));

    servo1.write(data_received.j1);
    servo2.write(data_received.j2);
    servo3.write(data_received.j3);
    servo4.write(data_received.j4);

    digitalWrite(OUT1, data_received.b1 ? HIGH : LOW);
    digitalWrite(OUT2, data_received.b2 ? HIGH : LOW);

    Serial.print("J1: "); Serial.print(data_received.j1);
    Serial.print(" J2: "); Serial.print(data_received.j2);
    Serial.print(" J3: "); Serial.print(data_received.j3);
    Serial.print(" J4: "); Serial.print(data_received.j4);
    Serial.print(" B1: "); Serial.print(data_received.b1);
    Serial.print(" B2: "); Serial.println(data_received.b2);
  }
}
