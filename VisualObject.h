//
//  VisualObject.h
//  Scene
//
//  Created by T.K. Broderick on 10/11/14.
//
//

#pragma once
#include "Component.h"

using VisualObjectRef = std::shared_ptr<class VisualObject>;

class VisualObject : public ComponentBase {
public:
  
  static VisualObjectRef create(){
    return VisualObjectRef( new VisualObject() );
  }
  
  void update()override{}
  
  void draw()override{
    ci::gl::color(mColor.r, mColor.g, mColor.b);
    ci::gl::drawSolidCircle(ci::vec2(0, 0), 1, 50);
  }
  
  void setColor(float r, float g, float b){
    mColor = ci::vec3(r, g, b);
  }
  
  ci::vec3 getColor() {
    return mColor;
  }
  
  ci::vec3 mColor = ci::vec3(1, 1, 1);
  
protected:
  
};