# Smartwatch
<p align="justify"> 
  <h2>Open Projects 2021</h2>
  </p>

## Abstract  
<p align="justify"> This smartwatch project largely deals with the exploration of what is Arduino and how it works. A Smartwatch functions both as a watch as well as a miniature size smart phone with limited features. Designing and simulating an Arduino based smartwatch requires a lot of knowledge about the hardware part. But this project was entirely designed and simulated in online mode using various softwares to draw the schematic and simulate it (Proteus), work on the PCB layout (Easy EDA) and finally do a casing for the smartwatch (solidworks).   
 </p>

<p align="justify">
  This watch can be connected to mobile via Bluetooth and it can respond to the commands given via the mobile too. It can also monitor the notifications that we receive in our mobile and alert the user accordingly. Apart from this, it can also show the day-date-time information like a normal digital watch and can also show us the temperature of the medium in which it is kept.
 </p>  
<p align="center">
  <img src="https://github.com/crooknish/Smartwatch/blob/328de0d6db4d20f19190899e9200ea6b46cae17e/Images%20and%20Videos/Images/PCB%203D%20view.jpeg" height = "350px", width="400px"><br>
  <i> Smartwatch PCB 3D Model </i>
  </p>
  

## Motivation
<p align="justify">
This project mainly aimed to create a rough model of a smartwatch that will resemble a typical smartwatch in functioning but, we however optimized the design so that it will also resemble a typical smartwatch in appearance too. However, the ultimate motive of this project was to learn the coding of the Arduino and testing it along with different sensors and modules that are connected to the Arduino. So, we were least bothered about the size of the model that we made at first but when the project arrived at the PCB designing part, our motive extended to space management.
  </p>
  <br>

![workflow](https://github.com/crooknish/Smartwatch/blob/328de0d6db4d20f19190899e9200ea6b46cae17e/Images%20and%20Videos/Images/Workflow.jpeg)

## Mechanical Aspect of the Design
<p align="justify"> 
  For the smart watch, we made a case to protect it from external damage from scratches, any accidental drops or damage to its hardware by any means. It also makes it look good. As we are limited to work in this online environment, we have designed a virtual case in <b> Solidworks</b>.   
The case is a 51mm x 51mm x 20mm cuboid made of PVC. It is designed such that it has it has holes for the OLED pins to be attached as well as for the keys to be placed. Also, it has base which is also made of PVC and can be fastened with the case using screws. 
  </p>
<p align="center"> 
  <img src="https://github.com/crooknish/Smartwatch/blob/328de0d6db4d20f19190899e9200ea6b46cae17e/Images%20and%20Videos/Images/case.jpeg" > <br>
  <i> 3D Case </i><br><br>
  <img src ="https://github.com/crooknish/Smartwatch/blob/19d6efc3654f7e7757a4fd50ef805bb6503ef1a1/Images%20and%20Videos/Images/Case-Front%20side.png" height ="300px" width ="300px" alt ="case-front side">  <img src ="https://github.com/crooknish/Smartwatch/blob/19d6efc3654f7e7757a4fd50ef805bb6503ef1a1/Images%20and%20Videos/Images/Case-Back%20side.png" height ="300px" width ="300px" alt ="case-back side">
  </p><br>
  

## Electronic Aspect of the Design
### Components used
#### Microcontroller  
   - Arduino Nano is used for simulation in proteus.  
   - Arduino micro was used in PCB layout (to minimize space usage).
#### Real Time Clock [RTC] (DS 3231)
   - Low-cost
   - Long term accuracy
   - Separate backup battery
   - works on I2C protocol is sensor is ±0.5°C.

#### Temperature Sensor (DS 18B20)
   - The accuracy of this sensor is ±0.5°C.
   - Range is -55oC to +125oC
   - It communicates over a 1-Wire bus.

#### OLED Display 
   - Adafruit SSD-1306 [128x64] pixel
   - Very readable due to the high contrast of an OLED display.
   - No backlight is required
   
#### 	Bluetooth Module (HC 05) 
   - The device uses UART. 
   - The module can act as both master and slave.
   - It consumes less power as compared to wi-fi module

#### 	Buzzer
   - Used to notify us about messages and alarms.
   - Codable and cheap, with less power consumption.

#### 	Push Buttons
   - Used to power up and break the circuit enabling to switch between different Menu Bar

![schematic in proteus](https://github.com/crooknish/Smartwatch/blob/328de0d6db4d20f19190899e9200ea6b46cae17e/Images%20and%20Videos/Images/smartwach_proteus_simulation.JPG)
 <p align="center"> <i> Schematic in Proteus</i> </p>
 
### PCB Layout
<p align="justify"> PCB designing in EasyEDA involves drawing the schematic with modules and sensors that have a properly defined footprint.   

The next step is to design a PCB layout using the schematic. Here is where, using EasyEDA was advantageous. In this software, this can be done by simply converting the schematic to layout.   

After converting the schematic to PCB layout, the real task begins. Keeping the size of the watch in mind and placing all the components was really challenging. After designing the layout, the 2D and 3D views were projected to verify whether the components overlap or interfere with each other.  </p>

<p align="center">
  <img src="https://github.com/crooknish/Smartwatch/blob/328de0d6db4d20f19190899e9200ea6b46cae17e/Images%20and%20Videos/Images/PCB%20Layout.jpeg"></br>
   <i> PCB Layout </i><br><br>
  <img src="https://github.com/crooknish/Smartwatch/blob/328de0d6db4d20f19190899e9200ea6b46cae17e/Images%20and%20Videos/Images/PCB-Top%20view.png" height ="300px" width ="300px" alt="PCB top view">    <img src="https://github.com/crooknish/Smartwatch/blob/19d6efc3654f7e7757a4fd50ef805bb6503ef1a1/Images%20and%20Videos/Images/PCB%20-%20Bottom%20view.png" height ="300px" width ="300px" alt="PCB bottom view"><br>

  </p>

 
 
 ### BATTERY MANAGEMENT SYSTEM (BMS)
 <p align="justify"> 
  <b>Why use BMS:</b> Battery management system (BMS) are electronic control circuits that monitor and regulate the charging and discharge of batteries.
The battery characteristics to be monitored include the detection of battery type, voltages, temperature, capacity, state of charge, power consumption, remaining operating time charging cycles, etc.  
</p>

<p align="justify"> 
  <b>Task :</b> The task of BMS is to ensure the optimal use of the residual energy present in a battery, in order to avoid loading the batteries, BMS protect the batteries from deep discharge, from over-voltage, which are results to extreme fast charge and extreme high discharge current. In the case of multicell batteries, the battery management system also provides for cell balancing function, to manage that different battery cells have the same charging and discharging requirements.   
  </p>
 

<p align="justify">
  <b>Charge protection IC’s :</b> For portable devices are offered featuring a withstand voltage up to 28V and multiple built-in protection circuits, including overvoltage lockout, over current limiter, undervoltage malfunction prevention, startup delay, and status flag, that provide the necessary protection for smart watch and other power consumer products. </p>

#### Battery Charging System 
<p align="justify"> One of the basic tasks in the battery charge is the regulation of battery voltage and current without exceeding the temperature limits. This requires a control loop that involves measurement of the battery parameters (like- voltages, current, and temperature) and controlling the PWM (Pulse Width Modulation) duty cycle that drives the external power network. PSOC (programmable system on a chip) with its precision ADC (Analog-to-Digital Converter) (max 14bits) – implemented using its analog blocks, PWM- implemented using its digital blocks and a processor core forms such a control loop required for regulation. Other algorithms like cell balancing can be implemented using a firmware logic.
</p>

#### Secondary Battery - LiPo/Li-ion battery

    -	High Cell Voltage (3.7V under Load)
    -	Lightweight, High power Density
    -	Output capability better than other (like- LEAD TYPE, NiMH, etc.)
    -	Higher power to size ratio
   
## How to simulate smartwatch in proteus
  - Install proteus and arduino IDE and all the required libraries.
  - Make the arrangement of all component according to the schematic.
  - Copy the code kept in src folder to the arduino and compile it.
  - Now copy the hex file location after compiling and paste it in edit component of arduino nano in Proteus.
  - Now run the simulation.

## Cost Structure
| Components  | Cost (in Rupees) |
| ------------- | ------------- |
| Arduino Nano  | 1500  |
| Real Time Clock [RTC] (DS 3231)  | 250  |
| Temperature Sensor (DS 18B20)  | 100  |
| OLED Display (Adafruit SSD-1306 [128x64] pixel)  | 250  |
| Bluetooth Module (HC 05)  | 250  |
| Buzzer  | 20  |
| Push Buttons (x3)  | 50   |
| Li ion Battery  | 270  |
| PCB designing  | 250  |
| 3D printed Casing  | 200  |
| Net Expected Cost  | 3090  |

## Applications
<p align="justify">
  1. This smart watch functions just like other smart watches in the market. It shows us time, connects with the phone and alerts us if we receive notifications of any kind (call, messages, Whatsapp etc.).<br>
2. Another practical application is it measures the temperature of the surroundings where we are in. This could be useful for a lot of purposes. <br>
3. Another common feature  in a watch is alarm. Alarms form an integral part of our life. They act as reminders, wake us in the morning or when we take a break/nap during our routine etc. The buzzer in the smartwatch does this purpose.
  </p>

## Limitations
<p align="justify">
  1. One of the main limitations of the project is about the simulation environment. We didn’t have all the required features and components for simulating all the required components in a single software. This has made us to look for different alternatives like initially we started with tinkercad, then moved to Proteus 8 for simulating the hardware part of the smartwatch. For PCB designing, as we didn’t find all the required components in Proteus 8, we had to depend on EasyEDA for PCB designing. <br>
2. Also, the Proteus 8 was not able to simulate the alarm feature that we added. Mostly the fault lies with the simulation software as ARUINO IDE didn’t show any kind of errors while compiling it. <br>
3. We did think of add a lot of features like heartbeat sensor etc., but these components weren’t available for simulation in Proteus 8.
  </p>

## Future Improvement  
<p align="justify"> 
  1. We can make our own processing board in place of arduino nano by using ATMEGA-328P processor. This will reduce the cost and space occupied. <br>
2. A feature like finding phone through our smartwatch can be added to it. Our smartwatch will send instructions to start ringing the phone so that we can find it easily.
  </p>

## Team Members
1. [Abhijith Reddy Dasari](https://github.com/Abhijithreddydasari)
2. [Nishant Kumar](https://github.com/crooknish)
3. [Diwahar H](https://github.com/Diwa-060603)
4. [Karan Saharan](https://github.com/KaranSaharan91)

## Mentor
1. [Sanjeev Krishnan R](https://github.com/SanjeevKrishnan)

## References
  - [SolidWorks](	https://www.solidworks.com/)
  - [Downloading Proteus Libraries](https://www.youtube.com/watch?v=A2KrMkxZQmw&t=138s)
  - [OLED Display tutorial](https://lastminuteengineers.com/oled-display-arduino-tutorial/)
  - [EasyEda](https://easyeda.com/)
  - [PCB Designing Tutorial](https://www.youtube.com/watch?v=tKZCE2DGuas&list=PLE1qlkmzXrwSp1nBlkF8qCC2p2mUKT9Y0)
  
  
