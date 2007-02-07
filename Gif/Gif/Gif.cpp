#include "Gif.h"

CGif::CGif()
:
repeate(0),
size(0,0),
frames()
{
}
CGif::~CGif()
{
	for (int i=frames.size()-1; i>=0; i--)
	{
		delete frames[i];
	}
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
int CGif::GetRepeate()
{
	return repeate;
}
CSize CGif::GetSize()
{
	return size;
}
