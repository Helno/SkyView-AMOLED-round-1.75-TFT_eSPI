# Demo Flight Phases

This document describes the demo.nmea file structure and flight scenario for the SkyView AMOLED traffic awareness display.

## File Statistics

- **Total NMEA sentences:** 6,894
- **Duration:** ~861 seconds (~14.4 minutes)
- **Update rate:** 1 Hz (one complete frame per second)
- **Sentences per frame:** 6-10 (varies with number of aircraft visible)
- **Maximum simultaneous aircraft:** 3 (1 glider + 2 paragliders)

## Aircraft Configuration

### Primary Aircraft: Glider
- **Aircraft Type:** Glider (Type 1)
- **Aircraft ID:** 40AB21
- **Speed:** 100 km/h (27.78 m/s)
- **Starting Position:** 5 km North of ownship
- **Starting Altitude:** 500 meters above ownship

### Secondary Aircraft: Paraglider 1 (appears during Phase 4)
- **Aircraft Type:** Paraglider (Type 7)
- **Aircraft ID:** A1B2C3
- **Speed:** 40 km/h (11.11 m/s)
- **Starting Position:** 500 meters South-West of ownship
- **Starting Altitude:** +50 meters above ownship (appears RED - above)
- **Behavior:** Flying North parallel to ownship, sinking at -1.1 m/s

### Secondary Aircraft: Paraglider 2 (appears during Phase 4)
- **Aircraft Type:** Paraglider (Type 7)
- **Aircraft ID:** D4E5F6
- **Speed:** 35 km/h (9.72 m/s)
- **Starting Position:** 600 meters North-East of ownship
- **Starting Altitude:** -750 meters below ownship (appears GREEN - below)
- **Behavior:** Circling 50m radius, climbing -0.5 to 3.5 m/s (gains ~800m over duration)

## Flight Scenario Phases

The demo file simulates a realistic glider cross-country flight with thermal soaring behavior.

### Phase 1: Initial Approach (0-144 seconds)

**Duration:** 144 seconds (~2.4 minutes)

**Behavior:**
- Glider starts at 5,000 meters North of ownship
- Initial altitude: 500 meters above ownship
- Heading: 180° (South - directly toward you)
- Speed: 100 km/h constant
- Vertical speed: -3 m/s (descending)
- Distance covered: ~4,000 meters

**Description:** The glider approaches from the North while descending at a steady rate, simulating an aircraft in cruise between thermals. The approach continues until the glider reaches approximately 1,000 meters distance.

**Alarm Levels:**
- 0 (No alarm) - Distance > 2,000m
- 1 (Warning) - Distance 1,000-2,000m

---

### Phase 2: Right Turn (144-154 seconds)

**Duration:** 10 seconds

**Behavior:**
- Starting position: ~1,000 meters North
- Turn rate: 9° per second
- Heading change: 180° → 270° (South to East)
- Turn direction: Right (clockwise)
- Continues slow descent at -1 m/s
- Maintains 100 km/h speed

**Description:** The glider executes a standard-rate right turn, changing direction by 90 degrees. This represents the pilot deciding to turn East, possibly to intercept a thermal or continue cross-country.

**Alarm Levels:**
- 1-2 (Warning to Alert) - Distance ~1,000-1,100m

---

### Phase 3: Thermal Circling (154-370 seconds)

**Duration:** 216 seconds (~3.6 minutes)

**Behavior:**
- Circle radius: 100 meters
- Number of circles: ~6 complete circles
- Heading: Continuously changing (circling counter-clockwise)
- Speed: 100 km/h (maintained around circle)
- Vertical speed: **Variable 3-5 m/s** (climbing)
- Starting altitude: ~100 meters
- Ending altitude: ~1,200 meters
- Altitude gain: ~1,100 meters

**Climb Rate Pattern:**
The climb rate varies sinusoidally to simulate realistic thermal lift variations:
- Peak: 5 m/s (strong core)
- Average: 4 m/s
- Minimum: 3 m/s (edge of thermal)

**Description:** This is the most interesting phase. The glider has found a thermal updraft and circles within it to gain altitude. The variable climb rate simulates the natural variability of thermal lift - stronger in the core, weaker at the edges. This is typical soaring behavior where pilots work the thermal to maximize altitude gain.

**Position:** The glider maintains a relatively constant distance (~1,100-1,200 meters) from ownship while circling.

**Alarm Levels:**
- 1-2 (Warning to Alert) - Distance remains ~1,000-1,200m throughout circling

---

### Phase 4: Departure with Paragliders (370-514 seconds)

**Duration:** 144 seconds (~2.4 minutes)

**Primary Glider Behavior:**
- Heading: 90° (East - departing)
- Speed: 100 km/h constant
- Vertical speed: +2 m/s (gentle climb)
- Starting position: ~1,100 meters North, circling exit point
- Ending position: ~1,000 meters North, ~3,800 meters East
- Final distance: ~3,970 meters from ownship
- Altitude at departure start: ~1,220 meters
- Altitude at departure end: ~1,510 meters

**Description:** Having gained sufficient altitude in the thermal, the glider departs to the East to continue its cross-country flight. It maintains a gentle climb rate while cruising, typical of flying in rising air or dolphin-style soaring between thermals.

**Paragliders Appear at ~437 seconds (when glider reaches 2km distance):**

#### Paraglider 1 (A1B2C3) - Sinking Aircraft
- **Position:** 500 meters South-West (SW) of ownship
- **Initial Altitude:** +50 meters above ownship
- **Color on Display:** RED (above ownship)
- **Heading:** 0° (North) - flying parallel to ownship course
- **Speed:** 40 km/h
- **Vertical Speed:** -1.1 m/s (sinking/descending)
- **Behavior:** Flies North at constant speed while gradually descending. This simulates a paraglider in sinking air, unable to find lift, slowly losing altitude.
- **Alarm Level:** 3 (Urgent) - Close proximity (~350-370m)
- **Duration:** Visible for remainder of Phase 4

#### Paraglider 2 (D4E5F6) - Thermaling Aircraft
- **Position:** 600 meters North-East (NE) of ownship
- **Initial Altitude:** -750 meters below ownship
- **Final Altitude:** ~+50 meters above ownship (gains ~800m total)
- **Color on Display:** GREEN (below ownship, initially), transitions to CYAN/PURPLE as it climbs
- **Circle Radius:** 50 meters
- **Speed:** 35 km/h (around circle)
- **Vertical Speed:** Variable -0.5 to +3.5 m/s (sinusoidal pattern)
- **Behavior:** Circles counter-clockwise while climbing in a thermal. The variable climb rate simulates realistic thermal lift variations. Demonstrates sustained thermal climbing over extended period.
- **Alarm Level:** 2 (Alert) - Medium distance (~420-480m)
- **Duration:** Visible for remainder of Phase 4 (600 seconds total)

**Multi-Aircraft Alarm Levels:**
- PFLAU now shows total count of aircraft (3 total)
- Highest alarm level is reported (level 3 from PG1)
- Closest aircraft distance reported in PFLAU
- Phase transitions from 2 → 1 → 0 as glider departs, but jumps to 3 when PG1 appears

---

### Phase 5: Traffic Lost (514-518 seconds)

**Duration:** 4 seconds

**Behavior:**
- No traffic data (PFLAA sentences absent)
- PFLAU shows alarm level 0
- Only GPS position sentences remain

**Description:** The glider has departed beyond the effective range or has been filtered out. The display returns to "NO DATA" state with only ownship position information.

---

## Technical Details

### NMEA Sentence Structure

Each frame contains 6-10 NMEA sentences (varies with number of aircraft):

1. **$GPGGA** - GPS Fix Data (ownship position, altitude)
2. **$GPRMC** - Recommended Minimum Specific GPS Data (ownship position, speed, course)
3. **$GPGSA** - GPS DOP and Active Satellites (satellite info)
4. **$PFLAA** - FLARM Relative Position Data (one sentence per aircraft)
5. **$PFLAU** - FLARM Operating Status (summary of all traffic)
6. **$PGRMZ** - Garmin Altitude (pressure altitude)

**Note:** When multiple aircraft are visible (Phase 4 with paragliders), there will be multiple PFLAA sentences - one for each aircraft. The PFLAU sentence summarizes all traffic.

### PFLAA Sentence Format

```
$PFLAA,<AlarmLevel>,<RelativeNorth>,<RelativeEast>,<RelativeVertical>,
       <IDType>,<ID>,<Track>,<TurnRate>,<GroundSpeed>,<ClimbRate>,<AcftType>
```

**Key Fields:**
- **AlarmLevel:** 0=None, 1=Warning, 2=Alert, 3=Urgent
- **RelativeNorth/East:** Position in meters relative to ownship
- **RelativeVertical:** Altitude difference in meters
- **ID:** Aircraft identifier (40AB21 for glider, A1B2C3/D4E5F6 for paragliders)
- **Track:** Heading in degrees
- **GroundSpeed:** Speed in km/h
- **ClimbRate:** Vertical speed in m/s (decimal format)
- **AcftType:** 1=Glider, 7=Paraglider

### Coordinate System

- **North/South:** Positive North, Negative South
- **East/West:** Positive East, Negative West
- **Altitude:** Meters above ownship (positive = above, negative = below)

### Ownship Position (Fixed)

- **Latitude:** 48°52.5378'S (48.875630°S)
- **Longitude:** 123°23.6000'W (123.393333°W)
- **Altitude:** 500 meters MSL

---

## Visualization on Radar Display

### Phase 1: Approach
The glider appears as a cyan/purple dot (depending on altitude) directly North on the radar screen, moving toward the center. The relative altitude and descent rate are displayed next to the symbol.

### Phase 2: Turn
The glider traces an arc on the radar screen as it turns from North toward East.

### Phase 3: Circling
The glider traces small circles on the radar display, offset to the North. The altitude numbers increase steadily, and the climb rate indicator shows variable positive values (3-5 m/s).

### Phase 4: Departure with Multiple Aircraft
The glider moves steadily toward the East (right side) of the radar screen. When it reaches approximately 3km distance, two paragliders suddenly appear:

**Paraglider 1 (Red/Orange):**
- Appears in the South-West quadrant, very close (~350-370m)
- Red/orange color indicates it's above ownship altitude
- Shows "-1.1" climb rate (sinking)
- Moves slowly North while descending
- Triggers urgent (level 3) alarm due to close proximity

**Paraglider 2 (Green, transitioning to Cyan/Purple):**
- Appears in the North-East quadrant, medium distance (~420-480m)
- Initially green (below ownship), gradually changes color as it climbs
- Traces small 50m radius circles
- Shows variable climb rate (−0.5 to +3.5 m/s)
- Alert (level 2) alarm
- Climbs ~800m over the course of Phase 4, ending at +50m above ownship

**Multi-Aircraft Display:**
- Display now shows 3 aircraft symbols simultaneously
- PFLAU shows "RX:3" indicating 3 aircraft received
- Alarm system prioritizes closest/highest threat (PG1 at level 3)
- Traffic list shows all three aircraft with different colors based on relative altitude

### Phase 5: No Traffic
The radar displays "NO DATA" or returns to showing only ownship information.

---

## Generating Custom Scenarios

The demo file was generated using the Python script `generate_demo_nmea.py` located in the project root directory. You can modify this script to create custom scenarios with different:

- Aircraft types (glider, tow plane, helicopter, paraglider, etc.)
- Flight paths (straight-line, circling, figure-8, etc.)
- Speeds and altitudes
- Multiple aircraft (script now supports this via generate_frame_multi function)
- Climb/descent rates
- Starting positions and distances
- Timing of when aircraft appear/disappear

### Example Modifications:

**Change speed to 150 km/h:**
```python
SPEED_KMH = 150.0
```

**Change circle radius to 150 meters:**
```python
CIRCLE_RADIUS = 150.0
```

**Change aircraft type to powered aircraft (type 8):**
```python
AIRCRAFT_TYPE = 8
```

**Change starting distance to 10 km:**
```python
north_start = 10000.0  # 10km
```

**Add or modify paragliders:**
```python
# Change PG1 position to 1km North instead of SW
pg1_north_start = 1000.0
pg1_east_start = 0.0

# Change PG2 circle radius to 75m
PG2_CIRCLE_RADIUS = 75.0

# Make PG2 climb to 1500m instead of 1000m
if pg2_altitude_start + pg2_cumulative_altitude < 1500.0:
```

**Add a third aircraft:**
Extend the `aircraft_list.append()` pattern in Phase 4 with additional aircraft dictionaries containing position, speed, and behavior parameters.

After modifying the script, run:
```bash
python generate_demo_nmea.py
```

This will regenerate the `data/demo.nmea` file with your custom parameters.

---

## Using Demo Mode

1. **Upload the demo file:**
   - Access the SkyView web interface (device IP address)
   - Navigate to "Demo Mode" page
   - Click "Choose File" and select `demo.nmea`
   - Click "Upload"

2. **Enable demo mode:**
   - Go to Settings page
   - Change "Connection type" dropdown to "Demo File"
   - Click "Update"
   - Device will restart in demo mode

3. **Playback control:**
   - Demo automatically loops when it reaches the end
   - Default line delay: 160ms (adjustable in DemoHelper.h)
   - Maintains ~1 second between $GPGGA sentences

4. **Return to normal operation:**
   - Change "Connection type" back to your normal connection (BLE, WiFi, Serial)
   - Click "Update"

---

## Troubleshooting

**Problem:** Display shows "NO DATA" during demo playback

**Solutions:**
- Verify demo.nmea file was uploaded successfully
- Check that "Demo File" is selected in Connection type
- Ensure demo file contains valid PFLAA sentences
- Restart device after changing connection type

**Problem:** Demo playback is too fast or too slow

**Solution:**
- Edit `src/DemoHelper.h` and adjust `DEFAULT_DEMO_LINE_DELAY_MS`
- Rebuild and upload firmware
- Default: 160ms (creates ~1 second between GPS updates)

**Problem:** Want to download current demo file

**Solution:**
- Go to Demo Mode page in web interface
- Click "Download Current Demo File" button
- File will download as `demo.nmea`

---

## Testing Scenarios with Demo Mode

This demo file is designed to comprehensively test various features of the SkyView AMOLED device. Below are specific features and scenarios that can be validated using this demo:

### Visual Display Testing

#### 1. **Radar Display**
- **Multiple aircraft rendering**: Verify 3 aircraft displayed simultaneously (Phase 4)
- **Color coding by altitude**:
  - PG1: RED/Orange (above ownship)
  - PG2: GREEN transitioning to CYAN/PURPLE (climbing from below to above)
  - Glider: Color based on relative altitude
- **Aircraft symbols**: Different symbols for glider (Type 1) vs paragliders (Type 7)
- **Distance rings**: Verify aircraft positioning on correct range rings
- **Track-Up vs North-Up orientation**: Toggle and verify aircraft rotation

#### 2. **Traffic Info/Text Display**
- **Multi-aircraft list**: All 3 aircraft should appear in scrollable list
- **Altitude display**: Relative altitude with +/− prefix
- **Climb rate display**: Variable rates (-3.0, -1.1, +2.0, etc.)
- **Distance calculation**: Verify distances match radar display
- **Aircraft ID display**: 40AB21, A1B2C3, D4E5F6

#### 3. **Visual Thermal Indicators**
- **Phase 3**: Primary glider circling with 3-5 m/s climb rate
- **Phase 4**: PG2 circling with variable -0.5 to +3.5 m/s
- Verify thermal visualization (if implemented):
  - Circling pattern detection
  - Climb rate averaging over time
  - Visual indicators (circles, colors, animations)

#### 4. **Climb Rate Analysis**
- **Instantaneous climb rate**: Displayed next to each aircraft
  - Glider Phase 1: -3.0 m/s (descending)
  - Glider Phase 3: 3.0-5.0 m/s (variable)
  - PG1: -1.1 m/s (constant sink)
  - PG2: -0.5 to +3.5 m/s (variable thermal)
- **Average climb rate** (if implemented):
  - Phase 3 glider average: ~4.0 m/s
  - PG2 average over time: ~1.5 m/s
- Verify instantaneous vs average climb rate calculations

### Audio Alert Testing (Waveshare with Audio Module)

#### 5. **Alarm Level Progression**
- **Phase 1**: Alarm escalates as glider approaches (0→1→2→3)
- **Phase 4**: Level 3 alarm triggered by PG1 (close proximity ~350-370m)
- Test audio alerts for each alarm level:
  - Level 0: No alarm
  - Level 1: Warning tone
  - Level 2: Alert tone
  - Level 3: Urgent alarm

#### 6. **Voice Announcements** (if configured)
- Traffic callouts with distance and bearing
- Altitude announcements (above/below)
- Climb/descent rate announcements

### Touch/Interaction Testing

#### 7. **Target Selection (Click on Aircraft)**
- Tap on glider symbol → should highlight and show details
- Tap on PG1 → details for sinking paraglider
- Tap on PG2 → details for climbing paraglider
- Verify selected target remains highlighted
- Test deselection (tap elsewhere or same target again)

#### 8. **View Mode Switching**
- Single click button: Cycle through Radar → Traffic Info → Compass
- Swipe gestures: Left/Right to change views
- Verify all views update correctly with 3 aircraft

#### 9. **Settings Access**
- Double-click button: Access settings page
- Long press button: Power options menu
- Verify demo mode continues running after settings changes

### Buddy List Testing

#### 10. **Buddy List Functionality**
Add these IDs to `/buddylist.txt` via web interface:
```
40AB21
A1B2C3
D4E5F6
```

**Expected Behavior:**
- **Glider (40AB21)**: Should display with white blinking dot and initials on radar
- **PG1 (A1B2C3)**: Buddy indicator when it appears in Phase 4
- **PG2 (D4E5F6)**: Buddy indicator with circling thermal pattern

**Test Scenarios:**
- Upload buddy list before starting demo
- Verify buddies are visually distinct from non-buddies
- Check buddy initials/callsigns display correctly
- Test with partial buddy list (only 1 or 2 IDs)

### Advanced Feature Testing

#### 11. **Alarm Priority with Multiple Aircraft**
- Phase 4: Verify closest/highest threat prioritized
- Expected: PG1 (level 3) overrides glider (level 0) and PG2 (level 2)
- PFLAU RX count: Should show "3" aircraft received

#### 12. **Data Expiration**
- Demo loops automatically (tests continuous operation)
- Verify smooth transition from end back to beginning
- No "NO DATA" flashing during loop

#### 13. **Performance/Rendering**
- **14+ minute duration**: Tests sustained operation
- **3 simultaneous aircraft**: Tests rendering performance
- **Variable data rates**: Tests parser with consistent 1Hz updates
- Monitor for:
  - Screen tearing or flicker
  - Memory leaks over time
  - CPU usage/heat generation

#### 14. **Protocol Parsing**
- **NMEA sentence validation**: All sentences have correct checksums
- **Multiple PFLAA sentences**: Up to 3 per frame (one per aircraft)
- **PFLAU summary**: RX count matches number of aircraft
- **Field parsing**: Verify all fields (position, altitude, speed, type) parsed correctly

### Edge Case Testing

#### 15. **Altitude Transitions**
- PG2 crosses zero altitude (below → above ownship)
- Verify color change from GREEN → CYAN/PURPLE
- Test alarm level recalculation based on altitude difference

#### 16. **Close Proximity**
- PG1 approaches ~350m (very close)
- Test level 3 alarm triggers correctly
- Verify visual/audio alerts are prominent

#### 17. **Long Duration Monitoring**
- Run full 14+ minute demo multiple times
- Check for memory stability
- Verify battery consumption is reasonable

---

## Related Documentation

- [Demo Mode User Guide](Demo_Mode_User_Guide.md) - Complete guide to using demo mode
- [SkyView User Manual](SkyView_User_Manual.md) - General device operation
- [CLAUDE.md](../CLAUDE.md) - Technical project overview

---

## Revision History

| Date | Version | Description |
|------|---------|-------------|
| 2025-10-26 | 1.0 | Initial documentation for improved demo scenario with glider circling |
| 2025-10-26 | 1.1 | Added two paragliders in Phase 4: PG1 (sinking, SW, +50m) and PG2 (circling/climbing, NW, -750m). Updated file statistics, aircraft configurations, and multi-aircraft visualization details. |
| 2025-10-26 | 1.2 | Updated PG2 position to 600m North-East (from NW). Changed paraglider appearance to 2km glider distance (from 3km). Set demo duration to 600s total. Added comprehensive "Testing Scenarios with Demo Mode" section covering visual, audio, touch interaction, buddy list, and advanced feature testing. |
