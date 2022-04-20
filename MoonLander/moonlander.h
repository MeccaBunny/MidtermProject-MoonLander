#ifndef MOONLANDER
#define MOONLANDER


struct physicObject MoonLander_coordinate;
double thrusterX;
double thrusterY;
double thrusterZ;
double thrusterRoll;
double thrusterYaw;
double thrusterPitch;

// initialize
void MoonLander_SpaceshipInit();
//Thruster
void MoonLander_mainThruster();
void MoonLander_thrusterX();
void MoonLander_thrusterY();
void MoonLander_thrusterRoll();
void MoonLander_thrusterYaw();
void MoonLander_thrusterPitch();
void MoonLander_phsics(double dt);
void MoonLander_thrustDisperse();

#endif