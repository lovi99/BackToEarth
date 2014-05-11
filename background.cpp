#include <stdio.h>
#include "yspng.h"
#include "fssimplewindow.h"
#include "background.h"

void Background::Draw(int stage)
{

  
	YsRawPngDecoder png;
	if (stage==0)
	{
		if(YSOK==png.Decode("stage0.png"))
		{
			FsOpenWindow(16,16,png.wid,png.hei,1);
        	png.Flip();
		}
		else
		{
        printf("Read Error!\n");
		return;
		}
	}
	else if (stage==1)
	{
    if(YSOK==png.Decode("stage1.png"))
    {
		FsOpenWindow(16,16,png.wid,png.hei,1);
        	png.Flip();
    }
    else
    {
        printf("Read Error!\n");
		return;
    }
	}
	else if(stage==2)
	{
		 if(YSOK==png.Decode("stage2.png"))
		{
		FsOpenWindow(16,16,png.wid,png.hei,1);
        	png.Flip();
		}
		else
		{
        printf("Read Error!\n");
		return;
		}
	}
	else if(stage==3)
	{
		 if(YSOK==png.Decode("stage3.png"))
    {
		FsOpenWindow(16,16,png.wid,png.hei,1);
        	png.Flip();
    }
    else
    {
        printf("Read Error!\n");
		return;
	}
	}

	key=FSKEY_NULL;
    while(FSKEY_ESC!=key)
    {
        FsPollDevice();
        key=FsInkey();
        glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
		int winWid,winHei;
        FsGetWindowSize(winWid,winHei);
        glRasterPos2d(0.0,(double)(winHei-1));
        glDrawPixels(png.wid,png.hei,GL_RGBA,GL_UNSIGNED_BYTE,png.rgba);
		
		

        FsSwapBuffers();
        FsSleep(50);
    }
    return;
	
	
  
}
int main(void)
{
	Background background;
	background.Draw(0);
}

