#include "robot.hpp"
  
// count of black pixels (not good idea to put here)
int blackIndexCount = 0;

// structure so that processImage can return two values
struct Result
{
  // how far away from the middle the white line is
  double error;
  // can the robot see the white line?
  int lost;
};
// function to adjust the robot's motor speeds based on where the white line is
void moveRobot(Result result)
{
  // default speed of motors
  int v = 50;
  // difference based on error
  int dv = 0;
  // if the robot isn't lost, dv is error/2
  if (result.lost == 0) {
    dv = result.error / 2;
    // if the robot is lost, dv is large so that it turns around
  }
  else if (result.lost == 1) {
    dv = 50;
  } 
	// sets speed of motors to 0
  else if (result.lost == 2){
	v = 0;
	dv = 0;
}
  // set left motor to default + dv
  double vLeft = v + dv;
  // set right motor to default - dv
  double vRight = v - dv;
  // set the robot's motor speeds based on above calculation
  setMotors(vLeft, vRight);
}
// process the image from the camera
Result processImage(){
  // create a result structure to hold values
  Result result;
  takePicture();
  int width = cameraView.width;
  int height = cameraView.height;
  // get the middle row
  int row = width / 2;
  
  // loop forever (probably not ideal)
  while (1) {
    // by default robot is not lost
    int lost = 0;
    // index of white pixels
    int whiteIndex = 0;
    // sum of the indexes of white pixels
    int whiteIndexTotal = 0;
    // count of white pixels
    int whiteIndexCount = 0;

    usleep(10000);
    takePicture();
    // loop across the middle row
	for (int column = 0; column < width; column++)
    {
      // get the luminosity of each pixel
		int luminosity = (int)get_pixel(cameraView, row, column, 3);
      // if luminosity is greater than 200, it's white (bad way of doing it)
		if (luminosity > 200) {
			whiteIndexTotal += column;
			whiteIndexCount += 1;
		} 
	  // if luminosity is less than 20, it's black
		else if (luminosity < 20){
			blackIndexCount = blackIndexCount + 1;
			//std::cout << "blackIndexCount: "<<blackIndexCount<<std::endl;
		}

    }
	// If the image has black pixels, then lost = 2.
	if (blackIndexCount > 20) {
		lost = 2;
	}
    // If there are any white pixels, average their indexes to find out where in the row they are
    else if (whiteIndexCount != 0)
    {
      whiteIndex = whiteIndexTotal / whiteIndexCount;
      // if there aren't any white pixels, the robot is lost
    }
    else
    {
      lost = 1;
    }
    
    // set the error to the index minus the width over 2
    // this is so that if the white line is on the left, error is negative
    // and if it's on the right, error is positive
    result.error = whiteIndex - width / 2;
    result.lost = lost;
    // call moverobot
    moveRobot(result);
  }
}

int main() {
	if (initClientRobot() != 0) {
		std::cout << " Error initializing robot" << std::endl;
	}
	processImage();
}
