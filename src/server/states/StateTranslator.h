#ifndef ARGENTUM_TALLER_STATETRANSLATOR_H
#define ARGENTUM_TALLER_STATETRANSLATOR_H


#include "../../common/Identificators.h"

class StateTranslator {
public:
    StateTranslator();

    static CharacterStateID stateToCharacterState(StateID stateId);

    virtual ~StateTranslator();
};


#endif //ARGENTUM_TALLER_STATETRANSLATOR_H
