#include "robot.hpp"
  struct Result{
		double error;
		int lost;
  };
	
	void moveRobot(Result result){
		int v = 50 , dv = 0;
		if(result.lost ==0){
			dv = result.error / 2;
		}else if(result.lost ==1){
			dv = 50;
		}else if(result.lost ==2){
			v = 0; // set speed to 0 so that robot stops
		}
		double vLeft = v + dv , vRight = v - dv;
		setMotors(vLeft, vRight);
	}	
	Result processImage(){
		Result result;
		takePicture();
		int width = cameraView.width , height = cameraView.height;;
		int row = width / 2;
		while(1){
			int lost=0 , whiteIndex=0 , whiteIndexTotal=0 , whiteIndexCount=0;			  
			usleep(10000);
			takePicture();
			for(int column = 0;column < width;column++){
				int white = (int)get_pixel(cameraView,row,column,3);
				if (white > 200){
					whiteIndexTotal += column;
					whiteIndexCount += 1;
				}else if(white<20){ // it means that it is black
					lost = 2;
				}
			}
			if(lost == 2){// if the robot see black
				break; // then it will break out of the while loop
			}
			if(whiteIndexCount != 0){
				whiteIndex = whiteIndexTotal / whiteIndexCount;
			}else{
				lost = 1;
			}
			result.error = whiteIndex - width /2;
			result.lost = lost;
			moveRobot(result);
		}
		result.error = 0;
		result.lost = 2;
		moveRobot(result);
		return result;
	}
int main(){
	if (initClientRobot() !=0){
	std::cout<<" Error initializing robot"<<std::endl;
	}
	processImage();
} // main
