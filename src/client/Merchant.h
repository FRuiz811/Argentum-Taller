#ifndef MERCHANT_H
#define MERCHANT_H

#include "Character.h"
#include "TextureManager.h"
#include "Items/MerchantBody.h"

union SDL_Event;


class Merchant: public Character {
private:
	MerchantBody body;

public:
	Merchant(const TextureManager& manager, int posX, int posY);

	virtual void render(Camera& camera);
	virtual void update(double dt);

	void handleEvent(SDL_Event& event);

	~Merchant();
};

#endif
