//
// Created by choleraplague on 18.11.22.
//

#ifndef UNTITLED1_TCONTROL_H
#define UNTITLED1_TCONTROL_H

#include <functional>
#include <string>
#include <map>
#include <memory>
#include <SDL2/SDL.h>
#include "IControl.h"
#include "Enums/NNState.h"

class TControl : public IControl {
	public:
	TControl()=default;
	virtual ~TControl() override;
	
	public:
	virtual bool HandleEvents() override;
	virtual bool Render() override;
	virtual bool Clean() override;
	
	public:
	virtual void StateTexture(NState state, std::string str);
	
	public:
	virtual bool IsMouseOn();
	
	#define DECL(xx, type, prefix, val) \
		protected:            \
		type m_##prefix##xx = val;      \
                                \
        public:                        \
		virtual void xx(type vv); \
		virtual type xx();
	
		DECL(Dx, int, i, 0);
		DECL(Dy, int, i, 0);
		DECL(Sx, int, i, 0);
		DECL(Sy, int, i, 0);
		DECL(Width, int, i, 0);
		DECL(Height, int, i, 0);
		DECL(Renderer, SDL_Renderer*, p, nullptr);
		DECL(State, NState, x, NState::Normal);
		DECL(Selected, bool, b, false);
		DECL(Over, bool, b, false);
		DECL(UserData, std::string, s, "");
		DECL(Enabled, bool, b, true);
		DECL(Visible, bool, b, true);
		DECL(Parent, TControl*, p, nullptr);
		DECL(ZIndex, int, i, 0);
	#undef DECL
		
	#define INIT_HANDLER(xx) \
    	protected:\
		std::function<void(TControl* obj)> On##xx##Handler = nullptr; \
                                    \
		public:\
		virtual void On##xx(std::function<void(TControl* obj)>&& func);\
		virtual void On##xx();
		
		INIT_HANDLER(LeftDown);
		INIT_HANDLER(RightDown);
		INIT_HANDLER(MiddleDown);
		INIT_HANDLER(LeftUp);
		INIT_HANDLER(RightUp);
		INIT_HANDLER(MiddleUp);
		INIT_HANDLER(Change);
	#undef INIT_HANDLER
	
	public:
	virtual int AbsoluteDx();
	virtual int AbsoluteDy();
	
	protected:
	std::map<NState, std::string> m_mMap = 	{
												{NState::Normal, ""},
												{NState::Over, ""},
												{NState::OverSelected, ""},
												{NState::Selected, ""}
											};
};
#endif //UNTITLED1_TCONTROL_H
