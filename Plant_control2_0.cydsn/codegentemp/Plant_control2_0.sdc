# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\LaimonasIgnas\Desktop\Plant_control2_0.cydsn\PSoC\Plant_control2_0.cydsn\Plant_control2_0.cyprj
# Date: Wed, 11 Nov 2015 15:16:09 GMT
#set_units -time ns
create_clock -name {ADC_SAR_Seq_1_intClock(FFB)} -period 62.5 -waveform {0 31.25} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {CyRouted1} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 20.833333333333332 -waveform {0 10.4166666666667} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {ADC_SAR_Seq_1_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 7} [list]
create_generated_clock -name {UART_IntClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 313 627} [list [get_pins {ClockBlock/udb_div_1}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 12001 24001} [list [get_pins {ClockBlock/udb_div_3}]]


# Component constraints for C:\Users\LaimonasIgnas\Desktop\Plant_control2_0.cydsn\PSoC\Plant_control2_0.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\LaimonasIgnas\Desktop\Plant_control2_0.cydsn\PSoC\Plant_control2_0.cydsn\Plant_control2_0.cyprj
# Date: Wed, 11 Nov 2015 15:16:05 GMT
