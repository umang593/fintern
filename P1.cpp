/* Name - Umang Agarwal
   trade - CSE 
   College - IIT Mandi */
// Objective - We focus on finding the minimum of the negative of the optimization equation
// Source : http://www.coin-or.org/Cbc/cbcuserguide.html 


#include "OsiClpSolverInterface.hpp"                         // For taking Input from a file
#include "CbcModel.hpp"                                     // Problem solver

int main ()
{
    OsiClpSolverInterface solver;                               // creating an object solver for reading from file
    int errors = solver.readMps("question.mps","");            // read the question file to know about the problem
    assert(errors==0);   					                  // Inorder to be confident about the input file
    
    /* Logics And  Calculation */
    CbcModel calc(solver);                                 // passing object solver into CBCModel object for solving Problem Statement
    calc.branchAndBound();
    double temp ;
    int numc = calc.solver()->getNumCols();
    double * res  = calc.bestSolution();		         // res pointer has optimum solution to the problem
    for (int j=0;j<numc;j++)
    {
        temp =res[j];
      		printf("x%d = %lf\n",j+1,temp);              // Printing Optimum Variable Values
   	}
    return 0;
}


