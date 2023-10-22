#include "audio.h"

#include "helper.h"
#include "res.h"

extern const int bgmNums;
extern Mix_Music *bgms[AUDIO_BGM_SIZE];
extern Mix_Chunk *sounds[AUDIO_SOUND_SIZE];

int nowBgmId = -1;
void playBgm(int id) {//����ָ���ı������֡������ǰ���ڲ��ŵı���������ָ����������ͬ����ִ���κβ�����
    //�����ǰû�����ڲ��ŵı������֣���ֱ�Ӳ���ָ�������֡���������ڲ��ŵı������֣���ͨ������Ч�������滻Ϊָ�������֡�
  if (nowBgmId == id) return;
  if (nowBgmId == -1)
    Mix_PlayMusic(bgms[id], -1);
  else
    Mix_FadeInMusic(bgms[id], -1, BGM_FADE_DURATION);
  nowBgmId = id;
}
void stopBgm() {//ֹ��ǰ���ڲ��ŵı������֡�
  Mix_FadeOutMusic(BGM_FADE_DURATION);
  nowBgmId = -1;
}
void randomBgm() { playBgm(randInt(1, bgmNums - 1)); }//������ű������֡���Ԥ���صı������������ѡ��һ�����в��š�


void playAudio(int id) {//����ָ������Ч��ͨ������ͨ��������Ч��-1 ������ʾʹ��������õ�ͨ����
  if (id >= 0) Mix_PlayChannel(-1, sounds[id], 0);
}
void pauseSound() {//��ͣ�������ڲ��ŵ���Ч�ͱ�������
  Mix_Pause(-1);
  Mix_PauseMusic();
}
void resumeSound() {//��ͣ�������ڲ��ŵ���Ч�ͱ�������
  Mix_Resume(-1);
  Mix_ResumeMusic();
}
