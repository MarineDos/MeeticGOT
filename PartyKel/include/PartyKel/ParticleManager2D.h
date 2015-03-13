
#pragma once

#include <PartyKel/renderer/Renderer2D.hpp>
#include <PartyKel/glm.hpp>
#include <vector>

namespace PartyKel
{

	typedef std::vector<std::pair<unsigned int, unsigned int>> ParticleGraph;

	class ParticleManager2D
	{
	protected:
		std::vector<glm::vec2> 	m_PositionArray;
		std::vector<glm::vec2>	m_VelocityArray;
		std::vector<float>		m_MassArray;
		std::vector<glm::vec2>	m_ForceArray;
		std::vector<glm::vec3>	m_ColorArray;

	public:
		void clear();

		glm::vec2 getParticleForce(int index);
		glm::vec2 getParticlePosition(int index);
		glm::vec2 getParticleVelocity(int index);
		float getParticleMass(int index);

		int getNbParticle(){ return m_PositionArray.size(); };

		int addParticle(glm::vec2 position, glm::vec2 velocity, float mass, glm::vec2 force, glm::vec3 color);

		void addRandomParticles(unsigned int count);

		void drawParticles(Renderer2D& renderer);

		void addForce(glm::vec2 force);

		void addForce(int index, glm::vec2 force);

		void updateVelocity(float dt);

		void updatePosition(float dt);

		void removeForce();

		void drawParticleGraph(ParticleGraph& graph, Renderer2D& renderer);
	}; // class

} // namespace
