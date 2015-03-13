
#include <iostream>
#include "PartyKel/HookForce2D.hpp"
#include "PartyKel/ParticleManager2D.hpp"
#include <algorithm> 
#include <PartyKel/glm.hpp>

namespace PartyKel
{
	HookForce2D::HookForce2D(float K, float L)
		: m_fK(K), m_fL(L)
	{};

	void HookForce2D::apply(ParticleManager2D& pm)
	{
		glm::vec2 force;

		int n = pm.getNbParticle();

		//Pour chaque particule
		for (int i = 0; i < n; ++i)
		{
			glm::vec2 P1 = pm.getParticlePosition(i);
			for (int j = i + 1; j < n; ++j)
			{
				glm::vec2 P2 = pm.getParticlePosition(j);

				if (pm.getParticleSex(i) != pm.getParticleSex(j))
				{
					float distance = glm::distance(P1, P2);
					if (distance < 0.5)
					{
						if (pm.getParticleIsInCouple(i) && pm.getParticleIsInCouple(j) && pm.getParticleLover(i) == j && pm.getParticleLover(j) == i)
						{
							force = m_fK * (1 - (m_fL / (std::max(glm::distance(P1, P2), 0.001f)))) * (P2 - P1);
							pm.addForce(i, -force);
							pm.addForce(j, force);
						}
					}
				}
			}
		}



	}
}