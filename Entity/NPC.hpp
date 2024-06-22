#pragma once
#include "Entity.hpp"

class NPC : public Entity
{
protected:
    int levelRequest;
    double Exp;
public:
    NPC() : Entity(), levelRequest(0), Exp(0) {};
    void setLevelRequest(int levelRequest) { this->levelRequest = levelRequest; }
    int getLevelRequest() const { return levelRequest; }
};