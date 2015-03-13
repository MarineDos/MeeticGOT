
#pragma once

#include "PartyKel/Force2D.hpp"
#include <PartyKel/glm.hpp>
#include <PartyKel/ParticleManager2D.hpp>

namespace PartyKel
{

class ConstantForce2D : public Force2D
{
	glm::vec2 m_Force;
public:

	ConstantForce2D(glm::vec2 i_Force);
	virtual ~ConstantForce2D() {};

	virtual void apply(ParticleManager2D& pm);
}; // class

} // namespace