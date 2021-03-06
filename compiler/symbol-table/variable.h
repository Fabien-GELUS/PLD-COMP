/*************************************************************************
                           Variable  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Variable> (fichier Variable.h) ----------------
#if ! defined ( VARIABLE_H )
#define VARIABLE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "type.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Variable>
//
// Cette classe correspond a l'objet represetant toues les informations d'une
// variable. Elle contient toutes les donnees nécessaires concernant les
// variables pendant la compilation.
//
//------------------------------------------------------------------------
class Variable
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  string getName()
  {
    return this->name;
  }

  Type getType()
  {
    return this->type;
  }

  virtual string getAddress() = 0;

  void setDefined()
  {
    defined = true;
  }

  bool isDefined()
  {
    return defined;
  }

  bool isArray()
  {
    return (this->type == INT_ARRAY);
  }

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    // Variable (const Variable & unVariable);
    Variable ();

    Variable (string name, Type type) : name(name), type(type), defined(false){}

    virtual ~Variable ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  string name;
  Type type;
  bool defined;

};

//-------------------------------- Autres définitions dépendantes de <Variable>

#endif // VARIABLE_H
