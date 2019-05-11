#ifndef _CHARABESE_H_
#define _CHARABESE_H_

struct Inventory
{
	int number;
	bool use_flag;
	std::string name;
	int damage_bonus;
	int force;
};

class Chara
{
public:
	Vector3 f_pos;				//�t�B�[���h���W
	Vector3 b_pos;				//�o�g�����W
	Vector3 vec;				//�ړ��x�N�g��
	Vector3 first_pos;			//�o�g���̏����|�W�V����
    std::string name;			//���O
	std::string name_origin;	//���O
	int modelHandle;			//�摜
	int status[13];
	bool ally_or_enemy_flag;//�������G���̃t���O��true�������@false���G��
	//�ŏ��̃R�}���h�t���O
	bool first_command_flag;//�ŏ��̃R�}���h��ł������ǂ����̃t���O
	bool first_behavior_flag[KEY_1ST_MAX_COMMAND];//�ŏ��̃R�}���h
	//�Q�Ԗڂ̃R�}���h�t���O
	bool second_command_flag;//�Q�Ԗڂ̃R�}���h��ł������ǂ����̃t���O
	bool second_behavior_flag[KEY_2ND_MAX_COMMAND_Y * KEY_2ND_MAX_COMMAND_X];//�ŏ��̃R�}���h
	//�ǂ̖��@���g����
	bool magic_command_flag;//�Q�Ԗڂ̃R�}���h��ł������ǂ����̃t���O
	//�����_������
	bool who_command_flag[KEY_3RD_MAX_COMMAND_Y];
	
	Inventory magic[KEY_MAGIC_MAX_COMMAND_X * KEY_MAGIC_MAX_COMMAND_Y];//���@
	Inventory skill[KEY_MAGIC_MAX_COMMAND_X * KEY_MAGIC_MAX_COMMAND_Y];//���Z
	Inventory item[KEY_MAGIC_MAX_COMMAND_X * KEY_MAGIC_MAX_COMMAND_Y];//����

	//�R�}���h�����I���̃t���O
	bool turn_flag;

	bool command_play_flag;	//�R�}���h�̍s������������ǂ����̃t���O
	bool attack_flag;		//�U���������ǂ����̃t���O

	bool set_flag;
	bool chara_move_flag;	//�R�}���h�ł�����̃L�����𓮂������߂̃t���O
	bool chara_move_flag2;	//�R�}���h�ł�����̃L�����𓮂������߂̃t���O
	bool chara_move_flag3;	//�R�}���h�ł�����̃L�����𓮂����~�߂邽�߂̃t���O

    bool die_flag;          //HP���O�ɂȂ������̃t���O

	int puls_pow;			//�o�t�f�o�t�ő������茸�����肷�镪�̍U����
	int puls_def;			//�o�t�f�o�t�ő������茸�����肷�镪�̖h���
	int puls_spd;			//�o�t�f�o�t�ő������茸�����肷�镪�̑f����

	bool damage_ones_flag;

	int damage_move_y;
};


#endif // _CHARABESE_H_