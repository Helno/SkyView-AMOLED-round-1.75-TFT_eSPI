# SkyView AMOLED - Demo Mode User Guide

## Overview

Demo mode allows you to playback pre-recorded NMEA data from a file stored in SPIFFS, simulating real-time traffic data without needing an actual BLE/Serial/WiFi connection.

**Perfect for:**
- Testing and development
- Product demonstrations
- Training scenarios
- Offline operation
- Feature testing without live data source

---

## Quick Start Guide

### Step 1: Prepare Your Demo File

Create or obtain an NMEA data file (`.nmea` or `.txt`) containing flight data. Example format:

```nmea
$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47
$PFLAA,0,1234,5678,100,2,ABC123,50,1.5,2,000000,GLIDER*34
$PFLAU,0,1,2,1,0,123,1,100,50*1F
$GPGGA,123520,4807.039,N,01131.001,E,1,08,0.9,545.4,M,46.9,M,,*48
$PFLAA,0,1235,5679,101,2,ABC123,50,1.5,2,000000,GLIDER*35
```

**Important Notes:**
- Each NMEA sentence should be on its own line
- Use standard NMEA format (GPGGA, PFLAA, PFLAU, etc.)
- File will loop automatically when it reaches the end
- Default timing: 160ms between lines, targeting 1 second between `$GPGGA` sentences

### Step 2: Upload the Demo File

**Option A: Via Web Interface**

1. Connect to your SkyView device WiFi or ensure it's on your network
2. Open web browser and navigate to: `http://192.168.1.1/demofile`
   (Or use your device's IP address)
3. Click **"Choose File"** and select your `.nmea` file
4. Click **"Upload"** button
5. Wait for confirmation message: "Demo file uploaded successfully"

**Option B: Via Settings Page**

1. Navigate to: `http://192.168.1.1/settings`
2. Scroll to find demo file upload section (if available)
3. Upload your file

### Step 3: Enable Demo Mode

1. Go to Settings page: `http://192.168.1.1/settings`
2. Find the **"Connection type"** dropdown
3. Select **"Demo File"** from the options:
   - Serial
   - WiFi UDP
   - Bluetooth SPP
   - Bluetooth LE
   - **Demo File** ← Select this
4. Click **"Save"** button
5. Device may restart automatically

### Step 4: Verify Playback

1. Check the display - you should see:
   - Simulated traffic on the radar view
   - Aircraft appearing on text info view
   - Position data updating
2. Watch for the demo data cycling through
3. File will automatically loop back to the beginning

---

## Web Interface Pages

### Demo File Management (`/demofile`)

Access at: `http://192.168.1.1/demofile`

**Features:**
- **Upload:** Select and upload new demo NMEA files
- **Download:** Download the current demo file from device
- **Info:** View current settings and file information
- **Link:** Quick link back to Settings page

### Settings Page (`/settings`)

The main settings page now includes:
- **Connection type dropdown** with "Demo File" option
- All other standard SkyView settings
- Save button to apply changes

### Status Page (`/`)

The home/status page will show:
- **Connection:** "Demo File" when active
- Other device status information

---

## File Management

### Current Demo File Location

The demo file is stored in SPIFFS filesystem as:
```
/demo.nmea
```

### Download Current File

To backup or view your current demo file:
1. Navigate to: `http://192.168.1.1/download-demo`
2. File will download automatically
3. Can be edited and re-uploaded

### Replace Demo File

Simply upload a new file - it will overwrite the existing `/demo.nmea`

---

## Playback Timing

### Default Settings

- **Line delay:** 160ms between each NMEA sentence
- **Target interval:** 1 second between `$GPGGA` position updates
- **Mode:** Continuous loop playback

### Understanding Timing

If your NMEA file has this structure:
```
$GPGGA,120000,...    ← Position update
$PFLAA,0,...         ← Traffic 1 (160ms later)
$PFLAA,0,...         ← Traffic 2 (320ms later)
$PFLAA,0,...         ← Traffic 3 (480ms later)
$PFLAU,0,...         ← Traffic summary (640ms later)
$GPGGA,120001,...    ← Next position (1000ms later)
```

Total time: 160ms × 6 lines = ~1000ms (1 second) between position updates

### Adjusting Playback Speed

The line delay is currently hardcoded to 160ms but can be customized in the firmware if needed. Contact development team for custom timing requirements.

---

## Creating Effective Demo Files

### Tips for Good Demo Files

1. **Include Position Data**
   - Use `$GPGGA` sentences for own-ship position
   - Update every 1 second for smooth playback

2. **Add Traffic Data**
   - Use `$PFLAA` sentences for individual aircraft
   - Use `$PFLAU` for traffic summary
   - Show aircraft at various distances and altitudes

3. **Create Scenarios**
   - Show aircraft approaching (decreasing distance)
   - Demonstrate different alarm levels
   - Include various aircraft types

4. **File Length**
   - 30-60 seconds of data works well
   - File loops automatically
   - Longer files provide more variety

### Example Scenario: Aircraft Approaching

```nmea
$GPGGA,120000,5200.000,N,00100.000,E,1,08,0.9,100.0,M,46.9,M,,*4F
$PFLAA,0,3000,0,50,2,ABC123,150,1.5,2,000000,GLIDER*12
$PFLAU,1,1,2,1,0,150,1,100,50*5A
$GPGGA,120001,5200.001,N,00100.001,E,1,08,0.9,100.0,M,46.9,M,,*4E
$PFLAA,0,2500,0,50,2,ABC123,150,1.5,2,000000,GLIDER*13
$PFLAU,1,1,2,1,0,150,1,100,50*5B
$GPGGA,120002,5200.002,N,00100.002,E,1,08,0.9,100.0,M,46.9,M,,*4D
$PFLAA,0,2000,0,50,2,ABC123,150,1.5,2,000000,GLIDER*14
$PFLAU,2,1,2,1,0,150,1,100,50*58
$GPGGA,120003,5200.003,N,00100.003,E,1,08,0.9,100.0,M,46.9,M,,*4C
$PFLAA,0,1500,0,50,2,ABC123,150,1.5,2,000000,GLIDER*15
$PFLAU,2,1,2,1,0,150,1,100,50*59
```

---

## Switching Between Modes

### From Demo Mode to Live Data

1. Go to Settings: `http://192.168.1.1/settings`
2. Change **Connection type** to:
   - **Bluetooth LE** (for SoftRF/SenseCap)
   - **WiFi UDP** (for network sources)
   - **Serial** (for wired connections)
3. Click **Save**
4. Device restarts with live data connection

### From Live Data to Demo Mode

1. Ensure demo file is uploaded (`/demofile`)
2. Go to Settings page
3. Select **Demo File** from dropdown
4. Save and restart

---

## Troubleshooting

### No Traffic Appearing

**Problem:** Demo mode is active but no traffic shows on display

**Solutions:**
1. Verify demo file is uploaded:
   - Try downloading from `/download-demo`
   - Check file is not empty
2. Check connection type is set to "Demo File"
3. Verify NMEA sentences are properly formatted
4. Check serial monitor for debug messages (if DEBUG_MODE enabled)

### File Upload Fails

**Problem:** Cannot upload demo file

**Solutions:**
1. Check file size (should be under 100KB typically)
2. Verify SPIFFS has free space
3. Try smaller file
4. Check network connection to device
5. Refresh browser and try again

### Playback Too Fast/Slow

**Problem:** Traffic updates don't match expected timing

**Solutions:**
1. Verify your file has correct number of lines between `$GPGGA` sentences
2. For 1-second updates with 160ms line delay: Use 6-7 lines between position updates
3. For custom timing, contact development team

### Demo File Won't Loop

**Problem:** Playback stops after one cycle

**Solutions:**
1. This shouldn't happen - file loops automatically
2. Check serial monitor for error messages
3. Try re-uploading the file
4. Verify file ends with proper line termination

---

## Technical Specifications

### File Format
- **Type:** Plain text NMEA sentences
- **Encoding:** ASCII
- **Line endings:** LF or CRLF
- **Extension:** `.nmea` or `.txt`
- **Location:** `/demo.nmea` in SPIFFS

### Timing
- **Default line delay:** 160ms
- **Recommended GPGGA interval:** 1000ms (1 second)
- **Playback mode:** Continuous loop
- **Processing:** Real-time character-by-character parsing

### Supported NMEA Sentences
- `$GPGGA` - GPS position data
- `$PFLAA` - FLARM relative traffic data
- `$PFLAU` - FLARM status/summary
- `$GPRMC` - Recommended minimum data
- Other standard NMEA sentences

### Memory Usage
- **SPIFFS storage:** Available flash space
- **RAM:** Minimal (single line buffer)
- **Typical file size:** 10-100 KB

---

## Advanced Usage

### Multiple Demo Scenarios

To switch between different demo scenarios:
1. Create multiple NMEA files on your computer:
   - `demo_training.nmea`
   - `demo_busy_traffic.nmea`
   - `demo_emergency.nmea`
2. Upload the desired scenario file
3. It will overwrite `/demo.nmea`
4. Restart demo mode if already active

### Integration with Testing

Demo mode is ideal for:
- **UI/UX testing** - Verify display updates
- **Alarm testing** - Test proximity warnings
- **Performance testing** - Check system under load
- **User training** - Safe environment learning
- **Feature demos** - Show capabilities to users

---

## Safety Notes

⚠️ **Important Safety Information:**

- **Demo mode is for TESTING ONLY**
- **Never use demo mode during actual flight operations**
- **Always use live data sources (BLE/WiFi/Serial) when flying**
- Demo mode displays **simulated data** - not real traffic
- Ensure you switch back to proper connection type before flight

---

## Support

### Getting Help

If you encounter issues with Demo mode:

1. **Check Serial Monitor** (38400 baud)
   - Look for demo mode messages
   - Check for file read errors
   - Verify SPIFFS mount status

2. **Verify File Format**
   - Ensure NMEA sentences are valid
   - Check line endings
   - Validate checksums if present

3. **Report Issues**
   - Include demo file (if possible)
   - Provide serial monitor output
   - Describe expected vs actual behavior

### Debug Mode

If compiled with `DEBUG_MODE` enabled, you'll see:
```
Demo mode started - playing: /demo.nmea
Demo NMEA: $GPGGA,123519,4807.038,N,01131.000,E,...
Demo NMEA: $PFLAA,0,1234,5678,100,2,ABC123,...
Demo playback complete - looping to start
```

---

## Changelog

### Version 1.0 (Current)
- Initial demo mode implementation
- File upload/download via web interface
- Automatic looping playback
- 160ms default line timing
- NMEA sentence parsing support
- SPIFFS file storage

### Future Enhancements (Planned)
- Adjustable playback speed via UI
- Multiple file slots (demo1, demo2, etc.)
- Pause/resume functionality
- Real-time playback speed adjustment
- File validation and preview

---

## Quick Reference

| Action | URL | Method |
|--------|-----|--------|
| Upload demo file | `/demofile` | Web UI |
| Download demo file | `/download-demo` | GET |
| Enable demo mode | `/settings` | Select "Demo File" |
| Check status | `/` | View connection type |

**Default Settings:**
- File: `/demo.nmea`
- Line delay: 160ms
- Loop: Enabled
- Protocol: NMEA (TinyGPS++)

---

**Last Updated:** 2025-10-26
**Firmware Version:** VB007+
**Compatible Boards:** LilyGo AMOLED 1.75", Waveshare AMOLED 1.75"

---

For more information, visit the [SkyView-AMOLED GitHub repository](https://github.com/slash-bit/SkyView-AMOLED-TFT_eSPI).
