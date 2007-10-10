#ifndef COMMON_H
#define COMMON_H

typedef struct {
	int x, y;
} Position2D;

typedef struct {
	int width, height;
} Size2D;

typedef struct {
	float x, y, z;
} Vector3Df;

typedef struct {
	float r, g, b;
} Color3f;

typedef struct {
	float r, g, b, a;
} Color4f;

#endif
