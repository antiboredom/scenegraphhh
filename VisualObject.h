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
//        ci::gl::drawColorCube(ci::vec3(0,0,0), ci::vec3(1,1,1));
      ci::gl::drawSolidCircle(ci::vec2(0, 0), 1, 50);
    }
    
protected:
    
};