
#pragma once

namespace PartyKel
{

class ParticleManager2D;

class Force2D
{
public:
	virtual ~Force2D() {};

	virtual void apply(ParticleManager2D& pm) = 0;
}; // class

} // namespace