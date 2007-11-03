#ifndef ELEMENT_H
#define ELEMENT_H

#include "transformation.h"
#include "context.h"
#include <string>
#include <vector>

using namespace std;

/**
 * Elément
 */
class Element
{

public:

	Element(void);

	void animate(int timerInterval);

	void render(void);

	void addTransformation(Transformation* transformation);

	void addContext(Context* context);

	inline void setVisible(bool visible) { _visible = visible; }
	inline bool isVisible(void) { return _visible; }

protected:

	virtual void _animate(int timerInterval);

	virtual void _preRender(void);

	virtual void _render(void) = 0;

	virtual void _postRender(void);

private:

	void _startContext(void);

	void _stopContext(void);

	vector<Transformation*> _transformations;

	vector<Context*> _contexts;

	bool _visible;

};

#endif

