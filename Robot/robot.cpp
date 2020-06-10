#include "robot.hpp"
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
  if (result.lost == 0)
  {
    dv = result.error / 2;
    // if the robot is lost, dv is large and positive so it turns to the left
    // it needs to turn to the left since if it is lost it's either completely lost the line
    // or the line is to the left of it, which it doesn't check for.
    // Both of these scenarios are fixed by turning left until you find the line again
  }
  else if (result.lost == 1)
  {
    dv = 50;
  }
  // set left motor to default + dv
  double vLeft = v + dv;
  // set right motor to default - dv
  double vRight = v - dv;
  // set the robot's motor speeds based on above calculation
  setMotors(vLeft, vRight);
}
// process the image from the camera
void processImage()
{
  // create a result structure to hold values
  Result result;
  takePicture();
  int width = cameraView.width;
  int height = cameraView.height;
  // get the middle row
  int row = width / 2;
  // get right and left columns for forks
  int columnLeft = 0;
  // loop forever
  while (1)
  {
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
    // loop down left column
    for (int row = 0; row < height; row++)
    {
      // get the whiteness of each pixel
      int white = (int)get_pixel(cameraView, row, columnLeft, 3);
      // if whiteness is greater than 200, it's white (bad way of doing it)
      if (white > 200)
      {
        whiteIndexTotal += row;
        whiteIndexCount += 1;
      }
    }
    // check if a right turn is available
    if (whiteIndexCount == 0)
    {
      // loop across the middle row
      for (int column = 0; column < width; column++)
      {
        // get the whiteness of each pixel
        int white = (int)get_pixel(cameraView, row, column, 3);
        // if whiteness is greater than 200, it's white (bad way of doing it)
        if (white > 200)
        {
          whiteIndexTotal += column;
          whiteIndexCount += 1;
        }
      }
      if (whiteIndexCount != 0)
      {
        whiteIndex = whiteIndexTotal / whiteIndexCount;
        // if there aren't any white pixels, the robot is lost
        // this also serves to get the robot to turn right if there's no left
        // or forward available
      }
      else
      {
        std::cout << "lost" << std::endl;
        lost = 1;
      }
    }
    else
    {
      // if a right turn is available, tell the robot that the line is 3/4 to the right
      whiteIndex = width / 4;
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
int main()
{
  if (initClientRobot() != 0)
  {
    std::cout << " Error initializing robot" << std::endl;
  }
  processImage();
}
