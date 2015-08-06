#include "solving_08_01.h"
#include "solving_07_01.h"
#include "solving_07_02.h"
#include <assert.h>

/**
 * give the status of a clause under a given interpretation
 * @param c the clause
 * @parm I the interpretation
 * @return TRUE if it is satisfied, FALSE if it is falsified, UNDEF if one can not answer this question
 */
int statusClause(Clause c,Interpretation I){
	int value;
	int nbFalse=0;
		for ( int  i = 0; i < c.size; i++)
		{
			
			value=getValueLiteral(I,c.datas[i]);
			if(value==TRUE)return TRUE;
			if(value==FALSE)nbFalse++;
		}
		if(nbFalse==c.size)return FALSE;
		return UNDEF;
		
}
int isSatisfiedClause(Clause c,Interpretation I){
	if(statusClause(c,I)==TRUE)return TRUE;
	return FALSE;
}
int isFalsifiedClause(Clause c,Interpretation I){
		if(statusClause(c,I)==FALSE)return TRUE;
		return FALSE;
}
int isUndefClause(Clause c,Interpretation I){
	if(statusClause(c,I)==UNDEF)return TRUE;
		return FALSE;
}
int isUnit(Clause c,Interpretation I){
	int nbUndef=0;
	int nbFalse=0;
	int value;
	for (int i = 0; i <c.size ; i++)
	{
		value=getValueLiteral(I,c.datas[i]);
		if(value==FALSE)nbFalse++;
		if(value==UNDEF)nbUndef++;
	}
	if(c.size-1==nbFalse&&nbUndef==1){
			//assert(isUndefClause(c,I)==TRUE);
			return TRUE;
		}
	return FALSE;
	
}

/**
 * Display a clause under a given interpretation
 * You can print colors on terminal 
 * see http://www.daniweb.com/software-development/c/threads/266484/how-to-print-text-into-a-different-color-in-terminal
 * For example: 
 *  the literal is true in the clause : write in green
 *  the literal is false in the clause : write in red
 * the literal is undefined in the clause : write in blue
 * @param c the clause
 * @parm I the interpretation
 */ 
 void displayClause(Clause c,Interpretation I){
	 
	int value;
	for (int i = 0; i <c.size ; i++)
	{
		value=getValueLiteral(I,c.datas[i]);
		if(value==FALSE)printf("\033[22;31m%d,c.datas[i]");
		if(value==UNDEF)printf("\033[22;34m%d,c.datas[i]");
		if(value==TRUE)printf("\033[22;32m %d,c.datas[i]");
	}
	printf("\n");
}
/**
 * @param f the formula
 * @param I an interpretation 
 * @return TRUE if it is satisfied, FALSE if it is falsified, UNDEF if one can not answer this question
 */
int statusFormula(Formula f,Interpretation I){
	int nbSat=0;
	for (int i = 0; i < f.nbClauses; i++)
	{
		if(isSatisfiedClause(f.clauses[i],I)==TRUE)nbSat++;
		else if(isSatisfiedClause(f.clauses[i],I)==FALSE)return FALSE;
	}
	if(nbSat==f.nbClauses)return TRUE;
	return UNDEF;
}
int isSatisfiedFormula(Formula c,Interpretation I){
	if(statusFormula(c,I)==TRUE)return TRUE;
	return FALSE;
}
int isFalsifiedFormula(Formula c,Interpretation I){
	if(statusFormula(c,I)==FALSE)return TRUE;
	return FALSE;
}
int isUndefFormula(Formula c,Interpretation I){
	if(statusFormula(c,I)==UNDEF)return TRUE;
	return FALSE;
}
 void displayFormula(Formula f,Interpretation I){
	 for (int i = 0; i <f.nbClauses ; i++)
	 {
		 displayClause(f.clauses[i],I);
		
	 }
}
