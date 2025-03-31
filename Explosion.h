#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include "CommonFunc.h"
#include "BaseObject.h"

#define NUM_FRAME_EXP 8

class ExplosionObject : public BaseObject{
public:
    ExplosionObject();
    ~ExplosionObject();

public:
    void set_clip();
    void set_frame(const int&fr){
        frame_ = fr;
    }
    virtual bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* screen);
    int get_frame_width() const{
        return width_frame_;
    }
    int get_frame_height() const{
        return height_frame_;
    }

private:
    int width_frame_;
    int height_frame_;

    unsigned int frame_;
    SDL_Rect frame_clip_[8];
};
#endif // EXPLOSION_H_
