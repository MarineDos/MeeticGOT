
#include "PartyKel/Polygon2D.h"
#include <math.h>

#define PI 3.14159265

namespace PartyKel
{

	Polygon2D::Polygon2D(std::vector<glm::vec2> _pointArray, glm::vec3 _color, bool _bIsInner)
	: m_pointArray(_pointArray)
	, m_color(_color)
	, m_bIsInner(_bIsInner)
	{}

	Polygon2D Polygon2D::buildBox(glm::vec3 color, glm::vec2 position, float width, float height, bool isInner)
	{
		glm::vec2 pointBottomLeft = position;
		glm::vec2 pointBottomRight = glm::vec2(position.x + width, position.y);
		glm::vec2 pointTopRight = glm::vec2(position.x + width, position.y + height);
		glm::vec2 pointTopLeft = glm::vec2(position.x, position.y + height);

		std::vector<glm::vec2> _pointArray;
		_pointArray.push_back(pointTopLeft);
		_pointArray.push_back(pointTopRight);
		_pointArray.push_back(pointBottomRight);
		_pointArray.push_back(pointBottomLeft);

		return Polygon2D(_pointArray, color, isInner);
	}

	Polygon2D Polygon2D::buildCircle(glm::vec3 color, glm::vec2 center, float radius, size_t discFactor, bool isInner)
	{
		std::vector<glm::vec2> _pointArray;

		for(int i = 0; i < discFactor; ++i)
		{
			float x = radius * cos(i * ((2 * PI) / discFactor));
			float y = radius * sin(i * ((2 * PI) / discFactor));
			_pointArray.push_back(glm::vec2(x,y));
		}


		return Polygon2D(_pointArray, color, isInner);
	}

	void Polygon2D::draw(Renderer2D& renderer, float lineWidth) const
	{
		renderer.drawPolygon(m_pointArray.size(), m_pointArray.data(), m_color, lineWidth);
	}
}
