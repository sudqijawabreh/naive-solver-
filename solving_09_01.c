#include"vecInt.h"
#include"solving_07_01.h"
#include"solving_07_02.h"
#include"solving_09_01.h"




/**
 * Return all indexes clauses of the literal l in the formula f
 * @param f : the formula
 * @param l : the literal
 * @return a pointer on all occurences of the literal l in the formula f
 */

vecInt* getOccurrences(Formula f, Literal l) {
	/*vecInt * occ=(vecInt *)malloc(sizeof(vecInt));
	createEmptyVec(f.nbVariables,occ);
	for (int i = 0; i <f.nbClauses ; i++)
	{
		
		for(int j=0;j<f.clauses[i].size;j++)
		if(f.clauses[i].datas[j]==l)addLast(occ,i);
	}
	return occ;*/
	/*int v=getVariable(l);
	if(l>0)
	return &f.literalOccurrences[2*(v-1)];
	if(l<0)
	return &f.literalOccurrences[2*(v-1)+1];*/
	//return f.literalOccurrences[literalIdx(l)]);
	
}



/***********************************************************/

// ----- BE CAREFUL : EXERCISE 2, do not touch before!

/***********************************************************/





/**
 * Used to retrieve occurences of v and \not v
 */
// I suppose occurences[v] is at position 2*(v-1)
// occurences[-v] is at position 2*(v-1)+1

int positiveVariableIdx(Variable v) {
	return 2*(v-1);
}

int negativeVariableIdx(Variable v) {
	return 2*(v-1)+1;
}

/**
 * Used to retrieve occurences of l and \not l
 * If l is positive produces same results as before
 * If l is negative provides the opposite
 */

int literalIdx(Literal l) {
	if(l>0)return positiveVariableIdx(l);
	return negativeVariableIdx(-l);
}
int oppositeLiteralIdx(Literal l) {
	if(l>0)return negativeVariableIdx(l);
	return positiveVariableIdx(-l);
}







