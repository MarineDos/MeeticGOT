
#include "PartyKel/GraphHookForce2D.hpp"
#include <algorithm> 
#include <PartyKel/glm.hpp>

namespace PartyKel
{
	GraphHookForce2D::GraphHookForce2D(float K, float L)
	: m_fK(K), m_fL(L), m_pGraph(NULL)
	{};

	void GraphHookForce2D::apply(ParticleManager2D& pm)
	{
		glm::vec2 force;

		if(m_pGraph == NULL)
		{
			return;
		}

		//Pour chaque particule
		for(const auto& pair: *m_pGraph) 
		{
			glm::vec2 P1 = pm.getParticlePosition(pair.first);
			glm::vec2 P2 = pm.getParticlePosition(pair.second);

			force = m_fK * (1 - (m_fL/(std::max(glm::distance(P1, P2), 0.001f)))) * (P2-P1);
			pm.addForce(pair.first, force);
			pm.addForce(pair.second, -force);
		}
	}

	void GraphHookForce2D::setGraph(const ParticleGraph* pGraph)
	{
		m_pGraph = pGraph;
	}
}