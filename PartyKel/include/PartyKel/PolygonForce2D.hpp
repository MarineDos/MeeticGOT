
#pragma once


#include "PartyKel/Force2D.hpp"
#include "PartyKel/Polygon2D.h"
#include "PartyKel/LeapfrogSolver2D.hpp"
#include <PartyKel/glm.hpp>
#include <vector>

namespace PartyKel
{

class PolygonForce2D : public Force2D
{
	const Polygon2D& m_Polygon; // Polygon repoussant les particules 
	float m_fElasticity; // Controller le rebondissement des particules 
	const LeapfrogSolver2D& m_Solver;
	float m_fDt;

public:
	PolygonForce2D(const Polygon2D& polygon, float elasticity, const LeapfrogSolver2D& solver);
	void setDt(float dt);

	virtual void apply(ParticleManager2D& pm);

}; // class PolygonForce2D

} // namespace PartyKel
