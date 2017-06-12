#include "tache.h"

char* enum_statut_to_string(Type_statut_tache t){
      switch(t){
         case en_cours:
            return "en cours";
         case attente:
            return "attente";
         case terminee:
            return "terminee";
      }
 }
