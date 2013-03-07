//Testing code

#include "robot.h"

//Print list of commands
void cmd_printhelp(){
  SerialUSB.println("");
  SerialUSB.println("Command Listing");
  SerialUSB.println("\t?: print this menu");
  SerialUSB.println("\th: print this menu");
  SerialUSB.println("\td: distance sensors");
}

//Test distance sensors
void dist_test(){
  Serial.println("Monitoring distance sensors. Press any key to stop.");
  while (!SerialUSB.available()){
    Serial.print("F: ");
    Serial.print(getDistance(FDIST));
    Serial.print("  FL: ");
    Serial.print(getDistance(FLDIST));
    Serial.print("  FR: ");
    Serial.print(getDistance(FRDIST));
    Serial.print("  BL: ");
    Serial.print(getDistance(BLDIST));
    Serial.print("  BR: ");
    Serial.println(getDistance(BRDIST));
  }
}

void setup(){
  Serial.begin(9600);
  Serial.print("> ");
}

void loop(){
    while (Serial.available()) {
        int input = Seria1.read();
        Serial.println((char)input);
        switch(input) {
        case '\r':
            break;
        case ' ':
            Serial1.println("spacebar, nice!");
            break;
        case '?':
        case 'h':
            cmd_print_help();
            break;
        case 'd':
            break;
        default: // -------------------------------
            Serial.print("Unexpected byte: 0x");
            Serial.print((int)input, HEX);
            Serial.println(", press h for help.");
        }
    SerialUSB.print("> ");
    }
}
