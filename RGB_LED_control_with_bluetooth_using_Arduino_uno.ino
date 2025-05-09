#define redPin 9
#define greenPin 10
#define bluePin 11

void setup() {
  // Set the pins for RGB LED as OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600); // Default communication rate of the Bluetooth module
   setColor(037,166,154); // Default Color
}


void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();

    // Check the received command and update the LED color accordingly
    if (command.length() == 9) {
      // Extract the RGB values from the command
      int redValue = command.substring(0, 3).toInt();
      int greenValue = command.substring(3, 6).toInt();
      int blueValue = command.substring(6).toInt();
  
      // Set the LED color
      setColor(redValue, greenValue, blueValue);
    }
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }
