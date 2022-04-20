# vdu

This is a stripped-down program for generating composite video on the ESP32 based on bitluni's Space Invader game. It is the starting point for the vdu project.

Basically, I've taken all of the code I didn't want out of bitluni's game to leave something that simply allows you to draw text, triangles, lines, and filled and unfilled rectangles. I've also added some comments and moved a few things around to help with readabiliy. The process of doing this was very helpful in helping me to understand his code.

As with the original code, the composite video output is on pin 25. I've removed the audio output for now.

## Functions

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
- graphics.dot
- graphics.triangle
- graphics.line
- graphics.fillRect
- graphics.rect

### Colour
- graphics.rgb
- graphics.rgba
