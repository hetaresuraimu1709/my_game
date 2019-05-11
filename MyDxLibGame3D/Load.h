#ifndef _LOAD_H_
#define _LOAD_H_

#include "Header.h"

// �ǂݍ��ރt�@�C���̑���
#define FILENUM 300

// �Q�[�W�̕�
#define GAUGEWIDTH 300

struct Load
{
public:
	void DrawLoadingScreen();
	void Init();
	void NowLoading();
	bool end_flag = false;
private:
	// �摜�n���h��
	int GrHandle[FILENUM];
	// �ǂݍ���ł���摜�̔ԍ�
	int LoadingFile;

	int now_load = LoadGraph("data/title/NowLoading.png");
	double font_enlargement = 1.0;
	bool size_flag = false;
	Vector2 miffypos = VectorGet(1400.0f, 1000.0f);
};

#endif