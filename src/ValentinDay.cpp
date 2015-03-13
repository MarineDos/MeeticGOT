#include <iostream>
#include <cstdlib>

#include <PartyKel/glm.hpp>
#include <PartyKel/WindowManager.hpp>
#include <PartyKel/renderer/Renderer2D.hpp>
#include <PartyKel/ParticleManager2D.hpp>
#include <PartyKel/LeapfrogSolver2D.hpp>
#include <PartyKel/Polygon2D.h>
#include <PartyKel/PolygonForce2D.hpp>
#include <PartyKel/HookForce2D.hpp>
#include <PartyKel/BrakeForce2D.hpp>
#include <PartyKel/RepulseForce2D.hpp>

#include <vector>

static const Uint32 WINDOW_WIDTH = 1024;
static const Uint32 WINDOW_HEIGHT = 1024;

using namespace PartyKel;

int wmain() {
	WindowManager wm(WINDOW_WIDTH, WINDOW_HEIGHT, "Valentin's Day");
	wm.setFramerate(30);

	Renderer2D renderer;

	uint32_t particleCount = 128;

	// Création des particules
	ParticleManager2D particleManager;
	LeapfrogSolver2D leapfrogSolver;

	// Création des Polygons
	Polygon2D mPolyBox = Polygon2D::buildBox(glm::vec3(1.0, 0, 0), glm::vec2(-1.0f, -1.0f), 2.0f, 2.0f, true);
	PolygonForce2D mPolyForceBox = PolygonForce2D(mPolyBox, 2, leapfrogSolver);

	// HookForce
	HookForce2D hookForce = HookForce2D(0.5, 0.5);
	// BrakeForce
	BrakeForce2D brakeForce = BrakeForce2D(0.2, 0.0);
	// RepulseForce
	RepulseForce2D repulseForce = RepulseForce2D(0.8, 0.8);

	float randomMoveScale = 0.01f;

	// Temps s'écoulant entre chaque frame
	float dt = 0.f;
	particleManager.addGOTParticles();

	srand(time(NULL));
	bool done = false;
	while (!done) {
		wm.startMainLoop();
		
		if (((double)rand() / (RAND_MAX)) * 3 < dt)
		{

			particleManager.updateStatus();
		}

		// Force
		hookForce.apply(particleManager);
		repulseForce.apply(particleManager);
		if (dt > 0.000001)
		{
			brakeForce.setDt(dt);
			brakeForce.apply(particleManager);

			mPolyForceBox.setDt(dt);
			mPolyForceBox.apply(particleManager);
		}


		// Simulation
		leapfrogSolver.solve(particleManager, dt);
		// Rendu
		renderer.clear();
		particleManager.drawParticles(renderer);
		
		//renderer.clear();
		//particleManager.drawParticles(renderer);
		mPolyBox.draw(renderer);
		
		// Gestion des evenements
		SDL_Event e;
		while (wm.pollEvent(e)) {
			switch (e.type) {
			default:
				break;
			case SDL_QUIT:
				done = true;
				break;
			}
		}

		// Mise à jour de la fenêtre
		dt = wm.update();
	}

	return EXIT_SUCCESS;
}
