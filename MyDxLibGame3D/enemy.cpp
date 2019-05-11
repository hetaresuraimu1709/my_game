#include"Header.h"

Enemy::Enemy(Memory memory)
{
	for (int i = 0; i < ENEMY; i++)
	{
		notice_flag[i] = false;
		notice_count[i] = 0;
		move_count[i] = 0;
	}
	on_flag = false;
	//�G�l�~�[�̃X�e�[�^�X���           ���O               �A�h���X��								  �t�B�[���h														�퓬                HP   MP    �U��   �h��  �U�� �� ���悤�� ���΂₳ �o���l
	enemy[suraimu] = Status_Get(       "�X���C��"		,"data/model/enemy/suraimu1/suraimu.pmx", Map_On_Pos(VectorGet(MAP_CHIP, MAP_CHIP), VectorGet(10, 15)), VectorGet(0, 0, 0), 20,    0,   10,     5,  10,   0,     50,     5, 3,false);
	enemy[suraimubesu] = Status_Get(   "�X���C���x�X"	,"data/model/enemy/suraimu2/suraimu.pmx", Map_On_Pos(VectorGet(MAP_CHIP, MAP_CHIP), VectorGet(11, 15)), VectorGet(0, 0, 0), 30,   10,   15,     5,  10,   0,     30,     4, 3,false);
	enemy[metarusuraimu] = Status_Get( "���^���X���C��"	,"data/model/enemy/suraimu4/suraimu.pmx", Map_On_Pos(VectorGet(MAP_CHIP, MAP_CHIP), VectorGet(12, 15)), VectorGet(0, 0, 0),  3, 2500,    3,  2500,  10,   0,     10,   700, 1000,false);
	enemy[raimusuraimu] = Status_Get(  "���C���X���C��"	,"data/model/enemy/suraimu3/suraimu.pmx", Map_On_Pos(VectorGet(MAP_CHIP, MAP_CHIP), VectorGet(13, 15)), VectorGet(0, 0, 0), 15,   10,    5,    20,   0,  20,     50,     3, 3,false);
	enemy[remonsuraimu] = Status_Get(  "�������X���C��"	,"data/model/enemy/suraimu5/suraimu.pmx", Map_On_Pos(VectorGet(MAP_CHIP, MAP_CHIP), VectorGet(14, 15)), VectorGet(0, 0, 0), 20,    0,   10,     5,  10,   0,     50,     2, 3,false);
	Inventory_Have_Get(enemy[suraimu].		skill, memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi]);
	Inventory_Have_Get(enemy[suraimubesu].	skill, memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi]);
	Inventory_Have_Get(enemy[metarusuraimu].skill, memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi]);
	Inventory_Have_Get(enemy[raimusuraimu].	skill, memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi]);
	Inventory_Have_Get(enemy[remonsuraimu].	skill, memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi]);
	Inventory_Have_Get(enemy[suraimu].		magic, memory.I_spell[memory.spell1], memory.I_spell[memory.spell4], memory.I_spell[memory.spell7], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi]);
	Inventory_Have_Get(enemy[suraimubesu].	magic, memory.I_spell[memory.spell1], memory.I_spell[memory.spell4], memory.I_spell[memory.spell7], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi]);
	Inventory_Have_Get(enemy[metarusuraimu].magic, memory.I_spell[memory.spell1], memory.I_spell[memory.spell4], memory.I_spell[memory.spell7], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi]);
	Inventory_Have_Get(enemy[raimusuraimu].	magic, memory.I_spell[memory.spell1], memory.I_spell[memory.spell4], memory.I_spell[memory.spell7], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi]);
	Inventory_Have_Get(enemy[remonsuraimu].	magic, memory.I_spell[memory.spell1], memory.I_spell[memory.spell4], memory.I_spell[memory.spell7], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi]);
}

Enemy::~Enemy()
{
}

void Enemy::Turn_Reset()
{
}

void Attack_Hp_Max(Chara *chara, Battle battle)
{
	if (!chara->chara_move_flag2)
	{
		chara->second_behavior_flag[battle.attack] = true;
		int hp = 0;
		for (int j = 0; j < 3; j++)
		{
			if (hp < battle.m_ally[j].status[_hp_])
			{
				hp = battle.m_ally[j].status[_hp_];
				chara->who_command_flag[0] = false;
				chara->who_command_flag[1] = false;
				chara->who_command_flag[2] = false;
				chara->who_command_flag[j] = true;
			}
		}
	}
}

void Enemy::Battle_AI(Battle *battle)
{
	for (int i = 0; i < 4; i++)
	{
		if (battle->m_enemy[i].name_origin == "�X���C��")
		{
			Attack_Hp_Max(&battle->m_enemy[i], *battle);
        }
        if (battle->m_enemy[i].name_origin == "�X���C���x�X")
        {
			Attack_Hp_Max(&battle->m_enemy[i], *battle);
        }
        if (battle->m_enemy[i].name_origin == "���^���X���C��")
        {
			Attack_Hp_Max(&battle->m_enemy[i], *battle);
		}
        if (battle->m_enemy[i].name_origin == "���C���X���C��")
        {
			Attack_Hp_Max(&battle->m_enemy[i], *battle);
        }
        if (battle->m_enemy[i].name_origin == "�������X���C��")
        {
			Attack_Hp_Max(&battle->m_enemy[i], *battle);
        }
     }
}

void Enemy::Move(Map map, Player player)
{
	if (map.now_floor > 0)
	{
		on_flag = true;
		for (int i = 0; i < ENEMY; i++)
		{
			//printfDx("%f,%f,%f\n", enemy[i].f_pos.x, enemy[i].f_pos.y, enemy[i].f_pos.z);
			/*if (Enemy_notice(player.c_ally[0].f_pos, enemy[i].f_pos))
			{
				notice_flag[i] = true;
			}
			if (notice_flag[i])
			{
				enemy[i].vec = Sub_Vector_Vector(enemy[i].f_pos, player.c_ally[0].f_pos);
				enemy[i].vec = Vector_Normalize(enemy[i].vec);
				enemy[i].vec = Mul_Vector_Scaler(enemy[i].vec, -0.5);
				enemy[i].f_pos = Add_Vector_Vector(enemy[i].f_pos, enemy[i].vec);
				notice_count[i]++;
				if (notice_count[i] > 300)
				{
					notice_count[i] = 0;
					notice_flag[i] = false;
				}
			}
			if (!notice_flag[i])
			{
				if (move_count[i] < 200)
				{
					enemy[i].vec = Vector_Normalize(enemy[i].vec);
					enemy[i].vec = Mul_Vector_Scaler(enemy[i].vec, 1);
					enemy[i].f_pos = Add_Vector_Vector(enemy[i].f_pos, enemy[i].vec);
				}
				else if (move_count[i] > 400)
				{
					enemy[i].vec = Vector_Normalize(enemy[i].vec);
					enemy[i].vec = Mul_Vector_Scaler(enemy[i].vec, -1);
					enemy[i].f_pos = Add_Vector_Vector(enemy[i].f_pos, enemy[i].vec);
					if (move_count[i] > 600)
					{
						move_count[i] = 0;
					}
				}
				move_count[i]++;
			}*/
		}
	}
	else
	{
		on_flag = false;
	}
}

void Enemy::Draw(Map map)
{
	if(map.now_floor > 0)
	{
		for (int i = 0; i < ENEMY; i++)
		{
			MV1DrawModel(enemy[i].modelHandle);
			MV1SetPosition(enemy[i].modelHandle, VGet(enemy[i].f_pos.x, enemy[i].f_pos.y, enemy[i].f_pos.z));
		}
	}
}

void Enemy::Battle_Draw(Battle battle, Effect *effect)
{
    for (int i = 0; i < ENEMY; i++)
    {
		if (battle.m_enemy[i].status[_hp_] > 0)
		{
			MV1DrawModel(battle.m_enemy[i].modelHandle);
			MV1SetPosition(battle.m_enemy[i].modelHandle, VGet(battle.m_enemy[i].b_pos.x, battle.m_enemy[i].b_pos.y, battle.m_enemy[i].b_pos.z));
			MV1SetRotationXYZ(battle.m_enemy[i].modelHandle, VGet(0.0f, DX_PI_F, 0.0f));
		}
		else if (battle.m_enemy[i].die_flag)
		{
           /* effect->enemy_die.pos = enemy[i].b_pos;
            effect->Draw(&effect->enemy_die, 150);*/
			/*MV1DrawModel(battle.m_enemy[i].modelHandle);
			MV1SetPosition(battle.m_enemy[i].modelHandle, VGet(battle.m_enemy[i].b_pos.x, battle.m_enemy[i].b_pos.y, battle.m_enemy[i].b_pos.z));
			MV1SetRotationXYZ(battle.m_enemy[i].modelHandle, VGet(0.0f, DX_PI_F, 0.0f));*/
		}
    }
}
