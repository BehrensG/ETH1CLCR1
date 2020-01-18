EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 15
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
	10450 4100 10650 4100
Wire Wire Line
	10150 4700 10650 4700
Wire Wire Line
	8200 4100 8050 4100
Connection ~ 8200 4100
Wire Wire Line
	8200 4250 8200 4100
Wire Wire Line
	8200 4700 8750 4700
Wire Wire Line
	8200 4550 8200 4700
$Comp
L Device:C C?
U 1 1 5DCFB9F2
P 8200 4400
AR Path="/5DC846AF/5DCFB9F2" Ref="C?"  Part="1" 
AR Path="/5DCE1F8B/5DCFB9F2" Ref="C?"  Part="1" 
AR Path="/5DD0DBE6/5DCFB9F2" Ref="C?"  Part="1" 
AR Path="/5DEC0296/5DCFB9F2" Ref="C620"  Part="1" 
F 0 "C620" H 8315 4446 50  0000 L CNN
F 1 "10u/50V" H 8315 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8238 4250 50  0001 C CNN
F 3 "~" H 8200 4400 50  0001 C CNN
	1    8200 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10650 3950 10650 4100
Wire Wire Line
	10150 4400 10150 4700
Wire Wire Line
	10650 4700 10650 4550
Connection ~ 10150 4700
Wire Wire Line
	9600 4700 10150 4700
Wire Wire Line
	9850 4100 9600 4100
Connection ~ 10650 4100
Wire Wire Line
	10650 4250 10650 4100
$Comp
L Device:C C?
U 1 1 5DCFB975
P 10650 4400
AR Path="/5DC846AF/5DCFB975" Ref="C?"  Part="1" 
AR Path="/5DCE1F8B/5DCFB975" Ref="C?"  Part="1" 
AR Path="/5DD0DBE6/5DCFB975" Ref="C?"  Part="1" 
AR Path="/5DEC0296/5DCFB975" Ref="C626"  Part="1" 
F 0 "C626" H 10765 4446 50  0000 L CNN
F 1 "10u/16V" H 10765 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 10688 4250 50  0001 C CNN
F 3 "~" H 10650 4400 50  0001 C CNN
	1    10650 4400
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM1117-3.3 U?
U 1 1 5DCFB96F
P 10150 4100
AR Path="/5DC846AF/5DCFB96F" Ref="U?"  Part="1" 
AR Path="/5DCE1F8B/5DCFB96F" Ref="U?"  Part="1" 
AR Path="/5DD0DBE6/5DCFB96F" Ref="U?"  Part="1" 
AR Path="/5DEC0296/5DCFB96F" Ref="U610"  Part="1" 
F 0 "U610" H 10150 4342 50  0000 C CNN
F 1 "LM1117IMP-3.3/NOPB" H 10150 4250 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 10150 4100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 10150 4100 50  0001 C CNN
	1    10150 4100
	1    0    0    -1  
$EndComp
Connection ~ 9600 4100
Wire Wire Line
	9600 4550 9600 4700
$Comp
L Device:C C?
U 1 1 5DCFB966
P 9600 4400
AR Path="/5DC846AF/5DCFB966" Ref="C?"  Part="1" 
AR Path="/5DCE1F8B/5DCFB966" Ref="C?"  Part="1" 
AR Path="/5DD0DBE6/5DCFB966" Ref="C?"  Part="1" 
AR Path="/5DEC0296/5DCFB966" Ref="C623"  Part="1" 
F 0 "C623" H 9715 4446 50  0000 L CNN
F 1 "10u/16V" H 9715 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 9638 4250 50  0001 C CNN
F 3 "~" H 9600 4400 50  0001 C CNN
	1    9600 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 4100 9600 4100
Wire Wire Line
	9250 4400 9250 4700
Connection ~ 9600 4700
Wire Wire Line
	9250 4700 9600 4700
Connection ~ 10650 4700
Wire Wire Line
	10650 4700 10650 4750
$Comp
L ETH1CLCR1:+3.3VF #PWR0623
U 1 1 5E155843
P 10650 3950
F 0 "#PWR0623" H 10650 3800 50  0001 C CNN
F 1 "+3.3VF" H 10665 4123 50  0000 C CNN
F 2 "" H 10650 3950 50  0001 C CNN
F 3 "" H 10650 3950 50  0001 C CNN
	1    10650 3950
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:LT8330_S6 U601
U 1 1 5DD3A2BA
P 1900 2650
F 0 "U601" H 1800 3100 50  0000 L CNN
F 1 "LT8330_S6" H 1700 2800 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23-6_HandSoldering" H 2800 2950 50  0001 C CNN
F 3 "" H 2800 2950 50  0001 C CNN
	1    1900 2650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R601
U 1 1 5DD3BF1D
P 1150 2400
F 0 "R601" H 1220 2446 50  0000 L CNN
F 1 "1M" H 1220 2355 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1080 2400 50  0001 C CNN
F 3 "~" H 1150 2400 50  0001 C CNN
	1    1150 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 2650 1150 2650
Wire Wire Line
	1150 2650 1150 2550
$Comp
L Device:R R602
U 1 1 5DD3D810
P 1150 2900
F 0 "R602" H 1220 2946 50  0000 L CNN
F 1 "287k" H 1220 2855 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1080 2900 50  0001 C CNN
F 3 "~" H 1150 2900 50  0001 C CNN
	1    1150 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 2750 1150 2650
Connection ~ 1150 2650
Wire Wire Line
	1150 2250 1150 2100
Wire Wire Line
	1150 2100 1700 2100
Wire Wire Line
	1700 2100 1700 2150
$Comp
L ETH1CLCR1:74489440068 L601
U 1 1 5DD40E78
P 1900 2100
F 0 "L601" H 1900 2325 50  0000 C CNN
F 1 "74489440068" H 1900 2234 50  0000 C CNN
F 2 "ETH1CLCR1:74489440068" H 1950 2500 50  0001 C CNN
F 3 "" H 1950 2500 50  0001 C CNN
	1    1900 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2100 1700 2100
Connection ~ 1700 2100
Wire Wire Line
	2050 2100 2100 2100
Wire Wire Line
	2100 2100 2100 2150
$Comp
L ETH1CLCR1:74489440068 L601
U 2 1 5DD443FC
P 2600 2350
F 0 "L601" V 2646 2278 50  0000 R CNN
F 1 "74489440068" V 2555 2278 50  0000 R CNN
F 2 "ETH1CLCR1:74489440068" H 2650 2750 50  0001 C CNN
F 3 "" H 2650 2750 50  0001 C CNN
	2    2600 2350
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C603
U 1 1 5DD45139
P 1700 3350
F 0 "C603" H 1815 3396 50  0000 L CNN
F 1 "1u" H 1815 3305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1738 3200 50  0001 C CNN
F 3 "~" H 1700 3350 50  0001 C CNN
	1    1700 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 3200 1700 3150
Wire Wire Line
	1700 3500 1700 3550
Wire Wire Line
	1700 3550 1150 3550
Wire Wire Line
	1150 3550 1150 3050
Wire Wire Line
	1700 3550 2100 3550
Wire Wire Line
	2100 3550 2100 3150
Connection ~ 1700 3550
$Comp
L Device:R R606
U 1 1 5DD4B340
P 3350 3050
F 0 "R606" H 3420 3096 50  0000 L CNN
F 1 "R" H 3420 3005 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3280 3050 50  0001 C CNN
F 3 "~" H 3350 3050 50  0001 C CNN
	1    3350 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C605
U 1 1 5DD4C41A
P 2400 2100
F 0 "C605" V 2148 2100 50  0000 C CNN
F 1 "1u/HC" V 2239 2100 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 2438 1950 50  0001 C CNN
F 3 "~" H 2400 2100 50  0001 C CNN
	1    2400 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	2250 2100 2100 2100
Connection ~ 2100 2100
Wire Wire Line
	2600 2200 2600 2100
Wire Wire Line
	2550 2100 2600 2100
Wire Wire Line
	2600 2550 2600 2500
$Comp
L Device:R R605
U 1 1 5DD6A506
P 3350 2550
F 0 "R605" H 3420 2596 50  0000 L CNN
F 1 "1M" H 3420 2505 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3280 2550 50  0001 C CNN
F 3 "~" H 3350 2550 50  0001 C CNN
	1    3350 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 2100 3350 2100
Wire Wire Line
	3350 2100 3350 2300
Wire Wire Line
	3350 3200 3350 3550
Connection ~ 2100 3550
$Comp
L Device:C C609
U 1 1 5DD78F06
P 4200 2550
F 0 "C609" H 4315 2596 50  0000 L CNN
F 1 "4u7/50V" H 4315 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 4238 2400 50  0001 C CNN
F 3 "~" H 4200 2550 50  0001 C CNN
	1    4200 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 2400 4200 2100
$Comp
L Device:C C611
U 1 1 5DD7C537
P 4800 2550
F 0 "C611" H 4915 2596 50  0000 L CNN
F 1 "4u7/50V" H 4915 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 4838 2400 50  0001 C CNN
F 3 "~" H 4800 2550 50  0001 C CNN
	1    4800 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 2400 4800 2100
Wire Wire Line
	4800 2100 4200 2100
Connection ~ 4200 2100
Wire Wire Line
	4200 3550 4200 2700
Wire Wire Line
	4200 3550 4800 3550
Wire Wire Line
	4800 3550 4800 2700
Connection ~ 4200 3550
$Comp
L Device:D_Schottky D602
U 1 1 5DD85EFF
P 2950 2100
F 0 "D602" H 2950 1884 50  0000 C CNN
F 1 "PMEG6010CEJ" H 2950 1975 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 2950 2100 50  0001 C CNN
F 3 "~" H 2950 2100 50  0001 C CNN
	1    2950 2100
	-1   0    0    1   
$EndComp
$Comp
L Device:C C601
U 1 1 5DD8869E
P 650 2550
F 0 "C601" H 765 2596 50  0000 L CNN
F 1 "4u7/50V" H 765 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 688 2400 50  0001 C CNN
F 3 "~" H 650 2550 50  0001 C CNN
	1    650  2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  2400 650  2100
Wire Wire Line
	650  2100 1150 2100
Connection ~ 1150 2100
Wire Wire Line
	650  2700 650  3550
Wire Wire Line
	650  3550 1150 3550
Connection ~ 1150 3550
Wire Wire Line
	2100 3600 2100 3550
$Comp
L ETH1CLCR1:+24VF #PWR0601
U 1 1 5DD94C6F
P 650 1950
F 0 "#PWR0601" H 650 1800 50  0001 C CNN
F 1 "+24VF" H 665 2123 50  0000 C CNN
F 2 "" H 650 1950 50  0001 C CNN
F 3 "" H 650 1950 50  0001 C CNN
	1    650  1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  1950 650  2100
Connection ~ 650  2100
Wire Wire Line
	5000 2100 4800 2100
Connection ~ 4800 2100
Wire Wire Line
	4800 3550 5300 3550
Wire Wire Line
	5300 3550 5300 2400
Connection ~ 4800 3550
$Comp
L Device:C C613
U 1 1 5DDAAA7C
P 5650 2550
F 0 "C613" H 5765 2596 50  0000 L CNN
F 1 "4u7/50V" H 5765 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5688 2400 50  0001 C CNN
F 3 "~" H 5650 2550 50  0001 C CNN
	1    5650 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 2400 5650 2100
Wire Wire Line
	5650 2100 5600 2100
Wire Wire Line
	5650 2700 5650 3550
Wire Wire Line
	5650 3550 5300 3550
Connection ~ 5300 3550
Connection ~ 5650 2100
$Comp
L ETH1CLCR1:+15VF #PWR0610
U 1 1 5DDB9470
P 5850 2050
F 0 "#PWR0610" H 5850 1900 50  0001 C CNN
F 1 "+15VF" H 5865 2223 50  0000 C CNN
F 2 "" H 5850 2050 50  0001 C CNN
F 3 "" H 5850 2050 50  0001 C CNN
	1    5850 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 2050 5850 2100
Connection ~ 2600 2100
Wire Wire Line
	2600 2100 2800 2100
Wire Wire Line
	3350 3550 2100 3550
Wire Wire Line
	2400 2800 3350 2800
Connection ~ 3350 2800
Wire Wire Line
	3350 2800 3350 2900
$Comp
L Device:C C607
U 1 1 5DE2A0D5
P 3750 2550
F 0 "C607" H 3865 2596 50  0000 L CNN
F 1 "4p7" H 3865 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3788 2400 50  0001 C CNN
F 3 "~" H 3750 2550 50  0001 C CNN
	1    3750 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 2700 3350 2800
Wire Wire Line
	3350 2800 3750 2800
Wire Wire Line
	3750 2800 3750 2700
Wire Wire Line
	3750 2400 3750 2300
Wire Wire Line
	3750 2300 3350 2300
Connection ~ 3350 2300
Wire Wire Line
	3350 2300 3350 2400
Wire Wire Line
	3350 2100 4200 2100
Connection ~ 3350 2100
Wire Wire Line
	3350 3550 4200 3550
Connection ~ 3350 3550
$Comp
L ETH1CLCR1:LT8330_S6 U602
U 1 1 5DE72066
P 1900 5950
F 0 "U602" H 1800 6400 50  0000 L CNN
F 1 "LT8330_S6" H 1700 6100 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:TSOT-23-6_HandSoldering" H 2800 6250 50  0001 C CNN
F 3 "" H 2800 6250 50  0001 C CNN
	1    1900 5950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R603
U 1 1 5DE7206C
P 1150 5700
F 0 "R603" H 1220 5746 50  0000 L CNN
F 1 "1M" H 1220 5655 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1080 5700 50  0001 C CNN
F 3 "~" H 1150 5700 50  0001 C CNN
	1    1150 5700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1400 5950 1150 5950
Wire Wire Line
	1150 5950 1150 5850
$Comp
L Device:R R604
U 1 1 5DE72074
P 1150 6200
F 0 "R604" H 1220 6246 50  0000 L CNN
F 1 "287k" H 1220 6155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1080 6200 50  0001 C CNN
F 3 "~" H 1150 6200 50  0001 C CNN
	1    1150 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1150 6050 1150 5950
Connection ~ 1150 5950
Wire Wire Line
	1150 5550 1150 5400
Wire Wire Line
	1150 5400 1700 5400
Wire Wire Line
	1700 5400 1700 5450
$Comp
L ETH1CLCR1:74489440068 L602
U 1 1 5DE7207F
P 1900 5400
F 0 "L602" H 1900 5625 50  0000 C CNN
F 1 "74489440068" H 1900 5534 50  0000 C CNN
F 2 "ETH1CLCR1:74489440068" H 1950 5800 50  0001 C CNN
F 3 "" H 1950 5800 50  0001 C CNN
	1    1900 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 5400 1700 5400
Connection ~ 1700 5400
Wire Wire Line
	2050 5400 2100 5400
Wire Wire Line
	2100 5400 2100 5450
$Comp
L ETH1CLCR1:74489440068 L602
U 2 1 5DE72089
P 2950 5400
F 0 "L602" H 2950 5625 50  0000 C CNN
F 1 "74489440068" H 2950 5534 50  0000 C CNN
F 2 "ETH1CLCR1:74489440068" H 3000 5800 50  0001 C CNN
F 3 "" H 3000 5800 50  0001 C CNN
	2    2950 5400
	-1   0    0    -1  
$EndComp
$Comp
L Device:C C604
U 1 1 5DE7208F
P 1700 6650
F 0 "C604" H 1815 6696 50  0000 L CNN
F 1 "1u" H 1815 6605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1738 6500 50  0001 C CNN
F 3 "~" H 1700 6650 50  0001 C CNN
	1    1700 6650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 6500 1700 6450
Wire Wire Line
	1700 6800 1700 6850
Wire Wire Line
	1700 6850 1150 6850
Wire Wire Line
	1150 6850 1150 6350
Wire Wire Line
	1700 6850 2100 6850
Wire Wire Line
	2100 6850 2100 6450
Connection ~ 1700 6850
$Comp
L Device:R R608
U 1 1 5DE7209C
P 3350 6350
F 0 "R608" H 3420 6396 50  0000 L CNN
F 1 "R" H 3420 6305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3280 6350 50  0001 C CNN
F 3 "~" H 3350 6350 50  0001 C CNN
	1    3350 6350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C606
U 1 1 5DE720A2
P 2400 5400
F 0 "C606" V 2148 5400 50  0000 C CNN
F 1 "1u/HC" V 2239 5400 50  0000 C CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 2438 5250 50  0001 C CNN
F 3 "~" H 2400 5400 50  0001 C CNN
	1    2400 5400
	0    1    1    0   
$EndComp
Wire Wire Line
	2250 5400 2100 5400
Connection ~ 2100 5400
Wire Wire Line
	2600 5500 2600 5400
Wire Wire Line
	2550 5400 2600 5400
Wire Wire Line
	2600 5850 2600 5800
$Comp
L Device:R R607
U 1 1 5DE720B3
P 3350 5850
F 0 "R607" H 3420 5896 50  0000 L CNN
F 1 "1M" H 3420 5805 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3280 5850 50  0001 C CNN
F 3 "~" H 3350 5850 50  0001 C CNN
	1    3350 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 5400 3350 5400
Wire Wire Line
	3350 5400 3350 5600
Wire Wire Line
	3350 6500 3350 6850
Connection ~ 2100 6850
$Comp
L Device:C C610
U 1 1 5DE720BD
P 4200 5850
F 0 "C610" H 4315 5896 50  0000 L CNN
F 1 "2u2/50V" H 4315 5805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 4238 5700 50  0001 C CNN
F 3 "~" H 4200 5850 50  0001 C CNN
	1    4200 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 5700 4200 5400
$Comp
L Device:C C612
U 1 1 5DE720C4
P 4800 5850
F 0 "C612" H 4915 5896 50  0000 L CNN
F 1 "2u2/50V" H 4915 5805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 4838 5700 50  0001 C CNN
F 3 "~" H 4800 5850 50  0001 C CNN
	1    4800 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 5700 4800 5400
Wire Wire Line
	4800 5400 4200 5400
Connection ~ 4200 5400
Wire Wire Line
	4200 6850 4200 6000
Wire Wire Line
	4200 6850 4800 6850
Wire Wire Line
	4800 6850 4800 6000
Connection ~ 4200 6850
$Comp
L Device:D_Schottky D601
U 1 1 5DE720D1
P 2600 5650
F 0 "D601" V 2646 5571 50  0000 R CNN
F 1 "PMEG6010CEJ" V 2555 5571 50  0000 R CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 2600 5650 50  0001 C CNN
F 3 "~" H 2600 5650 50  0001 C CNN
	1    2600 5650
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C602
U 1 1 5DE720D7
P 650 5850
F 0 "C602" H 765 5896 50  0000 L CNN
F 1 "4u7/50V" H 765 5805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 688 5700 50  0001 C CNN
F 3 "~" H 650 5850 50  0001 C CNN
	1    650  5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  5700 650  5400
Wire Wire Line
	650  5400 1150 5400
Connection ~ 1150 5400
Wire Wire Line
	650  6000 650  6850
Wire Wire Line
	650  6850 1150 6850
Connection ~ 1150 6850
Wire Wire Line
	2100 6900 2100 6850
$Comp
L ETH1CLCR1:+24VF #PWR0602
U 1 1 5DE720EA
P 650 5250
F 0 "#PWR0602" H 650 5100 50  0001 C CNN
F 1 "+24VF" H 665 5423 50  0000 C CNN
F 2 "" H 650 5250 50  0001 C CNN
F 3 "" H 650 5250 50  0001 C CNN
	1    650  5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  5250 650  5400
Connection ~ 650  5400
Wire Wire Line
	5000 5400 4800 5400
Connection ~ 4800 5400
Wire Wire Line
	4800 6850 5300 6850
Wire Wire Line
	5300 6850 5300 5700
Connection ~ 4800 6850
$Comp
L Device:C C614
U 1 1 5DE720FD
P 5650 5850
F 0 "C614" H 5765 5896 50  0000 L CNN
F 1 "4u7/50V" H 5765 5805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 5688 5700 50  0001 C CNN
F 3 "~" H 5650 5850 50  0001 C CNN
	1    5650 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 5700 5650 5400
Wire Wire Line
	5650 5400 5600 5400
Wire Wire Line
	5650 6000 5650 6850
Wire Wire Line
	5650 6850 5300 6850
Connection ~ 5300 6850
Connection ~ 5650 5400
Wire Wire Line
	5850 5350 5850 5400
Connection ~ 2600 5400
Wire Wire Line
	2600 5400 2800 5400
Wire Wire Line
	3350 6850 2100 6850
Wire Wire Line
	2400 6100 3350 6100
Connection ~ 3350 6100
Wire Wire Line
	3350 6100 3350 6200
$Comp
L Device:C C608
U 1 1 5DE7211E
P 3750 5850
F 0 "C608" H 3865 5896 50  0000 L CNN
F 1 "4p7" H 3865 5805 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3788 5700 50  0001 C CNN
F 3 "~" H 3750 5850 50  0001 C CNN
	1    3750 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 6000 3350 6100
Wire Wire Line
	3350 6100 3750 6100
Wire Wire Line
	3750 6100 3750 6000
Wire Wire Line
	3750 5700 3750 5600
Wire Wire Line
	3750 5600 3350 5600
Connection ~ 3350 5600
Wire Wire Line
	3350 5600 3350 5700
Wire Wire Line
	3350 5400 4200 5400
Connection ~ 3350 5400
Wire Wire Line
	3350 6850 4200 6850
Connection ~ 3350 6850
Wire Wire Line
	10450 5500 10650 5500
Wire Wire Line
	10150 6100 10650 6100
Wire Wire Line
	8100 5500 8250 5500
Wire Wire Line
	8950 5500 8800 5500
Wire Wire Line
	8700 5500 8550 5500
Connection ~ 8700 5500
Wire Wire Line
	8700 5650 8700 5500
Wire Wire Line
	8700 6100 9250 6100
Wire Wire Line
	8100 6100 8700 6100
Connection ~ 8700 6100
Wire Wire Line
	8700 5950 8700 6100
$Comp
L Device:C C?
U 1 1 5DED3D42
P 8700 5800
AR Path="/5DC846AF/5DED3D42" Ref="C?"  Part="1" 
AR Path="/5DCE1F8B/5DED3D42" Ref="C?"  Part="1" 
AR Path="/5DD0DBE6/5DED3D42" Ref="C?"  Part="1" 
AR Path="/5DEC0296/5DED3D42" Ref="C621"  Part="1" 
F 0 "C621" H 8815 5846 50  0000 L CNN
F 1 "10u/50V" H 8815 5755 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8738 5650 50  0001 C CNN
F 3 "~" H 8700 5800 50  0001 C CNN
	1    8700 5800
	1    0    0    -1  
$EndComp
$Comp
L Device:L L?
U 1 1 5DED3D48
P 8400 5500
AR Path="/5DC846AF/5DED3D48" Ref="L?"  Part="1" 
AR Path="/5DCE1F8B/5DED3D48" Ref="L?"  Part="1" 
AR Path="/5DD0DBE6/5DED3D48" Ref="L?"  Part="1" 
AR Path="/5DEC0296/5DED3D48" Ref="L604"  Part="1" 
F 0 "L604" V 8590 5500 50  0000 C CNN
F 1 "TCK-141" V 8499 5500 50  0000 C CNN
F 2 "ETH1CLCR1:TCK-141" H 8400 5500 50  0001 C CNN
F 3 "~" H 8400 5500 50  0001 C CNN
	1    8400 5500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8100 5950 8100 6100
Wire Wire Line
	8100 5650 8100 5500
$Comp
L Device:C C?
U 1 1 5DED3D51
P 8100 5800
AR Path="/5DC846AF/5DED3D51" Ref="C?"  Part="1" 
AR Path="/5DCE1F8B/5DED3D51" Ref="C?"  Part="1" 
AR Path="/5DD0DBE6/5DED3D51" Ref="C?"  Part="1" 
AR Path="/5DEC0296/5DED3D51" Ref="C619"  Part="1" 
F 0 "C619" H 8215 5846 50  0000 L CNN
F 1 "10u/50V" H 8215 5755 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8138 5650 50  0001 C CNN
F 3 "~" H 8100 5800 50  0001 C CNN
	1    8100 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10650 5350 10650 5500
$Comp
L ETH1CLCR1:TSR1-2450 U?
U 1 1 5DED3D5A
P 9250 5550
AR Path="/5DC846AF/5DED3D5A" Ref="U?"  Part="1" 
AR Path="/5DCE1F8B/5DED3D5A" Ref="U?"  Part="1" 
AR Path="/5DD0DBE6/5DED3D5A" Ref="U?"  Part="1" 
AR Path="/5DEC0296/5DED3D5A" Ref="U608"  Part="1" 
F 0 "U608" H 9250 5865 50  0000 C CNN
F 1 "TSR1-2490" H 9250 5774 50  0000 C CNN
F 2 "ETH1CLCR1:TSR1" H 9250 5550 50  0001 C CNN
F 3 "" H 9250 5550 50  0001 C CNN
	1    9250 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 5800 10150 6100
Wire Wire Line
	10650 6100 10650 5950
Connection ~ 10150 6100
Wire Wire Line
	9600 6100 10150 6100
Wire Wire Line
	9850 5500 9600 5500
Connection ~ 10650 5500
Wire Wire Line
	10650 5650 10650 5500
$Comp
L Device:C C?
U 1 1 5DED3D67
P 10650 5800
AR Path="/5DC846AF/5DED3D67" Ref="C?"  Part="1" 
AR Path="/5DCE1F8B/5DED3D67" Ref="C?"  Part="1" 
AR Path="/5DD0DBE6/5DED3D67" Ref="C?"  Part="1" 
AR Path="/5DEC0296/5DED3D67" Ref="C627"  Part="1" 
F 0 "C627" H 10765 5846 50  0000 L CNN
F 1 "10u/16V" H 10765 5755 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 10688 5650 50  0001 C CNN
F 3 "~" H 10650 5800 50  0001 C CNN
	1    10650 5800
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM1117-3.3 U?
U 1 1 5DED3D6D
P 10150 5500
AR Path="/5DC846AF/5DED3D6D" Ref="U?"  Part="1" 
AR Path="/5DCE1F8B/5DED3D6D" Ref="U?"  Part="1" 
AR Path="/5DD0DBE6/5DED3D6D" Ref="U?"  Part="1" 
AR Path="/5DEC0296/5DED3D6D" Ref="U611"  Part="1" 
F 0 "U611" H 10150 5742 50  0000 C CNN
F 1 "LM1117IMP-5.0/NOPB" H 10150 5650 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 10150 5500 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 10150 5500 50  0001 C CNN
	1    10150 5500
	1    0    0    -1  
$EndComp
Connection ~ 9600 5500
Wire Wire Line
	9600 5650 9600 5500
Wire Wire Line
	9600 5950 9600 6100
$Comp
L Device:C C?
U 1 1 5DED3D76
P 9600 5800
AR Path="/5DC846AF/5DED3D76" Ref="C?"  Part="1" 
AR Path="/5DCE1F8B/5DED3D76" Ref="C?"  Part="1" 
AR Path="/5DD0DBE6/5DED3D76" Ref="C?"  Part="1" 
AR Path="/5DEC0296/5DED3D76" Ref="C624"  Part="1" 
F 0 "C624" H 9715 5846 50  0000 L CNN
F 1 "10u/16V" H 9715 5755 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 9638 5650 50  0001 C CNN
F 3 "~" H 9600 5800 50  0001 C CNN
	1    9600 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 5500 9600 5500
Wire Wire Line
	9250 5800 9250 6100
Connection ~ 9600 6100
Connection ~ 9250 6100
Wire Wire Line
	9250 6100 9600 6100
Connection ~ 10650 6100
Wire Wire Line
	10650 6100 10650 6150
$Comp
L ETH1CLCR1:+5VF #PWR0625
U 1 1 5DEE4B5F
P 10650 5350
F 0 "#PWR0625" H 10650 5200 50  0001 C CNN
F 1 "+5VF" H 10665 5523 50  0000 C CNN
F 2 "" H 10650 5350 50  0001 C CNN
F 3 "" H 10650 5350 50  0001 C CNN
	1    10650 5350
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:-15VF #PWR0611
U 1 1 5DF2FE99
P 5850 5350
F 0 "#PWR0611" H 5850 5200 50  0001 C CNN
F 1 "-15VF" H 5865 5523 50  0000 C CNN
F 2 "" H 5850 5350 50  0001 C CNN
F 3 "" H 5850 5350 50  0001 C CNN
	1    5850 5350
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:DGNDF #PWR0606
U 1 1 5DF46A7A
P 2100 3600
F 0 "#PWR0606" H 2100 3350 50  0001 C CNN
F 1 "DGNDF" H 2105 3427 50  0000 C CNN
F 2 "" H 2100 3600 50  0001 C CNN
F 3 "" H 2100 3600 50  0001 C CNN
	1    2100 3600
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:DGNDF #PWR0608
U 1 1 5DF487C8
P 2600 2550
F 0 "#PWR0608" H 2600 2300 50  0001 C CNN
F 1 "DGNDF" H 2605 2377 50  0000 C CNN
F 2 "" H 2600 2550 50  0001 C CNN
F 3 "" H 2600 2550 50  0001 C CNN
	1    2600 2550
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:DGNDF #PWR0607
U 1 1 5DF49793
P 2100 6900
F 0 "#PWR0607" H 2100 6650 50  0001 C CNN
F 1 "DGNDF" H 2105 6727 50  0000 C CNN
F 2 "" H 2100 6900 50  0001 C CNN
F 3 "" H 2100 6900 50  0001 C CNN
	1    2100 6900
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:DGNDF #PWR0626
U 1 1 5DF4DCC7
P 10650 6150
F 0 "#PWR0626" H 10650 5900 50  0001 C CNN
F 1 "DGNDF" H 10655 5977 50  0000 C CNN
F 2 "" H 10650 6150 50  0001 C CNN
F 3 "" H 10650 6150 50  0001 C CNN
	1    10650 6150
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:DGNDF #PWR0624
U 1 1 5DF4E402
P 10650 4750
F 0 "#PWR0624" H 10650 4500 50  0001 C CNN
F 1 "DGNDF" H 10655 4577 50  0000 C CNN
F 2 "" H 10650 4750 50  0001 C CNN
F 3 "" H 10650 4750 50  0001 C CNN
	1    10650 4750
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:LM1117-3.3 U?
U 1 1 5E4B714B
P 10150 2900
AR Path="/5DC846AF/5E4B714B" Ref="U?"  Part="1" 
AR Path="/5DCE1F8B/5E4B714B" Ref="U?"  Part="1" 
AR Path="/5DD0DBE6/5E4B714B" Ref="U?"  Part="1" 
AR Path="/5DEC0296/5E4B714B" Ref="U609"  Part="1" 
F 0 "U609" H 10150 3142 50  0000 C CNN
F 1 "LM1117IMP-3.3/NOPB" H 10150 3050 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 10150 2900 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 10150 2900 50  0001 C CNN
	1    10150 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 4250 9600 4100
Wire Wire Line
	9850 2900 9600 2900
Wire Wire Line
	9600 2900 9600 4100
$Comp
L Device:C C?
U 1 1 5E4CE9DB
P 10650 3200
AR Path="/5DC846AF/5E4CE9DB" Ref="C?"  Part="1" 
AR Path="/5DCE1F8B/5E4CE9DB" Ref="C?"  Part="1" 
AR Path="/5DD0DBE6/5E4CE9DB" Ref="C?"  Part="1" 
AR Path="/5DEC0296/5E4CE9DB" Ref="C625"  Part="1" 
F 0 "C625" H 10765 3246 50  0000 L CNN
F 1 "10u/16V" H 10765 3155 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 10688 3050 50  0001 C CNN
F 3 "~" H 10650 3200 50  0001 C CNN
	1    10650 3200
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:DGNDF #PWR0620
U 1 1 5E4E760E
P 10150 3400
F 0 "#PWR0620" H 10150 3150 50  0001 C CNN
F 1 "DGNDF" H 10155 3227 50  0000 C CNN
F 2 "" H 10150 3400 50  0001 C CNN
F 3 "" H 10150 3400 50  0001 C CNN
	1    10150 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 3400 10150 3200
$Comp
L ETH1CLCR1:DGNDF #PWR0622
U 1 1 5E4F37FA
P 10650 3400
F 0 "#PWR0622" H 10650 3150 50  0001 C CNN
F 1 "DGNDF" H 10655 3227 50  0000 C CNN
F 2 "" H 10650 3400 50  0001 C CNN
F 3 "" H 10650 3400 50  0001 C CNN
	1    10650 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	10650 3400 10650 3350
Wire Wire Line
	10650 3050 10650 2900
Wire Wire Line
	10650 2900 10450 2900
Wire Wire Line
	10650 2750 10650 2900
Connection ~ 10650 2900
$Comp
L ETH1CLCR1:DGNDF #PWR0609
U 1 1 5F7AA41C
P 2600 5850
F 0 "#PWR0609" H 2600 5600 50  0001 C CNN
F 1 "DGNDF" H 2605 5677 50  0000 C CNN
F 2 "" H 2600 5850 50  0001 C CNN
F 3 "" H 2600 5850 50  0001 C CNN
	1    2600 5850
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:TSR2 U607
U 1 1 5DE430A3
P 9250 4150
F 0 "U607" H 9250 4465 50  0000 C CNN
F 1 "TSR2-2450" H 9250 4374 50  0000 C CNN
F 2 "ETH1CLCR1:TSR2" H 9250 4150 50  0001 C CNN
F 3 "" H 9250 4150 50  0001 C CNN
	1    9250 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 3950 7050 4100
$Comp
L ETH1CLCR1:+24VF #PWR0614
U 1 1 5E1C68D9
P 7050 3950
F 0 "#PWR0614" H 7050 3800 50  0001 C CNN
F 1 "+24VF" H 7065 4123 50  0000 C CNN
F 2 "" H 7050 3950 50  0001 C CNN
F 3 "" H 7050 3950 50  0001 C CNN
	1    7050 3950
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:DGNDF #PWR0615
U 1 1 5DF4F662
P 7050 4750
F 0 "#PWR0615" H 7050 4500 50  0001 C CNN
F 1 "DGNDF" H 7055 4577 50  0000 C CNN
F 2 "" H 7050 4750 50  0001 C CNN
F 3 "" H 7050 4750 50  0001 C CNN
	1    7050 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 4750 7050 4700
Wire Wire Line
	7600 4100 7750 4100
Wire Wire Line
	7600 4250 7600 4100
Wire Wire Line
	7600 4550 7600 4700
Connection ~ 8200 4700
Wire Wire Line
	7600 4700 8200 4700
$Comp
L Device:C C?
U 1 1 5DCFB9E3
P 7600 4400
AR Path="/5DC846AF/5DCFB9E3" Ref="C?"  Part="1" 
AR Path="/5DCE1F8B/5DCFB9E3" Ref="C?"  Part="1" 
AR Path="/5DD0DBE6/5DCFB9E3" Ref="C?"  Part="1" 
AR Path="/5DEC0296/5DCFB9E3" Ref="C618"  Part="1" 
F 0 "C618" H 7715 4446 50  0000 L CNN
F 1 "10u/50V" H 7715 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 7638 4250 50  0001 C CNN
F 3 "~" H 7600 4400 50  0001 C CNN
	1    7600 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:L L?
U 1 1 5DCFB9EC
P 7900 4100
AR Path="/5DC846AF/5DCFB9EC" Ref="L?"  Part="1" 
AR Path="/5DCE1F8B/5DCFB9EC" Ref="L?"  Part="1" 
AR Path="/5DD0DBE6/5DCFB9EC" Ref="L?"  Part="1" 
AR Path="/5DEC0296/5DCFB9EC" Ref="L603"  Part="1" 
F 0 "L603" V 8090 4100 50  0000 C CNN
F 1 "TCK-141" V 7999 4100 50  0000 C CNN
F 2 "ETH1CLCR1:TCK-141" H 7900 4100 50  0001 C CNN
F 3 "~" H 7900 4100 50  0001 C CNN
	1    7900 4100
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C?
U 1 1 5E6ABE78
P 7050 4400
AR Path="/5DC846AF/5E6ABE78" Ref="C?"  Part="1" 
AR Path="/5DCE1F8B/5E6ABE78" Ref="C?"  Part="1" 
AR Path="/5DD0DBE6/5E6ABE78" Ref="C?"  Part="1" 
AR Path="/5DEC0296/5E6ABE78" Ref="C617"  Part="1" 
F 0 "C617" H 7165 4446 50  0000 L CNN
F 1 "10u/50V" H 7165 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 7088 4250 50  0001 C CNN
F 3 "~" H 7050 4400 50  0001 C CNN
	1    7050 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 4700 7600 4700
Connection ~ 7600 4700
Wire Wire Line
	7050 4100 7600 4100
Connection ~ 7600 4100
Wire Wire Line
	7050 4250 7050 4100
Connection ~ 7050 4100
Wire Wire Line
	7050 4550 7050 4700
Connection ~ 7050 4700
$Comp
L Device:C C?
U 1 1 5E789ECF
P 8750 4400
AR Path="/5DC846AF/5E789ECF" Ref="C?"  Part="1" 
AR Path="/5DCE1F8B/5E789ECF" Ref="C?"  Part="1" 
AR Path="/5DD0DBE6/5E789ECF" Ref="C?"  Part="1" 
AR Path="/5DEC0296/5E789ECF" Ref="C622"  Part="1" 
F 0 "C622" H 8865 4446 50  0000 L CNN
F 1 "10u/50V" H 8865 4355 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 8788 4250 50  0001 C CNN
F 3 "~" H 8750 4400 50  0001 C CNN
	1    8750 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 4100 8750 4250
Wire Wire Line
	8200 4100 8750 4100
Wire Wire Line
	8750 4550 8750 4700
Wire Wire Line
	8750 4100 8950 4100
Connection ~ 8750 4100
Wire Wire Line
	8750 4700 9250 4700
Connection ~ 8750 4700
Connection ~ 9250 4700
$Comp
L Connector:TestPoint TP?
U 1 1 5E1A35BB
P 650 7350
AR Path="/5DF36C0B/5E1A35BB" Ref="TP?"  Part="1" 
AR Path="/5DD0DBE6/5E1A35BB" Ref="TP?"  Part="1" 
AR Path="/5DEC0296/5E1A35BB" Ref="TP601"  Part="1" 
F 0 "TP601" H 708 7468 50  0000 L CNN
F 1 "5006" H 708 7377 50  0000 L CNN
F 2 "TestPoint:TestPoint_Loop_D2.60mm_Drill1.6mm_Beaded" H 850 7350 50  0001 C CNN
F 3 "~" H 850 7350 50  0001 C CNN
	1    650  7350
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:DGNDF #PWR0603
U 1 1 5E1AEE0F
P 650 7450
F 0 "#PWR0603" H 650 7200 50  0001 C CNN
F 1 "DGNDF" H 655 7277 50  0000 C CNN
F 2 "" H 650 7450 50  0001 C CNN
F 3 "" H 650 7450 50  0001 C CNN
	1    650  7450
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  7450 650  7350
$Comp
L power:PWR_FLAG #FLG0606
U 1 1 5E52D497
P 8800 5450
F 0 "#FLG0606" H 8800 5525 50  0001 C CNN
F 1 "PWR_FLAG" H 8800 5623 50  0000 C CNN
F 2 "" H 8800 5450 50  0001 C CNN
F 3 "~" H 8800 5450 50  0001 C CNN
	1    8800 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 5450 8800 5500
Connection ~ 8800 5500
Wire Wire Line
	8800 5500 8700 5500
Connection ~ 8100 6100
Connection ~ 8100 5500
$Comp
L ETH1CLCR1:DGNDF #PWR0617
U 1 1 5DF4AD33
P 7900 6150
F 0 "#PWR0617" H 7900 5900 50  0001 C CNN
F 1 "DGNDF" H 7905 5977 50  0000 C CNN
F 2 "" H 7900 6150 50  0001 C CNN
F 3 "" H 7900 6150 50  0001 C CNN
	1    7900 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 6100 8100 6100
Wire Wire Line
	7900 6150 7900 6100
Wire Wire Line
	7900 5350 7900 5500
$Comp
L ETH1CLCR1:+24VF #PWR0616
U 1 1 5DED3D95
P 7900 5350
F 0 "#PWR0616" H 7900 5200 50  0001 C CNN
F 1 "+24VF" H 7915 5523 50  0000 C CNN
F 2 "" H 7900 5350 50  0001 C CNN
F 3 "" H 7900 5350 50  0001 C CNN
	1    7900 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 5500 8100 5500
$Comp
L power:PWR_FLAG #FLG0604
U 1 1 5E57B65B
P 4200 5350
F 0 "#FLG0604" H 4200 5425 50  0001 C CNN
F 1 "PWR_FLAG" H 4200 5523 50  0000 C CNN
F 2 "" H 4200 5350 50  0001 C CNN
F 3 "~" H 4200 5350 50  0001 C CNN
	1    4200 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 5350 4200 5400
$Comp
L power:PWR_FLAG #FLG0603
U 1 1 5E588007
P 4200 2050
F 0 "#FLG0603" H 4200 2125 50  0001 C CNN
F 1 "PWR_FLAG" H 4200 2223 50  0000 C CNN
F 2 "" H 4200 2050 50  0001 C CNN
F 3 "~" H 4200 2050 50  0001 C CNN
	1    4200 2050
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0605
U 1 1 5E5A01D6
P 8750 4050
F 0 "#FLG0605" H 8750 4125 50  0001 C CNN
F 1 "PWR_FLAG" H 8750 4223 50  0000 C CNN
F 2 "" H 8750 4050 50  0001 C CNN
F 3 "~" H 8750 4050 50  0001 C CNN
	1    8750 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 4050 8750 4100
$Comp
L power:+3.3VP #PWR0621
U 1 1 5E73326F
P 10650 2750
F 0 "#PWR0621" H 10800 2700 50  0001 C CNN
F 1 "+3.3VP" H 10670 2893 50  0000 C CNN
F 2 "" H 10650 2750 50  0001 C CNN
F 3 "" H 10650 2750 50  0001 C CNN
	1    10650 2750
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+24VF #PWR0604
U 1 1 5DE107B6
P 1250 7450
F 0 "#PWR0604" H 1250 7300 50  0001 C CNN
F 1 "+24VF" H 1265 7623 50  0000 C CNN
F 2 "" H 1250 7450 50  0001 C CNN
F 3 "" H 1250 7450 50  0001 C CNN
	1    1250 7450
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0601
U 1 1 5DE10F55
P 1250 7450
F 0 "#FLG0601" H 1250 7525 50  0001 C CNN
F 1 "PWR_FLAG" H 1250 7623 50  0000 C CNN
F 2 "" H 1250 7450 50  0001 C CNN
F 3 "~" H 1250 7450 50  0001 C CNN
	1    1250 7450
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG0602
U 1 1 5DE65EAA
P 1700 7450
F 0 "#FLG0602" H 1700 7525 50  0001 C CNN
F 1 "PWR_FLAG" H 1700 7623 50  0000 C CNN
F 2 "" H 1700 7450 50  0001 C CNN
F 3 "~" H 1700 7450 50  0001 C CNN
	1    1700 7450
	-1   0    0    1   
$EndComp
$Comp
L ETH1CLCR1:DGNDF #PWR0605
U 1 1 5DE6634D
P 1700 7450
F 0 "#PWR0605" H 1700 7200 50  0001 C CNN
F 1 "DGNDF" H 1705 7277 50  0000 C CNN
F 2 "" H 1700 7450 50  0001 C CNN
F 3 "" H 1700 7450 50  0001 C CNN
	1    1700 7450
	-1   0    0    1   
$EndComp
Wire Wire Line
	5650 2100 5850 2100
Wire Wire Line
	5650 5400 5850 5400
$Comp
L Regulator_Linear:L7815 U603
U 1 1 5E3D3561
P 5300 2100
F 0 "U603" H 5300 2342 50  0000 C CNN
F 1 "MC7815BD2TG " H 5300 2251 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-263-2" H 5325 1950 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 5300 2050 50  0001 C CNN
	1    5300 2100
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7815 U605
U 1 1 5E3BDF7C
P 6350 2100
F 0 "U605" H 6350 2342 50  0000 C CNN
F 1 "MC78M12ABDTRKG" H 6350 2251 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 6375 1950 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 6350 2050 50  0001 C CNN
	1    6350 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 2100 5850 2100
Wire Wire Line
	4200 2050 4200 2100
Wire Wire Line
	6850 2050 6850 2100
Wire Wire Line
	6650 2100 6700 2100
$Comp
L ETH1CLCR1:+12VF #PWR0612
U 1 1 5E414385
P 6850 2050
F 0 "#PWR0612" H 6850 1900 50  0001 C CNN
F 1 "+12VF" H 6865 2223 50  0000 C CNN
F 2 "" H 6850 2050 50  0001 C CNN
F 3 "" H 6850 2050 50  0001 C CNN
	1    6850 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 5400 5850 5400
Wire Wire Line
	6850 5350 6850 5400
Wire Wire Line
	6650 5400 6700 5400
$Comp
L ETH1CLCR1:-12VF #PWR0613
U 1 1 5E4EFBD2
P 6850 5350
F 0 "#PWR0613" H 6850 5200 50  0001 C CNN
F 1 "-12VF" H 6865 5523 50  0000 C CNN
F 2 "" H 6850 5350 50  0001 C CNN
F 3 "" H 6850 5350 50  0001 C CNN
	1    6850 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C615
U 1 1 5E4F3F19
P 6700 2550
F 0 "C615" H 6815 2596 50  0000 L CNN
F 1 "4u7/50V" H 6815 2505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 6738 2400 50  0001 C CNN
F 3 "~" H 6700 2550 50  0001 C CNN
	1    6700 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 2400 6700 2100
Connection ~ 6700 2100
Wire Wire Line
	6700 2100 6850 2100
$Comp
L Device:C C616
U 1 1 5E53289B
P 6700 5850
F 0 "C616" H 6815 5896 50  0000 L CNN
F 1 "4u7/50V" H 6815 5805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric_Pad1.42x1.75mm_HandSolder" H 6738 5700 50  0001 C CNN
F 3 "~" H 6700 5850 50  0001 C CNN
	1    6700 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6700 5700 6700 5400
Connection ~ 6700 5400
Wire Wire Line
	6700 5400 6850 5400
Connection ~ 5850 5400
Connection ~ 5850 2100
$Comp
L Regulator_Linear:MC79M15_TO252 U604
U 1 1 5E19327E
P 5300 5400
F 0 "U604" H 5300 5158 50  0000 C CNN
F 1 "MC7915BD2TG" H 5300 5249 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-263-2" H 5300 5200 50  0001 C CIN
F 3 "http://www.onsemi.com/pub/Collateral/MC79M00-D.PDF" H 5300 5400 50  0001 C CNN
	1    5300 5400
	1    0    0    1   
$EndComp
$Comp
L Regulator_Linear:MC79M12_TO252 U606
U 1 1 5E1975D1
P 6350 5400
F 0 "U606" H 6350 5158 50  0000 C CNN
F 1 "MC79M12CDTG" H 6350 5249 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-2" H 6350 5200 50  0001 C CIN
F 3 "http://www.onsemi.com/pub/Collateral/MC79M00-D.PDF" H 6350 5400 50  0001 C CNN
	1    6350 5400
	1    0    0    1   
$EndComp
Wire Wire Line
	5650 3550 6350 3550
Wire Wire Line
	6700 3550 6700 2700
Connection ~ 5650 3550
Wire Wire Line
	6350 2400 6350 3550
Connection ~ 6350 3550
Wire Wire Line
	6350 3550 6700 3550
Wire Wire Line
	5650 6850 6350 6850
Wire Wire Line
	6700 6850 6700 6000
Connection ~ 5650 6850
Wire Wire Line
	6350 5700 6350 6850
Connection ~ 6350 6850
Wire Wire Line
	6350 6850 6700 6850
$Comp
L ETH1CLCR1:+24VF #PWR0619
U 1 1 5E91BD20
P 7850 2050
F 0 "#PWR0619" H 7850 1900 50  0001 C CNN
F 1 "+24VF" H 7865 2223 50  0000 C CNN
F 2 "" H 7850 2050 50  0001 C CNN
F 3 "" H 7850 2050 50  0001 C CNN
	1    7850 2050
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+24VDD #PWR0618
U 1 1 5E91C38B
P 7400 2050
F 0 "#PWR0618" H 7400 1900 50  0001 C CNN
F 1 "+24VDD" H 7415 2223 50  0000 C CNN
F 2 "" H 7400 2050 50  0001 C CNN
F 3 "" H 7400 2050 50  0001 C CNN
	1    7400 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 2050 7400 2100
Wire Wire Line
	7400 2100 7850 2100
Wire Wire Line
	7850 2100 7850 2050
$Comp
L ETH1CLCR1:DGNDF #PWR?
U 1 1 5E95CC6A
P 2100 7450
F 0 "#PWR?" H 2100 7200 50  0001 C CNN
F 1 "DGNDF" H 2105 7277 50  0000 C CNN
F 2 "" H 2100 7450 50  0001 C CNN
F 3 "" H 2100 7450 50  0001 C CNN
	1    2100 7450
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:AGNDF #PWR?
U 1 1 5E95D4F1
P 2450 7450
F 0 "#PWR?" H 2450 7200 50  0001 C CNN
F 1 "AGNDF" H 2455 7277 50  0000 C CNN
F 2 "" H 2450 7450 50  0001 C CNN
F 3 "" H 2450 7450 50  0001 C CNN
	1    2450 7450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 7450 2450 7400
Wire Wire Line
	2450 7400 2100 7400
Wire Wire Line
	2100 7400 2100 7450
$EndSCHEMATC