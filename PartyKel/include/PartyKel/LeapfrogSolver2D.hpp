
#pragma once 

#include <PartyKel/ParticleManager2D.hpp>

namespace PartyKel
{
	struct ParticleState2D
	{
		glm::vec2 position;
		glm::vec2 velocity;
	};

	class LeapfrogSolver2D
	{

	public:
		void solve(ParticleManager2D& pm, float dt);

		ParticleState2D getNextState(uint32_t particleIdx, ParticleManager2D& pm, float dt) const;

	}; // class

} // namespace
