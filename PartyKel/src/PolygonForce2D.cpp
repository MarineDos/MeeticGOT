
#include "PartyKel/PolygonForce2D.hpp"
#include <PartyKel/LeapfrogSolver2D.hpp>

#include <iostream>
#include <cstdlib>

namespace PartyKel
{
	bool intersect(const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& A, const glm::vec2& B, glm::vec2* intersection, glm::vec2* normal) 
	{
	    /*float a1 = (p2.y - p1.y) / (p2.x - p1.x);
	    float b1 = p2.y - a1 * p2.x;

	    float a2 = (B.y - A.y) / (B.x - A.x);
	    float b2 = B.y - a2 * B.x;

	    if( a1 == a2 )
	    {
	        //Parallèle
	        return false;
	    }

	    //y = ax + b
	    float x_intersection = (b2 - b1)/(a1 - a2);
	    float y_intersection = (a2 * x_intersection + b2);

	    if(x_intersection < A.x || x_intersection > B.x)
	    {
	        //Sur la droite mais pas sur le segment 
	        return false;
	    }

	    intersection->x = x_intersection;
	    intersection->y = y_intersection;

	    normal->x = -a2;
	    normal->y = 1;*/

	    glm::vec2 P1P2 = p2 - p1;
	    glm::vec2 AB = B - A;
	    glm::vec2 AP1 = p1 - A;
	    glm::vec2 NAB = glm::vec2(AB.y, -AB.x);
	    float diviseur = glm::dot(NAB, P1P2);
	    if(diviseur != 0)
	    {
	    	float t = -( glm::dot(NAB, AP1) / glm::dot(NAB, P1P2));
	    	if( t > 0 && t < 1 )
	    	{
	    		glm::vec2 possiblePoint = p1 + t * P1P2;
	    		glm::vec2 APt = possiblePoint - A;
	    		float test = glm::dot(APt, AB);
	    		if(test > 0 && test < glm::dot(AB, AB))
	    		{
	    			*intersection = possiblePoint;
	    			*normal = glm::normalize(NAB);
	    			return true;
	    		}
	    	}
	    }

	    return false;
	}


	PolygonForce2D::PolygonForce2D(const Polygon2D& polygon, float elasticity, const LeapfrogSolver2D& solver)
	: m_Polygon(polygon)
	, m_fElasticity(elasticity)
	, m_Solver(solver)
	, m_fDt(0)
	{}

	void PolygonForce2D::setDt(float dt)
	{
		m_fDt = dt;
	}

	void PolygonForce2D::apply(ParticleManager2D& pm)
	{
		glm::vec2 force;
		int n = pm.getNbParticle();
		int m = m_Polygon.getSize();

		//Pour chaque particule
		for(int i = 0; i < n; ++i)
		{
			//Pour chaque arrête du polygon
			for(int j = 0; j < m; ++j)
			{
				glm::vec2 intersection;
				glm::vec2 normal;
				ParticleState2D ps2D = m_Solver.getNextState(i, pm, m_fDt);
				if(intersect(pm.getParticlePosition(i), ps2D.position, m_Polygon.getPoint(j), m_Polygon.getPoint((j+1)%m), &intersection, &normal))
				{
					//Ajouter une force 
					force = m_fElasticity * glm::dot(ps2D.velocity, -normal) * (pm.getParticleSexAppeal(i)/m_fDt) * normal;
					pm.addForce(i, force);
				}
			}
		}
	}

}