//-----------------------------------------------------------------------------
// @brief  ���C������.
// 2016 Takeru Yui All Rights Reserved.
//-----------------------------------------------------------------------------
#include "Header.h"
#include "Load.h"
#include "Save.h"

//-----------------------------------------------------------------------------
// @brief  ���C���֐�.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) 
{
	// ��ʃ��[�h�̃Z�b�g
	ChangeWindowMode(TRUE);
	SetGraphMode(1920, 1080, 16);
	SetWindowSizeExtendRate(0.7, 0.7);

	//�`���𗠉�ʂɕύX����B
	SetDrawScreen(DX_SCREEN_BACK);

	// DirectX9,11���g�p����悤�ɂ���B(�G�t�F�N�V�A�p)
	SetUseDirect3DVersion(DX_DIRECT3D_9);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;	// �G���[���N�����璼���ɏI��
	}

	// Effekseer������������B
	// �����ɂ͉�ʂɕ\������ő�p�[�e�B�N������ݒ肷��B
	if (Effkseer_Init(8000) == -1)
	{
		DxLib_End();
		return -1;
	}

	// �t���X�N���[���E�C���h�E�̐؂�ւ��Ń��\�[�X��������̂�h���B
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);

	// DX���C�u�����̃f�o�C�X���X�g�������̃R�[���o�b�N��ݒ肷��B
	Effekseer_SetGraphicsDeviceLostCallbackFunctions();

	// Z�o�b�t�@��L���ɂ���B
	// Effekseer���g�p����ꍇ�A2D�Q�[���ł�Z�o�b�t�@���g�p����B
	SetUseZBuffer3D(TRUE);

	// Z�o�b�t�@�ւ̏������݂�L���ɂ���B
	// Effekseer���g�p����ꍇ�A2D�Q�[���ł�Z�o�b�t�@���g�p����B
	SetWriteZBuffer3D(TRUE);

	// �����Ə�����
	Load load;
	load.Init();
	load.NowLoading();
	Title *c_title = new Title();
	End *c_end = new End();
	Memory *c_memory = new Memory();
	Player *c_player = new Player(*c_memory);
	c_player->Init();
	Camera *c_camera = new Camera();
	c_camera->Init();
	Map *c_map = new Map();
	c_map->Init();
	Enemy *c_enemy = new Enemy(*c_memory);
	Comment_string *c_string = new Comment_string();
	c_string->Init();
	Effect *c_effect = new Effect();
	c_effect->Init();
	Battle *c_battle = new Battle();
	c_battle->Init(c_camera, c_player);
	Music *c_music = new Music();
	Window *c_window = new Window();
	Field *c_field = new Field();
	c_field->Init();
	//Npc *c_npc = new Npc();
	//c_npc->Init();
	Chara_Status_Load(c_player->c_ally, 3);
	int scene = s_title;
	bool game_end_flag = false;
	load.end_flag = true;
	c_map->now_floor = 1;

	// �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && !game_end_flag)
	{
		// DX���C�u�����̃J������Effekseer�̃J�����𓯊�����B
		Effekseer_Sync3DSetting();

		//�L�[���Ƃ邽�߂̂��
		updateKey();

		//*********************
		// �����A�����蔻�蓙
		//*********************
		//�^�C�g��
		switch (scene)
		{
		case s_title:
			c_title->Move(&scene, c_music, &game_end_flag);
			break;
		case s_field:
			Status_Check(c_player->c_ally[0].status, c_player->c_ally[1].status, c_player->c_ally[2].status);
			//c_npc->Updata();
			if (!c_player->menu_open_flag)
			{
				c_player->Move(c_camera, c_map);
				c_player->Turn();
				c_enemy->Move(*c_map, *c_player);
				c_player->EnemyHit(&scene, c_enemy, c_battle, c_camera);
				c_camera->Move(*c_player, c_map);
				c_player->VectorReset();
			}
			if (CheckHitKey(KEY_INPUT_C))
			{
				Chara_Status_Save(c_player->c_ally);
			}
			c_field->Updata(c_player, *c_music);
			break;
		case s_battle:
			c_battle->Updata(&scene, c_player, c_enemy, c_camera, c_map, c_music);
			break;
		case s_end:
			c_end->Move(&scene);
			break;
		default:
			break;
		}

		

		// ��ʂ�����������
		ClearDrawScreen();
		//*********
		// �`��
		//*********
		//�^�C�g��
		switch (scene)
		{
		case s_title:
			c_music->field_theme_Stop();
			c_title->Draw(c_string, c_music, c_window);
			break;
		case s_field:
			//c_npc->Draw();
			c_music->field_theme(0);
			c_map->Field_Draw(c_effect);
			c_player->Draw();
			c_enemy->Draw(*c_map);
			c_effect->Draw(&c_effect->warp, 1500000000);
			c_field->Draw(c_player, c_string, c_window);
			break;
		case s_battle:
			c_music->field_theme_Stop();
			c_battle->Draw(&scene, c_player, c_enemy, c_map, c_camera, c_string, c_effect, c_music, c_window, c_memory);
			break;
		case s_end:
			c_music->field_theme_Stop();
			c_end->Draw(c_string, c_music);
			break;
		default:
			break;
		}
		
		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();
	}
	//���ꂼ������
	delete c_player;
	delete c_enemy;
	delete c_camera;
	delete c_map;
	delete c_battle;
	delete c_string;

	// Effekseer���I������B
	Effkseer_End();

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}