#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);

	ofSetLineWidth(20);

	//Creates width of canvas for scaling
	tileSizeX = ofGetWidth() / numOfTilesX;
	tileSizeY = ofGetHeight() / numOfTilesY;

	//Creates individual canvas for the ties
	tile.allocate(tileSizeX, tileSizeY, GL_RGBA, 4);
	canvas.allocate(ofGetWidth(), ofGetHeight(), GL_RGB, 4);

	tile.begin();

	//Clears tile and sets background to white & object colour to black
	ofClear(255); 
	ofSetColor(0);

	//Sets circle resolution to '3' - to create a triangle
	ofSetCircleResolution(3);

	//Draws the three componant parts of the individual tile
	ofDrawEllipse(tileSizeX, tileSizeY / 2, tileSizeX, tileSizeY);
	ofDrawLine(tileSizeX / 2, 0, tileSizeX / 2, tileSizeY);
	ofDrawLine((tileSizeX / 2) + 30, 30, (tileSizeX / 2) + 30, tileSizeY-(tileSizeY/4));

	tile.end();

	//Generates a nested list of random numbers, for tile generation
	for (int x = 0; x < numOfTilesX; x++) {
		for (int y = 0; y < numOfTilesY; y++) {
			randomNumbers[x][y] = ofRandom(1);
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	canvas.begin();
	ofClear(255);

	//Generates canvas made up of the smaller tile canvases
	for (int x = 0; x < numOfTilesX; x++) {
		float locX = x * tileSizeX;
		for (int y = 0; y < numOfTilesY; y++) {
			float locY = y * tileSizeY;

			ofPushMatrix();
			ofPushStyle();

			ofTranslate(locX, locY);

			ofPushMatrix();

			ofTranslate(tileSizeX / 2, tileSizeY / 2);


			ofSetColor(255);

			//Based on 'Randomised Texture' Week 3 Code Example

			if (randomNumbers[x][y] > 0.3) {
				ofRotateDeg(90);
			}

			if (randomNumbers[x][y] > 0.6) {
				ofRotateDeg(180);
			}

			tile.draw(-tileSizeX / 2, -tileSizeY / 2, tileSizeX, tileSizeY);

			ofPopMatrix();


			ofPopStyle();
			ofPopMatrix();
		}
	}
	canvas.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	canvas.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	//Re-generates tiles with C key
	if (key == 'c') {
		for (int x = 0; x < numOfTilesX; x++) {
			for (int y = 0; y < numOfTilesY; y++) {
				randomNumbers[x][y] = ofRandom(1);
			}
		}
	}


	//Saves Output as PNG file
	if (key == 's') {
		ofPixels pix;
		canvas.readToPixels(pix);
		ofSaveImage(pix, "genimg_" + ofToString(ofGetTimestampString()) + ".png", OF_IMAGE_QUALITY_BEST);
	}

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
