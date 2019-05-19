#pragma once

struct Vertex {
	float x, y; // vertex coords
	float s, t; // texture coords
};

struct Triangle {
	Vertex a, b, c;
};