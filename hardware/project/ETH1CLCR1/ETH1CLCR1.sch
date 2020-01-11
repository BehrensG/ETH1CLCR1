EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 16
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 13650 1650 850  1100
U 5DE9401C
F0 "Ethernet" 50
F1 "Ethernet.sch" 50
F2 "TX+" B R 14500 1750 50 
F3 "TX-" B R 14500 1850 50 
F4 "RX+" B R 14500 2050 50 
F5 "RX-" B R 14500 2150 50 
F6 "RMII_TXD1" B L 13650 1750 50 
F7 "RMII_TXD0" B L 13650 1850 50 
F8 "RMII_TXEN" B L 13650 1950 50 
F9 "RMII_RXD0" B L 13650 2050 50 
F10 "RMII_RXD1" B L 13650 2150 50 
F11 "RMII_CRS_DV" B L 13650 2250 50 
F12 "RMII_MDIO" B L 13650 2350 50 
F13 "RMII_MDC" B L 13650 2450 50 
F14 "NRST" B L 13650 2650 50 
F15 "REF_CLK" B L 13650 2550 50 
$EndSheet
$Sheet
S 12250 1650 1300 1700
U 5DE9DFDA
F0 "MCU1" 50
F1 "MCU1.sch" 50
F2 "RMII_TXD1" B R 13550 1750 50 
F3 "RMII_TXD0" B R 13550 1850 50 
F4 "RMII_TXEN" B R 13550 1950 50 
F5 "RMII_RXD0" B R 13550 2050 50 
F6 "RMII_RXD1" B R 13550 2150 50 
F7 "RMII_CRS_DV" B R 13550 2250 50 
F8 "RMII_MDIO" B R 13550 2350 50 
F9 "RMII_MDC" B R 13550 2450 50 
F10 "REF_CLK" B R 13550 2550 50 
F11 "NRST" B R 13550 2650 50 
F12 "TRIG_EN" O R 13550 3050 50 
F13 "TRIG_OUT" O R 13550 3150 50 
F14 "TRIG_IN" I R 13550 3250 50 
F15 "MCU1_STATUS_IN" I L 12250 1750 50 
F16 "MCU1_GPIO_OUT2" O L 12250 1850 50 
F17 "MCU1_GPIO_OUT1" O L 12250 1950 50 
F18 "MCU1_~MSS" O L 12250 2050 50 
F19 "MCU1_MISO" I L 12250 2150 50 
F20 "MCU1_MOSI" O L 12250 2250 50 
F21 "MCU1_MCLK" O L 12250 2350 50 
$EndSheet
$Sheet
S 13650 2950 850  400 
U 5DEA9498
F0 "Trigger" 50
F1 "Trigger.sch" 50
F2 "EXT_TRIG" B R 14500 3050 50 
F3 "TRIG_EN" I L 13650 3050 50 
F4 "TRIG_OUT" I L 13650 3150 50 
F5 "TRIG_IN" O L 13650 3250 50 
$EndSheet
$Sheet
S 12400 3600 2100 1200
U 5DEBC70F
F0 "Power Base" 50
F1 "Power_Base.sch" 50
$EndSheet
$Sheet
S 10600 3600 1700 1200
U 5DEC0296
F0 "Power Float" 50
F1 "Power_Float.sch" 50
$EndSheet
Wire Wire Line
	14600 3050 14500 3050
Wire Wire Line
	14500 2150 14600 2150
Wire Wire Line
	14600 2050 14500 2050
Wire Wire Line
	14500 1850 14600 1850
Wire Wire Line
	14600 1750 14500 1750
Wire Wire Line
	13550 1750 13650 1750
Wire Wire Line
	13550 1850 13650 1850
Wire Wire Line
	13650 1950 13550 1950
Wire Wire Line
	13550 2050 13650 2050
Wire Wire Line
	13650 2250 13550 2250
Wire Wire Line
	13550 2150 13650 2150
Wire Wire Line
	13550 2350 13650 2350
Wire Wire Line
	13650 2450 13550 2450
Wire Wire Line
	13550 2550 13650 2550
Wire Wire Line
	13650 2650 13550 2650
Wire Wire Line
	13650 3050 13550 3050
Wire Wire Line
	13550 3150 13650 3150
Wire Wire Line
	13650 3250 13550 3250
$Sheet
S 10600 1650 1550 1700
U 5DED9BB6
F0 "Isolation" 50
F1 "Isolation.sch" 50
F2 "MCU1_GPIO_OUT1" I R 12150 1950 50 
F3 "MCU1_~MSS" I R 12150 2050 50 
F4 "MCU1_MISO" O R 12150 2150 50 
F5 "MCU1_MOSI" I R 12150 2250 50 
F6 "MCU1_MCLK" I R 12150 2350 50 
F7 "MCU1_STATUS_IN" O R 12150 1750 50 
F8 "MCU1_GPIO_OUT2" I R 12150 1850 50 
F9 "MCU2_~SSS" O L 10600 2050 50 
F10 "MCU2_MISO" I L 10600 2150 50 
F11 "MCU2_MOSI" O L 10600 2250 50 
F12 "MCU2_SCLK" O L 10600 2350 50 
F13 "MCU2_GPIO_OUT1" O L 10600 1950 50 
F14 "MCU2_STATUS_IN" I L 10600 1750 50 
F15 "MCU2_GPIO_OUT2" O L 10600 1850 50 
$EndSheet
Wire Wire Line
	12250 1750 12150 1750
Wire Wire Line
	12150 1850 12250 1850
Wire Wire Line
	12250 1950 12150 1950
Wire Wire Line
	12150 2050 12250 2050
Wire Wire Line
	12250 2150 12150 2150
Wire Wire Line
	12150 2250 12250 2250
Wire Wire Line
	12250 2350 12150 2350
$Sheet
S 6200 8200 1100 2800
U 5DEEF70B
F0 "FGEN" 50
F1 "FGEN.sch" 50
F2 "FGEN" O L 6200 9500 50 
F3 "DDS_DAC_~SYNC" I R 7300 9800 50 
F4 "DDS_DAC_SCLK" I R 7300 9900 50 
F5 "DDS_DAC_SDIN" I R 7300 9400 50 
F6 "DDS_MDAC_~SYNC" I R 7300 8300 50 
F7 "DDS_MDAC_SCLK" I R 7300 8400 50 
F8 "DDS_MDAC_DIN" I R 7300 8500 50 
F9 "DDS_DAC_SDO" O R 7300 10000 50 
F10 "DDS_DAC_~RESET" I R 7300 9500 50 
F11 "DDS_DAC_~LDAC" I R 7300 9600 50 
F12 "DDS_DAC_RSTSEL" I R 7300 9700 50 
F13 "DDS_FGEN_~FSYNC" I R 7300 10300 50 
F14 "DDS_FGEN_SDATA" I R 7300 10200 50 
F15 "DDS_FGEN_SCLK" I R 7300 10500 50 
F16 "DDS_FGEN_PSEL0" I R 7300 10600 50 
F17 "DDS_FGEN_PSEL1" I R 7300 10700 50 
F18 "DDS_MEAS_CLK" I R 7300 8700 50 
F19 "DDS_MEAS_CONV" I R 7300 8800 50 
F20 "DDS_MEAS_DATA" I R 7300 8900 50 
F21 "DDS_MEAS_A0" I R 7300 9000 50 
F22 "DDS_MEAS_A1" I R 7300 9100 50 
F23 "DDS_MEAS_A2" I R 7300 9200 50 
F24 "DDS_FGEN_FSELECT" I R 7300 10400 50 
F25 "ANALOG_SWITCH" I R 7300 10900 50 
$EndSheet
$Sheet
S 7400 8200 1300 2800
U 5DF38F82
F0 "MCU3" 50
F1 "MCU3.sch" 50
F2 "DDS_FGEN_~FSYNC" O L 7400 10300 50 
F3 "DDS_FGEN_SDATA" O L 7400 10200 50 
F4 "DDS_FGEN_SCLK" O L 7400 10500 50 
F5 "DDS_MDAC_~SYNC" O L 7400 8300 50 
F6 "DDS_MDAC_SCLK" O L 7400 8400 50 
F7 "DDS_MDAC_DIN" O L 7400 8500 50 
F8 "DDS_MEAS_CLK" O L 7400 8700 50 
F9 "DDS_MEAS_CONV" O L 7400 8800 50 
F10 "DDS_MEAS_DATA" O L 7400 8900 50 
F11 "DDS_DAC_~SYNC" O L 7400 9800 50 
F12 "DDS_DAC_SCLK" O L 7400 9900 50 
F13 "DDS_DAC_SDIN" O L 7400 9400 50 
F14 "MCU3_SCLK" I R 8700 8300 50 
F15 "MCU3_MISO" O R 8700 8400 50 
F16 "MCU3_MOSI" I R 8700 8500 50 
F17 "MCU3_NSS" I R 8700 8600 50 
F18 "DDS_DAC_~RESET" O L 7400 9500 50 
F19 "DDS_DAC_~LDAC" O L 7400 9600 50 
F20 "DDS_DAC_RSTSEL" O L 7400 9700 50 
F21 "DDS_MEAS_A0" O L 7400 9000 50 
F22 "DDS_MEAS_A1" O L 7400 9100 50 
F23 "DDS_MEAS_A2" O L 7400 9200 50 
F24 "DDS_FGEN_PSEL0" O L 7400 10600 50 
F25 "DDS_FGEN_PSEL1" O L 7400 10700 50 
F26 "DDS_DAC_SDO" I L 7400 10000 50 
F27 "DDS_FGEN_FSELECT" O L 7400 10400 50 
F28 "ANALOG_SWITCH" O L 7400 10900 50 
$EndSheet
Wire Wire Line
	7400 10900 7300 10900
Wire Wire Line
	7300 10700 7400 10700
Wire Wire Line
	7400 10600 7300 10600
Wire Wire Line
	7300 10500 7400 10500
Wire Wire Line
	7400 10400 7300 10400
Wire Wire Line
	7300 10300 7400 10300
Wire Wire Line
	7400 10200 7300 10200
$Sheet
S 2350 8200 1100 1500
U 5E314C16
F0 "FGEN Buffer" 50
F1 "FGEN_Buffer.sch" 50
F2 "FGEN" I R 3450 9500 50 
F3 "SR10CTR" I R 3450 9300 50 
F4 "SR100CTR" I R 3450 8900 50 
F5 "SR1KCTR" I R 3450 9100 50 
F6 "SR10KCTR" I R 3450 9200 50 
F7 "VLI" B L 2350 8400 50 
F8 "HCUR" O L 2350 8300 50 
F9 "FB_SDI" I R 3450 8700 50 
F10 "FB_SDO" O R 3450 8600 50 
F11 "FB_CLK" I R 3450 8500 50 
F12 "FB_~CS" I R 3450 8400 50 
F13 "FB_RDY" O R 3450 8300 50 
F14 "FB_~RST" I R 3450 8800 50 
F15 "FB_CAP" I R 3450 9000 50 
$EndSheet
$Sheet
S 8850 1300 1600 9700
U 5DEACD0F
F0 "MCU2" 50
F1 "MCU2.sch" 50
F2 "MCU2_~SSS" I R 10450 2050 50 
F3 "MCU2_MISO" O R 10450 2150 50 
F4 "MCU2_MOSI" I R 10450 2250 50 
F5 "MCU2_SCLK" I R 10450 2350 50 
F6 "MCU2_GPIO_OUT1" I R 10450 1950 50 
F7 "MCU2_STATUS_IN" O R 10450 1750 50 
F8 "MCU2_GPIO_OUT2" I R 10450 1850 50 
F9 "MCU3_NSS" O L 8850 8600 50 
F10 "MCU3_SCLK" O L 8850 8300 50 
F11 "MCU3_MISO" I L 8850 8400 50 
F12 "MCU3_MOSI" O L 8850 8500 50 
F13 "SR1KCTR" O L 8850 7700 50 
F14 "SR10KCTR" O L 8850 7800 50 
F15 "SR10CTR" O L 8850 7900 50 
F16 "SR100CTR" O L 8850 8000 50 
F17 "CXN_REL1" O R 10450 5000 50 
F18 "CXN_REL2" O R 10450 5100 50 
F19 "CXN_REL3" O R 10450 5200 50 
F20 "R100CRT" O L 8850 5600 50 
F21 "R10CRT" O L 8850 5500 50 
F22 "R1KCRT" O L 8850 5700 50 
F23 "R10KCRT" O L 8850 5800 50 
F24 "R100KCRT" O L 8850 5900 50 
F25 "RELAY_CTR" O L 8850 6000 50 
F26 "HA3-COMP" O L 8850 6100 50 
F27 "PA_NULL" O L 8850 4400 50 
F28 "PA_EM" O L 8850 4500 50 
F29 "PA_50MV" O L 8850 4600 50 
F30 "PA_MOS1" O L 8850 4700 50 
F31 "PA_MOS2" O L 8850 4800 50 
F32 "PA_MOS3" O L 8850 4900 50 
F33 "PA_MOS4" O L 8850 5000 50 
F34 "PA_MOS5" O L 8850 5100 50 
F35 "PA_MOS6" O L 8850 5200 50 
F36 "G1A1_CTR" O L 8850 2600 50 
F37 "G1A0_CTR" O L 8850 2500 50 
F38 "G2A1_CTR" O L 8850 2800 50 
F39 "G2A0_CTR" O L 8850 2700 50 
F40 "ADC_NULL2" O L 8850 2300 50 
F41 "ADC_NULL1" O L 8850 2200 50 
F42 "ADC_CONVST" O L 8850 1400 50 
F43 "ADC_~CS" O L 8850 1500 50 
F44 "ADC_CLOCK" O L 8850 1600 50 
F45 "ADC_BUSY" I L 8850 1700 50 
F46 "ADC_SDI" O L 8850 1800 50 
F47 "ADC_RD" O L 8850 1900 50 
F48 "ADC_SDOA" I L 8850 2000 50 
F49 "RR_SDI" O L 8850 6300 50 
F50 "RR_SDO" I L 8850 6400 50 
F51 "RR_CLK" O L 8850 6500 50 
F52 "RR_~CS" O L 8850 6600 50 
F53 "RR_RDY" I L 8850 6700 50 
F54 "RR_~RST" O L 8850 6800 50 
F55 "FB_SDI" O L 8850 7400 50 
F56 "FB_SDO" I L 8850 7300 50 
F57 "FB_CLK" O L 8850 7200 50 
F58 "FB_~CS" O L 8850 7100 50 
F59 "FB_RDY" I L 8850 7000 50 
F60 "FB_~RST" O L 8850 7500 50 
F61 "DAC_~LDAC" O L 8850 3200 50 
F62 "DAC_~SYNC" O L 8850 3300 50 
F63 "DAC_~CLR" O L 8850 3400 50 
F64 "DAC_DIN" O L 8850 3500 50 
F65 "DAC_SCLK" O L 8850 3600 50 
F66 "FB_CAP" O L 8850 7600 50 
F67 "CXN_REL4" O R 10450 5300 50 
F68 "CXN_REL5" O R 10450 5400 50 
F69 "CXN_REL6" O R 10450 5500 50 
$EndSheet
Wire Wire Line
	7300 10000 7400 10000
Wire Wire Line
	7300 9900 7400 9900
Wire Wire Line
	7300 9800 7400 9800
Wire Wire Line
	7400 9700 7300 9700
Wire Wire Line
	7300 9600 7400 9600
Wire Wire Line
	7400 9500 7300 9500
Wire Wire Line
	7300 9400 7400 9400
Wire Wire Line
	7300 9200 7400 9200
Wire Wire Line
	7400 9100 7300 9100
Wire Wire Line
	7300 9000 7400 9000
Wire Wire Line
	7400 8900 7300 8900
Wire Wire Line
	7300 8800 7400 8800
Wire Wire Line
	7400 8700 7300 8700
Wire Wire Line
	7300 8500 7400 8500
Wire Wire Line
	7400 8400 7300 8400
Wire Wire Line
	7300 8300 7400 8300
$Sheet
S 2350 6400 1100 1500
U 5E252C19
F0 "Range Resistors" 50
F1 "RangeResistor.sch" 50
F2 "R1KCRT" I R 3450 6700 50 
F3 "R10KCRT" I R 3450 6800 50 
F4 "R100CRT" I R 3450 6600 50 
F5 "R10CRT" I R 3450 6500 50 
F6 "R100KCRT" I R 3450 6900 50 
F7 "Err" O L 2350 6550 50 
F8 "RELAY_CTR" I R 3450 7000 50 
F9 "LCUR" I L 2350 6650 50 
F10 "LPOT" I L 2350 6750 50 
F11 "HPOT" I L 2350 6850 50 
F12 "HA3-COMP" I R 3450 7100 50 
F13 "RR_SDI" I R 3450 7300 50 
F14 "RR_SDO" O R 3450 7400 50 
F15 "RR_CLK" I R 3450 7500 50 
F16 "RR_~CS" I R 3450 7600 50 
F17 "RR_RDY" O R 3450 7700 50 
F18 "RR_~RST" I R 3450 7800 50 
F19 "RR_OFFS1" I L 2350 7100 50 
$EndSheet
$Sheet
S 2350 1300 1100 1800
U 5EB3D8D6
F0 "Process Amplifier" 50
F1 "ProcessAmplifier.sch" 50
F2 "Err" I L 2350 1800 50 
F3 "LCUR" I L 2350 1500 50 
F4 "VLI" I L 2350 1900 50 
F5 "HPOT" I L 2350 1400 50 
F6 "Em" O R 3450 1400 50 
F7 "PA_OFS2" I R 3450 1800 50 
F8 "PA_OFS1" I R 3450 1700 50 
F9 "PA_OFS3" I R 3450 1900 50 
F10 "PA_OFS4" I R 3450 2000 50 
F11 "Eref" O R 3450 1500 50 
F12 "LPOT" I L 2350 1600 50 
F13 "PA_NULL" I R 3450 2200 50 
F14 "PA_EM" I R 3450 2300 50 
F15 "PA_50MV" I R 3450 2400 50 
F16 "PA_MOS1" I R 3450 2500 50 
F17 "PA_MOS2" I R 3450 2600 50 
F18 "PA_MOS3" I R 3450 2700 50 
F19 "PA_MOS4" I R 3450 2800 50 
F20 "PA_MOS5" I R 3450 2900 50 
F21 "PA_MOS6" I R 3450 3000 50 
$EndSheet
$Sheet
S 7400 3100 1300 1150
U 5E087FDC
F0 "DAC" 50
F1 "DAC.sch" 50
F2 "PA_OFFS1" O L 7400 3500 50 
F3 "PA_OFFS2" O L 7400 3600 50 
F4 "PA_OFFS3" O L 7400 3700 50 
F5 "PA_OFFS4" O L 7400 3800 50 
F6 "ADC_OFFS1" O L 7400 3300 50 
F7 "ADC_OFFS2" O L 7400 3200 50 
F8 "RR_OFFS1" O L 7400 4000 50 
F9 "DAC_~LDAC" I R 8700 3200 50 
F10 "DAC_~SYNC" I R 8700 3300 50 
F11 "DAC_~CLR" I R 8700 3400 50 
F12 "DAC_DIN" I R 8700 3500 50 
F13 "DAC_SCLK" I R 8700 3600 50 
$EndSheet
$Sheet
S 7400 1300 1300 1600
U 5E402F62
F0 "ADC" 50
F1 "ADC.sch" 50
F2 "ADC_CONVST" I R 8700 1400 50 
F3 "ADC_~CS" I R 8700 1500 50 
F4 "ADC_CLOCK" I R 8700 1600 50 
F5 "ADC_BUSY" O R 8700 1700 50 
F6 "ADC_SDI" I R 8700 1800 50 
F7 "ADC_RD" I R 8700 1900 50 
F8 "ADC_SDOA" O R 8700 2000 50 
F9 "ADC_OFFS1" I L 7400 1700 50 
F10 "ADC_OFFS2" I L 7400 1800 50 
F11 "G1A0_CTR" I R 8700 2500 50 
F12 "G1A1_CTR" I R 8700 2600 50 
F13 "G2A0_CTR" I R 8700 2700 50 
F14 "G2A1_CTR" I R 8700 2800 50 
F15 "ADC_NULL1" I R 8700 2200 50 
F16 "ADC_NULL2" I R 8700 2300 50 
F17 "Em" I L 7400 1400 50 
F18 "Eref" I L 7400 1500 50 
$EndSheet
Wire Wire Line
	8700 8600 8850 8600
Wire Wire Line
	8850 8500 8700 8500
Wire Wire Line
	8700 8400 8850 8400
Wire Wire Line
	8850 8300 8700 8300
Wire Wire Line
	3450 9500 6200 9500
Wire Wire Line
	3450 9300 6100 9300
Wire Wire Line
	6100 9300 6100 8000
Wire Wire Line
	3450 9200 6000 9200
Wire Wire Line
	6000 9200 6000 7900
Wire Wire Line
	8850 8000 6100 8000
Wire Wire Line
	8850 7900 6000 7900
Wire Wire Line
	8850 7800 5900 7800
Wire Wire Line
	5900 7800 5900 9100
Wire Wire Line
	5900 9100 3450 9100
Wire Wire Line
	8850 7700 5800 7700
Wire Wire Line
	5800 7700 5800 9000
Wire Wire Line
	3450 9000 5800 9000
Wire Wire Line
	3450 8800 5600 8800
Wire Wire Line
	5600 8800 5600 7500
Wire Wire Line
	5600 7500 8850 7500
Wire Wire Line
	3450 8700 5500 8700
Wire Wire Line
	5500 8700 5500 7400
Wire Wire Line
	5500 7400 8850 7400
$Sheet
S 14600 650  1250 4950
U 5DEACCC1
F0 "Connector" 50
F1 "Connector.sch" 50
F2 "RX+" B L 14600 2050 50 
F3 "TX+" B L 14600 1750 50 
F4 "RX-" B L 14600 2150 50 
F5 "TX-" B L 14600 1850 50 
F6 "EXT_TRIG" B L 14600 3050 50 
F7 "HCUR" B L 14600 750 50 
F8 "HPOT" B L 14600 850 50 
F9 "LCUR" B L 14600 950 50 
F10 "LPOT" B L 14600 1050 50 
F11 "CXN_REL1" I L 14600 5000 50 
F12 "CXN_REL2" I L 14600 5100 50 
F13 "CXN_REL3" I L 14600 5200 50 
F14 "CXN_REL4" I L 14600 5300 50 
F15 "CXN_REL5" I L 14600 5400 50 
F16 "CXN_REL6" I L 14600 5500 50 
$EndSheet
Wire Wire Line
	14600 5000 10450 5000
Wire Wire Line
	14600 5100 10450 5100
Wire Wire Line
	14600 5200 10450 5200
Wire Wire Line
	7400 3200 7300 3200
Wire Wire Line
	7300 3200 7300 1800
Wire Wire Line
	7300 1800 7400 1800
Wire Wire Line
	7400 3300 7200 3300
Wire Wire Line
	7200 3300 7200 1700
Wire Wire Line
	7200 1700 7400 1700
Wire Wire Line
	3450 8600 5400 8600
Wire Wire Line
	5400 8600 5400 7300
Wire Wire Line
	5400 7300 8850 7300
Wire Wire Line
	3450 8500 5300 8500
Wire Wire Line
	5300 8500 5300 7200
Wire Wire Line
	5300 7200 8850 7200
Wire Wire Line
	3450 8400 5200 8400
Wire Wire Line
	5200 8400 5200 7100
Wire Wire Line
	5200 7100 8850 7100
Wire Wire Line
	3450 8300 5100 8300
Wire Wire Line
	5100 8300 5100 7000
Wire Wire Line
	5100 7000 8850 7000
Wire Wire Line
	3450 1700 7000 1700
Wire Wire Line
	7000 1700 7000 3500
Wire Wire Line
	7000 3500 7400 3500
Wire Wire Line
	3450 1800 6900 1800
Wire Wire Line
	6900 1800 6900 3600
Wire Wire Line
	6900 3600 7400 3600
Wire Wire Line
	3450 1900 6800 1900
Wire Wire Line
	6800 1900 6800 3700
Wire Wire Line
	6800 3700 7400 3700
Wire Wire Line
	3450 2000 6700 2000
Wire Wire Line
	6700 2000 6700 3800
Wire Wire Line
	6700 3800 7400 3800
Wire Wire Line
	3450 1500 7400 1500
Wire Wire Line
	7400 1400 3450 1400
Wire Wire Line
	3450 2200 6500 2200
Wire Wire Line
	6500 2200 6500 4400
Wire Wire Line
	6500 4400 8850 4400
Wire Wire Line
	3450 2300 6400 2300
Wire Wire Line
	6400 2300 6400 4500
Wire Wire Line
	6400 4500 8850 4500
Wire Wire Line
	3450 2400 6300 2400
Wire Wire Line
	6300 2400 6300 4600
Wire Wire Line
	6300 4600 8850 4600
Wire Wire Line
	3450 2500 6200 2500
Wire Wire Line
	6200 2500 6200 4700
Wire Wire Line
	6200 4700 8850 4700
Wire Wire Line
	3450 2600 6100 2600
Wire Wire Line
	6100 2600 6100 4800
Wire Wire Line
	6100 4800 8850 4800
Wire Wire Line
	3450 2700 6000 2700
Wire Wire Line
	6000 2700 6000 4900
Wire Wire Line
	6000 4900 8850 4900
Wire Wire Line
	3450 2800 5900 2800
Wire Wire Line
	5900 2800 5900 5000
Wire Wire Line
	5900 5000 8850 5000
Wire Wire Line
	3450 2900 5800 2900
Wire Wire Line
	5800 2900 5800 5100
Wire Wire Line
	5800 5100 8850 5100
Wire Wire Line
	3450 3000 5700 3000
Wire Wire Line
	5700 3000 5700 5200
Wire Wire Line
	5700 5200 8850 5200
Wire Wire Line
	3450 7800 4900 7800
Wire Wire Line
	4900 7800 4900 6800
Wire Wire Line
	4900 6800 8850 6800
Wire Wire Line
	3450 7700 4800 7700
Wire Wire Line
	4800 7700 4800 6700
Wire Wire Line
	4800 6700 8850 6700
Wire Wire Line
	3450 7600 4700 7600
Wire Wire Line
	4700 7600 4700 6600
Wire Wire Line
	4700 6600 8850 6600
Wire Wire Line
	3450 7500 4600 7500
Wire Wire Line
	4600 7500 4600 6500
Wire Wire Line
	4600 6500 8850 6500
Wire Wire Line
	3450 7400 4500 7400
Wire Wire Line
	4500 7400 4500 6400
Wire Wire Line
	4500 6400 8850 6400
Wire Wire Line
	3450 7100 4200 7100
Wire Wire Line
	4200 7100 4200 6100
Wire Wire Line
	4200 6100 8850 6100
Wire Wire Line
	3450 7000 4100 7000
Wire Wire Line
	4100 7000 4100 6000
Wire Wire Line
	4100 6000 8850 6000
Wire Wire Line
	3450 7300 4400 7300
Wire Wire Line
	4400 7300 4400 6300
Wire Wire Line
	4400 6300 8850 6300
Wire Wire Line
	3450 6900 4000 6900
Wire Wire Line
	4000 6900 4000 5900
Wire Wire Line
	4000 5900 8850 5900
Wire Wire Line
	3450 6800 3900 6800
Wire Wire Line
	3900 6800 3900 5800
Wire Wire Line
	3900 5800 8850 5800
Wire Wire Line
	3450 6700 3800 6700
Wire Wire Line
	3800 6700 3800 5700
Wire Wire Line
	3800 5700 8850 5700
Wire Wire Line
	3450 6600 3700 6600
Wire Wire Line
	3700 6600 3700 5600
Wire Wire Line
	3700 5600 8850 5600
Wire Wire Line
	3450 6500 3600 6500
Wire Wire Line
	3600 6500 3600 5500
Wire Wire Line
	3600 5500 8850 5500
Wire Wire Line
	14600 750  1600 750 
Wire Wire Line
	1600 750  1600 8300
Wire Wire Line
	1600 8300 2350 8300
Wire Wire Line
	2350 1900 2000 1900
Wire Wire Line
	2000 1900 2000 8400
Wire Wire Line
	2000 8400 2350 8400
Wire Wire Line
	14600 850  1700 850 
Wire Wire Line
	1700 850  1700 1400
Wire Wire Line
	1700 1400 2350 1400
Wire Wire Line
	2350 6850 1700 6850
Wire Wire Line
	1700 6850 1700 1400
Connection ~ 1700 1400
Wire Wire Line
	14600 950  1800 950 
Wire Wire Line
	1800 950  1800 1500
Wire Wire Line
	1800 1500 2350 1500
Wire Wire Line
	2350 6650 1800 6650
Wire Wire Line
	1800 6650 1800 1500
Connection ~ 1800 1500
Wire Wire Line
	14600 1050 1900 1050
Wire Wire Line
	1900 1050 1900 1600
Wire Wire Line
	1900 1600 2350 1600
Wire Wire Line
	2350 6750 1900 6750
Wire Wire Line
	1900 6750 1900 1600
Connection ~ 1900 1600
Wire Wire Line
	2350 6550 2100 6550
Wire Wire Line
	2100 6550 2100 1800
Wire Wire Line
	2100 1800 2350 1800
Wire Wire Line
	2350 7100 2200 7100
Wire Wire Line
	2200 7100 2200 4000
Wire Wire Line
	2200 4000 7400 4000
Wire Wire Line
	8700 1400 8850 1400
Wire Wire Line
	8700 1500 8850 1500
Wire Wire Line
	8700 1600 8850 1600
Wire Wire Line
	8700 1700 8850 1700
Wire Wire Line
	8700 1800 8850 1800
Wire Wire Line
	8700 1900 8850 1900
Wire Wire Line
	8700 2000 8850 2000
Wire Wire Line
	8700 2200 8850 2200
Wire Wire Line
	8700 2300 8850 2300
Wire Wire Line
	8700 2500 8850 2500
Wire Wire Line
	8700 2600 8850 2600
Wire Wire Line
	8700 2700 8850 2700
Wire Wire Line
	8700 2800 8850 2800
Wire Wire Line
	10450 2350 10600 2350
Wire Wire Line
	10600 2250 10450 2250
Wire Wire Line
	10450 2150 10600 2150
Wire Wire Line
	10600 2050 10450 2050
Wire Wire Line
	10450 1950 10600 1950
Wire Wire Line
	10600 1850 10450 1850
Wire Wire Line
	10450 1750 10600 1750
Wire Wire Line
	3450 8900 5700 8900
Wire Wire Line
	5700 8900 5700 7600
Wire Wire Line
	5700 7600 8850 7600
Wire Wire Line
	8850 3200 8700 3200
Wire Wire Line
	8700 3300 8850 3300
Wire Wire Line
	8850 3400 8700 3400
Wire Wire Line
	8700 3500 8850 3500
Wire Wire Line
	8850 3600 8700 3600
Wire Wire Line
	10450 5300 14600 5300
Wire Wire Line
	14600 5400 10450 5400
Wire Wire Line
	10450 5500 14600 5500
$EndSCHEMATC
