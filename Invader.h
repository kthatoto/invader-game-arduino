
#ifndef Invader_h
#define Invader_h

class Invader {
  public:
    Invader(int x, int y, int vx);
    void slide();
    void draw();
    void update();

  private:
    int x;
    int y;
    int vx;
    int turn;
};

#endif

Invader::Invader(int _x, int _y, int _vx) {
  x  = _x;
  y  = _y;
  vx = _vx;
  turn = 0;
}
void Invader::slide(void) {
  turn++;
  if (turn == 3) {
    turn = 0;
    if (x + vx <= 0 || 84 <= x + vx) {
      vx *= -1;
    }
    x += vx;
  }
}
void Invader::draw(void) {
  gotoXY(x, y);
  LCDString("i");
}
void Invader::update(void) {
  slide();
  draw();
}

