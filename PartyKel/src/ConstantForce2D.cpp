
#include <PartyKel/ConstantForce2D.hpp>

namespace PartyKel
{

ConstantForce2D::ConstantForce2D(glm::vec2 i_Force)
: m_Force(i_Force)
{}

void ConstantForce2D::apply(ParticleManager2D& pm)
{
	pm.addForce(m_Force);
}

}