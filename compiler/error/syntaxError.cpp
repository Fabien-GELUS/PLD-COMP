/*************************************************************************
                           SyntaxError  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <SyntaxError> (fichier SyntaxError.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "syntaxError.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type SyntaxError::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
ostream & operator << (ostream & os, const SyntaxError & error){
  os << "Error " << error.message << endl;
  os << "On position " << error.lineNumber << ":" << error.charPositionInLine << endl;
  return os;
}

//-------------------------------------------- Constructeurs - destructeur
SyntaxError::SyntaxError ( const SyntaxError & unSyntaxError )
// Algorithme :
//
{
  recognizer = unSyntaxError.recognizer;
  offendingSymbol = unSyntaxError.offendingSymbol;
  lineNumber = unSyntaxError.lineNumber;
  charPositionInLine = unSyntaxError.charPositionInLine;
  message = unSyntaxError.message;
  e = unSyntaxError.e;
#ifdef MAP
    cout << "Appel au constructeur de copie de <SyntaxError>" << endl;
#endif
} //----- Fin de SyntaxError (constructeur de copie)


SyntaxError::SyntaxError ( Recognizer *recognizerA, Token * offendingSymbolA, size_t lineNumberA, size_t charPositionInLineA,
   const std::string & msgA, std::exception_ptr eA)
// Algorithme :
//
{
 recognizer = recognizerA;
 lineNumber = lineNumberA;
 charPositionInLine = charPositionInLineA;
 message = msgA;
 e = eA;

#ifdef MAP
    cout << "Appel au constructeur de <SyntaxError>" << endl;
#endif
} //----- Fin de SyntaxError (constructeur de copie)



SyntaxError::~SyntaxError ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <SyntaxError>" << endl;
#endif
} //----- Fin de ~SyntaxError


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
