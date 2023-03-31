#include "DxLib.h"
#include "Vector2.h"
#include "Player.h"

// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "�^�C�g��";

// �E�B���h�E����
const int WIN_WIDTH = 900;

// �E�B���h�E�c��
const int WIN_HEIGHT = 700;

Vector2 BoxCollision(Vector2 posP, Vector2 sizeP, Vector2 posF, Vector2 sizeF, Vector2 DS, Vector2 AW)
{
	Vector2 nowPosP = posP;
	Vector2 nowPosF = posF;

	//�v���C���[�̏㉺���E
	float p_top = nowPosP.y - sizeP.y;
	float p_bottom = nowPosP.y + sizeP.y;
	float p_right = nowPosP.x + sizeP.x;
	float p_left = nowPosP.x - sizeP.x;

	//�t�B���^�[�̏㉺���E
	float f_top = nowPosF.y - sizeF.y;
	float f_bottom = nowPosF.y + sizeF.y;
	float f_right = nowPosF.x + sizeF.x;
	float f_left = nowPosF.x - sizeF.x;

	//�t�B���^�[�ɓ������Ă��邩
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

			//�v���C���[�̏㉺���E
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

	//�v���C���[�̏㉺���E
	float p_top = nowPosP.y - sizePUD.x;
	float p_bottom = nowPosP.y + sizePUD.y;
	float p_right = nowPosP.x + sizePRL.x;
	float p_left = nowPosP.x - sizePRL.y;

	//�t�B���^�[�̏㉺���E
	float f_top = nowPosF.y - sizeF.y;
	float f_bottom = nowPosF.y + sizeF.y;
	float f_right = nowPosF.x + sizeF.x;
	float f_left = nowPosF.x - sizeF.x;

	//�t�B���^�[�ɓ������Ă��邩
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

			//�v���C���[�̏㉺���E
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

	//�v���C���[�̏㉺���E
	float p_top = nowPosP.y - sizePUD.x;
	float p_bottom = nowPosP.y + sizePUD.y;
	float p_right = nowPosP.x + sizePRL.x;
	float p_left = nowPosP.x - sizePRL.y;

	//�t�B���^�[�̏㉺���E
	float f_top = nowPosF.y - sizeUD.x;
	float f_bottom = nowPosF.y + sizeUD.y;
	float f_right = nowPosF.x + sizeLR.y;
	float f_left = nowPosF.x - sizeLR.x;

	//�t�B���^�[�ɓ������Ă��邩
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

			//�v���C���[�̏㉺���E
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
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���

	Player player;

	// �Q�[�����[�v�Ŏg���ϐ��̐錾

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

	//�{�b�N�X�̐�
	int boxcount = 20;

	//�L�[��������Ă��邩�ǂ���
	Vector2 DS;
	Vector2 AW;

	//�v���C���[���t�B���^�[��
	bool chengeF = true;

	//�v���C���[�����蔲���邩
	bool sukeF = false;

	//�t�B���^�[�̊p�ɓ������Ă��邩�ǂ���
	bool kadoF = false;

	Vector2 circlePos = { 0, 0 };
	int CSize = WIN_WIDTH * 2;
	bool CF = false;

	//�}�b�v��ɔz�u���Ă���u���b�N
	for (int i = 0; i < boxcount; i++)
	{
		Box[i].x = (i * 30);
		Box[i].y = (19 * 30);

		BoxSizeLR[i].x = 16;
		BoxSizeLR[i].y = 16;

		BoxSizeUD[i].x = 16;
		BoxSizeUD[i].y = 16;
	}

	//�ׂ��Ȓ���
	Box[19].x = (18 * 30);
	Box[19].y = (20 * 30);

	Box[15].x = (16 * 30) - 5;
	Box[15].y = (15 * 30);

	Box[2].x = (16 * 30) - 5;
	Box[2].y = (14 * 30) - 25;

	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	float Gravity = 0;
	float GravityPower = 0;

	//�v���C���[�̏㉺���E
	float p_top = playerCheckPos.y - playerCheckSize.y;
	float p_bottom = playerCheckPos.y + playerCheckSize.y;
	float p_right = playerCheckPos.x + playerCheckSize.x;
	float p_left = playerCheckPos.x - playerCheckSize.x;

	//�t�B���^�[�̏㉺���E
	float f_top = filterPos.y - filterSize.y;
	float f_bottom = filterPos.y + filterSize.y;
	float f_right = filterPos.x + filterSize.x;
	float f_left = filterPos.x - filterSize.x;

	bool JumpFlag = false;
	float JumpPower = 0;
	float Jump = 0;

	// �Q�[�����[�v
	while (true) {

		for (int i = 0; i < 256; i++)
		{
			oldkeys[i] = keys[i];
		}

		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//

		// �X�V����
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

		//�d��
		playerPos.y += Gravity;

		//��Ɖ��̖߂�����
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
			//�v���C���[�̏㉺���E
			p_top = Box[i].y - BoxSize.y;
			p_bottom = Box[i].y + BoxSize.y;
			p_right = Box[i].x + BoxSize.x;
			p_left = Box[i].x - BoxSize.x;

			//���^�[�̏㉺���E
			f_top = filterPos.y - filterSize.y;
			f_bottom = filterPos.y + filterSize.y;
			f_right = filterPos.x + filterSize.x;
			f_left = filterPos.x - filterSize.x;

			//�t�B���^�[�ɓ������Ă��邩BOXver
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
					//�ǂ��̕ӂ��v���C���[�ɓ������Ă��邩
					//�E��
					if (p_right > f_right &&
						p_left < f_right &&
						p_bottom > f_top &&
						p_top < f_top)
					{
						BoxSizeLR[i].x = Box[i].x - (filterPos.x + (filterSize.x));

						BoxSizeUD[i].y = (filterPos.y - (filterSize.y)) - Box[i].y;
					}
					//�E��
					else if (
						p_right > f_right &&
						p_left < f_right &&
						p_bottom > f_bottom &&
						p_top < f_bottom)
					{
						BoxSizeLR[i].x = Box[i].x - (filterPos.x + (filterSize.x));

						BoxSizeUD[i].x = Box[i].y - (filterPos.y + (filterSize.y));
					}
					//����
					else if (
						p_right > f_left &&
						p_left < f_left &&
						p_bottom > f_top &&
						p_top < f_top)
					{
						BoxSizeLR[i].y = (filterPos.x - (filterSize.x)) - Box[i].x;

						BoxSizeUD[i].y = (filterPos.y - (filterSize.y)) - Box[i].y;
					}
					//����
					else if (
						p_right > f_left &&
						p_left < f_left &&
						p_bottom > f_bottom &&
						p_top < f_bottom)
					{
						BoxSizeLR[i].y = (filterPos.x - (filterSize.x)) - Box[i].x;

						BoxSizeUD[i].x = Box[i].y - (filterPos.y + (filterSize.y));
					}
					//�E
					else if (
						p_right > f_right &&
						p_left < f_right)
					{
						BoxSizeLR[i].x = Box[i].x - (filterPos.x + (filterSize.x));

					}
					//��
					else if (p_right > f_left &&
						p_left < f_left)
					{
						BoxSizeLR[i].y = (filterPos.x - (filterSize.x)) - Box[i].x;
					}
					//��
					else if (p_bottom > f_top &&
						p_top < f_top)
					{
						//�����Ă�
						BoxSizeUD[i].y = (filterPos.y - (filterSize.y / 2)) - Box[i].y - (BoxSize.y * 2);
					}
					//��
					else if (p_bottom > f_bottom &&
						p_top < f_bottom)
					{
						//�ł���
						BoxSizeUD[i].x = Box[i].y - (BoxSize.y * 2) - (filterPos.y + (filterSize.y / 2));
					}
				}
			}
		}


		//�v���C���[�̏㉺���E
		p_top = playerCheckPos.y - playerCheckSize.y;
		p_bottom = playerCheckPos.y + playerCheckSize.y;
		p_right = playerCheckPos.x + playerCheckSize.x;
		p_left = playerCheckPos.x - playerCheckSize.x;

		//���^�[�̏㉺���E
		f_top = filterPos.y - filterSize.y;
		f_bottom = filterPos.y + filterSize.y;
		f_right = filterPos.x + filterSize.x;
		f_left = filterPos.x - filterSize.x;

		//�t�B���^�[�ɓ������Ă��邩
		if (p_left < f_right &&
			p_right > f_left &&
			p_top  < f_bottom &&
			p_bottom > f_top)
		{
			DrawFormatString(100, 200, 0xffffff, "hit");

			/*Gravity = 0;
			GravityPower = 0.0f;*/

			//���S�Ƀt�B���^�[���ɂ��邩
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
				//�ǂ��̕ӂ��v���C���[�ɓ������Ă��邩

				//�E��
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
				//�E��
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
				//����
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
				//����
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
				//�E
				else if (
					p_right > f_right &&
					p_left < f_right)
				{
					playerCheckSizeRL.y = playerPos.x - (filterPos.x + (filterSize.x));
					DrawFormatString(100, 240, 0xffffff, "right");

				}
				//��
				else if (p_right > f_left &&
					p_left < f_left)
				{

					playerCheckSizeRL.x = (filterPos.x - (filterSize.x)) - playerPos.x;
					DrawFormatString(100, 260, 0xffffff, "left");
				}
				//��
				else if (p_bottom > f_top &&
					p_top < f_top)
				{
					//�����Ă�
					playerCheckSizeUD.y = (filterPos.y - (filterSize.y / 2)) - playerPos.y - playerSize.y;
					DrawFormatString(100, 280, 0xffffff, "up");
				}
				//��
				else if (p_bottom > f_bottom &&
					p_top < f_bottom)
				{
					//�ł���
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


		// �`�揈��

		int ColorC = 0x003333;

		if (CF)
		{
			ColorC = 0x333300;
		}

		DrawCircle(circlePos.x, circlePos.y, CSize, ColorC, true);

		//�ʏ�
		/*DrawBox(playerPos.x - playerSize.x,
			playerPos.y - playerSize.y,
			playerPos.x + playerSize.x,
			playerPos.y + playerSize.y,
			0x777777,
			false);*/

			//player.Draw()

		//�{�b�N�X
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

		//�v���C���[�㉺���E
		DrawBox(
			playerPos.x - playerCheckSizeRL.y,
			playerPos.y - playerCheckSizeUD.x,
			playerPos.x + playerCheckSizeRL.x + 1,
			playerPos.y + playerCheckSizeUD.y + 1,
			0x770077,
			true);

		//���E
		DrawBox(
			playerPos.x - playerCheckSizeRL.y,
			playerPos.y - playerSize.y,
			playerPos.x + playerCheckSizeRL.x,
			playerPos.y + playerSize.y,
			0x007777,
			false);

		//�㉺
		DrawBox(
			playerPos.x - playerSize.x,
			playerPos.y - playerCheckSizeUD.x,
			playerPos.x + playerSize.x,
			playerPos.y + playerCheckSizeUD.y,
			0x770077,
			false);

		//�t�B���^�[
		DrawBox(
			filterPos.x - filterSize.x,
			filterPos.y - filterSize.y,
			filterPos.x + filterSize.x,
			filterPos.y + filterSize.y,
			0xaaaaaa,
			false);

		//���\��
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

		DrawFormatString(400, 10 + 10, 0xffffff, "AD:���ړ�");
		DrawFormatString(400, 10 + 30, 0xffffff, "W:�W�����v");
		DrawFormatString(400, 30 + 30, 0xffffff, "SPACE:�v���C���[�ƃt�B���^�[�̑���؂�ւ�");
		DrawFormatString(400, 50 + 30, 0xffffff, "�v���C���[�����S�Ƀt�B���^�[���ɂ���Ɛ؂�ւ��ł��܂���");
		DrawFormatString(400, 70 + 30, 0xffffff, "R:�v���C���[�̈ʒu���Z�b�g");
		DrawFormatString(400, 90 + 30, 0xffffff, "�܂��܂��o�O�������̂Œ���");


		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();

	// ����I��
	return 0;
}
