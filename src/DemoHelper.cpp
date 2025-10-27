/*
 * DemoHelper.cpp
 * Demo mode playback from SPIFFS file
 */

#include "DemoHelper.h"
#include "EEPROMHelper.h"
#include "NMEAHelper.h"
#include "GDL90Helper.h"
#include "SkyView.h"
#include <FS.h>
#include <SPIFFS.h>

static File demoFile;
static bool demoPlaying = false;
static unsigned long lastLineTime = 0;
static uint16_t lineDelayMs = DEFAULT_DEMO_LINE_DELAY_MS;
static String currentLine = "";

void Demo_setup() {
    if (!SPIFFS.begin(true)) {
        Serial.println("SPIFFS mount failed for demo mode");
        return;
    }

    if (!SPIFFS.exists(DEMO_FILE_PATH)) {
        Serial.println("Demo file not found: " DEMO_FILE_PATH);
        return;
    }

    demoFile = SPIFFS.open(DEMO_FILE_PATH, "r");
    if (!demoFile) {
        Serial.println("Failed to open demo file");
        return;
    }

    Serial.println("Demo mode started - playing: " DEMO_FILE_PATH);
    demoPlaying = true;
    lastLineTime = millis();
}

void Demo_loop() {
    if (!demoPlaying || !demoFile) {
        return;
    }

    // Check if it's time to send the next line
    if (millis() - lastLineTime < lineDelayMs) {
        return;
    }

    // Read next line from file
    if (demoFile.available()) {
        currentLine = demoFile.readStringUntil('\n');
        currentLine.trim();  // Remove any whitespace/newlines

        if (currentLine.length() > 0) {
            // Feed the line to NMEA or GDL90 parser based on protocol
            if (settings->protocol == PROTOCOL_NMEA) {
                #if defined(DEBUG_MODE)
                Serial.print("Demo NMEA: ");
                Serial.println(currentLine);
                #endif

                // Process NMEA sentence character by character through the full parser
                // This ensures all PFLAA/PFLAU traffic data is properly parsed
                currentLine += "\r\n";  // Add CRLF terminators
                for (size_t i = 0; i < currentLine.length(); i++) {
                    NMEA_ParseChar(currentLine[i]);  // Use public wrapper function
                }
            } else if (settings->protocol == PROTOCOL_GDL90) {
                // Process as GDL90 (if needed in future)
                // GDL90 is binary, so would need different handling
                #if defined(DEBUG_MODE)
                Serial.println("Demo mode: GDL90 not yet implemented");
                #endif
            }
        }

        lastLineTime = millis();
    } else {
        // End of file - loop back to beginning
        Serial.println("Demo playback complete - looping to start");
        demoFile.seek(0);
        lastLineTime = millis();
    }
}

void Demo_fini() {
    if (demoFile) {
        demoFile.close();
    }
    demoPlaying = false;
    Serial.println("Demo mode stopped");
}

bool Demo_isPlaying() {
    return demoPlaying;
}

void Demo_setLineDelay(uint16_t delay_ms) {
    lineDelayMs = delay_ms;
    Serial.print("Demo line delay set to: ");
    Serial.print(lineDelayMs);
    Serial.println(" ms");
}

uint16_t Demo_getLineDelay() {
    return lineDelayMs;
}
