#include "Application.h"

int main() {

	Application app{ "Particles", {1920, 1080} };
	app.run();


	// release  ~25-30 FPS 10'000 particles drawing sf::RectangleShape
	// release  ~60-65 FPS drawing sf::Vertex
	// release  ~200-240 FPS BATCHING DRAW CALLS JESUS FUCK
	// Batching has 3x performance with 10x the particles
	// 1000 batches, with 1 million total particles ~18-20 FPS
	// Fixed update call 1 mil part, 80 fps, 1 batch
	// Fixed update call 1 mil part, 80 fps, 10 batch
	// Fixed update call 1 mil part, 150 fps, 100 batches
	// Fixed update call 1 mil part, 150 fps, 1000 batches
	// 
	// Fixed update call 1 mil part, 170 fps, 100 batches using memcpy
	// Eliminating memcpy, 190-200 fps. draw call takes 5% time, update 35%
	// 2 mil particles = 105fps
	// 8 mil ~20fps
}

