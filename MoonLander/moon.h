#ifndef MOON
#define MOON

//MoonSurface
void MoonSurface_create();
void endMoon();

//MoonWind
struct physicObject MoonWind;
void WindInitialize();
void WindUpdate();

#endif