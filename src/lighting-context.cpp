#include "lighting-context.h"

LightingContext::LightingContext(void)
{
}

LightingContext::LightingContext(int number, GLenum* lights)
{
	for (int i = 0; i < number; i++) {
		_lights.push_back(lights[i]);
	}
}

void LightingContext::start(void)
{
	glEnable(GL_LIGHTING);
	if (_lights.size() > 0) {
		for (vector<GLenum>::iterator i = _lights.begin(); i != _lights.end(); ++i) {
			glEnable(*i);
		}
	}
}

void LightingContext::stop(void)
{
	if (_lights.size() > 0) {
		for (vector<GLenum>::iterator i = _lights.begin(); i != _lights.end(); ++i) {
			glDisable(*i);
		}
	}
	glDisable(GL_LIGHTING);
}

