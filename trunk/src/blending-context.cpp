#include "blending-context.h"

BlendingContext::BlendingContext(GLenum srcFactor, GLenum destFactor)
{
	_srcFactor = srcFactor;
	_destFactor = destFactor;
}

void BlendingContext::start(void)
{
	glBlendFunc(_srcFactor, _destFactor);
	glEnable(GL_BLEND);
}

void BlendingContext::stop(void)
{
	glDisable(GL_BLEND);
}

