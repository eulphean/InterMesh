#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"
#include "Agent.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
  
    void setupGui();
    void createAgent();
    void clearAgents();
    void updateAgentProps();
  
    // Contact listening callbacks.
    void contactStart(ofxBox2dContactArgs &e);
    void contactEnd(ofxBox2dContactArgs &e);
  
    // Interactive elements
		void keyPressed(int key);
    void mousePressed(int x, int y, int button); 
    void exit();
  
    bool hideGui;
  
    // Box2d
    ofxBox2d box2d;
  
    // Agents
    std::vector<Agent> agents;
    AgentProperties agentProps;
  
    // GUI
    ofxPanel gui;
  
    // Mesh dimensions
    ofxIntSlider meshColumns;
    ofxIntSlider meshRows;
  
    // Mesh size
    ofxIntSlider meshWidth;
    ofxIntSlider meshHeight;
  
    // Vertex radius
    ofxFloatSlider vertexRadius;
  
    // Vertex physics
    ofxFloatSlider vertexDensity;
    ofxFloatSlider vertexBounce;
    ofxFloatSlider vertexFriction;
  
    // Joint physics
    ofxFloatSlider jointFrequency;
    ofxFloatSlider jointDamping;
  
    // Soft body turn on
    ofxToggle showSoftBody;
  
  private:
    int agentNum;
    std::vector<std::shared_ptr<ofxBox2dJoint>> interAgentJoints;
    std::vector<b2Body *> collidingBodies;
  
};
