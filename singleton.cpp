#include <iostream>
#include <string>

class GameSetting{
    static GameSetting* _instance;

    int _brightness;
    int _width;
    int _height;
    GameSetting():_brightness(100), _width(200), _height(300){}

    public:
    void setBrightness(int b){_brightness=b;}
    void setWidth(int w){_width=w;}
    void setHeight(int h){_height=h;}
    
    int getBrightness(){return _brightness;}
    int getWidth(){return _width;}
    int getHeight(){return _height;}

    static GameSetting* getInstance(){
        if (_instance == NULL)
            _instance = new GameSetting();
        return _instance;
    }

    void displayInstance(){
        std::cout<<"b, w, h"<<_brightness<<_width<<_height<<std::endl;
    }
};

GameSetting* GameSetting::_instance = NULL;

int main(){
    GameSetting* setting = GameSetting::getInstance();
    setting->displayInstance();

    GameSetting* setting1 = GameSetting::getInstance();
    setting1->displayInstance();

    setting1->setBrightness(10000);

    setting->displayInstance();
    setting1->displayInstance();
    return 0;
}