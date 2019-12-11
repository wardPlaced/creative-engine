#ifdef __MODUS_TARGET_DESKTOP_DISPLAY__

#ifndef DESKTOPDISPLAY_H
#define DESKTOPDISPLAY_H

#include "DisplayDefines.h"
#include "Display.h"

#include "BBase.h"
#include "BBitmap.h"

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Texture;

class DesktopDisplay : public Display {

public:
  DesktopDisplay();

  ~DesktopDisplay();

  void Update() override;

  // For compatibility
  void Init() override {};

  TUint16 color565(TUint8 red, TUint8 green, TUint8 blue) override{
    // lifted from Display2.cpp
    // maybe we want to return something else for SDL
    return ((blue & 0xF8) << 8) | ((red & 0xFC) << 3) | ((green & 0xF8) >> 3);
  }
public:
  SDL_Window *screen = ENull;
  SDL_Renderer *renderer = ENull;
  SDL_Texture *texture = ENull;

};


#endif //DESKTOPDISPLAY_H

#endif