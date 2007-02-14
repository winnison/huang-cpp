#include "defines.h"
#include "GifFrame.h"
#include <vector>

class CGif
{
	int repeat;
	CSize size;
	std::vector<CGifFrame*> frames;
public:
	CGif();
	~CGif();

	bool AddFrame(CGifFrame* frame);
	int GetFrameCount();
	CGifFrame* GetFrame(int index = 0);
	void SetRepeat(int repeat);
	int GetRepeat();
	CSize GetSize();
};