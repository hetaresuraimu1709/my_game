#include "inputkey.h"
#include <DxLib.h>

KEY_STATE_ENUM key[256];
char           keyState[2][256];

int nowKey, prevKey;

void initKey()
{
    int i, j;

    for(i = 0; i < 2; i++)
    {
        for (j = 0; j < 256; j++)
        {
            keyState[i][j] = 0;
            key[j] = KEY_STATE_OFF;
        }
    }
    nowKey = 0; prevKey = 1;

}

void updateKey()
{
    // ���݂̃L�[�ƈ�O�̃t���[���̃L�[��Ԃ����ւ���
    nowKey ^= 1;
    prevKey = nowKey ^ 1;

    // �L�[��Ԏ擾
    GetHitKeyStateAll(keyState[nowKey]);

    //
    for (int i = 0; i < 256; i++)
    {
        char nowInput = keyState[nowKey][i];
        char prevInput = keyState[prevKey][i];

        if (nowInput)
        {
            //���݉�����Ă���

            //�O�̃t���[����������Ă����H
            if (prevInput)
            {
                key[i] = KEY_STATE_PRESSED; // ��������ςȂ�
            }
            else 
			{
                key[i] = KEY_STATE_PUSHDOWN;// �������ꂽ
            }

        }
        else
        {
            // ���݃L�[�͉�����Ă��Ȃ�

            // �O�̃t���[���ŉ�����Ă����H
            if (prevInput)
            {
                key[i] = KEY_STATE_PULLUP;
            }
            else {
                key[i] = KEY_STATE_OFF;
            }
        }
    }
}



KEY_STATE_ENUM getKey(unsigned char keyCode)
{
    return key[keyCode];
}

