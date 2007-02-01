#include "GifFont.h"


UINT CGifFont::MotionExtraSize()
{
	return 0;
}

UINT CGifFont::EdgeExtraSize()
{
	return 2;
}

UINT CGifFont::ShadowExtraSize()
{
	return m_ShadowDis;
}
