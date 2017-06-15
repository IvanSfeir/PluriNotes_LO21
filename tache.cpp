#include "tache.h"

string enum_statut_to_string(Type_statut_tache t){
      switch(t){
         case en_cours:
            return "en cours";
         case attente:
            return "attente";
         case terminee:
            return "terminee";
      }
 }


Type_statut_tache string_to_enum_statut(const string &s){
    if(s=="en cours")
        return en_cours;
    if(s=="attente")
        return attente;
    if(s=="terminee")
        return terminee;

}

QString enum_statut_to_qstring(Type_statut_tache t){
      switch(t){
         case en_cours:
            return "en cours";
         case attente:
            return "attente";
         case terminee:
            return "terminee";
      }
 }


Type_statut_tache qstring_to_enum_statut(const QString &s){
    if(s=="en cours")
        return en_cours;
    if(s=="attente")
        return attente;
    if(s=="terminee")
        return terminee;

}
