# vdu-bitluni

This is a stripped-down program for generating composite video on the ESP32 based on bitluni's "Space Shooter" game. It was the starting point for the vdu project, but is generally useful when working with bitluni's composite video code for the ESP32.

Basically, I took all of the code I didn't want out of bitluni's game to leave something that allows you to draw text, dots, lines, filled and unfilled triangles, and filled and unfilled rectangles. I also added some comments and moved a few things around to help with readabiliy. The process of doing this was very helpful in helping me to understand his code. All the good stuff is still bitluni's, of couse.

As with the bitluni original, the composite video output is on pin 25. Yhere is no audio.

### Control
- graphics.init
- graphics.begin
- graphics.end

### Text
- graphics.setTextColor
- graphics.setFont
- graphics.setCursor
- graphics.print

### Graphic
- graphics.dot(int x, int y, int color) // there are other dot related functions.
- graphics.line(int x1, int y1, int x2, int y2, unsigned int color)
- graphics.triangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned int color)
- graphics.FillTriangle(int x1, int y1, int x2, int y2, int x3, int y3, unsigned int color)
- graphics.rect(int x, int y, int w, int h, unsigned int color)
- graphics.fillRect(int x, int y, int w, int h, unsigned int color)

### Colour
- graphics.rgb
- graphics.rgba

## Notes

* SimplePALOutpit.h *
The composite video over the ESP32's DAC stuff is all very clever and explained in his YouTube videos. Basically, it turns the frame in to cideo signals.

* Graphics.cpp / Graphics.h *
There is a "backbuffer" where all the latest graphics are placed so that a new frame is not part-rendered before it is ready (this is called double buffering).
The backbuffer is copied to "frame" when it is ready tp be rendered by SimplePALOutpit.h.
"Graphics.begin" (optionally) clears the buffer.
"Graphics.end" copies the buffer to the frame.
The "Graphics.dot" functions are used when rasterising a line, rectangle etc. "Graphics.dotFast" has no frame boundary check.
The "Graphics.line" function graws a line between two points. I base all of my polygons on this. bitluni's code is a little different.

* RGB2YUV.h *
This is a big lookup table used in the conversion of RGB to the YUV colour model used in composite video.
