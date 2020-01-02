#pragma once
#include "State.h"

class MoveState : public State {

private:
	Vector3 direction = Vector3::Zero();
	float speed = 0;
public:
	MoveState(StateMachine& InMachine);
	virtual ~MoveState();
	virtual void Update(float DeltaTime) override;
	virtual void OnExitState() override;
	inline const Vector3& Direction() const { return direction; } 
    inline void Direction(const Vector3& Dir) { direction = Dir; } 
	inline const float Speed() const { return speed; } 
    inline void Speed(const float in_speed) { speed = in_speed; } 
};