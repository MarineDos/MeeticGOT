
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
	std::vector<float>		m_SexAppealArray;
	std::vector<float>		m_HeightArray;
	std::vector<glm::vec2>	m_ForceArray;
	std::vector<glm::vec3>	m_ColorArray;
	std::vector<char*>		m_NameArray;
	std::vector<int>		m_SexArray;
	std::vector<bool>		m_IsInCoupleArray;
	std::vector<int>		m_LoverIndexArray;
	std::vector<int>		m_FidelityArray;
	std::vector<int>		m_ExIndexArray;

public:
	void clear();

	glm::vec2 getParticleForce(int index);
	glm::vec2 getParticlePosition(int index);
	glm::vec2 getParticleVelocity(int index);
	float getParticleSexAppeal(int index);
	float getParticleHeight(int index);
	int getParticleSex(int index);
	char* getParticleName(int index);
	bool getParticleIsInCouple(int index);
	int getParticleLover(int index);
	int getParticleFidelity(int index);
	int getParticleEx(int index);

	int getNbParticle(){ return m_PositionArray.size(); };

	int addParticle(glm::vec2 position, glm::vec2 velocity, float sexAppeal, glm::vec2 force, glm::vec3 color, float height, char* name, int sex, bool isIncouple, int loverIndex, int fidelity, int ex);

	void addGOTParticles();

	void drawParticles(Renderer2D& renderer);

	void addForce(glm::vec2 force);

	void addForce(int index, glm::vec2 force);

	void updateVelocity(float dt);

	void updatePosition(float dt);

	void setIsInCouple(int index, bool isInCouple);
	void setParticleLover(int index, int indexLover);
	void setParticleEx(int index, int indexEx);
	
	void removeForce();

	void updateStatus();
}; // class

} // namespace
