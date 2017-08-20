
#ifndef Bullet_h
#define Bullet_h

class Bullet {
  public:
    Bullet();
    void shoot(int x, int y);
    void run();
    bool running;

  private:
    int x;
    int y;
};

#endif

Bullet::Bullet() {
  running = false;
}
void Bullet::shoot(int _x, int _y) {
  x = _x;
  y = _y;
  running = true;
}
void Bullet::run(void) {
  y--;
  if (y <= 0) {
    running = false;
  }
  gotoXY(x, y);
  LCDString(".");
}

