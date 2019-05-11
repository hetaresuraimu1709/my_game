//Battle.h
#ifndef _BATTLE_H_
#define _BATTLE_H_

class Window;

struct Damege
{
	int damage;				//battle�ł̃_���[�W������Ƃ�
	bool critical_hit_flag;	//��S�̈ꌂ���ǂ����̃t���O
	bool damege_once_flag;	//�_���[�W�v�Z����񂾂����邽�߂̃t���O
};

class Battle
{
public:
	Battle();
	~Battle();
	void Init(Camera *camera, Player *player);//������
    void In(Chara *ally1, Chara *ally2, Chara *ally3, Chara *enemy1, Chara *enemy2, Chara *enemy3, Chara *enemy4);//�L�������
	void Commanding(Player *player, Enemy *enemy, Camera *camera, Map *map, Music music);//�������ꂼ��̂�𓮂���
	void Playing(Player *player, Enemy *enemy, Camera *camera);
	void Updata(int *scene, Player *player, Enemy *enemy, Camera *camera, Map *map, Music *music);
	void Draw(int *scene, Player *player, Enemy *enemy, Map *map, Camera *camera, Comment_string *comment, Effect *effect, Music *music, Window *window, Memory *memory);//�`��
	bool probability(int max);
	void Flag_Reset();//�t���O���Z�b�g�p
	void Move_Flag_Reset();

	enum first_command
	{
		battle,//�키
		see,//����
		escape,//������
	};
	enum second_command
	{
		attack,//�U��
		skill,//���Z
		magic,//���@
		guard,//�h��
		item,//����
		sink,//���߂�
	};

	int first_count;//�ŏ��̂��\�������鎞��
	int command_play_count;//�ł����R�}���h��play���Ă�Ƃ��ɕ\�������鎞��
	bool camera_flag[7];//���ꂪ�s�����Ă邩���J�����Ŕ��ʂ��邽�߂̃t���O
    int turn_count;//���݂Ȃ�^�[���ڂ�
	Damege damege[7];

    Chara m_ally[3];//����������Ƃ���
    Chara m_enemy[4];//�G������Ƃ���
private:
	//battle�ł����g��Ȃ��֐�
	void Have_Spell_Draw(Chara ally, int behavior, Inventory *ally_inv, Inventory *all_inv, Comment_string *comment);
	void Command(int number, Music music);//�R�}���h��������
	void Key_Anim(int number);
	Chara No_1_Speed_Get(Chara *speed0, Chara *speed1, Chara *speed2, Chara *speed3, Chara *speed4, Chara *speed5, Chara *speed6);
	void Command_Play_Move();//�R�}���h�ł������Ƃ̓���
	void Command_Play_Draw(Comment_string *comment, Chara *chara0, Chara *chara1, Chara *chara2, Chara *chara3, Chara *chara4, Chara *chara5, Chara *chara6, int count_max);//�R�}���h�ł������Ƃ̕`��
	void Command_Choice_Draw(int number, Comment_string *comment, Window *window, Memory *memory);//�R�}���h�I�𒆂̕`��
    void Enemy_Kill_Next(Chara *chara, Chara *enemy, int enemy_num);
	void Hit_And_Awey(Chara *chara, Chara *enemy, bool *chara_move_flag2, bool *chara_move_flag3, int enemy_num);
	void Playing_Move(Chara *ally, Chara *enemy, int ally_num, int enemy_num);
	void Damage_Adjustment(int *damege);
	void Damage_Calculation(Chara *chara_case, int damege_source, int damege_bonus, bool physics_flag);
	void Damage_Calculation_Set(Comment_string *comment, Chara *chara_case, float command_x, float command_y, int damege_source, int damege_bonus, bool physics_flag);
	//battle�ł����g��Ȃ��ϐ�
	std::string first_behavior[KEY_1ST_MAX_COMMAND];							//���������A�݂�A�ɂ���
	std::string second_behavior[KEY_2ND_MAX_COMMAND_Y * KEY_2ND_MAX_COMMAND_X];	//���������A�Ƃ����A�܂ق��A�ڂ�����A�ǂ����A���߂�
	Vector2 key_pos[4];															//�J�[�\���̍��W
	Vector2 command_word_pos[9];												//�����������̕����̍��W
    Vector2 command_pos[10];													//�R�}���h�g�̍��W
	float key_move_pos[4];														//�J�[�\���̈ړ����W
	bool reset_command_pos_flag;												//�R�}���h�����ɖ߂������̃t���O
	bool reset_command_pos_flag2;												//�R�}���h�����ɖ߂������̃t���O
	int key_graph[8];															//�J�[�\���̉摜
	int anim_count;																//�A�j���[�V�����̂��߂̃J�E���g
	int now_frame[4];															//�A�j���[�V�����̂��߂̃t���[��
	int first_frame_graph;														//�ŏ��̕����g
    int name_command_graph;														//�P�ڂ̃R�}���h�̏�ɕ\�������閼�O�p�̘g
    int status_command_graph;													//�X�e�[�^�X�̃R�}���h�g
	int one_command_graph;														//�P�ڂ̃R�}���h�g
	int two_command_graph;														//�Q�ڂ̃R�}���h�g
	int three_command_graph;													//�R�ڂ̃R�}���h�g
	int magic_command_graph;													//���@���̃R�}���h�g
	int count_graph[10];														//�����̉摜
    int count_graph_orange[10];													//�����̉摜
    int count_graph_red[10];													//�����̉摜
	int key_count[4];															//������
    int rand_count;                                                             //�����_���Ŏg���悤�̕ϐ�
	bool end_flag;
	int rast_count;
};

#endif // _BATTLE_H_