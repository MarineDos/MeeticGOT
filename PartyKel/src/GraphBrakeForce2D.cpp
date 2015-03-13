
#include "PartyKel/GraphBrakeForce2D.hpp"
#include "PartyKel/ParticleManager2D.hpp"
#include <PartyKel/glm.hpp>

namespace PartyKel
{
	GraphBrakeForce2D::GraphBrakeForce2D(float v, float dt)
	: m_fV(v), m_fDt(dt), m_pGraph(NULL)
	{};

	void GraphBrakeForce2D::setDt(float dt)
	{
		m_fDt = dt;
	}

	void GraphBrakeForce2D::apply(ParticleManager2D& pm)
	{
		glm::vec2 force;

		if(m_pGraph == NULL)
		{
			return;
		}
		//Pour chaque particule
		for(const auto& pair: *m_pGraph) 
		{
			glm::vec2 V1 = pm.getParticleVelocity(pair.first);
			glm::vec2 V2 = pm.getParticleVelocity(pair.second);

			force = m_fV * ( (V2 - V1) / m_fDt);
			pm.addForce(pair.first, force);
			pm.addForce(pair.second, -force);
		}
	}

	void GraphBrakeForce2D::setGraph(const ParticleGraph* pGraph)
	{
		m_pGraph = pGraph;
	}
}