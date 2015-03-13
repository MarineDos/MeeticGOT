
#pragma once

#include <PartyKel/glm.hpp>
#include "PartyKel/renderer/Renderer2D.hpp"
#include <vector>

namespace PartyKel
{

class Polygon2D
{
	std::vector<glm::vec2> m_pointArray;
	glm::vec3 m_color;
	bool m_bIsInner;

public:
	Polygon2D(std::vector<glm::vec2> _pointArray, glm::vec3 _color, bool _bIsInner);

	static Polygon2D buildBox(glm::vec3 color, glm::vec2 position, float width, float height, bool isInner = false);
	static Polygon2D buildCircle(glm::vec3 color, glm::vec2 center, float radius, size_t discFactor, bool isInner = false);
	void draw(Renderer2D& renderer, float lineWidth = 1.f) const;

	int getSize() const { return m_pointArray.size(); };

	glm::vec2 getPoint(int index) const { return m_pointArray[index]; };

}; // class Polygon2D

} // namespace PartyKel
