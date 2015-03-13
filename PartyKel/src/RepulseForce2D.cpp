
#include <iostream>
#include "PartyKel/RepulseForce2D.hpp"
#include "PartyKel/ParticleManager2D.hpp"
#include <algorithm> 
#include <PartyKel/glm.hpp>

namespace PartyKel
{
	RepulseForce2D::RepulseForce2D(float K, float L)
		: m_fK(K), m_fL(L)
	{};

	void RepulseForce2D::apply(ParticleManager2D& pm)
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
					float distance = glm::distance(pm.getParticlePosition(i), pm.getParticlePosition(j));

					if (distance < 0.5)
					{
						if (pm.getParticleEx(i) == j || pm.getParticleEx(j) == i)
						{
							// Ils ne s'aiment plus
							force = m_fK * (1 - (m_fL / (std::max(glm::distance(P1, P2), 0.001f)))) * (P2 - P1);
							if (!pm.getParticleIsInCouple(i))
							{
								pm.addForce(i, force);
							}
							if (!pm.getParticleIsInCouple(j))
							{
								pm.addForce(j, -force);
							}
						}
						if (pm.getParticleIsInCouple(i) == true && pm.getParticleIsInCouple(j) == true)
						{
							// Ils sont tout les deux en couples
							force = m_fK * (1 - (m_fL / (std::max(glm::distance(P1, P2), 0.001f)))) * (P2 - P1);
							if (pm.getParticleLover(i) != j && pm.getParticleLover(j) != i)
							{
								pm.addForce(j, -force);
								pm.addForce(i, force);
							}

						}
					}
				}
			}
		}



	}
}