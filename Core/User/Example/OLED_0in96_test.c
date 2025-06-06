/*****************************************************************************
* | File        :   OLED_0in96_test.c
* | Author      :   Waveshare team
* | Function    :   OLED_0in96 OLED Module test demo
* | Info        :
*----------------
* | This version:   V2.0
* | Date        :   2020-08-14
* | Info        :
* -----------------------------------------------------------------------------
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "test.h"
#include "../OLED/OLED_0in96.h"

int OLED_0in96_test(void)
{
    printf("0.96inch OLED test demo\n");
	if(System_Init() != 0) {
		return -1;
	}
      
	if(USE_IIC) {
		printf("Only USE_SPI_4W or USE_IIC_SOFT, Please revise DEV_Config.h !!!\r\n");
		return -1;
	}
	
    printf("OLED Init...\r\n");
    OLED_0in96_Init();
    Driver_Delay_ms(500);  
    // 0.Create a new image cache
    UBYTE *BlackImage;
    UWORD Imagesize = ((OLED_0in96_WIDTH%8==0)? (OLED_0in96_WIDTH/8): (OLED_0in96_WIDTH/8+1)) * OLED_0in96_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
            printf("Failed to apply for black memory...\r\n");
            return -1;
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, OLED_0in96_WIDTH, OLED_0in96_HEIGHT, 90, BLACK);  

    printf("Drawing\r\n");
    //1.Select Image
    Paint_SelectImage(BlackImage);
    Driver_Delay_ms(500);
    Paint_Clear(BLACK);
    while(1) {
        
    	/******************************************************************************
    	function:	Display nummber
    	parameter:
    	    Xstart           ：X coordinate
    	    Ystart           : Y coordinate
    	    Nummber          : The number displayed
    	    Font             ：A structure pointer that displays a character size
    			Digit						 : Fractional width
    	    Color_Foreground : Select the foreground color
    	    Color_Background : Select the background color
    	******************************************************************************/
        // Drawing on the image
        printf("Drawing:page 2\r\n");           
        Paint_DrawString_EN(10, 0, "waveshare hello world waveshare hello world waveshare", &Font12, WHITE, BLACK);
        Paint_DrawNum(10, 30, 123.456789, &Font8, 4, WHITE, WHITE);
        Paint_DrawNum(10, 43, 987654, &Font12, 5, WHITE, WHITE);
        // Show image on page2
        OLED_0in96_display(BlackImage);
        Driver_Delay_ms(2000); 
        Paint_Clear(BLACK);     
        
    }
}

