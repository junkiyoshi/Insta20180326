#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	int span = 50;
	for (int radius = 50; radius < ofGetWidth(); radius += span) {

		ofRotate(ofMap(ofNoise(radius * 0.005 + ofGetFrameNum() * 0.05), 0, 1, -50, 50));
		int small_radius = radius - span;

		for (int i = 0; i < 2; i++) {

			int deg_start = i * 180;
			vector<ofPoint> vertices;
			for (int deg = deg_start; deg <= deg_start + 90; deg += 1) {

				vertices.push_back(ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)));
			}

			for (int deg = deg_start + 90; deg >= deg_start; deg -= 1) {

				vertices.push_back(ofPoint(small_radius * cos(deg * DEG_TO_RAD), small_radius * sin(deg * DEG_TO_RAD)));
			}

			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}