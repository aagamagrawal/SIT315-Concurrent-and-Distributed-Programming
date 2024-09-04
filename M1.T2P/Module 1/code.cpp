// Define pin connections
const int tempSensorPin = A0;  // Analog pin connected to the temperature sensor
const int ledPin = 13;         // Digital pin connected to the LED

// Define a temperature threshold
const float tempThreshold = 50.0;  // Temperature in Celsius

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Start with the LED turned off
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Read the analog value from the temperature sensor
  int sensorValue = analogRead(tempSensorPin);
  
  // Convert the analog value to a voltage (assuming 5V reference)
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Convert the voltage to a temperature in Celsius
  // Assuming a 10mV per degree C scale for a typical TMP36 sensor
  float temperatureC = (voltage - 0.5) * 100.0;

  // Print the temperature value to the serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  // Check if the temperature exceeds the threshold
  if (temperatureC > tempThreshold) {
    // Turn on the LED if the temperature is above the threshold
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn off the LED if the temperature is below the threshold
    digitalWrite(ledPin, LOW);
  }

  // Wait for a short period before reading the sensor again
  delay(500);
}
