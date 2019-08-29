#include "viewport.h"

#include "CMU462.h"

namespace CMU462 {

void ViewportImp::set_viewbox( float centerX, float centerY, float span ) {

  // Task 5 (part 2): 
  // Set svg to normalized device coordinate transformation. Your input
  // arguments are defined as SVG canvans coordinates.
  this->centerX = centerX;
  this->centerY = centerY;
  this->span = span; 

}

void ViewportImp::update_viewbox( float dx, float dy, float scale ) { 
  
  this->centerX -= dx;
  this->centerY -= dy;
  this->span *= scale;
  set_viewbox( centerX, centerY, span );
}

} // namespace CMU462
