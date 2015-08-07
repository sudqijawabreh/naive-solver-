#ifndef SOLVING_07_02_H
#define SOLVING_07_02_H
#include"vecInt.h"
#include"solving_07_01.h"


#define DEFAULTSIZE 20
// Typedef usefull for readbility
typedef vecInt Clause;
typedef vecInt Occurrences;
typedef vecInt Occurrences;

typedef struct node{
	vecInt * clause;
	struct node  * next;

}node;
typedef struct {
  int nbClauses;
  int nbVariables;
  node * clauses;
  node ** literalOccurrences;
} Formula;


/*****************************************************
 * Create the memory space for a formula f
 * @param f the formula
 * @param nbClauses
 * @param nbVariables
 */
	void createFormula(Formula *f,int nbVariables);

/*****************************************************
 * Free the dynamic memory allocation

 * 
 */
void freeFormula(Formula *f);



/*****************************************************
 * Create space for clause 
 * The default space allocated will be DEFAULTSIZE
 * @param f the formula
 * @param clauseNumber (the position)

 */
void createClause(Clause ** c);

/*****************************************************
 * insert a literal l in a given clause
 * @param f the formula
 * @param clauseNumber (the position)
 * @param Literal l
 */
void addLiteralInClause(Formula f,Clause * c, Literal l);
void addClause(Formula * f, Clause * c);
void addOccurance(Formula f, Clause * c,Literal l);
void creatNode(node ** n,Clause * c);
void creatEmptyNode(node ** n);


#endif
