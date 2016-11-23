#include "LoginBoxComponent.h"

LoginBoxComponent::LoginBoxComponent() {
}

sf::FloatRect LoginBoxComponent::getGlobalBounds() const{
    return this->getTransform().transformRect(p_rect.getGlobalBounds());
}

LoginBoxComponent::~LoginBoxComponent() {
}
