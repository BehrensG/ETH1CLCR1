EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 15
Title "Function generator power ampl. and source resistor"
Date "2020-01-18"
Rev "1.0"
Comp ""
Comment1 "Verification done."
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Q_PNP_BEC Q706
U 1 1 5E317F1D
P 4000 3800
F 0 "Q706" H 4191 3754 50  0000 L CNN
F 1 "MMBT4403L" H 4191 3845 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4200 3900 50  0001 C CNN
F 3 "~" H 4000 3800 50  0001 C CNN
	1    4000 3800
	1    0    0    1   
$EndComp
Wire Wire Line
	4100 2850 4100 2800
Wire Wire Line
	4100 3550 4100 3600
$Comp
L Device:D D705
U 1 1 5E31B79A
P 3600 3000
F 0 "D705" V 3646 2921 50  0000 R CNN
F 1 "1N4148" V 3555 2921 50  0000 R CNN
F 2 "Diode_SMD:D_SOD-123" H 3600 3000 50  0001 C CNN
F 3 "~" H 3600 3000 50  0001 C CNN
	1    3600 3000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3600 2850 3600 2600
Wire Wire Line
	3600 2600 3800 2600
$Comp
L Device:D D706
U 1 1 5E31BEEE
P 3600 3400
F 0 "D706" V 3646 3321 50  0000 R CNN
F 1 "1N4148" V 3555 3321 50  0000 R CNN
F 2 "Diode_SMD:D_SOD-123" H 3600 3400 50  0001 C CNN
F 3 "~" H 3600 3400 50  0001 C CNN
	1    3600 3400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3600 3150 3600 3200
Wire Wire Line
	3600 3550 3600 3800
Wire Wire Line
	3600 3800 3800 3800
$Comp
L Device:R R707
U 1 1 5E31DF19
P 3600 4000
F 0 "R707" H 3670 4046 50  0000 L CNN
F 1 "15k" H 3670 3955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3530 4000 50  0001 C CNN
F 3 "~" H 3600 4000 50  0001 C CNN
	1    3600 4000
	1    0    0    -1  
$EndComp
$Comp
L Device:R R706
U 1 1 5E31FAD7
P 3600 2400
F 0 "R706" H 3670 2446 50  0000 L CNN
F 1 "15k" H 3670 2355 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3530 2400 50  0001 C CNN
F 3 "~" H 3600 2400 50  0001 C CNN
	1    3600 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 2550 3600 2600
Connection ~ 3600 2600
Wire Wire Line
	3600 3850 3600 3800
Connection ~ 3600 3800
Wire Wire Line
	3600 2250 3600 2200
Wire Wire Line
	3600 2200 4100 2200
Wire Wire Line
	4100 2200 4100 2400
Wire Wire Line
	3600 4150 3600 4200
Wire Wire Line
	3600 4200 4100 4200
Wire Wire Line
	4100 4200 4100 4000
Connection ~ 3600 3200
Wire Wire Line
	3600 3200 3600 3250
Wire Wire Line
	4100 3200 4700 3200
Wire Wire Line
	4150 2200 4100 2200
Connection ~ 4100 2200
Wire Wire Line
	4150 4200 4100 4200
Connection ~ 4100 4200
Wire Wire Line
	4100 3150 4100 3200
Connection ~ 4100 3200
Wire Wire Line
	4100 3200 4100 3250
$Comp
L Device:R R708
U 1 1 5E35A823
P 4100 1900
F 0 "R708" V 3893 1900 50  0000 C CNN
F 1 "2k" V 3984 1900 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4030 1900 50  0001 C CNN
F 3 "~" H 4100 1900 50  0001 C CNN
	1    4100 1900
	0    1    1    0   
$EndComp
Wire Wire Line
	4250 1900 4700 1900
$Comp
L Device:R R703
U 1 1 5E35C49A
P 2500 3700
F 0 "R703" H 2570 3746 50  0000 L CNN
F 1 "2k" H 2570 3655 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 2430 3700 50  0001 C CNN
F 3 "~" H 2500 3700 50  0001 C CNN
	1    2500 3700
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:AGNDF #PWR0705
U 1 1 5E360FBA
P 2500 3900
F 0 "#PWR0705" H 2500 3650 50  0001 C CNN
F 1 "AGNDF" H 2505 3727 50  0000 C CNN
F 2 "" H 2500 3900 50  0001 C CNN
F 3 "" H 2500 3900 50  0001 C CNN
	1    2500 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 3900 2500 3850
Wire Wire Line
	4700 1900 4700 3200
Wire Wire Line
	2500 1900 2500 3100
Wire Wire Line
	2500 1900 3950 1900
Connection ~ 2500 3100
Wire Wire Line
	2500 3100 2500 3550
$Comp
L Device:R R719
U 1 1 5E393A7D
P 6550 3200
F 0 "R719" V 6343 3200 50  0000 C CNN
F 1 "100k" V 6434 3200 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6480 3200 50  0001 C CNN
F 3 "~" H 6550 3200 50  0001 C CNN
	1    6550 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 3200 5400 3200
Connection ~ 4700 3200
$Comp
L Device:R R720
U 1 1 5E3981DC
P 7000 3600
F 0 "R720" H 7070 3646 50  0000 L CNN
F 1 "56" H 7070 3555 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6930 3600 50  0001 C CNN
F 3 "~" H 7000 3600 50  0001 C CNN
	1    7000 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 3450 7000 3200
Wire Wire Line
	7000 3200 6700 3200
$Comp
L Device:D_Zener D707
U 1 1 5E39B636
P 7000 3950
F 0 "D707" V 6954 4029 50  0000 L CNN
F 1 "CMDZ5256B TR" V 7045 4029 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 7000 3950 50  0001 C CNN
F 3 "~" H 7000 3950 50  0001 C CNN
	1    7000 3950
	0    1    1    0   
$EndComp
$Comp
L Device:D_Zener D708
U 1 1 5E39BE55
P 7000 4300
F 0 "D708" V 7046 4221 50  0000 R CNN
F 1 "CMDZ5256B TR" V 6955 4221 50  0000 R CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 7000 4300 50  0001 C CNN
F 3 "~" H 7000 4300 50  0001 C CNN
	1    7000 4300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7000 4150 7000 4100
Wire Wire Line
	7000 3800 7000 3750
$Comp
L ETH1CLCR1:AGNDF #PWR0731
U 1 1 5E39F2D3
P 7000 4500
F 0 "#PWR0731" H 7000 4250 50  0001 C CNN
F 1 "AGNDF" H 7005 4327 50  0000 C CNN
F 2 "" H 7000 4500 50  0001 C CNN
F 3 "" H 7000 4500 50  0001 C CNN
	1    7000 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4500 7000 4450
Wire Wire Line
	5700 1800 5400 1800
Wire Wire Line
	5400 1800 5400 2500
Wire Wire Line
	5700 2500 5400 2500
Wire Wire Line
	5400 2500 5400 2850
Wire Wire Line
	5700 2850 5400 2850
Connection ~ 5400 2850
Wire Wire Line
	5400 2850 5400 3200
$Comp
L Device:R R718
U 1 1 5E3FD008
P 6550 2850
F 0 "R718" V 6343 2850 50  0000 C CNN
F 1 "10k" V 6434 2850 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6480 2850 50  0001 C CNN
F 3 "~" H 6550 2850 50  0001 C CNN
	1    6550 2850
	0    1    1    0   
$EndComp
$Comp
L Device:R R717
U 1 1 5E3FE5CD
P 6550 2500
F 0 "R717" V 6343 2500 50  0000 C CNN
F 1 "2k" V 6434 2500 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6480 2500 50  0001 C CNN
F 3 "~" H 6550 2500 50  0001 C CNN
	1    6550 2500
	0    1    1    0   
$EndComp
$Comp
L Device:R R715
U 1 1 5E3FE9F0
P 6550 1800
F 0 "R715" V 6343 1800 50  0000 C CNN
F 1 "200" V 6434 1800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6480 1800 50  0001 C CNN
F 3 "~" H 6550 1800 50  0001 C CNN
	1    6550 1800
	0    1    1    0   
$EndComp
$Comp
L Device:R R713
U 1 1 5E3FEE05
P 6550 1050
F 0 "R713" V 6343 1050 50  0000 C CNN
F 1 "10" V 6434 1050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6480 1050 50  0001 C CNN
F 3 "~" H 6550 1050 50  0001 C CNN
	1    6550 1050
	0    1    1    0   
$EndComp
$Comp
L ETH1CLCR1:+5VF #PWR0703
U 1 1 5E4066C3
P 1250 6300
F 0 "#PWR0703" H 1250 6150 50  0001 C CNN
F 1 "+5VF" H 1265 6473 50  0000 C CNN
F 2 "" H 1250 6300 50  0001 C CNN
F 3 "" H 1250 6300 50  0001 C CNN
	1    1250 6300
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+5VF #PWR0706
U 1 1 5E4076B6
P 3250 4650
F 0 "#PWR0706" H 3250 4500 50  0001 C CNN
F 1 "+5VF" H 3265 4823 50  0000 C CNN
F 2 "" H 3250 4650 50  0001 C CNN
F 3 "" H 3250 4650 50  0001 C CNN
	1    3250 4650
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+5VF #PWR0708
U 1 1 5E407A59
P 3250 6300
F 0 "#PWR0708" H 3250 6150 50  0001 C CNN
F 1 "+5VF" H 3265 6473 50  0000 C CNN
F 2 "" H 3250 6300 50  0001 C CNN
F 3 "" H 3250 6300 50  0001 C CNN
	1    3250 6300
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+5VF #PWR0701
U 1 1 5E408269
P 1250 4650
F 0 "#PWR0701" H 1250 4500 50  0001 C CNN
F 1 "+5VF" H 1265 4823 50  0000 C CNN
F 2 "" H 1250 4650 50  0001 C CNN
F 3 "" H 1250 4650 50  0001 C CNN
	1    1250 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 1050 6000 1050
Wire Wire Line
	6700 1050 7000 1050
Connection ~ 7000 3200
Wire Wire Line
	6000 2850 6400 2850
Wire Wire Line
	6700 2850 7000 2850
Connection ~ 7000 2850
Wire Wire Line
	7000 2850 7000 3200
Wire Wire Line
	6000 2500 6300 2500
Wire Wire Line
	6700 2500 6800 2500
Wire Wire Line
	7000 2500 7000 2850
Wire Wire Line
	6000 1800 6300 1800
$Comp
L Device:C C701
U 1 1 5E448F9B
P 1550 5750
F 0 "C701" V 1298 5750 50  0000 C CNN
F 1 "10p" V 1389 5750 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1588 5600 50  0001 C CNN
F 3 "~" H 1550 5750 50  0001 C CNN
	1    1550 5750
	0    1    1    0   
$EndComp
Wire Wire Line
	1400 5750 1250 5750
Wire Wire Line
	1250 5750 1250 5550
Wire Wire Line
	1700 5750 1800 5750
Wire Wire Line
	1800 5750 1800 5350
Wire Wire Line
	1800 5350 1550 5350
$Comp
L Device:R R701
U 1 1 5E452E95
P 2000 5350
F 0 "R701" V 1793 5350 50  0000 C CNN
F 1 "10k" V 1884 5350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1930 5350 50  0001 C CNN
F 3 "~" H 2000 5350 50  0001 C CNN
	1    2000 5350
	0    1    1    0   
$EndComp
Wire Wire Line
	1850 5350 1800 5350
Connection ~ 1800 5350
$Comp
L ETH1CLCR1:DGNDF #PWR0702
U 1 1 5E454A54
P 1250 5800
F 0 "#PWR0702" H 1250 5550 50  0001 C CNN
F 1 "DGNDF" H 1255 5627 50  0000 C CNN
F 2 "" H 1250 5800 50  0001 C CNN
F 3 "" H 1250 5800 50  0001 C CNN
	1    1250 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 5800 1250 5750
Connection ~ 1250 5750
$Comp
L Device:C C702
U 1 1 5E45A4F5
P 1550 7400
F 0 "C702" V 1298 7400 50  0000 C CNN
F 1 "10p" V 1389 7400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 1588 7250 50  0001 C CNN
F 3 "~" H 1550 7400 50  0001 C CNN
	1    1550 7400
	0    1    1    0   
$EndComp
Wire Wire Line
	1400 7400 1250 7400
Wire Wire Line
	1250 7400 1250 7200
Wire Wire Line
	1700 7400 1800 7400
Wire Wire Line
	1800 7400 1800 7000
Wire Wire Line
	1800 7000 1550 7000
$Comp
L Device:R R702
U 1 1 5E45A500
P 2000 7000
F 0 "R702" V 1793 7000 50  0000 C CNN
F 1 "10k" V 1884 7000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 1930 7000 50  0001 C CNN
F 3 "~" H 2000 7000 50  0001 C CNN
	1    2000 7000
	0    1    1    0   
$EndComp
Wire Wire Line
	1850 7000 1800 7000
Connection ~ 1800 7000
$Comp
L ETH1CLCR1:DGNDF #PWR0704
U 1 1 5E45A508
P 1250 7450
F 0 "#PWR0704" H 1250 7200 50  0001 C CNN
F 1 "DGNDF" H 1255 7277 50  0000 C CNN
F 2 "" H 1250 7450 50  0001 C CNN
F 3 "" H 1250 7450 50  0001 C CNN
	1    1250 7450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 7450 1250 7400
Connection ~ 1250 7400
$Comp
L Device:C C703
U 1 1 5E487065
P 3550 5750
F 0 "C703" V 3298 5750 50  0000 C CNN
F 1 "10p" V 3389 5750 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3588 5600 50  0001 C CNN
F 3 "~" H 3550 5750 50  0001 C CNN
	1    3550 5750
	0    1    1    0   
$EndComp
Wire Wire Line
	3400 5750 3250 5750
Wire Wire Line
	3250 5750 3250 5550
Wire Wire Line
	3700 5750 3800 5750
Wire Wire Line
	3800 5750 3800 5350
Wire Wire Line
	3800 5350 3550 5350
$Comp
L Device:R R704
U 1 1 5E487070
P 4000 5350
F 0 "R704" V 3793 5350 50  0000 C CNN
F 1 "10k" V 3884 5350 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3930 5350 50  0001 C CNN
F 3 "~" H 4000 5350 50  0001 C CNN
	1    4000 5350
	0    1    1    0   
$EndComp
Wire Wire Line
	3850 5350 3800 5350
Connection ~ 3800 5350
$Comp
L ETH1CLCR1:DGNDF #PWR0707
U 1 1 5E487078
P 3250 5800
F 0 "#PWR0707" H 3250 5550 50  0001 C CNN
F 1 "DGNDF" H 3255 5627 50  0000 C CNN
F 2 "" H 3250 5800 50  0001 C CNN
F 3 "" H 3250 5800 50  0001 C CNN
	1    3250 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 5800 3250 5750
Connection ~ 3250 5750
$Comp
L Device:C C704
U 1 1 5E496D41
P 3550 7400
F 0 "C704" V 3298 7400 50  0000 C CNN
F 1 "10p" V 3389 7400 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 3588 7250 50  0001 C CNN
F 3 "~" H 3550 7400 50  0001 C CNN
	1    3550 7400
	0    1    1    0   
$EndComp
Wire Wire Line
	3400 7400 3250 7400
Wire Wire Line
	3250 7400 3250 7200
Wire Wire Line
	3700 7400 3800 7400
Wire Wire Line
	3800 7400 3800 7000
Wire Wire Line
	3800 7000 3550 7000
$Comp
L Device:R R705
U 1 1 5E496D4C
P 4000 7000
F 0 "R705" V 3793 7000 50  0000 C CNN
F 1 "10k" V 3884 7000 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 3930 7000 50  0001 C CNN
F 3 "~" H 4000 7000 50  0001 C CNN
	1    4000 7000
	0    1    1    0   
$EndComp
Wire Wire Line
	3850 7000 3800 7000
Connection ~ 3800 7000
$Comp
L ETH1CLCR1:DGNDF #PWR0709
U 1 1 5E496D54
P 3250 7450
F 0 "#PWR0709" H 3250 7200 50  0001 C CNN
F 1 "DGNDF" H 3255 7277 50  0000 C CNN
F 2 "" H 3250 7450 50  0001 C CNN
F 3 "" H 3250 7450 50  0001 C CNN
	1    3250 7450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3250 7450 3250 7400
Connection ~ 3250 7400
Wire Wire Line
	3250 5050 3250 5100
Wire Wire Line
	1250 5050 1250 5100
Wire Wire Line
	3250 6700 3250 6750
Wire Wire Line
	1250 6700 1250 6750
$Comp
L Device:R R714
U 1 1 5E4DFEBC
P 6550 1450
F 0 "R714" V 6343 1450 50  0000 C CNN
F 1 "200" V 6434 1450 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6480 1450 50  0001 C CNN
F 3 "~" H 6550 1450 50  0001 C CNN
	1    6550 1450
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 1450 6300 1450
Wire Wire Line
	6300 1450 6300 1800
Connection ~ 6300 1800
Wire Wire Line
	6300 1800 6400 1800
Wire Wire Line
	6800 1800 7000 1800
Wire Wire Line
	6700 1800 6800 1800
Connection ~ 6800 1800
Wire Wire Line
	6700 1450 6800 1450
Wire Wire Line
	6800 1450 6800 1800
$Comp
L Device:R R716
U 1 1 5E5157DA
P 6550 2150
F 0 "R716" V 6343 2150 50  0000 C CNN
F 1 "2k" V 6434 2150 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6480 2150 50  0001 C CNN
F 3 "~" H 6550 2150 50  0001 C CNN
	1    6550 2150
	0    1    1    0   
$EndComp
Wire Wire Line
	6400 2150 6300 2150
Wire Wire Line
	6300 2150 6300 2500
Wire Wire Line
	6700 2150 6800 2150
Wire Wire Line
	6800 2150 6800 2500
Connection ~ 6300 2500
Wire Wire Line
	6300 2500 6400 2500
Connection ~ 6800 2500
Wire Wire Line
	6800 2500 7000 2500
Connection ~ 5400 2500
Connection ~ 7000 2500
Wire Wire Line
	7000 1050 7000 1800
Connection ~ 7000 1800
Wire Wire Line
	7000 1800 7000 2500
Wire Wire Line
	5400 1050 5400 1800
Connection ~ 5400 1800
Text HLabel 2200 3300 0    50   Input ~ 0
FGEN
Text HLabel 4200 7000 2    50   Input ~ 0
SR_10CTR
Wire Wire Line
	4200 7000 4150 7000
Text HLabel 4200 5350 2    50   Input ~ 0
SR_100CTR
Wire Wire Line
	4200 5350 4150 5350
Text HLabel 2200 7000 2    50   Input ~ 0
SR_1KCTR
Wire Wire Line
	2200 7000 2150 7000
Text HLabel 2200 5350 2    50   Input ~ 0
SR_10KCTR
Wire Wire Line
	2200 5350 2150 5350
$Comp
L Amplifier_Operational:TL072 U702
U 1 1 5DFEDDBD
P 7900 2600
F 0 "U702" H 8000 2350 50  0000 C CNN
F 1 "TL072" H 8000 2450 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 7900 2600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 7900 2600 50  0001 C CNN
	1    7900 2600
	1    0    0    1   
$EndComp
$Comp
L Amplifier_Operational:TL072 U702
U 2 1 5DFEF34F
P 9050 2150
F 0 "U702" H 9200 1900 50  0000 C CNN
F 1 "TL072" H 9200 2000 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 9050 2150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 9050 2150 50  0001 C CNN
	2    9050 2150
	1    0    0    1   
$EndComp
$Comp
L Amplifier_Operational:TL072 U702
U 3 1 5DFF2732
P 5300 7200
F 0 "U702" H 5258 7246 50  0000 L CNN
F 1 "TL072" H 5258 7155 50  0000 L CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 5300 7200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 5300 7200 50  0001 C CNN
	3    5300 7200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 2500 7550 2500
$Comp
L ETH1CLCR1:AGNDF #PWR0732
U 1 1 5E0240ED
P 7600 2700
F 0 "#PWR0732" H 7600 2450 50  0001 C CNN
F 1 "AGNDF" V 7605 2572 50  0000 R CNN
F 2 "" H 7600 2700 50  0001 C CNN
F 3 "" H 7600 2700 50  0001 C CNN
	1    7600 2700
	0    1    1    0   
$EndComp
$Comp
L Device:R R721
U 1 1 5E0289B4
P 7900 2050
F 0 "R721" V 7693 2050 50  0000 C CNN
F 1 "205" V 7784 2050 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7830 2050 50  0001 C CNN
F 3 "~" H 7900 2050 50  0001 C CNN
	1    7900 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	7750 2050 7550 2050
Wire Wire Line
	7550 2050 7550 2500
Connection ~ 7550 2500
Wire Wire Line
	7550 2500 7000 2500
Wire Wire Line
	8050 2050 8250 2050
Wire Wire Line
	8250 2050 8250 2600
Wire Wire Line
	8250 2600 8200 2600
$Comp
L Device:C C713
U 1 1 5E034F4B
P 8450 2050
F 0 "C713" V 8198 2050 50  0000 C CNN
F 1 "43p/200V" V 8289 2050 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8488 1900 50  0001 C CNN
F 3 "~" H 8450 2050 50  0001 C CNN
	1    8450 2050
	0    1    1    0   
$EndComp
Wire Wire Line
	8250 2050 8300 2050
Connection ~ 8250 2050
Wire Wire Line
	8600 2050 8700 2050
$Comp
L ETH1CLCR1:AGNDF #PWR0734
U 1 1 5E047572
P 8750 2250
F 0 "#PWR0734" H 8750 2000 50  0001 C CNN
F 1 "AGNDF" V 8755 2122 50  0000 R CNN
F 2 "" H 8750 2250 50  0001 C CNN
F 3 "" H 8750 2250 50  0001 C CNN
	1    8750 2250
	0    1    1    0   
$EndComp
Connection ~ 8700 2050
Wire Wire Line
	8700 2050 8750 2050
Wire Wire Line
	7000 3200 9900 3200
$Comp
L Device:C C709
U 1 1 5E0713AD
P 6100 7200
F 0 "C709" H 6215 7246 50  0000 L CNN
F 1 "100n" H 6215 7155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6138 7050 50  0001 C CNN
F 3 "~" H 6100 7200 50  0001 C CNN
	1    6100 7200
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:AGNDF #PWR0723
U 1 1 5E085ACE
P 6100 7500
F 0 "#PWR0723" H 6100 7250 50  0001 C CNN
F 1 "AGNDF" H 6105 7327 50  0000 C CNN
F 2 "" H 6100 7500 50  0001 C CNN
F 3 "" H 6100 7500 50  0001 C CNN
	1    6100 7500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 7350 6100 7500
Wire Wire Line
	6100 7050 6100 6900
$Comp
L Device:C C710
U 1 1 5E096A20
P 6550 7200
F 0 "C710" H 6665 7246 50  0000 L CNN
F 1 "100n" H 6665 7155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6588 7050 50  0001 C CNN
F 3 "~" H 6550 7200 50  0001 C CNN
	1    6550 7200
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:AGNDF #PWR0725
U 1 1 5E096A2C
P 6550 7500
F 0 "#PWR0725" H 6550 7250 50  0001 C CNN
F 1 "AGNDF" H 6555 7327 50  0000 C CNN
F 2 "" H 6550 7500 50  0001 C CNN
F 3 "" H 6550 7500 50  0001 C CNN
	1    6550 7500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 7350 6550 7500
Wire Wire Line
	6550 7050 6550 6900
$Comp
L Device:C C711
U 1 1 5E09D22B
P 6100 6100
F 0 "C711" H 6215 6146 50  0000 L CNN
F 1 "100n" H 6215 6055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6138 5950 50  0001 C CNN
F 3 "~" H 6100 6100 50  0001 C CNN
	1    6100 6100
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:AGNDF #PWR0728
U 1 1 5E09D237
P 6100 6400
F 0 "#PWR0728" H 6100 6150 50  0001 C CNN
F 1 "AGNDF" H 6105 6227 50  0000 C CNN
F 2 "" H 6100 6400 50  0001 C CNN
F 3 "" H 6100 6400 50  0001 C CNN
	1    6100 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 6250 6100 6400
Wire Wire Line
	6100 5950 6100 5800
$Comp
L Device:C C712
U 1 1 5E09D23F
P 6550 6100
F 0 "C712" H 6665 6146 50  0000 L CNN
F 1 "100n" H 6665 6055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6588 5950 50  0001 C CNN
F 3 "~" H 6550 6100 50  0001 C CNN
	1    6550 6100
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:AGNDF #PWR0730
U 1 1 5E09D24B
P 6550 6400
F 0 "#PWR0730" H 6550 6150 50  0001 C CNN
F 1 "AGNDF" H 6555 6227 50  0000 C CNN
F 2 "" H 6550 6400 50  0001 C CNN
F 3 "" H 6550 6400 50  0001 C CNN
	1    6550 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 6250 6550 6400
Wire Wire Line
	6550 5950 6550 5800
$Comp
L Device:R_POT_TRIM RV701
U 1 1 5E0A9254
P 9550 1400
F 0 "RV701" V 9343 1400 50  0000 C CNN
F 1 "3314J-1-501E" V 9434 1400 50  0000 C CNN
F 2 "Potentiometer_SMD:Potentiometer_Bourns_3314J_Vertical" H 9550 1400 50  0001 C CNN
F 3 "~" H 9550 1400 50  0001 C CNN
	1    9550 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	8700 1400 9400 1400
NoConn ~ 9700 1400
$Comp
L ETH1CLCR1:+15VF #PWR0738
U 1 1 5E0DE8D7
P 9550 4950
F 0 "#PWR0738" H 9550 4800 50  0001 C CNN
F 1 "+15VF" H 9565 5123 50  0000 C CNN
F 2 "" H 9550 4950 50  0001 C CNN
F 3 "" H 9550 4950 50  0001 C CNN
	1    9550 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9200 4950 9350 4950
Wire Wire Line
	9200 5950 9350 5950
$Comp
L ETH1CLCR1:AGNDF #PWR0737
U 1 1 5E0DE8E5
P 9200 5950
F 0 "#PWR0737" H 9200 5700 50  0001 C CNN
F 1 "AGNDF" H 9205 5777 50  0000 C CNN
F 2 "" H 9200 5950 50  0001 C CNN
F 3 "" H 9200 5950 50  0001 C CNN
	1    9200 5950
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:-15VF #PWR0739
U 1 1 5E0DE8EB
P 9550 5950
F 0 "#PWR0739" H 9550 5800 50  0001 C CNN
F 1 "-15VF" H 9565 6123 50  0000 C CNN
F 2 "" H 9550 5950 50  0001 C CNN
F 3 "" H 9550 5950 50  0001 C CNN
	1    9550 5950
	-1   0    0    1   
$EndComp
$Comp
L Potentiometer_Digital:AD5293 U?
U 1 1 5E0DE8F1
P 9450 5450
AR Path="/5E252C19/5E0DE8F1" Ref="U?"  Part="1" 
AR Path="/5E314C16/5E0DE8F1" Ref="U704"  Part="1" 
F 0 "U704" H 10050 6000 50  0000 C CNN
F 1 "AD5293BRUZ-20" H 10050 5900 50  0000 C CNN
F 2 "Package_SO:TSSOP-14_4.4x5mm_P0.65mm" H 9450 4850 50  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/AD5293.pdf" H 9450 5450 50  0001 C CNN
	1    9450 5450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 5450 8700 5450
Wire Wire Line
	8750 5650 8700 5650
$Comp
L Device:C C714
U 1 1 5E0DE8FD
P 8750 6000
F 0 "C714" H 8865 6046 50  0000 L CNN
F 1 "1u" H 8865 5955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 8788 5850 50  0001 C CNN
F 3 "~" H 8750 6000 50  0001 C CNN
	1    8750 6000
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 5850 8750 5750
$Comp
L ETH1CLCR1:AGNDF #PWR0735
U 1 1 5E0DE904
P 8750 6150
F 0 "#PWR0735" H 8750 5900 50  0001 C CNN
F 1 "AGNDF" H 8755 5977 50  0000 C CNN
F 2 "" H 8750 6150 50  0001 C CNN
F 3 "" H 8750 6150 50  0001 C CNN
	1    8750 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 5150 8750 5150
Wire Wire Line
	8700 5350 8750 5350
NoConn ~ 10150 5650
Text HLabel 9900 2150 2    50   BiDi ~ 0
VLI
Text HLabel 9900 3200 2    50   Output ~ 0
HCUR
Wire Wire Line
	2200 3300 2700 3300
Wire Wire Line
	2500 3100 2700 3100
Text Label 9550 2050 1    50   ~ 0
TRIM_2
Text Label 9350 1400 2    50   ~ 0
TRIM_3
Text Label 10450 5250 2    50   ~ 0
TRIM_3
Wire Wire Line
	10450 5250 10150 5250
Text Label 10450 5450 2    50   ~ 0
TRIM_2
Wire Wire Line
	10450 5450 10150 5450
Wire Wire Line
	8700 5250 8750 5250
Text HLabel 8700 5150 0    50   Input ~ 0
FB_SDI
Text HLabel 8700 5250 0    50   Output ~ 0
FB_SDO
Text HLabel 8700 5350 0    50   Input ~ 0
FB_CLK
Text HLabel 8700 5450 0    50   Input ~ 0
FB_~CS
Text HLabel 7950 5550 0    50   Output ~ 0
FB_RDY
Text HLabel 8700 5650 0    50   Input ~ 0
FB_~RST
$Comp
L Device:R R722
U 1 1 5E1C1859
P 8000 5350
F 0 "R722" H 8070 5396 50  0000 L CNN
F 1 "2k2" H 8070 5305 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 7930 5350 50  0001 C CNN
F 3 "~" H 8000 5350 50  0001 C CNN
	1    8000 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 5500 8000 5550
Wire Wire Line
	4700 3200 4900 3200
Connection ~ 5400 3200
Wire Wire Line
	5200 3200 5400 3200
$Comp
L Device:R R711
U 1 1 5E25146B
P 5050 3600
F 0 "R711" V 4843 3600 50  0000 C CNN
F 1 "OPT" V 4934 3600 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4980 3600 50  0001 C CNN
F 3 "~" H 5050 3600 50  0001 C CNN
	1    5050 3600
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 3600 4700 3600
Wire Wire Line
	4700 3600 4700 3200
Wire Wire Line
	5200 3600 5400 3600
Wire Wire Line
	5400 3600 5400 3200
$Comp
L Device:CP C708
U 1 1 5E2673B9
P 5050 3200
F 0 "C708" V 5305 3200 50  0000 C CNN
F 1 " EEHZC1V221V" V 5214 3200 50  0000 C CNN
F 2 "Capacitor_SMD:CP_Elec_10x10" H 5088 3050 50  0001 C CNN
F 3 "~" H 5050 3200 50  0001 C CNN
	1    5050 3200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	9350 2150 9550 2150
$Comp
L Device:R R723
U 1 1 5E139404
P 9150 1750
F 0 "R723" V 8943 1750 50  0000 C CNN
F 1 "550" V 9034 1750 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 9080 1750 50  0001 C CNN
F 3 "~" H 9150 1750 50  0001 C CNN
	1    9150 1750
	0    1    1    0   
$EndComp
Wire Wire Line
	9000 1750 8700 1750
Connection ~ 8700 1750
Wire Wire Line
	8700 1750 8700 2050
Wire Wire Line
	8700 1400 8700 1750
Wire Wire Line
	9550 1550 9550 1750
Connection ~ 9550 2150
Wire Wire Line
	9550 2150 9900 2150
Wire Wire Line
	9300 1750 9550 1750
Connection ~ 9550 1750
Wire Wire Line
	9550 1750 9550 2150
$Comp
L ETH1CLCR1:+3.3VF #PWR0733
U 1 1 5E72777A
P 8000 5200
F 0 "#PWR0733" H 8000 5050 50  0001 C CNN
F 1 "+3.3VF" H 8015 5373 50  0000 C CNN
F 2 "" H 8000 5200 50  0001 C CNN
F 3 "" H 8000 5200 50  0001 C CNN
	1    8000 5200
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+3.3VF #PWR0736
U 1 1 5E727A6B
P 9200 4950
F 0 "#PWR0736" H 9200 4800 50  0001 C CNN
F 1 "+3.3VF" H 9215 5123 50  0000 C CNN
F 2 "" H 9200 4950 50  0001 C CNN
F 3 "" H 9200 4950 50  0001 C CNN
	1    9200 4950
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:-15VF #PWR0713
U 1 1 5E1926A7
P 4150 4200
F 0 "#PWR0713" H 4150 4050 50  0001 C CNN
F 1 "-15VF" V 4150 4350 50  0000 L CNN
F 2 "" H 4150 4200 50  0001 C CNN
F 3 "" H 4150 4200 50  0001 C CNN
	1    4150 4200
	0    1    1    0   
$EndComp
$Comp
L ETH1CLCR1:+15VF #PWR0712
U 1 1 5E19AE73
P 4150 2200
F 0 "#PWR0712" H 4150 2050 50  0001 C CNN
F 1 "+15VF" V 4150 2350 50  0000 L CNN
F 2 "" H 4150 2200 50  0001 C CNN
F 3 "" H 4150 2200 50  0001 C CNN
	1    4150 2200
	0    1    1    0   
$EndComp
$Comp
L ETH1CLCR1:LT1468 U701
U 1 1 5E1A5EBF
P 3050 3200
F 0 "U701" H 3150 3500 50  0000 L CNN
F 1 "LT1468" H 3150 3400 50  0000 L CNN
F 2 "Package_SO:SSOP-8_3.9x5.05mm_P1.27mm" H 3050 3200 50  0001 C CNN
F 3 "" H 3050 3200 50  0001 C CNN
	1    3050 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 3200 3600 3200
$Comp
L ETH1CLCR1:+15VF #PWR0710
U 1 1 5E1ADAB2
P 3000 2800
F 0 "#PWR0710" H 3000 2650 50  0001 C CNN
F 1 "+15VF" H 3015 2973 50  0000 C CNN
F 2 "" H 3000 2800 50  0001 C CNN
F 3 "" H 3000 2800 50  0001 C CNN
	1    3000 2800
	1    0    0    -1  
$EndComp
NoConn ~ 3200 3500
NoConn ~ 3100 3550
$Comp
L ETH1CLCR1:-15VF #PWR0711
U 1 1 5E1B9BBE
P 3000 3600
F 0 "#PWR0711" H 3000 3450 50  0001 C CNN
F 1 "-15VF" H 3015 3773 50  0000 C CNN
F 2 "" H 3000 3600 50  0001 C CNN
F 3 "" H 3000 3600 50  0001 C CNN
	1    3000 3600
	-1   0    0    1   
$EndComp
Connection ~ 4700 3600
Wire Wire Line
	5400 3600 5400 3800
Connection ~ 5400 3600
$Comp
L ETH1CLCR1:AQY212GS U703
U 1 1 5E9BD9A1
P 5700 3900
F 0 "U703" H 5700 4225 50  0000 C CNN
F 1 "AQY212GS" H 5700 4134 50  0000 C CNN
F 2 "ETH1CLCR1:AQY212GS" H 5700 4100 50  0001 C CNN
F 3 "" H 5700 4100 50  0001 C CNN
	1    5700 3900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5400 4000 4700 4000
Wire Wire Line
	4700 3600 4700 4000
$Comp
L Device:R R712
U 1 1 5E9CEFD9
P 6150 3800
F 0 "R712" V 5943 3800 50  0000 C CNN
F 1 "330" V 6034 3800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6080 3800 50  0001 C CNN
F 3 "~" H 6150 3800 50  0001 C CNN
	1    6150 3800
	0    1    1    0   
$EndComp
$Comp
L ETH1CLCR1:AGNDF #PWR0726
U 1 1 5E9D2BD8
P 6000 4000
F 0 "#PWR0726" H 6000 3750 50  0001 C CNN
F 1 "AGNDF" V 6005 3872 50  0000 R CNN
F 2 "" H 6000 4000 50  0001 C CNN
F 3 "" H 6000 4000 50  0001 C CNN
	1    6000 4000
	0    -1   -1   0   
$EndComp
Text HLabel 6300 3800 2    50   Input ~ 0
FB_CAP
$Comp
L Device:Q_NPN_BEC Q705
U 1 1 5E316416
P 4000 2600
F 0 "Q705" H 4191 2646 50  0000 L CNN
F 1 "MMBT4401L" H 4191 2555 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 4200 2700 50  0001 C CNN
F 3 "~" H 4000 2600 50  0001 C CNN
	1    4000 2600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R710
U 1 1 5E31AB77
P 4100 3400
F 0 "R710" H 4170 3446 50  0000 L CNN
F 1 "27/.25W" H 4170 3355 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4030 3400 50  0001 C CNN
F 3 "~" H 4100 3400 50  0001 C CNN
	1    4100 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R709
U 1 1 5E31A426
P 4100 3000
F 0 "R709" H 4170 3046 50  0000 L CNN
F 1 "27/.25W" H 4170 2955 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4030 3000 50  0001 C CNN
F 3 "~" H 4100 3000 50  0001 C CNN
	1    4100 3000
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:9012 K701
U 2 1 5E5F8D91
P 1250 4900
F 0 "K701" H 1328 4946 50  0000 L CNN
F 1 "9012" H 1328 4855 50  0000 L CNN
F 2 "ETH1CLCR1:9012" H 1500 4850 50  0001 C CNN
F 3 "" H 1500 4850 50  0001 C CNN
	2    1250 4900
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:9012 K703
U 1 1 5E61CF4C
P 5850 1800
F 0 "K703" V 6065 1800 50  0000 C CNN
F 1 "9012" V 5974 1800 50  0000 C CNN
F 2 "ETH1CLCR1:9012" H 6100 1750 50  0001 C CNN
F 3 "" H 6100 1750 50  0001 C CNN
	1    5850 1800
	0    -1   -1   0   
$EndComp
$Comp
L ETH1CLCR1:9012 K703
U 2 1 5E61CF52
P 3250 4900
F 0 "K703" H 3328 4946 50  0000 L CNN
F 1 "9012" H 3328 4855 50  0000 L CNN
F 2 "ETH1CLCR1:9012" H 3500 4850 50  0001 C CNN
F 3 "" H 3500 4850 50  0001 C CNN
	2    3250 4900
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:9012 K702
U 1 1 5E623CCD
P 5850 2500
F 0 "K702" V 6065 2500 50  0000 C CNN
F 1 "9012" V 5974 2500 50  0000 C CNN
F 2 "ETH1CLCR1:9012" H 6100 2450 50  0001 C CNN
F 3 "" H 6100 2450 50  0001 C CNN
	1    5850 2500
	0    -1   -1   0   
$EndComp
$Comp
L ETH1CLCR1:9012 K702
U 2 1 5E623CD3
P 1250 6550
F 0 "K702" H 1328 6596 50  0000 L CNN
F 1 "9012" H 1328 6505 50  0000 L CNN
F 2 "ETH1CLCR1:9012" H 1500 6500 50  0001 C CNN
F 3 "" H 1500 6500 50  0001 C CNN
	2    1250 6550
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:9012 K704
U 1 1 5E62A46A
P 5850 2850
F 0 "K704" V 6065 2850 50  0000 C CNN
F 1 "9012" V 5974 2850 50  0000 C CNN
F 2 "ETH1CLCR1:9012" H 6100 2800 50  0001 C CNN
F 3 "" H 6100 2800 50  0001 C CNN
	1    5850 2850
	0    -1   -1   0   
$EndComp
$Comp
L ETH1CLCR1:9012 K704
U 2 1 5E62A470
P 3250 6550
F 0 "K704" H 3328 6596 50  0000 L CNN
F 1 "9012" H 3328 6505 50  0000 L CNN
F 2 "ETH1CLCR1:9012" H 3500 6500 50  0001 C CNN
F 3 "" H 3500 6500 50  0001 C CNN
	2    3250 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 1050 5400 1050
$Comp
L ETH1CLCR1:9012 K701
U 1 1 5E5F8149
P 5850 1050
F 0 "K701" V 6065 1050 50  0000 C CNN
F 1 "9012" V 5974 1050 50  0000 C CNN
F 2 "ETH1CLCR1:9012" H 6100 1000 50  0001 C CNN
F 3 "" H 6100 1000 50  0001 C CNN
	1    5850 1050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1250 4650 1250 4700
$Comp
L Device:D D701
U 1 1 5E6733B7
P 1800 4900
F 0 "D701" V 1754 4979 50  0000 L CNN
F 1 "1N4148" V 1845 4979 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 1800 4900 50  0001 C CNN
F 3 "~" H 1800 4900 50  0001 C CNN
	1    1800 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	1250 5100 1800 5100
Wire Wire Line
	1800 5100 1800 5050
Connection ~ 1250 5100
Wire Wire Line
	1250 5100 1250 5150
Wire Wire Line
	1800 4750 1800 4700
Wire Wire Line
	1800 4700 1250 4700
Connection ~ 1250 4700
Wire Wire Line
	1250 4700 1250 4750
Wire Wire Line
	3250 4650 3250 4700
$Comp
L Device:D D703
U 1 1 5E699AD7
P 3800 4900
F 0 "D703" V 3754 4979 50  0000 L CNN
F 1 "1N4148" V 3845 4979 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 3800 4900 50  0001 C CNN
F 3 "~" H 3800 4900 50  0001 C CNN
	1    3800 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	3250 5100 3800 5100
Wire Wire Line
	3800 5100 3800 5050
Wire Wire Line
	3800 4750 3800 4700
Wire Wire Line
	3800 4700 3250 4700
Connection ~ 3250 5100
Wire Wire Line
	3250 5100 3250 5150
Connection ~ 3250 4700
Wire Wire Line
	3250 4700 3250 4750
Wire Wire Line
	1250 6400 1250 6350
Wire Wire Line
	3250 6400 3250 6350
$Comp
L Device:D D702
U 1 1 5E7031E2
P 1800 6550
F 0 "D702" V 1754 6629 50  0000 L CNN
F 1 "1N4148" V 1845 6629 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 1800 6550 50  0001 C CNN
F 3 "~" H 1800 6550 50  0001 C CNN
	1    1800 6550
	0    1    1    0   
$EndComp
Wire Wire Line
	1250 6750 1800 6750
Wire Wire Line
	1800 6750 1800 6700
Wire Wire Line
	1800 6400 1800 6350
Wire Wire Line
	1800 6350 1250 6350
Connection ~ 1250 6350
Wire Wire Line
	1250 6350 1250 6300
Connection ~ 1250 6750
Wire Wire Line
	1250 6750 1250 6800
$Comp
L Device:D D704
U 1 1 5E71146F
P 3800 6550
F 0 "D704" V 3754 6629 50  0000 L CNN
F 1 "1N4148" V 3845 6629 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 3800 6550 50  0001 C CNN
F 3 "~" H 3800 6550 50  0001 C CNN
	1    3800 6550
	0    1    1    0   
$EndComp
Wire Wire Line
	3250 6750 3800 6750
Wire Wire Line
	3800 6750 3800 6700
Wire Wire Line
	3800 6400 3800 6350
Wire Wire Line
	3800 6350 3250 6350
Connection ~ 3250 6750
Wire Wire Line
	3250 6750 3250 6800
Connection ~ 3250 6350
Wire Wire Line
	3250 6350 3250 6300
$Comp
L ETH1CLCR1:+15VF #PWR0716
U 1 1 5E249D54
P 5200 6900
F 0 "#PWR0716" H 5200 6750 50  0001 C CNN
F 1 "+15VF" H 5215 7073 50  0000 C CNN
F 2 "" H 5200 6900 50  0001 C CNN
F 3 "" H 5200 6900 50  0001 C CNN
	1    5200 6900
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+15VF #PWR0722
U 1 1 5E24CFCD
P 6100 6900
F 0 "#PWR0722" H 6100 6750 50  0001 C CNN
F 1 "+15VF" H 6115 7073 50  0000 C CNN
F 2 "" H 6100 6900 50  0001 C CNN
F 3 "" H 6100 6900 50  0001 C CNN
	1    6100 6900
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:+15VF #PWR0724
U 1 1 5E24D5CA
P 6550 6900
F 0 "#PWR0724" H 6550 6750 50  0001 C CNN
F 1 "+15VF" H 6565 7073 50  0000 C CNN
F 2 "" H 6550 6900 50  0001 C CNN
F 3 "" H 6550 6900 50  0001 C CNN
	1    6550 6900
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:-15VF #PWR0727
U 1 1 5E24DDD6
P 6100 5800
F 0 "#PWR0727" H 6100 5650 50  0001 C CNN
F 1 "-15VF" H 6115 5973 50  0000 C CNN
F 2 "" H 6100 5800 50  0001 C CNN
F 3 "" H 6100 5800 50  0001 C CNN
	1    6100 5800
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:-15VF #PWR0729
U 1 1 5E250E58
P 6550 5800
F 0 "#PWR0729" H 6550 5650 50  0001 C CNN
F 1 "-15VF" H 6565 5973 50  0000 C CNN
F 2 "" H 6550 5800 50  0001 C CNN
F 3 "" H 6550 5800 50  0001 C CNN
	1    6550 5800
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:-15VF #PWR0717
U 1 1 5E251502
P 5200 7500
F 0 "#PWR0717" H 5200 7350 50  0001 C CNN
F 1 "-15VF" H 5215 7673 50  0000 C CNN
F 2 "" H 5200 7500 50  0001 C CNN
F 3 "" H 5200 7500 50  0001 C CNN
	1    5200 7500
	-1   0    0    1   
$EndComp
$Comp
L Device:C C707
U 1 1 5E6471EB
P 5650 7200
F 0 "C707" H 5765 7246 50  0000 L CNN
F 1 "100n" H 5765 7155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5688 7050 50  0001 C CNN
F 3 "~" H 5650 7200 50  0001 C CNN
	1    5650 7200
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:AGNDF #PWR0721
U 1 1 5E6471F1
P 5650 7500
F 0 "#PWR0721" H 5650 7250 50  0001 C CNN
F 1 "AGNDF" H 5655 7327 50  0000 C CNN
F 2 "" H 5650 7500 50  0001 C CNN
F 3 "" H 5650 7500 50  0001 C CNN
	1    5650 7500
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 7350 5650 7500
Wire Wire Line
	5650 7050 5650 6900
$Comp
L ETH1CLCR1:+3.3VF #PWR0720
U 1 1 5E651F2D
P 5650 6900
F 0 "#PWR0720" H 5650 6750 50  0001 C CNN
F 1 "+3.3VF" H 5665 7073 50  0000 C CNN
F 2 "" H 5650 6900 50  0001 C CNN
F 3 "" H 5650 6900 50  0001 C CNN
	1    5650 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C706
U 1 1 5EBB2A0C
P 5650 6100
F 0 "C706" H 5765 6146 50  0000 L CNN
F 1 "100n" H 5765 6055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5688 5950 50  0001 C CNN
F 3 "~" H 5650 6100 50  0001 C CNN
	1    5650 6100
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:AGNDF #PWR0719
U 1 1 5EBB2A12
P 5650 6400
F 0 "#PWR0719" H 5650 6150 50  0001 C CNN
F 1 "AGNDF" H 5655 6227 50  0000 C CNN
F 2 "" H 5650 6400 50  0001 C CNN
F 3 "" H 5650 6400 50  0001 C CNN
	1    5650 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 6250 5650 6400
Wire Wire Line
	5650 5950 5650 5800
$Comp
L ETH1CLCR1:-15VF #PWR0718
U 1 1 5EBB2A1A
P 5650 5800
F 0 "#PWR0718" H 5650 5650 50  0001 C CNN
F 1 "-15VF" H 5665 5973 50  0000 C CNN
F 2 "" H 5650 5800 50  0001 C CNN
F 3 "" H 5650 5800 50  0001 C CNN
	1    5650 5800
	1    0    0    -1  
$EndComp
$Comp
L Device:C C705
U 1 1 5EBBE5EC
P 5200 6100
F 0 "C705" H 5315 6146 50  0000 L CNN
F 1 "100n" H 5315 6055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5238 5950 50  0001 C CNN
F 3 "~" H 5200 6100 50  0001 C CNN
	1    5200 6100
	1    0    0    -1  
$EndComp
$Comp
L ETH1CLCR1:AGNDF #PWR0715
U 1 1 5EBBE5F2
P 5200 6400
F 0 "#PWR0715" H 5200 6150 50  0001 C CNN
F 1 "AGNDF" H 5205 6227 50  0000 C CNN
F 2 "" H 5200 6400 50  0001 C CNN
F 3 "" H 5200 6400 50  0001 C CNN
	1    5200 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 6250 5200 6400
Wire Wire Line
	5200 5950 5200 5800
$Comp
L ETH1CLCR1:+15VF #PWR0714
U 1 1 5EBBE5FA
P 5200 5800
F 0 "#PWR0714" H 5200 5650 50  0001 C CNN
F 1 "+15VF" H 5215 5973 50  0000 C CNN
F 2 "" H 5200 5800 50  0001 C CNN
F 3 "" H 5200 5800 50  0001 C CNN
	1    5200 5800
	1    0    0    -1  
$EndComp
Connection ~ 8000 5550
Wire Wire Line
	8000 5550 8750 5550
Wire Wire Line
	7950 5550 8000 5550
$Comp
L Transistor_BJT:BC847W Q701
U 1 1 5EDA1695
P 1350 5350
F 0 "Q701" H 1541 5396 50  0000 L CNN
F 1 "BC847W" H 1541 5305 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70" H 1550 5275 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/Infineon-BC847SERIES_BC848SERIES_BC849SERIES_BC850SERIES-DS-v01_01-en.pdf?fileId=db3a304314dca389011541d4630a1657" H 1350 5350 50  0001 L CNN
	1    1350 5350
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC847W Q702
U 1 1 5EDA714C
P 1350 7000
F 0 "Q702" H 1541 7046 50  0000 L CNN
F 1 "BC847W" H 1541 6955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70" H 1550 6925 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/Infineon-BC847SERIES_BC848SERIES_BC849SERIES_BC850SERIES-DS-v01_01-en.pdf?fileId=db3a304314dca389011541d4630a1657" H 1350 7000 50  0001 L CNN
	1    1350 7000
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC847W Q704
U 1 1 5EDA7948
P 3350 7000
F 0 "Q704" H 3541 7046 50  0000 L CNN
F 1 "BC847W" H 3541 6955 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70" H 3550 6925 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/Infineon-BC847SERIES_BC848SERIES_BC849SERIES_BC850SERIES-DS-v01_01-en.pdf?fileId=db3a304314dca389011541d4630a1657" H 3350 7000 50  0001 L CNN
	1    3350 7000
	-1   0    0    -1  
$EndComp
$Comp
L Transistor_BJT:BC847W Q703
U 1 1 5EDA7FD4
P 3350 5350
F 0 "Q703" H 3541 5396 50  0000 L CNN
F 1 "BC847W" H 3541 5305 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70" H 3550 5275 50  0001 L CIN
F 3 "http://www.infineon.com/dgdl/Infineon-BC847SERIES_BC848SERIES_BC849SERIES_BC850SERIES-DS-v01_01-en.pdf?fileId=db3a304314dca389011541d4630a1657" H 3350 5350 50  0001 L CNN
	1    3350 5350
	-1   0    0    -1  
$EndComp
$EndSCHEMATC
