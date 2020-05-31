#include "robot.hpp"

struct Result
{
  double error;
  int lost;
};
void moveRobot(Result result)
{
  int v = 200;
  int dv = 0;
  if (result.lost == 0)
  {
    dv = result.error / 2;
  }
  else if (result.lost == 1)
  {
    dv = 50;
  }
  double vLeft = v + dv;
  double vRight = v - dv;
  setMotors(vLeft, vRight);
}
Result processImage()
{
  Result result;
  takePicture();
  int width = cameraView.width;
  int height = cameraView.height;
  int row = width / 2;
  while (1)
  {
    int lost = 0;
    int whiteIndex = 0;
    int whiteIndexTotal = 0;
    int whiteIndexCount = 0;
    usleep(10000);
    takePicture();
    for (int column = 0; column < width; column++)
    {
      int white = (int)get_pixel(cameraView, row, column, 3);
      if (white > 200)
      {
        whiteIndexTotal += column;
        whiteIndexCount += 1;
      }
    }
    if (whiteIndexCount != 0)
    {
      whiteIndex = whiteIndexTotal / whiteIndexCount;
    }
    else
    {
      lost = 1;
    }
    std::cout << whiteIndex << std::endl;
    result.error = whiteIndex - width / 2;
    result.lost = lost;
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
