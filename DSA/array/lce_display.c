/*#include <reg51.h>
sbit RS = P1 ^ 0;
sbit EN = P1 ^ 1;
sbit RW = P1 ^ 2;
void delay(unsigned int count)
{
    int i, j;
    for (i = 0; i < count; i++)
        for (j = 0; j < 112; j++)
            ;
}
void command(unsigned char cmd)
{
    P0 = cmd;
    RS = 0;
    RW = 0;
    EN = 1;
    delay(1);
    EN = 0;
    delay(5);
}
void display(unsigned char dat)
{
    P0 = dat;
    RS = 1;
    RW = 0;
    EN = 1;
    delay(1);
    EN = 0;
    delay(5);
}
void LCD_init(void)
{
    delay(20);
    command(0x38); // Initialization of 16X2 LCD in 8bit mode
    command(0x01); // Display ON Cursor OFF
    command(0x0C); // Auto Increment cursor
    command(0x83); // Clear display
    command(0x06); // Cursor at home position

    // cmd(0x38);
    // cmd(0x01);
    // cmd(0x0c);
    // cmd(0x83);
    // cmd(0x06);
}
void showMSG(char loc, char *msg, char len)
{
    int i = 0;
    command(loc);
    for (i = 0; i < len; i++)
    {
        display(msg[i]);
    }
}
void main(void)
{
    LCD_init();
    delay(100);
    command(0x01); // Clear display
    showMSG(0x80, " Welcome to ", 16);
    showMSG(0xC0, " Asian College ", 16);
    while (1)
        ;
}
*/

#include <reg51.h>
sbit rs = P1 ^ 0;
sbit rw = P1 ^ 1;
sbit e = P1 ^ 2;
void delay(unsigned int);
void cmd(unsigned char);
void dat(unsigned char);

void main(void)
{
    unsigned char ch[] = "GREATECH";
    unsigned char ch1[] = "YOUTUBE";
    unsigned int i, j, k;

    cmd(0x38);
    cmd(0x01);
    cmd(0x0c);
    cmd(0x83);
    cmd(0x06);

    for (i = 0; ch[i] != '\0'; i++)
        dat(ch[i]);

    cmd(0xc3);

    for (j = 0; ch1[j] != '\0'; j++)
        dat(ch1[j]);

    while (1)
    {
        for (k = 0; k < 16; k++)
            cmd(0x1c);
    }
}
void delay(unsigned int t)
{
    unsigned int i, j;
    e = 1;
    for (i = 0; i < t; i++)
        for (j = 0; j < 1275; j++);
    e = 0;
}

void cmd(unsigned char ch)
{

    rs = 0;
    rw = 0;
    P2 = ch;
    delay(20);
}
void dat(unsigned char ch)
{

    rs = 1;
    rw = 0;
    P2 = ch;
    delay(20);
}