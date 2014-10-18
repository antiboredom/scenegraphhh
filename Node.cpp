//
//  Node.cpp
//  Node
//
//  Created by T.K. Broderick on 10/11/14.
//
//

#include "Node.h"
using namespace ci;
using namespace ci::app;
using namespace std;

void Node::setPosition( const ci::vec3& position ){
  mPosition = position;
  setMatrix( mat4( translate( position ) ) );
}

void Node::setRotation( const ci::vec3& axis, const float& degree ){
  mRotationAxis = axis;
  mRotationDegree = degree;
  setMatrix( mat4( rotate( degree, axis ) ) );
}

void Node::setScaled( const ci::vec3& scale ){
  mScale = scale;
  setMatrix( mat4( glm::scale( scale ) ) );
}

void Node::updatePosition( const ci::vec3& position ){
  updateMatrix( mat4( translate( position ) ) );
  
}

void Node::updateRotation( const ci::vec3& axis, const float& degree ){
  updateMatrix( mat4( rotate( degree, axis ) ) );
}

void Node::updateScaled( const ci::vec3& scale ){
  updateMatrix(mat4( glm::scale( scale ) ));
}

void Node::lookAt( const ci::vec3& position, const ci::vec3& center_of_interest ){
  vec3 diff = position - center_of_interest;
  mLookDirection = normalize(diff);
  
  mModelMatrix = mat4( translate(position) );
}

void Node::setMatrix(const ci::mat4 &matrix){
  mModelMatrix = matrix;
}

void Node::updateMatrix(const ci::mat4 &matrix){
  mModelMatrix *= matrix;
}


void Node::draw(){
  
  gl::ScopedModelMatrix push;
  
  if( mParent )
    gl::multModelMatrix(mModelMatrix * mParent->mModelMatrix);
  else
    gl::multModelMatrix(mModelMatrix);
  
  gl::drawColorCube( vec3( 0,0,0 ), vec3( 1,1,1 ) );
  
  auto it = mChildren.begin();
  auto end = mChildren.end();
  
  while (it != end) {
    it->second->draw();
    it++;
  }
}