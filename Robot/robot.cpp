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
  }
  else if (result.lost == 1)
  {
    // if the robot is lost, dv is large and positive so it turns to the left
    dv = 35;
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
  int row = height / 2;
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
    // check if a left turn is available
    if (whiteIndexCount == 0)
    {
      // loop across the middle row
      for (int column = 0; column < width; column++)
      {
        // get the whiteness of each pixel
        int white = (int)get_pixel(cameraView, row, column, 3);
        // if whiteness is greater than 200, it's white
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
        lost = 1;
      }
    }
    else
    {
      // if a left turn is available, tell the robot that the line is 1/4 from the left
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
// method to make sure the robot can see the walls at the start
int adjust(bool turnleft, bool turnright)
{
  int error;
  if ((!turnleft) && (!turnright))
  {
    error = 0;
  }
  else if (turnleft)
  {
    error = -15;
  }
  else if (turnright)
  {
    error = 15;
  }
  return error;
}
void processChallenge()
{
  // create a result structure to hold values
  Result result;
  takePicture();
  int width = cameraView.width;
  int height = cameraView.height;
  int row = 0;
  // counter used to wait before turning
  int rightcount = 0;
  // counter to keep the robot from doing 180s
  int leftcount = 0;
  bool turned;
  while (1)
  {
    // move the viewpoint slowly back as it needs to be at the front at the start and at the back for the turns.
    if (row < height * 3 / 4)
    {
      row = row + 4;
    }
    takePicture();
    // by default robot is not lost
    int lost = 0;
    // booleans for decision-making
    bool turnleft = true;
    bool turnright = true;
    bool middle = false;
    for (int column = 0; column < width; column++)
    {
      int red = (int)get_pixel(cameraView, row, column, 0);
      if (red > 250)
      {
        // if there's a wall on the right, don't turn right
        if (column > width / 2)
        {
          turnright = false;
        }
        // If there's a wall in the middle, turn left
        else if (column == width / 2)
        {
          middle = true;
        }
        // required for the adjustment at the start
        else if (column < width / 2)
        {
          turnleft = false;
        }
      }
    }
    // adjust robot for the first bit (using the row number is just convenient)
    if (row < height / 2)
    {
      result.error = adjust(turnleft, turnright);
      moveRobot(result);
    }
    else
    {
      // if robot doesn't need to turn left or right, there is no error
      result.error = 0;
      leftcount--;
      // if the robot can turn right for 7 loops, turn 90 degrees (more or less)
      if (turnright)
      {
        rightcount++;
        if (rightcount > 7)
        {
          result.error = 169;
          rightcount = 0;
        }
      }
      // if the robot can't turn right but there's a wall in front, turn left
      // but not too soon after it already turned left
      else if (middle)
      {
        if (leftcount < 0)
        {
          result.error = -169;
          leftcount = 2;
        }
      }
      moveRobot(result);
    }
    result.lost = lost;
  }
}

int main()
{
  if (initClientRobot() != 0)
  {
    std::cout << " Error initializing robot" << std::endl;
  }
  char x;
  std::cout << "Core/Completion (0) or challenge(1)?" << std::endl;
  std::cin >> x;
  if (x == '0')
  {
    processImage();
  }
  else if (x == '1')
  {
    processChallenge();
  }
  else
  {
    std::cout << "invalid choice";
  }
}
