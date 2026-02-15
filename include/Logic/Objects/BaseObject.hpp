#pragma once
#include <Utils/Vec.hpp>
#include <Graphic/Sprite/Sprite.hpp>

class BaseObject{
//Accessible par tous
public:
    BaseObject();
    BaseObject(const Vec& pos_initial);
    virtual ~BaseObject();
    virtual void Update(double dt);
    bool IsActive() const;
    virtual void SetActivity(bool new_activity);
    virtual Vec GetPos() const;
    virtual void SetPos(const Vec& new_pos);
    void SetSprite(const Sprite& new_sprite);
    Sprite GetSprite() const;
    void FreeRessources();
    // Accessible par les héritiers et soi-même
    int draw_id = -1; // Id in the draw heap, -1 if not in the draw heap
protected:
    Vec pos;
    bool is_active;
    Sprite sprite;
    // Accessible par soi-même
private:
};