#ifndef DRAWTRANSFORM_INCLUDE
#define DRAWTRANSFORM_INCLUDE

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>


// Class that contains Drawable and Transformable without any modification
// to use at specialization of Listaestatica
class DrawTransform : public sf::Drawable, public sf::Transformable
{
public:
	DrawTransform();
	virtual ~DrawTransform();
};

#endif
