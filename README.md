# arduino-timer-stop-game

A two player Arduino timing game where each player tries to stop a timer as close as possible to a randomly selected target time. 

I built this as I was inspired by different youtube videos and instagram reels where people would do this challernge. 

The game uses two buttons and a monochrome OLED display. At the beginning of each round, the Arduino randomly selects a target time between 1 and 8 seconds. Both players compete against the exact same target.

Great for fun for students in school. I decided to make this because there was no way I was going to buy 2 buttons and a real stopwatch for this, I decided I could just make it at home with what I had :)

Features
- Two player gameplay pvp
- Random target time every round
- Uses only two buttons, minimal materials required
- No external button resistors required

**Uploading the Code**  

1. Open `main.ino` in the Arduino IDE either download from firmware folder the file and open it, or just copy and paste its contents into the ide yourself.  
2. Connect your Arduino to your computer with a USB cable.  
3. Select the correct **Board** and **Port** under **Tools**.  
4. Click **Upload** (→).  
5. Wait for the upload to finish. The Arduino will automatically restart and run the program. 

Bill of Materials

| Item | Quantity | Estimated Price (USD) | Notes |
|---|---:|---:|---|
| Arduino UNO R4 WiFi | 1 | $30.00 | Main microcontroller |
| 0.96 inch OLED SSD1306 I2C | 1 | $3.00 | 128x64 monochrome OLED display |
| Push Button | 2 | $0.50 | Player 1 and Player 2 buttons |
| Breadboard | 1 | $5.00 | For prototyping and wiring |
| Jumper Wires | 1 | $5.00 | For connecting components |
| **Estimated Total** | | **$44.00** | |


 Pin Mapping

| Component | Pin | Arduino UNO R4 |
|---|---|---|
| Player 1 Button | Signal | D2 |
| Player 2 Button | Signal | D3 |
| Player 1 Button | Other Pin | GND |
| Player 2 Button | Other Pin | GND |
| OLED | VCC | 5V |
| OLED | GND | GND |
| OLED | SDA | SDA |
| OLED | SCL | SCL |



Demo link: https://www.youtube.com/watch?v=z8JxR8j9lNo 
