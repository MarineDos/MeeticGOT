
#pragma once

#include "PartyKel/Force2D.hpp"

namespace PartyKel
{
	class ParticleManager2D;

	class RepulseForce2D : public Force2D
	{
	public:
		RepulseForce2D(float K, float L);
		virtual void apply(ParticleManager2D& pm);
	private:
		float m_fK;
		float m_fL;

	}; // class
}// namespace
