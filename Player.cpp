#include "Player.h"
#include <DxLib.h>

Player::Player()
{
	//位置
	playerPos.x = 300;
	playerPos.y = 400;

	//サイズ
	playerSize.x = 21;
	playerSize.y = 32;

	//確認用
	playerCheckPos.x = 0;
	playerCheckPos.y = 0;

	//確認用
	playerCheckSize.x = 16;
	playerCheckSize.y = 64;

	//確認用
	playerCheckSizeRL.x = 16;
	playerCheckSizeRL.y = 64;

	//確認用
	playerCheckSizeUD.x = 16;
	playerCheckSizeUD.y = 64;

	//入力している値を渡す
	DS.x = false;
	DS.y = false;
	//入力している値を渡す
	AW.x = false;
	AW.y = false;

	//プレイヤーかフィルターか
	chengeF = true;

	//プレイヤーがすり抜けるか
	sukeF = false;

	//フィルターの角に当たっているかどうか
	kadoF = false;
}

Player::~Player()
{

}

void Player::Inilialize()
{
	//位置
	playerPos.x = 300;
	playerPos.y = 400;

	//サイズ
	playerSize.x = 21;
	playerSize.y = 32;

	//確認用
	playerCheckPos.x = 0;
	playerCheckPos.y = 0;

	//確認用
	playerCheckSize.x = 16;
	playerCheckSize.y = 64;

	//確認用
	playerCheckSizeRL.x = 16;
	playerCheckSizeRL.y = 64;

	//確認用
	playerCheckSizeUD.x = 16;
	playerCheckSizeUD.y = 64;

	//入力している値を渡す
	DS.x = false;
	DS.y = false;
	//入力している値を渡す
	AW.x = false;
	AW.y = false;

	//プレイヤーかフィルターか
	chengeF = true;

	//プレイヤーがすり抜けるか
	sukeF = false;

	//フィルターの角に当たっているかどうか
	kadoF = false;
}

void Player::Update()
{
	DS.x = 0;
	DS.y = 0;

	AW.x = 0;
	AW.y = 0;

	// 更新処理
	float moveSpd = 3.0f;

	//playerPos.y += 1;

	playerCheckPos = playerPos;
	playerCheckSize = playerSize;

	playerCheckSizeRL.x = playerSize.x;
	playerCheckSizeRL.y = playerSize.x;

	playerCheckSizeUD.x = playerSize.y;
	playerCheckSizeUD.y = playerSize.y;

	kadoF = false;

	if (CheckHitKey(KEY_INPUT_SPACE) &&
		//oldkeys[KEY_INPUT_SPACE] == false &&
		sukeF == false)
	{
		chengeF = !chengeF;

		/*CF = !CF;

		circlePos = playerPos;

		CSize = 0;*/
	}

	/*if (CSize < WIN_WIDTH * 2)
		CSize += 30;*/

	if (CheckHitKey(KEY_INPUT_R) 
		//&& oldkeys[KEY_INPUT_R] == false
		)
	{
		playerPos.x = 300;
		playerPos.y = 400;
	}

	//プレイヤーの上下左右
	float p_top = playerCheckPos.y - playerCheckSize.y;
	float p_bottom = playerCheckPos.y + playerCheckSize.y;
	float p_right = playerCheckPos.x + playerCheckSize.x;
	float p_left = playerCheckPos.x - playerCheckSize.x;

	sukeF = false;

	////プレイヤーの上下左右
	//float p_top = playerCheckPos.y - playerCheckSize.y;
	//float p_bottom = playerCheckPos.y + playerCheckSize.y;
	//float p_right = playerCheckPos.x + playerCheckSize.x;
	//float p_left = playerCheckPos.x - playerCheckSize.x;

	////フィルターの上下左右
	//float f_top = filterPos.y - filterSize.y;
	//float f_bottom = filterPos.y + filterSize.y;
	//float f_right = filterPos.x + filterSize.x;
	//float f_left = filterPos.x - filterSize.x;

	//sukeF = false;

	////フィルターに当たっているか
	//if (p_left < f_right &&
	//	p_right > f_left &&
	//	p_top  < f_bottom &&
	//	p_bottom > f_top)
	//{
	//	DrawFormatString(100, 200, 0xffffff, "hit");

	//	//完全にフィルター内にいるか
	//	if (p_right < f_right &&
	//		p_left > f_left &&
	//		p_bottom  < f_bottom &&
	//		p_top > f_top)
	//	{
	//		DrawFormatString(100, 220, 0xffffff, "Phit");

	//		sukeF = true;
	//	}
	//	else
	//	{
	//		//どこの辺がプレイヤーに当たっているか

	//		//右上
	//		if (p_right > f_right &&
	//			p_left < f_right &&
	//			p_bottom > f_top &&
	//			p_top < f_top)
	//		{
	//			playerCheckSizeRL.y = playerPos.x - (filterPos.x + (filterSize.x));
	//			DrawFormatString(100, 240, 0xffffff, "right");

	//			playerCheckSizeUD.y = (filterPos.y - (filterSize.y)) - playerPos.y;
	//			DrawFormatString(100, 280, 0xffffff, "up");

	//			kadoF = true;
	//		}
	//		//右下
	//		else if (
	//			p_right > f_right &&
	//			p_left < f_right &&
	//			p_bottom > f_bottom &&
	//			p_top < f_bottom)
	//		{
	//			playerCheckSizeRL.y = playerPos.x - (filterPos.x + (filterSize.x));
	//			DrawFormatString(100, 240, 0xffffff, "right");

	//			playerCheckSizeUD.x = playerPos.y - (filterPos.y + (filterSize.y));
	//			DrawFormatString(100, 300, 0xffffff, "down");

	//			kadoF = true;
	//		}
	//		//左上
	//		else if (
	//			p_right > f_left &&
	//			p_left < f_left &&
	//			p_bottom > f_top &&
	//			p_top < f_top)
	//		{
	//			playerCheckSizeRL.x = (filterPos.x - (filterSize.x)) - playerPos.x;
	//			DrawFormatString(100, 260, 0xffffff, "left");

	//			playerCheckSizeUD.y = (filterPos.y - (filterSize.y)) - playerPos.y;
	//			DrawFormatString(100, 280, 0xffffff, "up");

	//			kadoF = true;
	//		}
	//		//左下
	//		else if (
	//			p_right > f_left &&
	//			p_left < f_left &&
	//			p_bottom > f_bottom &&
	//			p_top < f_bottom)
	//		{
	//			playerCheckSizeRL.x = (filterPos.x - (filterSize.x)) - playerPos.x;
	//			DrawFormatString(100, 260, 0xffffff, "left");

	//			playerCheckSizeUD.x = playerPos.y - (filterPos.y + (filterSize.y));
	//			DrawFormatString(100, 300, 0xffffff, "down");

	//			kadoF = true;
	//		}
	//		//右
	//		else if (
	//			p_right > f_right &&
	//			p_left < f_right)
	//		{
	//			playerCheckSizeRL.y = playerPos.x - (filterPos.x + (filterSize.x));
	//			DrawFormatString(100, 240, 0xffffff, "right");

	//		}
	//		//左
	//		else if (p_right > f_left &&
	//			p_left < f_left)
	//		{

	//			playerCheckSizeRL.x = (filterPos.x - (filterSize.x)) - playerPos.x;
	//			DrawFormatString(100, 260, 0xffffff, "left");
	//		}
	//		//上
	//		else if (p_bottom > f_top &&
	//			p_top < f_top)
	//		{
	//			//あってる
	//			playerCheckSizeUD.y = (filterPos.y - (filterSize.y / 2)) - playerPos.y - playerSize.y;
	//			DrawFormatString(100, 280, 0xffffff, "up");
	//		}
	//		//下
	//		else if (p_bottom > f_bottom &&
	//			p_top < f_bottom)
	//		{
	//			//できた
	//			playerCheckSizeUD.x = playerPos.y - playerSize.y - (filterPos.y + (filterSize.y / 2));

	//			DrawFormatString(100, 300, 0xffffff, "down");
	//		}

	//	}
	//}

	//if (chengeF)
	//{
	//	if (CheckHitKey(KEY_INPUT_D))
	//	{
	//		playerPos.x += moveSpd;

	//		DS.x = CheckHitKey(KEY_INPUT_D);
	//		DS.y = 0;

	//		AW.x = 0;
	//		AW.y = 0;

	//		if (!sukeF)
	//		{
	//			if (kadoF)
	//			{
	//				Vector2 size = { playerSize.x,playerSize.x };

	//				for (int i = 0; i < boxcount; i++)
	//				{
	//					playerPos = BoxCollision(
	//						playerPos,
	//						size,
	//						playerCheckSizeUD,
	//						Box[i],
	//						BoxSize,
	//						DS,
	//						AW);
	//				}

	//				size.x = playerSize.y;
	//				size.y = playerSize.y;

	//				for (int i = 0; i < boxcount; i++)
	//				{
	//					playerPos = BoxCollision(
	//						playerPos,
	//						playerCheckSizeRL,
	//						size,
	//						Box[i],
	//						BoxSize,
	//						DS,
	//						AW);
	//				}
	//			}
	//			else
	//			{
	//				for (int i = 0; i < boxcount; i++)
	//				{
	//					playerPos = BoxCollision(
	//						playerPos,
	//						playerCheckSizeRL,
	//						playerCheckSizeUD,
	//						Box[i],
	//						BoxSize,
	//						DS,
	//						AW);
	//				}
	//			}
	//		}
	//	}

	//	if (CheckHitKey(KEY_INPUT_A))
	//	{
	//		playerPos.x -= moveSpd;

	//		DS.x = 0;
	//		DS.y = 0;

	//		AW.x = CheckHitKey(KEY_INPUT_A);
	//		AW.y = 0;

	//		if (!sukeF)
	//		{
	//			if (kadoF)
	//			{
	//				Vector2 size = { playerSize.x,playerSize.x };

	//				for (int i = 0; i < boxcount; i++)
	//				{
	//					playerPos = BoxCollision(
	//						playerPos,
	//						size,
	//						playerCheckSizeUD,
	//						Box[i],
	//						BoxSize,
	//						DS,
	//						AW);
	//				}

	//				size.x = playerSize.y;
	//				size.y = playerSize.y;

	//				for (int i = 0; i < boxcount; i++)
	//				{
	//					playerPos = BoxCollision(
	//						playerPos,
	//						playerCheckSizeRL,
	//						size,
	//						Box[i],
	//						BoxSize,
	//						DS,
	//						AW);
	//				}
	//			}
	//			else
	//			{
	//				for (int i = 0; i < boxcount; i++)
	//				{
	//					playerPos = BoxCollision(
	//						playerPos,
	//						playerCheckSizeRL,
	//						playerCheckSizeUD,
	//						Box[i],
	//						BoxSize,
	//						DS,
	//						AW);
	//				}
	//			}
	//		}
	//	}

	//	if (CheckHitKey(KEY_INPUT_S))
	//	{
	//		playerPos.y += moveSpd;

	//		DS.x = 0;
	//		DS.y = CheckHitKey(KEY_INPUT_S);
	//		//DS.y = 1;

	//		AW.x = 0;
	//		AW.y = 0;

	//		if (!sukeF)
	//		{
	//			if (kadoF)
	//			{
	//				Vector2 size = { playerSize.x,playerSize.x };

	//				for (int i = 0; i < boxcount; i++)
	//				{
	//					playerPos = BoxCollision(
	//						playerPos,
	//						size,
	//						playerCheckSizeUD,
	//						Box[i],
	//						BoxSize,
	//						DS,
	//						AW);
	//				}

	//				size.x = playerSize.y;
	//				size.y = playerSize.y;

	//				for (int i = 0; i < boxcount; i++)
	//				{
	//					playerPos = BoxCollision(
	//						playerPos,
	//						playerCheckSizeRL,
	//						size,
	//						Box[i],
	//						BoxSize,
	//						DS,
	//						AW);
	//				}
	//			}
	//			else
	//			{
	//				for (int i = 0; i < boxcount; i++)
	//				{
	//					playerPos = BoxCollision(
	//						playerPos,
	//						playerCheckSizeRL,
	//						playerCheckSizeUD,
	//						Box[i],
	//						BoxSize,
	//						DS,
	//						AW);
	//				}
	//			}
	//		}
	//	}

	//	if (CheckHitKey(KEY_INPUT_W))
	//	{
	//		playerPos.y -= moveSpd;

	//		DS.x = 0;
	//		DS.y = 0;

	//		AW.x = 0;
	//		AW.y = CheckHitKey(KEY_INPUT_W);

	//		if (!sukeF)
	//		{
	//			if (kadoF)
	//			{
	//				Vector2 size = { playerSize.x,playerSize.x };

	//				for (int i = 0; i < boxcount; i++)
	//				{
	//					playerPos = BoxCollision(
	//						playerPos,
	//						size,
	//						playerCheckSizeUD,
	//						Box[i],
	//						BoxSize,
	//						DS,
	//						AW);
	//				}

	//				size.x = playerSize.y;
	//				size.y = playerSize.y;

	//				for (int i = 0; i < boxcount; i++)
	//				{
	//					playerPos = BoxCollision(
	//						playerPos,
	//						playerCheckSizeRL,
	//						size,
	//						Box[i],
	//						BoxSize,
	//						DS,
	//						AW);
	//				}
	//			}
	//			else
	//			{
	//				for (int i = 0; i < boxcount; i++)
	//				{
	//					playerPos = BoxCollision(
	//						playerPos,
	//						playerCheckSizeRL,
	//						playerCheckSizeUD,
	//						Box[i],
	//						BoxSize,
	//						DS,
	//						AW);
	//				}
	//			}
	//		}
	//	}
	//}
	//else
	//{
	//	filterPos.x += (CheckHitKey(KEY_INPUT_D) - CheckHitKey(KEY_INPUT_A)) * moveSpd;
	//	filterPos.y += (CheckHitKey(KEY_INPUT_S) - CheckHitKey(KEY_INPUT_W)) * moveSpd;
	//}

}

void Player::Draw()
{
	//通常
	/*DrawBox(playerPos.x - playerSize.x,
		playerPos.y - playerSize.y,
		playerPos.x + playerSize.x,
		playerPos.y + playerSize.y,
		0x777777,
		false);*/

	//プレイヤー上下左右
	/*DrawBox(
		playerPos.x - playerCheckSizeRL.y,
		playerPos.y - playerCheckSizeUD.x,
		playerPos.x + playerCheckSizeRL.x,
		playerPos.y + playerCheckSizeUD.y,
		0x770077,
		false);*/

	//左右
	DrawBox(
		playerPos.x - playerCheckSizeRL.y,
		playerPos.y - playerSize.y,
		playerPos.x + playerCheckSizeRL.x,
		playerPos.y + playerSize.y,
		0x770077,
		true);

	//上下
	DrawBox(
		playerPos.x - playerSize.x,
		playerPos.y - playerCheckSizeUD.x,
		playerPos.x + playerSize.x,
		playerPos.y + playerCheckSizeUD.y,
		0x770077,
		true);
}
