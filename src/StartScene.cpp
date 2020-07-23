#include "StartScene.h"
#include <algorithm>
#include "Game.h"
#include "glm/gtx/string_cast.hpp"
#include "EventManager.h"

StartScene::StartScene()
{
	StartScene::start();
}

StartScene::~StartScene()
= default;

void StartScene::draw()
{
	drawDisplayList();
}

void StartScene::update()
{
	updateDisplayList();
}

void StartScene::clean()
{
	std::cout << "Clean called on StartScene" << std::endl;
	
	delete m_pStartLabel;
	m_pStartLabel = nullptr;
	
	delete m_pInstructionsLabel;
	m_pInstructionsLabel = nullptr;

	delete m_pShip;
	m_pShip = nullptr;

	delete m_pStartButton;
	m_pStartButton = nullptr;

	removeAllChildren();
}

void StartScene::handleEvents()
{
	EventManager::Instance().update();

	// Keyboard Events
	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if(EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	}
}

void StartScene::start()
{
	const SDL_Color orange = { 196, 105, 0, 255 };
	const SDL_Color purple = { 255, 0, 255, 0 };
	m_pStartLabel = new Label("START SCENE", "Consolas", 80, orange, glm::vec2(400.0f, 40.0f));
	m_pStartLabel->setParent(this);
	addChild(m_pStartLabel);

	m_pInstructionsLabel = new Label("Robert Marshall", "Consolas", 40, orange, glm::vec2(400.0f, 120.0f));
	m_pInstructionsLabel2 = new Label("Gil Dobrovinsky", "Consolas", 40, purple, glm::vec2(400.0f, 180.0f));
	m_pInstructionsLabel->setParent(this);
	m_pInstructionsLabel2->setParent(this);
	addChild(m_pInstructionsLabel);
	addChild(m_pInstructionsLabel2);

	m_pInstructionsLabel = new Label("101287661", "Consolas", 40, orange, glm::vec2(410.0f, 150.0f));
	m_pInstructionsLabel2 = new Label("101304972", "Consolas", 40, purple, glm::vec2(410.0f, 210.0f));
	m_pInstructionsLabel->setParent(this);
	m_pInstructionsLabel2->setParent(this);
	addChild(m_pInstructionsLabel);
	addChild(m_pInstructionsLabel2);

	// Start Button
	m_pStartButton = new Button();
	m_pStartButton->getTransform()->position = glm::vec2(400.0f, 400.0f);

	m_pStartButton->addEventListener(CLICK, [&]()-> void
	{
		m_pStartButton->setActive(false);
		TheGame::Instance()->changeSceneState(PLAY_SCENE);
	});
	
	m_pStartButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pStartButton->setAlpha(128);
	});

	m_pStartButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pStartButton->setAlpha(255);
	});
	addChild(m_pStartButton);

	
}

