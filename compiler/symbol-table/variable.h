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

  string getType()
  {
    return this->type;
  }

  int getAddress()
  {
    return this->address;
  }




//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    // Variable (const Variable & unVariable);
    Variable ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    Variable (string name, string type, int address) : name(name), type(type), address(address){}
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Variable ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  string name;
  string type;
  int address;



};

//-------------------------------- Autres définitions dépendantes de <Variable>

#endif // VARIABLE_H