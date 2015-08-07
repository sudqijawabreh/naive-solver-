#ifndef SOLVING_01_04_MOFIFY_H
#define SOLVING_01_04_MOFIFY_H
#include"solving_07_01.h"
#include"solving_07_02.h"
#include<stdlib.h>
#include<stdio.h>


/**
 * Generate and print a random clause with nbLiterals literals
 * @param f the formula
 * @param clauseNumber : the clause to generate
 * @param : the number of literals that contain the clause
	
 */
void generateClause(Formula * f, int nbLiterals) {
  Clause * c;
    createClause(&c);
    addClause(f,c);
  for(int i = 0;i<nbLiterals;i++) {
    int sign = rand()%2 ? 1 : -1;
    Literal l = sign*(rand()%f->nbVariables+1);
      
    addLiteralInClause(*f,c,l);
   
  }
}

/**
 * Generate and print nbClauses
 * @param f the formula
 * @param 
 */

void generateAllClauses(Formula * f,int nbClauses) {

  for(int i = 0;i<nbClauses;i++) {
    int value =rand()%(f->nbVariables)+1;
    generateClause(f,value);
  }
}

/**
 * Generate a full random formula
 * @param number of variables
 * @param number of clauses
 * @return the formula
 */

void generateFullRandomFormula(Formula *f,int nbVars,int nbClauses) {
  createFormula(f,nbVars);
  generateAllClauses(f,nbClauses);


}
/**
 * Generate a 3-SAT random formula
 * Each clause have to contain exactly 3 literals
 * @param number of variables
 * @param number of clauses
 * Return the formula
 */

void generate3RandomFormula(Formula *f,int nbVars,int nbClauses) {
  
}


/**
 * Print in a DIMACS format a formula
 * @param f the formula to print
 */

void printDimacs(Formula f);
#endif

