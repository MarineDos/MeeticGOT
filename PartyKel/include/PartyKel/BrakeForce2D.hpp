
#pragma once

#include "PartyKel/Force2D.hpp"

namespace PartyKel
{
	class ParticleManager2D;

	class BrakeForce2D : public Force2D
	{
	public:
		BrakeForce2D(float v, float dt);
		virtual void apply(ParticleManager2D& pm);

		void setDt(float dt);
	private:
		float m_fV;
		float m_fDt;

	}; // class
}// namespace
