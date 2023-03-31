#pragma once
#include "Vector2.h"

class Player
{
private:
	Vector2 playerPos = { 0,0 };
	Vector2 playerSize = { 16,32 };

	Vector2 playerCheckPos = { 0,0 };
	Vector2 playerCheckSize = { 16,64 };

	Vector2 playerCheckSizeRL = { 16,64 };
	Vector2 playerCheckSizeUD = { 16,64 };

	//キーが押されているかどうか
	Vector2 DS;
	Vector2 AW;

	//プレイヤーかフィルターか
	bool chengeF = true;

	//プレイヤーがすり抜けるか
	bool sukeF = false;
	//passFlag

	//フィルターの角に当たっているかどうか
	bool kadoF = false;
	//corner

public:
	Player();
	~Player();

	void Inilialize();
	void Update();
	void Draw();

	//位置
	Vector2 GetPos() { return playerPos; };
	void SetPos(Vector2 nowpos) { playerPos = nowpos; };

	//最初の大きさ
	Vector2 GetSize() { return playerSize; };
	void SetSize(Vector2 nowsize) { playerPos = nowsize; };

	//今の大きさ
	Vector2 GetNowSizeX() { return playerCheckSizeRL; };
	Vector2 GetNowSizeY() { return playerCheckSizeUD; };

	bool GetmoveFlag() { return chengeF; };
	bool GetpassFlag() { return sukeF; };
	bool GetcornerFlag() { return kadoF; };

	void SetmoveFlag(bool flag) { chengeF = flag; };
	void SetpassFlag(bool flag) { sukeF = flag; };
	void SetcornerFlag(bool flag) { kadoF = flag; };
};