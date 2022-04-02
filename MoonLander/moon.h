#ifndef MOON
#define MOON

//MoonSurface
int moonSize;
float* MoonSurface;
void MoonSurface_create();
void endMoon();

//MoonWind
struct physicObject MoonWind;
void WindInitialize();
void WindUpdate();

#endif