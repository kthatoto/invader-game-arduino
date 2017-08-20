
#ifndef Player_h
#define Player_h

class Player {
  public:
    Player();
    void move_left();
    void move_right();
    void draw();
    void shoot();

  private:
    int x;
    int y;
    int move_force;
    int last_shot_bullet_id;
};

#endif

Player::Player() {
  x = LCD_X / 2;
  y = 5;
  move_force = 5;
  last_shot_bullet_id = 0;
}
void Player::move_left(void) {
  if (5 <= x) {
    x -= move_force;
  }
}
void Player::move_right(void) {
  if (x <= 80 - 5) {
    x += move_force;
  }
}
void Player::draw(void) {
  gotoXY(x, y);
  LCDString("o");
}
void Player::shoot(void) {
  bullets[last_shot_bullet_id].shoot(x, y);
  last_shot_bullet_id = (last_shot_bullet_id + 1) % bullet_num;
}


