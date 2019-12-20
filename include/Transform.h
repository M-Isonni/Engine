#pragma once
class Vector3
{
public:
    float X, Y, Z = 0;
    Vector3 operator+(const Vector3 &right)
    {
        Vector3 out;
        out.X = X + right.X;
        out.Y = Y + right.Y;
        out.Z = Z + right.Z;
        return out;
    }    
};

class Transform
{
public:
    Transform(){};
    ~Transform(){};

    Vector3 position;
    Vector3 scale;
    Vector3 rotation;
};
