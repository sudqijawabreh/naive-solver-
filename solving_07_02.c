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


void createFormula(Formula *f,int nbClauses,int nbVariables) {
   f->nbClauses = nbClauses;
   f->nbVariables = nbVariables;
   f->clauses = (Clause*) malloc(sizeof(Clause)*nbClauses);
   f->literalOccurrences=(Occurrences *) malloc(sizeof(Occurrences)*nbVariables*2);
   

   for(int i = 0;i<nbClauses;i++) 
    createClause(*f,i);
    for (int i = 0; i < nbVariables*2; i++)
	{
		createEmptyVec(f->nbVariables*2,&(f->literalOccurrences[i]));
	}
	

}

void freeFormula(Formula *f) {
  for(int i = 0;i<f->nbClauses;i++) 
    freeVec(&(f->clauses[i]));
  free(f->clauses);
 
  for(int i = 0;i<f->nbVariables*2;i++) 
    freeVec(&(f->literalOccurrences[i]));
     free(f->literalOccurrences);
}

/*****************************************************
 * Create space for clause 
 * The default space allocated will be DEFAULTSIZE
 * @param f the formula
 * @param clauseNumber (the position)

 */
void createClause(Formula f,int clauseNumber) {
  assert(clauseNumber < f.nbClauses);
  createEmptyVec(DEFAULTSIZE,&(f.clauses[clauseNumber]));
}

/*****************************************************
 * insert a literal l in a given clause
 * @param f the formula
 * @param clauseNumber (the position)
 * @param Literal l
 */
void addLiteralInClause(Formula f,int clauseNumber, Literal l) {
  assert(clauseNumber < f.nbClauses);
  addLast(&(f.clauses[clauseNumber]),l);
  int v=getVariable(l);
  if(l>0)
  addLast(&(f.literalOccurrences[2*(v-1)]),clauseNumber);
  if(l<0)
    addLast(&(f.literalOccurrences[2*(v-1)+1]),clauseNumber);
}


void importDimacs(char * name,Formula * f){
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
	createFormula(f,nbClauses,nbVariables);
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
	

}
void exportDimacs(char *name,Formula *f){
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
	
}










