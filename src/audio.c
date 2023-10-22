#include "audio.h"

#include "helper.h"
#include "res.h"

extern const int bgmNums;
extern Mix_Music *bgms[AUDIO_BGM_SIZE];
extern Mix_Chunk *sounds[AUDIO_SOUND_SIZE];

int nowBgmId = -1;
void playBgm(int id) {//播放指定的背景音乐。如果当前正在播放的背景音乐与指定的音乐相同，则不执行任何操作。
    //如果当前没有正在播放的背景音乐，则直接播放指定的音乐。如果有正在播放的背景音乐，则通过淡入效果将其替换为指定的音乐。
  if (nowBgmId == id) return;
  if (nowBgmId == -1)
    Mix_PlayMusic(bgms[id], -1);
  else
    Mix_FadeInMusic(bgms[id], -1, BGM_FADE_DURATION);
  nowBgmId = id;
}
void stopBgm() {//止当前正在播放的背景音乐。
  Mix_FadeOutMusic(BGM_FADE_DURATION);
  nowBgmId = -1;
}
void randomBgm() { playBgm(randInt(1, bgmNums - 1)); }//随机播放背景音乐。从预加载的背景音乐中随机选择一个进行播放。


void playAudio(int id) {//播放指定的音效。通过混音通道播放音效，-1 参数表示使用任意可用的通道。
  if (id >= 0) Mix_PlayChannel(-1, sounds[id], 0);
}
void pauseSound() {//暂停所有正在播放的音效和背景音乐
  Mix_Pause(-1);
  Mix_PauseMusic();
}
void resumeSound() {//暂停所有正在播放的音效和背景音乐
  Mix_Resume(-1);
  Mix_ResumeMusic();
}
