// Title.h
//�^�C�g���̃w�b�_�[
#ifndef _TITLE_H_
#define _TITLE_H_

struct Graph
{
	int graph;//�摜�f�[�^
	Vector2 pos;//position
	float enl;//�g�嗦
	bool flag;//�g�嗦�����邽�߂̃t���O
};

class Title
{
public:
	Title();//�R���X�g���N�^
	~Title();//�f�X�g���N�^
	void Move(int *scene, Music *music, bool *game_end_flag);//����
	void Draw(Comment_string *comment, Music *music, Window *window);//�`��
private:
	Graph main_title;
	Graph title_back;
	Graph miffy[3];
	Graph suraimu[2];
	int cursor_graph[8];
	int anim_count;
	int anim_frame;
	Vector2 gamestart_pos;
	Vector2 cursor_pos;
	Vector2 window_pos;
};

class End
{
public:
	End();//�R���X�g���N�^
	~End();//�f�X�g���N�^
	void Move(int *scene);//����
	void Draw(Comment_string *comment, Music *music);//�`��
};

#endif // _TITLE_H_