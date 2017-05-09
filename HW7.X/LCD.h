#ifndef LCD
#define LCD
static const char ASCII[96][5]={
 {0x00, 0x00, 0x00, 0x00, 0x00}//20  
,{0x00, 0x00, 0x5f, 0x00, 0x00}//21 !
,{0x00, 0x07, 0x00, 0x07, 0x00}//22 "
,{0x14, 0x7f, 0x14, 0x7f, 0x14}//23 #
,{0x24, 0x2a, 0x7f, 0x2a, 0x12}//24 $
,{0x23, 0x13, 0x08, 0x64, 0x62}//25 %
,{0x36, 0x49, 0x55, 0x22, 0x50}//26 &
,{0x00, 0x05, 0x03, 0x00, 0x00}//27 '
,{0x00, 0x1c, 0x22, 0x41, 0x00}//28 (
,{0x00, 0x41, 0x22, 0x1c, 0x00}//29 )
,{0x14, 0x08, 0x3e, 0x08, 0x14}//2a *
,{0x08, 0x08, 0x3e, 0x08, 0x08}//2b +
,{0x00, 0x50, 0x30, 0x00, 0x00}//2c ,
,{0x08, 0x08, 0x08, 0x08, 0x08}//2d -
,{0x00, 0x60, 0x60, 0x00, 0x00}//2e .
,{0x20, 0x10, 0x08, 0x04, 0x02}//2f /
,{0x3e, 0x51, 0x49, 0x45, 0x3e}//30 0
,{0x00, 0x42, 0x7f, 0x40, 0x00}//31 1
,{0x42, 0x61, 0x51, 0x49, 0x46}//32 2
,{0x21, 0x41, 0x45, 0x4b, 0x31}//33 3
,{0x18, 0x14, 0x12, 0x7f, 0x10}//34 4
,{0x27, 0x45, 0x45, 0x45, 0x39}//35 5
,{0x3c, 0x4a, 0x49, 0x49, 0x30}//36 6
,{0x01, 0x71, 0x09, 0x05, 0x03}//37 7
,{0x36, 0x49, 0x49, 0x49, 0x36}//38 8
,{0x06, 0x49, 0x49, 0x29, 0x1e}//39 9
,{0x00, 0x36, 0x36, 0x00, 0x00}//3a :
,{0x00, 0x56, 0x36, 0x00, 0x00}//3b ;
,{0x08, 0x14, 0x22, 0x41, 0x00}//3c <
,{0x14, 0x14, 0x14, 0x14, 0x14}//3d =
,{0x00, 0x41, 0x22, 0x14, 0x08}//3e >
,{0x02, 0x01, 0x51, 0x09, 0x06}//3f ?
,{0x32, 0x49, 0x79, 0x41, 0x3e}//40 @
,{0x7e, 0x11, 0x11, 0x11, 0x7e}//41 A
,{0x7f, 0x49, 0x49, 0x49, 0x36}//42 B
,{0x3e, 0x41, 0x41, 0x41, 0x22}//43 C
,{0x7f, 0x41, 0x41, 0x22, 0x1c}//44 D
,{0x7f, 0x49, 0x49, 0x49, 0x41}//45 E
,{0x7f, 0x09, 0x09, 0x09, 0x01}//46 F
,{0x3e, 0x41, 0x49, 0x49, 0x7a}//47 G
,{0x7f, 0x08, 0x08, 0x08, 0x7f}//48 H
,{0x00, 0x41, 0x7f, 0x41, 0x00}//49 I
,{0x20, 0x40, 0x41, 0x3f, 0x01}//4a J
,{0x7f, 0x08, 0x14, 0x22, 0x41}//4b K
,{0x7f, 0x40, 0x40, 0x40, 0x40}//4c L
,{0x7f, 0x02, 0x0c, 0x02, 0x7f}//4d M
,{0x7f, 0x04, 0x08, 0x10, 0x7f}//4e N
,{0x3e, 0x41, 0x41, 0x41, 0x3e}//4f O
,{0x7f, 0x09, 0x09, 0x09, 0x06}//50 P
,{0x3e, 0x41, 0x51, 0x21, 0x5e}//51 Q
,{0x7f, 0x09, 0x19, 0x29, 0x46}//52 R
,{0x46, 0x49, 0x49, 0x49, 0x31}//53 S
,{0x01, 0x01, 0x7f, 0x01, 0x01}//54 T
,{0x3f, 0x40, 0x40, 0x40, 0x3f}//55 U
,{0x1f, 0x20, 0x40, 0x20, 0x1f}//56 V
,{0x3f, 0x40, 0x38, 0x40, 0x3f}//57 W
,{0x63, 0x14, 0x08, 0x14, 0x63}//58 X
,{0x07, 0x08, 0x70, 0x08, 0x07}//59 Y
,{0x61, 0x51, 0x49, 0x45, 0x43}//5a Z
,{0x00, 0x7f, 0x41, 0x41, 0x00}//5b [
,{0x02, 0x04, 0x08, 0x10, 0x20}//5c ?
,{0x00, 0x41, 0x41, 0x7f, 0x00}//5d ]
,{0x04, 0x02, 0x01, 0x02, 0x04}//5e ^
,{0x40, 0x40, 0x40, 0x40, 0x40}//5f _
,{0x00, 0x01, 0x02, 0x04, 0x00}//60 `
,{0x20, 0x54, 0x54, 0x54, 0x78}//61 a
,{0x7f, 0x48, 0x44, 0x44, 0x38}//62 b
,{0x38, 0x44, 0x44, 0x44, 0x20}//63 c
,{0x38, 0x44, 0x44, 0x48, 0x7f}//64 d
,{0x38, 0x54, 0x54, 0x54, 0x18}//65 e
,{0x08, 0x7e, 0x09, 0x01, 0x02}//66 f
,{0x0c, 0x52, 0x52, 0x52, 0x3e}//67 g
,{0x7f, 0x08, 0x04, 0x04, 0x78}//68 h
,{0x00, 0x44, 0x7d, 0x40, 0x00}//69 i
,{0x20, 0x40, 0x44, 0x3d, 0x00}//6a j
,{0x7f, 0x10, 0x28, 0x44, 0x00}//6b k
,{0x00, 0x41, 0x7f, 0x40, 0x00}//6c l
,{0x7c, 0x04, 0x18, 0x04, 0x78}//6d m
,{0x7c, 0x08, 0x04, 0x04, 0x78}//6e n
,{0x38, 0x44, 0x44, 0x44, 0x38}//6f o
,{0x7c, 0x14, 0x14, 0x14, 0x08}//70 p
,{0x08, 0x14, 0x14, 0x18, 0x7c}//71 q
,{0x7c, 0x08, 0x04, 0x04, 0x08}//72 r
,{0x48, 0x54, 0x54, 0x54, 0x20}//73 s
,{0x04, 0x3f, 0x44, 0x40, 0x20}//74 t
,{0x3c, 0x40, 0x40, 0x20, 0x7c}//75 u
,{0x1c, 0x20, 0x40, 0x20, 0x1c}//76 v
,{0x3c, 0x40, 0x30, 0x40, 0x3c}//77 w
,{0x44, 0x28, 0x10, 0x28, 0x44}//78 x
,{0x0c, 0x50, 0x50, 0x50, 0x3c}//79 y
,{0x44, 0x64, 0x54, 0x4c, 0x44}//7a z
,{0x00, 0x08, 0x36, 0x41, 0x00}//7b {
,{0x00, 0x00, 0x7f, 0x00, 0x00}//7c |
,{0x00, 0x41, 0x36, 0x08, 0x00}//7d }
,{0x10, 0x08, 0x08, 0x10, 0x08}//7e ?
,{0x00, 0x06, 0x09, 0x09, 0x06}//7f ?
};
#define CMD_NOP 0x00
#define CMD_SWRESET 0x01
#define CMD_SLPIN 0x10
#define CMD_SLPOUT 0x11
#define CMD_PTLON 0x12
#define CMD_NORML 0x13
#define CMD_DINVOF 0x20
#define CMD_DINVON 0x21
#define CMD_GAMMASET 0x26
#define CMD_DISPOFF 0x28
#define CMD_DISPON 0x29
#define CMD_IDLEON 0x39
#define CMD_IDLEOF 0x38
#define CMD_CLMADRS 0x2A
#define CMD_PGEADRS 0x2B
#define CMD_RAMWR 0x2C
#define CMD_RAMRD 0x2E
#define CMD_CLRSPACE 0x2D
#define CMD_PARTAREA 0x30
#define CMD_VSCLLDEF 0x33
#define CMD_TEFXLON 0x35
#define CMD_TEFXLOF 0x34
#define CMD_MADCTL 0x36
#define CMD_VSSTADRS 0x37
#define CMD_PIXFMT 0x3A
#define CMD_FRMCTR1 0xB1
#define CMD_FRMCTR2 0xB2
#define CMD_FRMCTR3 0xB3
#define CMD_DINVCTR 0xB4
#define CMD_RGBBLK 0xB5
#define CMD_DFUNCTR 0xB6
#define CMD_SDRVDIR 0xB7
#define CMD_GDRVDIR 0xB8
#define CMD_PWCTR1 0xC0
#define CMD_PWCTR2 0xC1
#define CMD_PWCTR3 0xC2
#define CMD_PWCTR4 0xC3
#define CMD_PWCTR5 0xC4
#define CMD_VCOMCTR1 0xC5
#define CMD_VCOMCTR2 0xC6
#define CMD_VCOMOFFS 0xC7
#define CMD_PGAMMAC 0xE0
#define CMD_NGAMMAC 0xE1
#define CMD_GAMRSEL 0xF2
#define _GRAMWIDTH 132
#define _GRAMHEIGH 132
#define _GRAMSIZE _GRAMWIDTH*_GRAMHEIGH
#define	BLACK 0x0000
#define WHITE 0xFFFF
#define	BLUE 0x001F
#define	RED 0xF800
#define	GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
static char pGammaSet[15]={0x36,0x29,0x12,0x22,0x1C,0x15,0x42,0xB7,0x2F,0x13,0x12,0x0A,0x11,0x0B,0x06};
static char nGammaSet[15]={0x09,0x16,0x2D,0x0D,0x13,0x15,0x40,0x48,0x53,0x0C,0x1D,0x25,0x2E,0x34,0x39};
void LCD_command(char);
void LCD_data(char);
void LCD_data16(unsigned short);
void LCD_init(void);
void LCD_drawPixel(unsigned short,unsigned short,unsigned short);
void LCD_setAddr(unsigned short,unsigned short,unsigned short,unsigned short);
void LCD_clearScreen(unsigned short);
void print_char(char,unsigned short,unsigned short,unsigned short);
void print_string(char str[],unsigned short,unsigned short,unsigned short);
void clearBar(unsigned short,unsigned short,unsigned short,unsigned short,unsigned short);
void flowbar(short,short);
#endif