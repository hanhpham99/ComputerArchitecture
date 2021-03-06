/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

ATmega16HVB and ATmega32HVB I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __MEGA32HVB_BITS_INCLUDED__
#define __MEGA32HVB_BITS_INCLUDED__

/* ***** AD_CONVERTER ***************** */
/* VADMUX - The VADC multiplexer Selection Register */
#define    VADMUX0         0       // Analog Channel and Gain Selection Bits
#define    VADMUX1         1       // Analog Channel and Gain Selection Bits
#define    VADMUX2         2       // Analog Channel and Gain Selection Bits
#define    VADMUX3         3       // Analog Channel and Gain Selection Bits

/* VADCSR - The VADC Control and Status register */
#define    VADCCIE         0       // VADC Conversion Complete Interrupt Enable
#define    VADCCIF         1       // VADC Conversion Complete Interrupt Flag
#define    VADSC           2       // VADC Satrt Conversion
#define    VADEN           3       // VADC Enable


/* ***** WATCHDOG ********************* */
/* WDTCSR - Watchdog Timer Control Register */
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDCE            4       // Watchdog Change Enable
#define    WDP3            5       // Watchdog Timer Prescaler Bit 3
#define    WDIE            6       // Watchdog Timeout Interrupt Enable
#define    WDIF            7       // Watchdog Timeout Interrupt Flag


/* ***** FET ************************** */
/* FCSR - FET Control and Status Register */
#define    CFE             0       // Charge FET Enable
#define    DFE             1       // Discharge FET Enable
#define    CPS             2       // Current Protection Status
#define    DUVRD           3       // Deep Under-Voltage Recovery Disable


/* ***** SPI ************************** */
/* SPDR - SPI Data Register */
#define    SPDR0           0       // SPI Data Register bit 0
#define    SPDR1           1       // SPI Data Register bit 1
#define    SPDR2           2       // SPI Data Register bit 2
#define    SPDR3           3       // SPI Data Register bit 3
#define    SPDR4           4       // SPI Data Register bit 4
#define    SPDR5           5       // SPI Data Register bit 5
#define    SPDR6           6       // SPI Data Register bit 6
#define    SPDR7           7       // SPI Data Register bit 7

/* SPSR - SPI Status Register */
#define    SPI2X           0       // Double SPI Speed Bit
#define    WCOL            6       // Write Collision Flag
#define    SPIF            7       // SPI Interrupt Flag

/* SPCR - SPI Control Register */
#define    SPR0            0       // SPI Clock Rate Select 0
#define    SPR1            1       // SPI Clock Rate Select 1
#define    CPHA            2       // Clock Phase
#define    CPOL            3       // Clock polarity
#define    MSTR            4       // Master/Slave Select
#define    DORD            5       // Data Order
#define    SPE             6       // SPI Enable
#define    SPIE            7       // SPI Interrupt Enable


/* ***** EEPROM *********************** */
/* EEDR - EEPROM Data Register */
#define    EEDR0           0       // EEPROM Data Register bit 0
#define    EEDR1           1       // EEPROM Data Register bit 1
#define    EEDR2           2       // EEPROM Data Register bit 2
#define    EEDR3           3       // EEPROM Data Register bit 3
#define    EEDR4           4       // EEPROM Data Register bit 4
#define    EEDR5           5       // EEPROM Data Register bit 5
#define    EEDR6           6       // EEPROM Data Register bit 6
#define    EEDR7           7       // EEPROM Data Register bit 7

/* EECR - EEPROM Control Register */
#define    EERE            0       // EEPROM Read Enable
#define    EEPE            1       // EEPROM Write Enable
#define    EEWE            EEPE    // For compatibility
#define    EEMPE           2       // EEPROM Master Write Enable
#define    EEMWE           EEMPE   // For compatibility
#define    EERIE           3       // EEProm Ready Interrupt Enable
#define    EEPM0           4       //
#define    EEPM1           5       //


/* ***** COULOMB_COUNTER ************** */
/* CADCSRA - CC-ADC Control and Status Register A */
#define    CADSE           0       // When the CADSE bit is written to one, the ongoing CC-ADC conversion is aborted, and the CC-ADC enters Regular Current detection mode.
#define    CADSI0          1       // The CADSI bits determine the current sampling interval for the Regular Current detection in Power-down mode. The actual settings remain to be determined.
#define    CADSI1          2       // The CADSI bits determine the current sampling interval for the Regular Current detection in Power-down mode. The actual settings remain to be determined.
#define    CADAS0          3       // CC_ADC Accumulate Current Select Bit 0
#define    CADAS1          4       // CC_ADC Accumulate Current Select Bit 1
#define    CADUB           5       // CC_ADC Update Busy
#define    CADPOL          6       //
#define    CADEN           7       // When the CADEN bit is cleared (zero), the CC-ADC is disabled. When the CADEN bit is set (one), the CC-ADC will continuously measure the voltage drop over the external sense resistor RSENSE. In Power-down, only the Regular Current detection is active. In Power-off, the CC-ADC is always disabled.

/* CADCSRB - CC-ADC Control and Status Register B */
#define    CADICIF         0       // CC-ADC Instantaneous Current Interrupt Flag
#define    CADRCIF         1       // CC-ADC Accumulate Current Interrupt Flag
#define    CADACIF         2       // CC-ADC Accumulate Current Interrupt Flag
#define    CADICIE         4       // CAD Instantenous Current Interrupt Enable
#define    CADRCIE         5       // Regular Current Interrupt Enable
#define    CADACIE         6       //

/* CADCSRC - CC-ADC Control and Status Register C */
#define    CADVSE          0       // CC-ADC Voltage Scaling Enable

/* CADAC3 - ADC Accumulate Current */
#define    CADAC24         0       //
#define    CADAC25         1       //
#define    CADAC26         2       //
#define    CADAC27         3       //
#define    CADAC28         4       //
#define    CADAC29         5       //
#define    CADAC30         6       //
#define    CADAC31         7       //

/* CADAC2 - ADC Accumulate Current */
#define    CADAC16         0       //
#define    CADAC17         1       //
#define    CADAC18         2       //
#define    CADAC19         3       //
#define    CADAC20         4       //
#define    CADAC21         5       //
#define    CADAC22         6       //
#define    CADAC23         7       //

/* CADAC1 - ADC Accumulate Current */
#define    CADAC08         0       //
#define    CADAC09         1       //
#define    CADAC10         2       //
#define    CADAC11         3       //
#define    CADAC12         4       //
#define    CADAC13         5       //
#define    CADAC14         6       //
#define    CADAC15         7       //

/* CADAC0 - ADC Accumulate Current */
#define    CADAC00         0       //
#define    CADAC01         1       //
#define    CADAC02         2       //
#define    CADAC03         3       //
#define    CADAC04         4       //
#define    CADAC05         5       //
#define    CADAC06         6       //
#define    CADAC07         7       //

/* CADRCC - CC-ADC Regular Charge Current */
#define    CADRCC0         0       //
#define    CADRCC1         1       //
#define    CADRCC2         2       //
#define    CADRCC3         3       //
#define    CADRCC4         4       //
#define    CADRCC5         5       //
#define    CADRCC6         6       //
#define    CADRCC7         7       //

/* CADRDC - CC-ADC Regular Discharge Current */
#define    CADRDC0         0       //
#define    CADRDC1         1       //
#define    CADRDC2         2       //
#define    CADRDC3         3       //
#define    CADRDC4         4       //
#define    CADRDC5         5       //
#define    CADRDC6         6       //
#define    CADRDC7         7       //


/* ***** TWI ************************** */
/* TWBCSR - TWI Bus Control and Status Register */
#define    TWBCIP          0       // TWI Bus Connect/Disconnect Interrupt Polarity
#define    TWBDT0          1       // TWI Bus Disconnect Time-out Period
#define    TWBDT1          2       // TWI Bus Disconnect Time-out Period
#define    TWBCIE          6       // TWI Bus Connect/Disconnect Interrupt Enable
#define    TWBCIF          7       // TWI Bus Connect/Disconnect Interrupt Flag

/* TWAMR - TWI (Slave) Address Mask Register */
#define    TWAM0           1       //
#define    TWAM1           2       //
#define    TWAM2           3       //
#define    TWAM3           4       //
#define    TWAM4           5       //
#define    TWAM5           6       //
#define    TWAM6           7       //

/* TWBR - TWI Bit Rate register */
#define    TWBR0           0       //
#define    TWBR1           1       //
#define    TWBR2           2       //
#define    TWBR3           3       //
#define    TWBR4           4       //
#define    TWBR5           5       //
#define    TWBR6           6       //
#define    TWBR7           7       //

/* TWCR - TWI Control Register */
#define    TWIE            0       // TWI Interrupt Enable
#define    TWEN            2       // TWI Enable Bit
#define    TWWC            3       // TWI Write Collition Flag
#define    TWSTO           4       // TWI Stop Condition Bit
#define    TWSTA           5       // TWI Start Condition Bit
#define    TWEA            6       // TWI Enable Acknowledge Bit
#define    TWINT           7       // TWI Interrupt Flag

/* TWSR - TWI Status Register */
#define    TWPS0           0       // TWI Prescaler
#define    TWPS1           1       // TWI Prescaler
#define    TWS3            3       // TWI Status
#define    TWS4            4       // TWI Status
#define    TWS5            5       // TWI Status
#define    TWS6            6       // TWI Status
#define    TWS7            7       // TWI Status

/* TWDR - TWI Data register */
#define    TWD0            0       // TWI Data Register Bit 0
#define    TWD1            1       // TWI Data Register Bit 1
#define    TWD2            2       // TWI Data Register Bit 2
#define    TWD3            3       // TWI Data Register Bit 3
#define    TWD4            4       // TWI Data Register Bit 4
#define    TWD5            5       // TWI Data Register Bit 5
#define    TWD6            6       // TWI Data Register Bit 6
#define    TWD7            7       // TWI Data Register Bit 7

/* TWAR - TWI (Slave) Address register */
#define    TWGCE           0       // TWI General Call Recognition Enable Bit
#define    TWA0            1       // TWI (Slave) Address register Bit 0
#define    TWA1            2       // TWI (Slave) Address register Bit 1
#define    TWA2            3       // TWI (Slave) Address register Bit 2
#define    TWA3            4       // TWI (Slave) Address register Bit 3
#define    TWA4            5       // TWI (Slave) Address register Bit 4
#define    TWA5            6       // TWI (Slave) Address register Bit 5
#define    TWA6            7       // TWI (Slave) Address register Bit 6


/* ***** EXTERNAL_INTERRUPT *********** */
/* EICRA - External Interrupt Control Register */
#define    ISC00           0       // External Interrupt Sense Control 0 Bit 0
#define    ISC01           1       // External Interrupt Sense Control 0 Bit 1
#define    ISC10           2       // External Interrupt Sense Control 1 Bit 0
#define    ISC11           3       // External Interrupt Sense Control 1 Bit 1
#define    ISC20           4       // External Interrupt Sense Control 2 Bit 0
#define    ISC21           5       // External Interrupt Sense Control 2 Bit 1
#define    ISC30           6       // External Interrupt Sense Control 3 Bit 0
#define    ISC31           7       // External Interrupt Sense Control 3 Bit 1

/* EIMSK - External Interrupt Mask Register */
#define    INT0            0       // External Interrupt Request 0 Enable
#define    INT1            1       // External Interrupt Request 1 Enable
#define    INT2            2       // External Interrupt Request 2 Enable
#define    INT3            3       // External Interrupt Request 3 Enable

/* EIFR - External Interrupt Flag Register */
#define    INTF0           0       // External Interrupt Flag 0
#define    INTF1           1       // External Interrupt Flag 1
#define    INTF2           2       // External Interrupt Flag 2
#define    INTF3           3       // External Interrupt Flag 3

/* PCICR - Pin Change Interrupt Control Register */
#define    PCIE0           0       // Pin Change Interrupt Enable 0
#define    PCIE1           1       // Pin Change Interrupt Enable 1

/* PCIFR - Pin Change Interrupt Flag Register */
#define    PCIF0           0       // Pin Change Interrupt Flag 1
#define    PCIF1           1       // Pin Change Interrupt Flag 1

/* PCMSK1 - Pin Change Enable Mask Register 1 */
#define    PCINT4          0       // Pin Change Enable Mask 4
#define    PCINT5          1       // Pin Change Enable Mask 5
#define    PCINT6          2       // Pin Change Enable Mask 6
#define    PCINT7          3       // Pin Change Enable Mask 7
#define    PCINT8          4       // Pin Change Enable Mask 8
#define    PCINT9          5       // Pin Change Enable Mask 9
#define    PCINT10         6       // Pin Change Enable Mask 10
#define    PCINT11         7       // Pin Change Enable Mask 11

/* PCMSK0 - Pin Change Enable Mask Register 0 */
#define    PCINT0          0       // Pin Change Enable Mask 0
#define    PCINT1          1       // Pin Change Enable Mask 1
#define    PCINT2          2       // Pin Change Enable Mask 2
#define    PCINT3          3       // Pin Change Enable Mask 3


/* ***** TIMER_COUNTER_1 ************** */
/* TCCR1A - Timer/Counter 1 Control Register A */
#define    WGM10           0       // Waveform Generation Mode
#define    ICS1            3       // Input Capture Select
#define    ICES1           4       // Input Capture Edge Select
#define    ICNC1           5       // Input Capture Noise Canceler
#define    ICEN1           6       // Input Capture Mode Enable
#define    TCW1            7       // Timer/Counter Width

/* TCCR1B - Timer/Counter1 Control Register B */
#define    CS10            0       // Clock Select1 bit 0
#define    CS11            1       // Clock Select1 bit 1
#define    CS12            2       // Clock Select1 bit 2

/* OCR1A - Output Compare Register 1A */
#define    OCR1A0          0       //
#define    OCR1A1          1       //
#define    OCR1A2          2       //
#define    OCR1A3          3       //
#define    OCR1A4          4       //
#define    OCR1A5          5       //
#define    OCR1A6          6       //
#define    OCR1A7          7       //

/* OCR1B - Output Compare Register B */
#define    OCR1B0          0       //
#define    OCR1B1          1       //
#define    OCR1B2          2       //
#define    OCR1B3          3       //
#define    OCR1B4          4       //
#define    OCR1B5          5       //
#define    OCR1B6          6       //
#define    OCR1B7          7       //

/* TIMSK1 - Timer/Counter Interrupt Mask Register */
#define    TOIE1           0       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1A          1       // Timer/Counter1 Output Compare A Interrupt Enable
#define    OCIE1B          2       // Timer/Counter1 Output Compare B Interrupt Enable
#define    ICIE1           3       // Timer/Counter n Input Capture Interrupt Enable

/* TIFR1 - Timer/Counter Interrupt Flag register */
#define    TOV1            0       // Timer/Counter1 Overflow Flag
#define    OCF1A           1       // Timer/Counter1 Output Compare Flag A
#define    OCF1B           2       // Timer/Counter1 Output Compare Flag B
#define    ICF1            3       // Timer/Counter 1 Input Capture Flag

/* GTCCR - General Timer/Counter Control Register */
#define    PSRSYNC         0       // Prescaler Reset
#define    TSM             7       // Timer/Counter Synchronization Mode


/* ***** CELL_BALANCING *************** */
/* CBCR - Cell Balancing Control Register */
#define    CBE1            0       // Battery Protection Parameter Lock
#define    CBE2            1       // Cell Balancing Enable 2
#define    CBE3            2       // Cell Balancing Enable 4
#define    CBE4            3       // Cell Balancing Enable 4


/* ***** BATTERY_PROTECTION *********** */
/* BPPLR - Battery Protection Parameter Lock Register */
#define    BPPL            0       // Battery Protection Parameter Lock
#define    BPPLE           1       // Battery Protection Parameter Lock Enable

/* BPCR - Battery Protection Control Register */
#define    CHCD            0       // Charge High-current Protection Disable
#define    DHCD            1       // Discharge High-current Protection Disable
#define    COCD            2       // Charge Over-current Protection Disabled
#define    DOCD            3       // Discharge Over-current Protection Disabled
#define    SCD             4       // Short Circuit Protection Disabled
#define    EPID            5       // External Protection Input Disable

/* BPHCTR - Battery Protection Short-current Timing Register */
#define    HCPT0           0       // High-current Protection Timing bit 0
#define    HCPT1           1       // High-current Protection Timing bit 1
#define    HCPT2           2       // High-current Protection Timing bit 2
#define    HCPT3           3       // High-current Protection Timing bit 3
#define    HCPT4           4       // High-current Protection Timing bit 4
#define    HCPT5           5       // High-current Protection Timing bit 5

/* BPOCTR - Battery Protection Over-current Timing Register */
#define    OCPT0           0       // Over-current Protection Timing bit 0
#define    OCPT1           1       // Over-current Protection Timing bit 1
#define    OCPT2           2       // Over-current Protection Timing bit 2
#define    OCPT3           3       // Over-current Protection Timing bit 3
#define    OCPT4           4       // Over-current Protection Timing bit 4
#define    OCPT5           5       // Over-current Protection Timing bit 5

/* BPSCTR - Battery Protection Short-current Timing Register */
#define    SCPT0           0       // Short-current Protection Timing
#define    SCPT1           1       // Short-current Protection Timing
#define    SCPT2           2       // Short-current Protection Timing
#define    SCPT3           3       // Short-current Protection Timing
#define    SCPT4           4       // Short-current Protection Timing
#define    SCPT5           5       // Short-current Protection Timing
#define    SCPT6           6       // Short-current Protection Timing

/* BPCHCD - Battery Protection Charge-High-current Detection Level Register */
#define    CHCDL0          0       // Charge High-current Detection Level
#define    CHCDL1          1       // Charge High-current Detection Level
#define    CHCDL2          2       // Charge High-current Detection Level
#define    CHCDL3          3       // Charge High-current Detection Level
#define    CHCDL4          4       // Charge High-current Detection Level
#define    CHCDL5          5       // Charge High-current Detection Level
#define    CHCDL6          6       // Charge High-current Detection Level
#define    CHCDL7          7       // Charge High-current Detection Level

/* BPDHCD - Battery Protection Discharge-High-current Detection Level Register */
#define    DHCDL0          0       // Discharge High-current Detection Level bit 0
#define    DHCDL1          1       // Discharge High-current Detection Level bit 1
#define    DHCDL2          2       // Discharge High-current Detection Level bit 2
#define    DHCDL3          3       // Discharge High-current Detection Level bit 3
#define    DHCDL4          4       // Discharge High-current Detection Level bit 4
#define    DHCDL5          5       // Discharge High-current Detection Level bit 5
#define    DHCDL6          6       // Discharge High-current Detection Level bit 6
#define    DHCDL7          7       // Discharge High-current Detection Level bit 7

/* BPCOCD - Battery Protection Charge-Over-current Detection Level Register */
#define    COCDL0          0       // Charge Over-current Detection Level
#define    COCDL1          1       // Charge Over-current Detection Level
#define    COCDL2          2       // Charge Over-current Detection Level
#define    COCDL3          3       // Charge Over-current Detection Level
#define    COCDL4          4       // Charge Over-current Detection Level
#define    COCDL5          5       // Charge Over-current Detection Level
#define    COCDL6          6       // Charge Over-current Detection Level
#define    COCDL7          7       // Charge Over-current Detection Level

/* BPDOCD - Battery Protection Discharge-Over-current Detection Level Register */
#define    DOCDL0          0       // Discharge Over-current Detection Level bit0
#define    DOCDL1          1       // Discharge Over-current Detection Level bit1
#define    DOCDL2          2       // Discharge Over-current Detection Level bit2
#define    DOCDL3          3       // Discharge Over-current Detection Level bit3
#define    DOCDL4          4       // Discharge Over-current Detection Level bit4
#define    DOCDL5          5       // Discharge Over-current Detection Level bit5
#define    DOCDL6          6       // Discharge Over-current Detection Level bit6
#define    DOCDL7          7       // Discharge Over-current Detection Level bit7

/* BPSCD - Battery Protection Short-Circuit Detection Level Register */
#define    SCDL0           0       // Short-circuit Detection Level bit 0
#define    SCDL1           1       // Short-circuit Detection Level bit 1
#define    SCDL2           2       // Short-circuit Detection Level bit 2
#define    SCDL3           3       // Short-circuit Detection Level bit 3
#define    SCDL4           4       // Short-circuit Detection Level bit 4
#define    SCDL5           5       // Short-circuit Detection Level bit 5
#define    SCDL6           6       // Short-circuit Detection Level bit 6
#define    SCDL7           7       // Short-circuit Detection Level bit 7

/* BPIFR - Battery Protection Interrupt Flag Register */
#define    CHCIF           0       // Charge High-current Protection Activated Interrupt
#define    DHCIF           1       // Disharge High-current Protection Activated Interrupt
#define    COCIF           2       // Charge Over-current Protection Activated Interrupt Flag
#define    DOCIF           3       // Discharge Over-current Protection Activated Interrupt Flag
#define    SCIF            4       // Short-circuit Protection Activated Interrupt Flag

/* BPIMSK - Battery Protection Interrupt Mask Register */
#define    CHCIE           0       // Charger High-current Protection Activated Interrupt
#define    DHCIE           1       // Discharger High-current Protection Activated Interrupt
#define    COCIE           2       // Charge Over-current Protection Activated Interrupt Enable
#define    DOCIE           3       // Discharge Over-current Protection Activated Interrupt Enable
#define    SCIE            4       // Short-circuit Protection Activated Interrupt Enable


/* ***** CHARGER_DETECT *************** */
/* CHGDCSR - Charger Detect Control and Status Register */
#define    CHGDIE          0       // Charger Detect Interrupt Enable
#define    CHGDIF          1       // Charger Detect Interrupt Flag
#define    CHGDISC0        2       // Charger Detect Interrupt Sense Control
#define    CHGDISC1        3       // Charger Detect Interrupt Sense Control
#define    BATTPVL         4       // BATT Pin Voltage Level


/* ***** VOLTAGE_REGULATOR ************ */
/* ROCR - Regulator Operating Condition Register */
#define    ROCWIE          0       // ROC Warning Interrupt Enable
#define    ROCWIF          1       // ROC Warning Interrupt Flag
#define    ROCD            4       // ROC Disable
#define    ROCS            7       // ROC Status


/* ***** BANDGAP ********************** */
/* BGCSR - Bandgap Control and Status Register */
#define    BGSCDIE         0       // Bandgap Short Circuit Detection Interrupt Enable
#define    BGSCDIF         1       // Bandgap Short Circuit Detection Interrupt Flag
#define    BGSCDE          4       // Bandgap Short Circuit Detection Enabled
#define    BGD             5       // Bandgap Disable

/* BGCRR - Bandgap Calibration of Resistor Ladder */
#define    BGCR0           0       // Bandgap Calibration of Resistor Ladder Bit 0
#define    BGCR1           1       // Bandgap Calibration of Resistor Ladder Bit 1
#define    BGCR2           2       // Bandgap Calibration of Resistor Ladder Bit 2
#define    BGCR3           3       // Bandgap Calibration of Resistor Ladder Bit 3
#define    BGCR4           4       // Bandgap Calibration of Resistor Ladder Bit 4
#define    BGCR5           5       // Bandgap Calibration of Resistor Ladder Bit 5
#define    BGCR6           6       // Bandgap Calibration of Resistor Ladder Bit 6
#define    BGCR7           7       // Bandgap Calibration of Resistor Ladder Bit 7

/* BGCCR - Bandgap Calibration Register */
#define    BGCC0           0       // BG Calibration of PTAT Current Bit 0
#define    BGCC1           1       // BG Calibration of PTAT Current Bit 1
#define    BGCC2           2       // BG Calibration of PTAT Current Bit 2
#define    BGCC3           3       // BG Calibration of PTAT Current Bit 3
#define    BGCC4           4       // BG Calibration of PTAT Current Bit 4
#define    BGCC5           5       // BG Calibration of PTAT Current Bit 5


/* ***** CPU ************************** */
/* SREG - Status Register */
#define    SREG_C          0       // Carry Flag
#define    SREG_Z          1       // Zero Flag
#define    SREG_N          2       // Negative Flag
#define    SREG_V          3       // Two's Complement Overflow Flag
#define    SREG_S          4       // Sign Bit
#define    SREG_H          5       // Half Carry Flag
#define    SREG_T          6       // Bit Copy Storage
#define    SREG_I          7       // Global Interrupt Enable

/* MCUCR - MCU Control Register */
#define    IVCE            0       // Interrupt Vector Change Enable
#define    IVSEL           1       // Interrupt Vector Select
#define    PUD             4       // Pull-up disable
#define    CKOE            5       // Clock Output Enable

/* MCUSR - MCU Status Register */
#define    PORF            0       // Power-on reset flag
#define    EXTRF           1       // External Reset Flag
#define    BODRF           2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag
#define    OCDRF           4       // OCD Reset Flag

/* FOSCCAL - Fast Oscillator Calibration Value */
#define    FCAL0           0       // Oscillator Calibration Value Bit0
#define    FCAL1           1       // Oscillator Calibration Value Bit1
#define    FCAL2           2       // Oscillator Calibration Value Bit2
#define    FCAL3           3       // Oscillator Calibration Value Bit3
#define    FCAL4           4       // Oscillator Calibration Value Bit4
#define    FCAL5           5       // Oscillator Calibration Value Bit5
#define    FCAL6           6       // Oscillator Calibration Value Bit6
#define    FCAL7           7       // Oscillator Calibration Value Bit7

/* OSICSR - Oscillator Sampling Interface Control and Status Register */
#define    OSIEN           0       // Oscillator Sampling Interface Enable
#define    OSIST           1       // Oscillator Sampling Interface Status
#define    OSISEL0         4       // Oscillator Sampling Interface Select 0

/* SMCR - Sleep Mode Control Register */
#define    SE              0       // Sleep Enable
#define    SM0             1       // Sleep Mode Select bit 0
#define    SM1             2       // Sleep Mode Select bit 1
#define    SM2             3       // Sleep Mode Select bit 2

/* GPIOR2 - General Purpose IO Register 2 */
#define    GPIOR20         0       // General Purpose IO Register 2 bit 0
#define    GPIOR21         1       // General Purpose IO Register 2 bit 1
#define    GPIOR22         2       // General Purpose IO Register 2 bit 2
#define    GPIOR23         3       // General Purpose IO Register 2 bit 3
#define    GPIOR24         4       // General Purpose IO Register 2 bit 4
#define    GPIOR25         5       // General Purpose IO Register 2 bit 5
#define    GPIOR26         6       // General Purpose IO Register 2 bit 6
#define    GPIOR27         7       // General Purpose IO Register 2 bit 7

/* GPIOR1 - General Purpose IO Register 1 */
#define    GPIOR10         0       // General Purpose IO Register 1 bit 0
#define    GPIOR11         1       // General Purpose IO Register 1 bit 1
#define    GPIOR12         2       // General Purpose IO Register 1 bit 2
#define    GPIOR13         3       // General Purpose IO Register 1 bit 3
#define    GPIOR14         4       // General Purpose IO Register 1 bit 4
#define    GPIOR15         5       // General Purpose IO Register 1 bit 5
#define    GPIOR16         6       // General Purpose IO Register 1 bit 6
#define    GPIOR17         7       // General Purpose IO Register 1 bit 7

/* GPIOR0 - General Purpose IO Register 0 */
#define    GPIOR00         0       // General Purpose IO Register 0 bit 0
#define    GPIOR01         1       // General Purpose IO Register 0 bit 1
#define    GPIOR02         2       // General Purpose IO Register 0 bit 2
#define    GPIOR03         3       // General Purpose IO Register 0 bit 3
#define    GPIOR04         4       // General Purpose IO Register 0 bit 4
#define    GPIOR05         5       // General Purpose IO Register 0 bit 5
#define    GPIOR06         6       // General Purpose IO Register 0 bit 6
#define    GPIOR07         7       // General Purpose IO Register 0 bit 7

/* DIDR0 - Digital Input Disable Register */
#define    PA0DID          0       // When this bit is written logic one, the digital input buffer of the corresponding V_ADC pin is disabled.
#define    PA1DID          1       // When this bit is written logic one, the digital input buffer of the corresponding V_ADC pin is disabled.

/* PRR0 - Power Reduction Register 0 */
#define    PRVADC          0       // Power Reduction V-ADC
#define    PRTIM0          1       // Power Reduction Timer/Counter0
#define    PRTIM1          2       // Power Reduction Timer/Counter1
#define    PRSPI           3       // Power reduction SPI
#define    PRVRM           5       // Power Reduction Voltage Regulator Monitor
#define    PRTWI           6       // Power Reduction TWI

/* CLKPR - Clock Prescale Register */
#define    CLKPS0          0       // Clock Prescaler Select Bit 0
#define    CLKPS1          1       // Clock Prescaler Select Bit 1
#define    CLKPCE          7       // Clock Prescaler Change Enable


/* ***** PORTA ************************ */
/* PORTA - Port A Data Register */
#define    PORTA0          0       // Port A Data Register bit 0
#define    PORTA1          1       // Port A Data Register bit 1
#define    PORTA2          2       // Port A Data Register bit 2
#define    PORTA3          3       // Port A Data Register bit 3

/* DDRA - Port A Data Direction Register */
#define    DDA0            0       // Data Direction Register, Port A, bit 0
#define    DDA1            1       // Data Direction Register, Port A, bit 1
#define    DDA2            2       // Data Direction Register, Port A, bit 2
#define    DDA3            3       // Data Direction Register, Port A, bit 3

/* PINA - Port A Input Pins */
#define    PINA0           0       // Input Pins, Port A bit 0
#define    PINA1           1       // Input Pins, Port A bit 1
#define    PINA2           2       // Input Pins, Port A bit 2
#define    PINA3           3       // Input Pins, Port A bit 3


/* ***** PORTB ************************ */
/* PORTB - Port B Data Register */
#define    PORTB0          0       // Port B Data Register bit 0
#define    PORTB1          1       // Port B Data Register bit 1
#define    PORTB2          2       // Port B Data Register bit 2
#define    PORTB3          3       // Port B Data Register bit 3
#define    PORTB4          4       // Port B Data Register bit 4
#define    PORTB5          5       // Port B Data Register bit 5
#define    PORTB6          6       // Port B Data Register bit 6
#define    PORTB7          7       // Port B Data Register bit 7

/* DDRB - Port B Data Direction Register */
#define    DDB0            0       // Port B Data Direction Register bit 0
#define    DDB1            1       // Port B Data Direction Register bit 1
#define    DDB2            2       // Port B Data Direction Register bit 2
#define    DDB3            3       // Port B Data Direction Register bit 3
#define    DDB4            4       // Port B Data Direction Register bit 4
#define    DDB5            5       // Port B Data Direction Register bit 5
#define    DDB6            6       // Port B Data Direction Register bit 6
#define    DDB7            7       // Port B Data Direction Register bit 7

/* PINB - Port B Input Pins */
#define    PINB0           0       // Port B Input Pins bit 0
#define    PINB1           1       // Port B Input Pins bit 1
#define    PINB2           2       // Port B Input Pins bit 2
#define    PINB3           3       // Port B Input Pins bit 3
#define    PINB4           4       // Port B Input Pins bit 4
#define    PINB5           5       // Port B Input Pins bit 5
#define    PINB6           6       // Port B Input Pins bit 6
#define    PINB7           7       // Port B Input Pins bit 7


/* ***** PORTC ************************ */
/* PORTC - Port C Data Register */
#define    PORTC0          0       // Port C Data Register bit 0
#define    PORTC1          1       // Port C Data Register bit 1
#define    PORTC2          2       // Port C Data Register bit 2
#define    PORTC3          3       // Port C Data Register bit 3
#define    PORTC4          4       // Port C Data Register bit 4
#define    PORTC5          5       // Port C Data Register bit 5

/* PINC - Port C Input Pins */
#define    PINC0           0       // Port C Input Pins bit 0
#define    PINC1           1       // Port C Input Pins bit 1
#define    PINC2           2       // Port C Input Pins bit 2
#define    PINC3           3       // Port C Input Pins bit 3
#define    PINC4           4       // Port C Input Pins bit 4


/* ***** TIMER_COUNTER_0 ************** */
/* TCCR0A - Timer/Counter 0 Control Register A */
#define    WGM00           0       // Waveform Generation Mode
#define    ICS0            3       // Input Capture Select
#define    ICES0           4       // Input Capture Edge Select
#define    ICNC0           5       // Input Capture Noise Canceler
#define    ICEN0           6       // Input Capture Mode Enable
#define    TCW0            7       // Timer/Counter Width

/* TCCR0B - Timer/Counter0 Control Register B */
#define    CS00            0       // Clock Select0 bit 0
#define    CS01            1       // Clock Select0 bit 1
#define    CS02            2       // Clock Select0 bit 2

/* OCR0A - Output Compare Register 0A */
#define    OCR0A0          0       //
#define    OCR0A1          1       //
#define    OCR0A2          2       //
#define    OCR0A3          3       //
#define    OCR0A4          4       //
#define    OCR0A5          5       //
#define    OCR0A6          6       //
#define    OCR0A7          7       //

/* OCR0B - Output Compare Register B */
#define    OCR0B0          0       //
#define    OCR0B1          1       //
#define    OCR0B2          2       //
#define    OCR0B3          3       //
#define    OCR0B4          4       //
#define    OCR0B5          5       //
#define    OCR0B6          6       //
#define    OCR0B7          7       //

/* TIMSK0 - Timer/Counter Interrupt Mask Register */
#define    TOIE0           0       // Timer/Counter0 Overflow Interrupt Enable
#define    OCIE0A          1       // Timer/Counter0 Output Compare A Interrupt Enable
#define    OCIE0B          2       // Timer/Counter0 Output Compare B Interrupt Enable
#define    ICIE0           3       // Timer/Counter n Input Capture Interrupt Enable

/* TIFR0 - Timer/Counter Interrupt Flag register */
#define    TOV0            0       // Timer/Counter0 Overflow Flag
#define    OCF0A           1       // Timer/Counter0 Output Compare Flag A
#define    OCF0B           2       // Timer/Counter0 Output Compare Flag B
#define    ICF0            3       // Timer/Counter 0 Input Capture Flag

/* ***** BOOT_LOAD ******************** */
/* SPMCSR - Store Program Memory Control and Status Register */
#define    SPMEN           0       // Store Program Memory Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    LBSET           3       // Lock Bit Set
#define    RWWSRE          4       // Read-While-Write Section Read Enable
#define    SIGRD           5       // Signature Row Read
#define    RWWSB           6       // Read-While-Write Section Busy
#define    SPMIE           7       // SPM Interrupt Enable

#endif

