#include "CGraduateStudent.h"

void CGraduateStudent::useCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CGraduateStudent>>& graduateStudent, int randomCard, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	unique_ptr<CGraduateStudent> printCardType = make_unique<CGraduateStudent>();
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>();
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>(); 

	printCardType->printCardUse();

	int cardPowerAttackerInt = 0;
	int cardResilienceAttackerInt = 0;
	int cardPowerAttackedInt = 0;
	int cardResilienceAttackedInt = 0;

	if (cardsDrawn[randomCard]->mType == G_GRADUATE_STUDENT)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CGraduateStudent> pStudentElement = static_pointer_cast<CGraduateStudent>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		graduateStudent.push_back(pStudentElement);
	}

	professorAttacked.mProfName;
	professorAttacker.mProfName;

	if (!graduateStudent.empty())
	{

		for (int i = 0; i < graduateStudent.size(); i++)
		{

			string cardPowerAttacker = graduateStudent[i]->mPower;
			string cardResilienceAttacker = graduateStudent[i]->mResilience;

			if (!tableAttacked.empty()) {
				int randomIndex = randomNumber->Random(tableAttacked.size() - 1);

				string cardPowerAttacked = tableAttacked[randomIndex]->mPower;
				string cardResilienceAttacked = tableAttacked[randomIndex]->mResilience;

				cardPowerAttackerInt = stoi(cardPowerAttacker);
				cardResilienceAttackerInt = stoi(cardResilienceAttacker);
				cardPowerAttackedInt = stoi(cardPowerAttacked);
				cardResilienceAttackedInt = stoi(cardResilienceAttacked);

				activateEasyTarget->useCardSpecialAbility(cardPowerAttackerInt, easyTarget);

				if (cardResilienceAttackedInt > 0) {
					string cardResilienceStringDueled;
					printCardType->attackEntity(cardResilienceAttackedInt, cardPowerAttackerInt, cardResilienceStringDueled, tableAttacked, randomIndex, randomCard, cardsDrawn);
					professorAttacker.mProfPrestige += 2;
				}
				if (cardResilienceAttackedInt <= 0) {
					printCardType->activateCardDeath(randomIndex, tableAttacked);
				
				}
			}

			if (tableAttacked.empty()) {
				printCardType->attackProfessor(professorAttacked, cardPowerAttackerInt, cardsDrawn, randomCard);
				professorAttacker.mProfPrestige += 2;
			}

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}


		}
	}
	if (graduateStudent.empty())
	{
		
	}
	graduateStudent.clear();
}
void CGraduateStudent::printCardUse()
{
	
}

void CGraduateStudent::activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked)
{
	cout << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " is defeated" << endl;
	tableAttacked.erase(tableAttacked.begin() + randomIndex);
}

void CGraduateStudent::attackEntity(int &cardResilienceAttackedInt, int &cardPowerAttackerInt, string &cardResilienceStringDueled, vector<shared_ptr<CTable>>& tableAttacked, int randomIndex, int randomCard, vector<shared_ptr<CCard>> &cardsDrawn)
{
	cardResilienceAttackedInt -= cardPowerAttackerInt;
	cardResilienceStringDueled = to_string(cardResilienceAttackedInt);
	tableAttacked[randomIndex]->mResilience = cardResilienceStringDueled;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << ". " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " resilience is now " << tableAttacked[randomIndex]->mResilience << endl;
}

void CGraduateStudent::attackProfessor(CPlayers::SProfessor& professorAttacked, int cardPowerAttackerInt, vector<shared_ptr<CCard>> cardsDrawn, int randomCard)
{
	professorAttacked.mProfPrestige -= cardPowerAttackerInt;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << professorAttacked.mProfName << ". " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}