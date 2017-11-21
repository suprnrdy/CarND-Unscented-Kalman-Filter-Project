#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
  VectorXd rmse(4);
  rmse << 0,0,0,0;

    // TODO: YOUR CODE HERE

  // check the validity of the following inputs:
  //  * the estimation vector size should not be zero
  //  * the estimation vector size should equal ground truth vector size
  // ... your code here
  if(estimations.size() == 0 || estimations.size() != ground_truth.size()) return rmse;
    
  //accumulate squared residuals
  VectorXd sum(4);
  sum << 0, 0, 0, 0;
  for(int i=0; i < estimations.size(); ++i){
    // ... your code here
    VectorXd mult = (estimations[i] - ground_truth[i]);
    VectorXd sqr = mult.array() * mult.array();
    sum = sum + sqr;
  }

  //calculate the mean
  // ... your code here
  VectorXd mean = sum.array()/estimations.size();

  //calculate the squared root
  // ... your code here
  rmse = mean.array().sqrt();

  //return the result
  return rmse;
}