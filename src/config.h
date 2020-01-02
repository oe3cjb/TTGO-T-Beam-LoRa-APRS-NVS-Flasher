// NVS Flasher for LoRA APRS Tracker TTGO T-Beam
//
// licensed under CC BY-NC-SA
//
// version: V1.0
// last update: 02.01.2020

// SET HW version
#define T_BEAM_V1_0    // use this for older Boards AKA Rev1 (second board release)
// #define T_BEAM_V0_7    // use this for older Boards AKA Rev0 (first board release)

// #define WRITE_VALUES      // uncomment to write values

#define CALLSIGN "OE3CJB-9"     // enter your callsign here - less then 6 letter callsigns please add "spaces" so total length is 6 (without SSID)
#define WX_CALLSIGN "OE3CJB-9"  // use same callsign but you can use different SSID
#define LONGITUDE_PRESET "01539.85E" // please in APRS notation DDMM.mmN or DDMM.mmS
#define LATIDUDE_PRESET "4813.62N"   // please in APRS notation DDDMM.mmE or DDDMM.mmW
#define APRS_SYMBOL ">"         // other symbols are
#define TRACKER_MODE TRACKER        // TRACKER, WX_TRACKER, WX_MOVE, WX_FIXED
