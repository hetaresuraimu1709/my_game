//Define.h

#ifndef _DEFINE_H_
#define _DEFINE_H_

//��ʃT�C�Y
#define SCREEN_W 1920
#define SCREEN_H 1080

//�L�����̏����X�e�[�^�X
#define ALLY_1_NAME     "�N���~"
#define ALLY_1_FIRST_HP  50
#define ALLY_1_FIRST_MP  5
#define ALLY_1_FIRST_STR 30
#define ALLY_1_FIRST_DEF 45
#define ALLY_1_FIRST_MST 5
#define ALLY_1_FIRST_MHL 5
#define ALLY_1_FIRST_SKI 15
#define ALLY_1_FIRST_SPD 10
#define ALLY_2_NAME      "���J��"
#define ALLY_2_FIRST_HP  25
#define ALLY_2_FIRST_MP  50
#define ALLY_2_FIRST_STR 5
#define ALLY_2_FIRST_DEF 10
#define ALLY_2_FIRST_MST 50
#define ALLY_2_FIRST_MHL 20
#define ALLY_2_FIRST_SKI 50
#define ALLY_2_FIRST_SPD 15
#define ALLY_3_NAME      "�o�u�~"
#define ALLY_3_FIRST_HP  10
#define ALLY_3_FIRST_MP  40
#define ALLY_3_FIRST_STR 10
#define ALLY_3_FIRST_DEF 50
#define ALLY_3_FIRST_MST 15
#define ALLY_3_FIRST_MHL 50
#define ALLY_3_FIRST_SKI 10
#define ALLY_3_FIRST_SPD 50

//�L�����̓����֌W
#define GRAVITY 0.3f//�d��
#define vertical_dir_SPEED 20.f//
#define PLAYER_REAR 360.f//�O
#define PLAYER_LEFT 90.f//��
#define PLAYER_AHEAD 180.f//���
#define PLAYER_RIGHT 270.f//�E
#define ANIM_MAX 3//�O�F�_�����A�P�F�����A�Q�F����
//�}�b�v�֌W
#define MAP_CHIP 50//�}�b�v�̏c���T�C�Y
#define BATTLE_MAP_CHIP 25//�o�g���}�b�v�̏c���T�C�Y
#define MAP_BLOCK_SIZE 50.f//�}�b�v�`�b�v���̏c���T�C�Y

//�G�֌W
#define ENEMY 5//�G�̎�ސ�
#define BOSS_NAME "�h���S��"
#define ENEMY_NOTICE 100.f
#define ENEMY_B_POS_X 545
#define ENEMY_B_POS_Y 530

//���R�}���h�֌W��
//�L�[
#define KEY_ANIM_LOAD 2
#define KEY_ANIM_FRAME 8
//�ŏ��̃��c
#define FIRST_COMMAND_X 27.5f
#define FIRST_COMMAND_Y SCREEN_H - 110 - 10
//�X�e�[�^�X�E�B���h�E
#define STATUS_COMMAND_SIZE_X 907
#define STATUS_COMMAND_SIZE_Y 285
//���
#define KEY_1ST_COMMAND_SIZE_X 224
#define KEY_1ST_COMMAND_SIZE_Y 240
#define KEY_1ST_COMMAND_X 20
#define KEY_1ST_COMMAND_Y SCREEN_H - KEY_1ST_COMMAND_SIZE_Y - 50
#define KEY_1ST_POS_X 5
#define KEY_1ST_POS_Y 40
#define KEY_1ST_MOVE_Y 70.0f
#define KEY_1ST_MAX_COMMAND 3
//���O�̂��
#define NAME_COMMAND_SIZE_X 224
#define NAME_COMMAND_SIZE_Y 70
#define NAME_COMMAND_X 20
#define NAME_COMMAND_Y -71
//���
#define KEY_2ND_COMMAND_SIZE_X 700
#define KEY_2ND_COMMAND_SIZE_Y 229
#define KEY_2ND_COMMAND_X KEY_1ST_COMMAND_X + KEY_1ST_COMMAND_SIZE_X + 20
#define KEY_2ND_COMMAND_Y SCREEN_H - KEY_1ST_COMMAND_SIZE_Y - 50
#define KEY_2ND_POS_X 10
#define KEY_2ND_POS_Y 40
#define KEY_2ND_MOVE_X 230.0f
#define KEY_2ND_MOVE_Y 120.0f
#define KEY_2ND_MAX_COMMAND_X 3
#define KEY_2ND_MAX_COMMAND_Y 2
//�O��
#define KEY_3RD_COMMAND_SIZE_X 761
#define KEY_3RD_COMMAND_SIZE_Y 229
#define KEY_3RD_COMMAND_X KEY_2ND_COMMAND_X + KEY_2ND_COMMAND_SIZE_X + 20
#define KEY_3RD_COMMAND_Y SCREEN_H - KEY_1ST_COMMAND_SIZE_Y - 50
#define KEY_3RD_POS_X 30
#define KEY_3RD_POS_Y 20
#define KEY_3RD_MOVE_X 200.0f
#define KEY_3RD_MOVE_Y 55.0f
#define KEY_3RD_MAX_COMMAND_Y 4
//���@�R�}���h
#define KEY_MAGIC_COMMAND_SIZE_X 1000
#define KEY_MAGIC_COMMAND_SIZE_Y 229
#define KEY_MAGIC_COMMAND_X KEY_2ND_COMMAND_X
#define KEY_MAGIC_COMMAND_Y KEY_2ND_COMMAND_Y - KEY_1ST_COMMAND_SIZE_Y - 10
#define KEY_MAGIC_POS_X 30
#define KEY_MAGIC_POS_Y 40
#define KEY_MAGIC_MOVE_X 300.0f
#define KEY_MAGIC_MOVE_Y 120.0f
#define KEY_MAGIC_MAX_COMMAND_X 3
#define KEY_MAGIC_MAX_COMMAND_Y 2
//�R�}���h�������X�s�[�h
#define KEY_SPEED 0.8f

//�����֌W
#define NUMBER_MAX_X 10
#define NUMBER_MAX_Y 1
#define NUMBER_SIZE_X 50.0f
#define NUMBER_SIZE_Y 50.0f

//�����֌W
#define STRING_SIZE_W 50
#define STRING_SIZE_H 50
#define STRING_NUM 200
#define STRING_XNUM 10
#define STRING_YNUM 20

//���@�̍ő吔
#define SPELL_MAX 16
#define SKILL_MAX 16
#define ITEM_MAX 16

//���y�֌W
#define BGM_VOL_THROW 0

//�ڂ���
#define BOKASI 3.0f

//�R�}���h�E�B���h�E�̘g
#define COMMAND_WINDOW_LINE_SIZE 10

//���j���[��ʂ̃E�B���h�E�T�C�Y
#define MENU_WINDOW_SIZE_X_0 350.0f
#define MENU_WINDOW_SIZE_Y_0 550.0f
#define KEY_COMMAND_X_0 20
#define KEY_COMMAND_Y_0 SCREEN_H - KEY_1ST_COMMAND_SIZE_Y - 50
#define KEY_POS_X_0 55.0f
#define KEY_POS_Y_0 52.5f
#define KEY_MOVE_Y_0 100.0f
#define KEY_MAX_COMMAND_0 5
#define MENU_WINDOW_SIZE_X_1 1000.0f
#define MENU_WINDOW_SIZE_Y_1 400.0f

//�����ڕW�o���l
#define EXP_GOAL_1ST 5

struct Vector3
{
	float x, y, z;
};

struct Vector2
{
    float x, y;
};

struct Point
{
	float x, y, z;
};
enum
{
	nodir,//�ǂ����Ȃ�
	left,//��
	right,//�E
	ahead,//�O��
	rear,//���
};

enum scene
{
	s_title,//�^�C�g�����
	s_field,//�t�B�[���h���
	s_battle,//�o�g�����
	s_end,//�G���f�B���O
};

enum stauts_
{
	_level_,		//���x��
	_max_hp_,		//�̗͂̍ő�l
	_hp_,			//�̗�
	_max_mp_,		//���͂̍ő�l
	_mp_,			//����
	_pow_,		//�U����
	_def_,		//�h���
	_m_pow_,		//�U������
	_m_res_,		//�񕜖���
	_ski_,		//��p��
	_spd_,		//�f����
	_exp_,		//�o���l��
	_exp_goal_,	//���̖ڕW�o���l
};

#endif
