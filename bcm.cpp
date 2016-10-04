#include "bcm.hpp"
// double bcm(double m, double b, double *x, double *y, double *yerr, int N) {
    // int n;
    // double result = 0.0, diff;

    // for (n = 0; n < N; n++) {
        // diff = (y[n] - (m * x[n] + b)) / yerr[n];
        // result += diff * diff;
    // }

    // return result;
// }
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