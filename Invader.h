
#ifndef Invader_h
#define Invader_h

class Invader {
  public:
    Invader(int x, int y, int vx);
    void slide();
    void draw();
    void update();
    void hit();

  private:
    int x;
    int y;
    int vx;
    int turn;
    bool alive;
};

#endif

Invader::Invader(int _x, int _y, int _vx) {
  x  = _x;
  y  = _y;
  vx = _vx;
  turn = 0;
  alive = true;
}
void Invader::slide(void) {
  turn++;
  if (turn == 5) {
    turn = 0;
    if (x + vx <= 0 || 80 <= x + vx) {
      vx *= -1;
      y++;
    } else {
      x += vx;
    }
  }
}
void Invader::draw(void) {
  gotoXY(x, y);
  LCDString("x");
}
void Invader::update(void) {
  if (alive) {
    slide();
    draw();
  }
}
void Invader::hit(void) {
  alive = false;
}




