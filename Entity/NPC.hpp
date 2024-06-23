#pragma once
#include "Entity.hpp"

class NPC : public Entity
{
protected:
    int levelRequest;
    double exp;
public:
    NPC() : Entity(), levelRequest(0), exp(0) {};
    void setLevelRequest(int levelRequest) { this->levelRequest = levelRequest; }
    int getLevelRequest() const { return levelRequest; }
    void setExp(double exp) { this->exp = exp; }
    double getExp() const { return exp; }
};