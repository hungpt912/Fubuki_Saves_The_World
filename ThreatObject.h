#ifndef THREAT_OBJECT_H_
#define THREAT_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"
#include "BulletObject.h"

#define THREAT_FRAME_NUM 8
#define THREAT_GRAVITY 0.8
#define THREAT_MAX_FALL_SPEED 18
#define THREAT_SPEED 3

class ThreatsObject : public BaseObject{
public:
    ThreatsObject();
    ~ThreatsObject();

    enum TypeMove{
        STATIC_THREAT = 0,
        MOVE_IN_SPACE_THREAT = 1,
    };

    void set_x_val(const float& xval){
        x_val_ = xval;
    }

    void set_y_val(const float& yval){
        y_val_ = yval;
    }

    void set_x_pos(const float& xp){
        x_pos_ = xp;
    }

    void set_y_pos(const float& yp){
        y_pos_ = yp;
    }

    float get_y_pos(){
        return y_pos_;
    }
    float get_x_pos(){
        return x_pos_;
    }

    void SetMapXY(const int& map_x, const int& map_y){
        map_x_ = map_x;
        map_y_ = map_y;
    }

    void set_clips();
    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    int get_width_frame() const {return width_frame_;}
    int get_height_frame() const {return height_frame_;}
    void DoPlayer(Map& gMap);
    void CheckToMap(Map& gMap);

    void set_type_move(const int& typeMove){
        type_move_ = typeMove;
    }
    void SetAnimationPos(const int& pos_a, const int& pos_b){
        animation_a_ = pos_a;
        animation_b_ = pos_b;
    }
    void set_input_left(const int& ipLeft){
        input_type_.left_ = ipLeft;
    }
    void ImpMoveType(SDL_Renderer* screen);
    void InitThreats();

    std::vector<BulletObject*> get_bullet_list() const{
        return bullet_list_;
    }

    void set_bullet_list(const std::vector<BulletObject*>& bl_list){
        bullet_list_ = bl_list;
    }
    void InitBullet(BulletObject *p_bullet, SDL_Renderer* screen);
    void MakeBullet(SDL_Renderer* screen, const int& x_limit, const int& y_limit);
private:
    int map_x_;
    int map_y_;
    int frame_;
    int width_frame_;
    int height_frame_;
    SDL_Rect frame_clip_[THREAT_FRAME_NUM];
    bool on_ground_;
    int come_back_time_;
    float x_pos_;
    float y_pos_;
    float x_val_;
    float y_val_;

    int type_move_;
    int animation_a_;
    int animation_b_;
    Input input_type_;

    std::vector<BulletObject*> bullet_list_;
};
#endif // THREAT_OBJECT_H
