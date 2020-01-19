EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 6 15
Title "MCU3"
Date "2020-01-19"
Rev "1.0"
Comp ""
Comment1 "Verification done."
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	7350 6850 7350 6900
Wire Wire Line
	7350 6900 7450 6900
Wire Wire Line
	7750 6900 7750 6850
Wire Wire Line
	7650 6850 7650 6900
Connection ~ 7650 6900
Wire Wire Line
	7650 6900 7750 6900
Wire Wire Line
	7550 6850 7550 6900
Connection ~ 7550 6900
Wire Wire Line
	7550 6900 7650 6900
Wire Wire Line
	7450 6850 7450 6900
Connection ~ 7450 6900
Wire Wire Line
	7450 6900 7550 6900
$Comp
L ETH1CLCR1:DGNDF #PWR?
U 1 1 5E29D787
P 7550 6950
AR Path="/5DF36C25/5E29D787" Ref="#PWR?"  Part="1" 
AR Path="/5E29C232/5E29D787" Ref="#PWR?"  Part="1" 
AR Path="/5DF38F82/5E29D787" Ref="#PWR0606"  Part="1" 
F 0 "#PWR0606" H 7550 6700 50  0001 C CNN
F 1 "DGNDF" H 7555 6777 50  0000 C CNN
F 2 "" H 7550 6950 50  0001 C CNN
F 3 "" H 7550 6950 50  0001 C CNN
	1    7550 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 6950 7550 6900
Wire Wire Line
	7300 3150 7300 3100
Wire Wire Line
	7300 3100 7400 3100
Wire Wire Line
	7800 3100 7800 3150
Wire Wire Line
	7700 3150 7700 3100
Connection ~ 7700 3100
Wire Wire Line
	7700 3100 7800 3100
Wire Wire Line
	7600 3150 7600 3100
Connection ~ 7600 3100
Wire Wire Line
	7600 3100 7700 3100
Wire Wire Line
	7500 3150 7500 3100
Connection ~ 7500 3100
Wire Wire Line
	7500 3100 7550 3100
Wire Wire Line
	7400 3150 7400 3100
Connection ~ 7400 3100
Wire Wire Line
	7400 3100 7500 3100
Wire Wire Line
	7550 3050 7550 3100
Connection ~ 7550 3100
Wire Wire Line
	7550 3100 7600 3100
$Comp
L Device:R R?
U 1 1 5E29D7A6
P 13300 6450
AR Path="/5DF36C25/5E29D7A6" Ref="R?"  Part="1" 
AR Path="/5E29C232/5E29D7A6" Ref="R?"  Part="1" 
AR Path="/5DF38F82/5E29D7A6" Ref="R603"  Part="1" 
F 0 "R603" H 13370 6496 50  0000 L CNN
F 1 "10k" H 13370 6405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 13230 6450 50  0001 C CNN
F 3 "~" H 13300 6450 50  0001 C CNN
	1    13300 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	13300 6300 13300 6250
Wire Wire Line
	13300 6250 13200 6250
$Comp
L ETH1CLCR1:DGNDF #PWR?
U 1 1 5E29D7AE
P 13300 6650
AR Path="/5DF36C25/5E29D7AE" Ref="#PWR?"  Part="1" 
AR Path="/5E29C232/5E29D7AE" Ref="#PWR?"  Part="1" 
AR Path="/5DF38F82/5E29D7AE" Ref="#PWR0613"  Part="1" 
F 0 "#PWR0613" H 13300 6400 50  0001 C CNN
F 1 "DGNDF" H 13305 6477 50  0000 C CNN
F 2 "" H 13300 6650 50  0001 C CNN
F 3 "" H 13300 6650 50  0001 C CNN
	1    13300 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	13300 6650 13300 6600
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J?
U 1 1 5E74C1A0
P 10500 10350
AR Path="/5DCED281/5E74C1A0" Ref="J?"  Part="1" 
AR Path="/5DF35BC8/5E74C1A0" Ref="J?"  Part="1" 
AR Path="/5E29C232/5E74C1A0" Ref="J?"  Part="1" 
AR Path="/5DF38F82/5E74C1A0" Ref="J601"  Part="1" 
F 0 "J601" H 10550 10767 50  0000 C CNN
F 1 "20021111-00010T4LF" H 10550 10676 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_2x05_P1.27mm_Vertical" H 10500 10350 50  0001 C CNN
F 3 "~" H 10500 10350 50  0001 C CNN
	1    10500 10350
	1    0    0    -1  
$EndComp
NoConn ~ 10300 10450
NoConn ~ 10300 10550
Wire Wire Line
	10300 10350 10000 10350
Wire Wire Line
	10000 10350 10000 10250
Wire Wire Line
	10000 10250 10300 10250
Wire Wire Line
	10000 10600 10000 10350
Connection ~ 10000 10350
Wire Wire Line
	10000 10050 10000 10150
Wire Wire Line
	10000 10150 10300 10150
Wire Wire Line
	10800 10150 11250 10150
Text Label 11250 10150 2    50   ~ 0
TMS_SWDIO
Wire Wire Line
	10800 10250 11250 10250
Text Label 11250 10250 2    50   ~ 0
TCK_SWCLK
Wire Wire Line
	10800 10550 11250 10550
Text Label 11250 10550 2    50   ~ 0
MCU_NRST
$Comp
L ETH1CLCR1:DGNDF #PWR?
U 1 1 5E74C1B5
P 10000 10600
AR Path="/5DF35BC8/5E74C1B5" Ref="#PWR?"  Part="1" 
AR Path="/5E29C232/5E74C1B5" Ref="#PWR?"  Part="1" 
AR Path="/5DF38F82/5E74C1B5" Ref="#PWR0612"  Part="1" 
F 0 "#PWR0612" H 10000 10350 50  0001 C CNN
F 1 "DGNDF" H 10005 10427 50  0000 C CNN
F 2 "" H 10000 10600 50  0001 C CNN
F 3 "" H 10000 10600 50  0001 C CNN
	1    10000 10600
	1    0    0    -1  
$EndComp
NoConn ~ 10800 10350
NoConn ~ 10800 10450
$Comp
L Device:Crystal Y?
U 1 1 5E7594B4
P 15000 5150
AR Path="/5DCED281/5E7594B4" Ref="Y?"  Part="1" 
AR Path="/5E29C232/5E7594B4" Ref="Y?"  Part="1" 
AR Path="/5DF38F82/5E7594B4" Ref="Y601"  Part="1" 
F 0 "Y601" V 14954 5281 50  0000 L CNN
F 1 "NX3225GD-8MHZ-STD-CRA-3" V 15045 5281 50  0000 L CNN
F 2 "ETH1CLCR1:NX3225GD" H 15000 5150 50  0001 C CNN
F 3 "~" H 15000 5150 50  0001 C CNN
	1    15000 5150
	0    -1   1    0   
$EndComp
Wire Wire Line
	13650 5350 15000 5350
Wire Wire Line
	15000 5350 15000 5300
Wire Wire Line
	15000 5000 15000 4950
$Comp
L Device:C C?
U 1 1 5E7594BE
P 15000 5550
AR Path="/5DCED281/5E7594BE" Ref="C?"  Part="1" 
AR Path="/5E29C232/5E7594BE" Ref="C?"  Part="1" 
AR Path="/5DF38F82/5E7594BE" Ref="C611"  Part="1" 
F 0 "C611" H 15115 5596 50  0000 L CNN
F 1 "8p" H 15115 5505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 15038 5400 50  0001 C CNN
F 3 "~" H 15000 5550 50  0001 C CNN
	1    15000 5550
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5E7594C4
P 15500 5550
AR Path="/5DCED281/5E7594C4" Ref="C?"  Part="1" 
AR Path="/5E29C232/5E7594C4" Ref="C?"  Part="1" 
AR Path="/5DF38F82/5E7594C4" Ref="C612"  Part="1" 
F 0 "C612" H 15615 5596 50  0000 L CNN
F 1 "8p" H 15615 5505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 15538 5400 50  0001 C CNN
F 3 "~" H 15500 5550 50  0001 C CNN
	1    15500 5550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	15000 5400 15000 5350
Connection ~ 15000 5350
Wire Wire Line
	15000 4950 15500 4950
Wire Wire Line
	15500 4950 15500 5400
Connection ~ 15000 4950
Wire Wire Line
	15500 5700 15500 5750
Wire Wire Line
	15500 5750 15250 5750
Wire Wire Line
	15000 5750 15000 5700
Wire Wire Line
	15250 5800 15250 5750
Connection ~ 15250 5750
Wire Wire Line
	15250 5750 15000 5750
Wire Wire Line
	13200 5050 13650 5050
$Comp
L Device:R R604
U 1 1 5E7616EE
P 14150 5750
F 0 "R604" H 14080 5704 50  0000 R CNN
F 1 "10k" H 14080 5795 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 14080 5750 50  0001 C CNN
F 3 "~" H 14150 5750 50  0001 C CNN
	1    14150 5750
	-1   0    0    1   
$EndComp
$Comp
L Memory_EEPROM:24LC08 U?
U 1 1 5E76F022
P 8000 10300
AR Path="/5DCED281/5E76F022" Ref="U?"  Part="1" 
AR Path="/5E29C232/5E76F022" Ref="U?"  Part="1" 
AR Path="/5DF38F82/5E76F022" Ref="U602"  Part="1" 
F 0 "U602" H 8350 10650 50  0000 C CNN
F 1 "24LC08B-E/MS" H 8350 10550 50  0000 C CNN
F 2 "Package_SO:MSOP-8_3x3mm_P0.65mm" H 8000 10300 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21710J.pdf" H 8000 10300 50  0001 C CNN
	1    8000 10300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 10200 7550 10200
Wire Wire Line
	7550 10200 7550 10300
Wire Wire Line
	7550 10400 7600 10400
Wire Wire Line
	7550 10600 7550 10400
Connection ~ 7550 10400
Wire Wire Line
	7600 10300 7550 10300
Connection ~ 7550 10300
Wire Wire Line
	7550 10300 7550 10400
Wire Wire Line
	8400 10400 8900 10400
Text Label 8900 10400 2    50   ~ 0
EEPROM_WP
Text Label 8900 10300 2    50   ~ 0
EEPROM_SCL
Text Label 8900 10200 2    50   ~ 0
EEPROM_SDA
$Comp
L Device:R R?
U 1 1 5E76F046
P 8950 10000
AR Path="/5DCED281/5E76F046" Ref="R?"  Part="1" 
AR Path="/5E29C232/5E76F046" Ref="R?"  Part="1" 
AR Path="/5DF38F82/5E76F046" Ref="R601"  Part="1" 
F 0 "R601" H 9020 10046 50  0000 L CNN
F 1 "4k7" H 9020 9955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 8880 10000 50  0001 C CNN
F 3 "~" H 8950 10000 50  0001 C CNN
	1    8950 10000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E76F04C
P 9300 10000
AR Path="/5DCED281/5E76F04C" Ref="R?"  Part="1" 
AR Path="/5E29C232/5E76F04C" Ref="R?"  Part="1" 
AR Path="/5DF38F82/5E76F04C" Ref="R602"  Part="1" 
F 0 "R602" H 9370 10046 50  0000 L CNN
F 1 "4k7" H 9370 9955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9230 10000 50  0001 C CNN
F 3 "~" H 9300 10000 50  0001 C CNN
	1    9300 10000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 10200 8950 10150
Wire Wire Line
	8400 10200 8950 10200
Wire Wire Line
	9300 10300 9300 10150
Wire Wire Line
	8400 10300 9300 10300
Wire Wire Line
	8950 9850 8950 9800
Wire Wire Line
	8950 9800 9300 9800
Wire Wire Line
	9300 9800 9300 9850
Wire Wire Line
	9300 9750 9300 9800
Connection ~ 9300 9800
$Comp
L ETH1CLCR1:DGNDF #PWR0609
U 1 1 5E77122F
P 8000 10600
F 0 "#PWR0609" H 8000 10350 50  0001 C CNN
F 1 "DGNDF" H 8005 10427 50  0000 C CNN
F 2 "" H 8000 10600 50  0001 C CNN
F 3 "" H 8000 10600 50  0001 C CNN
	1    8000 10600
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:DGNDF #PWR0607
U 1 1 5E7714DB
P 7550 10600
F 0 "#PWR0607" H 7550 10350 50  0001 C CNN
F 1 "DGNDF" H 7555 10427 50  0000 C CNN
F 2 "" H 7550 10600 50  0001 C CNN
F 3 "" H 7550 10600 50  0001 C CNN
	1    7550 10600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 9950 8000 10000
$Comp
L Device:C C609
U 1 1 5E776A2B
P 13400 5650
F 0 "C609" V 13148 5650 50  0000 C CNN
F 1 "2u2" V 13239 5650 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 13438 5500 50  0001 C CNN
F 3 "~" H 13400 5650 50  0001 C CNN
	1    13400 5650
	0    1    1    0   
$EndComp
Wire Wire Line
	13250 5650 13200 5650
$Comp
L ETH1CLCR1:DGNDF #PWR0617
U 1 1 5E77E2A8
P 15250 5800
F 0 "#PWR0617" H 15250 5550 50  0001 C CNN
F 1 "DGNDF" H 15255 5627 50  0000 C CNN
F 2 "" H 15250 5800 50  0001 C CNN
F 3 "" H 15250 5800 50  0001 C CNN
	1    15250 5800
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:DGNDF #PWR0614
U 1 1 5E77E4B3
P 13600 5650
F 0 "#PWR0614" H 13600 5400 50  0001 C CNN
F 1 "DGNDF" V 13605 5522 50  0000 R CNN
F 2 "" H 13600 5650 50  0001 C CNN
F 3 "" H 13600 5650 50  0001 C CNN
	1    13600 5650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	13600 5650 13550 5650
NoConn ~ 13200 5350
NoConn ~ 13200 5250
Wire Wire Line
	13200 3850 13700 3850
Text Label 13700 3850 2    50   ~ 0
EEPROM_WP
Text Label 13700 3950 2    50   ~ 0
EEPROM_SCL
Text Label 13700 4050 2    50   ~ 0
EEPROM_SDA
Wire Wire Line
	13200 4050 13700 4050
Wire Wire Line
	13200 3950 13700 3950
Wire Wire Line
	1900 4650 1450 4650
Text Label 1450 4650 0    50   ~ 0
TMS_SWDIO
Wire Wire Line
	1900 4750 1450 4750
Text Label 1450 4750 0    50   ~ 0
TCK_SWCLK
Wire Wire Line
	13200 4950 15000 4950
Wire Wire Line
	13650 5050 13650 5350
$Comp
L Device:C C610
U 1 1 5E7B49DC
P 14150 6150
F 0 "C610" H 14265 6196 50  0000 L CNN
F 1 "100n" H 14265 6105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 14188 6000 50  0001 C CNN
F 3 "~" H 14150 6150 50  0001 C CNN
	1    14150 6150
	1    0    0    -1  
$EndComp
Text Label 13650 5950 2    50   ~ 0
MCU_NRST
Wire Wire Line
	14150 6000 14150 5950
Wire Wire Line
	13200 5950 14150 5950
Connection ~ 14150 5950
Wire Wire Line
	14150 5950 14150 5900
$Comp
L ETH1CLCR1:DGNDF #PWR?
U 1 1 5E7BFF4D
P 14150 6300
AR Path="/5DF36C25/5E7BFF4D" Ref="#PWR?"  Part="1" 
AR Path="/5E29C232/5E7BFF4D" Ref="#PWR?"  Part="1" 
AR Path="/5DF38F82/5E7BFF4D" Ref="#PWR0616"  Part="1" 
F 0 "#PWR0616" H 14150 6050 50  0001 C CNN
F 1 "DGNDF" H 14155 6127 50  0000 C CNN
F 2 "" H 14150 6300 50  0001 C CNN
F 3 "" H 14150 6300 50  0001 C CNN
	1    14150 6300
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:STM32F413RGT6Tx U601
U 1 1 5DD8B08C
P 7550 5000
F 0 "U601" H 2050 6800 50  0000 C CNN
F 1 "STM32F413RGT6Tx" H 12750 6800 50  0000 C CNN
F 2 "Package_QFP:LQFP-64_10x10mm_P0.5mm" H 850 4400 50  0001 C CNN
F 3 "" H 850 4400 50  0001 C CNN
	1    7550 5000
	1    0    0    -1  
$EndComp
Text HLabel 13250 3450 2    50   Output ~ 0
DDS_FGEN_~FSYNC
Text HLabel 1850 4350 0    50   Output ~ 0
DDS_FGEN_SDATA
Text HLabel 13250 3350 2    50   Output ~ 0
DDS_FGEN_SCLK
Wire Wire Line
	13250 3350 13200 3350
Wire Wire Line
	1850 4350 1900 4350
NoConn ~ 1900 4550
Text HLabel 13250 4450 2    50   Output ~ 0
DDS_MDAC_~SYNC
Text HLabel 13250 4550 2    50   Output ~ 0
DDS_MDAC_SCLK
Text HLabel 1850 3450 0    50   Output ~ 0
DDS_MDAC_DIN
Wire Wire Line
	13250 4550 13200 4550
Wire Wire Line
	1850 3450 1900 3450
Wire Wire Line
	13250 4450 13200 4450
Wire Wire Line
	13250 3450 13200 3450
Text HLabel 1850 4850 0    50   Output ~ 0
DDS_DAC_~SYNC
Text HLabel 1850 3850 0    50   Output ~ 0
DDS_DAC_SCLK
Text HLabel 1850 4050 0    50   Output ~ 0
DDS_DAC_SDIN
Wire Wire Line
	1850 3850 1900 3850
Wire Wire Line
	1850 4050 1900 4050
NoConn ~ 1900 5250
Wire Wire Line
	1900 6150 1850 6150
Wire Wire Line
	1900 6250 1850 6250
Wire Wire Line
	1900 6050 1850 6050
Text HLabel 1850 6050 0    50   Input ~ 0
MCU3_SCLK
Wire Wire Line
	1900 3750 1850 3750
Text HLabel 1850 3750 0    50   Input ~ 0
MCU3_NSS
Text HLabel 1850 3650 0    50   Output ~ 0
DDS_DAC_~RESET
Text HLabel 1850 3550 0    50   Output ~ 0
DDS_DAC_~LDAC
Text HLabel 1850 3350 0    50   Output ~ 0
DDS_DAC_RSTSEL
Wire Wire Line
	1850 4850 1900 4850
Wire Wire Line
	1850 3650 1900 3650
Wire Wire Line
	1850 3550 1900 3550
Wire Wire Line
	1850 3350 1900 3350
NoConn ~ 1900 4450
Text HLabel 1850 4150 0    50   Output ~ 0
DDS_FGEN_PSEL0
Text HLabel 1850 4250 0    50   Output ~ 0
DDS_FGEN_PSEL1
Text HLabel 1850 3950 0    50   Input ~ 0
DDS_DAC_SDO
Wire Wire Line
	1850 3950 1900 3950
Wire Wire Line
	1850 4250 1900 4250
Wire Wire Line
	1900 4150 1850 4150
Text HLabel 13250 3550 2    50   Output ~ 0
DDS_FGEN_FSELECT
Wire Wire Line
	13250 3550 13200 3550
NoConn ~ 13200 3650
NoConn ~ 13200 3750
NoConn ~ 13200 4150
NoConn ~ 13200 4650
NoConn ~ 13200 4750
NoConn ~ 1900 6350
NoConn ~ 1900 6550
NoConn ~ 1900 5550
NoConn ~ 1900 5450
NoConn ~ 1900 5150
NoConn ~ 1900 5050
$Comp
L Device:C C601
U 1 1 5E0C93AD
P 950 10500
F 0 "C601" H 1065 10546 50  0000 L CNN
F 1 "100n" H 1065 10455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 988 10350 50  0001 C CNN
F 3 "~" H 950 10500 50  0001 C CNN
	1    950  10500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C602
U 1 1 5E0CAC52
P 1450 10500
F 0 "C602" H 1565 10546 50  0000 L CNN
F 1 "100n" H 1565 10455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1488 10350 50  0001 C CNN
F 3 "~" H 1450 10500 50  0001 C CNN
	1    1450 10500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C603
U 1 1 5E0CAEC5
P 1950 10500
F 0 "C603" H 2065 10546 50  0000 L CNN
F 1 "100n" H 2065 10455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1988 10350 50  0001 C CNN
F 3 "~" H 1950 10500 50  0001 C CNN
	1    1950 10500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C604
U 1 1 5E0CB1FC
P 2450 10500
F 0 "C604" H 2565 10546 50  0000 L CNN
F 1 "100n" H 2565 10455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2488 10350 50  0001 C CNN
F 3 "~" H 2450 10500 50  0001 C CNN
	1    2450 10500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C605
U 1 1 5E0CB50D
P 2950 10500
F 0 "C605" H 3065 10546 50  0000 L CNN
F 1 "100n" H 3065 10455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2988 10350 50  0001 C CNN
F 3 "~" H 2950 10500 50  0001 C CNN
	1    2950 10500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C606
U 1 1 5E0CB78E
P 3450 10500
F 0 "C606" H 3565 10546 50  0000 L CNN
F 1 "100n" H 3565 10455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3488 10350 50  0001 C CNN
F 3 "~" H 3450 10500 50  0001 C CNN
	1    3450 10500
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  10350 950  10300
Wire Wire Line
	3450 10300 3450 10350
Wire Wire Line
	2950 10350 2950 10300
Connection ~ 2950 10300
Wire Wire Line
	2950 10300 3450 10300
Wire Wire Line
	950  10300 1450 10300
Wire Wire Line
	2450 10350 2450 10300
Connection ~ 2450 10300
Wire Wire Line
	2450 10300 2950 10300
Wire Wire Line
	1950 10350 1950 10300
Connection ~ 1950 10300
Wire Wire Line
	1450 10350 1450 10300
Connection ~ 1450 10300
Wire Wire Line
	1450 10300 1950 10300
Wire Wire Line
	950  10650 950  10700
Wire Wire Line
	950  10700 1450 10700
Wire Wire Line
	3450 10700 3450 10650
Wire Wire Line
	2950 10650 2950 10700
Connection ~ 2950 10700
Wire Wire Line
	2950 10700 3450 10700
Wire Wire Line
	2450 10650 2450 10700
Connection ~ 2450 10700
Wire Wire Line
	2450 10700 2950 10700
Wire Wire Line
	1950 10650 1950 10700
Connection ~ 1950 10700
Wire Wire Line
	1450 10650 1450 10700
Connection ~ 1450 10700
Wire Wire Line
	1450 10700 1950 10700
$Comp
L ETH1CLCR1:DGNDF #PWR0602
U 1 1 5E107792
P 2450 10750
F 0 "#PWR0602" H 2450 10500 50  0001 C CNN
F 1 "DGNDF" H 2455 10577 50  0000 C CNN
F 2 "" H 2450 10750 50  0001 C CNN
F 3 "" H 2450 10750 50  0001 C CNN
	1    2450 10750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 10750 2450 10700
Wire Wire Line
	2450 10250 2450 10300
$Comp
L Device:C C608
U 1 1 5DEC46E0
P 4500 10500
F 0 "C608" H 4615 10546 50  0000 L CNN
F 1 "100n" H 4615 10455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4538 10350 50  0001 C CNN
F 3 "~" H 4500 10500 50  0001 C CNN
	1    4500 10500
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:DGNDF #PWR0604
U 1 1 5DEC5F6E
P 4500 10750
F 0 "#PWR0604" H 4500 10500 50  0001 C CNN
F 1 "DGNDF" H 4505 10577 50  0000 C CNN
F 2 "" H 4500 10750 50  0001 C CNN
F 3 "" H 4500 10750 50  0001 C CNN
	1    4500 10750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 10750 4500 10650
Wire Wire Line
	4500 10250 4500 10350
Text HLabel 1850 5650 0    50   Output ~ 0
ANALOG_SWITCH
Wire Wire Line
	1850 5650 1900 5650
$Comp
L ETH1CLCR1:+3.3VF #PWR0601
U 1 1 5E94700D
P 2450 10250
F 0 "#PWR0601" H 2450 10100 50  0001 C CNN
F 1 "+3.3VF" H 2465 10423 50  0000 C CNN
F 2 "" H 2450 10250 50  0001 C CNN
F 3 "" H 2450 10250 50  0001 C CNN
	1    2450 10250
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+3.3VF #PWR0603
U 1 1 5E9476B2
P 4500 10250
F 0 "#PWR0603" H 4500 10100 50  0001 C CNN
F 1 "+3.3VF" H 4515 10423 50  0000 C CNN
F 2 "" H 4500 10250 50  0001 C CNN
F 3 "" H 4500 10250 50  0001 C CNN
	1    4500 10250
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+3.3VF #PWR0608
U 1 1 5E94791E
P 8000 9950
F 0 "#PWR0608" H 8000 9800 50  0001 C CNN
F 1 "+3.3VF" H 8015 10123 50  0000 C CNN
F 2 "" H 8000 9950 50  0001 C CNN
F 3 "" H 8000 9950 50  0001 C CNN
	1    8000 9950
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+3.3VF #PWR0610
U 1 1 5E949139
P 9300 9750
F 0 "#PWR0610" H 9300 9600 50  0001 C CNN
F 1 "+3.3VF" H 9315 9923 50  0000 C CNN
F 2 "" H 9300 9750 50  0001 C CNN
F 3 "" H 9300 9750 50  0001 C CNN
	1    9300 9750
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+3.3VF #PWR0611
U 1 1 5E9493FF
P 10000 10050
F 0 "#PWR0611" H 10000 9900 50  0001 C CNN
F 1 "+3.3VF" H 10015 10223 50  0000 C CNN
F 2 "" H 10000 10050 50  0001 C CNN
F 3 "" H 10000 10050 50  0001 C CNN
	1    10000 10050
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+3.3VF #PWR0615
U 1 1 5E9495AA
P 14150 5600
F 0 "#PWR0615" H 14150 5450 50  0001 C CNN
F 1 "+3.3VF" H 14165 5773 50  0000 C CNN
F 2 "" H 14150 5600 50  0001 C CNN
F 3 "" H 14150 5600 50  0001 C CNN
	1    14150 5600
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+3.3VF #PWR0605
U 1 1 5E94B0CB
P 7550 3050
F 0 "#PWR0605" H 7550 2900 50  0001 C CNN
F 1 "+3.3VF" H 7565 3223 50  0000 C CNN
F 2 "" H 7550 3050 50  0001 C CNN
F 3 "" H 7550 3050 50  0001 C CNN
	1    7550 3050
	1    0    0    -1  
$EndComp
Text HLabel 1850 6150 0    50   Output ~ 0
MCU3_MISO
Text HLabel 1850 6250 0    50   Input ~ 0
MCU3_MOSI
NoConn ~ 1900 5750
NoConn ~ 1900 5850
NoConn ~ 1900 5950
NoConn ~ 1900 5350
NoConn ~ 13200 4350
NoConn ~ 13200 4250
$Comp
L Device:C C607
U 1 1 5E3535F6
P 3900 10500
F 0 "C607" H 4015 10546 50  0000 L CNN
F 1 "1u" H 4015 10455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3938 10350 50  0001 C CNN
F 3 "~" H 3900 10500 50  0001 C CNN
	1    3900 10500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 10650 3900 10700
Wire Wire Line
	3900 10700 3450 10700
Connection ~ 3450 10700
Wire Wire Line
	3450 10300 3900 10300
Wire Wire Line
	3900 10300 3900 10350
Connection ~ 3450 10300
Wire Wire Line
	1950 10300 2450 10300
Wire Wire Line
	1950 10700 2450 10700
$EndSCHEMATC
