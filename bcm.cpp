#include "bcm.hpp"
int colFromXCoord(double xCoord){
    double xLeft = -374495.83635;
    double cellSize = 270.0;
    double result;
    int retVal;
    
    result = (xCoord - xLeft)/cellSize;
    retVal = result;
    return retVal;
}
int RowFromYCoord(double yCoord){
    double yBot = -616153.33419;
    double cellSize = 270.0;
    double result;
    int retVal;
    
    result = (yCoord - yBot)/cellSize;
    retVal = result;
    return retVal;
}