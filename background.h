
#include "yspng.h"

class Background
{
public:
	
	int key;
	YsRawPngDecoder png;
	
	void Draw(int stage);
};
