#include "Header.h"

Window::Window()
{
	//�R�}���h�w�i�摜���C���X�g�[���I�I
	window_back_graph = LoadGraph("data/command/window_back.png");
}

Window::~Window()
{
}

void Window::Command_Draw(float pos_x, float pos_y, float size_x, float size_y)
{
	//�`��u�����h���[�h���A���t�@�u�����h�i�T�O���j�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
	//�E�B���h�E�̔w�i
	DrawExtendGraph((int)pos_x, (int)pos_y, (int)(pos_x + size_x), (int)(pos_y + size_y), window_back_graph, true);
	//�E�B���h�E�̊O�g
	DrawBox((int)pos_x, (int)pos_y, (int)(pos_x + size_x), (int)(pos_y + COMMAND_WINDOW_LINE_SIZE), GetColor(255, 255, 255), true);//��
	DrawBox((int)pos_x, (int)(pos_y + size_y - COMMAND_WINDOW_LINE_SIZE), (int)(pos_x + size_x), (int)(pos_y + size_y), GetColor(255, 255, 255), true);//��
	DrawBox((int)pos_x, (int)(pos_y + COMMAND_WINDOW_LINE_SIZE), (int)(pos_x + COMMAND_WINDOW_LINE_SIZE), (int)(pos_y + size_y - COMMAND_WINDOW_LINE_SIZE), GetColor(255, 255, 255), true);//��
	DrawBox((int)(pos_x + size_x - COMMAND_WINDOW_LINE_SIZE), (int)(pos_y + COMMAND_WINDOW_LINE_SIZE), (int)(pos_x + size_x), (int)(pos_y + size_y - COMMAND_WINDOW_LINE_SIZE), GetColor(255, 255, 255), true);//�E
	// �`��u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

//�ύX�O
////�`��u�����h���[�h���A���t�@�u�����h�i�T�O���j�ɂ���
//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
////�E�B���h�E�̔w�i
//DrawExtendGraph((int)pos_x, (int)pos_y, (int)(pos_x + size_x), (int)(pos_y + size_y), window_back_graph, true);
////�E�B���h�E�̊O�g
//DrawBox((int)pos_x, (int)pos_y, (int)(pos_x + COMMAND_WINDOW_LINE_SIZE), (int)(pos_y + size_y), GetColor(255, 255, 255), true);//��
//DrawBox((int)pos_x, (int)pos_y, (int)(pos_x + size_x), (int)(pos_y + COMMAND_WINDOW_LINE_SIZE), GetColor(255, 255, 255), true);//��
//DrawBox((int)pos_x, (int)(pos_y + size_y - COMMAND_WINDOW_LINE_SIZE), (int)(pos_x + size_x), (int)(pos_y + size_y), GetColor(255, 255, 255), true);//��
//DrawBox((int)(pos_x + size_x - COMMAND_WINDOW_LINE_SIZE), (int)pos_y, (int)(pos_x + size_x), (int)(pos_y + size_y), GetColor(255, 255, 255), true);//�E
//																																				   // �`��u�����h���[�h���m�[�u�����h�ɂ���
//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);