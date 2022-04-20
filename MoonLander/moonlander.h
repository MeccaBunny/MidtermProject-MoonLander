#ifndef MOONLANDER
#define MOONLANDER

// initialize
struct physicObject MoonLander_coordinate;
void MoonLander_SpaceshipInit();

//Thruster
double thrusterX;
double thrusterY;
double thrusterZ;
double thrusterRoll;
double thrusterYaw;
double thrusterPitch;
void MoonLander_mainThruster();
void MoonLander_thrusterX();
void MoonLander_thrusterY();
void MoonLander_thrusterRoll();
void MoonLander_thrusterYaw();
void MoonLander_thrusterPitch();
void MoonLander_phsics(double dt);
void MoonLander_thrustDisperse();

//Sensor
float MoonLander_surfaceSensor[8][8];
void MoonLander_getSurface(); // get surface data relative to lander's yaw.

#endif