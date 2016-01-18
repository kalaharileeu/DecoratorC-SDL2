#pragma once
class GeneralParameters
{
public:
	static GeneralParameters* Instance()
	{
		if (instance == 0)
		{
			instance = new GeneralParameters();
		}

		return instance;
	}

	int Getgamewidth()
	{
		return gamewidth;
	}

	int Getgameheight()
	{
		return gameheight;
	}

private:
	GeneralParameters() {};
	const int gamewidth = 1000;
	const int gameheight = 1000;

	// singleton instance
	static GeneralParameters* instance;
};

//GeneralParameters* instance = 0;

