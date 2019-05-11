#include "Header.h"
#include <list>

//********************************************************
// �֐��Q
//********************************************************
void Comment_string::word_insert(int col, std::string a, std::string i, std::string u, std::string e, std::string o, std::string A, std::string I, std::string U, std::string E, std::string O)
{
	word.insert(std::make_pair(a, &pos[col][0]));
	word.insert(std::make_pair(i, &pos[col][1]));
	word.insert(std::make_pair(u, &pos[col][2]));
	word.insert(std::make_pair(e, &pos[col][3]));
	word.insert(std::make_pair(o, &pos[col][4]));
	word.insert(std::make_pair(A, &pos[col][5]));
	word.insert(std::make_pair(I, &pos[col][6]));
	word.insert(std::make_pair(U, &pos[col][7]));
	word.insert(std::make_pair(E, &pos[col][8]));
	word.insert(std::make_pair(O, &pos[col][9]));
}

//********************************************************
// �摜�ǂݍ���
//********************************************************
Comment_string::Comment_string()
{
	comment_graph = LoadGraph("data/command/character_all3.png");
    comment_graph_orange = LoadGraph("data/command/character_all3_orange.png");
    comment_graph_red = LoadGraph("data/command/character_all3_red.png");
}

//********************************************************
// �摜�f���[�g�p�i���ݖ��g�p�j
//********************************************************
Comment_string::~Comment_string()
{
}

//********************************************************
// ������
//********************************************************
void Comment_string::Init()
{
	count = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			pos[i][j].u = (int)(j * STRING_SIZE_W);
			pos[i][j].v = (int)(i * STRING_SIZE_H);
			pos[i][j].w = (int)STRING_SIZE_W;
			pos[i][j].h = (int)STRING_SIZE_H;
		}
	}
	word_insert(0,  "��", "��", "��", "��", "��", "�A", "�C", "�E", "�G", "�I");
	word_insert(1,  "��", "��", "��", "��", "��", "�J", "�L", "�N", "�P", "�R");
	word_insert(2,  "��", "��", "��", "��", "��", "�T", "�V", "�X", "�Z", "�\");
	word_insert(3,  "��", "��", "��", "��", "��", "�^", "�`", "�c", "�e", "�g");
	word_insert(4,  "��", "��", "��", "��", "��", "�i", "�j", "�k", "�l", "�m");
	word_insert(5,  "��", "��", "��", "��", "��", "�n", "�q", "�t", "�w", "�z");
	word_insert(6,  "��", "��", "��", "��", "��", "�}", "�~", "��", "��", "��");
	word_insert(7,  "��", "��", "��", "��", "��", "��", "�[", "��", "�{", "��");
	word_insert(8,  "��", "��", "��", "��", "��", "��", "��", "��", "��", "��");
	word_insert(9,  "��", "��", "��", "�I", "�H", "��", "��", "��", "�A", "�B");
	word_insert(10, "��", "��", "��", "��", "��", "�K", "�M", "�O", "�Q", "�S");
	word_insert(11, "��", "��", "��", "��", "��", "�U", "�W", "�Y", "�[", "�]");
	word_insert(12, "��", "��", "��", "��", "��", "�_", "�a", "�d", "�f", "�h");
	word_insert(13, "��", "��", "��", "��", "��", "�o", "�r", "�u", "�x", "�{");
	word_insert(14, "��", "��", "��", "��", "��", "�p", "�s", "�v", "�y", "�|");
	word_insert(15, "��", "��", "��", "��", "��", "�@", "�B", "�D", "�F", "�H");
	word_insert(16, "��", "�i", "��", "�j", "��", "��", "�^", "��", "�E", "��");
	word_insert(17, "�`", "�a", "�b", "�c", "�d", "�e", "�f", "�g", "�h", "�i");
	word_insert(18, "�j", "�k", "�l", "�m", "�n", "�o", "�p", "�q", "�r", "�s");
	word_insert(19, "�t", "�u", "�v", "�w", "�x", "�y", "��", "�b", "��", "�@");
}

//********************************************************
// �`��
//********************************************************
void Comment_string::Draw(float x, float y, std::string comment)
{
    //�������l���i�S�p������Q���̂P�ɂ���j
    std::size_t word_num = comment.size() / 2;
	// ���X�g�̌������������Ă���
	for (size_t i = 0; i < word_num; i++)
	{
		auto tmpRect = word.find( std::string(comment.substr(i * 2, 2)));
		DrawRectGraph(
			(int)(x + (i * (STRING_SIZE_W - 5))),	// destX
			(int)y,									// destY
			tmpRect->second->u,						// srcX
			tmpRect->second->v,						// srcY
			tmpRect->second->w,						// w
			tmpRect->second->h,						// h
			comment_graph,							// handle
			true									// trans
		);
	}
}
void Comment_string::Draw_Orange(float x, float y, std::string comment)
{
    //�������l���i�S�p������Q���̂P�ɂ���j
    std::size_t word_num = comment.size() / 2;
    // ���X�g�̌������������Ă���
    for (size_t i = 0; i < word_num; i++)
    {
        auto tmpRect = word.find(std::string(comment.substr(i * 2, 2)));
        DrawRectGraph(
            (int)(x + (i * (STRING_SIZE_W - 5))),	// destX
            (int)y,									// destY
            tmpRect->second->u,						// srcX
            tmpRect->second->v,						// srcY
            tmpRect->second->w,						// w
            tmpRect->second->h,						// h
			comment_graph_orange,					// handle
            true									// trans
        );
    }
}
void Comment_string::Draw_Red(float x, float y, std::string comment)
{
    //�������l���i�S�p������Q���̂P�ɂ���j
    std::size_t word_num = comment.size() / 2;
    // ���X�g�̌������������Ă���
    for (size_t i = 0; i < word_num; i++)
    {
        auto tmpRect = word.find(std::string(comment.substr(i * 2, 2)));
        DrawRectGraph(
            (int)(x + (i * (STRING_SIZE_W - 5))),	// destX
            (int)y,									// destY
            tmpRect->second->u,						// srcX
            tmpRect->second->v,						// srcY
            tmpRect->second->w,						// w
            tmpRect->second->h,						// h
			comment_graph_red,						// handle
            true									// trans
        );
    }
}
