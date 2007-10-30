#include "alpha-test-context.h"

AlphaTestContext::AlphaTestContext(GLenum func, GLclampf ref)
{
	_func = func;
	_ref = ref;
}

void AlphaTestContext::start(void)
{
	glAlphaFunc(_func, _ref);
	glEnable(GL_ALPHA_TEST);
}

void AlphaTestContext::stop(void)
{
	glDisable(GL_ALPHA_TEST);
}

