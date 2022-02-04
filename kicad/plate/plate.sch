EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:LED_Small D1
U 1 1 617A13D8
P 1150 1850
F 0 "D1" H 1150 2085 50  0000 C CNN
F 1 "LED_Small" H 1150 1994 50  0000 C CNN
F 2 "LED_SMD:LED_1206_3216Metric_ReverseMount_Hole1.8x2.4mm" V 1150 1850 50  0001 C CNN
F 3 "~" V 1150 1850 50  0001 C CNN
	1    1150 1850
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x02 J1
U 1 1 617A49EE
P 1200 2250
F 0 "J1" V 1072 2330 50  0000 L CNN
F 1 "Conn_01x02" V 1163 2330 50  0000 L CNN
F 2 "LED_SMD:LED_2816_7142Metric_Pad3.20x4.45mm_HandSolder" H 1200 2250 50  0001 C CNN
F 3 "~" H 1200 2250 50  0001 C CNN
	1    1200 2250
	0    1    1    0   
$EndComp
Wire Wire Line
	1200 2050 1250 2050
Wire Wire Line
	1250 2050 1250 1850
Wire Wire Line
	1100 2050 1050 2050
Wire Wire Line
	1050 2050 1050 1850
$EndSCHEMATC
