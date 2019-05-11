//player.cpp

//�w�b�_�[�Ăяo��
#include "Header.h"

//�R���X�g���N�^
Player::Player(Memory memory)
{
    //ALLY_1_NAME
    {
        //�L������,�A�h���X��
        c_ally[0] = Status_Get(ALLY_1_NAME, "data/model/miffy/miffy_tool.pmx",
            //�������W
            VectorGet(50.0f * BATTLE_MAP_CHIP / 2, 0.0f, 50.0f * BATTLE_MAP_CHIP / 2),
            //�����o�g�����W
            VectorGet(50.0f * BATTLE_MAP_CHIP / 2 - 50, 0.0f, 50.0f * BATTLE_MAP_CHIP / 2),
            //HP,MP,�U��,�h��,�U������,�񕜖���,���悤��,���΂₳
            ALLY_1_FIRST_HP, ALLY_1_FIRST_MP, ALLY_1_FIRST_STR, ALLY_1_FIRST_DEF, ALLY_1_FIRST_MST, ALLY_1_FIRST_MHL, ALLY_1_FIRST_SKI, ALLY_1_FIRST_SPD, 0,true);
        Inventory_Have_Get(c_ally[0].skill, memory.I_skill[memory.skill1], memory.I_skill[memory.skill2], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi]);
        Inventory_Have_Get(c_ally[0].magic, memory.I_spell[memory.spell1], memory.I_spell[memory.spell4], memory.I_spell[memory.spell7], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi]);
        Inventory_Have_Get(c_ally[0].item, memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi]);
    }
    //ALLY_2_NAME
    {
        //�L������,�A�h���X��
        c_ally[1] = Status_Get(ALLY_2_NAME, "data/model/miffy/miffy_rood.pmx",
            //�������W
            VectorGet(50.0f * BATTLE_MAP_CHIP / 2, 0.0f, 50.0f * BATTLE_MAP_CHIP / 2),
            //�����o�g�����W
            VectorGet(50.0f * BATTLE_MAP_CHIP / 2, 0.0f, 50.0f * BATTLE_MAP_CHIP / 2),
            //HP,MP,�U��,�h��,�U������,�񕜖���,���悤��,���΂₳
            ALLY_2_FIRST_HP, ALLY_2_FIRST_MP, ALLY_2_FIRST_STR, ALLY_2_FIRST_DEF, ALLY_2_FIRST_MST, ALLY_2_FIRST_MHL, ALLY_2_FIRST_SKI, ALLY_2_FIRST_SPD, 0,true);
        Inventory_Have_Get(c_ally[1].skill, memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi]);
        Inventory_Have_Get(c_ally[1].magic, memory.I_spell[memory.spell1], memory.I_spell[memory.spell4], memory.I_spell[memory.spell7], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi]);
        Inventory_Have_Get(c_ally[1].item, memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi]);
    }
    //ALLY_3_NAME
    {
        //�L������,�A�h���X��
        c_ally[2] = Status_Get(ALLY_3_NAME, "data/model/miffy/miffy_sord.pmx",
            //�������W
            VectorGet(50.0f * BATTLE_MAP_CHIP / 2, 0.0f, 50.0f * BATTLE_MAP_CHIP / 2),
            //�����o�g�����W
            VectorGet(50.0f * BATTLE_MAP_CHIP / 2 + 50, 0.0f, 50.0f * BATTLE_MAP_CHIP / 2),
            //HP,MP,�U��,�h��,�U������,�񕜖���,���悤��,���΂₳
            ALLY_3_FIRST_HP, ALLY_3_FIRST_MP, ALLY_3_FIRST_STR, ALLY_3_FIRST_DEF, ALLY_3_FIRST_MST, ALLY_3_FIRST_MHL, ALLY_3_FIRST_SKI, ALLY_3_FIRST_SPD, 0,true);
        Inventory_Have_Get(c_ally[2].skill, memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi], memory.I_skill[memory.sk_nasi]);
        Inventory_Have_Get(c_ally[2].magic, memory.I_spell[memory.spell1], memory.I_spell[memory.spell4], memory.I_spell[memory.spell7], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi], memory.I_spell[memory.sp_nasi]);
        Inventory_Have_Get(c_ally[2].item, memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi], memory.I_item[memory.it_nasi]);
    }
	for (int i = 0; i < 3; i++)
	{
		// ����A�j���[�V�������A�^�b�`
		AnimAttachIndex[0] = MV1AttachAnim(c_ally[i].modelHandle, 0, -1, FALSE);
		AnimAttachIndex[1] = MV1AttachAnim(c_ally[i].modelHandle, 1, -1, FALSE);
		// ����A�j���[�V�����̑����Ԃ��擾���Ă���
		AnimTotalTime[i] = MV1GetAttachAnimTotalTime(c_ally[i].modelHandle, AnimAttachIndex[i]);
		// �A�j���[�V�����Đ����Ԃ�������
		AnimNowTime = 0.f;
		MV1SetAttachAnimTime(c_ally[i].modelHandle, AnimAttachIndex[i], AnimNowTime);
	}
	hoge_chara = Status_Get("�G���[�I", "", VectorGet(0.0f, 0.0f, 0.0f), VectorGet(0.0f, 0.0f, 0.0f), -1, -1, -1, -1, -1, -1, -1, -1, -1,false);
}

void Player::Init()
{
	now_anim = 0;
	dir_angle = 0;
	dir_angle_plas = 0;
	left_turn_flag = false;
	right_turn_flag = false;
	ahead_turn_flag = false;
	rear_turn_flag = false;
	ahead_left_turn_flag = false;
	ahead_right_turn_flag = false;
	rear_left_turn_flag = false;
	rear_right_turn_flag = false;
	jumpflag = false;
	keyflag = false;
	ahead_hit_flag = false;
	rear_hit_flag = false;
	left_hit_flag = false;
	right_hit_flag = false;
	warp_flag = false;
	jumppow = 0;
	vertical_dir = nodir;
	heng_dir = nodir;
	c_ally[0].vec = VectorGet(0.0f, 0.0f, 0.0f);
	menu_open_flag = false;
}

void Player::Turn_Reset()
{
	left_turn_flag = false;
	right_turn_flag = false;
	ahead_turn_flag = false;
	rear_turn_flag = false;
	ahead_left_turn_flag = false;
	ahead_right_turn_flag = false;
	rear_left_turn_flag = false;
	rear_right_turn_flag = false;
}

//����
void Player::Move(Camera *camera,Map *map)
{
	AnimNowTime += 0.3f;
	// ��ɐi�ޏ���
	if (getKey(KEY_INPUT_W) == KEY_STATE_PRESSED)
	{
		dir_angle = camera->HRotate;
		UpMove = Sub_Vector_Vector(c_ally[0].f_pos,camera->f_pos);//�O�ւ̃x�N�g���擾
		UpMove = Vector_Normalize(UpMove);//���K������
		UpMove = Mul_Vector_Scaler(UpMove, 1.0f);//�ړ����x����
        c_ally[0].vec = Add_Vector_Vector(c_ally[0].vec, UpMove);//�ړ��x�N�g���ɉ��Z
		vertical_dir = ahead;
	}
	// ���ɐi�ޏ���
	else if (getKey(KEY_INPUT_S) == KEY_STATE_PRESSED)
	{
		dir_angle = camera->HRotate;
		DownMove = Sub_Vector_Vector(c_ally[0].f_pos, camera->f_pos);//���x�N�g���擾
		DownMove = Mul_Vector_Scaler(DownMove, -1.0f);//�O�̋t�����甽�]������
		DownMove = Vector_Normalize(DownMove);//���K������
		DownMove = Mul_Vector_Scaler(DownMove, 1.0f);//�ړ����x����
		c_ally[0].vec = Add_Vector_Vector(c_ally[0].vec, DownMove);//�ړ��x�N�g���ɉ��Z
		vertical_dir = rear;
	}
	// �E�ɐi�ޏ���
	if (getKey(KEY_INPUT_D) == KEY_STATE_PRESSED)
	{
		dir_angle = camera->HRotate;
		RightMove = Vector_Cross(camera->up, Sub_Vector_Vector(c_ally[0].f_pos, camera->f_pos));//�E�x�N�g���擾
		RightMove = Vector_Normalize(RightMove);//���K������
		RightMove = Mul_Vector_Scaler(RightMove, 1.0f);//�ړ����x����
        c_ally[0].vec = Add_Vector_Vector(c_ally[0].vec, RightMove);//�ړ��x�N�g���ɉ��Z
		heng_dir = right;
	}
	// ���ɐi�ޏ���
	else if (getKey(KEY_INPUT_A) == KEY_STATE_PRESSED)
	{
		dir_angle = camera->HRotate;
		LeftMove = Vector_Cross(Sub_Vector_Vector(c_ally[0].f_pos, camera->f_pos), camera->up);//���ւ̃x�N�g���擾
		LeftMove = Vector_Normalize(LeftMove);//���K��
		LeftMove = Mul_Vector_Scaler(LeftMove, 1.0f);//�ړ����x����
		c_ally[0].vec = Add_Vector_Vector(c_ally[0].vec, LeftMove);//�ړ��x�N�g���ɉ��Z
		heng_dir = left;
	}
    //��{�^���𗣂����Ƃ�
	if (getKey(KEY_INPUT_W) == KEY_STATE_PULLUP)
	{
		vertical_dir = nodir;
	}
    //���{�^���𗣂����Ƃ�
	else if (getKey(KEY_INPUT_S) == KEY_STATE_PULLUP)
	{
		vertical_dir = nodir;
	}
    //�E�{�^���𗣂����Ƃ�
	if (getKey(KEY_INPUT_D) == KEY_STATE_PULLUP)
	{
		heng_dir = nodir;
	}
    //���{�^���𗣂����Ƃ�
	if (getKey(KEY_INPUT_A) == KEY_STATE_PULLUP)
	{
		heng_dir = nodir;
	}
	if ((getKey(KEY_INPUT_SPACE) == KEY_STATE_PULLUP) && !keyflag && !jumpflag)//�X�y�[�X�L�[
	{
		keyflag = true;
		jumpflag = true;
		jumppow = 3.0f;
	}
	else
	{
		keyflag = false;
	}

    if (getKey(KEY_INPUT_W) == KEY_STATE_PRESSED ||
        getKey(KEY_INPUT_S) == KEY_STATE_PRESSED ||
        getKey(KEY_INPUT_A) == KEY_STATE_PRESSED ||
        getKey(KEY_INPUT_D) == KEY_STATE_PRESSED)
    {
        c_ally[0].vec = Vector_Normalize(c_ally[0].vec);//���K��
        c_ally[0].vec = Mul_Vector_Scaler(c_ally[0].vec, 1.0f);//�ړ����x����
		switch (map->now_floor)
		{
		case 1:
			WallHit(*map, map->map_data_1);//�ǂɓ����������~�߂�悤��
			break;
		case 2:
			WallHit(*map, map->map_data_2);//�ǂɓ����������~�߂�悤��
			break;
		case 3:
			WallHit(*map, map->map_data_3);//�ǂɓ����������~�߂�悤��
			break;
		default:
			break;
		}
        c_ally[0].f_pos = Add_Vector_Vector(c_ally[0].f_pos, c_ally[0].vec);//���W�ɉ��Z
    }
	
	if (jumpflag)
	{
		c_ally[0].f_pos.y += jumppow;
		jumppow -= GRAVITY;
		if (c_ally[0].f_pos.y < 0.0f)
		{
			c_ally[0].f_pos.y = 0.0f;
			jumpflag = false;
		}
	}

	if (warp_flag)
	{
		if (map->now_floor < 4)
		{
			map->now_floor++;
			camera->HRotate = 0;
			dir_angle_plas = 0;
			warp_flag = false;
			c_ally[0].f_pos = VectorGet(50.0f * BATTLE_MAP_CHIP / 2, 0.0f, 50.0f * BATTLE_MAP_CHIP / 2);
			camera->f_pos = VectorGet(50.0f * BATTLE_MAP_CHIP / 2, 15.f, 50.0f * BATTLE_MAP_CHIP / 2 - 30.f);
		}
	}
}

void Player::Turn()
{
	//�L������]�̃t���O�𗧂Ă�
	for (int i = 0; i < ANIM_MAX; i++)
	{
		if (vertical_dir == ahead && heng_dir == nodir)
		{
			Turn_Reset();
			AnimNowTime += 0.3f;
			ahead_turn_flag = true;
		}
		if (vertical_dir == rear && heng_dir == nodir)
		{
			Turn_Reset();
			AnimNowTime += 0.3f;
			rear_turn_flag = true;
		}
		if (heng_dir == left && vertical_dir == nodir)
		{
			Turn_Reset();
			AnimNowTime += 0.3f;
			left_turn_flag = true;
		}
		if (heng_dir == right && vertical_dir == nodir)
		{
			Turn_Reset();
			AnimNowTime += 0.3f;
			right_turn_flag = true;
		}
		if (vertical_dir == ahead && heng_dir == right)
		{
			Turn_Reset();
			AnimNowTime += 0.3f;
			ahead_right_turn_flag = true;
		}
		if (vertical_dir == ahead && heng_dir == left)
		{
			Turn_Reset();
			AnimNowTime += 0.3f;
			ahead_left_turn_flag = true;
		}
		if (vertical_dir == rear && heng_dir == right)
		{
			Turn_Reset();
			AnimNowTime += 0.3f;
			rear_right_turn_flag = true;
		}
		if (vertical_dir == rear && heng_dir == left)
		{
			Turn_Reset();
			AnimNowTime += 0.3f;
			rear_left_turn_flag = true;
		}
	}

	//�L������]�̌v�Z�i�ق��̃L�[��������Ȃ�����A��񉟂����牟���ꂽ�����Ɍ����܂ő����j
	if (ahead_turn_flag)
	{
		Turn_Around(dir_angle_plas, PLAYER_AHEAD, vertical_dir_SPEED, ahead_turn_flag);
	}
	if (rear_turn_flag)
	{
		Turn_Around(dir_angle_plas, PLAYER_REAR, vertical_dir_SPEED, rear_turn_flag);
	}
	if (left_turn_flag)
	{
		Turn_Around(dir_angle_plas, PLAYER_LEFT, vertical_dir_SPEED, left_turn_flag);
	}
	if (right_turn_flag)
	{
		Turn_Around(dir_angle_plas, PLAYER_RIGHT, vertical_dir_SPEED, right_turn_flag);
	}
	if (ahead_right_turn_flag)
	{
		Turn_Around(dir_angle_plas, PLAYER_AHEAD + 45.f, vertical_dir_SPEED, ahead_right_turn_flag);
	}
	if (ahead_left_turn_flag)
	{
		Turn_Around(dir_angle_plas, PLAYER_AHEAD - 45.f, vertical_dir_SPEED, ahead_left_turn_flag);
	}
	if (rear_right_turn_flag)
	{
		Turn_Around(dir_angle_plas, PLAYER_REAR - 45.f, vertical_dir_SPEED, rear_right_turn_flag);
	}
	if (rear_left_turn_flag)
	{
		Turn_Around(dir_angle_plas, 45.f, vertical_dir_SPEED, rear_left_turn_flag);
	}
	//printfDx("%f\n", dir_angle_plas);

	//�v���C���[����]������悤
	MV1SetRotationXYZ(c_ally[0].modelHandle, VGet(0.0f, dir_angle + (dir_angle_plas / (180.f / DX_PI_F)), 0.0f));
}

void WallHitBase(int map_number,Map map, int map_data[BATTLE_MAP_CHIP][BATTLE_MAP_CHIP], bool conditions, Vector3 pos, float *x_or_z, bool *hit_flag, int plasx1, int plasx2, int plasx3, int plasz1, int plasz2, int plasz3)
{
	if (conditions &&
		map.GetMapType( pos.x + plasx1, pos.z + plasz1, map_data, &map) == map_number &&
		(map.GetMapType(pos.x + plasx2, pos.z + plasz2, map_data, &map) == map_number ||
		map.GetMapType( pos.x + plasx3, pos.z + plasz3, map_data, &map) == map_number ))
	{
		if (map_number == 1)
		{
			*x_or_z -= *x_or_z;
		}
		*hit_flag = true;
	}
	else
	{
		*hit_flag = false;
	}
}

//�ǂ̓����蔻��
void Player::WallHit(Map map,int map_data[BATTLE_MAP_CHIP][BATTLE_MAP_CHIP])
{
	//�O
	WallHitBase(1, map, map_data, c_ally[0].vec.z > 0, c_ally[0].f_pos, &c_ally[0].vec.z, &ahead_hit_flag, 25, 20, 30, 30, 30, 30);
	//���
	WallHitBase(1, map, map_data, c_ally[0].vec.z < 0, c_ally[0].f_pos, &c_ally[0].vec.z, &rear_hit_flag, 25, 20, 30, 20, 20, 20);
	//��
	WallHitBase(1, map, map_data, c_ally[0].vec.x < 0, c_ally[0].f_pos, &c_ally[0].vec.x, &left_hit_flag, 20, 20, 20, 25, 20, 30);
	//�E
	WallHitBase(1, map, map_data, c_ally[0].vec.x > 0, c_ally[0].f_pos, &c_ally[0].vec.x, &right_hit_flag, 30, 30, 30, 25, 20, 30);
	//�O
	WallHitBase(2, map, map_data, true, c_ally[0].f_pos, &c_ally[0].vec.z, &warp_flag, 25, 20, 30, 30, 30, 30);
	//���
	WallHitBase(2, map, map_data, true, c_ally[0].f_pos, &c_ally[0].vec.z, &warp_flag, 25, 20, 30, 20, 20, 20);
	//��
	WallHitBase(2, map, map_data, true, c_ally[0].f_pos, &c_ally[0].vec.x, &warp_flag, 20, 20, 20, 25, 20, 30);
	//�E
	WallHitBase(2, map, map_data, true, c_ally[0].f_pos, &c_ally[0].vec.x, &warp_flag, 30, 30, 30, 25, 20, 30);
}

//�G�Ƃ̓����蔻��
void Player::EnemyHit(int *scene, Enemy *enemy, Battle *battle, Camera *camera)
{
	if (enemy->on_flag)
	{
		for (int i = 0; i < ENEMY; i++)
		{
			//�����G�ɐڐG������
			if (Vector_Length(Sub_Vector_Vector(enemy->enemy[i].f_pos, c_ally[0].f_pos)) < 10)
			{
				enemy->enemy[i].f_pos = VectorGet(100.0f, 100.0f, 100.0f);
				//�퓬�J�n
				camera->Init();
				battle->Init(camera, this);
				battle->In(&c_ally[0], &c_ally[1], &c_ally[2], &enemy->enemy[i], &enemy->enemy[i], &enemy->enemy[i], &enemy->enemy[i]);
				*scene = s_battle;
			}
		}
	}
}

//�������Ȃ��悤��
void Player::VectorReset()
{
	c_ally[0].vec = VectorGet(0.0f, 0.0f, 0.0f);
}

//�`��
void Player::Draw()
{
	printfDx("%f\n", AnimNowTime);
	// �A�j���[�V�����Đ����Ԃ��A�j���[�V�����̑����Ԃ��z���Ă����烋�[�v������
	if (AnimNowTime >= AnimTotalTime[now_anim])
	{
		// �V�����A�j���[�V�����Đ����Ԃ́A�A�j���[�V�����Đ����Ԃ���A�j���[�V���������Ԃ�����������
		AnimNowTime -= AnimTotalTime[now_anim];
	}
	// �V�����A�j���[�V�����Đ����Ԃ��Z�b�g
	MV1SetAttachAnimTime(c_ally[0].modelHandle, AnimAttachIndex[now_anim], AnimNowTime);
	
	//�_������������փA�j���[�V�����ϊ�
	if (getKey(KEY_INPUT_W) == KEY_STATE_PRESSED ||
		getKey(KEY_INPUT_S) == KEY_STATE_PRESSED || 
		getKey(KEY_INPUT_A) == KEY_STATE_PRESSED || 
		getKey(KEY_INPUT_D) == KEY_STATE_PRESSED)
	{
		// �S�Ԗڂ̃A�j���[�V��������T�Ԗڂ̃A�j���[�V�����ɏ��X�Ɉڍs����
		for (Rate = 0.0f; Rate < 1.0f; Rate += 0.01f)
		{
			// �����Ă���A�j���[�V�����̃u�����h�����Z�b�g
			MV1SetAttachAnimBlendRate(c_ally[0].modelHandle, AnimAttachIndex[1], 1.0f - Rate);

			// ���O�ɏo���Ă���A�j���[�V�����̃u�����h�����Z�b�g
			MV1SetAttachAnimBlendRate(c_ally[0].modelHandle, AnimAttachIndex[0], Rate);
		}
	}
	//��������_�����փA�j���[�V�����ϊ�
	if (getKey(KEY_INPUT_W) == KEY_STATE_OFF &&
		getKey(KEY_INPUT_S) == KEY_STATE_OFF &&
		getKey(KEY_INPUT_A) == KEY_STATE_OFF &&
		getKey(KEY_INPUT_D) == KEY_STATE_OFF)
	{
		// �S�Ԗڂ̃A�j���[�V��������T�Ԗڂ̃A�j���[�V�����ɏ��X�Ɉڍs����
		for (Rate = 0.0f; Rate < 1.0f; Rate += 0.01f)
		{
			// �����Ă���A�j���[�V�����̃u�����h�����Z�b�g
			MV1SetAttachAnimBlendRate(c_ally[0].modelHandle, AnimAttachIndex[0], 1.0f - Rate);

			// ���O�ɏo���Ă���A�j���[�V�����̃u�����h�����Z�b�g
			MV1SetAttachAnimBlendRate(c_ally[0].modelHandle, AnimAttachIndex[1], Rate);
		}
	}
	// �RD���f���̃|�W�V�����ݒ�
	MV1SetPosition(c_ally[0].modelHandle, VGet(c_ally[0].f_pos.x, c_ally[0].f_pos.y, c_ally[0].f_pos.z));
	// �v���C���[�`��.
	MV1DrawModel(c_ally[0].modelHandle);
}

void Player::BattleDraw(Battle battle)
{
	for (int i = 0; i < 3; i++)
	{
		// �A�j���[�V�����Đ����Ԃ��A�j���[�V�����̑����Ԃ��z���Ă����烋�[�v������
		if (AnimNowTime >= AnimTotalTime[now_anim])
		{
			// �V�����A�j���[�V�����Đ����Ԃ́A�A�j���[�V�����Đ����Ԃ���A�j���[�V���������Ԃ�����������
			AnimNowTime -= AnimTotalTime[now_anim];
		}
		// �V�����A�j���[�V�����Đ����Ԃ��Z�b�g
		MV1SetAttachAnimTime(battle.m_ally[i].modelHandle, AnimAttachIndex[now_anim], AnimNowTime);

		//�_������������փA�j���[�V�����ϊ�
		if (getKey(KEY_INPUT_W) == KEY_STATE_PRESSED ||
			getKey(KEY_INPUT_S) == KEY_STATE_PRESSED ||
			getKey(KEY_INPUT_A) == KEY_STATE_PRESSED ||
			getKey(KEY_INPUT_D) == KEY_STATE_PRESSED)
		{
			for (Rate = 0.0f; Rate < 1.0f; Rate += 0.001f)
			{
				// �����Ă���A�j���[�V�����̃u�����h�����Z�b�g
				MV1SetAttachAnimBlendRate(battle.m_ally[i].modelHandle, AnimAttachIndex[1], 1.0f - Rate);

				// ���O�ɏo���Ă���A�j���[�V�����̃u�����h�����Z�b�g
				MV1SetAttachAnimBlendRate(battle.m_ally[i].modelHandle, AnimAttachIndex[0], Rate);
				if (Rate == 0.99f)
				{
					now_anim = 0;
				}

			}
		}
		//��������_�����փA�j���[�V�����ϊ�
		if (getKey(KEY_INPUT_W) == KEY_STATE_OFF &&
			getKey(KEY_INPUT_S) == KEY_STATE_OFF &&
			getKey(KEY_INPUT_A) == KEY_STATE_OFF &&
			getKey(KEY_INPUT_D) == KEY_STATE_OFF)
		{
			for (Rate = 0.0f; Rate < 1.0f; Rate += 0.001f)
			{
				// �����Ă���A�j���[�V�����̃u�����h�����Z�b�g
				MV1SetAttachAnimBlendRate(battle.m_ally[i].modelHandle, AnimAttachIndex[0], 1.0f - Rate);

				// ���O�ɏo���Ă���A�j���[�V�����̃u�����h�����Z�b�g
				MV1SetAttachAnimBlendRate(battle.m_ally[i].modelHandle, AnimAttachIndex[1], Rate);
				if (Rate == 0.99f)
				{
					now_anim = 1;
				}
			}
		}

		// �RD���f���̃|�W�V�����ݒ�
		MV1SetPosition(battle.m_ally[i].modelHandle, VGet(battle.m_ally[i].b_pos.x, battle.m_ally[i].b_pos.y, battle.m_ally[i].b_pos.z));
		// �v���C���[�`��.
		MV1DrawModel(battle.m_ally[i].modelHandle);
	}
}

//�f�X�g���N�^
Player::~Player() {
	// �v���C���[���폜.
	//MV1DeleteModel(c_ally[0].modelHandle);
}