#include"vecInt.h"
#include"solving_07_01.h"
#include"solving_07_02.h"
#include"stdio.h"
#include"assert.h"
#include"string.h"
#include"stdlib.h"
#include"stdio.h"

int  main(int argc, char const *argv[])
{
	Formula f;
	createFormula(&f,3);
	Clause * c;
	createClause(&c);
	addClause(&f,c);
	addLiteralInClause(f,c,-1);
	addLiteralInClause(f,c ,2);
	printf("%d\n",f.clauses->clause->datas[1] );
	printf("%d\n",f.literalOccurrences[literalIdx(2)]->clause->datas[1]);
	freeFormula(&f);
	return 0;
}