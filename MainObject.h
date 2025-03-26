#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "CommonFunc.h"
#include "BaseObject.h"
#include "BulletObject.h"
#include <vector>

#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 10
#define PLAYER_JUMP 16

class MainObject : public BaseObject{
public:
    MainObject();
    ~MainObject();

    enum WalkType{
        WALK_NONE = 0,
        WALK_RIGHT = 1,
        WALK_LEFT = 2,
    };
    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void set_clip();

    void DoPlayer(Map& data);
    void CheckToMap(Map& data);
    void SetMapXY(const int map_x, const int map_y){
        map_x_ = map_x;
        map_y_ = map_y;
    };
    void CenterEntityOnMap(Map &data);
    void UpdateImagePlayer(SDL_Renderer* des);

    void set_buller_list(std::vector<BulletObject*> bullet_list){
        p_bullet_list_ = bullet_list;
    }
    std::vector<BulletObject*> get_bullet_list() const{
        return p_bullet_list_;
    }
    void HandleBullet(SDL_Renderer* des);
private:
    std::vector<BulletObject*> p_bullet_list_;
    float x_val_;
    float y_val_;

    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;

    SDL_Rect frame_clip_[8];
    Input input_type_;
    int frame_;
    int status_;
    bool on_ground_;

    int map_x_;
    int map_y_;

    int come_back_time_;
};

#endif // MAIN_OBJECT_H
