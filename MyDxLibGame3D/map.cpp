#include "Header.h"

Map::Map()
{
}

Map::~Map()
{
}

//bool Map::loadMapData(char * filename)
//{
//	FILE *fp;
//	fp = fopen(filename, "rt");
//
//	if (fp == NULL)
//	{
//		return false;
//	}
//
//	char buf[1024];
//	fgets(buf, 1024, fp);
//
//
//	char *token;
//
//	// �}�b�v�f�[�^�c���ǂݍ���
//	token = strtok(buf, ",");
//	mapXnum = atoi(token);
//
//	token = strtok(NULL, ",");
//	mapYnum = atoi(token);
//
//	token = strtok(NULL, ",");
//	graphchipSizeX = atoi(token);
//
//	token = strtok(NULL, ",");
//	graphchipSizeY = atoi(token);
//
//
//	//�}�b�v�f�[�^�z��m��
//	mapData = new unsigned char[mapXnum * mapYnum];
//
//	int x, y;
//	x = y = 0;
//	while (y < mapYnum)
//	{
//		//�P�s���Ƃɓǂݎ��
//		fgets(buf, 1024, fp);
//		printf("%s", buf);
//
//		//���g�[�N���擾
//		token = strtok(buf, ",");
//
//		//�P�s���J���}��؂�Ŕz��Ɏ擾
//		while (token != NULL || x < mapXnum)
//		{
//			mapData[x + y * mapXnum] = atoi(token);
//			token = strtok(NULL, ",");
//			x++;
//		}
//		x = 0;
//		y++;
//	}
//
//	fclose(fp);
//	return true;
//}
//
//bool Map::loadMapChip(char * chipGraphFilename)
//{
//	int tmp;
//	tmp = LoadGraph(chipGraphFilename);
//
//	if (tmp == -1)
//	{
//		return false;
//	}
//
//	int w, h;//�摜�̑S�̃T�C�Y
//	GetGraphSize(tmp, &w, &h);
//
//	int xNum, yNum; //�`�b�v���c���ɂ�������ł��邩�H
//
//					//�@�}�b�v�`�b�v�摜�̉摜���̏c����
//	xNum = w / graphchipSizeX;
//	yNum = h / graphchipSizeY;
//
//	// �}�b�v�`�b�v�摜�z��m��
//	mapGraph = new int[xNum * yNum];
//
//	//�}�b�v�`�b�v�摜�𕪊����ēǂݍ��� mapGraph�z�񂪎���
//	LoadDivGraph(chipGraphFilename, xNum * yNum, xNum, yNum, graphchipSizeX, graphchipSizeY, mapGraph);
//
//	return true;
//}
//
//void Map::mapDraw(int offsetX, int offsetY)
//{
//	int ix, iy;
//
//	// �}�b�v�f�[�^���摜�C���f�b�N�X�����o���ĉ�ʂɕ`��
//	for (iy = 0; iy < mapYnum; iy++)
//	{
//		for (ix = 0; ix < mapXnum; ix++)
//		{
//			DrawGraph(ix * graphchipSizeX - offsetX,
//				iy * graphchipSizeY - offsetY,
//				mapGraph[mapData[iy * mapXnum + ix]], FALSE);
//		}
//	}
//}
//
//void Map::mapRelease()
//{
//	if (mapGraph)
//	{
//		delete[] mapGraph;
//	}
//	if (mapData)
//	{
//		delete[] mapData;
//	}
//	mapGraph = NULL;
//	mapData = NULL;
//}

void Map::Init()
{
	graph[0]  = MV1LoadModel("data/field/grass.x");
	graph[1]  = MV1LoadModel("data/field/wall.x");
	graph[2]  = MV1LoadModel("data/field/warp.x");
	sky_model = MV1LoadModel("data/field/askyY/blue/askyY3_ao.x");
	sky_graph = LoadGraph("data/field/sky.png");
	for (int i = 0; i < 3; i++)
	{
		cloud_graph[i] = LoadGraph("data/field/cloud.png");
		cloud_pos[i] = VectorGet(0.0f + (i * 2000.0f), 0.0f);
	}
	map_ground[0] = MV1DuplicateModel(graph[0]);
	map_ground[1] = MV1DuplicateModel(graph[1]);
	map_ground[2] = MV1DuplicateModel(graph[2]);
	now_floor = 1;
	sky_move_x = 0.0f;
}

void Map::Draw(int map_data[BATTLE_MAP_CHIP][BATTLE_MAP_CHIP])
{
	for (int i = 0; i < BATTLE_MAP_CHIP; i++)
	{
		for (int j = 0; j < BATTLE_MAP_CHIP; j++)
		{
			for (int f = 0; f < 3; f++)
			{
				if (map_data[i][j] == f)
				{
					MV1SetPosition(map_ground[f], VGet(50.f*j, 0.f, 50.f*i));
					MV1DrawModel(map_ground[f]);
				}
			}
		}
	}
}

void Map::Cloud_P_Move()
{
	for (int i = 0; i < 3; i++)
	{
		cloud_pos[i].x += 5.5f;
	}
}

void Map::Cloud_M_Move()
{
	for (int i = 0; i < 3; i++)
	{
		cloud_pos[i].x -= 4.5f;
	}
}

void Map::Sky_Draw()
{
	MV1SetPosition(sky_model, VGet(50.f*10, 0.f, 50.f*10));
	MV1SetScale(sky_model, VGet(3.0f, 3.0f, 3.0f));
	MV1SetRotationXYZ(sky_model, VGet(0.0f, sky_move_x, 0.0f));
	sky_move_x -= 0.0005f;
	MV1DrawModel(sky_model);
}

void Map::Field_Draw(Effect *effect)
{
	Sky_Draw();
	switch (now_floor)
	{
	case 1:
		Draw(map_data_1);
		break;
	case 2:
		Draw(map_data_2);
		break;
	case 3:
		Draw(map_data_3);
		break;
	default:
		Draw(battle_map_data);
		break;
	}
}

void Map::Battle_Draw()
{
	Sky_Draw();
	Draw(battle_map_data);
}

//*******************************
//�u���b�N�̓����蔻��̑O����
//*******************************
//x���W���}�b�v�̓Y�����ԍ��𓾂�
int Map::GetMapIndexX(float x)
{
	return (int)(x / MAP_BLOCK_SIZE);
}
//z���W���}�b�v�̓Y�����ԍ��𓾂�
int Map::GetMapIndexZ(float z)
{
	return (int)(z / MAP_BLOCK_SIZE);
}
//x���W�Ay���W���}�b�v�̎�ނ�Ԃ�
int Map::GetMapType(float x, float z, int map_data[BATTLE_MAP_CHIP][BATTLE_MAP_CHIP] ,Map *map)
{
	//�`�ʔ͈͓��Ȃ�`�ʂ���
	if ((x > 0 && x < MAP_BLOCK_SIZE*BATTLE_MAP_CHIP) &&
		(z > 0 && z < MAP_BLOCK_SIZE*BATTLE_MAP_CHIP))
	{
		return map_data[GetMapIndexZ(z)][GetMapIndexX(x)];
	}
	return -1;
}