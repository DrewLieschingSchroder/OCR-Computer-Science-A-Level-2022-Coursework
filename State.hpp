#pragma once

namespace OCS
{
	class State
	{
	public:
		//initialise the state
		virtual void Init() = 0;
		//handle input of state
		virtual void HandleInput() = 0;
		//used for updating the screens
		virtual void Update(float dt) = 0;
		//draw everything to the screen
		virtual void Draw(float dt) = 0;


		virtual void Pause() {}
		virtual void Resume() {}
	};
}