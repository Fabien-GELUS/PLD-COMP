/*************************************************************************
                           CFG  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <CFG> (fichier CFG.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "CFG.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type CFG::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
BasicBlock* CFG::createNewBB(){
  current_bb  = new BasicBlock(newBBName());
  nextBBnumber++;
  bbs.push_back(current_bb);
  return current_bb;
}

void CFG::genAsm(ostream& o){
  o << name << ":" << endl;

  int blocNumber = 1;
  for(vector<BasicBlock*>::iterator it = bbs.begin(); it != bbs.end(); it++){
    o << "." << (*it)->getLabel() << ":" << endl;
    if(blocNumber == 1){
      genAsmPrologue(o);
    }
    (*it)->genAsm(o);
    blocNumber++;
  }


}

void CFG::enteringNewScope(){
  scopeNumber++;
  currentSymbolTable = new SymbolTable();
  symbolTableStack.push_back(currentSymbolTable);
}

void CFG::exitScope(){
  if(scopeNumber > 1){
    currentSymbolTable = (*symbolTableStack.rbegin() - 1);
    symbolTableStack.pop_back();
    scopeNumber--;
  }
}


// symbol table methods
void CFG::addToSymbolTable(string name, Type t){
  currentSymbolTable->addVariable(name, t, nextFreeSymbolIndex);
  nextFreeSymbolIndex -= 4;

}

// symbol table methods
void CFG::addArrayToSymbolTable(string name, Type t, int size){
  currentSymbolTable->addArray(name, t, size, nextFreeSymbolIndex);
  nextFreeSymbolIndex -= (4*size);

}

string CFG::createNewTempvar(Type t){
  string name = "!" + to_string(numberTempVar);

  currentSymbolTable->addVariable(name, t, nextFreeSymbolIndex);
  nextFreeSymbolIndex -= 4;

  //Variable var(name, t, nextFreeSymbolIndex);
  //nextFreeSymbolIndex += 4;
  //currentSymbolTable->addVariable(var);

  numberTempVar++;
  return name;
}

string CFG::deleteLastTempvar(Type t){
  numberTempVar--;
  string name = "!" + to_string(numberTempVar);

  currentSymbolTable->removeVariable(name);

  return name;
}

bool CFG::isVarExist(string var){
  for(vector<SymbolTable*>::reverse_iterator it = symbolTableStack.rbegin(); it != symbolTableStack.rend(); ++it ){
    if((*it)->variableExiste(var)){
      return true;
    }
  }
  return false;
}

bool CFG::isVarExistInScope(string var){
  vector<SymbolTable*>::reverse_iterator it = symbolTableStack.rbegin();
  if((*it)->variableExiste(var)){
    return true;
  }
  return false;
}

bool CFG::isDefined(string var){
  Variable* varPt = getVariable(var);
  return varPt->isDefined();
}

void CFG::setDefined(string var){
  Variable* varPt = getVariable(var);
  varPt->setDefined();
}

string CFG::varToAsm(string var){
  for(vector<SymbolTable*>::reverse_iterator it = symbolTableStack.rbegin(); it != symbolTableStack.rend(); ++it ){
    if((*it)->variableExiste(var)){
      return (*it)->varToAsm(var);
    }
  }
  return "";
}

string CFG::arrayToAsm(string arrayName, int index){
  for(vector<SymbolTable*>::reverse_iterator it = symbolTableStack.rbegin(); it != symbolTableStack.rend(); ++it ){
    if((*it)->variableExiste(arrayName) && (*it)->isArray(arrayName)){
      return (*it)->arrayToAsm(arrayName, index);
    }
  }
  return "";
}

Variable* CFG::getVariable(string var){
  for(vector<SymbolTable*>::reverse_iterator it = symbolTableStack.rbegin(); it != symbolTableStack.rend(); ++it ){
    if((*it)->variableExiste(var)){
      return (*it)->getVariable(var);
    }
  }
  return nullptr;
}

string CFG::getName(){
  return name;
}


//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

CFG::CFG(string name_)
// Algorithme :
//
{
  #ifdef MAP
      cout << "Appel au constructeur de <CFG>" << endl;
  #endif
  name = name_;
  numberTempVar = 0;
  nextBBnumber = 0;
  current_bb = nullptr;
  scopeNumber = 1;
  nextFreeSymbolIndex = -4;

  if (SymbolTable::getGlobalVariablesST() != nullptr){
    symbolTableStack.push_back(SymbolTable::getGlobalVariablesST());
  }

  currentSymbolTable = new SymbolTable();
  symbolTableStack.push_back(currentSymbolTable);
} //----- Fin de CFG


CFG::~CFG ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <CFG>" << endl;
#endif
  for(auto it = bbs.begin(); it != bbs.end(); ++it){
    delete *it;
  }

} //----- Fin de ~CFG


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void CFG::genAsmPrologue(ostream& o){
  o << "  #prologue" << endl;
  o <<"  pushq %rbp\n"      //save %rbp on the stack
      "  movq %rsp, %rbp\n"; //define %rbp for the current function
}

// basic block management
string CFG::newBBName(){
  return name+to_string(nextBBnumber);
}
