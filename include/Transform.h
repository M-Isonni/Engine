#pragma once
class Vector3
{
public:
    Vector3(){};
    ~Vector3(){};
    Vector3(float x, float y, float z)
    {
        X = x;
        Y = y;
        Z = z;
    };
    Vector3(const Vector3 &in_vec) = default;
    float X, Y, Z = 0;
    Vector3 operator+(const Vector3 &right)
    {
        Vector3 out;
        out.X = X + right.X;
        out.Y = Y + right.Y;
        out.Z = Z + right.Z;
        return out;
    }
    Vector3 operator*(float mul)
    {
        Vector3 out;
        out.X = X * mul;
        out.Y = Y * mul;
        out.Z = Z * mul;
        return out;
    }

    static Vector3 Zero()
    {
        return Vector3();
    }
};

class Transform
{
public:
    Transform(){};
    ~Transform(){};
    Transform(Vector3 pos, Vector3 sca, Vector3 rot){position = pos; scale = sca; rotation = rot;};

    Vector3 position;
    Vector3 scale;
    Vector3 rotation;

    static Transform Base()
    {
        return Transform(Vector3::Zero(),Vector3(1,1,1),Vector3::Zero());
    }
};
