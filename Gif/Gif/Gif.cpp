#include "Gif.h"

CGif::CGif()
:
repeat(0),
size(0,0),
frames()
{
}
CGif::~CGif()
{
	for (int i=frames.size()-1; i>=0; i--)
	{
		try
		{
			delete frames[i];
		}
		catch (...)
		{
		}
	}
}
bool CGif::AddFrame(CGifFrame* frame)
{
	if (size.cy==0 || size.cx == 0)
	{
		size.cx = frame->w;
		size.cy = frame->h;
	}
	else if (size.cx != frame->w || size.cy != frame->h)
	{
		return false;
	}
	frames.push_back(frame);
	return true;
}

int CGif::GetFrameCount()
{
	return frames.size();
}
CGifFrame* CGif::GetFrame(int index)
{
	if (index<0||index>=frames.size())
	{
		return NULL;
	}
	return frames[index];
}
void CGif::SetRepeat(int repeat)
{
	this->repeat = repeat;
}
int CGif::GetRepeat()
{
	return repeat;
}
CSize CGif::GetSize()
{
	return size;
}
