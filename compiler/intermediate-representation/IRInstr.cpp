/*************************************************************************
                           IRInstr  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <IRInstr> (fichier IRInstr.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "IR.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type IRInstr::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void IRInstr::gen_asm(ostream &o){ /**< x86 assembly code generation for this IR instruction */
  string operation = "";
  switch (op) {
    case ldconst:
      operation = "ldconst"; //à implementer
      break;
		case add:
      operation = "addl";
      break;
		case sub:
      operation = "subl";
      break;
		case mul:
      operation = "imul";
      break;
		case rmem:
      operation = "movl";
      break;
		case wmem:
      operation = "movl";
      break;
		case call:
      operation = "call"; //à implementer
      break;
		case cmp_eq:
      operation = "cmp_eq"; //à implementer
      break;
		case cmp_lt:
      operation = "cmp_lt"; //à implementer
      break;
		case cmp_le:
      operation = "cmp_le"; //à implementer
      break;
  }

  o << "  " << operation;
  for(vector<string>::iterator it = params.begin(); it != params.end(); it++ ){
    o << " " <<  *it;
  }
  o << endl;
}

bool IRInstr::isComp(){
  return (op == cmp_eq)||(op == cmp_lt)||(op == cmp_le);
}

//------------------------------------------------- Surcharge d'opérateurs
//-------------------------------------------- Constructeurs - destructeur
IRInstr::IRInstr (SymbolTable * symbolTable_, Operation op_, Type t_, vector<string> params_)
// Algorithme :
//
{
  symbolTable = symbolTable_;
  op = op_;
  t  = t_;
  params = params_;
} //----- Fin de IRInstr


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
