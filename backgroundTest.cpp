#include <stdio.h>
#include "yspng.h"
#include "fssimplewindow.h"
#include "background.h"

int main(void)
{
	
	int winWid,winHei;
	Background background;
	FsOpenWindow(16,16,800,600,1);
	background.Draw(0);
	
	return 0;
}