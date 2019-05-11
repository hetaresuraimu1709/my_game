#include "Header.h"

Memory::Memory()
{
    //�܂ق�
    {
        I_spell[0]  = Inventory_Get(sp_nasi, false, 0,	mu,		"�X�y���Ȃ�");       //���@����
        I_spell[1]  = Inventory_Get(spell1,  false, 10,	firen,	"�t�B����");         //�Α������@�i���j
        I_spell[2]  = Inventory_Get(spell2,  false, 30, firen,	"�t�B���C��");       //�Α������@�i���j
        I_spell[3]  = Inventory_Get(spell3,  false, 100,firen,	"�t�B�����[�A");     //�Α������@�i��j
        I_spell[4]  = Inventory_Get(spell4,  false, 10, rofs,	"���t�X");           //�X�������@�i���j
        I_spell[5]  = Inventory_Get(spell5,  false, 30, rofs,	"���t�X�B��");       //�X�������@�i���j
        I_spell[6]  = Inventory_Get(spell6,  false, 100,rofs,	"���u�X�[��");       //�X�������@�i��j
        I_spell[7]  = Inventory_Get(spell7,  false, 10,	alre,	"�A�[��");           //���������@�i���j
        I_spell[8]  = Inventory_Get(spell8,  false, 30, alre,	"�G�A�[��");         //���������@�i���j
        I_spell[9]  = Inventory_Get(spell9,  false, 100,alre,	"�G�A���K��");       //���������@�i��j
        I_spell[10] = Inventory_Get(spell10, false, 0,	mu,		"�t�H�[�Y");         //�U���̓o�t���@
        I_spell[11] = Inventory_Get(spell11, false, 0,	mu,		"�t�H�[��");         //�U���̓f�o�t���@
        I_spell[12] = Inventory_Get(spell12, false, 0,	mu,		"�K�[�d");           //�h��̓o�t���@
        I_spell[13] = Inventory_Get(spell13, false, 0,	mu,		"�K�[��");           //�h��̓f�o�t���@
        I_spell[14] = Inventory_Get(spell14, false, 0,	mu,		"�X�s�[�Y");         //�f�����o�t���@
        I_spell[15] = Inventory_Get(spell15, false, 0,	mu,		"�X�s�[��");         //�f�����f�o�t���@
    }
    //�Ƃ���
    {
        I_skill[0]  = Inventory_Get(sk_nasi, false, 0,	mu,		"�X�L���Ȃ�");       //�X�L������
        I_skill[1]  = Inventory_Get(skill1,  false, 0,  alre,	"�Ȃ��͂炢");       //�͈͍U��
        I_skill[2]  = Inventory_Get(skill2,  false, 0,	mu,		"��������");         //������Ή�S
        I_skill[3]  = Inventory_Get(skill3,  false, 0,	mu,		"�߂Ԃ�");         //����̍U�����Q�^�[��������Ȃ��Ȃ�
        I_skill[4]  = Inventory_Get(skill4,  false, 0,	mu,		"�����ӂ���");       //����̖��@���Q�^�[���������Ȃ��Ȃ�
        I_skill[5]  = Inventory_Get(skill5,  false, 0,	mu,		"���傤�͂�");       //����̓G�ӂ�������l�Ɋ񂹂�
        I_skill[6]  = Inventory_Get(skill6,  false, 0,	mu,		"����������");       //�h��͈ˑ��̃_���[�W�A����͂P�^�[���s���s�\
        I_skill[7]  = Inventory_Get(skill7,  false, 0,	mu,		"�݂˂���");         //��������čU���A�P�͕K���^����
        I_skill[8]  = Inventory_Get(skill8,  false, 0,	mu,		"��������");         //�G�S�̂��P�^�[���s���s�\�i�m���j�A�Q�Ă�l��������N����
        I_skill[9]  = Inventory_Get(skill9,  false, 0,	mu,		"�Ă���");           //������l��HP�����`����
        I_skill[10] = Inventory_Get(skill10, false, 0,	mu,		"�͂�����");         //�����S�̂�HP������
        I_skill[11] = Inventory_Get(skill11, false, 0,	mu,		"�Ђ낢����");       //�T�O���̊m����HP,MP���񕜁A�T�O���̊m���ŏ�Ԉُ�����炢��HP����
        I_skill[12] = Inventory_Get(skill12, false, 0,	mu,		"�����������");     //������l��h���i�m���j
        I_skill[13] = Inventory_Get(skill13, false, 0,	mu,		"�����傤��");     //�_���[�W��H�炤����Ԉُ��
        I_skill[14] = Inventory_Get(skill14, false, 0,	mu,		"���₷��");         //�R�^�[���̊Ԑ�����ԂɂȂ邪HP,MP���񕜂��Ă���
        I_skill[15] = Inventory_Get(skill15, false, 0,	mu,		"�܂�");           //�o�C�u�X���オ��i�R��A���Ő�������ƃo�C�u�X���L���V�ɂȂ��ēG������Łj
    }
    //�ǂ���
    {
        I_item[0]  = Inventory_Get(it_nasi, false, 0,	mu,	"�A�C�e���Ȃ�");       //�A�C�e������
        I_item[1]  = Inventory_Get(item1,   false, 0,	mu,	"�J�b�g�o��");         //������l��HP�𒆉�
        I_item[2]  = Inventory_Get(item2,   false, 0,	mu,	"�ق�����");           //������l��HP����
        I_item[3]  = Inventory_Get(item3,   false, 0,	mu,	"�|�[�V����");         //������l��HP�����S��
        I_item[4]  = Inventory_Get(item4,   false, 0,	mu,	"������");             //�����S�̂�HP,MP������
        I_item[5]  = Inventory_Get(item5,   false, 0,	mu,	"�~�l��������");       //������l��MP�𒆉�
        I_item[6]  = Inventory_Get(item6,   false, 0,	mu,	"�u���[�u��");         //������l��MP����
        I_item[7]  = Inventory_Get(item7,   false, 0,	mu,	"���ׂ�Ƃ�");         //������l��HP,MP�����񕜁A�R��g����
        I_item[8]  = Inventory_Get(item8,   false, 0,	mu,	"���ނ肾��");         //�퓬����m���ɓ������
        I_item[9]  = Inventory_Get(item9,   false, 0,	mu,	"");
        I_item[10] = Inventory_Get(item10,  false, 0,	mu,	"�A�C�e��");
        I_item[11] = Inventory_Get(item11,  false, 0,	mu,	"�A�C�e��");
        I_item[12] = Inventory_Get(item12,  false, 0,	mu,	"�A�C�e��");
        I_item[13] = Inventory_Get(item13,  false, 0,	mu,	"�A�C�e��");
        I_item[14] = Inventory_Get(item14,  false, 0,	mu,	"�A�C�e��");
        I_item[15] = Inventory_Get(item15,  false, 0,	mu,	"�A�C�e��");
    }
}

Memory::~Memory()
{
}

void Memory::UseSpell(Battle *battle, Chara *chara)
{
	for (int i = 0; i < KEY_MAGIC_MAX_COMMAND_X; i++)
	{
		for (int j = 0; j < KEY_MAGIC_MAX_COMMAND_Y; j++)
		{
			Inventory inv_case = chara->magic[j == 0 ? i : i + KEY_MAGIC_MAX_COMMAND_X];
			if (inv_case.use_flag)
			{
				if (inv_case.name == "�t�B����")
				{
					chara->status[_mp_] -= 3;
				}
				if (inv_case.name == "�t�B���C��")
				{
					chara->status[_mp_] -= 5;
				}
				if (inv_case.name == "�t�B�����[�A")
				{
					chara->status[_mp_] -= 10;
				}
				if (inv_case.name == "���t�X")
				{
					chara->status[_mp_] -= 3;
				}
				if (inv_case.name == "���t�X�B��")
				{
					chara->status[_mp_] -= 5;
				}
				if (inv_case.name == "���u�X�[��")
				{
					chara->status[_mp_] -= 10;
				}
				if (inv_case.name == "�A�[��")
				{
					chara->status[_mp_] -= 3;
				}
				if (inv_case.name == "�G�A�[��")
				{
					chara->status[_mp_] -= 5;
				}
				if (inv_case.name == "�G�A���K��")
				{
					chara->status[_mp_] -= 10;
				}
				if (inv_case.name == "�t�H�[�Y")
				{
					chara->status[_mp_] -= 2;
				}
				if (inv_case.name == "�t�H�[��")
				{
					chara->status[_mp_] -= 2;
				}
				if (inv_case.name == "�K�[�d")
				{
					chara->status[_mp_] -= 2;
				}
				if (inv_case.name == "�K�[��")
				{
					chara->status[_mp_] -= 2;
				}
				if (inv_case.name == "�X�s�[�Y")
				{
					chara->status[_mp_] -= 2;
				}
				if (inv_case.name == "�X�s�[��")
				{
					chara->status[_mp_] -= 2;
				}
			}
		}
	}
}

void Memory::UseSkill(Battle *battle, Chara *chara)
{
	for (int i = 0; i < KEY_MAGIC_MAX_COMMAND_X; i++)
	{
		for (int j = 0; j < KEY_MAGIC_MAX_COMMAND_Y; j++)
		{
			Inventory inv_case = chara->skill[j == 0 ? i : i + KEY_MAGIC_MAX_COMMAND_X];
			if (inv_case.use_flag)
			{
				if (inv_case.name == "�Ȃ��͂炢")
				{
					chara->status[_mp_] -= 3;
				}
				if (inv_case.name == "��������")
				{
					chara->status[_mp_] -= 5;
				}
				if (inv_case.name == "�߂Ԃ�")
				{
					chara->status[_mp_] -= 10;
				}
				if (inv_case.name == "�����ӂ���")
				{
					chara->status[_mp_] -= 3;
				}
				if (inv_case.name == "���傤�͂�")
				{
					chara->status[_mp_] -= 5;
				}
				if (inv_case.name == "����������")
				{
					chara->status[_mp_] -= 10;
				}
				if (inv_case.name == "�݂˂���")
				{
					chara->status[_mp_] -= 3;
				}
				if (inv_case.name == "��������")
				{
					chara->status[_mp_] -= 5;
				}
				if (inv_case.name == "�Ă���")
				{
					chara->status[_mp_] -= 10;
				}
				if (inv_case.name == "�͂�����")
				{
					chara->status[_mp_] -= 2;
				}
				if (inv_case.name == "�Ђ낢����")
				{
					chara->status[_mp_] -= 2;
				}
				if (inv_case.name == "�����������")
				{
					chara->status[_mp_] -= 2;
				}
				if (inv_case.name == "�����傤��")
				{
					chara->status[_mp_] -= 2;
				}
				if (inv_case.name == "���₷��")
				{
					chara->status[_mp_] -= 2;
				}
				if (inv_case.name == "�܂�")
				{
					chara->status[_mp_] -= 2;
				}
			}
		}
	}
}

void Memory::UseItem(Battle *battle, Chara *chara)
{
}
