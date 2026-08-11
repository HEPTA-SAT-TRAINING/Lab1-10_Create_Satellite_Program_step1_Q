const float bat_vol = 3.7; // Battery voltage in volts
const float temperature = 25.0; // Temperature in degrees Celsius

bool is_cmd_received(void);
char get_cmd(void);

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Lab1-03_create_satellite_program_setp2_Q");
}

void loop() {
  Serial.println("------------------------------");
  Serial.print("Satellite Time: ");
  Serial.println(millis() / 1000.0, 2); // Print time
  Serial.print("Battery Voltage: ");
  Serial.print(bat_vol);
  Serial.println("V");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.println("------------------------------");

  if (is_cmd_received()) {
    char cmd = get_cmd();

    if (cmd != '\0') {
      Serial.print("Received command: ");
      Serial.println(cmd);

      // Process the command and respond accordingly
      switch (cmd) {
        case 'a':
          Serial.println("Hello Hepta sat lite");




          
          break;
        default:
          Serial.println("Unknown command");
          break;
      }
    }
  }
  delay(1000);
}

bool is_cmd_received(void) {
  // Check if there is any data available in the serial buffer
  return Serial.available() > 0;
}

char get_cmd(void) {
  // Read one command character and ignore line endings from Serial Monitor.
  while (is_cmd_received()) {
    char received_char = Serial.read();
    if (received_char != '\r' && received_char != '\n') {
      return received_char;
    }
  }
  return '\0'; // Return null character if no data is available
}
