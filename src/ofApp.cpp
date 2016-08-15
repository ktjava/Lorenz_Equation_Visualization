#include "ofApp.h"

double ofApp::fx(double t, double x, double y, double z) {
  double p = 10 + 10 * ofRandom(-volumeIn * 10, volumeIn * 10);
  return p * (y - x);
}

double ofApp::fy(double t, double x, double y, double z) {
  double r = 28 + 10 * ofRandom(-volumeIn * 10, volumeIn * 10);
  return x * (r - z) - y;
}

double ofApp::fz(double t, double x, double y, double z) {
  double b = 8 / 3 + 10 * ofRandom(-volumeIn * 10, volumeIn * 10);
  return x * y - b * z;
}

//--------------------------------------------------------------
void ofApp::setup(){
  //oF Core Settings
  ofSetLogLevel(OF_LOG_VERBOSE);
  //Display Settings
	ofSetWindowTitle("Lorenz_Atractor");
	ofSetVerticalSync(true);
	ofSetFrameRate(DRAW_FPS);
	ofSetBackgroundAuto(false);
	ofBackground(0,0,0);
  //Input Sound Device Settings
	soundStream.printDeviceList();
	int bufferSize = 256;
	soundStream.setup(this, 0, 2, 48000, bufferSize, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
  ofSetColor(0, 10);
  ofRect(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::draw(){
  double t = 0, x = volumeIn, y = volumeIn, z = volumeIn, h = STEP_SIZE,
  kx1, kx2, kx3, kx4,
  ky1, ky2, ky3, ky4,
  kz1, kz2, kz3, kz4;

  ofFill();

  while(t <= 10){

    kx1 = fx(t, x, y, z);
    ky1 = fy(t, x, y, z);
    kz1 = fz(t, x, y, z);

    kx2 = fx(t + h / 2, x + h * kx1 / 2, y + h * ky1 / 2, z + h * kz1 / 2);
    ky2 = fy(t + h / 2, x + h * kx1 / 2, y + h * ky1 / 2, z + h * kz1 / 2);
    kz2 = fz(t + h / 2, x + h * kx1 / 2, y + h * ky1 / 2, z + h * kz1 / 2);

    kx3 = fx(t + h / 2, x + h * kx2 / 2, y + h * ky2 / 2, z + h * kz2 / 2);
    ky3 = fy(t + h / 2, x + h * kx2 / 2, y + h * ky2 / 2, z + h * kz2 / 2);
    kz3 = fz(t + h / 2, x + h * kx2 / 2, y + h * ky2 / 2, z + h * kz2 / 2);

    kx4 = fx(t + h, x + h * kx3, y + h * ky3, z + h * kz3);
    ky4 = fy(t + h, x + h * kx3, y + h * ky3, z + h * kz3);
    kz4 = fz(t + h, x + h * kx3, y + h * ky3, z + h * kz3);

    x += h * (kx1 + 2 * kx2 + 2 * kx3 + kx4) / 6;
    y += h * (ky1 + 2 * ky2 + 2 * ky3 + ky4) / 6;
    z += h * (kz1 + 2 * kz2 + 2 * kz3 + kz4) / 6;

    ofColor c;
    c.setHsb(ofMap(sqrt(x*x+y*y+z*z), 0, 50, 0, 255), 255, 255, ofMap(fabs(volumeIn), 0, 1, 0, 200));
    ofSetColor(c);
    ofDrawSphere(10 * x + ofGetWidth() / 2, 10 * y + ofGetHeight() / 2, 10 * z, 1);

    t += h;

  }
}

//--------------------------------------------------------------
void ofApp::audioIn(ofSoundBuffer &buffer){
    volumeIn = buffer.getSample(1, 1);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
