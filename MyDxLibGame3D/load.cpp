#include "Load.h"

// �ǂݍ��݉�ʕ`��֐�
void Load::DrawLoadingScreen()
{
	// �Q�[�W�̑S�̂��D�F�ŕ`��
	DrawBox(1200, 1050, 1200 + GAUGEWIDTH, 1075, GetColor(100, 0, 0), TRUE);

	// �����_�œǂݍ��ݏI����Ă��镪�𔒐F�ŕ`��
	DrawBox(1200, 1050, 1200 + (LoadingFile * GAUGEWIDTH / FILENUM), 1075, GetColor(0, 255, 0), TRUE);
}

void Load::Init()
{
	end_flag = false;
	now_load = LoadGraph("data/title/NowLoading.png");
	font_enlargement = 1.0;
	size_flag = false;
	miffypos = VectorGet(1400.0f, 1000.0f);
}

void Load::NowLoading()
{
	if(!end_flag)
	{
		// ��ʂ̏�����
		ClearDrawScreen();

		DrawRotaGraph(1600, 1030, font_enlargement, 0.0, now_load, true);

		// ����ʂ̓��e��\��ʂɔ��f
		ScreenFlip();
	}
}
