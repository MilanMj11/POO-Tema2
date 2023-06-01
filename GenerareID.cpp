#include "GenerareID.h"

int GenerareID::nextID = 0;

int GenerareID::getID() {
    return nextID++;
}