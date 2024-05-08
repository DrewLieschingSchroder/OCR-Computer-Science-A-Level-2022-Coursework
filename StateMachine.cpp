#include "StateMachine.hpp"

namespace OCS
{
	//adds state after popping off previous state
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;

		this->_newState = std::move(newState);
	}

	//removes top state
	//used to get back to previous state
	void StateMachine::RemoveState()
	{
		this->_isRemoving = true;
	}

	void StateMachine::ProcessStateChanges()
	{
		//will only run and remove if there are states left
		if (this->_isRemoving && !this->_states.empty())
		{
			this->_states.pop();

			if (!this->_states.empty())
			{
				//resumes the new top state
				this->_states.top()->Resume();
			}
			//will keep removing every state if not set to false
			this->_isRemoving = false;
		}
		//if adding set to true
		if (this->_isAdding)
		{
			//checks to make sure it is not empty
			if (!this->_states.empty())
			{
				//if user want to replace
				if (this->_isReplacing)
				{
					//then state is first popped
					this->_states.pop();
				}
				else
				{
					//if no state is getting replaced
					this->_states.top()->Pause();
				}
			}
			//push new state on to stack
			this->_states.push(std::move(this->_newState));
			//initialise state
			this->_states.top()->Init();
			//prevents multiple states from being added
			this->_isAdding = false;
		}
	}
	//gets active state
	StateRef& StateMachine::GetActiveState()
	{
		return this->_states.top();
	}
}