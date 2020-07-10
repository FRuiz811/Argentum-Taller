#ifndef ITEMTRANSLATOR_H
#define ITEMTRANSLATOR_H

#include "../common/Identificators.h"

class ItemTranslator {
public:
    ItemTranslator();

    static ItemsInventoryID weaponToItem(WeaponID weapon);
    static ItemsInventoryID shieldToItem(ShieldID shield);
    static ItemsInventoryID bodyToItem(BodyID body);
    static ItemsInventoryID helmetToItem(HelmetID helmet);

    static WeaponID itemToWeapon(ItemsInventoryID item);
    static ShieldID itemToShield(ItemsInventoryID item);
    static BodyID itemToBody(ItemsInventoryID item);
    static HelmetID itemToHelmet(ItemsInventoryID item);

    ~ItemTranslator();
};

#endif
