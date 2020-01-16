EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 3 15
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	7550 850  7550 800 
Wire Wire Line
	7550 800  7750 800 
Wire Wire Line
	9950 800  9950 850 
Wire Wire Line
	9750 850  9750 800 
Connection ~ 9750 800 
Wire Wire Line
	9750 800  9950 800 
Wire Wire Line
	9550 850  9550 800 
Connection ~ 9550 800 
Wire Wire Line
	9550 800  9750 800 
Wire Wire Line
	9350 850  9350 800 
Connection ~ 9350 800 
Wire Wire Line
	9350 800  9550 800 
Wire Wire Line
	9150 850  9150 800 
Connection ~ 9150 800 
Wire Wire Line
	9150 800  9350 800 
Wire Wire Line
	8950 850  8950 800 
Connection ~ 8950 800 
Wire Wire Line
	8950 800  9150 800 
Wire Wire Line
	8750 850  8750 800 
Connection ~ 8750 800 
Wire Wire Line
	8750 800  8950 800 
Wire Wire Line
	8550 850  8550 800 
Connection ~ 8550 800 
Wire Wire Line
	8350 850  8350 800 
Connection ~ 8350 800 
Wire Wire Line
	8350 800  8550 800 
Wire Wire Line
	8150 850  8150 800 
Connection ~ 8150 800 
Wire Wire Line
	8150 800  8350 800 
Wire Wire Line
	7950 850  7950 800 
Connection ~ 7950 800 
Wire Wire Line
	7950 800  8150 800 
Wire Wire Line
	7750 850  7750 800 
Connection ~ 7750 800 
Wire Wire Line
	7750 800  7950 800 
$Comp
L power:+3.3V #PWR0316
U 1 1 5DA87423
P 8750 750
F 0 "#PWR0316" H 8750 600 50  0001 C CNN
F 1 "+3.3V" H 8765 923 50  0000 C CNN
F 2 "" H 8750 750 50  0001 C CNN
F 3 "" H 8750 750 50  0001 C CNN
	1    8750 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 750  8750 800 
Wire Wire Line
	7950 8950 7950 9000
Wire Wire Line
	7950 9000 8150 9000
Wire Wire Line
	9550 9000 9550 8950
Wire Wire Line
	9350 8950 9350 9000
Connection ~ 9350 9000
Wire Wire Line
	9350 9000 9550 9000
Wire Wire Line
	9150 8950 9150 9000
Connection ~ 9150 9000
Wire Wire Line
	9150 9000 9350 9000
Wire Wire Line
	8950 8950 8950 9000
Connection ~ 8950 9000
Wire Wire Line
	8950 9000 9150 9000
Wire Wire Line
	8750 8950 8750 9000
Connection ~ 8750 9000
Wire Wire Line
	8750 9000 8950 9000
Wire Wire Line
	8550 8950 8550 9000
Connection ~ 8550 9000
Wire Wire Line
	8550 9000 8750 9000
Wire Wire Line
	8350 8950 8350 9000
Connection ~ 8350 9000
Wire Wire Line
	8350 9000 8550 9000
Wire Wire Line
	8150 8950 8150 9000
Connection ~ 8150 9000
Wire Wire Line
	8150 9000 8350 9000
Wire Wire Line
	8750 9000 8750 9050
$Comp
L power:GND #PWR0317
U 1 1 5DAA3278
P 8750 9050
F 0 "#PWR0317" H 8750 8800 50  0001 C CNN
F 1 "GND" H 8755 8877 50  0000 C CNN
F 2 "" H 8750 9050 50  0001 C CNN
F 3 "" H 8750 9050 50  0001 C CNN
	1    8750 9050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R307
U 1 1 5DAA6CE1
P 14500 8850
F 0 "R307" H 14570 8896 50  0000 L CNN
F 1 "10k" H 14570 8805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 14430 8850 50  0001 C CNN
F 3 "~" H 14500 8850 50  0001 C CNN
	1    14500 8850
	1    0    0    -1  
$EndComp
Wire Wire Line
	14500 8700 14500 8650
Wire Wire Line
	14500 8650 14450 8650
$Comp
L Device:R R308
U 1 1 5DAA8BD1
P 15100 8050
F 0 "R308" H 15170 8096 50  0000 L CNN
F 1 "10k" H 15170 8005 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 15030 8050 50  0001 C CNN
F 3 "~" H 15100 8050 50  0001 C CNN
	1    15100 8050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C321
U 1 1 5DAA918D
P 15100 8450
F 0 "C321" H 15215 8496 50  0000 L CNN
F 1 "100n" H 15215 8405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 15138 8300 50  0001 C CNN
F 3 "~" H 15100 8450 50  0001 C CNN
	1    15100 8450
	1    0    0    -1  
$EndComp
Wire Wire Line
	15100 8250 15100 8300
Wire Wire Line
	15100 8200 15100 8250
Connection ~ 15100 8250
$Comp
L power:GND #PWR0324
U 1 1 5DAAC0BD
P 15100 8600
F 0 "#PWR0324" H 15100 8350 50  0001 C CNN
F 1 "GND" H 15105 8427 50  0000 C CNN
F 2 "" H 15100 8600 50  0001 C CNN
F 3 "" H 15100 8600 50  0001 C CNN
	1    15100 8600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0322
U 1 1 5DAACD0D
P 14500 9000
F 0 "#PWR0322" H 14500 8750 50  0001 C CNN
F 1 "GND" H 14505 8827 50  0000 C CNN
F 2 "" H 14500 9000 50  0001 C CNN
F 3 "" H 14500 9000 50  0001 C CNN
	1    14500 9000
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0323
U 1 1 5DAAE71B
P 15100 7900
F 0 "#PWR0323" H 15100 7750 50  0001 C CNN
F 1 "+3.3V" H 15115 8073 50  0000 C CNN
F 2 "" H 15100 7900 50  0001 C CNN
F 3 "" H 15100 7900 50  0001 C CNN
	1    15100 7900
	1    0    0    -1  
$EndComp
Text HLabel 14500 2550 2    50   BiDi ~ 0
RMII_TXD1
Text HLabel 14500 2450 2    50   BiDi ~ 0
RMII_TXD0
Text HLabel 14500 2250 2    50   BiDi ~ 0
RMII_TXEN
Text HLabel 3000 5250 0    50   BiDi ~ 0
RMII_RXD0
Text HLabel 3000 5350 0    50   BiDi ~ 0
RMII_RXD1
Text HLabel 3000 3850 0    50   BiDi ~ 0
RMII_CRS_DV
Text HLabel 3000 3350 0    50   BiDi ~ 0
RMII_MDIO
Text HLabel 3000 4950 0    50   BiDi ~ 0
RMII_MDC
Text HLabel 3000 3250 0    50   BiDi ~ 0
REF_CLK
Wire Wire Line
	3050 3250 3000 3250
Wire Wire Line
	3050 3350 3000 3350
Wire Wire Line
	3050 3850 3000 3850
Wire Wire Line
	3050 4950 3000 4950
Wire Wire Line
	3050 5250 3000 5250
Wire Wire Line
	3050 5350 3000 5350
Wire Wire Line
	15600 8250 15100 8250
Wire Wire Line
	3050 8250 3000 8250
Wire Wire Line
	3000 8250 3000 8050
Wire Wire Line
	3000 8050 3050 8050
Wire Wire Line
	2550 8250 3000 8250
Connection ~ 3000 8250
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J302
U 1 1 5DA8679B
P 8850 10450
F 0 "J302" H 8900 10867 50  0000 C CNN
F 1 "Conn_02x05" H 8900 10776 50  0000 C CNN
F 2 "Connector_PinHeader_1.27mm:PinHeader_2x05_P1.27mm_Vertical" H 8850 10450 50  0001 C CNN
F 3 "~" H 8850 10450 50  0001 C CNN
	1    8850 10450
	1    0    0    -1  
$EndComp
NoConn ~ 8650 10550
NoConn ~ 8650 10650
Wire Wire Line
	8650 10450 8500 10450
Wire Wire Line
	8500 10450 8500 10350
Wire Wire Line
	8500 10350 8650 10350
$Comp
L power:GND #PWR0315
U 1 1 5DAA5490
P 8500 10700
F 0 "#PWR0315" H 8500 10450 50  0001 C CNN
F 1 "GND" H 8505 10527 50  0000 C CNN
F 2 "" H 8500 10700 50  0001 C CNN
F 3 "" H 8500 10700 50  0001 C CNN
	1    8500 10700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 10700 8500 10450
Connection ~ 8500 10450
$Comp
L power:+3.3V #PWR0314
U 1 1 5DAA706A
P 8500 10150
F 0 "#PWR0314" H 8500 10000 50  0001 C CNN
F 1 "+3.3V" H 8515 10323 50  0000 C CNN
F 2 "" H 8500 10150 50  0001 C CNN
F 3 "" H 8500 10150 50  0001 C CNN
	1    8500 10150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 10150 8500 10250
Wire Wire Line
	8500 10250 8650 10250
Wire Wire Line
	9150 10250 9600 10250
Text Label 9600 10250 2    50   ~ 0
TMS_SWDIO
Wire Wire Line
	9150 10350 9600 10350
Text Label 9600 10350 2    50   ~ 0
TCK_SWCLK
Wire Wire Line
	9150 10450 9600 10450
Text Label 9600 10450 2    50   ~ 0
TDO
Wire Wire Line
	9150 10550 9600 10550
Text Label 9600 10550 2    50   ~ 0
TDI
Wire Wire Line
	9150 10650 9600 10650
Text Label 9600 10650 2    50   ~ 0
MCU_NRST
Text Label 15550 8250 2    50   ~ 0
MCU_NRST
Text Label 2550 8250 0    50   ~ 0
MCU_VDDA
$Comp
L power:GND #PWR0307
U 1 1 5DACCD5C
P 3000 8450
F 0 "#PWR0307" H 3000 8200 50  0001 C CNN
F 1 "GND" V 3005 8322 50  0000 R CNN
F 2 "" H 3000 8450 50  0001 C CNN
F 3 "" H 3000 8450 50  0001 C CNN
	1    3000 8450
	0    1    1    0   
$EndComp
Wire Wire Line
	3000 8450 3050 8450
$Comp
L power:+3.3V #PWR0306
U 1 1 5DAD0473
P 2950 8650
F 0 "#PWR0306" H 2950 8500 50  0001 C CNN
F 1 "+3.3V" V 2965 8778 50  0000 L CNN
F 2 "" H 2950 8650 50  0001 C CNN
F 3 "" H 2950 8650 50  0001 C CNN
	1    2950 8650
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C311
U 1 1 5DAD0A63
P 3000 8900
F 0 "C311" H 3115 8946 50  0000 L CNN
F 1 "1u" H 3115 8855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3038 8750 50  0001 C CNN
F 3 "~" H 3000 8900 50  0001 C CNN
	1    3000 8900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 8650 3000 8650
Wire Wire Line
	3000 8750 3000 8650
Connection ~ 3000 8650
Wire Wire Line
	3000 8650 3050 8650
$Comp
L power:GND #PWR0308
U 1 1 5DAD7BE9
P 3000 9050
F 0 "#PWR0308" H 3000 8800 50  0001 C CNN
F 1 "GND" H 3005 8877 50  0000 C CNN
F 2 "" H 3000 9050 50  0001 C CNN
F 3 "" H 3000 9050 50  0001 C CNN
	1    3000 9050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8550 800  8750 800 
$Comp
L Device:C C302
U 1 1 5DAEBFB7
P 650 10700
F 0 "C302" H 765 10746 50  0000 L CNN
F 1 "100n" H 765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 688 10550 50  0001 C CNN
F 3 "~" H 650 10700 50  0001 C CNN
	1    650  10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C304
U 1 1 5DAECAD7
P 1150 10700
F 0 "C304" H 1265 10746 50  0000 L CNN
F 1 "100n" H 1265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1188 10550 50  0001 C CNN
F 3 "~" H 1150 10700 50  0001 C CNN
	1    1150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C306
U 1 1 5DAEE29B
P 1650 10700
F 0 "C306" H 1765 10746 50  0000 L CNN
F 1 "100n" H 1765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1688 10550 50  0001 C CNN
F 3 "~" H 1650 10700 50  0001 C CNN
	1    1650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C308
U 1 1 5DAEE2A1
P 2150 10700
F 0 "C308" H 2265 10746 50  0000 L CNN
F 1 "100n" H 2265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2188 10550 50  0001 C CNN
F 3 "~" H 2150 10700 50  0001 C CNN
	1    2150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C310
U 1 1 5DAF1A5F
P 2650 10700
F 0 "C310" H 2765 10746 50  0000 L CNN
F 1 "100n" H 2765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2688 10550 50  0001 C CNN
F 3 "~" H 2650 10700 50  0001 C CNN
	1    2650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C312
U 1 1 5DAF1A65
P 3150 10700
F 0 "C312" H 3265 10746 50  0000 L CNN
F 1 "100n" H 3265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3188 10550 50  0001 C CNN
F 3 "~" H 3150 10700 50  0001 C CNN
	1    3150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C313
U 1 1 5DAF1A6B
P 3650 10700
F 0 "C313" H 3765 10746 50  0000 L CNN
F 1 "100n" H 3765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3688 10550 50  0001 C CNN
F 3 "~" H 3650 10700 50  0001 C CNN
	1    3650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C314
U 1 1 5DAF1A71
P 4150 10700
F 0 "C314" H 4265 10746 50  0000 L CNN
F 1 "100n" H 4265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4188 10550 50  0001 C CNN
F 3 "~" H 4150 10700 50  0001 C CNN
	1    4150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C315
U 1 1 5DAF5DB7
P 4650 10700
F 0 "C315" H 4765 10746 50  0000 L CNN
F 1 "100n" H 4765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 4688 10550 50  0001 C CNN
F 3 "~" H 4650 10700 50  0001 C CNN
	1    4650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C316
U 1 1 5DAF5DBD
P 5150 10700
F 0 "C316" H 5265 10746 50  0000 L CNN
F 1 "100n" H 5265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5188 10550 50  0001 C CNN
F 3 "~" H 5150 10700 50  0001 C CNN
	1    5150 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C317
U 1 1 5DAF5DC3
P 5650 10700
F 0 "C317" H 5765 10746 50  0000 L CNN
F 1 "100n" H 5765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5688 10550 50  0001 C CNN
F 3 "~" H 5650 10700 50  0001 C CNN
	1    5650 10700
	1    0    0    -1  
$EndComp
$Comp
L Device:C C318
U 1 1 5DAF5DC9
P 6150 10700
F 0 "C318" H 6265 10746 50  0000 L CNN
F 1 "100n" H 6265 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6188 10550 50  0001 C CNN
F 3 "~" H 6150 10700 50  0001 C CNN
	1    6150 10700
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  10550 650  10500
Wire Wire Line
	650  10500 1150 10500
Wire Wire Line
	6150 10500 6150 10550
Wire Wire Line
	5650 10550 5650 10500
Connection ~ 5650 10500
Wire Wire Line
	5650 10500 6150 10500
Wire Wire Line
	5150 10550 5150 10500
Connection ~ 5150 10500
Wire Wire Line
	5150 10500 5650 10500
Wire Wire Line
	4650 10550 4650 10500
Connection ~ 4650 10500
Wire Wire Line
	4650 10500 5150 10500
Wire Wire Line
	4150 10550 4150 10500
Connection ~ 4150 10500
Wire Wire Line
	4150 10500 4650 10500
Wire Wire Line
	3650 10550 3650 10500
Connection ~ 3650 10500
Wire Wire Line
	3650 10500 4150 10500
Wire Wire Line
	3150 10550 3150 10500
Connection ~ 3150 10500
Wire Wire Line
	2650 10550 2650 10500
Connection ~ 2650 10500
Wire Wire Line
	2650 10500 3150 10500
Wire Wire Line
	2150 10550 2150 10500
Connection ~ 2150 10500
Wire Wire Line
	2150 10500 2650 10500
Wire Wire Line
	1650 10550 1650 10500
Connection ~ 1650 10500
Wire Wire Line
	1650 10500 2150 10500
Wire Wire Line
	1150 10550 1150 10500
Connection ~ 1150 10500
Wire Wire Line
	1150 10500 1650 10500
Wire Wire Line
	650  10850 650  10900
Wire Wire Line
	650  10900 1150 10900
Wire Wire Line
	6150 10900 6150 10850
Wire Wire Line
	5650 10850 5650 10900
Connection ~ 5650 10900
Wire Wire Line
	5650 10900 6150 10900
Wire Wire Line
	5150 10850 5150 10900
Connection ~ 5150 10900
Wire Wire Line
	5150 10900 5650 10900
Wire Wire Line
	4650 10850 4650 10900
Connection ~ 4650 10900
Wire Wire Line
	4650 10900 5150 10900
Wire Wire Line
	4150 10850 4150 10900
Connection ~ 4150 10900
Wire Wire Line
	4150 10900 4650 10900
Wire Wire Line
	3650 10850 3650 10900
Connection ~ 3650 10900
Wire Wire Line
	3150 10850 3150 10900
Connection ~ 3150 10900
Wire Wire Line
	2650 10850 2650 10900
Connection ~ 2650 10900
Wire Wire Line
	2650 10900 3150 10900
Wire Wire Line
	2150 10850 2150 10900
Connection ~ 2150 10900
Wire Wire Line
	2150 10900 2650 10900
Wire Wire Line
	1650 10850 1650 10900
Connection ~ 1650 10900
Wire Wire Line
	1650 10900 2150 10900
Wire Wire Line
	1150 10850 1150 10900
Connection ~ 1150 10900
Wire Wire Line
	1150 10900 1650 10900
$Comp
L power:GND #PWR0310
U 1 1 5DB438B1
P 3650 10950
F 0 "#PWR0310" H 3650 10700 50  0001 C CNN
F 1 "GND" H 3655 10777 50  0000 C CNN
F 2 "" H 3650 10950 50  0001 C CNN
F 3 "" H 3650 10950 50  0001 C CNN
	1    3650 10950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 10950 3650 10900
$Comp
L power:+3.3V #PWR0309
U 1 1 5DB49ACF
P 3650 10450
F 0 "#PWR0309" H 3650 10300 50  0001 C CNN
F 1 "+3.3V" H 3665 10623 50  0000 C CNN
F 2 "" H 3650 10450 50  0001 C CNN
F 3 "" H 3650 10450 50  0001 C CNN
	1    3650 10450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 10500 3650 10450
$Comp
L Device:Ferrite_Bead FB301
U 1 1 5DB6CBFD
P 6850 10500
F 0 "FB301" V 6576 10500 50  0000 C CNN
F 1 "742792031" V 6667 10500 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6780 10500 50  0001 C CNN
F 3 "~" H 6850 10500 50  0001 C CNN
	1    6850 10500
	0    1    1    0   
$EndComp
$Comp
L Device:C C320
U 1 1 5DB6D4C6
P 7100 10700
F 0 "C320" H 7215 10746 50  0000 L CNN
F 1 "1u" H 7215 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 7138 10550 50  0001 C CNN
F 3 "~" H 7100 10700 50  0001 C CNN
	1    7100 10700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 10500 7100 10550
$Comp
L power:GND #PWR0311
U 1 1 5DB72CF5
P 7100 10950
F 0 "#PWR0311" H 7100 10700 50  0001 C CNN
F 1 "GND" H 7105 10777 50  0000 C CNN
F 2 "" H 7100 10950 50  0001 C CNN
F 3 "" H 7100 10950 50  0001 C CNN
	1    7100 10950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 10950 7100 10850
Wire Wire Line
	6650 10500 6700 10500
Wire Wire Line
	7100 10500 7600 10500
Text Label 7600 10500 2    50   ~ 0
MCU_VDDA
$Comp
L Connector_Generic:Conn_02x01 J301
U 1 1 5DB87F87
P 7750 10650
F 0 "J301" V 7754 10730 50  0000 L CNN
F 1 "Conn_02x01" V 7845 10730 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7750 10650 50  0001 C CNN
F 3 "~" H 7750 10650 50  0001 C CNN
	1    7750 10650
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0313
U 1 1 5DB88AAB
P 7750 10950
F 0 "#PWR0313" H 7750 10700 50  0001 C CNN
F 1 "GND" H 7755 10777 50  0000 C CNN
F 2 "" H 7750 10950 50  0001 C CNN
F 3 "" H 7750 10950 50  0001 C CNN
	1    7750 10950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R304
U 1 1 5DB8FF79
P 7750 10200
F 0 "R304" H 7680 10154 50  0000 R CNN
F 1 "10k" H 7680 10245 50  0000 R CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7680 10200 50  0001 C CNN
F 3 "~" H 7750 10200 50  0001 C CNN
	1    7750 10200
	-1   0    0    1   
$EndComp
Wire Wire Line
	7750 10450 7750 10400
Wire Wire Line
	7750 10400 8300 10400
Connection ~ 7750 10400
Wire Wire Line
	7750 10400 7750 10350
Text Label 8300 10400 2    50   ~ 0
MCU_DEFAULT
$Comp
L power:+3.3V #PWR0312
U 1 1 5DBA1842
P 7750 10050
F 0 "#PWR0312" H 7750 9900 50  0001 C CNN
F 1 "+3.3V" H 7765 10223 50  0000 C CNN
F 2 "" H 7750 10050 50  0001 C CNN
F 3 "" H 7750 10050 50  0001 C CNN
	1    7750 10050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C309
U 1 1 5DBA6521
P 2300 8050
F 0 "C309" H 2415 8096 50  0000 L CNN
F 1 "2u2" H 2415 8005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 2338 7900 50  0001 C CNN
F 3 "~" H 2300 8050 50  0001 C CNN
	1    2300 8050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 7850 2300 7850
Wire Wire Line
	2300 7850 2300 7900
$Comp
L Device:C C307
U 1 1 5DBADF01
P 1850 8050
F 0 "C307" H 1965 8096 50  0000 L CNN
F 1 "2u2" H 1965 8005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 1888 7900 50  0001 C CNN
F 3 "~" H 1850 8050 50  0001 C CNN
	1    1850 8050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 8200 1850 8250
Wire Wire Line
	1850 8250 2100 8250
Wire Wire Line
	2300 8250 2300 8200
Wire Wire Line
	1850 7650 3050 7650
Wire Wire Line
	1850 7650 1850 7900
$Comp
L power:GND #PWR0305
U 1 1 5DBC271D
P 2100 8300
F 0 "#PWR0305" H 2100 8050 50  0001 C CNN
F 1 "GND" H 2105 8127 50  0000 C CNN
F 2 "" H 2100 8300 50  0001 C CNN
F 3 "" H 2100 8300 50  0001 C CNN
	1    2100 8300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 8300 2100 8250
Connection ~ 2100 8250
Wire Wire Line
	2100 8250 2300 8250
$Comp
L Device:Crystal Y301
U 1 1 5DBCE9A3
P 1650 1050
F 0 "Y301" V 1604 1181 50  0000 L CNN
F 1 "NX3225GD-8MHZ-STD-CRA-3" V 1695 1181 50  0000 L CNN
F 2 "ETH1CLCR1:NX3225GD" H 1650 1050 50  0001 C CNN
F 3 "~" H 1650 1050 50  0001 C CNN
	1    1650 1050
	0    1    1    0   
$EndComp
Wire Wire Line
	1650 1250 1650 1200
Wire Wire Line
	1650 900  1650 850 
Wire Wire Line
	1650 850  3000 850 
Wire Wire Line
	3000 850  3000 1150
Wire Wire Line
	3000 1150 3050 1150
$Comp
L Device:C C305
U 1 1 5DBE0849
P 1650 1450
F 0 "C305" H 1765 1496 50  0000 L CNN
F 1 "8p" H 1765 1405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1688 1300 50  0001 C CNN
F 3 "~" H 1650 1450 50  0001 C CNN
	1    1650 1450
	1    0    0    -1  
$EndComp
$Comp
L Device:C C303
U 1 1 5DBE0C2D
P 1150 1450
F 0 "C303" H 1265 1496 50  0000 L CNN
F 1 "8p" H 1265 1405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1188 1300 50  0001 C CNN
F 3 "~" H 1150 1450 50  0001 C CNN
	1    1150 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 1300 1650 1250
Connection ~ 1650 1250
Wire Wire Line
	1650 850  1150 850 
Wire Wire Line
	1150 850  1150 1300
Connection ~ 1650 850 
Wire Wire Line
	1150 1600 1150 1650
Wire Wire Line
	1150 1650 1400 1650
Wire Wire Line
	1650 1650 1650 1600
$Comp
L power:GND #PWR0303
U 1 1 5DC11C96
P 1400 1700
F 0 "#PWR0303" H 1400 1450 50  0001 C CNN
F 1 "GND" H 1405 1527 50  0000 C CNN
F 2 "" H 1400 1700 50  0001 C CNN
F 3 "" H 1400 1700 50  0001 C CNN
	1    1400 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 1700 1400 1650
Connection ~ 1400 1650
Wire Wire Line
	1400 1650 1650 1650
Wire Wire Line
	3050 4450 2600 4450
Text Label 2600 4450 0    50   ~ 0
TMS_SWDIO
Wire Wire Line
	3050 4550 2600 4550
Text Label 2600 4550 0    50   ~ 0
TCK_SWCLK
Wire Wire Line
	3050 4650 2600 4650
Text Label 2600 4650 0    50   ~ 0
TDI
Text Notes 8500 11150 0    50   ~ 0
PROGRAMMING CONNECTOR\nDESIGNED FOR JLINK
$Comp
L ETH1CLCR1:STM32F765ZGT6 U301
U 1 1 5DC8ECD0
P 8750 4900
F 0 "U301" H 3300 8800 50  0000 C CNN
F 1 "STM32F765ZGT6" H 13900 8800 50  0000 C CNN
F 2 "ETH1CLCR1:TQFP-144_20x20mm_P0.5mm" H 24650 6400 50  0001 C CNN
F 3 "" H 24650 6400 50  0001 C CNN
	1    8750 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	14450 2250 14500 2250
Wire Wire Line
	14500 2450 14450 2450
Wire Wire Line
	14450 2550 14500 2550
Text Label 14900 6550 2    50   ~ 0
TDO
Wire Wire Line
	14450 6550 14900 6550
Text HLabel 15600 8250 2    50   BiDi ~ 0
NRST
Wire Wire Line
	3050 2750 2550 2750
Text Label 2550 2750 0    50   ~ 0
I2C_WP
Text Label 2550 2850 0    50   ~ 0
I2C_SCL
Text Label 2550 2950 0    50   ~ 0
I2C_SDA
Wire Wire Line
	3050 2950 2550 2950
Wire Wire Line
	3050 2850 2550 2850
$Comp
L Device:C C301
U 1 1 5E17592C
P 650 9850
F 0 "C301" H 765 9896 50  0000 L CNN
F 1 "100n" H 765 9805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 688 9700 50  0001 C CNN
F 3 "~" H 650 9850 50  0001 C CNN
	1    650  9850
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0301
U 1 1 5E176017
P 650 9600
F 0 "#PWR0301" H 650 9450 50  0001 C CNN
F 1 "+3.3V" H 665 9773 50  0000 C CNN
F 2 "" H 650 9600 50  0001 C CNN
F 3 "" H 650 9600 50  0001 C CNN
	1    650  9600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0302
U 1 1 5E1764D7
P 650 10100
F 0 "#PWR0302" H 650 9850 50  0001 C CNN
F 1 "GND" H 655 9927 50  0000 C CNN
F 2 "" H 650 10100 50  0001 C CNN
F 3 "" H 650 10100 50  0001 C CNN
	1    650  10100
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  10100 650  10000
Wire Wire Line
	650  9700 650  9600
Text HLabel 14500 7550 2    50   Output ~ 0
TRIG_EN
Text HLabel 14500 7650 2    50   Output ~ 0
TRIG_OUT
Text HLabel 14500 7750 2    50   Input ~ 0
TRIG_IN
Wire Wire Line
	14450 8250 15100 8250
Wire Wire Line
	14500 7550 14450 7550
Wire Wire Line
	14500 7650 14450 7650
Wire Wire Line
	14450 7750 14500 7750
Text HLabel 3000 5050 0    50   Input ~ 0
MCU1_STATUS_IN
Text HLabel 3000 4850 0    50   Output ~ 0
MCU1_GPIO_OUT2
Text HLabel 3000 2450 0    50   Output ~ 0
MCU1_GPIO_OUT1
Wire Wire Line
	3000 2450 3050 2450
Wire Wire Line
	3050 4850 3000 4850
Wire Wire Line
	3000 5050 3050 5050
Wire Wire Line
	3050 2050 3000 2050
Wire Wire Line
	3000 2150 3050 2150
Wire Wire Line
	3050 2250 3000 2250
Wire Wire Line
	3000 2350 3050 2350
Text HLabel 3000 2050 0    50   Output ~ 0
MCU1_~SS
Text HLabel 3000 2250 0    50   Input ~ 0
MCU1_MISO
Text HLabel 3000 2350 0    50   Output ~ 0
MCU1_MOSI
Text HLabel 3000 2150 0    50   Output ~ 0
MCU1_MCLK
Wire Wire Line
	1650 1250 3050 1250
NoConn ~ 3050 1750
NoConn ~ 3050 1850
NoConn ~ 3050 1950
NoConn ~ 3050 2550
NoConn ~ 3050 2650
NoConn ~ 3050 3150
NoConn ~ 3050 1450
NoConn ~ 3050 1550
NoConn ~ 3050 1650
NoConn ~ 3050 3450
NoConn ~ 3050 3550
NoConn ~ 3050 3650
NoConn ~ 3050 3750
NoConn ~ 3050 3950
NoConn ~ 3050 4050
NoConn ~ 3050 4150
NoConn ~ 3050 4250
NoConn ~ 3050 5150
NoConn ~ 3050 5450
NoConn ~ 3050 5550
NoConn ~ 3050 5650
NoConn ~ 3050 5750
NoConn ~ 3050 6150
NoConn ~ 3050 6250
NoConn ~ 3050 6350
NoConn ~ 14450 1150
NoConn ~ 14450 1250
NoConn ~ 14450 1350
NoConn ~ 14450 1450
NoConn ~ 14450 1550
NoConn ~ 14450 1650
NoConn ~ 14450 1750
NoConn ~ 14450 1850
NoConn ~ 14450 1950
NoConn ~ 14450 2050
NoConn ~ 14450 2150
NoConn ~ 14450 2350
NoConn ~ 14450 2650
NoConn ~ 14450 2850
NoConn ~ 14450 2950
NoConn ~ 14450 3050
NoConn ~ 14450 3150
NoConn ~ 14450 3250
NoConn ~ 14450 3350
NoConn ~ 14450 3450
NoConn ~ 14450 3550
NoConn ~ 14450 3650
NoConn ~ 14450 3750
NoConn ~ 14450 3850
NoConn ~ 14450 3950
NoConn ~ 14450 4050
NoConn ~ 14450 4150
NoConn ~ 14450 4250
NoConn ~ 14450 4350
NoConn ~ 14450 4550
NoConn ~ 14450 4650
NoConn ~ 14450 4750
NoConn ~ 14450 4850
NoConn ~ 14450 4950
NoConn ~ 14450 5050
NoConn ~ 14450 5150
NoConn ~ 14450 5250
NoConn ~ 14450 5350
NoConn ~ 14450 5450
NoConn ~ 14450 5550
NoConn ~ 14450 5650
NoConn ~ 14450 5750
NoConn ~ 14450 5850
NoConn ~ 14450 5950
NoConn ~ 14450 6050
NoConn ~ 14450 6250
NoConn ~ 14450 6350
NoConn ~ 14450 6450
NoConn ~ 14450 6650
NoConn ~ 14450 6750
NoConn ~ 14450 6850
NoConn ~ 14450 6950
NoConn ~ 14450 7050
NoConn ~ 14450 7150
NoConn ~ 14450 7250
NoConn ~ 14450 7350
NoConn ~ 14450 7450
$Comp
L Device:C C319
U 1 1 5DF2F119
P 6650 10700
F 0 "C319" H 6765 10746 50  0000 L CNN
F 1 "100n" H 6765 10655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6688 10550 50  0001 C CNN
F 3 "~" H 6650 10700 50  0001 C CNN
	1    6650 10700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 10550 6650 10500
Wire Wire Line
	6650 10500 6150 10500
Connection ~ 6150 10500
Wire Wire Line
	6150 10900 6650 10900
Wire Wire Line
	6650 10900 6650 10850
Connection ~ 6150 10900
Wire Wire Line
	3150 10500 3650 10500
Wire Wire Line
	3150 10900 3650 10900
Wire Wire Line
	3650 10900 4150 10900
Wire Wire Line
	3050 4350 2500 4350
Text Label 2500 4350 0    50   ~ 0
MCU_DEFAULT
Connection ~ 11400 9950
Wire Wire Line
	11400 9900 11400 9950
$Comp
L power:+3.3V #PWR0321
U 1 1 5E117FC1
P 11400 9900
F 0 "#PWR0321" H 11400 9750 50  0001 C CNN
F 1 "+3.3V" H 11415 10073 50  0000 C CNN
F 2 "" H 11400 9900 50  0001 C CNN
F 3 "" H 11400 9900 50  0001 C CNN
	1    11400 9900
	1    0    0    -1  
$EndComp
Wire Wire Line
	11400 9950 11400 10000
Wire Wire Line
	11050 9950 11400 9950
Wire Wire Line
	11050 10000 11050 9950
Wire Wire Line
	10700 10450 11400 10450
Wire Wire Line
	11400 10450 11400 10300
Wire Wire Line
	10700 10350 11050 10350
Wire Wire Line
	11050 10350 11050 10300
$Comp
L Device:R R306
U 1 1 5E0F3C03
P 11400 10150
F 0 "R306" H 11470 10196 50  0000 L CNN
F 1 "4k7" H 11470 10105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 11330 10150 50  0001 C CNN
F 3 "~" H 11400 10150 50  0001 C CNN
	1    11400 10150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R305
U 1 1 5E0F3906
P 11050 10150
F 0 "R305" H 11120 10196 50  0000 L CNN
F 1 "4k7" H 11120 10105 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 10980 10150 50  0001 C CNN
F 3 "~" H 11050 10150 50  0001 C CNN
	1    11050 10150
	1    0    0    -1  
$EndComp
Text Label 11000 10350 2    50   ~ 0
I2C_SDA
Text Label 11000 10450 2    50   ~ 0
I2C_SCL
Text Label 11000 10550 2    50   ~ 0
I2C_WP
Wire Wire Line
	10700 10550 11000 10550
Wire Wire Line
	9850 10450 9850 10550
Connection ~ 9850 10450
Wire Wire Line
	9900 10450 9850 10450
Connection ~ 9850 10550
Wire Wire Line
	9850 10750 9850 10550
$Comp
L power:GND #PWR0318
U 1 1 5E096BB8
P 9850 10750
F 0 "#PWR0318" H 9850 10500 50  0001 C CNN
F 1 "GND" H 9855 10577 50  0000 C CNN
F 2 "" H 9850 10750 50  0001 C CNN
F 3 "" H 9850 10750 50  0001 C CNN
	1    9850 10750
	1    0    0    -1  
$EndComp
Wire Wire Line
	9850 10550 9900 10550
Wire Wire Line
	9850 10350 9850 10450
Wire Wire Line
	9900 10350 9850 10350
$Comp
L power:GND #PWR0320
U 1 1 5E08CDE4
P 10300 10750
F 0 "#PWR0320" H 10300 10500 50  0001 C CNN
F 1 "GND" H 10305 10577 50  0000 C CNN
F 2 "" H 10300 10750 50  0001 C CNN
F 3 "" H 10300 10750 50  0001 C CNN
	1    10300 10750
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0319
U 1 1 5E08AE5B
P 10300 10150
F 0 "#PWR0319" H 10300 10000 50  0001 C CNN
F 1 "+3.3V" H 10315 10323 50  0000 C CNN
F 2 "" H 10300 10150 50  0001 C CNN
F 3 "" H 10300 10150 50  0001 C CNN
	1    10300 10150
	1    0    0    -1  
$EndComp
$Comp
L Memory_EEPROM:24LC08 U302
U 1 1 5E082698
P 10300 10450
F 0 "U302" H 10650 10800 50  0000 C CNN
F 1 "24LC08B-E/MS" H 10650 10700 50  0000 C CNN
F 2 "Package_SO:MSOP-8_3x3mm_P0.65mm" H 10300 10450 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21710J.pdf" H 10300 10450 50  0001 C CNN
	1    10300 10450
	1    0    0    -1  
$EndComp
Connection ~ 6650 10500
Wire Wire Line
	7100 10500 7000 10500
Connection ~ 7100 10500
$Comp
L Device:R R301
U 1 1 5E648C3B
P 2650 5850
F 0 "R301" V 2443 5850 50  0000 C CNN
F 1 "680" V 2534 5850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2580 5850 50  0001 C CNN
F 3 "~" H 2650 5850 50  0001 C CNN
	1    2650 5850
	0    1    1    0   
$EndComp
$Comp
L Device:R R302
U 1 1 5E64A32E
P 2650 6250
F 0 "R302" V 2443 6250 50  0000 C CNN
F 1 "560" V 2534 6250 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2580 6250 50  0001 C CNN
F 3 "~" H 2650 6250 50  0001 C CNN
	1    2650 6250
	0    1    1    0   
$EndComp
$Comp
L Device:R R303
U 1 1 5E64A698
P 2650 6650
F 0 "R303" V 2443 6650 50  0000 C CNN
F 1 "680" V 2534 6650 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2580 6650 50  0001 C CNN
F 3 "~" H 2650 6650 50  0001 C CNN
	1    2650 6650
	0    1    1    0   
$EndComp
Wire Wire Line
	2800 5850 3050 5850
Wire Wire Line
	2800 5950 3050 5950
Wire Wire Line
	2800 6650 2900 6650
Wire Wire Line
	2900 6050 3050 6050
$Comp
L Device:LED D301
U 1 1 5E66EF29
P 2300 5850
F 0 "D301" H 2293 5595 50  0000 C CNN
F 1 "RED" H 2293 5686 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2300 5850 50  0001 C CNN
F 3 "~" H 2300 5850 50  0001 C CNN
	1    2300 5850
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D302
U 1 1 5E66FC1B
P 2300 6250
F 0 "D302" H 2293 5995 50  0000 C CNN
F 1 "GREEN" H 2293 6086 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2300 6250 50  0001 C CNN
F 3 "~" H 2300 6250 50  0001 C CNN
	1    2300 6250
	-1   0    0    1   
$EndComp
Wire Wire Line
	2800 5950 2800 6250
$Comp
L Device:LED D303
U 1 1 5E69BE69
P 2300 6650
F 0 "D303" H 2293 6395 50  0000 C CNN
F 1 "BLUE" H 2293 6486 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 2300 6650 50  0001 C CNN
F 3 "~" H 2300 6650 50  0001 C CNN
	1    2300 6650
	-1   0    0    1   
$EndComp
Wire Wire Line
	2900 6050 2900 6650
Wire Wire Line
	2500 6650 2450 6650
Wire Wire Line
	2100 6650 2100 6250
Wire Wire Line
	2100 5850 2150 5850
Wire Wire Line
	2150 6650 2100 6650
Wire Wire Line
	2100 6250 2150 6250
Connection ~ 2100 6250
Wire Wire Line
	2100 6250 2100 5850
Wire Wire Line
	2450 6250 2500 6250
Wire Wire Line
	2450 5850 2500 5850
$Comp
L power:+3.3V #PWR0304
U 1 1 5E6FCD13
P 2050 6250
F 0 "#PWR0304" H 2050 6100 50  0001 C CNN
F 1 "+3.3V" V 2050 6500 50  0000 C CNN
F 2 "" H 2050 6250 50  0001 C CNN
F 3 "" H 2050 6250 50  0001 C CNN
	1    2050 6250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2050 6250 2100 6250
$Comp
L Sensor_Humidity:HDC1080 U303
U 1 1 5EF9C579
P 1400 3450
F 0 "U303" H 1650 3800 50  0000 R CNN
F 1 "HDC1080" H 1800 3700 50  0000 R CNN
F 2 "Package_SON:Texas_PWSON-N6" H 1350 3200 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/hdc1080.pdf" H 1000 3700 50  0001 C CNN
	1    1400 3450
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR0101
U 1 1 5EF9D455
P 1300 3050
F 0 "#PWR0101" H 1300 2900 50  0001 C CNN
F 1 "+3.3V" H 1315 3223 50  0000 C CNN
F 2 "" H 1300 3050 50  0001 C CNN
F 3 "" H 1300 3050 50  0001 C CNN
	1    1300 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5EF9F2A6
P 1300 3750
F 0 "#PWR0102" H 1300 3500 50  0001 C CNN
F 1 "GND" H 1305 3577 50  0000 C CNN
F 2 "" H 1300 3750 50  0001 C CNN
F 3 "" H 1300 3750 50  0001 C CNN
	1    1300 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:C C322
U 1 1 5EFA260C
P 700 3300
F 0 "C322" H 815 3346 50  0000 L CNN
F 1 "100n" H 815 3255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 738 3150 50  0001 C CNN
F 3 "~" H 700 3300 50  0001 C CNN
	1    700  3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 3150 1300 3100
Wire Wire Line
	700  3150 700  3100
Wire Wire Line
	700  3100 1300 3100
Connection ~ 1300 3100
Wire Wire Line
	1300 3100 1300 3050
$Comp
L power:GND #PWR0103
U 1 1 5EFC3E57
P 700 3450
F 0 "#PWR0103" H 700 3200 50  0001 C CNN
F 1 "GND" H 705 3277 50  0000 C CNN
F 2 "" H 700 3450 50  0001 C CNN
F 3 "" H 700 3450 50  0001 C CNN
	1    700  3450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
