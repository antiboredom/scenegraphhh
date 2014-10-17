//
//  Actor.h
//  Scene
//
//  Created by T.K. Broderick on 10/11/14.
//
//

#pragma once
#include "Node.h"
#include "Component.h"

using ActorRef = std::shared_ptr< class Actor >;

class Actor : public Node {
    
public:
    
    static ActorRef create( const std::string& name, Node* parent = nullptr){
        return ActorRef( new Actor( name, parent ) );
    }
    
    void addComponent( ComponentBaseRef component ){
        mComponents.push_back(component);
    }
    
    void update() override{
        for ( auto& component : mComponents ) {
            component->update();
        }
        
        auto it = mChildren.begin();
        auto end = mChildren.end();
        
        while (it != end) {
            it->second->update();
            it++;
        }
        
    }
    
    void draw() override{
        
        {
            ci::gl::ScopedModelMatrix push;
            if(mParent)
                ci::gl::multModelMatrix(mModelMatrix + mParent->mModelMatrix);
        
            for( auto& component : mComponents ){
                component->draw();
            }
        }
        
        auto it = mChildren.begin();
        auto end = mChildren.end();
        
        while (it != end) {
            it->second->draw();
            it++;
        }
        
    }
    
    const std::string& getName(){ return mName; }

protected:
    
    Actor(const std::string& name, Node* parent ): Node(parent), mName(name){}
    
    std::vector<ComponentBaseRef> mComponents;
    std::string mName;
};


