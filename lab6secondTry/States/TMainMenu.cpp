//
// Created by choleraplague on 18.11.22.
//

#include "TMainMenu.h"
#include "../GameSingletons/TGame.h"
#include "../GameSingletons/TTextureManager.h"
#include "../GameSingletons/TLogic.h"
#include "../Other/NNFileSystem.h"

static int constexpr s_iButtonWidth = 158;
static int constexpr s_iButtonHeigth = 35;
static std::string s_sMainMenuPath = "MainMenu/";

TMainMenu::TMainMenu() {
	auto center = TGame::Get()->ScreenWidth() / 2 - s_iButtonWidth / 2;
	auto middle = TGame::Get()->ScreenHeight() / 2 - s_iButtonHeigth / 2;

	#define INIT_BUTTON(xx, dx, dy, func) \
    	xx = CreateObject();\
		xx->Dx(dx);\
		xx->Dy(dy);\
		xx->Sx(0);\
		xx->Sx(0);\
		xx->Width(s_iButtonWidth);\
		xx->Height(s_iButtonHeigth);\
		xx->Renderer(TGame::Get()->Renderer()); \
        TTextureManager::Get()->Load(NNFileSystem::AssetsImagePath(s_sMainMenuPath+#xx+"/"+"Normal").c_str(), #xx"Normal", TGame::Get()->Renderer());\
        TTextureManager::Get()->Load(NNFileSystem::AssetsImagePath(s_sMainMenuPath+#xx+"/"+"Over").c_str(), #xx"Over", TGame::Get()->Renderer());\
		xx->StateTexture(NState::Normal, #xx"Normal");\
		xx->StateTexture(NState::Over, #xx"Over");\
		xx->StateTexture(NState::Selected, #xx"Normal");\
		xx->StateTexture(NState::OverSelected, #xx"Over");\
		xx->OnLeftDown(func);
		
		INIT_BUTTON(StartButton, center, middle, [this](std::shared_ptr<TVisualObject> obj) { OnStartButton(obj); });
		INIT_BUTTON(SettingsButton, center, middle + s_iButtonHeigth, [this](std::shared_ptr<TVisualObject> obj) { OnSettigsButton(obj); });
		INIT_BUTTON(QuitButton, center, middle + 2 * s_iButtonHeigth, [this](std::shared_ptr<TVisualObject> obj) { OnQuitButton(obj); });
	#undef INIT_BUTTON
}

void TMainMenu::OnStartButton(std::shared_ptr<TVisualObject> obj) {
	auto& settings = TGame::Get()->Settings;
	auto number = settings->GetNumberOfPlayers();
	auto diff = settings->GetDifficulty();
	auto& session = TLogic::Get()->Session;
	session = std::make_shared<TSession>(diff, number);
	TGameStateMachine::Get()->PushState(TGame::Get()->BoardScreen);
}

void TMainMenu::OnSettigsButton(std::shared_ptr<TVisualObject> obj) {
	TGameStateMachine::Get()->PushState(TGame::Get()->Settings);
}

void TMainMenu::OnQuitButton(std::shared_ptr<TVisualObject> obj) {
	TGameStateMachine::Get()->PopState();
}


