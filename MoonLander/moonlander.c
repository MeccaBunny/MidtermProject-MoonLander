/**************************************************************
* MoonLander
* Characteristics of moon lander.
**************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

#include"physic.h"
#include "moon.h"
#include "moonlander.h"
#include "ex.h"

double dispersingR = 0.61;

void MoonLander_SpaceshipInit()
{
	MoonLander_coordinate.X = 0;
	MoonLander_coordinate.DX = 0;
	MoonLander_coordinate.DDX = 0;
	MoonLander_coordinate.Y = 0;
	MoonLander_coordinate.DY = 0;
	MoonLander_coordinate.DDY = 0;
	MoonLander_coordinate.Z = 0;
	MoonLander_coordinate.DZ = 0;
	MoonLander_coordinate.DDZ = 0;
	MoonLander_coordinate.Roll = 0;
	MoonLander_coordinate.DRoll = 0;
	MoonLander_coordinate.DDRoll = 0;
	MoonLander_coordinate.Yaw = 0;
	MoonLander_coordinate.DYaw = 0;
	MoonLander_coordinate.DDYaw = 0;
	MoonLander_coordinate.Pitch = 0;
	MoonLander_coordinate.DPitch = 0;
	MoonLander_coordinate.DDPitch = 0;
}
void MoonLander_mainThruster() {
	thrusterZ += 100;
}
void MoonLander_thrusterX() {
	thrusterX += 10;
}
void MoonLander_thrusterY() {
	thrusterY += 10;
}
void MoonLander_thrusterRoll() {
	thrusterRoll += 5;
}
void MoonLander_thrusterYaw() {
	thrusterYaw += 5;
}
void MoonLander_thrusterPitch() {
	thrusterPitch += 5;
}
void MoonLander_phsics(double dt) {
	dt = dt / 1000;
	MoonLander_coordinate.X = 0.5 * MoonLander_coordinate.DDX * dt * dt + MoonLander_coordinate.DX * dt + MoonLander_coordinate.X;
	MoonLander_coordinate.Y = 0.5 * MoonLander_coordinate.DDY * dt * dt + MoonLander_coordinate.DY * dt + MoonLander_coordinate.Y;
	MoonLander_coordinate.Z = 0.5 * MoonLander_coordinate.DDZ * dt * dt + MoonLander_coordinate.DZ * dt + MoonLander_coordinate.Z;
	MoonLander_coordinate.Roll = 0.5 * MoonLander_coordinate.DDRoll * dt * dt + MoonLander_coordinate.DRoll * dt + MoonLander_coordinate.Roll;
	MoonLander_coordinate.Yaw = 0.5 * MoonLander_coordinate.DDYaw * dt * dt + MoonLander_coordinate.DYaw * dt + MoonLander_coordinate.Yaw;
	MoonLander_coordinate.Pitch = 0.5 * MoonLander_coordinate.DDPitch * dt * dt + MoonLander_coordinate.DPitch * dt + MoonLander_coordinate.Pitch;
	MoonLander_coordinate.DX = MoonLander_coordinate.DDX * dt + MoonLander_coordinate.DX;
	MoonLander_coordinate.DY = MoonLander_coordinate.DDY * dt + MoonLander_coordinate.DY;
	MoonLander_coordinate.DZ = MoonLander_coordinate.DDZ * dt + MoonLander_coordinate.DZ;
	MoonLander_coordinate.DRoll = MoonLander_coordinate.DDRoll * dt + MoonLander_coordinate.DRoll;
	MoonLander_coordinate.DYaw = MoonLander_coordinate.DDYaw * dt + MoonLander_coordinate.DYaw;
	MoonLander_coordinate.DPitch = MoonLander_coordinate.DDPitch * dt + MoonLander_coordinate.DPitch;
}
void MoonLander_thrustDisperse() {
	thrusterX = 0; thrusterY = 0; thrusterZ = 0; thrusterRoll = 0; thrusterYaw = 0; thrusterPitch = 0;
}
