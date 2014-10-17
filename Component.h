//
//  component.h
//  Scene
//
//  Created by T.K. Broderick on 10/11/14.
//
//

#pragma once

using ComponentBaseRef = std::shared_ptr<class ComponentBase>;
class ComponentBase {
    
public:
    virtual ~ComponentBase(){}
    virtual void update() = 0;
    virtual void draw() = 0;
    
protected:
    
};