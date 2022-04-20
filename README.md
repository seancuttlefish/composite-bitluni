# vdu-bitluni

This is a stripped-down program for generating composite video on the ESP32 based on bitluni's "Space Shooter" game. It was the starting point for the vdu project, but is generally useful for understanding bitluni's composite video code for the ESP32.

Basically, I took all of the code I didn't want out of bitluni's game to leave something that allows you to draw text, triangles, lines, and filled and unfilled rectangles. I also added some comments and moved a few things around to help with readabiliy. The process of doing this was very helpful in helping me to understand his code. All the good stuff is still bitluni's.

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
- graphics.dot
- graphics.triangle
- graphics.line
- graphics.fillRect
- graphics.rect

### Colour
- graphics.rgb
- graphics.rgba

## Notes

