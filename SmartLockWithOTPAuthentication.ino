
/*#include <SoftwareSerial.h>

SoftwareSerial sim800(10, 11); // RX, TX
String password;  // Variable to store password

void setup() {
  Serial.begin(9600);
  sim800.begin(9600);
  Serial.println("Testing SIM800A Module");
  delay(3000); // Wait for SIM800A to initialize

  // Set SMS mode to text
  sim800.println("AT+CMGF=1");  // Set SMS mode to text
  delay(1000);

  // Generate random password and send
  generatePassword();
  sendOTP("9550675001", "Your password is " + password);
}

void loop() {
  // No need to continuously send, so keeping the loop empty
}

// Function to generate a random 4-character password with A-D and 0-9
void generatePassword() {
  randomSeed(analogRead(0)); // Seed random with a floating analog pin
  char characters[] = "ABCD0123456789"; // Character set

  password = ""; // Clear previous password
  for (int i = 0; i < 4; i++) {
    int randomIndex = random(0, sizeof(characters) - 1); // Random index
    password += characters[randomIndex]; // Append random character
  }

  Serial.println("Generated Password: " + password); // Display password in Serial Monitor
}

// Function to send password via SMS
void sendOTP(const char* phoneNumber, String message) {
  sim800.print("AT+CMGS=\"");
  sim800.print(phoneNumber);
  sim800.println("\"");  // Command to specify phone number
  delay(1000);           // Wait for SIM800A to respond with '>'

  sim800.print(message);  // Message content
  delay(500);

  sim800.write(26); // ASCII code for Ctrl+Z to send SMS
  delay(5000);      // Wait for message to send

  // Read module response
  while (sim800.available()) {
    Serial.write(sim800.read());
  }
}

*/
/*
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Keypad.h>
#include <Servo.h>

// LCD setup
const int lcdColumns = 16; // For 16x2 LCD (change to 20 if you have a 20x4 LCD)
const int lcdRows = 2;
const int lcdAddress = 0x27; // Your detected I2C address
LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);

// Keypad setup
SoftwareSerial sim800(10, 11); // TX, RX
Servo myServo;                 // Servo motor object
String password;               // Variable to store the generated password
String inputPassword = "";     // Variable to store the entered password

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect keypad ROW0, ROW1, ROW2, ROW3 to these Arduino pins
byte colPins[COLS] = {5, 4, 3, 2}; // Connect keypad COL0, COL1, COL2, COL3 to these Arduino pins
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  sim800.begin(9600);
  myServo.attach(12); // Attach servo to pin 12
  myServo.write(0);   // Set initial position of servo

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Print a message on the LCD
  lcd.setCursor(0, 0);       
  lcd.print("Enter Password: "); // Display prompt
  lcd.setCursor(0, 1);       
  lcd.print("Input: ");         // Display another message

  Serial.println("Testing SIM800A Module");
  delay(3000); // Wait for SIM800A to initialize

  // Set SMS mode to text
  sim800.println("AT+CMGF=1");  // Set SMS mode to text
  delay(1000);

  // Generate random password and send
  generatePassword();
  sendOTP("9550675001", "Your password is " + password);
}

void loop() {
  char key = keypad.getKey(); // Get key from keypad

  if (key) {
    if (key == '#') { // '#' is used to confirm entry
      if (inputPassword == password) {
        Serial.println("Correct Password!");
        rotateServo();
        inputPassword = ""; // Reset input password after success
      } else {
        Serial.println("Incorrect Password.");
        inputPassword = ""; // Reset on failure
      }
      lcd.clear(); // Clear LCD for next entry
      lcd.setCursor(0, 0);       
      lcd.print("Enter Password: "); // Display prompt again
      lcd.setCursor(0, 1);       
      lcd.print("Input: ");
    } else if (key == '*') { // '*' is used to clear entry
      inputPassword = "";
      lcd.setCursor(7, 1);
      lcd.print("        "); // Clear input on LCD
      Serial.println("Password Cleared");
    } else {
      inputPassword += key; // Append entered key to inputPassword
      lcd.setCursor(7, 1);   // Move cursor to the second line
      lcd.print(inputPassword); // Display the entered characters on LCD
      Serial.println("Current Input: " + inputPassword);
    }
  }
}

// Function to generate a random 4-character password with A-D and 0-9
void generatePassword() {
  randomSeed(analogRead(0)); // Seed random with a floating analog pin
  char characters[] = "ABCD0123456789"; // Character set

  password = ""; // Clear previous password
  for (int i = 0; i < 4; i++) {
    int randomIndex = random(0, sizeof(characters) - 1); // Random index
    password += characters[randomIndex]; // Append random character
  }

  Serial.println("Generated Password: " + password); // Display password in Serial Monitor
}

// Function to send password via SMS
void sendOTP(const char* phoneNumber, String message) {
  sim800.print("AT+CMGS=\"");
  sim800.print(phoneNumber);
  sim800.println("\"");  // Command to specify phone number
  delay(1000);           // Wait for SIM800A to respond with '>'

  sim800.print(message);  // Message content
  delay(500);

  sim800.write(26); // ASCII code for Ctrl+Z to send SMS
  delay(5000);      // Wait for message to send

  // Read module response
  while (sim800.available()) {
    Serial.write(sim800.read());
  }
}

// Function to rotate the servo motor
void rotateServo() {
  Serial.println("Rotating Servo Motor...");
  myServo.write(90);  // Rotate to 90 degrees
  delay(2000);        // Hold position for 2 seconds
  myServo.write(0);   // Return to 0 degrees
  delay(1000);
}
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <Keypad.h>
#include <Servo.h>

// LCD setup
const int lcdColumns = 16; // For 16x2 LCD (change to 20 if you have a 20x4 LCD)
const int lcdRows = 2;
const int lcdAddress = 0x27; // Your detected I2C address
LiquidCrystal_I2C lcd(lcdAddress, lcdColumns, lcdRows);

// Keypad setup
SoftwareSerial sim800(10, 11); // TX, RX
Servo myServo;                 // Servo motor object
String password;               // Variable to store the generated password
String inputPassword = "";     // Variable to store the entered password

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect keypad ROW0, ROW1, ROW2, ROW3 to these Arduino pins
byte colPins[COLS] = {5, 4, 3, 2}; // Connect keypad COL0, COL1, COL2, COL3 to these Arduino pins
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  sim800.begin(9600);
  myServo.attach(12); // Attach servo to pin 12
  myServo.write(0);   // Set initial position of servo

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  
  // Print a message on the LCD
  lcd.setCursor(0, 0);       
  lcd.print("Enter Password: "); // Display prompt
  lcd.setCursor(0, 1);       
  lcd.print("Input: ");         // Display another message

  Serial.println("Testing SIM800A Module");
  delay(3000); // Wait for SIM800A to initialize

  // Set SMS mode to text
  sim800.println("AT+CMGF=1");  // Set SMS mode to text
  delay(1000);

  // Generate random password and send
  generatePassword();
  sendOTP("9550675001", "Your password is " + password);
}

void loop() {
  char key = keypad.getKey(); // Get key from keypad

  if (key) {
    if (key == '#') { // '#' is used to confirm entry
      if (inputPassword == password) {
        Serial.println("Correct Password!");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Correct Password!");
        rotateServo();  // Rotate the servo on correct password
        delay(2000);    // Show message for 2 seconds
        lcd.clear();
      } else {
        Serial.println("Incorrect Password.");
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Access Denied");
        delay(2000);    // Show "Access Denied" message for 2 seconds
        lcd.clear();
      }
      inputPassword = ""; // Reset input password after checking
      lcd.setCursor(0, 0);       
      lcd.print("Enter Password: "); // Display prompt again
      lcd.setCursor(0, 1);       
      lcd.print("Input: ");
    } else if (key == '*') { // '*' is used to clear entry
      inputPassword = "";
      lcd.setCursor(7, 1);
      lcd.print("        "); // Clear input on LCD
      Serial.println("Password Cleared");
    } else {
      inputPassword += key; // Append entered key to inputPassword
      lcd.setCursor(7, 1);   // Move cursor to the second line
      lcd.print(inputPassword); // Display the entered characters on LCD
      Serial.println("Current Input: " + inputPassword);
    }
  }
}

// Function to generate a random 4-character password with A-D and 0-9
void generatePassword() {
  randomSeed(analogRead(0)); // Seed random with a floating analog pin
  char characters[] = "ABCD0123456789"; // Character set

  password = ""; // Clear previous password
  for (int i = 0; i < 4; i++) {
    int randomIndex = random(0, sizeof(characters) - 1); // Random index
    password += characters[randomIndex]; // Append random character
  }

  Serial.println("Generated Password: " + password); // Display password in Serial Monitor
}

// Function to send password via SMS
void sendOTP(const char* phoneNumber, String message) {
  sim800.print("AT+CMGS=\"");
  sim800.print(phoneNumber);
  sim800.println("\"");  // Command to specify phone number
  delay(1000);           // Wait for SIM800A to respond with '>'

  sim800.print(message);  // Message content
  delay(500);

  sim800.write(26); // ASCII code for Ctrl+Z to send SMS
  delay(5000);      // Wait for message to send

  // Read module response
  while (sim800.available()) {
    Serial.write(sim800.read());
  }
}

// Function to rotate the servo motor
void rotateServo() {
  Serial.println("Rotating Servo Motor...");
  myServo.write(90);  // Rotate to 90 degrees
  delay(2000);        // Hold position for 2 seconds
  myServo.write(0);   // Return to 0 degrees
  delay(1000);
}
