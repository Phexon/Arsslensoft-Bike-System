//***************************************************************************
//  File........: nokia1100_lcd_lib.h
//  Author(s)...: Chiper
//  URL(s)......: http://digitalchip.ru/
//  Device(s)...: ATMega...
//  Compiler....: AVR-GCC
//  Description.: ������� LCD-����������� �� Nokia1100 � ������������ ���������
//  Data........: 28.03.12
//  Version.....: 2.1 
//***************************************************************************
//  Notice: ��� ����������� �������� LCD-����������� ������ ���� ���������� �
//  ������ � ���� �� ����� �� ����������������
//***************************************************************************
#ifndef _NOKIA1100_LCD_LIB_H_
#define _NOKIA1100_LCD_LIB_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

//******************************************************************************
//******************************************************************************
// ��������� ����������

// ����, � �������� ��������� LCD-���������� NOKIA 1100
#define PORT_LCD PORTC
#define PIN_LCD  PINC
#define DDR_LCD  DDRC

// ������ ������� �����, � ������� ���������� ������ LCD-�����������
#define SCLK_LCD_PIN    3
#define SDA_LCD_PIN     2
#define CS_LCD_PIN      1
#define RST_LCD_PIN     0

// ��������� ������ ����� ��������. 
#define FULL_CHARSET 

// *****!!!!! ����������� ��������, ��� ������� �������� ��� LCD-����������
// *****!!!!! ����������� ���������������� ��� ���������� ����������
#define NLCD_MIN_DELAY	34

//******************************************************************************
//******************************************************************************



//******************************************************************************
// �������, �����������, ��������� ����������

#define SCLK_LCD_SET    PORT_LCD |= (1<<SCLK_LCD_PIN)
#define SDA_LCD_SET     PORT_LCD |= (1<<SDA_LCD_PIN)
#define CS_LCD_SET      PORT_LCD |= (1<<CS_LCD_PIN)
#define RST_LCD_SET     PORT_LCD |= (1<<RST_LCD_PIN)

#define SCLK_LCD_RESET  PORT_LCD &= ~(1<<SCLK_LCD_PIN)
#define SDA_LCD_RESET   PORT_LCD &= ~(1<<SDA_LCD_PIN)
#define CS_LCD_RESET    PORT_LCD &= ~(1<<CS_LCD_PIN)
#define RST_LCD_RESET   PORT_LCD &= ~(1<<RST_LCD_PIN)

#define CMD_LCD_MODE	0
#define DATA_LCD_MODE	1

#define PIXEL_ON	0
#define PIXEL_OFF	1
#define PIXEL_INV 	2

#define FILL_OFF	0
#define FILL_ON		1

#define INV_MODE_ON		0
#define INV_MODE_OFF	1

// ���������� ������� � ��������
#define NLCD_X_RES	96		// ���������� �� �����������
#define NLCD_Y_RES	68		// ���������� �� ���������

// ����������. �������� ����� ������, ��� ��� �� ����������� NOKIA1100 ������ ������ ������, � ���
// ������������ ������ ��� ����� ����� ���������� �����������. (9 ������ �� 96 ����)  
static unsigned char nlcd_memory[NLCD_X_RES-1][(NLCD_Y_RES/8)+1];
											
// ������� ���������� (���������) � �����������
// nlcd_xcurr - � ��������, nlcd_ycurr- � ������ (�������)
static unsigned char nlcd_xcurr, nlcd_ycurr;

//******************************************************************************
// ��������� �������

void nlcd_Init(void);
void nlcd_Clear(void);
void nlcd_SendByte(char mode,unsigned char c);
void nlcd_Putc(unsigned char c);
void nlcd_PutcWide(unsigned char c);
void nlcd_Print(char * message);
void nlcd_PrintF(unsigned char * message);
void nlcd_PrintWide(unsigned char * message);

void nlcd_GotoXY(char x,char y);

void nlcd_Inverse(unsigned char mode);

void nlcd_Pixel (unsigned char x,unsigned char y, unsigned char pixel_mode);
void nlcd_Line  (unsigned char x1,unsigned char y1, unsigned char x2,unsigned char y2, unsigned char pixel_mode);
void nlcd_Circle(unsigned char x, unsigned char y, unsigned char radius, unsigned char fill, unsigned char pixel_mode);
void nlcd_Rect  (unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char fill, unsigned char pixel_mode);
void nlcd_Pict  (unsigned char x, unsigned char y, unsigned char * picture);

#endif /* _NOKIA1100_LCD_LIB_H_ */
