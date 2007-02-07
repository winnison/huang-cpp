#include "defines.h"
#include "GifFrame.h"
#include <vector>

class CGif
{
	friend class CGifDecoder;
	CGif();
	int repeate;
	CSize size;
	std::vector<CGifFrame*> frames;
public:
	~CGif();
	int GetFrameCount();
	CGifFrame* GetFrame(int index = 0);
	int GetRepeate();
	CSize GetSize();
};