
#pragma once

#include "PartyKel/ParticleManager2D.hpp"
#include "PartyKel/Force2D.hpp"

namespace PartyKel
{

	class GraphHookForce2D : public Force2D
	{
	public:
		GraphHookForce2D(float K, float L);
		
		virtual void apply(ParticleManager2D& pm);
		void setGraph(const ParticleGraph* pGraph);

	private:
		float m_fK;
		float m_fL;
		const ParticleGraph * m_pGraph;

	}; // class
}// namespace
