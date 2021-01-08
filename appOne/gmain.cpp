#include"libOne.h"
#define HEART_
#ifdef HEART_
void getShapePos(float t, float& x, float& y) {
    x = pow(sin(t), 3);
    y = (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t)) / 16;
}
#else
void getShapePos(float t, float& x, float& y) {
    x = sin(t);
    y = cos(t);
}
#endif
void gmain() {
    window(1920, 1080, full);
    float cx = width / 2;
    float cy = height / 2;
    float sx, sy, ex, ey;
#ifdef HEART_
    float radius = 200;
#else
    float radius = 120;
#endif
    float deg = 0, inc = 1;
    float limmit = 0;
    angleMode(DEGREES);
    ShowCursor(FALSE);
    while (notQuit) {
        limmit += 1;
        if (limmit >= 360) {
            limmit = 0;
        }
        clear(1);
        //x,y座標
        stroke(100);
        strokeWeight(2);
        line(cx - radius, cy, cx + radius, cy);
        line(cx, cy - radius, cx, cy + radius);
        //limmitの角度までハートのlineを描く
        deg = 0;
        getShapePos(deg, sx, sy);//始点
        while (deg <= limmit) {
            deg += inc;
            getShapePos(deg, ex, ey);//終点
            strokeWeight(4);
            //ｘ座標
            stroke(255, 128, 128);
            line(cx + sx * radius, deg - inc, cx + ex * radius, deg);
            //ｙ座標
            stroke(128, 255, 128);
            line(cx/3 + deg - inc, cy - sy * radius, cx/3 + deg, cy - ey * radius);
            //ハート
            strokeWeight(30);
            stroke(255, 128, 255);
            line(cx + sx * radius, cy - sy * radius, cx + ex * radius, cy - ey * radius);
            //終点を次のlineの始点にする
            sx = ex;
            sy = ey;
        }
        //x座標を下まで伸ばす
        strokeWeight(2);
        line(cx + sx * radius, deg - inc, cx + sx * radius, height);
        //y座標を右まで伸ばす
        line(cx / 3 + deg, cy - sy * radius, width, cy - sy * radius);
        //式の表示
#ifdef HEART_
        fill(255);
        text("x = pow(sin(t), 3)", cx+radius, 180);
        text("y = (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t))/16",200,cy+radius+100);
#endif
    }
    ShowCursor(TRUE);
}