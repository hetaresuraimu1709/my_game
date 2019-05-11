// Enemy.h
//�G�l�~�[�̃w�b�_�[
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "CharaBese.h"

class Enemy
{
public:
	Chara enemy[ENEMY];
	int notice_count[ENEMY];
	int move_count[ENEMY];
	bool notice_flag[ENEMY];
	bool on_flag;
	Enemy(Memory memory);//�R���X�g���N�^
	~Enemy();//�f�X�g���N�^
	void Turn_Reset();
	void Move(Map map, Player player);//����
	void Draw(Map map);//�`��
    void Battle_AI(Battle *battle);
    void Battle_Draw(Battle battle, Effect *effect);
};

enum
{
	suraimu,
	suraimubesu,
	metarusuraimu,
	raimusuraimu,
	remonsuraimu
};

#endif // _ENEMY_H_