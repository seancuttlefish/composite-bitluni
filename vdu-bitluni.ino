/*******************************************************************
* Visual Display Unit (VDU)                                        *
* v0.0.1                                                           *
* 19th April 2022                                                  *
* Sean Clark                                                       *
* Interact digital Arts                                            *
* https://www.interactdigitalarts.uk                               *
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
  init();
  graphics.init();
  xTaskCreatePinnedToCore(compositeCore, "c", 1024, NULL, 1, NULL, 0);
}

void loop()
{
  // Draw some text
  graphics.begin(0); // fill the backbuffer with graphics. > -1 will clear the screen.
  graphics.end(); // swap the buffers

  // Draw some random triangles
  graphics.begin(0);
  graphics.end();

  // Draw some random lines
  graphics.begin(0);
  graphics.end();

  // Draw some random rectangles
  graphics.begin(0);
  graphics.end();

  // Draw some random filled rectangles
  graphics.begin(0);
  for(int i=0;i<10;i++)
  {
    graphics.fillRect(random(320),random(240),random(200),random(200),graphics.rgb(random(255), random(255), random(255)));
  }
  graphics.end();
  delay(2000);
}
