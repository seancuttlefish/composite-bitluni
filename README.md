# vdu

This is a stripped-down program for generating composite video on the ESP32 based on bitluni's Space Invader game.

Basically, I've taken all of the code I didn't want out of bitluni's software to leave something that simply allows you to draw text, triangles, lines, and filled and unfilled rectangles. I've also added some comments. The process of doing this was very helpful in helping me to understand his code.

As with the original code, the composite video output is on pin 25.

## Functions

- graphics.init
- graphics.begin
- graphics.end

- graphics.setTextColor
- graphics.setFont
- graphics.setCursor
- graphics.print

- graphics.dotFast
- graphics.dot
- graphics.dotMixFaster
- graphics.dotMix
- graphics.dotAdd
- graphics.get

- graphics.triangle
- graphics.line
- graphics.fillRect
- graphics.rect

- graphics.rgb
- graphics.rgba
