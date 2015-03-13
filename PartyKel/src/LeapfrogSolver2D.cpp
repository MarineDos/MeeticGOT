
#include <PartyKel/LeapfrogSolver2D.hpp>

namespace PartyKel
{
	
	void LeapfrogSolver2D::solve(ParticleManager2D& pm, float dt)
	{
		pm.updateVelocity(dt);
		pm.updatePosition(dt);
		pm.removeForce();
	}

	ParticleState2D LeapfrogSolver2D::getNextState(uint32_t particleIdx, ParticleManager2D& pm, float dt) const
	{
		ParticleState2D ps2D;

		glm::vec2 position = pm.getParticlePosition(particleIdx);
		glm::vec2 velocity = pm.getParticleVelocity(particleIdx);
		float mass = pm.getParticleSexAppeal(particleIdx);
		glm::vec2 force = pm.getParticleForce(particleIdx);

		//Update velocity
		ps2D.velocity = velocity + (dt * (force / mass));
		//Update position 
		ps2D.position = position + (dt * ps2D.velocity);

		return ps2D;
	}

}