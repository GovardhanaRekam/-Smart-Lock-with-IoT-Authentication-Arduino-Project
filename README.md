# 🔒 Smart Lock with IoT Authentication

This repository contains the Arduino code for a **Smart Lock System** that uses a keypad for user input and IoT authentication via SMS. The system generates a random password, sends it to the user via SMS, and unlocks the lock when the correct password is entered. The lock is controlled using a servo motor.  

## 🌟 Features

- **Random Password Generation**: Generates a random 4-character password using alphanumeric characters.
- **SMS Authentication**: Sends the password via SMS using the SIM800 module for added security.
- **Keypad Input**: Users can enter the password using a 4x4 keypad.
- **Servo Lock Control**: Unlocks and locks the mechanism using a servo motor.
- **LCD Display**: Displays prompts and feedback to the user during operation.

## 🛠 Hardware Required

- **Arduino Uno** or similar Arduino board  
- **SIM800 GSM Module** for sending SMS  
- **4x4 Keypad** for user input  
- **16x2 LCD Display** with I2C module for display  
- **Servo Motor** for locking and unlocking  
- Power Supply (e.g., 9V battery or USB power)  
- Breadboard and jumper wires  

## 💻 Software

The smart lock system operates with the following functionality:
1. **Password Generation**: A random password is generated at startup.
2. **SMS Sending**: The generated password is sent to the registered phone number via the SIM800 module.
3. **Keypad Input**: Users enter the password on the keypad.
4. **Authentication**: The entered password is checked against the generated password.
5. **Servo Control**: The servo motor unlocks if the password is correct and relocks after a delay.
6. **LCD Display**: Prompts and feedback are shown on the LCD screen during operation.

## 🛠 Setup and Deployment

1. **Hardware Connections**:  
   - Connect the **SIM800 module** to pins 10 (RX) and 11 (TX).  
   - Connect the **keypad** to digital pins 2–9.  
   - Attach the **servo motor** to pin 12.  
   - Connect the **LCD display** via I2C at address `0x27`.  

2. **Code Configuration**:  
   - Update the `sendOTP` function with your phone number:  
     ```cpp
     sendOTP("YourPhoneNumber", "Your password is " + password);
     ```  
   - Upload the code to your Arduino board using the Arduino IDE.  

3. **Operation**:  
   - The system generates and sends a random password via SMS at startup.  
   - Enter the received password on the keypad to unlock the lock.  

## 🔒 Smart Lock in Action  

Watch the smart lock in action on YouTube:  

[![Watch the Video](https://img.youtube.com/vi/odgM3H7Qye4/0.jpg)](https://youtu.be/odgM3H7Qye4)  

> Click the image above to watch the demo video!

## 🤝 Contributing  

Contributions to this project are welcome. You can:  
- Fork the repository and submit a pull request with your improvements.  
- Report issues or suggest new features through the issue tracker.  

## 📄 License  

This project is released under the MIT License. For more details, see the [LICENSE](LICENSE) file included in this repository.  

---

Happy Coding! 🚀
