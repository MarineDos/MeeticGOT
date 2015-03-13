
#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <algorithm>
#include "PartyKel/BrakeForce2D.hpp"
#include "PartyKel/ParticleManager2D.hpp"
#include <PartyKel/glm.hpp>

namespace PartyKel
{
	BrakeForce2D::BrakeForce2D(float v, float dt)
		: m_fV(v), m_fDt(dt)
	{};

	void BrakeForce2D::setDt(float dt)
	{
		m_fDt = dt;
	}

	void BrakeForce2D::apply(ParticleManager2D& pm)
	{
		glm::vec2 force;

		int n = pm.getNbParticle();

		//Pour chaque particule
		for (int i = 0; i < n; ++i)
		{
			glm::vec2 V1 = pm.getParticleVelocity(i);
			for (int j = i + 1; j < n; ++j)
			{
				if (pm.getParticleSex(i) != pm.getParticleSex(j))
				{
					float distance = glm::distance(pm.getParticlePosition(i), pm.getParticlePosition(j));

					if (distance < 0.5)
					{
						if (pm.getParticleIsInCouple(i) && pm.getParticleIsInCouple(j) && pm.getParticleLover(i) == j && pm.getParticleLover(j) == i)
						{
							glm::vec2 V2 = pm.getParticleVelocity(j);

							force = m_fV * ((V2 - V1) / m_fDt);

							pm.addForce(i, force);
							pm.addForce(j, -force);
						}
					}
				}
			}
		}

	}
}