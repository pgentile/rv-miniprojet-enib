#include "textured-rectangle.h"
#include "png-loader.h"

TexturedRectangle::TexturedRectangle(string name,string texturePath, Size size)
{
	_name = name;
	_texture = PngLoader::load(texturePath);
	_size = size;
}

TexturedRectangle::TexturedRectangle(string name, string texturePath, GLfloat width, GLfloat height)
{
	_name = name;
	_texture = PngLoader::load(texturePath);
	_size = Size(width, height);
}

void TexturedRectangle::_preRender(void)
{  
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _texture);
}

string TexturedRectangle::getName()
{
	return _name;
}

void TexturedRectangle::_render(void)
{
	glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glTexCoord2f(0.0, 1.0); glVertex2f(-_size.width() / 2.0, _size.height() / 2.0);
		glTexCoord2f(1.0, 1.0); glVertex2f(_size.width() / 2.0, _size.height() / 2.0);
		glTexCoord2f(1.0, 0.0); glVertex2f(_size.width() / 2.0, -_size.height() / 2.0);
		glTexCoord2f(0.0, 0.0); glVertex2f(-_size.width() / 2.0, -_size.height() / 2.0);
	glEnd();
}

void TexturedRectangle::_postRender(void)
{
	glDisable(GL_TEXTURE_2D);
}

void TexturedRectangle::setTexture(string texturePath)
{
	_texture = PngLoader::load(texturePath);
}
	
