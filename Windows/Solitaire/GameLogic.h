#pragma once
#include <list>
#include "Card.h"

namespace solitaire
{
	class GameLogic
	{
		const int BOARD_ROW = 5;
		const int BOARD_COL = 8;
		const Gdiplus::RectF BOARD_COUNT_RECT{ 885.0f,60.0f,120.0f,30.0f };

	private:
		HWND mHwnd;
		std::unique_ptr<Gdiplus::Image> mBackground;
		std::list<Card> mDeck;
		int mClickCount;
		Card* mpPrevious;

	private:
		void CreateCards();

	public:
		void Init(HWND hwnd);
		void Release();
		void Draw(Gdiplus::Graphics& graphics);
		void OnClick(int x, int y)
		{
			Card* pCard{};
			for (auto& card : mDeck)
			{
				if (card.CheckClicked(x, y))
				{
					pCard = &card;
					break;
				}
			}

			if (pCard)
			{
				mClickCount++;
				RECT rct{ BOARD_COUNT_RECT.GetLeft(), BOARD_COUNT_RECT.GetTop(),
					BOARD_COUNT_RECT.GetRight(), BOARD_COUNT_RECT.GetBottom() };
				InvalidateRect(mHwnd, &rct, false);

				if (mpPrevious == nullptr)
				{
					mpPrevious = pCard;
				}
				else
				{
					if (mpPrevious != pCard)
					{
						UpdateWindow(mHwnd);
						Sleep(500);

						if (pCard->GetType() == mpPrevious->GetType())
						{
							mpPrevious->Invalidate();
							pCard->Invalidate();

							mDeck.remove_if([&](Card& card) { return card.GetIndex() == pCard->GetIndex(); });
							mDeck.remove_if([&](Card& card) { return card.GetIndex() == mpPrevious->GetIndex(); });
						}
						else
						{
							pCard->Flip(false);
							mpPrevious->Flip(false);
						}
					}
					mpPrevious = nullptr;
				}
			}
		}
	};
}


