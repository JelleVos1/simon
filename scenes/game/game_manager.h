#pragma once

#include "score_manager.h"
#include "board.h"

#include <sge/ecs/component.h>
#include <sge/ecs/entity_manager.h>
#include <sge/ecs/entity.h>
#include <sge/ecs/components/ui/label.h>
#include <sge/ecs/components/transform.h>
#include <sge/ecs/components/audio_source.h>
#include <vector>

class Board;

class GameManager : public Component
{
public:
	std::vector<int> colors;
	bool isPlaying = false;
	bool canGuess = false;
	int guessCount = 0;

public:
	void start();
	void startGame();
	void nextTurn();
	void gameOver();

private:
	EntityManager* entityManager;

	ScoreManager* scoreManager;
	Board* board;

	Entity* startText;
	Label* startLabel;
	Transform* scoreTransform;

	AudioSource* keyAudio;

	float timeHighlightedColor = 1.5f;
	float timeBetweenColors = 0.65f;

private:
	void addColors();
	void addColor(int color);
	void centerText();
};