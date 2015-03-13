
#pragma once

#include "PartyKel/Force2D.hpp"
#include "PartyKel/ParticleManager2D.hpp"

namespace PartyKel
{

	class GraphBrakeForce2D : public Force2D
	{
	public:
		GraphBrakeForce2D(float v, float dt);

		virtual void apply(ParticleManager2D& pm);
		void setDt(float dt);
		void setGraph(const ParticleGraph* pGraph);

	private:
		float m_fV;
		float m_fDt;
		const ParticleGraph * m_pGraph;

	}; // class
}// namespace
