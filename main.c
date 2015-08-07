#include"vecInt.h"
#include"solving_07_01.h"
#include"solving_07_02.h"
#include"solving_08_01.h"
#include"stdio.h"
#include"assert.h"
#include"string.h"
#include<stdlib.h>
#include<stdio.h>
#include"solving_01_04_modify.h"
#include<time.h>
// generate all possible Interpretations and check if the formula satisfiable
int generateAndCheck(Formula f,Interpretation  v,int size){
	if(size==0)return TRUE;
	assert(size>0);
	assert(v.size>=size);
	assert(v.size>0);
	int zero=FALSE;
	int one=FALSE;
	
	v.datas[size]=0;
	zero=generateAndCheck(f,v,size-1);//generate first part and check if it satisfaies the formula 
	if(size==1){
		for (int i =1;i<v.size ;i++)// printing the interpretation
		{
				printf("%d ",v.datas[i]);
		}
		printf("\n");
		zero=isSatisfiedFormula(f,v);
	}
	assert(zero==TRUE||zero==FALSE);
	if(zero==TRUE)return TRUE;
	
	
	v.datas[size]=1;
	one=generateAndCheck(f,v,size-1); //generate second part and check if it satisfaies the formula 
	if(size==1){
		for (int i =1;i<v.size ;i++)// printing the interpretation
		{
				printf("%d ",v.datas[i]);
		}
		printf("\n");
		one=isSatisfiedFormula(f,v);
	
	}
	assert(one==TRUE||one==FALSE);
	
	return one || zero;
	
}

int  main(int argc, char const *argv[])
{
	Formula f;
	Interpretation I;
	srand(clock());
	createAndInitializeInterpretation(&I,10);
	// generateRandomComplete(I);
	generateFullRandomFormula(&f,10,50);
	printf("check %d\n",generateAndCheck(f,I,10));
	displayFormula(f,I);
	printf("isSAT %d\n", isSatisfiedFormula(f,I));
	node *p =f.clauses;
	/*while(p!=NULL){
		for (int i = 0; i < p->clause->size; ++i)
		{
			printf("%d ",p->clause->datas[i]);
		}
		printf("0\n");
		p=p->next;
	}*/
	// importDimacs("1.cnf",&f);
/*	createFormula(&f,3);
	Clause * c;
	createClause(&c);
	addClause(&f,c);
	addLiteralInClause(f,c,-1);
	addLiteralInClause(f,c ,2);
	printf("%d\n",f.clauses->clause->datas[-1] );
	printf("%d\n",f.literalOccurrences[literalIdx(2)]->clause->datas[0]);
	
*/	printf("%d\n",f.nbClauses);
	exportDimacs("2.cnf",&f);
	freeFormula(&f);
	return 0;
}