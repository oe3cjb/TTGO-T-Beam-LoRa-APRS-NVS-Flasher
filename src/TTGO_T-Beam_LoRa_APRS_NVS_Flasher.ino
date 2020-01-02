
// NVS Flaher for LoRA APRS Tracker TTGO T-Beam
// https://github.com/oe3cjb/TTGO-T-Beam-LoRa-APRS

#include <config.h> // to config user parameters
#include <Arduino.h>
#include <Preferences.h>
#include <SPI.h>
#include <math.h>
#include <Wire.h>

#include <axp20x.h>

#define EMPTY "EMPTY"

// I2C LINES
#define I2C_SDA 21
#define I2C_SCL 22

// AXP192 address
#define AXP192_SLAVE_ADDRESS  0x34

// Variables
Preferences prefs;
enum Tx_Mode {TRACKER, WX_TRACKER, WX_MOVE, WX_FIXED};
Tx_Mode tracker_mode;
String LongFixed="";
String LatFixed="";
String TxSymbol="";
String Tcall;                //your Call Sign for normal position reports
String wxTcall;              //your Call Sign for weather reports
String sTable="/";           //Primer
String wxTable="/";          //Primer
String wxSymbol="_";         //Symbol Code Weather Station

#ifdef T_BEAM_V1_0
  AXP20X_Class axp;
#endif

// +---------------------------------------------------------------------+//
// + SETUP --------------------------------------------------------------+//
// +---------------------------------------------------------------------+//

void setup()
{
  Serial.begin(115200);

  Wire.begin(I2C_SDA, I2C_SCL);

  #ifdef T_BEAM_V1_0      // initialize power controller - new on HW V1.0
    if (!axp.begin(Wire, AXP192_SLAVE_ADDRESS)) {
      Serial.println("LoRa-APRS-NVS-Flasher / Init / AXP192 Begin PASS");
    } else {
      Serial.println("LoRa-APRS-NVS-Flasher / Init / AXP192 Begin FAIL");
    }
    axp.setPowerOutPut(AXP192_LDO2, AXP202_ON);
    axp.setPowerOutPut(AXP192_LDO3, AXP202_ON);
    axp.setPowerOutPut(AXP192_DCDC2, AXP202_ON);
    axp.setPowerOutPut(AXP192_EXTEN, AXP202_ON);
    axp.setPowerOutPut(AXP192_DCDC1, AXP202_ON);
    axp.setDCDC1Voltage(3300);
  #endif

  prefs.begin("nvs", false);
  tracker_mode = (Tx_Mode)prefs.getChar("tracker_mode", 9);
  Tcall = prefs.getString("Tcall", EMPTY);
  wxTcall = prefs.getString("wxTcall", EMPTY);
  LatFixed = prefs.getString("LatFixed", EMPTY);
  LongFixed = prefs.getString("LongFixed", EMPTY);
  TxSymbol = prefs.getString("TxSymbol", EMPTY);
  prefs.end();

  Serial.println("LoRa-APRS-NVS-Flasher / READ / MODE="+String(tracker_mode)+" / Call="+Tcall+" / WX-Call="+wxTcall+" / TxSymbol="+TxSymbol+" / Longitude="+LongFixed+" / Latitude="+LatFixed);

  Tcall = CALLSIGN;
  wxTcall = WX_CALLSIGN;
  LongFixed = LONGITUDE_PRESET;
  LatFixed = LATIDUDE_PRESET;
  TxSymbol = APRS_SYMBOL;


#ifdef WRITE_VALUES //
  Serial.println("LoRa-APRS-NVS-Flasher / WRITE / MODE="+String(tracker_mode)+" / Call="+Tcall+" / WX-Call="+wxTcall+" / TxSymbol="+TxSymbol+" / Longitude="+LongFixed+" / Latitude="+LatFixed);
  // write all values to NVRAM
  prefs.begin("nvs", false);
  prefs.putChar("tracker_mode", TRACKER_MODE);
  prefs.putString("Tcall", Tcall);
  prefs.putString("wxTcall", wxTcall);
  prefs.putString("LatFixed", LatFixed);
  prefs.putString("LongFixed", LongFixed);
  prefs.putString("TxSymbol", TxSymbol);
  prefs.end();
#endif
}

// +---------------------------------------------------------------------+//
// + MAINLOOP -----------------------------------------------------------+//
// +---------------------------------------------------------------------+//

void loop() {
  Serial.println("LoRa-APRS-NVS-Flasher / DONE!");
  while (1) {
    /* code */
  }
}
