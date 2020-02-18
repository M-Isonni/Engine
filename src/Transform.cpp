#include "Transform.h"
#include <math.h>

void Vector3::normalize(Vector3 &invec)
{
    invec = invec / magnitude(invec);
}

float Vector3::magnitude(Vector3 invec)
{
    return sqrt(invec.X * invec.X + invec.Y * invec.Y + invec.Z * invec.Z);
}