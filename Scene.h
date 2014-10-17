//
//  Scene.h
//  Scene
//
//  Created by T.K. Broderick on 10/11/14.
//
//

#pragma once
#include "Node.h"
#include "Actor.h"

using SceneRef = std::shared_ptr<class Scene>;

class Scene : public Node{
public:
    static SceneRef create(){ return SceneRef( new Scene() ); }
    
    void update() override{
        auto it = mChildren.begin();
        auto end = mChildren.end();
        
        while (it != end) {
            it->second->update();
            it++;
        }
        
        
    }
    void draw() override{
        auto it = mChildren.begin();
        auto end = mChildren.end();
        
        while (it != end) {
            it->second->draw();
            it++;
        }
    }
    



protected:
    Scene(): Node(nullptr) {}
    
};
