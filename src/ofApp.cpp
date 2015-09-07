#include "ofApp.h"
#include "graphics-utils.h"

void ofApp::setup() {
  ofSetWindowTitle("DEX UI");
  ofBackground(COLOR_15);

  ofSetFrameRate(60);

  std::cout << ofGetScreenWidth() << " " << ofGetWidth() << std::endl;
  std::cout << ofGetScreenHeight() << " " << ofGetHeight() << std::endl;

  unsigned int wm_width = ofGetScreenWidth();
  unsigned int wm_height = ofGetScreenHeight();

  layout = Layout();

  // Position components, set delays for animation
  left = Left();
  left.setPos(40,40); //TODO: USE OFFSETS
  left.setDelay(-50);

  right = Right();
  right.setPos(wm_width - 280,40);
  right.setPosSubviews(wm_width - 280,40);

  right.setDelay(-50);

  term = Term();
  term.setPos(310, 40); //x = 240 + 40 + 30
  term.setSize(wm_width-620,wm_height-310);

  keyboard.setPos(wm_width/2-390, wm_height-230);
  keyboard.setDelay(-100);

  // Other
  // isDrawing controls components, essentially play/pause
  isDrawing = true;

  // recording variables to handle saving animation frame by frame
  isRecording = false;
  recordFrameCounter = 0;
  recordMaxFrames = 1; //60*5;

}

void ofApp::update() {
  if (isRecording) {
    ofSaveFrame();
    recordFrameCounter++;

    if (recordFrameCounter >= recordMaxFrames) {
      isRecording = false;
      recordFrameCounter = 0;
    }
  }
}

void ofApp::draw() {
  ofPushMatrix();
  {
    // translate for osx development (smaller windows)
    // use translate to keep all other coordinates accurate when untranslated
    // note: some elements don't work with translate because they are positioned
    // with ofEasyCamera to deal with perspective differences
    ofTranslate(X_OFFSET, Y_OFFSET);

    //layout.drawBG();
    layout.drawGrid(30);

    // Draw and update components
    if (isDrawing) {
      left.draw();
      right.draw();
      term.draw();
      keyboard.draw();
    }
  }
  ofPopMatrix();

  // Framerate
  ofSetColor(255);
  ofDrawBitmapString(ofToString(ofGetFrameRate()), 10,10);
}

void ofApp::keyPressed(int key) {
  if (key == '.') {
    isRecording = !isRecording;
    cout << "recording: " << isRecording << endl;
  }

  if (key == '=')
    isDrawing = !isDrawing;
}

void ofApp::keyReleased(int key) { }
void ofApp::mouseMoved(int x, int y ) { }
void ofApp::mouseDragged(int x, int y, int button) { }
void ofApp::mousePressed(int x, int y, int button) {
    std::cout << "Press" << std::endl;
}
void ofApp::mouseReleased(int x, int y, int button) { }
void ofApp::windowResized(int w, int h) { }
void ofApp::gotMessage(ofMessage msg) { }
void ofApp::dragEvent(ofDragInfo dragInfo) { }
