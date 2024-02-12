#pragma once
class QuizGenerator
{
public:
	enum class QuizDifficulty { Easy, Normal, Hard };

	QuizDifficulty difficulty;
	int questionCount = 0;
	int lives = 3;


	QuizGenerator(QuizDifficulty difficulty) {//, std::map < std::string, boost::optional<std::> > 
		this->difficulty = difficulty;
	}

};

