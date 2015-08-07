#include"vecInt.h"
#include"solving_07_01.h"
#include"solving_07_02.h"
#include"stdio.h"
#include"assert.h"
#include"string.h"
#include"stdlib.h"
#include"stdio.h"

typedef vecInt Occurrences;
/**

/*****************************************************
 * Create the memory space for a formula f
 * 
 */
 /**
 * We suppose the string is trimmed 
 * Otherwise: http://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
 * @return -1 if OK, the position of the error otherwise
 */
int str2int(char *str,int *value) {
  *value = 0;
  int sign=(str[0]=='-' ? -1 : 1);
  for(int i=(str[0]=='-' ? 1 : 0);str[i]!=0;i++) {
    if(!(str[i]>=48 && str[i]<=57)) // Ascii char 0 to 9
      return i;
    *value= *value*10+(str[i]-48);
  }
  *value = *value * sign;
  return -1;
}

int extractWord(FILE *f,char *buffer) {
  int i = 0;char c;
  // skip space, tab, \n...
  do {
    c = fgetc(f);
  } while(c==' '  || c==10  || c==13 || c=='\t');
  if(c==EOF) {
    buffer[i]=0;// Finish the empty word
    return 1;
  }
  do {
    buffer[i++] = c;
    c = fgetc(f);
    if(c==EOF) break;
  } while(c!=' ' && c!=10 && c!='\t' && c!=13);
  
  buffer[i] = 0;
  return c==EOF;
}


void createFormula(Formula *f,int nbVariables) {
   f->nbClauses = 0;
   f->nbVariables = nbVariables;
   f->clauses = NULL; // head of linked list 
   f->literalOccurrences=(Occurrences **) malloc(sizeof(Occurrences*)*nbVariables*2); 
   

    for (int i = 0; i < nbVariables*2; i++)
	{
		f->literalOccurrences[i]=NULL;
	}
	

}

void freeFormula(Formula *f) {
 
}

/*****************************************************
 * Create space for clause 
 * The default space allocated will be DEFAULTSIZE
 * @param f the formula
 * @param clauseNumber (the position)

 */
 // creat Clause with type vecInt 
 // c can't be NULL
void createClause(Clause ** c) {
	assert(c!=NULL);
	*c=(Clause *)malloc(sizeof(Clause));
	createEmptyVec(DEFAULTSIZE,*c);
  	assert(*c!=NULL);
}

/*****************************************************
 * insert a literal l in a given clause
 * @param f the formula
 * @param clauseNumber (the position)
 * @param Literal l
 */
 // add literal to clause and clause to literal occurances list
 // c can't be NULL and l can't be zero 
void addLiteralInClause(Formula f, Clause * c, Literal l) {
	assert(l!=0);
	assert(c!=NULL);
  	addLast(c,l);
  	addOccurance(f,c,l);
}


void importDimacs(char * name,Formula * f){/*
	FILE * file=NULL;
	file=fopen(name,"r");
	if(file==NULL)exit(1);
	char * word=(char *)malloc(sizeof(char)*100);
	char c;
	extractWord(file,word);
	while(strcmp(word,"c")==0){
		c=fgetc(file);
		while(c!=13&& c!=10){c=fgetc(file);}
		extractWord(file,word);
	}
	//while(stcmp(word,"p")==0){fgetc(file);}
	extractWord(file,word);
	extractWord(file,word);
	int nbVariables ;
	str2int(word,&nbVariables);
	extractWord(file,word);
	int nbClauses;
	str2int(word,&nbClauses);
	//createFormula(f,nbClauses,nbVariables);
	int value=0;
	
	for (int i = 0;i<f->nbClauses ; i++)
	{
		extractWord(file,word);
		while(1){
			
			
			if(word[0]==EOF)return;
			str2int(word,&value);
			addLiteralInClause(*f,i,value);
			if(word[0]=='0')break;
			extractWord(file,word);
		}
		 
	}
	

*/}
void exportDimacs(char *name,Formula *f){/*
		FILE * file=NULL;
		file=fopen(name,"w");
		if(file==NULL)exit(1);
		fprintf(file,"p cnf %d %d \n",f->nbVariables,f->nbClauses);
		
		for(int i=0;i<f->nbClauses;i++){
		for(int j=0;j<f->clauses[i].size;j++){
			fprintf(file,"%d ",f->clauses[i].datas[j]);
		}
		fprintf(file,"\n");
	}
	
*/}
// malloc n and initilaize  clause,next to NULL
// n can't be NULL
void createEmptyNode(node ** n ){
	*n=(node *)malloc(sizeof(node));
	assert(*n!=NULL);
	(*n)->clause=NULL;
	(*n)->next=NULL;
}
// creat new Node and assigne clause 
// c and n  can't be NULL
void creatNode(node ** n,Clause * c){
	createEmptyNode(n);
	(*n)->clause=c;
	
}
// add clause to formula and increament # clauses 
void addClause(Formula * f, Clause * c){
	if(c==NULL)return ;
	node * n;
	creatNode(&n,c);
	assert(n!=NULL);
	n->next=f->clauses;
	f->clauses=n;
	f->nbClauses++;

	assert(f->clauses==n);

}
// addclause to the literal linked list
// clause can't be NULL
// l can't be 0 
void addOccurance(Formula f, Clause * c,Literal l){
	assert(c!=NULL);
	assert(l!=0);
	f.literalOccurrences[literalIdx(l)];
	node * n;
	creatNode(&n,c);
	assert(n!=NULL);
	n->next=f.literalOccurrences[literalIdx(l)];
	f.literalOccurrences[literalIdx(l)]=n;
	assert(f.literalOccurrences[literalIdx(l)]==n);


}









