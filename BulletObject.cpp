#include "BulletObject.h"

BulletObject::BulletObject(){
    x_val_ = 0;
    y_val_ = 0;
    is_move_ = false;
    bullet_type_ = SPHERE_BULLET;
}

BulletObject::~BulletObject(){

}

bool BulletObject::LoadBullet(SDL_Renderer* des){
    bool ret = false;
    if (bullet_type_ == SPHERE_BULLET){
        ret = LoadImg("img/bullet.png", des);
    } else if (bullet_type_ == PINK_BULLET){
        ret = LoadImg("img/bullet_pink.png", des);
    } else if (bullet_type_ == RED_BULLET){
        ret = LoadImg("img/bullet_red.png", des);
    } else if (bullet_type_ == GREEN_BULLET){
        ret = LoadImg("img/bullet_green.png", des);
    }
     else if (bullet_type_ == THREAT_BULLET){
        ret = LoadImg("img/bullet_threat.png", des);
    }
    return ret;
}

void BulletObject::HandleMove(const int& x_border, const int& y_border){
    if (bullet_dir_ == DIR_RIGHT){
        rect_.x += x_val_;
        if (rect_.x > x_border){
            is_move_ = false;
        }
    } else if (bullet_dir_ == DIR_LEFT){
        rect_.x -= x_val_;
        if (rect_.x < 0){
            is_move_ = false;
        }
    }
}
