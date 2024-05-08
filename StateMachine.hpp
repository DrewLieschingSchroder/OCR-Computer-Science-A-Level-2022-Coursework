#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

namespace OCS
{
	//unique pointer to state
	typedef std::unique_ptr<State> StateRef;

	class StateMachine
	{
	public:
		//constructor and destructor
		StateMachine() {}
		~StateMachine() {}

		//add state function
		//replacing = true will get rid of previous state, setting to false will pause for example
		void AddState(StateRef newState, bool isReplacing = true);
		//manually remove top state
		void RemoveState();

		//uses the add state and remove state function
		void ProcessStateChanges();

		//return referance to state at top of stack
		StateRef& GetActiveState();

	private:
		//unique pointer to all states in stack
		std::stack<StateRef> _states;
		//latest state
		StateRef _newState;

		//boolean statements for changing states
		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;
	};
}