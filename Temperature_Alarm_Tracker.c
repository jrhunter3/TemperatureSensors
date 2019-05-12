/* 
 * File:   FinalProject.c
 * Author: Joseph R. Hunter
 *
 * Code Basis Provided By Microchip, Inc.
 * 
 * Created on April 26, 2016, 5:38 PM
 */





/*
  Section: Configuration Files
*/
#pragma config IESO = OFF    // Internal/External Oscillator Switchover bit->Oscillator Switchover mode disabled
#pragma config PLLCFG = OFF    // 4X PLL Enable->Oscillator used directly
#pragma config PRICLKEN = OFF    // Primary clock enable bit->Primary clock can be disabled by software
#pragma config FOSC = INTIO67    // Oscillator Selection bits->Internal oscillator block
#pragma config FCMEN = ON    // Fail-Safe Clock Monitor Enable bit->Fail-Safe Clock Monitor enabled

// CONFIG2L
#pragma config BOREN = OFF    // Brown-out Reset Enable bits->Brown-out Reset disabled in hardware and software
#pragma config BORV = 250    // Brown Out Reset Voltage bits->VBOR set to 2.50 V nominal
#pragma config PWRTEN = OFF    // Power-up Timer Enable bit->Power up timer disabled

// CONFIG2H
#pragma config WDTPS = 1    // Watchdog Timer Postscale Select bits->1:1
#pragma config WDTEN = OFF    // Watchdog Timer Enable bits->Watch dog timer is always disabled. SWDTEN has no effect.

// CONFIG3H
#pragma config CCP2MX = PORTC1    // CCP2 MUX bit->CCP2 input/output is multiplexed with RC1
#pragma config P2BMX = PORTC0    // ECCP2 B output mux bit->P2B is on RC0
#pragma config HFOFST = OFF    // HFINTOSC Fast Start-up->HFINTOSC output and ready status are delayed by the oscillator stable status
#pragma config PBADEN = OFF    // PORTB A/D Enable bit->PORTB<5:0> pins are configured as digital I/O on Reset
#pragma config CCP3MX = PORTE0    // P3A/CCP3 Mux bit->P3A/CCP3 input/output is mulitplexed with RE0
#pragma config MCLRE = EXTMCLR    // MCLR Pin Enable bit->MCLR pin enabled, RE3 input pin disabled
#pragma config T3CMX = PORTB5    // Timer3 Clock input mux bit->T3CKI is on RB5

// CONFIG4L
#pragma config LVP = OFF    // Single-Supply ICSP Enable bit->Single-Supply ICSP disabled
#pragma config STVREN = OFF    // Stack Full/Underflow Reset Enable bit->Stack full/underflow will not cause Reset
#pragma config XINST = OFF    // Extended Instruction Set Enable bit->Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
#pragma config DEBUG = OFF    // Background Debug->Disabled

// CONFIG5L
#pragma config CP2 = OFF    // Code Protection Block 2->Block 2 (008000-00BFFFh) not code-protected
#pragma config CP1 = OFF    // Code Protection Block 1->Block 1 (004000-007FFFh) not code-protected
#pragma config CP3 = OFF    // Code Protection Block 3->Block 3 (00C000-00FFFFh) not code-protected
#pragma config CP0 = OFF    // Code Protection Block 0->Block 0 (000800-003FFFh) not code-protected

// CONFIG5H
#pragma config CPB = OFF    // Boot Block Code Protection bit->Boot block (000000-0007FFh) not code-protected
#pragma config CPD = OFF    // Data EEPROM Code Protection bit->Data EEPROM not code-protected

// CONFIG6L
#pragma config WRT0 = OFF    // Write Protection Block 0->Block 0 (000800-003FFFh) not write-protected
#pragma config WRT1 = OFF    // Write Protection Block 1->Block 1 (004000-007FFFh) not write-protected
#pragma config WRT2 = OFF    // Write Protection Block 2->Block 2 (008000-00BFFFh) not write-protected
#pragma config WRT3 = OFF    // Write Protection Block 3->Block 3 (00C000-00FFFFh) not write-protected

// CONFIG6H
#pragma config WRTC = OFF    // Configuration Register Write Protection bit->Configuration registers (300000-3000FFh) not write-protected
#pragma config WRTD = OFF    // Data EEPROM Write Protection bit->Data EEPROM not write-protected
#pragma config WRTB = OFF    // Boot Block Write Protection bit->Boot Block (000000-0007FFh) not write-protected

// CONFIG7L
#pragma config EBTR3 = OFF    // Table Read Protection Block 3->Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks
#pragma config EBTR1 = OFF    // Table Read Protection Block 1->Block 1 (004000-007FFFh) not protected from table reads executed in other blocks
#pragma config EBTR2 = OFF    // Table Read Protection Block 2->Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks
#pragma config EBTR0 = OFF    // Table Read Protection Block 0->Block 0 (000800-003FFFh) not protected from table reads executed in other blocks

// CONFIG7H
#pragma config EBTRB = OFF    // Boot Block Table Read Protection bit->Boot Block (000000-0007FFh) not protected from table reads executed in other blocks





/*
  Section: Included Files
*/
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>





#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN0 aliases
#define channel_AN0_TRIS               TRISA0
#define channel_AN0_LAT                LATA0
#define channel_AN0_PORT               PORTAbits.RA0
#define channel_AN0_ANS                ANSA0
#define channel_AN0_SetHigh()    do { LATA0 = 1; } while(0)
#define channel_AN0_SetLow()   do { LATA0 = 0; } while(0)
#define channel_AN0_Toggle()   do { LATA0 = ~LATA0; } while(0)
#define channel_AN0_GetValue()         PORTAbits.RA0
#define channel_AN0_SetDigitalInput()    do { TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISA0 = 0; } while(0)

#define channel_AN0_SetAnalogMode()   do { ANSA0 = 1; } while(0)
#define channel_AN0_SetDigitalMode()   do { ANSA0 = 0; } while(0)
// get/set IO_RA1 aliases
#define IO_RA1_TRIS               TRISA1
#define IO_RA1_LAT                LATA1
#define IO_RA1_PORT               PORTAbits.RA1
#define IO_RA1_ANS                ANSA1
#define IO_RA1_SetHigh()    do { LATA1 = 1; } while(0)
#define IO_RA1_SetLow()   do { LATA1 = 0; } while(0)
#define IO_RA1_Toggle()   do { LATA1 = ~LATA1; } while(0)
#define IO_RA1_GetValue()         PORTAbits.RA1
#define IO_RA1_SetDigitalInput()    do { TRISA1 = 1; } while(0)
#define IO_RA1_SetDigitalOutput()   do { TRISA1 = 0; } while(0)

#define IO_RA1_SetAnalogMode()   do { ANSA1 = 1; } while(0)
#define IO_RA1_SetDigitalMode()   do { ANSA1 = 0; } while(0)
// get/set IO_RA2 aliases
#define IO_RA2_TRIS               TRISA2
#define IO_RA2_LAT                LATA2
#define IO_RA2_PORT               PORTAbits.RA2
#define IO_RA2_ANS                ANSA2
#define IO_RA2_SetHigh()    do { LATA2 = 1; } while(0)
#define IO_RA2_SetLow()   do { LATA2 = 0; } while(0)
#define IO_RA2_Toggle()   do { LATA2 = ~LATA2; } while(0)
#define IO_RA2_GetValue()         PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISA2 = 0; } while(0)

#define IO_RA2_SetAnalogMode()   do { ANSA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()   do { ANSA2 = 0; } while(0)
// get/set IO_RA3 aliases
#define IO_RA3_TRIS               TRISA3
#define IO_RA3_LAT                LATA3
#define IO_RA3_PORT               PORTAbits.RA3
#define IO_RA3_ANS                ANSA3
#define IO_RA3_SetHigh()    do { LATA3 = 1; } while(0)
#define IO_RA3_SetLow()   do { LATA3 = 0; } while(0)
#define IO_RA3_Toggle()   do { LATA3 = ~LATA3; } while(0)
#define IO_RA3_GetValue()         PORTAbits.RA3
#define IO_RA3_SetDigitalInput()    do { TRISA3 = 1; } while(0)
#define IO_RA3_SetDigitalOutput()   do { TRISA3 = 0; } while(0)

#define IO_RA3_SetAnalogMode()   do { ANSA3 = 1; } while(0)
#define IO_RA3_SetDigitalMode()   do { ANSA3 = 0; } while(0)
// get/set IO_RA4 aliases
#define IO_RA4_TRIS               TRISA4
#define IO_RA4_LAT                LATA4
#define IO_RA4_PORT               PORTAbits.RA4
#define IO_RA4_SetHigh()    do { LATA4 = 1; } while(0)
#define IO_RA4_SetLow()   do { LATA4 = 0; } while(0)
#define IO_RA4_Toggle()   do { LATA4 = ~LATA4; } while(0)
#define IO_RA4_GetValue()         PORTAbits.RA4
#define IO_RA4_SetDigitalInput()    do { TRISA4 = 1; } while(0)
#define IO_RA4_SetDigitalOutput()   do { TRISA4 = 0; } while(0)

// get/set IO_RA5 aliases
#define IO_RA5_TRIS               TRISA5
#define IO_RA5_LAT                LATA5
#define IO_RA5_PORT               PORTAbits.RA5
#define IO_RA5_ANS                ANSA5
#define IO_RA5_SetHigh()    do { LATA5 = 1; } while(0)
#define IO_RA5_SetLow()   do { LATA5 = 0; } while(0)
#define IO_RA5_Toggle()   do { LATA5 = ~LATA5; } while(0)
#define IO_RA5_GetValue()         PORTAbits.RA5
#define IO_RA5_SetDigitalInput()    do { TRISA5 = 1; } while(0)
#define IO_RA5_SetDigitalOutput()   do { TRISA5 = 0; } while(0)

#define IO_RA5_SetAnalogMode()   do { ANSA5 = 1; } while(0)
#define IO_RA5_SetDigitalMode()   do { ANSA5 = 0; } while(0)
// get/set IO_RA6 aliases
#define IO_RA6_TRIS               TRISA6
#define IO_RA6_LAT                LATA6
#define IO_RA6_PORT               PORTAbits.RA6
#define IO_RA6_SetHigh()    do { LATA6 = 1; } while(0)
#define IO_RA6_SetLow()   do { LATA6 = 0; } while(0)
#define IO_RA6_Toggle()   do { LATA6 = ~LATA6; } while(0)
#define IO_RA6_GetValue()         PORTAbits.RA6
#define IO_RA6_SetDigitalInput()    do { TRISA6 = 1; } while(0)
#define IO_RA6_SetDigitalOutput()   do { TRISA6 = 0; } while(0)

// get/set IO_RA7 aliases
#define IO_RA7_TRIS               TRISA7
#define IO_RA7_LAT                LATA7
#define IO_RA7_PORT               PORTAbits.RA7
#define IO_RA7_SetHigh()    do { LATA7 = 1; } while(0)
#define IO_RA7_SetLow()   do { LATA7 = 0; } while(0)
#define IO_RA7_Toggle()   do { LATA7 = ~LATA7; } while(0)
#define IO_RA7_GetValue()         PORTAbits.RA7
#define IO_RA7_SetDigitalInput()    do { TRISA7 = 1; } while(0)
#define IO_RA7_SetDigitalOutput()   do { TRISA7 = 0; } while(0)

// get/set IO_RB0 aliases
#define IO_RB0_TRIS               TRISB0
#define IO_RB0_LAT                LATB0
#define IO_RB0_PORT               PORTBbits.RB0
#define IO_RB0_WPU                WPUB0
#define IO_RB0_ANS                ANSB0
#define IO_RB0_SetHigh()    do { LATB0 = 1; } while(0)
#define IO_RB0_SetLow()   do { LATB0 = 0; } while(0)
#define IO_RB0_Toggle()   do { LATB0 = ~LATB0; } while(0)
#define IO_RB0_GetValue()         PORTBbits.RB0
#define IO_RB0_SetDigitalInput()    do { TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISB0 = 0; } while(0)

#define IO_RB0_SetPullup()    do { WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()   do { WPUB0 = 0; } while(0)
#define IO_RB0_SetAnalogMode()   do { ANSB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode()   do { ANSB0 = 0; } while(0)
// get/set IO_RB1 aliases
#define IO_RB1_TRIS               TRISB1
#define IO_RB1_LAT                LATB1
#define IO_RB1_PORT               PORTBbits.RB1
#define IO_RB1_WPU                WPUB1
#define IO_RB1_ANS                ANSB1
#define IO_RB1_SetHigh()    do { LATB1 = 1; } while(0)
#define IO_RB1_SetLow()   do { LATB1 = 0; } while(0)
#define IO_RB1_Toggle()   do { LATB1 = ~LATB1; } while(0)
#define IO_RB1_GetValue()         PORTBbits.RB1
#define IO_RB1_SetDigitalInput()    do { TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISB1 = 0; } while(0)

#define IO_RB1_SetPullup()    do { WPUB1 = 1; } while(0)
#define IO_RB1_ResetPullup()   do { WPUB1 = 0; } while(0)
#define IO_RB1_SetAnalogMode()   do { ANSB1 = 1; } while(0)
#define IO_RB1_SetDigitalMode()   do { ANSB1 = 0; } while(0)
// get/set IO_RB2 aliases
#define IO_RB2_TRIS               TRISB2
#define IO_RB2_LAT                LATB2
#define IO_RB2_PORT               PORTBbits.RB2
#define IO_RB2_WPU                WPUB2
#define IO_RB2_ANS                ANSB2
#define IO_RB2_SetHigh()    do { LATB2 = 1; } while(0)
#define IO_RB2_SetLow()   do { LATB2 = 0; } while(0)
#define IO_RB2_Toggle()   do { LATB2 = ~LATB2; } while(0)
#define IO_RB2_GetValue()         PORTBbits.RB2
#define IO_RB2_SetDigitalInput()    do { TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISB2 = 0; } while(0)

#define IO_RB2_SetPullup()    do { WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()   do { WPUB2 = 0; } while(0)
#define IO_RB2_SetAnalogMode()   do { ANSB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode()   do { ANSB2 = 0; } while(0)
// get/set IO_RB3 aliases
#define IO_RB3_TRIS               TRISB3
#define IO_RB3_LAT                LATB3
#define IO_RB3_PORT               PORTBbits.RB3
#define IO_RB3_WPU                WPUB3
#define IO_RB3_ANS                ANSB3
#define IO_RB3_SetHigh()    do { LATB3 = 1; } while(0)
#define IO_RB3_SetLow()   do { LATB3 = 0; } while(0)
#define IO_RB3_Toggle()   do { LATB3 = ~LATB3; } while(0)
#define IO_RB3_GetValue()         PORTBbits.RB3
#define IO_RB3_SetDigitalInput()    do { TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISB3 = 0; } while(0)

#define IO_RB3_SetPullup()    do { WPUB3 = 1; } while(0)
#define IO_RB3_ResetPullup()   do { WPUB3 = 0; } while(0)
#define IO_RB3_SetAnalogMode()   do { ANSB3 = 1; } while(0)
#define IO_RB3_SetDigitalMode()   do { ANSB3 = 0; } while(0)
// get/set IO_RB4 aliases
#define IO_RB4_TRIS               TRISB4
#define IO_RB4_LAT                LATB4
#define IO_RB4_PORT               PORTBbits.RB4
#define IO_RB4_WPU                WPUB4
#define IO_RB4_ANS                ANSB4
#define IO_RB4_SetHigh()    do { LATB4 = 1; } while(0)
#define IO_RB4_SetLow()   do { LATB4 = 0; } while(0)
#define IO_RB4_Toggle()   do { LATB4 = ~LATB4; } while(0)
#define IO_RB4_GetValue()         PORTBbits.RB4
#define IO_RB4_SetDigitalInput()    do { TRISB4 = 1; } while(0)
#define IO_RB4_SetDigitalOutput()   do { TRISB4 = 0; } while(0)

#define IO_RB4_SetPullup()    do { WPUB4 = 1; } while(0)
#define IO_RB4_ResetPullup()   do { WPUB4 = 0; } while(0)
#define IO_RB4_SetAnalogMode()   do { ANSB4 = 1; } while(0)
#define IO_RB4_SetDigitalMode()   do { ANSB4 = 0; } while(0)
// get/set IO_RB5 aliases
#define IO_RB5_TRIS               TRISB5
#define IO_RB5_LAT                LATB5
#define IO_RB5_PORT               PORTBbits.RB5
#define IO_RB5_WPU                WPUB5
#define IO_RB5_ANS                ANSB5
#define IO_RB5_SetHigh()    do { LATB5 = 1; } while(0)
#define IO_RB5_SetLow()   do { LATB5 = 0; } while(0)
#define IO_RB5_Toggle()   do { LATB5 = ~LATB5; } while(0)
#define IO_RB5_GetValue()         PORTBbits.RB5
#define IO_RB5_SetDigitalInput()    do { TRISB5 = 1; } while(0)
#define IO_RB5_SetDigitalOutput()   do { TRISB5 = 0; } while(0)

#define IO_RB5_SetPullup()    do { WPUB5 = 1; } while(0)
#define IO_RB5_ResetPullup()   do { WPUB5 = 0; } while(0)
#define IO_RB5_SetAnalogMode()   do { ANSB5 = 1; } while(0)
#define IO_RB5_SetDigitalMode()   do { ANSB5 = 0; } while(0)
// get/set IO_RB6 aliases
#define IO_RB6_TRIS               TRISB6
#define IO_RB6_LAT                LATB6
#define IO_RB6_PORT               PORTBbits.RB6
#define IO_RB6_WPU                WPUB6
#define IO_RB6_SetHigh()    do { LATB6 = 1; } while(0)
#define IO_RB6_SetLow()   do { LATB6 = 0; } while(0)
#define IO_RB6_Toggle()   do { LATB6 = ~LATB6; } while(0)
#define IO_RB6_GetValue()         PORTBbits.RB6
#define IO_RB6_SetDigitalInput()    do { TRISB6 = 1; } while(0)
#define IO_RB6_SetDigitalOutput()   do { TRISB6 = 0; } while(0)

#define IO_RB6_SetPullup()    do { WPUB6 = 1; } while(0)
#define IO_RB6_ResetPullup()   do { WPUB6 = 0; } while(0)
// get/set IO_RB7 aliases
#define IO_RB7_TRIS               TRISB7
#define IO_RB7_LAT                LATB7
#define IO_RB7_PORT               PORTBbits.RB7
#define IO_RB7_WPU                WPUB7
#define IO_RB7_SetHigh()    do { LATB7 = 1; } while(0)
#define IO_RB7_SetLow()   do { LATB7 = 0; } while(0)
#define IO_RB7_Toggle()   do { LATB7 = ~LATB7; } while(0)
#define IO_RB7_GetValue()         PORTBbits.RB7
#define IO_RB7_SetDigitalInput()    do { TRISB7 = 1; } while(0)
#define IO_RB7_SetDigitalOutput()   do { TRISB7 = 0; } while(0)

#define IO_RB7_SetPullup()    do { WPUB7 = 1; } while(0)
#define IO_RB7_ResetPullup()   do { WPUB7 = 0; } while(0)
// get/set IO_RC0 aliases
#define IO_RC0_TRIS               TRISC0
#define IO_RC0_LAT                LATC0
#define IO_RC0_PORT               PORTCbits.RC0
#define IO_RC0_SetHigh()    do { LATC0 = 1; } while(0)
#define IO_RC0_SetLow()   do { LATC0 = 0; } while(0)
#define IO_RC0_Toggle()   do { LATC0 = ~LATC0; } while(0)
#define IO_RC0_GetValue()         PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISC0 = 0; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS               TRISC1
#define IO_RC1_LAT                LATC1
#define IO_RC1_PORT               PORTCbits.RC1
#define IO_RC1_SetHigh()    do { LATC1 = 1; } while(0)
#define IO_RC1_SetLow()   do { LATC1 = 0; } while(0)
#define IO_RC1_Toggle()   do { LATC1 = ~LATC1; } while(0)
#define IO_RC1_GetValue()         PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISC1 = 0; } while(0)

// get/set P1A aliases
#define P1A_TRIS               TRISC2
#define P1A_LAT                LATC2
#define P1A_PORT               PORTCbits.RC2
#define P1A_ANS                ANSC2
#define P1A_SetHigh()    do { LATC2 = 1; } while(0)
#define P1A_SetLow()   do { LATC2 = 0; } while(0)
#define P1A_Toggle()   do { LATC2 = ~LATC2; } while(0)
#define P1A_GetValue()         PORTCbits.RC2
#define P1A_SetDigitalInput()    do { TRISC2 = 1; } while(0)
#define P1A_SetDigitalOutput()   do { TRISC2 = 0; } while(0)

#define P1A_SetAnalogMode()   do { ANSC2 = 1; } while(0)
#define P1A_SetDigitalMode()   do { ANSC2 = 0; } while(0)
// get/set SCL1 aliases
#define SCL1_TRIS               TRISC3
#define SCL1_LAT                LATC3
#define SCL1_PORT               PORTCbits.RC3
#define SCL1_ANS                ANSC3
#define SCL1_SetHigh()    do { LATC3 = 1; } while(0)
#define SCL1_SetLow()   do { LATC3 = 0; } while(0)
#define SCL1_Toggle()   do { LATC3 = ~LATC3; } while(0)
#define SCL1_GetValue()         PORTCbits.RC3
#define SCL1_SetDigitalInput()    do { TRISC3 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISC3 = 0; } while(0)

#define SCL1_SetAnalogMode()   do { ANSC3 = 1; } while(0)
#define SCL1_SetDigitalMode()   do { ANSC3 = 0; } while(0)
// get/set SDA1 aliases
#define SDA1_TRIS               TRISC4
#define SDA1_LAT                LATC4
#define SDA1_PORT               PORTCbits.RC4
#define SDA1_ANS                ANSC4
#define SDA1_SetHigh()    do { LATC4 = 1; } while(0)
#define SDA1_SetLow()   do { LATC4 = 0; } while(0)
#define SDA1_Toggle()   do { LATC4 = ~LATC4; } while(0)
#define SDA1_GetValue()         PORTCbits.RC4
#define SDA1_SetDigitalInput()    do { TRISC4 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISC4 = 0; } while(0)

#define SDA1_SetAnalogMode()   do { ANSC4 = 1; } while(0)
#define SDA1_SetDigitalMode()   do { ANSC4 = 0; } while(0)
// get/set IO_RC5 aliases
#define IO_RC5_TRIS               TRISC5
#define IO_RC5_LAT                LATC5
#define IO_RC5_PORT               PORTCbits.RC5
#define IO_RC5_ANS                ANSC5
#define IO_RC5_SetHigh()    do { LATC5 = 1; } while(0)
#define IO_RC5_SetLow()   do { LATC5 = 0; } while(0)
#define IO_RC5_Toggle()   do { LATC5 = ~LATC5; } while(0)
#define IO_RC5_GetValue()         PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISC5 = 0; } while(0)

#define IO_RC5_SetAnalogMode()   do { ANSC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()   do { ANSC5 = 0; } while(0)
// get/set TX1 aliases
#define TX1_TRIS               TRISC6
#define TX1_LAT                LATC6
#define TX1_PORT               PORTCbits.RC6
#define TX1_ANS                ANSC6
#define TX1_SetHigh()    do { LATC6 = 1; } while(0)
#define TX1_SetLow()   do { LATC6 = 0; } while(0)
#define TX1_Toggle()   do { LATC6 = ~LATC6; } while(0)
#define TX1_GetValue()         PORTCbits.RC6
#define TX1_SetDigitalInput()    do { TRISC6 = 1; } while(0)
#define TX1_SetDigitalOutput()   do { TRISC6 = 0; } while(0)

#define TX1_SetAnalogMode()   do { ANSC6 = 1; } while(0)
#define TX1_SetDigitalMode()   do { ANSC6 = 0; } while(0)
// get/set RX1 aliases
#define RX1_TRIS               TRISC7
#define RX1_LAT                LATC7
#define RX1_PORT               PORTCbits.RC7
#define RX1_ANS                ANSC7
#define RX1_SetHigh()    do { LATC7 = 1; } while(0)
#define RX1_SetLow()   do { LATC7 = 0; } while(0)
#define RX1_Toggle()   do { LATC7 = ~LATC7; } while(0)
#define RX1_GetValue()         PORTCbits.RC7
#define RX1_SetDigitalInput()    do { TRISC7 = 1; } while(0)
#define RX1_SetDigitalOutput()   do { TRISC7 = 0; } while(0)

#define RX1_SetAnalogMode()   do { ANSC7 = 1; } while(0)
#define RX1_SetDigitalMode()   do { ANSC7 = 0; } while(0)
// get/set IO_RD0 aliases
#define IO_RD0_TRIS               TRISD0
#define IO_RD0_LAT                LATD0
#define IO_RD0_PORT               PORTDbits.RD0
#define IO_RD0_ANS                ANSD0
#define IO_RD0_SetHigh()    do { LATD0 = 1; } while(0)
#define IO_RD0_SetLow()   do { LATD0 = 0; } while(0)
#define IO_RD0_Toggle()   do { LATD0 = ~LATD0; } while(0)
#define IO_RD0_GetValue()         PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISD0 = 0; } while(0)

#define IO_RD0_SetAnalogMode()   do { ANSD0 = 1; } while(0)
#define IO_RD0_SetDigitalMode()   do { ANSD0 = 0; } while(0)
// get/set IO_RD1 aliases
#define IO_RD1_TRIS               TRISD1
#define IO_RD1_LAT                LATD1
#define IO_RD1_PORT               PORTDbits.RD1
#define IO_RD1_ANS                ANSD1
#define IO_RD1_SetHigh()    do { LATD1 = 1; } while(0)
#define IO_RD1_SetLow()   do { LATD1 = 0; } while(0)
#define IO_RD1_Toggle()   do { LATD1 = ~LATD1; } while(0)
#define IO_RD1_GetValue()         PORTDbits.RD1
#define IO_RD1_SetDigitalInput()    do { TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISD1 = 0; } while(0)

#define IO_RD1_SetAnalogMode()   do { ANSD1 = 1; } while(0)
#define IO_RD1_SetDigitalMode()   do { ANSD1 = 0; } while(0)
// get/set IO_RD2 aliases
#define IO_RD2_TRIS               TRISD2
#define IO_RD2_LAT                LATD2
#define IO_RD2_PORT               PORTDbits.RD2
#define IO_RD2_ANS                ANSD2
#define IO_RD2_SetHigh()    do { LATD2 = 1; } while(0)
#define IO_RD2_SetLow()   do { LATD2 = 0; } while(0)
#define IO_RD2_Toggle()   do { LATD2 = ~LATD2; } while(0)
#define IO_RD2_GetValue()         PORTDbits.RD2
#define IO_RD2_SetDigitalInput()    do { TRISD2 = 1; } while(0)
#define IO_RD2_SetDigitalOutput()   do { TRISD2 = 0; } while(0)

#define IO_RD2_SetAnalogMode()   do { ANSD2 = 1; } while(0)
#define IO_RD2_SetDigitalMode()   do { ANSD2 = 0; } while(0)
// get/set IO_RD3 aliases
#define IO_RD3_TRIS               TRISD3
#define IO_RD3_LAT                LATD3
#define IO_RD3_PORT               PORTDbits.RD3
#define IO_RD3_ANS                ANSD3
#define IO_RD3_SetHigh()    do { LATD3 = 1; } while(0)
#define IO_RD3_SetLow()   do { LATD3 = 0; } while(0)
#define IO_RD3_Toggle()   do { LATD3 = ~LATD3; } while(0)
#define IO_RD3_GetValue()         PORTDbits.RD3
#define IO_RD3_SetDigitalInput()    do { TRISD3 = 1; } while(0)
#define IO_RD3_SetDigitalOutput()   do { TRISD3 = 0; } while(0)

#define IO_RD3_SetAnalogMode()   do { ANSD3 = 1; } while(0)
#define IO_RD3_SetDigitalMode()   do { ANSD3 = 0; } while(0)
// get/set IO_RD4 aliases
#define IO_RD4_TRIS               TRISD4
#define IO_RD4_LAT                LATD4
#define IO_RD4_PORT               PORTDbits.RD4
#define IO_RD4_ANS                ANSD4
#define IO_RD4_SetHigh()    do { LATD4 = 1; } while(0)
#define IO_RD4_SetLow()   do { LATD4 = 0; } while(0)
#define IO_RD4_Toggle()   do { LATD4 = ~LATD4; } while(0)
#define IO_RD4_GetValue()         PORTDbits.RD4
#define IO_RD4_SetDigitalInput()    do { TRISD4 = 1; } while(0)
#define IO_RD4_SetDigitalOutput()   do { TRISD4 = 0; } while(0)

#define IO_RD4_SetAnalogMode()   do { ANSD4 = 1; } while(0)
#define IO_RD4_SetDigitalMode()   do { ANSD4 = 0; } while(0)
// get/set IO_RD5 aliases
#define IO_RD5_TRIS               TRISD5
#define IO_RD5_LAT                LATD5
#define IO_RD5_PORT               PORTDbits.RD5
#define IO_RD5_ANS                ANSD5
#define IO_RD5_SetHigh()    do { LATD5 = 1; } while(0)
#define IO_RD5_SetLow()   do { LATD5 = 0; } while(0)
#define IO_RD5_Toggle()   do { LATD5 = ~LATD5; } while(0)
#define IO_RD5_GetValue()         PORTDbits.RD5
#define IO_RD5_SetDigitalInput()    do { TRISD5 = 1; } while(0)
#define IO_RD5_SetDigitalOutput()   do { TRISD5 = 0; } while(0)

#define IO_RD5_SetAnalogMode()   do { ANSD5 = 1; } while(0)
#define IO_RD5_SetDigitalMode()   do { ANSD5 = 0; } while(0)
// get/set IO_RD6 aliases
#define IO_RD6_TRIS               TRISD6
#define IO_RD6_LAT                LATD6
#define IO_RD6_PORT               PORTDbits.RD6
#define IO_RD6_ANS                ANSD6
#define IO_RD6_SetHigh()    do { LATD6 = 1; } while(0)
#define IO_RD6_SetLow()   do { LATD6 = 0; } while(0)
#define IO_RD6_Toggle()   do { LATD6 = ~LATD6; } while(0)
#define IO_RD6_GetValue()         PORTDbits.RD6
#define IO_RD6_SetDigitalInput()    do { TRISD6 = 1; } while(0)
#define IO_RD6_SetDigitalOutput()   do { TRISD6 = 0; } while(0)

#define IO_RD6_SetAnalogMode()   do { ANSD6 = 1; } while(0)
#define IO_RD6_SetDigitalMode()   do { ANSD6 = 0; } while(0)
// get/set IO_RD7 aliases
#define IO_RD7_TRIS               TRISD7
#define IO_RD7_LAT                LATD7
#define IO_RD7_PORT               PORTDbits.RD7
#define IO_RD7_ANS                ANSD7
#define IO_RD7_SetHigh()    do { LATD7 = 1; } while(0)
#define IO_RD7_SetLow()   do { LATD7 = 0; } while(0)
#define IO_RD7_Toggle()   do { LATD7 = ~LATD7; } while(0)
#define IO_RD7_GetValue()         PORTDbits.RD7
#define IO_RD7_SetDigitalInput()    do { TRISD7 = 1; } while(0)
#define IO_RD7_SetDigitalOutput()   do { TRISD7 = 0; } while(0)

#define IO_RD7_SetAnalogMode()   do { ANSD7 = 1; } while(0)
#define IO_RD7_SetDigitalMode()   do { ANSD7 = 0; } while(0)
// get/set IO_RE0 aliases
#define IO_RE0_TRIS               TRISE0
#define IO_RE0_LAT                LATE0
#define IO_RE0_PORT               PORTEbits.RE0
#define IO_RE0_ANS                ANSE0
#define IO_RE0_SetHigh()    do { LATE0 = 1; } while(0)
#define IO_RE0_SetLow()   do { LATE0 = 0; } while(0)
#define IO_RE0_Toggle()   do { LATE0 = ~LATE0; } while(0)
#define IO_RE0_GetValue()         PORTEbits.RE0
#define IO_RE0_SetDigitalInput()    do { TRISE0 = 1; } while(0)
#define IO_RE0_SetDigitalOutput()   do { TRISE0 = 0; } while(0)

#define IO_RE0_SetAnalogMode()   do { ANSE0 = 1; } while(0)
#define IO_RE0_SetDigitalMode()   do { ANSE0 = 0; } while(0)
// get/set IO_RE1 aliases
#define IO_RE1_TRIS               TRISE1
#define IO_RE1_LAT                LATE1
#define IO_RE1_PORT               PORTEbits.RE1
#define IO_RE1_ANS                ANSE1
#define IO_RE1_SetHigh()    do { LATE1 = 1; } while(0)
#define IO_RE1_SetLow()   do { LATE1 = 0; } while(0)
#define IO_RE1_Toggle()   do { LATE1 = ~LATE1; } while(0)
#define IO_RE1_GetValue()         PORTEbits.RE1
#define IO_RE1_SetDigitalInput()    do { TRISE1 = 1; } while(0)
#define IO_RE1_SetDigitalOutput()   do { TRISE1 = 0; } while(0)

#define IO_RE1_SetAnalogMode()   do { ANSE1 = 1; } while(0)
#define IO_RE1_SetDigitalMode()   do { ANSE1 = 0; } while(0)
// get/set IO_RE2 aliases
#define IO_RE2_TRIS               TRISE2
#define IO_RE2_LAT                LATE2
#define IO_RE2_PORT               PORTEbits.RE2
#define IO_RE2_ANS                ANSE2
#define IO_RE2_SetHigh()    do { LATE2 = 1; } while(0)
#define IO_RE2_SetLow()   do { LATE2 = 0; } while(0)
#define IO_RE2_Toggle()   do { LATE2 = ~LATE2; } while(0)
#define IO_RE2_GetValue()         PORTEbits.RE2
#define IO_RE2_SetDigitalInput()    do { TRISE2 = 1; } while(0)
#define IO_RE2_SetDigitalOutput()   do { TRISE2 = 0; } while(0)

#define IO_RE2_SetAnalogMode()   do { ANSE2 = 1; } while(0)
#define IO_RE2_SetDigitalMode()   do { ANSE2 = 0; } while(0)

/*GPIO and peripheral I/O initialization*/
void PIN_MANAGER_Initialize (void);

/*Interrupt on Change Handling routine*/
void PIN_MANAGER_IOC(void);

#endif // PIN_MANAGER_H





#ifndef _I2C1_H
#define _I2C1_H
#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif
/*
 Section: Data Type Definitions
*/
/*
    This type enumeration specifies the different types of status
    that an i2c request will have. For every submission of an i2c
    transaction, the status of that transaction is available.
    Based on the status, new transactions can be requested to the
    driver or a recovery can be performed to resend the transaction.
*/
typedef enum
{
    I2C1_MESSAGE_COMPLETE,
    I2C1_MESSAGE_FAIL,
    I2C1_MESSAGE_PENDING,
    I2C1_STUCK_START,
    I2C1_MESSAGE_ADDRESS_NO_ACK,
    I2C1_DATA_NO_ACK,
    I2C1_LOST_STATE
} I2C1_MESSAGE_STATUS;

/*
    This data type is the i2c Transaction Request Block (TRB) that
    the needs to be built and sent to the driver to handle each i2c requests.
    Using the TRB, simple to complex i2c transactions can be constructed
    and sent to the i2c bus. This data type is only used by the master mode.
*/
typedef struct
{
    uint16_t  address;          // Bits <10:1> are the 10 bit address.
                                // Bits <7:1> are the 7 bit address
                                // Bit 0 is R/W (1 for read)
    uint8_t   length;           // the # of bytes in the buffer
    uint8_t   *pbuffer;         // a pointer to a buffer of length bytes
} I2C1_TRANSACTION_REQUEST_BLOCK;
        
/*
  Section: Interface Routines
*/
/*
    This routine initializes the i2c1 driver instance for : 1
    index, making it ready for clients to open and use it.
    This routine must be called before any other I2C1 routine is called.
    This routine should only be called once during system initialization.
*/
void I2C1_Initialize(void);

/*
        This function prepares a TRB, then inserts it on the i2c queue.
        Finally, it waits for the transaction to complete and returns
        the result.
*/
void I2C1_MasterWrite(
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address,
                                I2C1_MESSAGE_STATUS *pstatus);

/*
        This function prepares a TRB, then inserts it on the i2c queue.
        Finally, it waits for the transaction to complete and returns
        the result.
*/
void I2C1_MasterRead(
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address,
                                I2C1_MESSAGE_STATUS *pstatus);

/*
        The i2c processes lists of transaction requests.  Each transaction
        list is handled as a string of i2c restarts.  When the list of
        transactions is complete, an i2c stop is produced, the flag is set
        with the correct condition code and the next list is processed
        from the queue.

        This function inserts lists of requests prepared by the user
        application into the queue along with a pointer to the completion
        flag.

        The transaction is inserted into the list only if there is space
        in the list. If there is no space, the function exits with the
        flag set to I2C1_MESSAGE_FAIL.
*/
void I2C1_MasterTRBInsert(
                                uint8_t count,
                                I2C1_TRANSACTION_REQUEST_BLOCK *ptrb_list,
                                I2C1_MESSAGE_STATUS *pflag);

/*
        All i2c requests are in the form of TRB's. This helper function
        takes standard parameters and correctly formats the TRB. The R/W
        bit is set to ensure that the resulting TRB describes an i2c read
        operation.

        This function does not send the transaction. To send the transaction,
        the TRB insert function (I2C1_MasterTRBInsert()) must be called.
*/
void I2C1_MasterReadTRBBuild(
                                I2C1_TRANSACTION_REQUEST_BLOCK *ptrb,
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address);

/*
        All i2c requests are in the form of TRB's.  This helper function
        takes standard parameters and correctly formats the TRB. The R/W
        bit is cleared to ensure that the resulting TRB describes an i2c
        write operation.

        This function does not send the transaction. To send the transaction,
        the TRB insert function (I2C1_MasterTRBInsert()) must be called.
*/
void I2C1_MasterWriteTRBBuild(
                                I2C1_TRANSACTION_REQUEST_BLOCK *ptrb,
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address);

/*
        This function returns the empty status of the Master
        queue. Use this function to check if the queue is empty.
        This can verify if the Master is currently idle.
 */
bool I2C1_MasterQueueIsEmpty(void);

/*      This function returns the full status of the Master
        queue. Use this function to check if the queue is full.
        This can verify if the Master will not be able to accept
        addition transactions.
 */
bool I2C1_MasterQueueIsFull(void);
void I2C1_BusCollisionISR( void );
void I2C1_ISR ( void );
#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif

#endif //_I2C1_H
typedef union
{
    struct
    {
            uint8_t full:1;
            uint8_t empty:1;
            uint8_t reserved:6;
    }s;
    uint8_t status;
}I2C_TR_QUEUE_STATUS;
/*
    This defines the object in the i2c queue. Each entry is a composed
    of a list of TRBs, the number of the TRBs and the status of the
    currently processed TRB.
 */
typedef struct
{
    uint8_t                             count;          // a count of trb's in the trb list
    I2C1_TRANSACTION_REQUEST_BLOCK *ptrb_list;     // pointer to the trb list
    I2C1_MESSAGE_STATUS            *pTrFlag;       // set with the error of the last trb sent.
                                                        // if all trb's are sent successfully,
                                                        // then this is I2C1_MESSAGE_COMPLETE
} I2C_TR_QUEUE_ENTRY;
/*
    This defines the object that manages the sending and receiving of
    i2c master transactions.
  */
typedef struct
{
    /* Read/Write Queue */
    I2C_TR_QUEUE_ENTRY          *pTrTail;       // tail of the queue
    I2C_TR_QUEUE_ENTRY          *pTrHead;       // head of the queue
    I2C_TR_QUEUE_STATUS         trStatus;       // status of the last transaction
    uint8_t                         i2cDoneFlag;    // flag to indicate the current
                                                    // transaction is done
    uint8_t                         i2cErrors;      // keeps track of errors
} I2C_OBJECT ;

/*
    This defines the different states that the i2c master
    used to process transactions on the i2c bus.
*/
typedef enum
{
    S_MASTER_IDLE,
    S_MASTER_RESTART,
    S_MASTER_SEND_ADDR,
    S_MASTER_SEND_DATA,
    S_MASTER_SEND_STOP,
    S_MASTER_ACK_ADDR,
    S_MASTER_RCV_DATA,
    S_MASTER_RCV_STOP,
    S_MASTER_ACK_RCV_DATA,
    S_MASTER_NOACK_STOP,
    S_MASTER_SEND_ADDR_10BIT_LSB,
    S_MASTER_10BIT_RESTART,
} I2C_MASTER_STATES;
/*
 Section: Macro Definitions
*/
/* defined for I2C1 */
#ifndef I2C1_CONFIG_TR_QUEUE_LENGTH
#define I2C1_CONFIG_TR_QUEUE_LENGTH 1
#endif

#define I2C1_TRANSMIT_REG                       SSP1BUF                 // Defines the transmit register used to send data.
#define I2C1_RECEIVE_REG                        SSP1BUF                 // Defines the receive register used to receive data.

// The following control bits are used in the I2C state machine to manage
// the I2C module and determine next states.
#define I2C1_WRITE_COLLISION_STATUS_BIT         SSP1CON1bits.WCOL     // Defines the write collision status bit.
#define I2C1_MODE_SELECT_BITS                   SSP1CON1bits.SSPM     // I2C Master Mode control bit.
#define I2C1_MASTER_ENABLE_CONTROL_BITS         SSP1CON1bits.SSPEN    // I2C port enable control bit.

#define I2C1_START_CONDITION_ENABLE_BIT         SSP1CON2bits.SEN      // I2C START control bit.
#define I2C1_REPEAT_START_CONDITION_ENABLE_BIT  SSP1CON2bits.RSEN     // I2C Repeated START control bit.
#define I2C1_RECEIVE_ENABLE_BIT                 SSP1CON2bits.RCEN     // I2C Receive enable control bit.
#define I2C1_STOP_CONDITION_ENABLE_BIT          SSP1CON2bits.PEN      // I2C STOP control bit.
#define I2C1_ACKNOWLEDGE_ENABLE_BIT             SSP1CON2bits.ACKEN    // I2C ACK start control bit.
#define I2C1_ACKNOWLEDGE_DATA_BIT               SSP1CON2bits.ACKDT    // I2C ACK data control bit.
#define I2C1_ACKNOWLEDGE_STATUS_BIT             SSP1CON2bits.ACKSTAT  // I2C ACK status bit.

#define I2C1_7bit    true
/**
 Section: Local Functions
*/

void I2C1_FunctionComplete(void);
void I2C1_Stop(I2C1_MESSAGE_STATUS completion_code);

/**
 Section: Local Variables
*/

static I2C_TR_QUEUE_ENTRY                  i2c1_tr_queue[I2C1_CONFIG_TR_QUEUE_LENGTH];
static I2C_OBJECT                          i2c1_object;
static I2C_MASTER_STATES                   i2c1_state = S_MASTER_IDLE;
static uint8_t                                 i2c1_trb_count = 0;

static I2C1_TRANSACTION_REQUEST_BLOCK       *p_i2c1_trb_current = NULL;
static I2C_TR_QUEUE_ENTRY                  *p_i2c1_current = NULL;

    
    
    
    
#ifndef MCC_H
#define	MCC_H

#define _XTAL_FREQ  4000000

/*Initializes the device to the default states configured in the MCC GUI*/
void SYSTEM_Initialize(void);

/*Initializes the oscillator to the default states configured in the MCC GUI*/
void OSCILLATOR_Initialize(void);

#ifndef INTERRUPT_MANAGER_H
#define INTERRUPT_MANAGER_H

/*This macro will enable high priority global interrupts.*/
#define INTERRUPT_GlobalInterruptHighEnable() (INTCONbits.GIEH = 1)

/*This macro will disable high priority global interrupts.*/
#define INTERRUPT_GlobalInterruptHighDisable() (INTCONbits.GIEH = 0)

/*This macro will enable low priority global interrupts.*/
#define INTERRUPT_GlobalInterruptLowEnable() (INTCONbits.GIEL = 1)

/*This macro will disable low priority global interrupts.*/
#define INTERRUPT_GlobalInterruptLowDisable() (INTCONbits.GIEL = 0)

/*Initializes PIC18 peripheral interrupt priorities; enables/disables priority vectors*/
void INTERRUPT_Initialize (void);

/*High priority interrupt service routine. Calls module interrupt handlers.*/
void interrupt INTERRUPT_InterruptManagerHigh (void);

/*Low priority interrupt service routine. Calls module interrupt handlers.*/
void interrupt low_priority INTERRUPT_InterruptManagerLow (void);
#endif  // INTERRUPT_MANAGER_H

#endif	/* MCC_H */





#ifndef _APP_H
#define	_APP_H

#ifdef	__cplusplus
extern "C" {
#endif

 /**
  Section: Data Types Definitions
*/
extern uint8_t tmrCount;                                //Software timer counter

/*
    This function is called when the application starts and enters the
    Splash display mode for 2 seconds before automatically moving on to
    the Voltmeter mode (state). The main state machine enters this state
    only once at start up. 
*/
void StateInitial(void);

/*
    This routine is called each time the application enters the
    temperature mode (e.g. state). This is the Temperature state handler.
    It first displays the correct text (or menu) where the user can either
    select to goes to display the temperature readings or move go to the
    next mode (Clock). This is depending on what the user has chosen.
*/
void StateTemperature(void);

#ifdef	__cplusplus
}
#endif

#endif	/* _APP_H */





#ifndef _LCD_XC_H
#define	_LCD_XC_H

#ifdef	__cplusplus
extern "C" {
#endif

/**
 Section: Macro Definitions
*/
// set up the timing for the LCD delays
#define LCD_delay           5     // ~5mS
#define LCD_Startup         15    // ~15mS

// Command set for Hitachi 44780U LCD display controller
#define LCD_CLEAR           0x01
#define LCD_HOME            0x02
#define LCD_CURSOR_BACK     0x10
#define LCD_CURSOR_FWD      0x14
#define LCD_PAN_LEFT        0x18
#define LCD_PAN_RIGHT       0x1C
#define LCD_CURSOR_OFF      0x0C
#define LCD_CURSOR_ON       0x0E
#define LCD_CURSOR_BLINK    0x0F
#define LCD_CURSOR_LINE2    0xC0

// display controller setup commands from page 46 of Hitachi datasheet
#define FUNCTION_SET        0x28                         // 4 bit interface, 2 lines, 5x8 font
#define ENTRY_MODE          0x06                         // increment mode
#define DISPLAY_SETUP       0x0C                         // display on, cursor off, blink offd

#define LCDLine1()          LCDPutCmd(LCD_HOME)          // legacy support
#define LCDLine2()          LCDPutCmd(LCD_CURSOR_LINE2)  // legacy support
#define shift_cursor()      LCDPutCmd(LCD_CURSOR_FWD)    // legacy support
#define cursor_on()         LCDPutCmd(LCD_CURSOR_ON)     // legacy support
#define DisplayClr()        LCDPutCmd(LCD_CLEAR)         // Legacy support


//----------------------------------------------------------------------
// Definitions specific to the PICDEM 2 Plus
// These apply to the Black (2011) version.
//----------------------------------------------------------------------

// single bit for selecting command register or data register
#define instr        0
#define data         1

// These #defines create the pin connections to the LCD in case they are changed on a future demo board
#define LCD_PORT     PORTD
#define LCD_PWR      PORTDbits.RD7                      // LCD power pin
#define LCD_EN       PORTDbits.RD6                      // LCD enable
#define LCD_RW       PORTDbits.RD5                      // LCD read/write line
#define LCD_RS       PORTDbits.RD4                      // LCD register select line

#define NB_LINES    2                                   // Number of display lines
#define NB_COL      16                                  // Number of characters per line

// Function prototypes
/*This routine initializes the LCD driver.
    This routine must be called before any other LCD routine is called.*/
void LCD_Initialize(void);
 
 /*This function displays the specified ASCII character at current position on the LCD*/
void LCDPutChar(uint8_t ch);

/*This routine writes character to LCD command register*/
void LCDPutCmd(uint8_t ch);

/*This routine writes string to LCD at current cursor position*/
void LCDPutStr(const char *);                         

/*This function writes the specified nibble to the LCD.*/
void LCDWriteNibble(uint8_t ch,uint8_t rs);

/*This function positions the cursor at the specified Line and column.*/
void LCDGoto(uint8_t pos, uint8_t ln);
#ifdef	__cplusplus
}
#endif
#endif	/* _LCD_XC_H */





#ifndef _BUTTONS_H
#define	_BUTTONS_H
/*
  Section: Data Types Definitions
*/
typedef struct
        {
          uint8_t But1Pressed : 1;
          uint8_t But2Pressed : 1;
          uint8_t But3Pressed : 1;
          uint8_t But4Pressed : 1;
          uint8_t But5Pressed : 1;
          uint8_t But6Pressed : 1;
          uint8_t But7Pressed : 1;
          uint8_t But8Pressed : 1;
        } BUTMSK_T;

BUTMSK_T Buttons; // Buffer for up to 8 buttons

#define RA4_PRESSED()  (Buttons.But1Pressed)
#define RB0_PRESSED()  (Buttons.But2Pressed)
#define BOTH_PRESSED() ((Buttons.But1Pressed) && (Buttons.But2Pressed))
#define BUT_PRESSED()  ((Buttons.But1Pressed) || (Buttons.But2Pressed) || \
                        (Buttons.But3Pressed) || (Buttons.But4Pressed) || \
                        (Buttons.But5Pressed) || (Buttons.But6Pressed) || \
                        (Buttons.But7Pressed) || (Buttons.But8Pressed))

#define SET_RA4()     Buttons.But1Pressed = 1
#define RESET_RA4()   Buttons.But1Pressed = 0
#define SET_RB0()     Buttons.But2Pressed = 1
#define RESET_RB0()   Buttons.But2Pressed = 0

/*
    This function monitors RB0 and RA4 buttons on the PicDem 2
    Plus board. It starts a debounce period (filtering mechanical bounces)
    before validating a button press.*/
void CheckButtons(void);

/*This function returns to the caller what buttons have been pressed.*/
uint8_t GetButtons(void);

/*
    This function is called to initialize the button management
    environment, for proper operation. It mainly resets the button
    state flags, so they start in the released mode.
*/
void Buttons_Initialize(void);
#ifdef	__cplusplus
}
#endif
#endif	/* _BUTTONS_H */
#define DEB_TIMEOUT  2                      //Debounce value (# of Timer0 ticks)

#define RA4_BUTTON	 PORTAbits.RA4
#define RB0_BUTTON	 PORTBbits.RB0

volatile BUTMSK_T TempButtons;  // Temporary Buffer (just local) for up to 8 buttons

#define RA4_ARMED()   (TempButtons.But1Pressed == 1)
#define RB0_ARMED()   (TempButtons.But2Pressed == 1)

#define ARM_RA4()     TempButtons.But1Pressed = 1
#define NEUT_RA4()    TempButtons.But1Pressed = 0
#define ARM_RB0()     TempButtons.But2Pressed = 1
#define NEUT_RB0()    TempButtons.But2Pressed = 0

/*User defined variables*/
uint8_t debCnt1 = 0,                         // Debounce counter for button 1
      	debCnt2 = 0;                         // Debounce counter for button 2





#ifndef _TMR0_H
#define _TMR0_H

#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif
/**
  Section: TMR0 APIs
*/
/*
    This function initializes the TMR0 Registers.
    This function must be called before any other TMR0 function is called.
*/
void TMR0_Initialize(void);

/*
    This function starts the TMR0 operation.
    This function must be called after the initialization of TMR0.
*/
void TMR0_StartTimer(void);

/*
    This function stops the TMR0 operation.
    This function must be called after the start of TMR0.
*/
void TMR0_StopTimer(void);

/*
    This function reads the 8 bits TMR0 register value and return it.
*/
uint8_t TMR0_Read8bitTimer(void);

/*
    This function writes the 8 bits value to TMR0 register.
    This function must be called after the initialization of TMR0.
*/
void TMR0_Write8bitTimer(uint8_t timerVal);

/*
    This function reloads the 8 bit value to TMR0 register.
    This function must be called to write initial value into TMR0 register.
*/
void TMR0_Reload8bit(void);

/*Timer Interrupt Service Routine is called by the Interrupt Manager.*/
void TMR0_ISR(void);
#ifdef __cplusplus  // Provide C++ Compatibility
    }
#endif
#endif // _TMR0_H





#ifndef _STATEINITIAL_H
#define	_STATEINITIAL_H
#ifdef	__cplusplus
extern "C" {
#endif
/*
    This function is called to just display the splash screen when the app
    starts up, then immediately returns to the caller (state main handler).
*/
void DisplaySplashText(void);

/*
    This function is called to take and keep control of the CPU for 2 seconds & return to caller.
    It uses a software Timer (tmrCount) that's decremented by the TIMER0 interrupt
*/
void Wait2s(void);
#ifdef	__cplusplus
}
#endif
#endif	/* _STATEINITIAL_H */





#ifndef _DISPLAYMACROS_H
#define	_DISPLAYMACROS_H

#ifdef	__cplusplus
extern "C" {
#endif

/// @brief	Boot up info screen. [Splash Menu]
#define FINALPROJECT()                                         \
	do                                                  \
	{                                                   \
            LCDPutStr("   JOE HUNTER");                      \
            LCDGoto(0,1);                                   \
            LCDPutStr(" FINAL PROJECT");                    \
	}while (0);
/// @brief	Temperature function select display.
#define TEMPERATURE()                                       \
	do                                                  \
	{                                                   \
            LCDGoto(0,0);                                   \
            LCDPutStr("  Temperature");                     \
	}while (0);
/***************************** FAULT MACROS ****************************************/

/// @brief	I2C Communication Error. Check Address in I2C.C
#define COMFAULT()					   \
	do						   \
	{						   \
	    LCDGoto(0,0);				   \
	    LCDPutStr("   Temp Sensor  ");                 \
	    LCDGoto(0,1);			           \
	    LCDPutStr("   Comms Error  ");                 \
	} while (1);

/// @brief	I2C Timout Fault. Increase TO_MAX value in I2C.C
#define TOFAULT()					   \
	do						   \
	{						   \
	    LCDGoto(0,0);			           \
	    LCDPutStr("   Temp Sensor  ");                 \
	    LCDGoto(0,1);			           \
	    LCDPutStr(" Timeout  Fault ");                 \
	} while (1);
/***************************** VALUE MACROS ****************************************/
/// @brief	Display and convert TC74 temperature reading.
#define TEMPREADING()							\
	do								\
	{								\
	    LCDGoto(0,0);                                               \
	    LCDPutStr("Temp = ");                                       \
	    if (negValue == 1)						\
	    {                                                           \
                LCDPutChar('-');	                                \
            }                                                           \
	    else							\
	    {								\
		if (!(thermal/100))					\
		{                                                       \
                    LCDPutChar(' ');	                                \
                }			                                \
		else                                                    \
                {                                                       \
		    LCDPutChar(thermal/100+'0');                        \
                }                                                       \
	    }								\
	    LCDPutChar(thermal/10+'0');					\
	    LCDPutChar(thermal % 10+'0');                               \
	    LCDPutChar(223);                                            \
	    if (type == 1)					        \
	    {	                                                        \
                LCDPutStr("[F]   ");                                    \
            }                                                           \
	    else if(!type)					        \
	    {	                                                        \
                LCDPutStr("[C]   ");                                    \
            }                                                           \
	    LCDGoto(0,1);						\
        LCDPutStr("RA4=[!] RB0=Exit");                          \
 	} while (0);
// Character [223] creates the degree symbol    
/***************************** MENU MACROS *****************************************/
/// @brief	Display menu select options.
#define BIGMENU()                                                       \
	do                                                              \
	{                                                               \
	   LCDGoto(0,1);                                                \
	   LCDPutStr("RA4=Hist RB0=Now");                               \
	} while (0);    
#ifdef	__cplusplus
}
#endif

#endif	/* _DISPLAYMACROS_H */

#ifndef _STATETEMP_H
#define	_STATETEMP_H

#ifdef	__cplusplus
extern "C" {
#endif

/*
    This function is called to display the temperature selection screen
    only, then return to the caller.
*/
void DisplayTempMenu(void);

/*
    This function is called to display current temperature reading from
    the probe. It takes the specified raw reading, converts it into a real
    displayable ASCII value, and sends it out to the LCD.*/
int DisplayTemperature(uint8_t thermal,uint8_t type);

#ifdef	__cplusplus
}
#endif
#endif	/* _STATETEMP_H */

void tempAlarm(void);

/**
  Section: Global Variables
*/
uint8_t tmrCount;
volatile uint8_t timer0ReloadVal8bit;
uint8_t readValue;
uint8_t TC74_cmd = 0;                            // read temperature command
I2C1_MESSAGE_STATUS    I2C_status = I2C1_MESSAGE_COMPLETE;
uint8_t count = 0;
uint16_t I2C_Address = 0x4D;                      // slave device address















/*
 * 
 */
void main(void) {
/**
  Section: Local Variables
*/    
    uint8_t tempValue =0;
    uint8_t degreeType = 1; // 0 for Celsius, 1 for Fahrenheit
    TRISCbits.RC2 = 0; //set RC2 as output, connected to buzzer
    int i;
    int tempCheck;
    
    // Initialize the device
    SYSTEM_Initialize();

    // initialize the LCD
    LCD_Initialize();

    // Initialize buttons
    Buttons_Initialize();
    
    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();
    
    //Initial Splash Display
    StateInitial();
     
    // Temperature menu text
    DisplayTempMenu();

    while (1)
    {     
        // If next mode selected (by user)
        if(RA4_PRESSED())
        {
            // Event has been used
            RESET_RA4();

            // Clear LCD for next display
            DisplayClr();

            //return to the main function
            return;
        }

        // If temperature mode confirmed
        else if(RB0_PRESSED())
        {
            // Event has been used
            RESET_RB0();

            // Infinite loop
            while (1)
            {
                 // i2c master write transaction with the supplied parameters
                I2C1_MasterWrite( &TC74_cmd, 1, I2C_Address, &I2C_status);
                while (I2C1_MESSAGE_PENDING  == I2C_status);

                //i2c master read transaction with the supplied parameters
                I2C1_MasterRead( &readValue, 1, I2C_Address, &I2C_status);
                while (I2C1_MESSAGE_PENDING  == I2C_status );

                // Get current temperature reading
                tempValue = readValue;

                // Display current reading
                tempCheck = DisplayTemperature(tempValue,degreeType);
                
                // User chooses to exit
                if(RB0_PRESSED())
                {
                    // Event has been used
                    RESET_RB0();

                    // Clear LCD for next display
                    DisplayClr();

                    //exits the infinite loop
                    break;
                }

                //unit change
                else if(RA4_PRESSED())
                {
                    // Event has been used
                    RESET_RA4();

                    for (i=0; i<2500; i++){
                    PORTCbits.RC2=0;
                    _delay(10);
                    PORTCbits.RC2=1;
                    _delay(90);
                    }
                }
                if (tempCheck < 70 || tempCheck > 80){
                    tempAlarm();
                }
             }

            // Clear LCD for next display
            DisplayClr();

            //go to main function
            break;
        }
    }    
}




















void SYSTEM_Initialize(void)
{
    OSCILLATOR_Initialize();
    PIN_MANAGER_Initialize();
    INTERRUPT_Initialize();
    I2C1_Initialize();
    TMR0_Initialize();
}

void OSCILLATOR_Initialize(void)
{
    // SCS INTOSC; IDLEN disabled; IRCF 4MHz_HFINTOSC/4; 
    OSCCON = 0x52;
    // PRISD enabled; MFIOSEL disabled; SOSCGO disabled; 
    OSCCON2 = 0x04;
    // INTSRC disabled; PLLEN disabled; TUN 0x00; 
    OSCTUNE = 0x00;
    // Set the secondary oscillator
    
}

void LCD_Initialize()
{
    // clear latches before enabling TRIS bits
    LCD_PORT = 0;

    TRISD = 0x00;

    // power up the LCD
    LCD_PWR = 1;

    // required by display controller to allow power to stabilize
    __delay_ms(LCD_Startup);

    // required by display initialization
    LCDPutCmd(0x32);

    // set interface size, # of lines and font
    LCDPutCmd(FUNCTION_SET);

    // turn on display and sets up cursor
    LCDPutCmd(DISPLAY_SETUP);
    
    DisplayClr();

    // set cursor movement direction
    LCDPutCmd(ENTRY_MODE);

}

void LCDWriteNibble(uint8_t ch,uint8_t rs)
{
    // always send the upper nibble
    ch = (ch >> 4);

    // mask off the nibble to be transmitted
    ch = (ch & 0x0F);

    // clear the lower half of LCD_PORT
    LCD_PORT = (LCD_PORT & 0xF0);

    // move the nibble onto LCD_PORT
    LCD_PORT = (LCD_PORT | ch);

    // set data/instr bit to 0 = insructions; 1 = data
    LCD_RS = rs;

    // RW - set write mode
    LCD_RW = 0;

    // set up enable before writing nibble
    LCD_EN = 1;

    // turn off enable after write of nibble
    LCD_EN = 0;
}

void LCDPutChar(uint8_t ch)
{
    __delay_ms(LCD_delay);

    //Send higher nibble first
    LCDWriteNibble(ch,data);

    //get the lower nibble
    ch = (ch << 4);

    // Now send the low nibble
    LCDWriteNibble(ch,data);
}
    
void LCDPutCmd(uint8_t ch)
{
    __delay_ms(LCD_delay);

    //Send the higher nibble
    LCDWriteNibble(ch,instr);

    //get the lower nibble
    ch = (ch << 4);

    __delay_ms(1);

    //Now send the lower nibble
    LCDWriteNibble(ch,instr);
}
 
void LCDPutStr(const char *str)
{
    uint8_t i=0;
    
    // While string has not been fully traveresed
    while (str[i])
    {
        // Go display current char
        LCDPutChar(str[i++]);
    }
    
}

void LCDGoto(uint8_t pos,uint8_t ln)
{
    // if incorrect line or column
    if ((ln > (NB_LINES-1)) || (pos > (NB_COL-1)))
    {
        // Just do nothing
        return;
    }

    // LCD_Goto command
    LCDPutCmd((ln == 1) ? (0xC0 | pos) : (0x80 | pos));

    // Wait for the LCD to finish
    __delay_ms(LCD_delay);
}

void Buttons_Initialize(void)
{
    // Initialize all Buttons
    Buttons.But1Pressed = Buttons.But2Pressed = Buttons.But3Pressed = Buttons.But4Pressed =
    Buttons.But5Pressed = Buttons.But6Pressed = Buttons.But7Pressed = Buttons.But8Pressed =
    TempButtons.But1Pressed = TempButtons.But2Pressed = TempButtons.But3Pressed =
    TempButtons.But4Pressed = TempButtons.But5Pressed = TempButtons.But6Pressed =
    TempButtons.But7Pressed = TempButtons.But8Pressed = 0;
}

void CheckButtons(void)
{
    // If button 1 (RA4) is pressed
    if(!RA4_BUTTON)
    {
        // If already debouncing
        if(debCnt1)
        {
            // If time out elapsed
            if(!--debCnt1)
            {
            // Set the mask for button 1 (RA4) (Valid press)
            SET_RA4();

            // Neutralize temporary mask for button 1
            NEUT_RA4();
            }
        }
        // Not yet debouncing => first detection
        else
        {
        // Initialize debounce count
        debCnt1 = DEB_TIMEOUT;

         // Save temporary state for RA4
        ARM_RA4();
        }
    }
    // Button 1 (RA4) is released
    else
    {
        // Reset debounce time out
        debCnt1 = 0;

        // Neutralize temporary mask for button 1
        NEUT_RA4();
    }

    // If button 2 (RB0) is pressed
    if(!RB0_BUTTON)
    {
        // If already debouncing
        if(debCnt2)
        {
            // If debounce time's up
            if(!--debCnt2)
            {
            // Set the mask for buttone 2 (RB0) (Valid press)
            SET_RB0();

            // Neutralize temporary mask for button 2 (RB0)
            NEUT_RB0();
            }
        }
        // Not yet debouncing => first detection
        else
        {
            // Initialize debounce count
            debCnt2 = DEB_TIMEOUT;

            // Arm The temporary key detection
            ARM_RB0();
        }
    }
    // Button 2 (RB0) is released
    else
    {
        // Reset debounce time out
        debCnt2 = 0;

        // Clear temporary mask for button 2 (RB0)
        NEUT_RB0();
    }
}

uint8_t GetButtons(void)
{
    // Read all buttons
    uint8_t result = (7 << Buttons.But8Pressed) | (6 << Buttons.But7Pressed) |
                     (5 << Buttons.But6Pressed) | (4 << Buttons.But5Pressed) |
                     (3 << Buttons.But4Pressed) | (2 << Buttons.But3Pressed) |
                     (1 << Buttons.But2Pressed) | (0 << Buttons.But1Pressed);

    // Return memorized keys
    return(result);
}

void I2C1_Initialize(void)
{
    i2c1_object.pTrHead = i2c1_tr_queue;
    i2c1_object.pTrTail = i2c1_tr_queue;
    i2c1_object.trStatus.s.empty = true;
    i2c1_object.trStatus.s.full = false;

    i2c1_object.i2cErrors = 0;

    // BF RCinprocess_TXcomplete; UA dontupdate; SMP Sample At Middle; P stopbit_notdetected; S startbit_notdetected; R_nW write_noTX; CKE Idle to Active; D_nA lastbyte_address; 
    SSP1STAT = 0x00;
    // SSPEN enabled; WCOL no_collision; SSPOV no_overflow; CKP Idle:Low, Active:High; SSPM FOSC/4_SSPxADD; 
    SSP1CON1 = 0x28;
    // BOEN disabled; AHEN disabled; SBCDE disabled; SDAHT 100ns; DHEN disabled; ACKTIM ackseq; PCIE disabled; SCIE disabled; 
    SSP1CON3 = 0x00;
    // Baud Rate Generator Value: SSP1ADD 9;   
    SSP1ADD = 0x09;

    /* Byte sent or received */
    // clear the master interrupt flag
    PIR1bits.SSP1IF = 0;
    // enable the master interrupt
    PIE1bits.SSP1IE = 1;
    
}

        
uint8_t I2C1_ErrorCountGet(void)
{
    uint8_t ret;

    ret = i2c1_object.i2cErrors;
    return ret;
}

void I2C1_ISR ( void )
{
  
    static uint8_t  *pi2c_buf_ptr;
    static uint16_t i2c_address         = 0;
    static uint8_t  i2c_bytes_left      = 0;
    static uint8_t  i2c_10bit_address_restart = 0;

    PIR1bits.SSP1IF = 0;

    // Check first if there was a collision.
    // If we have a Write Collision, reset and go to idle state */
    if(I2C1_WRITE_COLLISION_STATUS_BIT)
    {
        // clear the Write colision
        I2C1_WRITE_COLLISION_STATUS_BIT = 0;
        i2c1_state = S_MASTER_IDLE;
        *(p_i2c1_current->pTrFlag) = I2C1_MESSAGE_FAIL;

        // reset the buffer pointer
        p_i2c1_current = NULL;

        return;
    }

    /* Handle the correct i2c state */
    switch(i2c1_state)
    {
        case S_MASTER_IDLE:    /* In reset state, waiting for data to send */

            if(i2c1_object.trStatus.s.empty != true)
            {
                // grab the item pointed by the head
                p_i2c1_current     = i2c1_object.pTrHead;
                i2c1_trb_count     = i2c1_object.pTrHead->count;
                p_i2c1_trb_current = i2c1_object.pTrHead->ptrb_list;

                i2c1_object.pTrHead++;

                // check if the end of the array is reached
                if(i2c1_object.pTrHead == (i2c1_tr_queue + I2C1_CONFIG_TR_QUEUE_LENGTH))
                {
                    // adjust to restart at the beginning of the array
                    i2c1_object.pTrHead = i2c1_tr_queue;
                }

                // since we moved one item to be processed, we know
                // it is not full, so set the full status to false
                i2c1_object.trStatus.s.full = false;

                // check if the queue is empty
                if(i2c1_object.pTrHead == i2c1_object.pTrTail)
                {
                    // it is empty so set the empty status to true
                    i2c1_object.trStatus.s.empty = true;
                }

                // send the start condition
                I2C1_START_CONDITION_ENABLE_BIT = 1;
                
                // start the i2c request
                i2c1_state = S_MASTER_SEND_ADDR;
            }

            break;

        case S_MASTER_RESTART:

            /* check for pending i2c Request */

            // ... trigger a REPEATED START
            I2C1_REPEAT_START_CONDITION_ENABLE_BIT = 1;

            // start the i2c request
            i2c1_state = S_MASTER_SEND_ADDR;

            break;

        case S_MASTER_SEND_ADDR_10BIT_LSB:

            if(I2C1_ACKNOWLEDGE_STATUS_BIT)
            {
                i2c1_object.i2cErrors++;
                I2C1_Stop(I2C1_MESSAGE_ADDRESS_NO_ACK);
            }
            else
            {
                // Remove bit 0 as R/W is never sent here
                I2C1_TRANSMIT_REG = (i2c_address >> 1) & 0x00FF;

                // determine the next state, check R/W
                if(i2c_address & 0x01)
                {
                    // if this is a read we must repeat start
                    // the bus to perform a read
                    i2c1_state = S_MASTER_10BIT_RESTART;
                }
                else
                {
                    // this is a write continue writing data
                    i2c1_state = S_MASTER_SEND_DATA;
                }
            }

            break;

        case S_MASTER_10BIT_RESTART:

            if(I2C1_ACKNOWLEDGE_STATUS_BIT)
            {
                i2c1_object.i2cErrors++;
                I2C1_Stop(I2C1_MESSAGE_ADDRESS_NO_ACK);
            }
            else
            {
                // ACK Status is good
                // restart the bus
                I2C1_REPEAT_START_CONDITION_ENABLE_BIT = 1;

                // fudge the address so S_MASTER_SEND_ADDR works correctly
                // we only do this on a 10-bit address resend
                i2c_address = 0x00F0 | ((i2c_address >> 8) & 0x0006);

                // set the R/W flag
                i2c_address |= 0x0001;

                // set the address restart flag so we do not change the address
                i2c_10bit_address_restart = 1;

                // Resend the address as a read
                i2c1_state = S_MASTER_SEND_ADDR;
            }

            break;

        case S_MASTER_SEND_ADDR:

            /* Start has been sent, send the address byte */

            /* Note: 
                On a 10-bit address resend (done only during a 10-bit
                device read), the original i2c_address was modified in
                S_MASTER_10BIT_RESTART state. So the check if this is
                a 10-bit address will fail and a normal 7-bit address
                is sent with the R/W bit set to read. The flag
                i2c_10bit_address_restart prevents the  address to
                be re-written.
             */
            if(i2c_10bit_address_restart != 1)
            {
                // extract the information for this message
                i2c_address    = p_i2c1_trb_current->address;
                pi2c_buf_ptr   = p_i2c1_trb_current->pbuffer;
                i2c_bytes_left = p_i2c1_trb_current->length;
            }

            // check for 10-bit address
            if(!I2C1_7bit && (0x0 != i2c_address))
            {  
                if (0 == i2c_10bit_address_restart)
                {
                    // we have a 10 bit address
                    // send bits<9:8>
                    // mask bit 0 as this is always a write                    
                    I2C1_TRANSMIT_REG = 0xF0 | ((i2c_address >> 8) & 0x0006);
                    i2c1_state = S_MASTER_SEND_ADDR_10BIT_LSB;
                }
                else
                {
                    // resending address bits<9:8> to trigger read
                    I2C1_TRANSMIT_REG = i2c_address;
                    i2c1_state = S_MASTER_ACK_ADDR;
                    // reset the flag so the next access is ok
                    i2c_10bit_address_restart = 0;
                }
            }
            else
            {
                // Transmit the address
                I2C1_TRANSMIT_REG = i2c_address;
                if(i2c_address & 0x01)
                {
                    // Next state is to wait for address to be acked
                    i2c1_state = S_MASTER_ACK_ADDR;
                }
                else
                {
                    // Next state is transmit
                    i2c1_state = S_MASTER_SEND_DATA;
                }
            }
            break;

        case S_MASTER_SEND_DATA:

            // Make sure the previous byte was acknowledged
            if(I2C1_ACKNOWLEDGE_STATUS_BIT)
            {
                // Transmission was not acknowledged
                i2c1_object.i2cErrors++;

                // Reset the Ack flag
                I2C1_ACKNOWLEDGE_STATUS_BIT = 0;

                // Send a stop flag and go back to idle
                I2C1_Stop(I2C1_DATA_NO_ACK);

            }
            else
            {
                // Did we send them all ?
                if(i2c_bytes_left-- == 0U)
                {
                    // yup sent them all!

                    // update the trb pointer
                    p_i2c1_trb_current++;

                    // are we done with this string of requests?
                    if(--i2c1_trb_count == 0)
                    {
                        I2C1_Stop(I2C1_MESSAGE_COMPLETE);
                    }
                    else
                    {
                        // no!, there are more TRB to be sent.
                        //I2C1_START_CONDITION_ENABLE_BIT = 1;

                        // In some cases, the slave may require
                        // a restart instead of a start. So use this one
                        // instead.
                        I2C1_REPEAT_START_CONDITION_ENABLE_BIT = 1;

                        // start the i2c request
                        i2c1_state = S_MASTER_SEND_ADDR;

                    }
                }
                else
                {
                    // Grab the next data to transmit
                    I2C1_TRANSMIT_REG = *pi2c_buf_ptr++;
                }
            }
            break;

        case S_MASTER_ACK_ADDR:

            /* Make sure the previous byte was acknowledged */
            if(I2C1_ACKNOWLEDGE_STATUS_BIT)
            {

                // Transmission was not acknowledged
                i2c1_object.i2cErrors++;

                // Send a stop flag and go back to idle
                I2C1_Stop(I2C1_MESSAGE_ADDRESS_NO_ACK);

                // Reset the Ack flag
                I2C1_ACKNOWLEDGE_STATUS_BIT = 0;
            }
            else
            {
                I2C1_RECEIVE_ENABLE_BIT = 1;
                i2c1_state = S_MASTER_ACK_RCV_DATA;
            }
            break;

        case S_MASTER_RCV_DATA:

            /* Acknowledge is completed.  Time for more data */

            // Next thing is to ack the data
            i2c1_state = S_MASTER_ACK_RCV_DATA;

            // Set up to receive a byte of data
            I2C1_RECEIVE_ENABLE_BIT = 1;

            break;

        case S_MASTER_ACK_RCV_DATA:

            // Grab the byte of data received and acknowledge it
            *pi2c_buf_ptr++ = I2C1_RECEIVE_REG;

            // Check if we received them all?
            if(--i2c_bytes_left)
            {

                /* No, there's more to receive */

                // No, bit 7 is clear.  Data is ok
                // Set the flag to acknowledge the data
                I2C1_ACKNOWLEDGE_DATA_BIT = 0;

                // Wait for the acknowledge to complete, then get more
                i2c1_state = S_MASTER_RCV_DATA;
            }
            else
            {

                // Yes, it's the last byte.  Don't ack it
                // Flag that we will nak the data
                I2C1_ACKNOWLEDGE_DATA_BIT = 1;

                I2C1_FunctionComplete();
            }

            // Initiate the acknowledge
            I2C1_ACKNOWLEDGE_ENABLE_BIT = 1;
            break;

        case S_MASTER_RCV_STOP:                
        case S_MASTER_SEND_STOP:

            // Send the stop flag
            I2C1_Stop(I2C1_MESSAGE_COMPLETE);
            break;

        default:

            // This case should not happen, if it does then
            // terminate the transfer
            i2c1_object.i2cErrors++;
            I2C1_Stop(I2C1_LOST_STATE);
            break;

    }
}

void I2C1_FunctionComplete(void)
{

    // update the trb pointer
    p_i2c1_trb_current++;

    // are we done with this string of requests?
    if(--i2c1_trb_count == 0)
    {
        i2c1_state = S_MASTER_SEND_STOP;
    }
    else
    {
        i2c1_state = S_MASTER_RESTART;
    }

}

void I2C1_Stop(I2C1_MESSAGE_STATUS completion_code)
{
    // then send a stop
    I2C1_STOP_CONDITION_ENABLE_BIT = 1;

    // make sure the flag pointer is not NULL
    if (p_i2c1_current->pTrFlag != NULL)
    {
        // update the flag with the completion code
        *(p_i2c1_current->pTrFlag) = completion_code;
    }

    // Done, back to idle
    i2c1_state = S_MASTER_IDLE;
    
}

void I2C1_MasterWrite(
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address,
                                I2C1_MESSAGE_STATUS *pflag)
{
    static I2C1_TRANSACTION_REQUEST_BLOCK   trBlock;

    // check if there is space in the queue
    if (i2c1_object.trStatus.s.full != true)
    {
        I2C1_MasterWriteTRBBuild(&trBlock, pdata, length, address);
        I2C1_MasterTRBInsert(1, &trBlock, pflag);
    }
    else
    {
        *pflag = I2C1_MESSAGE_FAIL;
    }

}

void I2C1_MasterRead(
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address,
                                I2C1_MESSAGE_STATUS *pflag)
{
    static I2C1_TRANSACTION_REQUEST_BLOCK   trBlock;


    // check if there is space in the queue
    if (i2c1_object.trStatus.s.full != true)
    {
        I2C1_MasterReadTRBBuild(&trBlock, pdata, length, address);
        I2C1_MasterTRBInsert(1, &trBlock, pflag);
    }
    else
    {
        *pflag = I2C1_MESSAGE_FAIL;
    }

}

void I2C1_MasterTRBInsert(
                                uint8_t count,
                                I2C1_TRANSACTION_REQUEST_BLOCK *ptrb_list,
                                I2C1_MESSAGE_STATUS *pflag)
{

    // check if there is space in the queue
    if (i2c1_object.trStatus.s.full != true)
    {
        *pflag = I2C1_MESSAGE_PENDING;

        i2c1_object.pTrTail->ptrb_list = ptrb_list;
        i2c1_object.pTrTail->count     = count;
        i2c1_object.pTrTail->pTrFlag   = pflag;
        i2c1_object.pTrTail++;

        // check if the end of the array is reached
        if (i2c1_object.pTrTail == (i2c1_tr_queue + I2C1_CONFIG_TR_QUEUE_LENGTH))
        {
            // adjust to restart at the beginning of the array
            i2c1_object.pTrTail = i2c1_tr_queue;
        }

        // since we added one item to be processed, we know
        // it is not empty, so set the empty status to false
        i2c1_object.trStatus.s.empty = false;

        // check if full
        if (i2c1_object.pTrHead == i2c1_object.pTrTail)
        {
            // it is full, set the full status to true
            i2c1_object.trStatus.s.full = true;
        }

    }
    else
    {
        *pflag = I2C1_MESSAGE_FAIL;
    }

    // for interrupt based
    if (*pflag == I2C1_MESSAGE_PENDING)
    {
        while(i2c1_state != S_MASTER_IDLE);
        {
            // force the task to run since we know that the queue has
            // something that needs to be sent
            PIR1bits.SSP1IF = true;
        }
    }   // block until request is complete

}

void I2C1_MasterReadTRBBuild(
                                I2C1_TRANSACTION_REQUEST_BLOCK *ptrb,
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address)
{
    ptrb->address  = address << 1;
    // make this a read
    ptrb->address |= 0x01;
    ptrb->length   = length;
    ptrb->pbuffer  = pdata;
}

void I2C1_MasterWriteTRBBuild(
                                I2C1_TRANSACTION_REQUEST_BLOCK *ptrb,
                                uint8_t *pdata,
                                uint8_t length,
                                uint16_t address)
{
    ptrb->address = address << 1;
    ptrb->length  = length;
    ptrb->pbuffer = pdata;
}

bool I2C1_MasterQueueIsEmpty(void)
{
    return(i2c1_object.trStatus.s.empty);
}

bool I2C1_MasterQueueIsFull(void)
{
    return(i2c1_object.trStatus.s.full);
}        
        
void I2C1_BusCollisionISR( void )
{
    // enter bus collision handling code here
}

void StateInitial(void)
{
    // Welcome message
    DisplaySplashText();

    // Leave splash screen for 2s
    Wait2s();

    // Display Jumper Warning
    DisplayClr();
    	do                                                  \
	{                                                   \
            LCDPutStr(" REMOVE JUMPERS ");                      \
            LCDGoto(0,1);                                   \
            LCDPutStr(" 6 20 21 22 23 ");                    \
	}while (0);
    
    // Leave splash screen for 2s
    Wait2s();   
        
    // Clear LCD for next display
    DisplayClr();
}

void DisplaySplashText(void)
{
    // Clear LCD
    DisplayClr();

    //Boot up info screen
    FINALPROJECT();
}

void Wait2s(void)
{
    tmrCount = 50;
    
    // While still counting
    while(tmrCount)
    {
      ;
    } // Wait here
}

void TMR0_Initialize(void)
{
    // Set TMR0 to the options selected in the User Interface

    // TMR0ON enabled; T0SE Increment_hi_lo; PSA assigned; T0CS FOSC/4; T08BIT 8-bit; T0PS 1:256; 
    T0CON = 0xD7;

    // TMR0H 0; 
    TMR0H = 0x00;

    // TMR0L 0; 
    TMR0L = 0x00;

    // Load TMR0 value to the 8-bit reload variable
    timer0ReloadVal8bit  = 0;

    // Clear Interrupt flag before enabling the interrupt
    INTCONbits.TMR0IF = 0;

    // Enabling TMR0 interrupt.
    INTCONbits.TMR0IE = 1;

    // Start TMR0
    TMR0_StartTimer();
}

void TMR0_StartTimer(void)
{
    // Start the Timer by writing to TMR0ON bit
    T0CONbits.TMR0ON = 1;
}

void TMR0_StopTimer(void)
{
    // Stop the Timer by writing to TMR0ON bit
    T0CONbits.TMR0ON = 0;
}


uint8_t TMR0_Read8bitTimer(void)
{
    uint8_t readVal;

    // read Timer0, low register only
    readVal = TMR0L;

    return readVal;
}

void TMR0_Write8bitTimer(uint8_t timerVal)
{
    // Write to the Timer0 registers, low register only
    TMR0L = timerVal;
 }

void TMR0_Reload8bit(void)
{
    //Write to the Timer0 register
    TMR0L = timer0ReloadVal8bit;
}


void TMR0_ISR(void)
{

    // clear the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;

    // reload TMR0
    TMR0L = timer0ReloadVal8bit;


    // add your TMR0 interrupt custom code
     if (tmrCount)                     // If counter Enabled by application
     {
	    	    tmrCount--;                         // The software timer is running
}
    	  CheckButtons();                           // Go scan & process buttons
}

void PIN_MANAGER_Initialize(void)
{
    LATA = 0x00;
    TRISA = 0xFF;
    ANSELA = 0x01;

    LATB = 0x00;
    TRISB = 0x01;
    ANSELB = 0x00;
    WPUB = 0x00;

    LATC = 0x18;
    TRISC = 0xFB;
    ANSELC = 0x00;

    LATD = 0x00;
    TRISD = 0x00;
    ANSELD = 0x00;

    LATE = 0x00;
    TRISE = 0x07;
    ANSELE = 0x00;

    INTCON2bits.nRBPU = 0x01;
}

void  INTERRUPT_Initialize (void)
{
    // Enable Interrupt Priority Vectors
    RCONbits.IPEN = 1;

    // Assign peripheral interrupt priority vectors

    // TMRI - high priority
    IPR1bits.TMR1IP = 1;


    // RCI - low priority
    IPR1bits.RC1IP = 0;

    // SSPI - low priority
    IPR1bits.SSP1IP = 0;

    // TXI - low priority
    IPR1bits.TX1IP = 0;

    // TMRI - low priority
    INTCON2bits.TMR0IP = 0;

    // BCLI - low priority
    IPR2bits.BCL1IP = 0;


}

void interrupt INTERRUPT_InterruptManagerHigh (void)
{
   // interrupt handler
    if(PIE1bits.TMR1IE == 1 && PIR1bits.TMR1IF == 1)
    {
        //Removed
    }
    else
    {
        //Unhandled Interrupt
    }
}
void interrupt low_priority INTERRUPT_InterruptManagerLow (void)
{
   // interrupt handler
    if(PIE1bits.SSP1IE == 1 && PIR1bits.SSP1IF == 1)
    {
        I2C1_ISR();
    }
    else if(INTCONbits.TMR0IE == 1 && INTCONbits.TMR0IF == 1)
    {
        TMR0_ISR();
    }
    else if(PIE2bits.BCL1IE == 1 && PIR2bits.BCL1IF == 1)
    {
        I2C1_BusCollisionISR();
    }
    else
    {
        //Unhandled Interrupt
    }
}

void DisplayTempMenu(void)
{
    //Temperature function select display
    TEMPERATURE();

    //Display menu select options
    BIGMENU();
}

int DisplayTemperature(uint8_t thermal,uint8_t type)
{
    volatile uint8_t negValue;
    
    // Check to see if Celsius Temperature is Negative
    if (thermal >= 128)
    {
        thermal = 256 - thermal;
        negValue = 1;
    }
    else
    {
        thermal = thermal;
        negValue = 0;
    }

    // Display the Celsius Temperature as a Fahrenheit value
    if (type == 1)
    {
        if (negValue == 0)
        {
            thermal = (((thermal*9)/5)+32);
        }
        else if (negValue == 1)
	{
           // Values larger then 18; Fahrenheit goes negative.
	   if (thermal < 18)
           {
                thermal = (((thermal)*9)/5);
                thermal = 32-thermal;
                negValue = 0;
           }
	   else
           {
                thermal = ((((thermal)*9)/5)-32);
                negValue = 1;
           }
         }
    }

    //Display and convert TC74 temperature reading
    TEMPREADING();
    return thermal;
}

void tempAlarm(void){
    int i, alarmReset = 0;
    while (alarmReset == 0){
        DisplayClr();
        LCDPutStr("[!] [!] [!] [!]");
        LCDGoto(0,1);
        LCDPutStr("ResetAlarm = RA4");
        for(i=0;i<2500;i++){    
            PORTCbits.RC2 = 1;
            _delay(90);
            PORTCbits.RC2 = 0;
            _delay(10);
        }
        for(i=0;i<2500;i++){     
            PORTCbits.RC2 = 0;
            _delay(100);
        }
        if (RA4_PRESSED()){
            RESET_RA4();
            alarmReset = 1;
        }
    }
}