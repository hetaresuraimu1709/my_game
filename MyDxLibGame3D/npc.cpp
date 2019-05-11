//npc.cpp

//�w�b�_�[�Ăяo��
#include "Header.h"

Npc::Npc()
{
}

Npc::~Npc()
{
}

Npc_base Npc_In(std::string name, char *filename, Vector3 pos, std::string line)
{
	Npc_base base;

	base.name = name;
	base.model = MV1LoadModel(filename);
	base.pos = pos;
	base.line = line;

	return base;
}

//������
void Npc::Init()
{
	for (int i = 0; i < 10; i++)
	{
		people[i] = Npc_In("��������", "data/model/miffy/miffy_tool.pmx", Map_On_Pos(VectorGet(MAP_CHIP, MAP_CHIP), VectorGet((float)(10.0f + i), 15.0f)), "����������");
	}
}

//�X�V�v���O����
void Npc::Updata()
{

}

//�`��
void Npc::Draw()
{
	//�RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(people[0].model, VGet(people[0].pos.x, people[0].pos.y, people[0].pos.z));
	//�v���C���[�`��
	MV1DrawModel(people[0].model);
}
