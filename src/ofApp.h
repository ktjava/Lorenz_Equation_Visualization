#pragma once

#include "ofMain.h"

#define DRAW_FPS 60
#define STEP_SIZE 0.005

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void audioIn(ofSoundBuffer &buffer);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		double fx(double t, double x, double y, double z);
		double fy(double t, double x, double y, double z);
		double fz(double t, double x, double y, double z);

		float volumeIn;
		ofSoundStream soundStream;

};
