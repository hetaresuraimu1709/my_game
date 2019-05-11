//Player.h
//�v���C���[�̃w�b�_�[
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "CharaBese.h"

class Map;
class Enemy;
class Camera;
class Battle;
class Memory;

class Player
{
public:
	int ShadowMapHandle;
	int run_animation;
	int AnimAttachIndex[ANIM_MAX];
	float Rate;
	float jumppow;
	float AnimTotalTime[ANIM_MAX];
	float AnimNowTime;
	int now_anim;//���݂̃A�j���[�V����
	float dir_angle;//�L�����̌����Ă���p�x
	float dir_angle_plas;//�����Ă�����ɉ��Z
	int vertical_dir;//�O��̌���
	int heng_dir;//���E�̌���
	bool menu_open_flag;
	bool left_turn_flag;
	bool right_turn_flag;
	bool ahead_turn_flag;
	bool rear_turn_flag;
	bool ahead_left_turn_flag;
	bool ahead_right_turn_flag;
	bool rear_left_turn_flag;
	bool rear_right_turn_flag;
	bool jumpflag;
	bool keyflag;
	bool ahead_hit_flag;
	bool rear_hit_flag;
	bool left_hit_flag;
	bool right_hit_flag;
	bool warp_flag;
	Vector3 pos,vec;//���W
	Vector3 UpMove;//W�ړ��̃x�N�g��
	Vector3 DownMove;//S�ړ�
	Vector3 LeftMove;//A�ړ�
	Vector3 RightMove;//D�ړ�
	Chara c_ally[3];
	Chara hoge_chara;
	Player(Memory memory);//�R���X�g���N�^
	~Player();//�f�X�g���N�^
	void Init();
	void Turn_Reset();
	void Move(Camera *camera,Map *map);//����
	void Turn();
	void WallHit(Map map, int map_data[BATTLE_MAP_CHIP][BATTLE_MAP_CHIP]);
	void EnemyHit(int *scene, Enemy *enemy, Battle *battle, Camera *camera);
	void VectorReset();
	void Draw();//�`��
	void BattleDraw(Battle battle);
};
#endif // _PLAYER_H_