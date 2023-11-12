#Smart-Water-Management-5109
The traditional system to determine water quality is not reliable. It rely on collecting water samples, testing and analyses in water laboratories is costly and time consuming.
Human errors can occur and may not provide accurate result.It lack capability for real-time data capture, analyses and fast dissemination of information to relevant stakeholders for making timely and appropriate decisions.  

In this project, we present a design and development of a system for real time monitoring of the water quality using IoT (internet of things).The system consist of several sensors
are used to measuring physical and chemical parameters of the water. The parameters such as temperature, PH, turbidity, conductivity of the water can be measured.

pH Sensor(SKU:SEN0161):

The pH sensor (SKU: SEN0161/0169) measures the concentration of hydrogen ions. It shows the water is acidic or alkaline. Pure water has 7pH value, less than 7pH has acidic, more 
than 7pH has alkaline. The range of pH is 0-14 ph. For drinking purpose, it should be 6.5-8.5pH. 

pH Sensor Working:

The potassium chloride inside the glass electrode (shown here colored orange) is a neutral solution with a pH of 7, so it contains a certain amount of hydrogen ions (H+). Suppose the unknown solution you're testing (blue) is much more acidic, so it contains a lot more hydrogen ions. What the glass electrode does is to measure the difference in pH between the orange solution and the blue solution by measuring the difference in the voltages their hydrogen ions produce. Since we know the pH of the orange solution (7), we can figure out the pH of the blue solution.
When you dip the two electrodes into the blue test solution, some of the hydrogen ions move toward the outer surface of the glass electrode and replace some of the metal ions inside it, while some of the metal ions move from the glass electrode into the blue solution. This ion-swapping process is called ion exchange, and it's the key to how a glass electrode works. Ion-swapping also takes place on the inside surface of the glass electrode from the orange solution. The two solutions on either side of the glass have different acidity, so a different amount of ion-swapping takes place on the two sides of the glass. This creates a different degree of hydrogen-ion activity on the two surfaces of the glass, which means a different amount of electrical charge builds up on them. This charge difference means a tiny voltage (sometimes called a potential difference, typically a few tens or hundreds of millivolts) appears between the two sides of the glass, which produces a difference in voltage between the silver electrode (5) and the reference electrode (8) that shows up as a measurement on the meter.

Although the meter is measuring voltage, what the pointer on the scale (or digital display) actually shows us is a pH measurement. The bigger the difference in voltage between the orange (inside) and blue (outside) solutions, the bigger the difference in hydrogen ion activity between. If there is more hydrogen ion activity in the blue solution, it's more acidic than the orange solution and the meter shows this as a lower pH; in the same way, if there's less hydrogen ion activity in the blue solution, the meter shows this as a higher pH (more alkaline).

pH Sensor Applications:

pH meters are used for soil measurements in agriculture, water quality for municipal water supplies, swimming pools, environmental remediation; brewing of wine or beer; manufacturing, healthcare and clinical applications such as blood chemistry; and many other applications.

Specifications of pH Sensor:

• Power : 5.00V
• Module Size : 43 x 32mm(1.69x1.26")
• Measuring Range :0 - 14PH
• Measuring Temperature: 0 - 60 deg c
• Accuracy : ± 0.1pH
• Response Time : < 1min
• pH Sensor with BNC Connector
• Gain Adjustment Potentiometer


Turbidity Sensor(SKU: SEN0189):

Turbidity sensor (SKU: SEN0189) is a measure of the degree to which the water loses its transparency due to the presence of suspended particulates. The more total suspended solids in the water, the murkier it seems and the higher the turbidity. 

Working of Turbidity Sensor:

A turbidity probe works by sending a light beam into the water to be tested. This light will then be scattered by any suspended particles.The amount of light reflected is used to determine the particle density within the water. The more light that is detected, the more particles are present in the water.

Turbidity Sensor Applications:

Applications for the turbidity sensors include: water quality testing and management, river monitoring, stream measurement, reservoir water quality testing, groundwater testing, water and wastewater treatment, and effluent and industrial control.The turbidity sensor directs a focused beam into the monitored water.

Specifications of Turbidity Sensor:

Operating Voltage: 3.3VDC ~ 5VDC
Output Method: Analog output
Measurement Range: 0 ~ 1000NTU

TDS Sensor:

This is an Arduino-compatible TDS Meter Kit for measuring TDS value of the water, to reflect the cleanliness of the water. It can be applied to domestic water, hydroponic and other fields of water quality testing.  
TDS (Total Dissolved Solids) indicates that how many milligrams of soluble solids dissolved in one liter of water. In general, the higher the TDS value, the more soluble solids dissolved in water, and the less clean the water is. Therefore, the TDS value can be used as one of the references for reflecting the cleanliness of water.
Temperature sensor (DS18B20) is used to measure the temperature of the water.

TDS sensor Working:

The result is interpreted by the TDS meter and converted into a ppm figure. If water contains no soluble materials and is pure, it will not conduct a charge and will therefore have a 0 ppm figure. Conversely, if the water is full of dissolved materials, it will conduct a charge, with the resulting ppm figure being proportional to the amount of dissolved solids. This is because all dissolved solids have an electrical charge, which allows conduction of electrical charge between the electrodes.	
In reality, the most accurate way to measure TDS of water in a laboratory setting would be to boil the water until there is none remaining, and then to weigh the remaining material. This of course is totally impractical for the lay person, as accurate scales and special equipment would be required to achieve such measurements. The TDS meter is therefore the next best device to achieving an estimated TDS reading.

TDS sensor Applications:

A TDS meter is a small hand-held device used to indicate the Total Dissolved Solids in a solution, usually water. Since dissolved ionized solids, such as salts and minerals, increase the conductivity of a solution, a TDS meter measures the conductivity of the solution and estimates the TDS from that reading.

Specifications of TDS Sensor:

Input Voltage: 3.3 ~ 5.5V
Output Voltage: 0 ~ 2.3V
Working Current: 3 ~ 6mA
TDS Measurement Range: 0 ~ 1000ppm
TDS Measurement Accuracy: ± 10% F.S. (25 ℃)
Module Size: 42 * 32mm

Waterproof Temperature Sensor DS18B20:

The DS18B20 is a 1-wire programmable Temperature sensor from maxim integrated. It is widely used to measure temperature in hard environments like in chemical solutions, mines or soil etc. It can measure a wide range of temperature from -55°C to +125° with a decent accuracy of ±5°C.

Effect of Temperature:

As water temperature increases, the conductivity of water also increases; where TDS in water is directly related to conductivity. For each 1°C increment, conductivity rise by 2–4%.
If you apply this to the temperature of water and its pH level, increasing the temperature of water prompts the equilibrium to lower the temperature again, which involves absorbing additional heat. This creates more hydrogen ions and hydroxide ions, which in return lower the pH of the water.

Specifications of DS18B20 Waterproof Temperature Sensor:

Colour: black
Housing material: stainless steel
Built-in temperature sensor: DS18B20
Supply voltage: 3 V to 5 V
Operating temperature range: -55°C to 125°C
Storage temperature: from -55°C to 125°C
Accuracy: ±0.5°C in temperature range from -10°C to 85°C
Cable length: 1 m
The dimensions of the probe: 6 x 50 mm

The microcontroller will obtain and process the data from the sensors and sent the data to the IoT cloud server (Thingspeak) through Esp32

ESP32:

ESP32 is the big brother of ESP8266. It comes with dual core 32-bit processor, built-in WiFi and Bluetooth, more RAM and Flash memory, more GPIO, more ADC, and many other peripherals. NodeMCU ESP32 is ESP-WROOM-32 module in breadboard friendly form factor, you can develop your project in using this compact microcontroller on breadboard.

Features of ESP32:

NodeMCU based on ESP-WROOM-32 module
Based on ESP32 DEVKIT DOIT
30 GPIO Version
ESP32 is a dual core 32-bit processor with built-in 2.4 GHz Wi-Fi and Bluetooth
4MByte flash memory
520KByte RAM
2.2 tp 3.6V Operating voltage range
In breadboard friendly breakout
USB microB for power and Serial communication, use to load program and serial debugging too


Thingspeak(IoT Platform):

ThingSpeak is an IoT analytics platform service that allows you to aggregate, visualize, and analyze live data streams in the cloud. You can send data to ThingSpeak from your devices, create instant visualization of live data, and send alerts.
There are sensors all around—in our homes, smart phones, automobiles, city infrastructure, and industrial equipment. Sensors detect and measure information on all sorts of things like temperature, humidity, and pressure. And they communicate that data in some form, such as a numerical value or electrical signal.
ThingSpeak provides tools that enable device communication for all of these actions and more. You can:
React to data—both raw data and new data that you calculate—as it comes into a channel
Queue up commands for a device to execute



Applications of Water Quality Monitoring System:

Maintain a continuously healthy water supply
Industrial Waste Cleaning purpose
Fish pond water quality testing
Helpful in saving Aquatic life
