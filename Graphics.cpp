#pragma once
#include <stdlib.h>
#include "Graphics.h"
#include "Font.h"

Graphics::Graphics(int w, int h)
  :xres(w), 
  yres(h)
{
  font = 0;
  cursorX = cursorY = cursorBaseX = 0;
  frontColor = 0xffff;
  backColor = 0;
}

void Graphics::setTextColor(int front, int back)
{
  // ;-1 = transparent back;
  frontColor = front;
  backColor = back;
}

/***********/
/* control */
/***********/

void Graphics::init()
{
  frame = (char**)malloc(yres * sizeof(char*));
  backbuffer = (char**)malloc(yres * sizeof(char*));
  for(int y = 0; y < yres; y++)
  {
    frame[y] = (char*)malloc(xres);
    backbuffer[y] = (char*)malloc(xres);
  }
}

void Graphics::begin(int clear)
{
  if(clear > -1)
    for(int y = 0; y < yres; y++)
      for(int x = 0; x < xres; x++)
        dotFast(x, y, clear);
}

void Graphics::end()
{
  char **b = backbuffer;
  backbuffer = frame;
  frame = b;    
}

/********/
/* text */
/********/

void Graphics::setFont(Font &font)
{
  this->font = &font;
}

void Graphics::setCursor(int x, int y)
{
  cursorX = cursorBaseX = x;  
  cursorY = y;  
}

void Graphics::print(const char *str)
{
  if(!font) return;
  while(*str)
  {
    if(*str >= 32 && *str < 128)
      font->drawChar(*this, cursorX, cursorY, *str, frontColor, backColor);
    cursorX += font->xres;
    if(cursorX + font->xres > xres || *str == '\n')
    {
      cursorX = cursorBaseX;
      cursorY += font->yres;        
    }
    str++;
  }
}

void Graphics::print(int number, int base, int minCharacters)
{
  bool sign = number < 0;
  if(sign) number = -number;
  const char baseChars[] = "0123456789ABCDEF";
  char temp[33];
  temp[32] = 0;
  int i = 31;
  do
  {
    temp[i--] = baseChars[number % base];
    number /= base;
  }while(number > 0);
  if(sign)
    temp[i--] = '-';
  for(;i > 31 - minCharacters; i--)
    temp[i] = ' ';
  print(&temp[i + 1]);
}

/********/
/* line */
/********/

void Graphics::line(int x1, int y1, int x2, int y2, unsigned int color)
{
  int x, y, xe, ye;
  int dx = x2 - x1;
  int dy = y2 - y1;
  int dx1 = labs(dx);
  int dy1 = labs(dy);
  int px = 2 * dy1 - dx1;
  int py = 2 * dx1 - dy1;
  if(dy1 <= dx1)
  {
    if(dx >= 0)
    {
      x = x1;
      y = y1;
      xe = x2;
    }
    else
    {
      x = x2;
      y = y2;
      xe = x1;
    }
    dot(x, y, color);
    for(int i = 0; x < xe; i++)
    {
      x = x + 1;
      if(px < 0)
      {
        px = px + 2 * dy1;
      }
      else
      {
        if((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
        {
          y = y + 1;
        }
        else
        {
          y = y - 1;
        }
        px = px + 2 *(dy1 - dx1);
      }
      dot(x, y, color);
    }
  }
  else
  {
    if(dy >= 0)
    {
      x = x1;
      y = y1;
      ye = y2;
    }
    else
    {
      x = x2;
      y = y2;
      ye = y1;
    }
    dot(x, y, color);
    for(int i = 0; y < ye; i++)
    {
      y = y + 1;
      if(py <= 0)
      {
        py = py + 2 * dx1;
      }
      else
      {
        if((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
        {
          x = x + 1;
        }
        else
        {
          x = x - 1;
        }
        py = py + 2 * (dx1 - dy1);
      }
      dot(x, y, color);
    }
  }
}

/************/
/* triangle */
/************/

void Graphics::triangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned int color)
{
  line(x1, y1, x2, y2, color);
  line(x2, y2, x3, y3, color);
  line(x3, y3, x1, y1, color);
}

/****************/
/* fillTriangle */
/****************/

void Graphics::fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned int color)
{
  line(x1, y1, x2, y2, color);
  line(x2, y2, x3, y3, color);
  line(x3, y3, x1, y1, color);
}

/********/
/* rect */
/********/

void Graphics::rect(int x, int y, int w, int h, unsigned int color)
{
  line(x, y, x + w, y, color);
  line(x + w, y, x + w, y + h, color);
  line(x + w, y + h, x, y + h, color);
  line(x, y + h, x, y, color);
}

/***********/
/* fillRec */
/***********/

void Graphics::fillRect(int x, int y, int w, int h, unsigned int color)
{
  if(x < 0)
  {
    w += x;
    x = 0;
  }
  if(y < 0)
  {
    h += y;
    y = 0;
  }
  if(x + w > xres)
    w = xres - x;
  if(y + h > yres)
    h = yres - y;
  for(int j = y; j < y + h; j++)
    for(int i = x; i < x + w; i++)
      dotFast(i, j, color);
}
