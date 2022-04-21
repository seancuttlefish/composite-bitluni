/*******************************************************************
* Visual Display Unit (VDU)                                        *
* v0.0.1                                                           *
* 19th April 2022                                                  *
* Sean Clark                                                       *
* Interact digital Arts                                            *
* https://www.interactdigitalarts.uk/projects/vdu                  *
* See README.MD for information.                                   *
*******************************************************************/

#include <soc/rtc.h>
#include "Graphics.h"
#include "SimplePALOutput.h"

const int XRES = 320;
const int YRES = 240;
Graphics graphics(XRES, YRES);
SimplePALOutput composite;

void compositeCore(void *data)
{
  while (true) {
    composite.sendFrame(&graphics.frame);
  }
}

void setup()
{
  rtc_clk_cpu_freq_set(RTC_CPU_FREQ_240M);
  composite.init();
  graphics.init();
  xTaskCreatePinnedToCore(compositeCore, "c", 1024, NULL, 1, NULL, 0);
}

void loop()
{
  // Draw some text

   // Draw some random numbers

  // Draw some random dots
   graphics.begin(0);
  for(int i=0;i<50;i++)
  {
    graphics.dot(random(XRES),random(YRES),graphics.rgb(random(255), random(255), random(255)));
  }
  graphics.end();
  delay(5000);

  // Draw some random lines
  graphics.begin(0);
  for(int i=0;i<20;i++)
  {
    graphics.line(random(XRES),random(YRES),random(XRES),random(YRES),graphics.rgb(random(255), random(255), random(255)));
  }
  graphics.end();
  delay(5000);
  
  // Draw some random triangles
  graphics.begin(0);
  for(int i=0;i<10;i++)
  {
    graphics.fillTriangle(random(320),random(240),random(320),random(240),random(320),random(240),graphics.rgb(random(255), random(255), random(255)));
  }
  graphics.end();
  delay(5000);

  // Draw some random filled triangles
  graphics.begin(0);
  for(int i=0;i<20;i++)
  {
    graphics.triangle(random(320),random(240),random(320),random(240),random(320),random(240),graphics.rgb(random(255), random(255), random(255)));
  }
  graphics.end();
  delay(5000);

  // Draw some random rectangles
  graphics.begin(0);
  for(int i=0;i<20;i++)
  {
    graphics.rect(random(XRES),random(YRES),random(200),random(200),graphics.rgb(random(255), random(255), random(255)));
  }
  graphics.end();
  delay(5000);

  // Draw some random filled rectangles
  graphics.begin(0);
  for(int i=0;i<20;i++)
  {
    graphics.fillRect(random(XRES),random(YRES),random(200),random(200),graphics.rgb(random(255), random(255), random(255)));
  }
  graphics.end();
  delay(5000);
}
