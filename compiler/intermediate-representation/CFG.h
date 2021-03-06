/*************************************************************************
                           CFG  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <CFG> (fichier CFG.h) ----------------
#if ! defined ( CFG_H )
#define CFG_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>

#include "BasicBlock.h"
#include "IRInstr.h"

#include "../symbol-table/symbolTable.h"
#include "../symbol-table/variable.h"
#include "../symbol-table/array.h"
#include "../symbol-table/type.h"


/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
	 The entry block is the one with the same label as the AST function name.
	   (it could be the first of bbs, or it could be defined by an attribute value)
	 The exit block is the one with both exit pointers equal to nullptr.
     (again it could be identified in a more explicit way)

 */
class CFG {
 public:
	CFG(string name);
  virtual ~CFG ( );


	BasicBlock* createNewBB();

	// x86 code generation: could be encapsulated in a processor class in a retargetable compiler
	void genAsm(ostream& o);

  // scope variable management
  void enteringNewScope();
  void exitScope();


	// symbol table methods
	void addToSymbolTable(string name, Type t);
	void addArrayToSymbolTable(string name, Type t, int size);
	string createNewTempvar(Type t);
  string deleteLastTempvar(Type t);
  bool isVarExist(string var);
  bool isVarExistInScope(string var);
  bool isDefined(string var);
  void setDefined(string var);
  string varToAsm(string var);
  string arrayToAsm(string arrayName, int index);
  Variable* getVariable(string var);
  string getName();

	// basic block management
	BasicBlock* current_bb;


 protected:
  void genAsmPrologue(ostream& o);
  string newBBName();

  vector<SymbolTable*> symbolTableStack; // stack of symbol table. Access the last in first.
  SymbolTable* currentSymbolTable;
  string name;
  int numberTempVar;
	int nextBBnumber; /**< just for naming */
  int nextFreeSymbolIndex; /**< to allocate new symbols in the symbol table */

  int scopeNumber;
	vector <BasicBlock*> bbs; /**< all the basic blocks of this CFG*/
};

//-------------------------------- Autres définitions dépendantes de <CFG>

#endif // CFG_H
