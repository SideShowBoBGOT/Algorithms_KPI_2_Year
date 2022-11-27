//
// Created by choleraplague on 25.11.22.
//

#ifndef UNTITLED1_TBOARDSCREEN_H
#define UNTITLED1_TBOARDSCREEN_H

#include <array>
#include "../VisualModels/TAutoAlignArea.h"
#include "../VisualModels/TVisualCard.h"

class TBoardScreen : public TParent {
	public:
	TBoardScreen();
	virtual ~TBoardScreen() override=default;
	
	public:
	TAutoAlignArea* ButtonPanel = nullptr;
	TControl* PutButton 		= nullptr;
	TControl* TakeButton 		= nullptr;
	TControl* EndTurnButton 	= nullptr;
	TControl* QuitButton 		= nullptr;
	TControl* DeselectButton 	= nullptr;
	
	public:
	TAutoAlignArea* AIPanel 	= nullptr;
	TControl* AIOneLabel 		= nullptr;
	TControl* AITwoLabel 		= nullptr;
	TControl* AIThreeLabel 		= nullptr;
	
	public:
	std::vector<TVisualCard*> VisualCards;
	TAutoAlignArea* LocalCards 	= nullptr;
	TAutoAlignArea* PlayCards 	= nullptr;
	
	protected:
	void OnPutButton(TControl* obj);
	void OnTakeButton(TControl* obj);
	void OnEndTurnButton(TControl* obj);
	void OnQuitButton(TControl* obj);
	void OnDeselectButton(TControl* obj);
	
	protected:
	void LockInterface();
	void UnLockInterface();
	void OnChangeCardsArea(TControl* c);
};
//101x144

#endif //UNTITLED1_TBOARDSCREEN_H
