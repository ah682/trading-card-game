// Adam James Anthony Hall
#pragma once
#pragma warning(suppress : 6031)
// Initialize necessary header files
#include <fstream>
#include <vector>

#include "CCard.h"
#include "CPlayers.h"
#include "CStudent.h"
#include "CTable.h"
#include "CCounter.h"
#include "CCourseAccreditation.h"
#include "CPlagiarismHearing.h"
#include "CFeedbackForum.h"
#include "CPassLeader.h"
#include "CResearchFunding.h"
#include "CMitigatingCircumstances.h"
#include "CEasyTarget.h"
#include "CSerialOffender.h"
#include "CGraduateStudent.h"
#include "CIndustrialPlacement.h"

class CManager
{
public:
	enum mSelectChoice
	{
		eChoiceAlpha = 1,
		eChoiceBeta = 2,
	};
	void GameStart();
	void GameOver(CPlayers::SProfessor piffle, CPlayers::SProfessor plagiarist, CPlayers::SProfessor pointless, CPlayers::SProfessor perdition);
	void StartRound(int& round);
	void UseStudentCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CStudent>>& ordinaryStudent, int randomCard, vector<shared_ptr<CEasyTarget>> &easyTarget);
	void FillDeck(ifstream& inFile, vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CStudent>>& cardsStudent);
	void DrawCard(vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CCard>>& drawnCards, int& deckCounter, int& i, CPlayers::SProfessor playerName, vector<shared_ptr<bool>>& usedCards);
	void pushToHand(vector<shared_ptr<CCard>>& drawnCards, vector<shared_ptr<CCard>>& hand, int& i, CPlayers::SProfessor playerName);
	void PrintTable(vector<shared_ptr<CTable>>& table, vector<shared_ptr<CCard>>& cardsDrawn, CPlayers::SProfessor playerName, string professor, int randomCard);
	void UseEasyTargetCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CEasyTarget>> easyTarget, int randomCard, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker);
	int getChoice() const;
	void setChoice(int choice);
	int getRoundCounter() const;
	void setRoundCounter(int round);

private:
	int mChoice = 0;
	int mRoundCounter = 1;
};


