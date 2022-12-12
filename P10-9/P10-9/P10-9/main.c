#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct card {
	const char *face;
	const char *suit;
}Card;//�]�wCard�ۭq���c

void fillDeck(Card* const wDeck, const char* wFace[],
	const char* wSuit[]);

void shuffle(Card* const wDeck);
void deal(Card* const wDeck);

int main()
{
	Card deck[52];
	const char* face[13] =//�]�w�P���Ʀr
	{ "Ace","Deuce","Three","Four",
	 "Five","Six","Seven","Eight",
	 "Nine","Ten","Jack","Queen","King" };

	const char *suit[4] = //�]�w���
	{ "Hearts","Diamonds","Clubs","Spades" };

	srand(time(NULL));//�ɶ������H��
	fillDeck(deck, face, suit);
	shuffle(deck);
	deal(deck);
	system("pause");
	return 0;
}

void fillDeck(Card * const wDeck, const char * wFace[],//��J���μƦr
	const char * wSuit[]) {
	int i;
	for (i = 0; i <= 51; i++)
	{
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wFace[i / 13];
	}
}
void shuffle(Card * const wDeck) {//�~�P
	int i, j;
	Card temp;
	for (i = 0; i <= 51; i++)
	{
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}
void deal(Card* const wDeck)
{
	int i;
	for (i = 0; i <= 51; i++)
		printf("%5s of %-8s%s",wDeck[i].face,wDeck[i].suit,
			(i+1)% 4 ? "  " : "\n");//�L�X�H���o�P�᪺���G
}