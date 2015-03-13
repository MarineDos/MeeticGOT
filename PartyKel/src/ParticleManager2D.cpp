
#include "PartyKel/ParticleManager2D.hpp"

#include <iostream>

namespace PartyKel
{
	void ParticleManager2D::clear()
	{
		m_PositionArray.clear();
		m_SexAppealArray.clear();
		m_ColorArray.clear();
		m_VelocityArray.clear();
		m_ForceArray.clear();
		m_NameArray.clear();
		m_HeightArray.clear();
		m_SexArray.clear();
		m_FidelityArray.clear();
		m_IsInCoupleArray.clear();
		m_LoverIndexArray.clear();
		m_ExIndexArray.clear();

	}

	glm::vec2 ParticleManager2D::getParticleForce(int index)
	{
		return m_ForceArray[index];
	}

	glm::vec2 ParticleManager2D::getParticlePosition(int index)
	{
		return m_PositionArray[index];
	}

	glm::vec2 ParticleManager2D::getParticleVelocity(int index)
	{
		return m_VelocityArray[index];
	}

	float ParticleManager2D::getParticleSexAppeal(int index)
	{
		return m_SexAppealArray[index];
	}

	float ParticleManager2D::getParticleHeight(int index)
	{
		return m_HeightArray[index];
	}

	int ParticleManager2D::getParticleSex(int index)
	{
		return m_SexArray[index];
	}

	char* ParticleManager2D::getParticleName(int index)
	{
		return m_NameArray[index];
	}

	bool ParticleManager2D::getParticleIsInCouple(int index)
	{
		return m_IsInCoupleArray[index];
	}

	int ParticleManager2D::getParticleLover(int index)
	{
		return m_LoverIndexArray[index];
	}

	int ParticleManager2D::getParticleFidelity(int index)
	{
		return m_FidelityArray[index];
	}

	int ParticleManager2D::getParticleEx(int index)
	{
		return m_ExIndexArray[index];
	}

	int ParticleManager2D::addParticle(glm::vec2 position, glm::vec2 velocity, float sexAppeal, glm::vec2 force, glm::vec3 color, float height, char* name, int sex, bool isIncouple, int loverIndex, int fidelity, int ex)
	{
		m_PositionArray.push_back(position);
		m_VelocityArray.push_back(velocity);
		m_SexAppealArray.push_back(sexAppeal);
		m_ForceArray.push_back(force);
		m_ColorArray.push_back(color);
		m_HeightArray.push_back(height);
		m_NameArray.push_back(name);
		m_SexArray.push_back(sex);
		m_IsInCoupleArray.push_back(isIncouple);
		m_LoverIndexArray.push_back(loverIndex);
		m_FidelityArray.push_back(fidelity);
		m_ExIndexArray.push_back(ex);

		return m_PositionArray.size() - 1;
	}


	void ParticleManager2D::addGOTParticles(){
		float positionX = glm::linearRand(-0.90f, 0.90f);
		float positionY = glm::linearRand(-0.90f, 0.90f);
		glm::vec2 position(positionX, positionY);
		float sexAppeal = 4;
		float sexAppealFactor = sexAppeal / 10;
		float height = 5.5f;
		glm::vec2 velocity(glm::linearRand(-0.2f, 0.02f), glm::linearRand(-0.2f, 0.2f));
		glm::vec2 force(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		glm::vec3 color(1, 0.6 * sexAppealFactor, 0.8 * sexAppealFactor);
		addParticle(position, velocity, sexAppeal, force, color, height, "Catelyn", 0, false, 0, 100, 100);


		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 6.0;
		sexAppealFactor = sexAppeal / 10;
		height = 5.7f;
		velocity = glm::vec2(glm::linearRand(-0.2f, 0.2f), glm::linearRand(-0.2f, 0.2f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		force = glm::vec2(0, 0);
		color = glm::vec3(1, 0.6 * sexAppealFactor, 0.8 * sexAppealFactor);
		addParticle(position, velocity, sexAppeal, force, color, height, "Sansa", 0, false, 0, 60, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 3.0;
		sexAppealFactor = sexAppeal / 10;
		height = 4.9f;
		velocity = glm::vec2(glm::linearRand(-0.2f, 0.2f), glm::linearRand(-0.2f, 0.2f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		force = glm::vec2(0, 0);
		color = glm::vec3(1, 0.6 * sexAppealFactor, 0.8 * sexAppealFactor);
		addParticle(position, velocity, sexAppeal, force, color, height, "Arya", 0, false, 0, 100, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 5.0;
		sexAppealFactor = sexAppeal / 10;
		height = 5.6f;
		velocity = glm::vec2(glm::linearRand(-0.2f, 0.2f), glm::linearRand(-0.2f, 0.2f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		force = glm::vec2(0, 0);
		color = glm::vec3(1, 0.6 * sexAppealFactor, 0.8 * sexAppealFactor);
		addParticle(position, velocity, sexAppeal, force, color, height, "Cersei", 0, false, 0, 70, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 10;
		sexAppealFactor = sexAppeal / 10;
		height = 5.5f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(1, 0.6 * sexAppealFactor, 0.8 * sexAppealFactor);
		addParticle(position, velocity, sexAppeal, force, color, height, "Margeary", 0, false, 0, 50, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 10;
		sexAppealFactor = sexAppeal / 10;
		height = 5.3f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(1, 0.6 * sexAppealFactor, 0.8 * sexAppealFactor);
		addParticle(position, velocity, sexAppeal, force, color, height, "Daenarys", 0, false, 0, 100, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 2;
		sexAppealFactor = sexAppeal / 10;
		height = 6.3f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(1, 0.6 * sexAppealFactor, 0.8 * sexAppealFactor);
		addParticle(position, velocity, sexAppeal, force, color, height, "Brienne", 0, false, 0, 20, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 5;
		sexAppealFactor = sexAppeal / 10;
		height = 5.11f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Eddard", 1, false, 0, 80, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 8;
		sexAppealFactor = sexAppeal / 10;
		height = 5.1f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Robb", 1, false, 0, 70, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 0.5;
		sexAppealFactor = sexAppeal / 10;
		height = 4.9f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Bran", 1, false, 0, 100, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 7;
		sexAppealFactor = sexAppeal / 10;
		height = 5.9f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Jon", 1, false, 0, 100, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 0.5;
		sexAppealFactor = sexAppeal / 10;
		height = 5.11f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Robert", 1, false, 0, 20, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 4;
		sexAppealFactor = sexAppeal / 10;
		height = 5.6f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Joffrey", 1, false, 0, 100, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 5;
		sexAppealFactor = sexAppeal / 10;
		height = 6.2f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Tywin", 1, false, 0, 50, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 7;
		sexAppealFactor = sexAppeal / 10;
		height = 6.2f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Jaime", 1, false, 0, 70, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 9;
		sexAppealFactor = sexAppeal / 10;
		height = 4.5f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Tyrion", 1, false, 0, 20, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 4;
		sexAppealFactor = sexAppeal / 10;
		height = 6.0f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Stannis", 1, false, 0, 50, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 2;
		sexAppealFactor = sexAppeal / 10;
		height = 5.1f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Loras", 1, false, 0, 90, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 1;
		sexAppealFactor = sexAppeal / 10;
		height = 7.1f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Gregor", 1, false, 0, 100, 100);

		positionX = glm::linearRand(-0.90f, 0.90f);
		positionY = glm::linearRand(-0.90f, 0.90f);
		position = glm::vec2(positionX, positionY);
		sexAppeal = 3;
		sexAppealFactor = sexAppeal / 10;
		height = 5.9f;
		velocity = glm::vec2(glm::linearRand(0.1f, 0.04f), glm::linearRand(0.1f, 0.04f));
		force = glm::vec2(glm::linearRand(-0.05f, 0.05f), glm::linearRand(-0.05f, 0.05f));
		color = glm::vec3(0.2, 0.7 * (1 - sexAppealFactor), 1);
		addParticle(position, velocity, sexAppeal, force, color, height, "Theon", 1, false, 0, 10, 100);

	}

	void ParticleManager2D::drawParticles(Renderer2D& renderer) {
		renderer.drawParticles(m_PositionArray.size(),
			m_PositionArray.data(),
			m_HeightArray.data(),
			m_ColorArray.data(),
			m_SexArray.data());
	}

	void ParticleManager2D::addForce(glm::vec2 force) {
		int n = m_PositionArray.size();
		for (int i = 0; i < n; ++i)
		{
			m_ForceArray[i] += force;
		}
	}

	void ParticleManager2D::addForce(int index, glm::vec2 force) {
		m_ForceArray[index] += force;
	}

	void ParticleManager2D::updateVelocity(float dt)
	{
		int n = m_PositionArray.size();
		for (int i = 0; i < n; ++i)
		{
			m_VelocityArray[i] = m_VelocityArray[i] + (dt * (m_ForceArray[i] / m_SexAppealArray[i]));
		}
	}

	void ParticleManager2D::updatePosition(float dt)
	{
		int n = m_PositionArray.size();
		for (int i = 0; i < n; ++i)
		{
			m_PositionArray[i] = m_PositionArray[i] + (dt * m_VelocityArray[i]);
		}
	}

	void ParticleManager2D::removeForce()
	{
		int n = m_PositionArray.size();
		for (int i = 0; i < n; ++i)
		{
			m_ForceArray[i] = glm::vec2(0, 0);
		}
	}

	void ParticleManager2D::setIsInCouple(int index, bool isInCouple)
	{
		m_IsInCoupleArray[index] = isInCouple;
	}

	void ParticleManager2D::setParticleLover(int index, int indexLover)
	{

		m_LoverIndexArray[index] = indexLover;
	}


	void ParticleManager2D::setParticleEx(int index, int indexEx){
		m_ExIndexArray[index] = indexEx;
	}

	void ParticleManager2D::updateStatus()
	{
		glm::vec2 force;

		int n = getNbParticle();

		//Pour chaque particule
		for (int i = 0; i < n; ++i)
		{
			glm::vec2 V1 = getParticleVelocity(i);
			for (int j = i + 1; j < n; ++j)
			{
				if (getParticleSex(i) != getParticleSex(j))
				{
					float distance = glm::distance(getParticlePosition(i), getParticlePosition(j));

					if (distance < 0.2)
					{
						if (getParticleIsInCouple(i) == false && getParticleIsInCouple(j) == false)
						{
							// Aucun des deux est en couple
							if (!(getParticleEx(i) == j || getParticleEx(j) == i))
							{
								setIsInCouple(i, true);
								setIsInCouple(j, true);
								setParticleLover(i, j);
								setParticleLover(j, i);
								std::cout << getParticleName(i) << " est désormais en couple avec " << getParticleName(j) << std::endl;
							}
						}
						else
						{
							if (getParticleIsInCouple(i) == true && getParticleIsInCouple(j) == false)
							{
								// i est en couple
								// On teste sa fidélité
								int alea = rand() % 100;
								if (alea > getParticleFidelity(i))
								{
									// Rupture !
									setIsInCouple(j, true);
									setParticleLover(j, i);

									int indexOldLover = getParticleLover(i);
									setIsInCouple(indexOldLover, false);
									setParticleLover(i, j);

									setParticleEx(indexOldLover, i);
									setParticleEx(i, indexOldLover);

									std::cout << "RUPTURE par " << getParticleName(i) << std::endl;
									std::cout << getParticleName(indexOldLover) << " est désormais célibataire" << std::endl;
									std::cout << getParticleName(i) << " est désormais en couple avec " << getParticleName(j) << std::endl;
								}
							}
							else
							{
								if (getParticleIsInCouple(i) == false && getParticleIsInCouple(j) == true)
								{
									// j est en couple
									// On teste sa fidélité
									int alea = rand() % 100;
									if (alea > getParticleFidelity(j))
									{
										// Rupture !
										setIsInCouple(i, true);
										setParticleLover(i, j);

										int indexOldLover = getParticleLover(j);
										setIsInCouple(indexOldLover, false);
										setParticleLover(j, i);

										setParticleEx(indexOldLover, j);
										setParticleEx(j, indexOldLover);

										std::cout << "RUPTURE par " << getParticleName(j) << std::endl;
										std::cout << getParticleName(indexOldLover) << " est désormais célibataire" << std::endl;
										std::cout << getParticleName(i) << " est désormais en couple avec " << getParticleName(j) << std::endl;
									}
								}
							}
						}
						
					}
				}
			}
		}

	}
}
