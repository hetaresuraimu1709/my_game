// Memory.h
//�������[�̃w�b�_�[
#ifndef _MEMORY_H_
#define _MEMORY_H_

class Memory
{
public:
    Memory();
    ~Memory();
    Inventory I_spell[SPELL_MAX], I_skill[SKILL_MAX], I_item[ITEM_MAX];
    enum spell
    {
        sp_nasi,//���������ĂȂ�
        spell1,//�Α����i���j
        spell2,//�Α����i���j
        spell3,//�Α����i��j
        spell4,//�������i���j
        spell5,//�������i���j
        spell6,//�������i��j
        spell7,//�������i���j
        spell8,//�������i���j
        spell9,//�������i��j
        spell10,//�������i���j
        spell11,//�������i���j
        spell12,//�������i��j
        spell13,//�ő����i���j
        spell14,//�ő����i���j
        spell15,//�ő����i��j
    };

    enum skill
    {
        sk_nasi,
        skill1,
        skill2,
        skill3,
        skill4,
        skill5,
        skill6,
        skill7,
        skill8,
        skill9,
        skill10,
        skill11,
        skill12,
        skill13,
        skill14,
        skill15,
    };

    enum item
    {
        it_nasi,
        item1,
        item2,
        item3,
        item4,
        item5,
        item6,
        item7,
        item8,
        item9,
        item10,
        item11,
        item12,
        item13,
        item14,
        item15,
    };

	enum force
	{
		mu = 0,		//�����Ȃ�
		firen = 1,	//�Α���
		rofs = 2,	//�X����
		alre = 3	//������
	};

    void UseSpell(Battle *battle, Chara *chara);
    void UseSkill(Battle *battle, Chara *chara);
    void UseItem(Battle *battle, Chara *chara);
private:

};

#endif // _MEMORY_H_
