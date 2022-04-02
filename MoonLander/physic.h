#ifndef PHYSIC
#define PHYSIC

struct physicObject {
	float X; float DX; float DDX;
	float Y; float DY; float DDY;
	float Z; float DZ; float DDZ;
	float Roll; float DRoll; float DDRoll;
	float Yaw; float DYaw; float DDYaw;
	float Pitch; float DPitch; float DDPitch;
};
double t; double dt;

#endif