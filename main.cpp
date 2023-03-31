#include "DxLib.h"
#include "Vector2.h"
#include "Player.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "タイトル";

// ウィンドウ横幅
const int WIN_WIDTH = 900;

// ウィンドウ縦幅
const int WIN_HEIGHT = 700;

Vector2 BoxCollision(Vector2 posP, Vector2 sizeP, Vector2 posF, Vector2 sizeF, Vector2 DS, Vector2 AW)
{
	Vector2 nowPosP = posP;
	Vector2 nowPosF = posF;

	//プレイヤーの上下左右
	float p_top = nowPosP.y - sizeP.y;
	float p_bottom = nowPosP.y + sizeP.y;
	float p_right = nowPosP.x + sizeP.x;
	float p_left = nowPosP.x - sizeP.x;

	//フィルターの上下左右
	float f_top = nowPosF.y - sizeF.y;
	float f_bottom = nowPosF.y + sizeF.y;
	float f_right = nowPosF.x + sizeF.x;
	float f_left = nowPosF.x - sizeF.x;

	//フィルターに当たっているか
	if (p_left < f_right &&
		p_right > f_left &&
		p_top  < f_bottom &&
		p_bottom > f_top)
	{
		while (p_left < f_right &&
			p_right > f_left &&
			p_top  < f_bottom &&
			p_bottom > f_top)
		{
			nowPosP -= DS;
			nowPosP += AW;

			//プレイヤーの上下左右
			p_top = nowPosP.y - sizeP.y;
			p_bottom = nowPosP.y + sizeP.y;
			p_right = nowPosP.x + sizeP.x;
			p_left = nowPosP.x - sizeP.x;
		}
	}

	return nowPosP;
}

Vector2 BoxCollision(Vector2 posP, Vector2 sizePRL, Vector2 sizePUD, Vector2 posF, Vector2 sizeF, Vector2 DS, Vector2 AW)
{
	Vector2 nowPosP = posP;
	Vector2 nowPosF = posF;

	Vector2 Ds = DS;
	Vector2 Aw = AW;

	Ds.x *= 0.1f;
	Ds.y *= 0.1f;
	Aw.x *= 0.1f;
	Aw.y *= 0.1f;

	//プレイヤーの上下左右
	float p_top = nowPosP.y - sizePUD.x;
	float p_bottom = nowPosP.y + sizePUD.y;
	float p_right = nowPosP.x + sizePRL.x;
	float p_left = nowPosP.x - sizePRL.y;

	//フィルターの上下左右
	float f_top = nowPosF.y - sizeF.y;
	float f_bottom = nowPosF.y + sizeF.y;
	float f_right = nowPosF.x + sizeF.x;
	float f_left = nowPosF.x - sizeF.x;

	//フィルターに当たっているか
	if (p_left < f_right &&
		p_right > f_left &&
		p_top  < f_bottom &&
		p_bottom > f_top)
	{
		while (p_left < f_right &&
			p_right > f_left &&
			p_top  < f_bottom &&
			p_bottom > f_top)
		{
			nowPosP -= Ds;
			nowPosP += Aw;

			//プレイヤーの上下左右
			p_top = nowPosP.y - sizePUD.x;
			p_bottom = nowPosP.y + sizePUD.y;
			p_right = nowPosP.x + sizePRL.x;
			p_left = nowPosP.x - sizePRL.y;
		}
	}

	return nowPosP;
}

Vector2 BoxCollision(Vector2 posP, Vector2 sizePRL, Vector2 sizePUD, Vector2 posF, Vector2 sizeLR, Vector2 sizeUD, Vector2 DS, Vector2 AW)
{
	Vector2 nowPosP = posP;
	Vector2 nowPosF = posF;

	Vector2 Ds = DS;
	Vector2 Aw = AW;

	Ds.x *= 0.1f;
	Ds.y *= 0.1f;
	Aw.x *= 0.1f;
	Aw.y *= 0.1f;

	//プレイヤーの上下左右
	float p_top = nowPosP.y - sizePUD.x;
	float p_bottom = nowPosP.y + sizePUD.y;
	float p_right = nowPosP.x + sizePRL.x;
	float p_left = nowPosP.x - sizePRL.y;

	//フィルターの上下左右
	float f_top = nowPosF.y - sizeUD.x;
	float f_bottom = nowPosF.y + sizeUD.y;
	float f_right = nowPosF.x + sizeLR.y;
	float f_left = nowPosF.x - sizeLR.x;

	//フィルターに当たっているか
	if (p_left < f_right &&
		p_right > f_left &&
		p_top  < f_bottom &&
		p_bottom > f_top)
	{
		while (p_left < f_right &&
			p_right > f_left &&
			p_top  < f_bottom &&
			p_bottom > f_top)
		{
			nowPosP -= Ds;
			nowPosP += Aw;

			//プレイヤーの上下左右
			p_top = nowPosP.y - sizePUD.x;
			p_bottom = nowPosP.y + sizePUD.y;
			p_right = nowPosP.x + sizePRL.x;
			p_left = nowPosP.x - sizePRL.y;
		}
	}

	return nowPosP;
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み

	Player player;

	// ゲームループで使う変数の宣言

	Vector2 playerPos = { 300,400 };
	Vector2 playerSize = { 21,32 };

	Vector2 playerCheckPos = { 0,0 };
	Vector2 playerCheckSize = { 16,64 };

	Vector2 playerCheckSizeRL = { 16,64 };
	Vector2 playerCheckSizeUD = { 16,64 };

	Vector2 filterPos = { 300,300 };
	Vector2 filterSize = { 128,64 };

	Vector2 Box[20];
	Vector2 BoxSize = { 16,16 };

	Vector2 BoxSizeLR[20];
	Vector2 BoxSizeUD[20];

	//ボックスの数
	int boxcount = 20;

	//キーが押されているかどうか
	Vector2 DS;
	Vector2 AW;

	//プレイヤーかフィルターか
	bool chengeF = true;

	//プレイヤーがすり抜けるか
	bool sukeF = false;

	//フィルターの角に当たっているかどうか
	bool kadoF = false;

	Vector2 circlePos = { 0, 0 };
	int CSize = WIN_WIDTH * 2;
	bool CF = false;

	//マップ上に配置しているブロック
	for (int i = 0; i < boxcount; i++)
	{
		Box[i].x = (i * 30);
		Box[i].y = (19 * 30);

		BoxSizeLR[i].x = 16;
		BoxSizeLR[i].y = 16;

		BoxSizeUD[i].x = 16;
		BoxSizeUD[i].y = 16;
	}

	//細かな調整
	Box[19].x = (18 * 30);
	Box[19].y = (20 * 30);

	Box[15].x = (16 * 30) - 5;
	Box[15].y = (15 * 30);

	Box[2].x = (16 * 30) - 5;
	Box[2].y = (14 * 30) - 25;

	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	float Gravity = 0;
	float GravityPower = 0;

	//プレイヤーの上下左右
	float p_top = playerCheckPos.y - playerCheckSize.y;
	float p_bottom = playerCheckPos.y + playerCheckSize.y;
	float p_right = playerCheckPos.x + playerCheckSize.x;
	float p_left = playerCheckPos.x - playerCheckSize.x;

	//フィルターの上下左右
	float f_top = filterPos.y - filterSize.y;
	float f_bottom = filterPos.y + filterSize.y;
	float f_right = filterPos.x + filterSize.x;
	float f_left = filterPos.x - filterSize.x;

	bool JumpFlag = false;
	float JumpPower = 0;
	float Jump = 0;

	// ゲームループ
	while (true) {

		for (int i = 0; i < 256; i++)
		{
			oldkeys[i] = keys[i];
		}

		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		float moveSpd = 3.0f;

		//playerPos.y += 1;

		if (CheckHitKey(KEY_INPUT_SPACE) &&
			oldkeys[KEY_INPUT_SPACE] == false &&
			sukeF == false)
		{
			if (!(p_left < f_right &&
				p_right > f_left &&
				p_top  < f_bottom &&
				p_bottom > f_top))
			{
				chengeF = !chengeF;

				CF = !CF;

				circlePos = playerPos;

				CSize = 0;
			}
		}

		if (CSize < WIN_WIDTH * 2)
			CSize += 30;

		if (CheckHitKey(KEY_INPUT_R) &&
			oldkeys[KEY_INPUT_R] == false)
		{
			playerPos.x = 300;
			playerPos.y = 400;

			Gravity = 0;
			GravityPower = 0;

			Jump = 0;
			JumpPower = 0;

			JumpFlag = false;
		}

		//重力
		playerPos.y += Gravity;

		//上と下の戻し判定
		if (!sukeF)
		{
			if (kadoF)
			{
				if (JumpFlag)
				{
					DS.x = 0;
					DS.y = 0;

					AW.x = 0;
					AW.y = 1;

					Vector2 size = { playerSize.x,playerSize.x };

					for (int i = 0; i < (int)Jump; i++)
					{
						playerPos.y -= 1;

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								size,
								playerCheckSizeUD,
								Box[i],
								BoxSize,
								BoxSizeUD[i],
								DS,
								AW);
						}

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								size,
								playerCheckSizeUD,
								Box[i],
								BoxSizeLR[i],
								BoxSize,
								DS,
								AW);
						}

						size.x = playerSize.y;
						size.y = playerSize.y;

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								size,
								Box[i],
								BoxSize,
								BoxSizeUD[i],
								DS,
								AW);
						}

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								size,
								Box[i],
								BoxSizeLR[i],
								BoxSize,
								DS,
								AW);
						}
					}
				}
				else if (!(Gravity == 0.0f))
				{

					DS.x = 0;
					DS.y = 1;

					AW.x = 0;
					AW.y = 0;

					Vector2 size = { playerSize.x,playerSize.x };

					for (int i = 0; i < boxcount; i++)
					{
						playerPos = BoxCollision(
							playerPos,
							size,
							playerCheckSizeUD,
							Box[i],
							BoxSize,
							BoxSizeUD[i],
							DS,
							AW);
					}

					for (int i = 0; i < boxcount; i++)
					{
						playerPos = BoxCollision(
							playerPos,
							size,
							playerCheckSizeUD,
							Box[i],
							BoxSizeLR[i],
							BoxSize,
							DS,
							AW);
					}

					size.x = playerSize.y;
					size.y = playerSize.y;

					for (int i = 0; i < boxcount; i++)
					{
						playerPos = BoxCollision(
							playerPos,
							playerCheckSizeRL,
							size,
							Box[i],
							BoxSize,
							BoxSizeUD[i],
							DS,
							AW);
					}

					for (int i = 0; i < boxcount; i++)
					{
						playerPos = BoxCollision(
							playerPos,
							playerCheckSizeRL,
							size,
							Box[i],
							BoxSizeLR[i],
							BoxSize,
							DS,
							AW);
					}
				}
			}
			else
			{
				if (JumpFlag)
				{
					DS.x = 0;
					DS.y = 0;

					AW.x = 0;
					AW.y = 1;

					for (int i = 0; i < (int)Jump; i++)
					{
						playerPos.y -= 1;

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								playerCheckSizeUD,
								Box[i],
								BoxSize,
								BoxSizeUD[i],
								DS,
								AW);
						}

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								playerCheckSizeUD,
								Box[i],
								BoxSizeLR[i],
								BoxSize,
								DS,
								AW);
						}
					}

				}
				else
				{
					DS.x = 0;
					DS.y = 1;

					AW.x = 0;
					AW.y = 0;

					for (int i = 0; i < boxcount; i++)
					{
						playerPos = BoxCollision(
							playerPos,
							playerCheckSizeRL,
							playerCheckSizeUD,
							Box[i],
							BoxSize,
							BoxSizeUD[i],
							DS,
							AW);
					}

					for (int i = 0; i < boxcount; i++)
					{
						playerPos = BoxCollision(
							playerPos,
							playerCheckSizeRL,
							playerCheckSizeUD,
							Box[i],
							BoxSizeLR[i],
							BoxSize,
							DS,
							AW);
					}
				}
			}
		}

		sukeF = false;
		kadoF = false;

		if (JumpFlag == false)
		{
			if (Gravity < 2.0f)
				Gravity += GravityPower;

			if (GravityPower < 0.1f)
				GravityPower += 0.02f;
		}
		else if (JumpFlag == true)
		{
			Gravity = 0;
			GravityPower = 0;

			Jump -= JumpPower;

			if (JumpPower < 0.1f)
				JumpPower += 0.05f;

			//playerPos.y -= Jump;

			if (Jump < 9.5f)
			{
				JumpFlag = false;
				Jump = 0;
			}
		}

		DS.x = 0;
		DS.y = 0;

		AW.x = 0;
		AW.y = 0;

		playerCheckPos = playerPos;
		playerCheckSize = playerSize;

		playerCheckSizeRL.x = playerSize.x;
		playerCheckSizeRL.y = playerSize.x;

		playerCheckSizeUD.x = playerSize.y;
		playerCheckSizeUD.y = playerSize.y;

		for (int i = 0; i < boxcount; i++)
		{
			BoxSizeLR[i].x = 16;
			BoxSizeLR[i].y = 16;
			BoxSizeUD[i].x = 16;
			BoxSizeUD[i].y = 16;
		}

		for (int i = 0; i < boxcount; i++)
		{
			//プレイヤーの上下左右
			p_top = Box[i].y - BoxSize.y;
			p_bottom = Box[i].y + BoxSize.y;
			p_right = Box[i].x + BoxSize.x;
			p_left = Box[i].x - BoxSize.x;

			//ルターの上下左右
			f_top = filterPos.y - filterSize.y;
			f_bottom = filterPos.y + filterSize.y;
			f_right = filterPos.x + filterSize.x;
			f_left = filterPos.x - filterSize.x;

			//フィルターに当たっているかBOXver
			if (p_left < f_right &&
				p_right > f_left &&
				p_top  < f_bottom &&
				p_bottom > f_top)
			{
				if (p_right < f_right &&
					p_left > f_left &&
					p_bottom  < f_bottom &&
					p_top > f_top)
				{
					BoxSizeLR[i].x = 0;
					BoxSizeLR[i].y = 0;
					BoxSizeUD[i].x = 0;
					BoxSizeUD[i].y = 0;
				}
				else
				{
					//どこの辺がプレイヤーに当たっているか
					//右上
					if (p_right > f_right &&
						p_left < f_right &&
						p_bottom > f_top &&
						p_top < f_top)
					{
						BoxSizeLR[i].x = Box[i].x - (filterPos.x + (filterSize.x));

						BoxSizeUD[i].y = (filterPos.y - (filterSize.y)) - Box[i].y;
					}
					//右下
					else if (
						p_right > f_right &&
						p_left < f_right &&
						p_bottom > f_bottom &&
						p_top < f_bottom)
					{
						BoxSizeLR[i].x = Box[i].x - (filterPos.x + (filterSize.x));

						BoxSizeUD[i].x = Box[i].y - (filterPos.y + (filterSize.y));
					}
					//左上
					else if (
						p_right > f_left &&
						p_left < f_left &&
						p_bottom > f_top &&
						p_top < f_top)
					{
						BoxSizeLR[i].y = (filterPos.x - (filterSize.x)) - Box[i].x;

						BoxSizeUD[i].y = (filterPos.y - (filterSize.y)) - Box[i].y;
					}
					//左下
					else if (
						p_right > f_left &&
						p_left < f_left &&
						p_bottom > f_bottom &&
						p_top < f_bottom)
					{
						BoxSizeLR[i].y = (filterPos.x - (filterSize.x)) - Box[i].x;

						BoxSizeUD[i].x = Box[i].y - (filterPos.y + (filterSize.y));
					}
					//右
					else if (
						p_right > f_right &&
						p_left < f_right)
					{
						BoxSizeLR[i].x = Box[i].x - (filterPos.x + (filterSize.x));

					}
					//左
					else if (p_right > f_left &&
						p_left < f_left)
					{
						BoxSizeLR[i].y = (filterPos.x - (filterSize.x)) - Box[i].x;
					}
					//上
					else if (p_bottom > f_top &&
						p_top < f_top)
					{
						//あってる
						BoxSizeUD[i].y = (filterPos.y - (filterSize.y / 2)) - Box[i].y - (BoxSize.y * 2);
					}
					//下
					else if (p_bottom > f_bottom &&
						p_top < f_bottom)
					{
						//できた
						BoxSizeUD[i].x = Box[i].y - (BoxSize.y * 2) - (filterPos.y + (filterSize.y / 2));
					}
				}
			}
		}


		//プレイヤーの上下左右
		p_top = playerCheckPos.y - playerCheckSize.y;
		p_bottom = playerCheckPos.y + playerCheckSize.y;
		p_right = playerCheckPos.x + playerCheckSize.x;
		p_left = playerCheckPos.x - playerCheckSize.x;

		//ルターの上下左右
		f_top = filterPos.y - filterSize.y;
		f_bottom = filterPos.y + filterSize.y;
		f_right = filterPos.x + filterSize.x;
		f_left = filterPos.x - filterSize.x;

		//フィルターに当たっているか
		if (p_left < f_right &&
			p_right > f_left &&
			p_top  < f_bottom &&
			p_bottom > f_top)
		{
			DrawFormatString(100, 200, 0xffffff, "hit");

			/*Gravity = 0;
			GravityPower = 0.0f;*/

			//完全にフィルター内にいるか
			if (p_right < f_right &&
				p_left > f_left &&
				p_bottom  < f_bottom &&
				p_top > f_top)
			{
				DrawFormatString(100, 220, 0xffffff, "Phit");

				sukeF = true;

				/*Gravity = 0;
				GravityPower = 0.0f;*/
			}
			else
			{
				//どこの辺がプレイヤーに当たっているか

				//右上
				if (p_right > f_right &&
					p_left < f_right &&
					p_bottom > f_top &&
					p_top < f_top)
				{
					playerCheckSizeRL.y = playerPos.x - (filterPos.x + (filterSize.x));
					DrawFormatString(100, 240, 0xffffff, "right");

					playerCheckSizeUD.y = (filterPos.y - (filterSize.y)) - playerPos.y;
					DrawFormatString(100, 280, 0xffffff, "up");

					kadoF = true;
				}
				//右下
				else if (
					p_right > f_right &&
					p_left < f_right &&
					p_bottom > f_bottom &&
					p_top < f_bottom)
				{
					playerCheckSizeRL.y = playerPos.x - (filterPos.x + (filterSize.x));
					DrawFormatString(100, 240, 0xffffff, "right");

					playerCheckSizeUD.x = playerPos.y - (filterPos.y + (filterSize.y));
					DrawFormatString(100, 300, 0xffffff, "down");

					kadoF = true;
				}
				//左上
				else if (
					p_right > f_left &&
					p_left < f_left &&
					p_bottom > f_top &&
					p_top < f_top)
				{
					playerCheckSizeRL.x = (filterPos.x - (filterSize.x)) - playerPos.x;
					DrawFormatString(100, 260, 0xffffff, "left");

					playerCheckSizeUD.y = (filterPos.y - (filterSize.y)) - playerPos.y;
					DrawFormatString(100, 280, 0xffffff, "up");

					kadoF = true;
				}
				//左下
				else if (
					p_right > f_left &&
					p_left < f_left &&
					p_bottom > f_bottom &&
					p_top < f_bottom)
				{
					playerCheckSizeRL.x = (filterPos.x - (filterSize.x)) - playerPos.x;
					DrawFormatString(100, 260, 0xffffff, "left");

					playerCheckSizeUD.x = playerPos.y - (filterPos.y + (filterSize.y));
					DrawFormatString(100, 300, 0xffffff, "down");

					kadoF = true;
				}
				//右
				else if (
					p_right > f_right &&
					p_left < f_right)
				{
					playerCheckSizeRL.y = playerPos.x - (filterPos.x + (filterSize.x));
					DrawFormatString(100, 240, 0xffffff, "right");

				}
				//左
				else if (p_right > f_left &&
					p_left < f_left)
				{

					playerCheckSizeRL.x = (filterPos.x - (filterSize.x)) - playerPos.x;
					DrawFormatString(100, 260, 0xffffff, "left");
				}
				//上
				else if (p_bottom > f_top &&
					p_top < f_top)
				{
					//あってる
					playerCheckSizeUD.y = (filterPos.y - (filterSize.y / 2)) - playerPos.y - playerSize.y;
					DrawFormatString(100, 280, 0xffffff, "up");
				}
				//下
				else if (p_bottom > f_bottom &&
					p_top < f_bottom)
				{
					//できた
					playerCheckSizeUD.x = playerPos.y - playerSize.y - (filterPos.y + (filterSize.y / 2));

					DrawFormatString(100, 300, 0xffffff, "down");
				}
			}
		}

		if (chengeF)
		{
			if (CheckHitKey(KEY_INPUT_D))
			{
				playerPos.x += moveSpd;

				DS.x = CheckHitKey(KEY_INPUT_D);
				DS.y = 0;

				AW.x = 0;
				AW.y = 0;

				if (!sukeF)
				{
					if (kadoF)
					{
						Vector2 size = { playerSize.x,playerSize.x };

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								size,
								playerCheckSizeUD,
								Box[i],
								BoxSize,
								BoxSizeUD[i],
								DS,
								AW);
						}

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								size,
								playerCheckSizeUD,
								Box[i],
								BoxSizeLR[i],
								BoxSize,
								DS,
								AW);
						}

						size.x = playerSize.y;
						size.y = playerSize.y;

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								size,
								Box[i],
								BoxSize,
								BoxSizeUD[i],
								DS,
								AW);
						}

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								size,
								Box[i],
								BoxSizeLR[i],
								BoxSize,
								DS,
								AW);
						}
					}
					else
					{
						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								playerCheckSizeUD,
								Box[i],
								BoxSize,
								BoxSizeUD[i],
								DS,
								AW);
						}

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								playerCheckSizeUD,
								Box[i],
								BoxSizeLR[i],
								BoxSize,
								DS,
								AW);
						}
					}
				}
			}

			if (CheckHitKey(KEY_INPUT_A))
			{
				playerPos.x -= moveSpd;

				DS.x = 0;
				DS.y = 0;

				AW.x = CheckHitKey(KEY_INPUT_A);
				AW.y = 0;

				if (!sukeF)
				{
					if (kadoF)
					{
						Vector2 size = { playerSize.x,playerSize.x };

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								size,
								playerCheckSizeUD,
								Box[i],
								BoxSize,
								BoxSizeUD[i],
								DS,
								AW);
						}

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								size,
								playerCheckSizeUD,
								Box[i],
								BoxSizeLR[i],
								BoxSize,
								DS,
								AW);
						}

						size.x = playerSize.y;
						size.y = playerSize.y;

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								size,
								Box[i],
								BoxSize,
								BoxSizeUD[i],
								DS,
								AW);
						}

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								size,
								Box[i],
								BoxSizeLR[i],
								BoxSize,
								DS,
								AW);
						}
					}
					else
					{
						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								playerCheckSizeUD,
								Box[i],
								BoxSize,
								BoxSizeUD[i],
								DS,
								AW);
						}

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								playerCheckSizeUD,
								Box[i],
								BoxSizeLR[i],
								BoxSize,
								DS,
								AW);
						}
					}
				}
			}

			//if (CheckHitKey(KEY_INPUT_S))
			//{
			//	playerPos.y += moveSpd;

			//	DS.x = 0;
			//	DS.y = CheckHitKey(KEY_INPUT_S);
			//	//DS.y = 1;

			//	AW.x = 0;
			//	AW.y = 0;

			//	if (!sukeF)
			//	{
			//		if (kadoF)
			//		{
			//			Vector2 size = { playerSize.x,playerSize.x };

			//			for (int i = 0; i < boxcount; i++)
			//			{
			//				playerPos = BoxCollision(
			//					playerPos,
			//					size,
			//					playerCheckSizeUD,
			//					Box[i],
			//					BoxSize,
			//					BoxSizeUD[i],
			//					DS,
			//					AW);
			//			}

			//			for (int i = 0; i < boxcount; i++)
			//			{
			//				playerPos = BoxCollision(
			//					playerPos,
			//					size,
			//					playerCheckSizeUD,
			//					Box[i],
			//					BoxSizeLR[i],
			//					BoxSize,
			//					DS,
			//					AW);
			//			}

			//			size.x = playerSize.y;
			//			size.y = playerSize.y;

			//			for (int i = 0; i < boxcount; i++)
			//			{
			//				playerPos = BoxCollision(
			//					playerPos,
			//					size,
			//					playerCheckSizeUD,
			//					Box[i],
			//					BoxSize,
			//					BoxSizeUD[i],
			//					DS,
			//					AW);
			//			}

			//			for (int i = 0; i < boxcount; i++)
			//			{
			//				playerPos = BoxCollision(
			//					playerPos,
			//					size,
			//					playerCheckSizeUD,
			//					Box[i],
			//					BoxSizeLR[i],
			//					BoxSize,
			//					DS,
			//					AW);
			//			}
			//		}
			//		else
			//		{
			//			for (int i = 0; i < boxcount; i++)
			//			{
			//				playerPos = BoxCollision(
			//					playerPos,
			//					playerCheckSizeRL,
			//					playerCheckSizeUD,
			//					Box[i],
			//					BoxSize,
			//					BoxSizeUD[i],
			//					DS,
			//					AW);
			//			}

			//			for (int i = 0; i < boxcount; i++)
			//			{
			//				playerPos = BoxCollision(
			//					playerPos,
			//					playerCheckSizeRL,
			//					playerCheckSizeUD,
			//					Box[i],
			//					BoxSizeLR[i],
			//					BoxSize,
			//					DS,
			//					AW);
			//			}
			//		}
			//	}
			//}

			if (CheckHitKey(KEY_INPUT_W) &&
				oldkeys[KEY_INPUT_W] == false)
			{
				//playerPos.y -= moveSpd;

				if (JumpFlag == false)
				{
					JumpFlag = true;

					Gravity = 0;
					GravityPower = 0;

					Jump = 10;
					JumpPower = 0;
				}

				/*DS.x = 0;
				DS.y = 0;

				AW.x = 0;
				AW.y = (int)JumpFlag;

				if (!sukeF)
				{
					if (kadoF)
					{
						Vector2 size = { playerSize.x,playerSize.x };

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								size,
								playerCheckSizeUD,
								Box[i],
								BoxSize,
								BoxSizeUD[i],
								DS,
								AW);
						}

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								size,
								playerCheckSizeUD,
								Box[i],
								BoxSizeLR[i],
								BoxSize,
								DS,
								AW);
						}

						size.x = playerSize.y;
						size.y = playerSize.y;

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								size,
								playerCheckSizeUD,
								Box[i],
								BoxSize,
								BoxSizeUD[i],
								DS,
								AW);
						}

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								size,
								playerCheckSizeUD,
								Box[i],
								BoxSizeLR[i],
								BoxSize,
								DS,
								AW);
						}
					}
					else
					{
						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								playerCheckSizeUD,
								Box[i],
								BoxSize,
								BoxSizeUD[i],
								DS,
								AW);
						}

						for (int i = 0; i < boxcount; i++)
						{
							playerPos = BoxCollision(
								playerPos,
								playerCheckSizeRL,
								playerCheckSizeUD,
								Box[i],
								BoxSizeLR[i],
								BoxSize,
								DS,
								AW);
						}
					}
				}*/
			}
		}
		else
		{
			filterPos.x += (CheckHitKey(KEY_INPUT_D) - CheckHitKey(KEY_INPUT_A)) * moveSpd;
			filterPos.y += (CheckHitKey(KEY_INPUT_S) - CheckHitKey(KEY_INPUT_W)) * moveSpd;
		}


		// 描画処理

		int ColorC = 0x003333;

		if (CF)
		{
			ColorC = 0x333300;
		}

		DrawCircle(circlePos.x, circlePos.y, CSize, ColorC, true);

		//通常
		/*DrawBox(playerPos.x - playerSize.x,
			playerPos.y - playerSize.y,
			playerPos.x + playerSize.x,
			playerPos.y + playerSize.y,
			0x777777,
			false);*/

			//player.Draw()

		//ボックス
		for (int i = 0; i < boxcount; i++)
		{
			DrawBox(
				Box[i].x - BoxSize.x,
				Box[i].y - BoxSize.x,
				Box[i].x + BoxSize.x,
				Box[i].y + BoxSize.y,
				0x007777,
				true);

			DrawBox(
				Box[i].x - BoxSize.x,
				Box[i].y - BoxSizeUD[i].x,
				Box[i].x + BoxSize.y,
				Box[i].y + BoxSizeUD[i].y,
				0x770000,
				false);

			DrawBox(
				Box[i].x - BoxSizeLR[i].x,
				Box[i].y - BoxSize.x,
				Box[i].x + BoxSizeLR[i].y,
				Box[i].y + BoxSize.y,
				0x770000,
				false);
		};

		//プレイヤー上下左右
		DrawBox(
			playerPos.x - playerCheckSizeRL.y,
			playerPos.y - playerCheckSizeUD.x,
			playerPos.x + playerCheckSizeRL.x + 1,
			playerPos.y + playerCheckSizeUD.y + 1,
			0x770077,
			true);

		//左右
		DrawBox(
			playerPos.x - playerCheckSizeRL.y,
			playerPos.y - playerSize.y,
			playerPos.x + playerCheckSizeRL.x,
			playerPos.y + playerSize.y,
			0x007777,
			false);

		//上下
		DrawBox(
			playerPos.x - playerSize.x,
			playerPos.y - playerCheckSizeUD.x,
			playerPos.x + playerSize.x,
			playerPos.y + playerCheckSizeUD.y,
			0x770077,
			false);

		//フィルター
		DrawBox(
			filterPos.x - filterSize.x,
			filterPos.y - filterSize.y,
			filterPos.x + filterSize.x,
			filterPos.y + filterSize.y,
			0xaaaaaa,
			false);

		//情報表示
		if (chengeF)
		{
			DrawFormatString(400, 0, 0xffffff, "nowMoveObj: player");
		}
		else
		{
			DrawFormatString(400, 0, 0xffffff, "nowMoveObj: filter");
		}

	/*	DrawFormatString(400, 30, 0xffffff, "playerPos%f,%f", playerPos.x, playerPos.y);
		DrawFormatString(400, 50, 0xffffff, "playerSize%f,%f", playerSize.x, playerSize.y);
		DrawFormatString(400, 70, 0xffffff, "playerSizeRL%f,%f", playerCheckSizeRL.x, playerCheckSizeRL.y);
		DrawFormatString(400, 90, 0xffffff, "playerSizeUD%f,%f", playerCheckSizeUD.x, playerCheckSizeUD.y);
		DrawFormatString(400, 130, 0xffffff, "Gravity%f,%f", Gravity, GravityPower);
		DrawFormatString(400, 110, 0xffffff, "suke:%d", sukeF);
		DrawFormatString(400, 150, 0xffffff, "Jump:%f,%f", Jump, JumpPower);*/

		DrawFormatString(400, 10 + 10, 0xffffff, "AD:横移動");
		DrawFormatString(400, 10 + 30, 0xffffff, "W:ジャンプ");
		DrawFormatString(400, 30 + 30, 0xffffff, "SPACE:プレイヤーとフィルターの操作切り替え");
		DrawFormatString(400, 50 + 30, 0xffffff, "プレイヤーが完全にフィルター内にいると切り替えできません");
		DrawFormatString(400, 70 + 30, 0xffffff, "R:プレイヤーの位置リセット");
		DrawFormatString(400, 90 + 30, 0xffffff, "まだまだバグが多いので直す");


		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}
