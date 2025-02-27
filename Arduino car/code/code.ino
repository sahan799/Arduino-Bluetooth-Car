
// Motor driver connections
#define IN1 5
#define IN2 6
#define IN3 9
#define IN4 10
#define ENA 3
#define ENB 11

// Bluetooth module connection
#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3);  // RX, TX (D2, D3)

void setup() {
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    Serial.begin(9600);
    BT.begin(9600);
}

void loop() {
    if (BT.available()) {
        char command = BT.read();
        Serial.println(command);
        
        switch (command) {
            case 'F':  // Move Forward
                moveForward();
                break;
            case 'B':  // Move Backward
                moveBackward();
                break;
            case 'L':  // Turn Left
                turnLeft();
                break;
            case 'R':  // Turn Right
                turnRight();
                break;
            case 'S':  // Stop
                stopCar();
                break;
            default:
                break;
        }
    }
}

// Function to move forward
void moveForward() {
    analogWrite(ENA, 150);  // Speed (0-255)
    analogWrite(ENB, 150);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

// Function to move backward
void moveBackward() {
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

// Function to turn left
void turnLeft() {
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

// Function to turn right
void turnRight() {
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

// Function to stop the car
void stopCar() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
