#include "bullet.h"

#include "helper.h"

Bullet* createBullet(Snake* owner, Weapon* parent, int x, int y, double rad,//创建一个子弹对象，并初始化其属性。
                     int team, Animation* ani) {
  Bullet* bullet = malloc(sizeof(Bullet));
  *bullet = (Bullet){parent, x, y, team, owner, rad, malloc(sizeof(Animation))};
  copyAnimation(ani, bullet->ani);
  bullet->ani->x = x;
  bullet->ani->y = y;
  bullet->ani->angle = rad * 180 / PI;
  return bullet;
}
void moveBullet(Bullet* bullet) { //移动子弹的位置。该函数接受一个指向子弹对象的指针，并根据子弹对象的方向和速度来更新子弹的坐标。
  int speed = bullet->parent->bulletSpeed;
  bullet->x += cos(bullet->rad) * speed;
  bullet->y += sin(bullet->rad) * speed;
  bullet->ani->x = bullet->x;
  bullet->ani->y = bullet->y;
}
void destroyBullet(Bullet* bullet) { free(bullet); }
