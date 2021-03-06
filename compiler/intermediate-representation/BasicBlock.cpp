/*************************************************************************
                           BasicBlock  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <BasicBlock> (fichier BasicBlock.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "BasicBlock.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void BasicBlock::genAsm(ostream &o){ /**< x86 assembly code generation for this basic block (very simple) */
  for(vector<IRInstr*>::iterator it = instrs.begin(); it != instrs.end(); it++){
    (*it)->genAsm(o);
  }

  if(exit_true == nullptr){
    genAsmEpilogue(o);
  } else if(exit_false != nullptr && instrs.back()->isComp() ){
    // deux branches conditionnelles sur la valeur de la dernière variable assignée
    string opTrue, opFalse;
    IRInstr* lastInstr = instrs.back();

    int compType = lastInstr->compType();
    if (compType == 1) {
      opTrue = "je";
      opFalse = "jne";
    }
    else if (compType == 2) {
      opTrue = "jl";
      opFalse = "jge";
    }
    else if (compType == 3) {
      opTrue = "jle";
      opFalse = "jg";
    }

    o << "  " << opTrue << " ." << exit_true->getLabel() << endl;
    o << "  " << opFalse << " ." << exit_false->getLabel() << endl;
  } else {
    // saut inconditionel vers la true branch
    o << "  jmp ." << exit_true->getLabel() << endl;
  }
  o << endl;
}

void BasicBlock::addIRInstr(IRInstr::Operation op, Type t, vector<string> params){
  IRInstr* newInstr = new IRInstr(op, t, params);
  instrs.push_back(newInstr);

}
void BasicBlock::genAsmEpilogue(ostream& o){
cout << "\n  # epilogue\n"
        "  popq %rbp\n" //restore %rbp from the stack
        "  ret\n";      //return to the caller (here the shell)
}

void BasicBlock::setExitTrueBlock(BasicBlock* exit_true_){
  exit_true = exit_true_;
}
void BasicBlock::setExitFalseBlock(BasicBlock* exit_false_){
  exit_false = exit_false_;
}

string BasicBlock::getLabel(){
  return label;
}


//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur

BasicBlock::BasicBlock (string entry_label)

{
  exit_true = nullptr;
  exit_false = nullptr;
  label = entry_label;
} //----- Fin de BasicBlock


BasicBlock::~BasicBlock ( )
{
  for(auto it = instrs.begin(); it != instrs.end(); ++it){
    delete *it;
  }

} //----- Fin de ~BasicBlock


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
