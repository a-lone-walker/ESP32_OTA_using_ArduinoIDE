# Getting Started

> **Important:** Arduino OTA works only after the ESP32 has been flashed **once** using a USB cable. The initial firmware starts the OTA service and makes the ESP32 discoverable on your local network.

---

# Project Structure

```text
ESP32_OTA_using_ArduinoIDE/
│
├── ESP32_OTA_ARDUINO_IDE SETUP/
│   └── ESP32_OTA_ARDUINO_IDE SETUP.ino
│
├── ESP32_OTA_ARDUINO_IDE_LED_BLINKING/
│   └── ESP32_OTA_ARDUINO_IDE_LED_BLINKING.ino
│
└── README.md
```

---

# Step 1: Upload the Setup Sketch (USB Upload)

Open the following sketch:

```text
ESP32_OTA_ARDUINO_IDE SETUP/
└── ESP32_OTA_ARDUINO_IDE SETUP.ino
```

Update your Wi-Fi credentials:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

Connect the ESP32 to your computer using a **USB cable** and upload this sketch.

**This step is mandatory and only needs to be done once.**

The setup sketch:

* Connects the ESP32 to Wi-Fi.
* Starts the Arduino OTA service.
* Makes the ESP32 discoverable on your local network.
* Prints the assigned IP address to the Serial Monitor.

---

# Step 2: Verify the ESP32 is Connected

Open the **Serial Monitor** at **115200 baud**.

You should see output similar to:

```text
Connecting to WiFi...

WiFi Connected

IP Address:
192.168.1.105

Arduino OTA Ready
```

---

# Step 3: Select the Network Port

In Arduino IDE, go to:

```text
Tools
    └── Port
```

After a few seconds, a new **Network Port** should appear.

Example:

```text
ESP32 at 192.168.1.105
```

Select this network port.

> **Important:** From this point onward, all firmware uploads will be performed wirelessly over Wi-Fi.

---

# Step 4: Upload the OTA Test Sketch

Open the OTA test sketch:

```text
ESP32_OTA_ARDUINO_IDE_LED_BLINKING/
└── ESP32_OTA_ARDUINO_IDE_LED_BLINKING.ino
```

Make sure the **Network Port** is still selected.

Click **Upload**.

The Arduino IDE will:

1. Compile the firmware.
2. Send the firmware over Wi-Fi.
3. Flash the ESP32 wirelessly.
4. Restart the ESP32 automatically.

---

# Step 5: Verify the OTA Update

Once the upload completes:

* The ESP32 restarts automatically.
* The onboard LED begins blinking.
* The Serial Monitor displays the updated firmware output.

This confirms that the OTA update was successful.

---

# OTA Development Workflow

For all future firmware updates:

1. Modify your code.
2. Select the ESP32 **Network Port**.
3. Click **Upload**.
4. Wait for the upload to finish.
5. ESP32 restarts automatically.
6. Verify the updated firmware.

No USB cable is required unless:

* Wi-Fi credentials are changed.
* The OTA setup sketch is erased.
* The ESP32 is factory reset.
* The firmware becomes corrupted and can no longer boot.

---

# Workflow Summary

```text
USB Upload (One Time)

        │
        ▼

ESP32_OTA_ARDUINO_IDE SETUP.ino

        │
        ▼

ESP32 Connects to Wi-Fi

        │
        ▼

Arduino OTA Service Starts

        │
        ▼

ESP32 Appears in Arduino IDE
(Network Port)

        │
        ▼

Open

ESP32_OTA_ARDUINO_IDE_LED_BLINKING.ino

        │
        ▼

Click Upload

        │
        ▼

Firmware Sent Over Wi-Fi

        │
        ▼

ESP32 Restarts

        │
        ▼

LED Starts Blinking

        │
        ▼

OTA Working Successfully
```
