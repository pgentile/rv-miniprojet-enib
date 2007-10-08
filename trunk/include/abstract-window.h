#ifndef ABSTRACT_WINDOW_H
#define ABSTRACT_WINDOW_H

class AbstractWindow {

	public: 

		AbstractWindow(void);

		virtual ~AbstractWindow(void);

		void setPosition(int x, int y);

		void setSize(int width, int height);

		void setTitle(const char * title);

		void init(void);

		void loop(void);

	protected:

		virtual void _handleKey(unsigned char key, int x, int y);

		virtual void _handleSpecialKey(int key, int x, int y);

	private:


		struct {
			int x, y;
		} _position;

		struct {
			int width, height;
		} _size;

		const char * _title;

};

#endif

