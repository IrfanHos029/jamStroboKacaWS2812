#include <Adafruit_NeoPixel.h>
#include <C:\Users\wahyu\Documents\Arduino\libraries\Adafruit_GFX_Library\Fonts\FreeSerifBold9pt7b.h>

const int led_count=60;
const int led_row=5;
const int led_col=20;
const int led_pararel=1;
const int led_module=led_col/5;

Adafruit_NeoPixel pixels(led_count, D4, NEO_GRB + NEO_KHZ800);

byte data_col[led_col];
void setup() {
  // put your setup code here, to run once:
 pixels.begin();
 
}

void loop() {
  // put your main code here, to run repeatedly:

}

void led_off()
{
  for(int i=0; i<led_count;i++)
  {
    pixels.setPixelColor(i,pixels.Color(0,0,0));
  }
  pixels.show();
}

int led_from_pixel(byte row,byte col)
{
  int a=0;
  if(row%2==0)
  {
    a = (row*led_col)+col;
    //r=0,col=2 (0*60)+2=2;
    //r=2 col=5 (2*60)+5=120+5=125;
  }
  else
  {
    a = ((row+1)*led_col)-1-col;
    //r=1 c=3 ((1+1)*60)-1-3=(2*60)-1-3=120-4=116;
    //r=3 c=2 ((3+1)*60)-1-2=(4*60)-1-2=240-3=237
  }
  return a;
}

void pixels_build(String s)
{
  int c=0;
  for(byte a=0;a<s.length();a++)
  {
    int index_char=s[a]-32;
    int index_colom=4;
    for(byte i=0;i<8;i++)
    {
      byte b=0;//pgm_read_byte(&namaLibrary[index_char*8+1]);
      data_col[c]=b;
      c++;
      if(b==0 && i>2)
      {
        break;
      }
    }
  }
}


void pixels_show(byte value_r,byte value_g,byte value_b)
{
  for(byte a=0;a<8;a++)
  {
    for(int c=0;c<led_col;c++)
    {
      byte b=bitRead(data_col[c],a);
      byte r=7-a;
      int index_led = led_from_pixel(r,c);
      if(b==1)
      {
        pixels.setPixelColor(index_led,pixels.Color(value_r,value_g,value_b));
      }
      else
      {
        pixels.setPixelColor(index_led,pixels.Color(0,0,0));
      }
    }
  }
  pixels.show();
}


void pixels_slide_right(byte d,byte value_r,byte value_g,byte value_b)
{
  for(int c=0;c<led_col;c++)
  {
    for(byte a=0;a<8;a++)
    {
      byte b=bitRead(data_col[c],a);
      byte r=7-a;
      int index_led = led_from_pixel(r,c);
      if(b==1)
      {
        pixels.setPixelColor(index_led,pixels.Color(value_r,value_g,value_b));
      }
      else
      {
        pixels.setPixelColor(index_led,pixels.Color(0,0,0));
      }
    }
    pixels.show();
    delay(d);
  }
}


void pixels_slide_down(byte d,byte value_r,byte value_g,byte value_b)
{
  for(byte a=0;a<8;a++)
  {
   for(int c=0;c<led_col;c++)
    {
      byte b=bitRead(data_col[c],a);
      byte r=7-a;
      int index_led = led_from_pixel(r,c);
      if(b==1)
      {
        pixels.setPixelColor(index_led,pixels.Color(value_r,value_g,value_b));
      }
      else
      {
        pixels.setPixelColor(index_led,pixels.Color(0,0,0));
      }
    }
    pixels.show();
    delay(d);
  }
}
void pixels_print()
{
  for(byte r=0;r<8;r++)
  {
    for(int i=0;i<led_module*8;i++)
    byte b=bitRead(data_col[i],r);
    Serial.print(r);
    Serial.print(" ");
  }
  Serial.println();
}
