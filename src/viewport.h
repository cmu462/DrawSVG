#ifndef CMU462_VIEWPORT_H
#define CMU462_VIEWPORT_H

#include "CMU462.h"
#include "svg.h"

namespace CMU462 {

class Viewport {
 public:

  Viewport( ) : svg_2_norm( Matrix3x3::identity() ) { }
 
  inline Matrix3x3 get_svg_2_norm() {
    return svg_2_norm;
  }

  inline void set_svg_2_norm( Matrix3x3 m ) {
    svg_2_norm = m;
  }

  // set viewbox to look at (centerX, centerY) in svg coordinate space. Span defineds 
  // the view radius of the viewbox in number of pixels (the amout of pixels
  // included in the viewbox in both x and y direction).
  virtual void set_viewbox( float centerX, float centerY, float span ) = 0;

  // Move the viewbox by (dx,dy) in svg coordinate space. Scale the the view 
  // range by scale.
  virtual void update_viewbox( float dx, float dy, float scale ) = 0;

 protected:

  // current viewbox properties
  float centerX, centerY, span;

  // SVG coordinate to normalized display coordinates
  Matrix3x3 svg_2_norm;

}; // class Viewport


class ViewportImp : public Viewport {
 public:
  
  virtual void set_viewbox( float centerX, float centerY, float size );
  virtual void update_viewbox( float dx, float dy, float scale );

}; // class ViewportImp


class ViewportRef : public Viewport {
 public:
  
  virtual void set_viewbox( float centerX, float centerY, float size );
  virtual void update_viewbox( float dx, float dy, float scale );

}; // class ViewportRef


} // namespace CMU462

#endif // CMU462_VIEWPORT_H
