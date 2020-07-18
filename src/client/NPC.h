#ifndef NPC_H
#define NPC_H

#include "Character.h"
#include "Items/Item.h"
#include "TextureManager.h"
#include "MusicManager.h"
#include "../common/Identificators.h"
#include "../common/GameObjectInfo.h"
#include "characterStates/CharacterState.h"
#include <memory>

class NPC : public Character {
private:
    std::shared_ptr<CharacterState> state = nullptr;

    bool aItem{false};
    std::shared_ptr<Item> item = nullptr;
    void setState(CharacterStateID newState);
    void setItem(ItemsInventoryID itemId);
    MusicID selectSound();

public:
    NPC(const TextureManager& manager, const GameObjectInfo& gameObjectInfo, const MusicManager& mixer);

    virtual void render(Camera& camera);
	virtual void update(double dt);
    bool isItem() const;
    void updatePlayerInfo(const GameObjectInfo& info);
    CharacterStateID& getState() const;
    ~NPC();

};

#endif
