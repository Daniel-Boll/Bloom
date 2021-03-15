#pragma once
#include <functional>

#include "Bloom/Core/Core.hpp" 

namespace Bloom {

	// Events in Bloom are currently <blocking>, meaning when an event occurs it
	// immediately gets dispatched and must be dealt with right then an there.

	// To be implemented: A better strategy might be to buffer events in an event
	// bus and process them during the "event" part of the update stage.

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication		= BIT(0),
		EventCategoryInput					= BIT(1),
		EventCategoryKeyboard				= BIT(2),
		EventCategoryMouse					= BIT(3),
		EventCategoryMouseButton		= BIT(4)
	};

	/*
		Every event registered on: 
			|> ApplicationEvent
			|> KeyEvent
			|> MouseEvent

		will have to implement those functions.
			|> Event class type
			|> Event class category

			The category will be same for every event in
			a particular file (E.g ApplicationEvent.hpp
			will only have EVENT_CLASS_CATEGORY(EventCategoryApplication))
	*/


	#define EVENT_CLASS_TYPE(type) static EventType getStaticType() {		\
		return EventType::##type;																					\
	}																																		\
																																			\
	virtual EventType getEventType() const override {										\
		return getStaticType();																						\
	}																																		\
																																			\
	virtual const char* getName() const override {											\
		return #type;																											\
	}

	#define EVENT_CLASS_CATEGORY(category)						\
	virtual int getCategoryFlags() const override {		\
		return category;																\
	}

	class BLOOM_API Event {
		friend class EventDispatcher;
		
		public:
			virtual ~Event() = default;

			bool Handled = false;
			// First three ones will be implemented
			// on EVENT_CLASS_TYPE; EVENT_CLASS_CATEGORY.
			virtual EventType getEventType() const = 0;
			virtual const char* getName()		 const = 0;
			virtual int getCategoryFlags()	 const = 0;

			// toString default is only returning it's name.
			// Might be override in a particular case
			virtual std::string toString()	 const { return getName(); }

			inline bool isInCategory(EventCategory category) {
				return getCategoryFlags() & category;
			}
	};

	class EventDispatcher {
		public:
			EventDispatcher(Event& event) : m_Event(event) {}

			// F will be deduced by the compiler
			template<typename T, typename F>
			bool Dispatch(const F& func) {
				if (m_Event.getEventType() == T::getStaticType()) {
					m_Event.Handled |= func(static_cast<T&>(m_Event));
					return true;
				}
				return false;
			}
		
		private:
			Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.toString();
	}
}