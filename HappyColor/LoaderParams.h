/*
This class holds any values we need when creating our object exactly the same way
as a load function would do.
*/
#pragma once
#include <string>

class LoaderParams
{
public:
    LoaderParams(int x, int y, int width, int height, std::string textureID, int numFrames = 0, int callbackID = 0, int animSpeed = 0):
        x(x),
        y(y),
        width(width),
        height(height),
        textureID(textureID),
        numFrames(numFrames),
        callbackID(callbackID),
        animSpeed(animSpeed)
        {
            //using callbackID to decide which callback function to use within a state.
        }

    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getNumFrames() const { return numFrames; }
    int getAnimSpeed() const { return animSpeed; }
    int getCallbackID() const { return callbackID; }
    std::string getTextureID() const { return textureID; }

private:
    int x;
    int y;
    int width;
    int height;
    std::string textureID;
    int callbackID;
    int animSpeed;
    int numFrames;
};
